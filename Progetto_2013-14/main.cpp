#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    MainWindow widget;
    QObject::connect(qApp,SIGNAL(lastWindowClosed()),qApp,SLOT(quit()));
    widget.resize(500,500);
    widget.show();
    return app.exec();
}
