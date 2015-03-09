#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), arc()
{
    setWindowTitle("qDB");
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
    Ricerca = new QAction("Ricerca",this);
    Ricerca->setShortcuts(QKeySequence::Find);
    Svuota = new QAction("Svuota container",this);
    Svuota->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    Inserisci = new QAction("Inserisci nel container",this);
    Inserisci->setShortcuts(QKeySequence::Refresh);
    Help = new QAction("Num. elementi",this);
    Help->setShortcuts(QKeySequence::HelpContents);
    MenuFile = new QMenu("File",this);
    MenuFile->addAction(Apri);
    MenuFile->addAction(Salva);
    MenuFile->addAction(Chiudi);
    MenuFile->addAction(Esci);
    MenuInserisci = new QMenu("Modifica",this);
    MenuInserisci->addAction(Aggiungi);
    MenuInserisci->addAction(Rimuovi);
    MenuInserisci->addAction(Ricerca);
    MenuInserisci->addAction(Svuota);
    MenuInserisci->addAction(Inserisci);
    MenuAiuto = new QMenu("?",this);
    MenuAiuto->addAction(Help);
    menuBar()->addMenu(MenuFile);
    menuBar()->addMenu(MenuInserisci);
    menuBar()->addMenu(MenuAiuto);
    tab=new Table(&arc,this);
    setCentralWidget(tab);
    connect(Apri,SIGNAL(triggered()),this,SLOT(OpenF()));
    connect(Salva,SIGNAL(triggered()),this,SLOT(Save()));
    connect(Chiudi,SIGNAL(triggered()),tab,SLOT(DelAll()));
    connect(Esci,SIGNAL(triggered()),this,SLOT(close()));
    connect(Aggiungi,SIGNAL(triggered()),tab,SLOT(Add()));
    connect(Rimuovi,SIGNAL(triggered()),tab,SLOT(Remove()));
    connect(Ricerca,SIGNAL(triggered()),this,SLOT(Find()));
    connect(Svuota,SIGNAL(triggered()),tab,SLOT(DelAll()));
    connect(Inserisci,SIGNAL(triggered()),tab,SLOT(InsVal()));
    connect(Help,SIGNAL(triggered()),this,SLOT(Aid()));
}

void MainWindow::Find() {
    FindWindow* trova=new FindWindow(&arc,this);
    trova->show();
}

void MainWindow::ParseXML(QString nomefile,Container<Gioiello*>& a ) {
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
            if(xml.name() == "Anello")
            {
                string materiale = "";
                int qualita = 0;
                double prezzo = 0.0;
                double misura = 0.0;
                bool solitario = false;
                while(!(xml.tokenType() == QXmlStreamReader::EndElement))
                {
                    if(xml.name() == "Materiale")
                    {
                        QString materialest = xml.readElementText();
                        materiale = materialest.toStdString();
                    }
                    if(xml.name() == "Qualita")
                    {
                        QString qualitast = xml.readElementText();
                        qualita = qualitast.toInt();
                    }
                    if(xml.name() == "Prezzo")
                    {
                        QString prezzost = xml.readElementText();
                        prezzo = prezzost.toDouble();
                    }
                    if(xml.name() == "Misura")
                    {
                        QString misurast = xml.readElementText();
                        misura = misurast.toDouble();
                    }
                    if(xml.name() == "Solitario")
                    {
                        QString solitariost = xml.readElementText();
                        solitario = solitariost.toInt();
                    }
                    xml.readNext();
                }
                Anello* anello=new Anello(materiale, qualita, prezzo, misura, solitario);
                a.add(anello);
            }
            else if(xml.name() == "Orecchino")
            {
                string materiale = "";
                int qualita = 0;
                double prezzo = 0.0;
                string chiusura = "";
                bool pendente = false;
                while(!(xml.tokenType() == QXmlStreamReader::EndElement))
                {
                    if(xml.name() == "Materiale")
                    {
                        QString materialest = xml.readElementText();
                        materiale = materialest.toStdString();
                    }
                    if(xml.name() == "Qualita")
                    {
                        QString qualitast = xml.readElementText();
                        qualita = qualitast.toInt();
                    }
                    if(xml.name() == "Prezzo")
                    {
                        QString prezzost = xml.readElementText();
                        prezzo = prezzost.toDouble();
                    }
                    if(xml.name() == "Chiusura")
                    {
                        QString chiusurast = xml.readElementText();
                        chiusura = chiusurast.toStdString();
                    }
                    if(xml.name() == "Pendente")
                    {
                        QString pendentest = xml.readElementText();
                        pendente = pendentest.toInt();
                    }
                    xml.readNext();
                }
                Orecchino* orecchino = new Orecchino(materiale, qualita, prezzo, chiusura, pendente);
                a.add(orecchino);
            }
        }
    }
    if(xml.hasError())
    {
        QMessageBox::critical(this,"Errore",xml.errorString(),QMessageBox::Ok);
        while (!a.is_empty()) a.pop_front();
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
    xml.writeStartElement("qDB");
    Container<Gioiello*>::Iteratore it = arc.begin();
    for( ; it!=arc.end() && !xml.hasError();it++) //accesso tramite iteratore
    {
        Gioiello* gp=arc[it];
        QString materialest=QString::fromStdString((gp->getMateriale()));
        int qualita=gp->getQualita();
        QString qualitast=QString::number(qualita);
        double prezzo = gp->getPrezzo();
        QString prezzost = QString::number(prezzo);
        if(dynamic_cast<Anello*>(arc[it]))
        {
            Anello* anello=dynamic_cast<Anello*>(arc[it]);
            double misura=anello->getMisura();
            QString misurast=QString::number(misura);
            bool solitario = anello->getSolitario();
            QString solitariost = QString::number(solitario);     //conversione bool a qstring
            xml.writeStartElement("Anello");
            xml.writeTextElement("Materiale",materialest);
            xml.writeTextElement("Qualita",qualitast);
            xml.writeTextElement("Prezzo",prezzost);
            xml.writeTextElement("Misura",misurast);
            xml.writeTextElement("Solitario",solitariost);
            xml.writeEndElement();
        }
        else
            if(dynamic_cast<Orecchino*>(arc[it]))
            {
                Orecchino* orecchino=dynamic_cast<Orecchino*>(arc[it]);
                QString chiusurast=QString::fromStdString((orecchino->getChiusura()));
                bool pendente = orecchino->getPendente();
                QString pendentest = QString::number(pendente);     //conversione bool a qstring
                xml.writeStartElement("Orecchino");
                xml.writeTextElement("Materiale",materialest);
                xml.writeTextElement("Qualita",qualitast);
                xml.writeTextElement("Prezzo",prezzost);
                xml.writeTextElement("Chiusura",chiusurast);
                xml.writeTextElement("Pendente",pendentest);
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
    if(tab->rowCount() || !arc.is_empty()) QMessageBox::critical(this,"Errore","Prima chiudi il file corrente!",QMessageBox::Ok);
    else {
        QString nomefile;
        nomefile = QFileDialog::getOpenFileName(this,"Apri file",QDir::currentPath(),"*.xml");
        ParseXML(nomefile,arc);
    }
}

void MainWindow::Save()
{
    if(!arc.is_empty())
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
        QMessageBox::critical(this,"Errore","Prima inserisci nel container!",QMessageBox::Ok);
}

void MainWindow::Aid()
{
    Aiuto* ai = new Aiuto(&arc,this);
    ai->show();
}
