#include "IHMMainWindow.h"
#include <QApplication>
#include <controleur.h>
#include "Tests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHMMainWindow w;
    StMorceau m;
    new Controleur(&w,&m);
    w.resize(1024,768);
    w.setWindowTitle("SoundTracker");
    w.show();

    return a.exec();
}
