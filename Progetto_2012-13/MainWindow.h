#ifndef MAINWINDOW_H
#define MAINWINDOW_h

#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QMainWindow>
#include <QMenu>
#include <QString>
#include <QAction>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMenuBar>
#include <QMessageBox>
#include <QApplication>
#include <string>
using std::string;

#include "Valori.h"
#include "Mdi.h"
#include "Aiuto.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Valori val;
    Mdi* md;
    QAction* Apri;
    QAction* Salva;
    QAction* Chiudi;
    QAction* Esci;
    QAction* Barchart;
    QAction* Linechart;
    QAction* Pointchart;
    QAction* Aggiungi;
    QAction* Inserisci;
    QAction* Help;
    QMenu* MenuFile;
    QMenu* MenuGrafico;
    QMenu* MenuInserisci;
    QMenu* MenuAiuto;
    void ParseXML(QString, Valori &);
    void GenerateXML(QFile &);
public:
    MainWindow(QWidget* parent = 0);
public slots:
    void OpenF();
    void Save();
    void CloseF();
    void Aid();
};

#endif // MAINWINDOW_H
