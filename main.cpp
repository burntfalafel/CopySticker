#include <QApplication>

#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
    Widget w;
    w.show();

//  don't need app event loop
//  return a.exec();
}
