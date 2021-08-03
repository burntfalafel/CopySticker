#ifndef PREVIEW_FILE_DIALOG_H
#define PREVIEW_FILE_DIALOG_H

#include <QFileDialog>

class QLabel;

class PreviewFileDialog : public QFileDialog
{
            Q_OBJECT
    public:
            explicit PreviewFileDialog(
                    QWidget* parent = 0,
                    const QString & caption = QString(),
                    const QString & directory = QString(),
                    const QString & filter = QString()
            );

    protected slots:
            void OnCurrentChanged(const QString & path);

    protected:
            QLabel* mpPreview;

};

#endif // PREVIEW_FILE_DIALOG_H
