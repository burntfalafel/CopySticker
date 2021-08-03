#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    //Method    descriptions can be found in the .cpp file
    //Attribute descriptions can be found in this file
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
//    ~Widget();
private slots:
    int loadStickers();
};

#endif // WINDOW_H
