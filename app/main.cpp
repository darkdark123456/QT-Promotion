/*******************************************
* @ProjectName 	GF408
* @Features   	NO
* @Author      	MENGZHENCHUAN
* @Data        	2022-08-12 12::34::01
* @Statement	The author holds the final interpretation right of this software,
        and the author shall not use this software to engage in any commercial activities without the author's permission,
        otherwise, the author has the legal responsibility to pursue it.
        This software can be used for learning and communication among classmates,
        which is also the original intention of the author to develop this software.
********************************************/


#include "widget.h"
#include <QApplication>
#include <QPalette>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
