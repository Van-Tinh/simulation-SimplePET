#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include<QString>
#include "sources.h"
#include "position.h"
#include "runrootoutput.h"
#include <QMessageBox>
#include <QProcess>
#include <QStringList>
#include <QDir>
#include <QPixmap>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::display()
{

    QPixmap sino, image ;
    sino.load("../recontrucstion/sinogram.png");
    image.load("../recontrucstion/image.png");

    ui->sinogram->setBackgroundRole(QPalette::Base);

    ui->sinogram->setPixmap(sino.scaled(160,160,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    //ui->sinogram->adjustSize();
    ui->image->setPixmap(image.scaled(160,160,Qt::KeepAspectRatio,Qt::SmoothTransformation));

}

void Widget::on_Apply_clicked()
{
    //write sources and contaniersources
 QString SA= ui->lineEdit->displayText();
QString psX = ui->AxisX->displayText();
QString psY = ui->AxisY->displayText();
QString name = ui->nameoutput->displayText();
Sources().Activitysources(name,SA.toInt());
Sources().Contaniersources(psX.toFloat(),psY.toFloat());
//write file position

QString Axisrotation = ui->Axisrotation->displayText();
QString Fanrotation = ui->Fanrotation ->displayText();
QString Timeslice = ui->Timeslice->displayText();

position().positiononestep(Timeslice.toInt(),Axisrotation.toFloat(),Fanrotation.toFloat());
position().positionministep(Timeslice.toInt(),Axisrotation.toFloat(),Fanrotation.toFloat());
//creative file main.mac
int timestop;
position().dataparameter(&timestop);
mainmac().filemainmac(timestop,Timeslice.toInt(),name);

}

void Widget::on_Ok_clicked()
{
    QDir a;
    QString path, paths ;
    path = a.absolutePath();
    int leng = path.length();
    paths = path.left(leng-32) + "Gate";
    ui->showhelpanderror->setText(paths);


    QProcess *runsimulation = new QProcess(this);
    runsimulation ->setWorkingDirectory(paths);
    runsimulation ->setProgram("/bin/bash");
    runsimulation ->setArguments({"-c", "./run.sh"});
    runsimulation ->startDetached();

   // runsimulation -> execute("/bin/bash", {"-c", "./run.sh"});
}

void Widget::on_Applyroot_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open root file"), "", tr("Text Files (*.root)"));

    QFileInfo infor(fileName);
    QString name = infor.fileName();

    runrootoutput().inputfile(name);
    ui-> showhelpanderror->setText(name);


}

void Widget::on_appl_clicked()
{
    QDir a;
    QString path, paths ;
    path = a.absolutePath();
    int leng = path.length();
    paths = path.left(leng-32);
    QProcess *runsimulation = new QProcess(this);
    runsimulation ->setWorkingDirectory(paths);
    runsimulation ->setProgram("/bin/bash");
    runsimulation ->setArguments({"-c", "./runrootoutput.sh"});
    runsimulation ->startDetached();


    QTimer *time = new QTimer(this);
    connect(time,&QTimer::timeout,this,QOverload<>::of(&Widget::display));
    time->start(1000);

//  QTimer::singleShot(10000,this,SLOT(display()));
}
void Widget::on_Cancel_clicked()
{
    QFile remove;
    remove.remove("../recontrucstion/sinogram.png");
    remove.remove("../recontrucstion/image.png");
}


