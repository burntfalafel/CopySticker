#include "window.h"

#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QClipboard>
#include <QMimeData>
#include <QApplication>
#include <QImage>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void Widget::loadStickers()
{
 // Set size of the window
// setMinimumSize(500, 500);

 // open a file manager - replace with settings.ini
 struct passwd *pw = getpwuid(getuid());
 const char *homedir = pw->pw_dir;

 QString fileName = QFileDialog::getOpenFileName(this,
     tr("Open sticker"), homedir, tr("Image/Video Files (*.png *.jpg *.jpeg *.bmp *.mp4 *.gif )"));
 // should display image
 if (!fileName.isEmpty())
 {
     qDebug().nospace() << "abc" << qPrintable(fileName) << "def";
     QImage image;
     bool status = image.load(fileName, nullptr); //conditional here
     QClipboard *clipboard =  QApplication::clipboard();
     QMimeData *data = new QMimeData;
     data->setImageData(image);
     clipboard->setMimeData(data, QClipboard::Clipboard);

 } // no else

 // Create and position the button
// m_button = new QPushButton("Hello World", this);
// m_button->setGeometry(10, 10, 80, 30);
// m_button->setCheckable(true);

//connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
}
Widget::Widget(QWidget *parent) : //constructor
    QWidget(parent)
{
    loadStickers();
}

//void Window::slotButtonClicked(bool checked)
//{
// if (checked) {
// m_button->setText("Checked");
// } else {
// m_button->setText("Hello World");
// }
//}
