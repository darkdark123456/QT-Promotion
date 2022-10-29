#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QPalette palette;
    QPixmap pixmap(":/backGround.png");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    w.setPalette(palette);
    w.show();
    return a.exec();
}
