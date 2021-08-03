#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QString>

class Widget : public QWidget
{
    //Method    descriptions can be found in the .cpp file
    //Attribute descriptions can be found in this file
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
private slots:
    int loadStickers();
};

#endif // WINDOW_H
