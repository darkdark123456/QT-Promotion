#include "LGMD2ModelApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LGMD2ModelApplication w;
    w.show();
    return a.exec();
}
