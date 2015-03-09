#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QString>
#include <string>
using std::string;

#include "findwindow.h"
#include "aiuto.h"
#include "table.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Container<Gioiello*> arc;
    Table* tab;
    QAction* Apri;
    QAction* Salva;
    QAction* Chiudi;
    QAction* Esci;
    QAction* Aggiungi;
    QAction* Rimuovi;
    QAction* Ricerca;
    QAction* Svuota;
    QAction* Inserisci;
    QAction* Help;
    QMenu* MenuFile;
    QMenu* MenuInserisci;
    QMenu* MenuAiuto;
    void ParseXML(QString, Container<Gioiello*> &);
    void GenerateXML(QFile &);
public:
    MainWindow(QWidget* parent = 0);
public slots:
    void OpenF();
    void Save();
    void Find();
    void Aid();
};

#endif // MAINWINDOW_H
