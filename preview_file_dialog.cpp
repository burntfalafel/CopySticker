#include <QBoxLayout>
#include <QLabel>

#include "preview_file_dialog.h"

PreviewFileDialog::PreviewFileDialog(
    QWidget* parent,
    const QString & caption,
    const QString & directory,
    const QString & filter
    ) :
  QFileDialog(parent, caption, directory, filter)
{
  this->setOption(QFileDialog::DontUseNativeDialog,true);
  setObjectName("PreviewFileDialog");
  QVBoxLayout* box = new QVBoxLayout();

  mpPreview = new QLabel(tr("Preview"), this);
  mpPreview->setAlignment(Qt::AlignCenter);
  mpPreview->setObjectName("labelPreview");
  mpPreview->setMinimumSize(512,512);
  box->addWidget(mpPreview);
  box->addStretch();

  // add to QFileDialog layout
  QGridLayout *layout = static_cast<QGridLayout*>(this->layout());

  QList< QPair<QLayoutItem*, QList<int> > > movedItems;
  for(int i = 0; i < layout->count(); i++)
  {
    int row, column, rowSpan, columnSpan;
    layout->getItemPosition(i,&row,&column,&rowSpan,&columnSpan);
    if (row > 2)
    {
      QList<int> list;
      list << row << column << rowSpan << columnSpan;
      movedItems << qMakePair(layout->takeAt(i),list);
      i--;
    }
  }
  for(int i = 0; i < movedItems.count(); i++)
  {
    layout->addItem(movedItems[i].first,
                    movedItems[i].second[0],
                    movedItems[i].second[1],
                    movedItems[i].second[2],
                    movedItems[i].second[3]
            );
  }

  layout->addItem(box,1,3,1,1);
  connect(this, SIGNAL(currentChanged(const QString&)), this, SLOT(OnCurrentChanged(const QString&)));
}

void PreviewFileDialog::OnCurrentChanged(const QString & path)
{
    QPixmap pixmap = QPixmap(path);
    if (pixmap.isNull()) {
        mpPreview->setText("not an image");
    } else {
        mpPreview->setPixmap(pixmap.scaled(mpPreview->width(), mpPreview->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}
