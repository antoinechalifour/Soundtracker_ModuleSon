#include "mainwindow.h"
#include "Tests.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    starwars();

    return a.exec();
}
