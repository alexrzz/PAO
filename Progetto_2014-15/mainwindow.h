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
#include <vector>
#include "aiuto.h"
#include "findadmin.h"
#include "tab.h"
#include "login.h"

using std::vector;
using std::string;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Utente* log, *ris;
    vector<Utente*> arc;
    Tab* tab;
    QAction* Apri;
    QAction* Salva;
    QAction* Chiudi;
    QAction* Esci;
    QAction* Aggiungi;
    QAction* Rimuovi;
    QAction* RicercaAdmin;
    QAction* Inserisci;
    QAction* Help;
    QAction* login;
    QAction* ricerca;
    QAction* risultato;
    QMenu* MenuFile;
    QMenu* MenuAdmin;
    QMenu* MenuAiuto;
    QMenu* MenuClient;
    void ParseXML(QString, vector<Utente*> &);
    void GenerateXML(QFile &);
public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
public slots:
    void OpenF();
    void FindC();
    void displayUser(Utente* p);
    void Save();
    void Aid();
    void CloseWindow();
    void Find();
    void Log();
    void disableLogin();
    void mostraRisultato();
};
#endif // MAINWINDOW_H
