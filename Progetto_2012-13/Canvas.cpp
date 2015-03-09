#include "Canvas.h"

Canvas::Canvas(Valori* v,QWidget *parent):QWidget(parent),origine(0,600),estrX(800,600),estrY(0,20),val(v),chart(0)
{
    resize(1000,700);
}

void Canvas::SetOrigine(const QPointF & o)
{
    origine=o;
    update();
}

void Canvas::SetEstrX(const QPointF & ex)
{
    estrX=ex;
    update();
}

void Canvas::SetEstrY(const QPointF & ey)
{
    estrY=ey;
    update();
}

void Canvas::paintEvent(QPaintEvent *)
{
    if(chart)
    {
        if(chart->Spazio()>=estrX.x()-30)
        {
            QPointF newestrX(chart->Spazio()+50,estrX.y());
            SetEstrX(newestrX);
            resize(newestrX.x()+100,650);
        }
        else if(chart->Spazio()<estrX.x()+500)
        {
            QPointF newestrX(chart->Spazio()+50,estrX.y());
            SetEstrX(newestrX);
            resize(newestrX.x()+100,650);
        }
    }
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,4));
    if(chart)
        chart->Draw(painter);
}

void Canvas::CloseC()
{
    delete chart;
    chart=0;
    update();
}

void Canvas::Aggiorna()
{
    if(dynamic_cast<LineChart*>(chart))
    {
        double dist=chart->GetDistanza();
        delete chart;
        Dati* dati=new Dati(*val);
        chart=new LineChart(origine,dist,*dati);
     }
    else
        if(dynamic_cast<BarChart*>(chart))
         {
            BarChart* bar=dynamic_cast<BarChart*>(chart);
            double dist=bar->GetDistanza();
            double width=bar->GetWidth();
            delete chart;
            Dati*dati =new Dati(*val);
            chart=new BarChart(origine,dist-width,width ,*dati);
        }
    else
            if(dynamic_cast<PointChart*>(chart))
             {
                double dist=chart->GetDistanza();
                delete chart;
                Dati* dati=new Dati(*val);
                chart=new PointChart(origine,dist,*dati);
            }
    update();
}

void Canvas::DrawBar()
{
    if(chart)
        delete chart;
    Dati*dati =new Dati(*val);
    chart=new BarChart(origine,20,30 ,*dati);
    update();
}

void Canvas::DrawLine()
{
    if(chart)
        delete chart;
    Dati* dati=new Dati(*val);
    chart=new LineChart(origine,50,*dati);
    update();
}

void Canvas::DrawPoint()
{
    if(chart)
        delete chart;
    Dati* dati=new Dati(*val);
    chart=new PointChart(origine,50,*dati);
    update();
}

Canvas::~Canvas()
{
    delete chart;
}

