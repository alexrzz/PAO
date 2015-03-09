#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    MainWindow widget;
    QObject::connect(qApp,SIGNAL(lastWindowClosed()),qApp,SLOT(quit()));
    widget.show();
    return app.exec();
}
