#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), val()
{
    setWindowTitle("qCharts");
    Apri = new QAction("Apri",this);
    Apri->setShortcuts(QKeySequence::Open);
    Salva = new QAction("Salva",this);
    Salva->setShortcuts(QKeySequence::Save);
    Chiudi = new QAction("Chiudi",this);
    Chiudi->setShortcuts(QKeySequence::Close);
    Esci = new QAction("Esci",this);
    Esci->setShortcuts(QKeySequence::Quit);
    Barchart = new QAction("Barchart",this);
    Linechart = new QAction("Linechart",this);
    Pointchart = new QAction("PointChart",this);
    Aggiungi = new QAction("Aggiungi",this);
    Aggiungi->setShortcuts(QKeySequence::New);
    Inserisci = new QAction("Inserisci",this);
    Inserisci->setShortcuts(QKeySequence::Refresh);
    Help = new QAction("Aiuto",this);
    Help->setShortcuts(QKeySequence::HelpContents);
    MenuFile = new QMenu("File",this);
    MenuFile->addAction(Apri);
    MenuFile->addAction(Salva);
    MenuFile->addAction(Chiudi);
    MenuFile->addAction(Esci);
    MenuGrafico = new QMenu("Grafico",this);
    MenuGrafico->addAction(Barchart);
    MenuGrafico->addAction(Linechart);
    MenuGrafico->addAction(Pointchart);
    MenuInserisci = new QMenu("Inserimento",this);
    MenuInserisci->addAction(Aggiungi);
    MenuInserisci->addAction(Inserisci);
    MenuAiuto = new QMenu("?",this);
    MenuAiuto->addAction(Help);
    menuBar()->addMenu(MenuFile);
    menuBar()->addMenu(MenuGrafico);
    menuBar()->addMenu(MenuInserisci);
    menuBar()->addMenu(MenuAiuto);
    md=new Mdi(&val,this);
    setCentralWidget(md);
    connect(Apri,SIGNAL(triggered()),this,SLOT(OpenF()));
    connect(Salva,SIGNAL(triggered()),this,SLOT(Save()));
    connect(Chiudi,SIGNAL(triggered()),this,SLOT(CloseF()));
    connect(Chiudi,SIGNAL(triggered()),md,SLOT(Close()));
    connect(Esci,SIGNAL(triggered()),this,SLOT(close()));
    connect(Linechart,SIGNAL(triggered()),md,SLOT(Line()));
    connect(Barchart,SIGNAL(triggered()),md,SLOT(Bar()));
    connect(Pointchart,SIGNAL(triggered()),md,SLOT(Point()));
    connect(Aggiungi,SIGNAL(triggered()),md,SLOT(Add()));
    connect(Inserisci,SIGNAL(triggered()),md,SLOT(InsVal()));
    connect(Help,SIGNAL(triggered()),this,SLOT(Aid()));
}

void MainWindow::ParseXML(QString nomefile,Valori & v)
{
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
            if(xml.name() == "Squadra")
            {
                string nome="";
                int punti=0;
                while(!(xml.tokenType() == QXmlStreamReader::EndElement))
                {
                    if(xml.name()=="Nome")
                    {
                        QString nomest=xml.readElementText();
                        nome=nomest.toStdString();
                    }
                    if(xml.name()=="Punti")
                    {
                        QString puntist=xml.readElementText();
                        punti=puntist.toInt();
                    }
                    xml.readNext();
                }
                Squadra* squadra=new Squadra(nome,punti);
                v.Add(*squadra);
            }
        }
    }
    if(xml.hasError())
    {
        QMessageBox::critical(this,"Errore",xml.errorString(),QMessageBox::Ok);
        v.DelAll();
    }
    xml.clear();
    file->close();
    md->Open();
}

void MainWindow::GenerateXML(QFile& file)
{
        QXmlStreamWriter xml;
        xml.setDevice(&file);
        xml.setAutoFormatting(true);
        xml.writeStartDocument();
        xml.writeStartElement("QCharts");
        for(int i=0;i<val.Dim() && !xml.hasError();i++)
        {
            Squadra* sq=val[i];
            QString nomest=QString::fromStdString((sq->GetNome()));
            int punti=sq->GetPunti();
            QString puntist=QString::number(punti);
            xml.writeStartElement("Squadra");
            xml.writeTextElement("Nome",nomest);
            xml.writeTextElement("Punti",puntist);
            xml.writeEndElement();
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
    QString nomefile;
    nomefile = QFileDialog::getOpenFileName(this,"Apri file",QDir::currentPath(),"*.xml");
    ParseXML(nomefile,val);
}

void MainWindow::Save()
{
    if(val.Dim())
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
                    QMessageBox::critical(this,"Errore","File di sola lettura",QMessageBox::Ok);
                }
            }
    }
    else
        QMessageBox::critical(this,"Errore","File vuoto",QMessageBox::Ok);
}

void MainWindow::CloseF()
{
    if(val.Dim())
    {
        val.DelAll();
    }
    else
        QMessageBox::critical(0,"Errore","Non ci sono dati da chiudere!");
}

void MainWindow::Aid()
{
    Aiuto* ai = new Aiuto(this);
    ai->show();
}
