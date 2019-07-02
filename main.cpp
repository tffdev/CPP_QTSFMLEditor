#include "mainroomeditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainRoomEditor w;
    w.show();

    return a.exec();
}
