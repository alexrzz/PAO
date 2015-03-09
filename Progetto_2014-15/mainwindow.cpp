#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), arc()
{
    resize(700,400);
    setWindowTitle("LinQedIn");
    tab = new Tab(&arc);
    setCentralWidget(tab);
    Apri = new QAction("Apri",this);
    Apri->setShortcuts(QKeySequence::Open);
    Salva = new QAction("Salva",this);
    Salva->setShortcuts(QKeySequence::Save);
    Chiudi = new QAction("Chiudi",this);
    Chiudi->setShortcuts(QKeySequence::Close);
    Esci = new QAction("Esci",this);
    Esci->setShortcuts(QKeySequence::Quit);
    Aggiungi = new QAction("Aggiungi",this);
    Aggiungi->setShortcuts(QKeySequence::New);
    Rimuovi = new QAction("Rimuovi",this);
    Rimuovi->setShortcuts(QKeySequence::Delete);
    RicercaAdmin = new QAction("Ricerca",this);
    RicercaAdmin->setShortcuts(QKeySequence::Find);
    Inserisci = new QAction("Aggiorna il DB",this);
    Inserisci->setShortcuts(QKeySequence::Refresh);
    Help = new QAction("Num. elementi",this);
    Help->setShortcuts(QKeySequence::HelpContents);
    login = new QAction("Login",this);
    ricerca = new QAction("Ricerca",this);
    risultato = new QAction("Vedi Risultato",this);
    MenuFile = new QMenu("File",this);
    MenuFile->addAction(Apri);
    MenuFile->addAction(Salva);
    MenuFile->addAction(Chiudi);
    MenuFile->addAction(Esci);
    MenuAdmin = new QMenu("Admin",this);
    MenuAdmin->addAction(Aggiungi);
    MenuAdmin->addAction(Rimuovi);
    MenuAdmin->addAction(Inserisci);
    MenuAdmin->addAction(RicercaAdmin);
    MenuAiuto = new QMenu("?",this);
    MenuAiuto->addAction(Help);
    MenuClient = new QMenu("Client",this);
    MenuClient->addAction(login);
    MenuClient->addAction(ricerca);
    MenuClient->addAction(risultato);
    menuBar()->addMenu(MenuFile);
    menuBar()->addMenu(MenuAdmin);
    menuBar()->addMenu(MenuAiuto);
    menuBar()->addMenu(MenuClient);
    ricerca->setEnabled(false);
    risultato->setEnabled(false);
    connect(Apri,SIGNAL(triggered()),this,SLOT(OpenF()));
    connect(Salva,SIGNAL(triggered()),this,SLOT(Save()));
    connect(Chiudi,SIGNAL(triggered()),tab,SLOT(DelAll()));
    connect(Esci,SIGNAL(triggered()),this,SLOT(close()));
    connect(Aggiungi,SIGNAL(triggered()),tab,SLOT(Add()));
    connect(Rimuovi,SIGNAL(triggered()),tab,SLOT(Remove()));
    connect(Inserisci,SIGNAL(triggered()),tab,SLOT(InsVal()));
    connect(Help,SIGNAL(triggered()),this,SLOT(Aid()));
    connect(RicercaAdmin,SIGNAL(triggered()),this,SLOT(Find()));
    connect(login,SIGNAL(triggered()),this,SLOT(Log()));
    connect(ricerca,SIGNAL(triggered()),this,SLOT(FindC()));
    connect(risultato,SIGNAL(triggered()),this,SLOT(mostraRisultato()));
}

void MainWindow::disableLogin() {
    ricerca->setEnabled(true);
    login->setEnabled(false);
}

void MainWindow::Find() {
    FindAdmin* trova=new FindAdmin(&arc,this);
    trova->show();
}

void MainWindow::FindC() {
    log = tab->getClient()->getLogged();
    FindClient* trova=new FindClient(log,&arc,this);
    trova->show();
    connect(trova,SIGNAL(searchOk(Utente*)),this,SLOT(displayUser(Utente*)));
}

void MainWindow::displayUser(Utente* p) {
    risultato->setEnabled(true);
    ris = p;
}

void MainWindow::mostraRisultato() {
    ShowResult* ricercato = new ShowResult(log,ris,this);
    ricercato->show();
}

void MainWindow::Log() {
    Login* logi=new Login(&arc,this);
    connect(logi,SIGNAL(loginOk(string, Utente*)),tab->getClient(),SLOT(loggedIn(string, Utente*)));
    connect(logi,SIGNAL(noMoreLogin()),this,SLOT(disableLogin()));
    connect(logi,SIGNAL(noMoreLogin()),tab,SLOT(setClientTab()));
    logi->show();
}

void MainWindow::ParseXML(QString nomefile,vector<Utente*>& a ) {
    QFile* file = new QFile(nomefile);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this,"Errore","File non aperto",QMessageBox::Ok);
        return;
    }
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        if(token == QXmlStreamReader::StartElement)
        {
            if(xml.name() == "UtenteBasic")
            {
                string nome = "";
                string cognome = "";
                string email = "";
                string titoloStudio = "";
                string lingue = "";
                while(!(xml.tokenType() == QXmlStreamReader::EndElement))
                {
                    if(xml.name() == "Nome")
                    {
                        QString nomest = xml.readElementText();
                        nome = nomest.toStdString();
                    }
                    if(xml.name() == "Cognome")
                    {
                        QString cognomest = xml.readElementText();
                        cognome = cognomest.toStdString();
                    }
                    if(xml.name() == "Email")
                    {
                        QString emailst = xml.readElementText();
                        email = emailst.toStdString();
                    }
                    if(xml.name() == "TitoloDiStudio")
                    {
                        QString titstudst = xml.readElementText();
                        titoloStudio = titstudst.toStdString();
                    }
                    if(xml.name() == "Lingue")
                    {
                        QString linguest = xml.readElementText();
                        lingue = linguest.toStdString();
                    }
                    xml.readNext();
                }
                UtenteBasic* utenteBasic=new UtenteBasic(nome,cognome,email,vector<Utente*>(),titoloStudio,lingue);
                a.push_back(utenteBasic);
            }
            else if(xml.name() == "UtenteBusiness")
            {
                string nome = "";
                string cognome = "";
                string email = "";
                string titoloStudio = "";
                string lingue = "";
                string espProf = "";
                while(!(xml.tokenType() == QXmlStreamReader::EndElement))
                {
                    if(xml.name() == "Nome")
                    {
                        QString nomest = xml.readElementText();
                        nome = nomest.toStdString();
                    }
                    if(xml.name() == "Cognome")
                    {
                        QString cognomest = xml.readElementText();
                        cognome = cognomest.toStdString();
                    }
                    if(xml.name() == "Email")
                    {
                        QString emailst = xml.readElementText();
                        email = emailst.toStdString();
                    }
                    if(xml.name() == "TitoloDiStudio")
                    {
                        QString titstudst = xml.readElementText();
                        titoloStudio = titstudst.toStdString();
                    }
                    if(xml.name() == "Lingue")
                    {
                        QString linguest = xml.readElementText();
                        lingue = linguest.toStdString();
                    }
                    if(xml.name() == "EspProf")
                    {
                        QString espprofst = xml.readElementText();
                        espProf = espprofst.toStdString();
                    }
                    xml.readNext();
                }
                UtenteBusiness* utenteBusiness=new UtenteBusiness(nome,cognome,email,vector<Utente*>(),titoloStudio,lingue,espProf);
                a.push_back(utenteBusiness);
            }
            else if(xml.name() == "UtenteExecutive")
            {
                string nome = "";
                string cognome = "";
                string email = "";
                string titoloStudio = "";
                string lingue = "";
                string espProf = "";
                string presentazione = "";
                while(!(xml.tokenType() == QXmlStreamReader::EndElement))
                {
                    if(xml.name() == "Nome")
                    {
                        QString nomest = xml.readElementText();
                        nome = nomest.toStdString();
                    }
                    if(xml.name() == "Cognome")
                    {
                        QString cognomest = xml.readElementText();
                        cognome = cognomest.toStdString();
                    }
                    if(xml.name() == "Email")
                    {
                        QString emailst = xml.readElementText();
                        email = emailst.toStdString();
                    }
                    if(xml.name() == "TitoloDiStudio")
                    {
                        QString titstudst = xml.readElementText();
                        titoloStudio = titstudst.toStdString();
                    }
                    if(xml.name() == "Lingue")
                    {
                        QString linguest = xml.readElementText();
                        lingue = linguest.toStdString();
                    }
                    if(xml.name() == "EspProf")
                    {
                        QString espprofst = xml.readElementText();
                        espProf = espprofst.toStdString();
                    }
                    if(xml.name() == "Presentazione")
                    {
                        QString presentazionest = xml.readElementText();
                        presentazione = presentazionest.toStdString();
                    }
                    xml.readNext();
                }
                UtenteExecutive* utenteExecutive = new UtenteExecutive(nome,cognome,email,vector<Utente*>(),titoloStudio,lingue,espProf,presentazione);
                a.push_back(utenteExecutive);
            }
        }
    }
    if(xml.hasError())
    {
        QMessageBox::critical(this,"Errore",xml.errorString(),QMessageBox::Ok);
        a.clear();
    }
    xml.clear();
    file->close();
    tab->NewVal();
}

void MainWindow::GenerateXML(QFile& file) {
    QXmlStreamWriter xml;
    xml.setDevice(&file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("LinQedIn");
    vector<Utente*>::iterator it = arc.begin();
    for( ; it!=arc.end() && !xml.hasError();it++)
    {
        Utente* ut=*it;
        QString nomest=QString::fromStdString((ut->getNome()));
        QString cognomest=QString::fromStdString((ut->getCognome()));
        QString emailst=QString::fromStdString((ut->getEmail()));
        if(dynamic_cast<UtenteBasic*>(*it) && !dynamic_cast<UtenteBusiness*>(*it) && !dynamic_cast<UtenteExecutive*>(*it))
        {
            UtenteBasic* utenteBasic=dynamic_cast<UtenteBasic*>(*it);
            QString titstudst = QString::fromStdString((utenteBasic->getTitoloStudio()));
            QString linguest = QString::fromStdString((utenteBasic->getLingue()));
            xml.writeStartElement("UtenteBasic");
            xml.writeTextElement("Nome",nomest);
            xml.writeTextElement("Cognome",cognomest);
            xml.writeTextElement("Email",emailst);
            xml.writeTextElement("TitoloDiStudio",titstudst);
            xml.writeTextElement("Lingue",linguest);
            xml.writeEndElement();
        }
        else
            if(dynamic_cast<UtenteBusiness*>(*it) && !dynamic_cast<UtenteExecutive*>(*it))
            {
                UtenteBusiness* utenteBusiness=dynamic_cast<UtenteBusiness*>(*it);
                QString titstudst = QString::fromStdString((utenteBusiness->getTitoloStudio()));
                QString linguest = QString::fromStdString((utenteBusiness->getLingue()));
                QString espprofst = QString::fromStdString((utenteBusiness->getEspProf()));
                xml.writeStartElement("UtenteBusiness");
                xml.writeTextElement("Nome",nomest);
                xml.writeTextElement("Cognome",cognomest);
                xml.writeTextElement("Email",emailst);
                xml.writeTextElement("TitoloDiStudio",titstudst);
                xml.writeTextElement("Lingue",linguest);
                xml.writeTextElement("EspProf",espprofst);
                xml.writeEndElement();
            }
            else
                if(dynamic_cast<UtenteExecutive*>(*it))
                {
                    UtenteExecutive* utenteExecutive=dynamic_cast<UtenteExecutive*>(*it);
                    QString titstudst = QString::fromStdString((utenteExecutive->getTitoloStudio()));
                    QString linguest = QString::fromStdString((utenteExecutive->getLingue()));
                    QString espprofst = QString::fromStdString((utenteExecutive->getEspProf()));
                    QString presentazionest = QString::fromStdString((utenteExecutive->getPresentazione()));
                    xml.writeStartElement("UtenteExecutive");
                    xml.writeTextElement("Nome",nomest);
                    xml.writeTextElement("Cognome",cognomest);
                    xml.writeTextElement("Email",emailst);
                    xml.writeTextElement("TitoloDiStudio",titstudst);
                    xml.writeTextElement("Lingue",linguest);
                    xml.writeTextElement("EspProf",espprofst);
                    xml.writeTextElement("Presentazione",presentazionest);
                    xml.writeEndElement();
                }
    }
    xml.writeEndElement();
    xml.writeEndDocument();
    file.close();
    if(xml.hasError())
    {
        QMessageBox::critical(this,"Errore","Impossibile creare il file XML",QMessageBox::Ok);
    }
}

void MainWindow::OpenF()
{
    if(tab->getTabella()->rowCount() || !arc.empty()) QMessageBox::critical(this,"Errore","Prima chiudi il file corrente!",QMessageBox::Ok);
    else {
        QString nomefile;
        nomefile = QFileDialog::getOpenFileName(this,"Apri file",QDir::currentPath(),"*.xml");
        ParseXML(nomefile,arc);
    }
}

void MainWindow::CloseWindow(){
    if(tab->getTabella()->rowCount() || !arc.empty()) tab->DelAll();
    close();
}

void MainWindow::Save()
{
    if(!arc.empty())
    {
            QString filename = QFileDialog::getSaveFileName(this,tr("Salva come"),QDir::currentPath(),"*.xml");
            if(!filename.isEmpty())
            {
                QFile file(filename);
                if (file.open(QIODevice::WriteOnly))
                {
                    GenerateXML(file);
                    file.close();
                }
                else
                {
                    file.close();
                    QMessageBox::critical(this,"Errore","File di sola lettura!",QMessageBox::Ok);
                }
            }
    }
    else
        QMessageBox::critical(this,"Errore","Prima inserisci nel DB!",QMessageBox::Ok);
}

void MainWindow::Aid()
{
    Aiuto* ai = new Aiuto(&arc,this);
    ai->show();
}

MainWindow::~MainWindow()
{
    for(vector<Utente*>::const_iterator it=arc.begin();it!=arc.end();++it)
        delete *it;
}
