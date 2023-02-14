#include "QtWidgetsTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsTest w;
    w.show();
    return a.exec();
}
