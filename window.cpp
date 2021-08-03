#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QClipboard>
#include <QMimeData>
#include <QApplication>
#include <QImage>
#include <QMainWindow>
#include <fstream>
#include <jsoncpp/json/json.h>

#include "window.h"
#include "preview_file_dialog.h"

int Widget::loadStickers()
{
  Json::Value root;
  std::ifstream config_jsn("copystickersettings.json", std::ifstream::binary);
  config_jsn >> root;
  std::string fileDir = root.get("location","/home/").asString();
  std::string formatTypes = root.get("formats","*.jpg *.jpeg").asString();
  config_jsn.close();
  std::string typeMessage = "Image/Video Files (" + formatTypes + " )";

 QFileDialog *dialog = new PreviewFileDialog(this,
     tr("Open sticker"), fileDir.c_str(), tr(typeMessage.c_str()));
 dialog->setFileMode(QFileDialog::AnyFile);
 dialog->setViewMode(QFileDialog::Detail);
 QStringList fileNames;
 if (dialog->exec())
     fileNames = dialog->selectedFiles();
 else
{
     dialog->close();
     return 1;
 }
 QString fileName = fileNames.takeFirst();

 if (!fileName.isEmpty() && !fileName.isNull())
 {
     QImage image;
     bool status = image.load(fileName, nullptr);
     if (status)
     {
        QClipboard *clipboard =  QApplication::clipboard();
        QMimeData *data = new QMimeData;
        data->setImageData(image);
        clipboard->setMimeData(data, QClipboard::Clipboard);
        return 0;
     }
 }
 return 1;
}
Widget::Widget(QWidget *parent) : //constructor
    QWidget(parent)
{
    int status = 0;
    while(!status)
        status = loadStickers();
}
