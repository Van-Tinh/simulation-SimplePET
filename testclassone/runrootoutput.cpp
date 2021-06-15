#include "runrootoutput.h"

runrootoutput::runrootoutput()
{


}
void runrootoutput::inputfile(QString namefileroot)
{
    QFile runroot("../runrootoutput.sh");
    if (runroot.open(QIODevice::WriteOnly)){
        QTextStream write(&runroot);
        write<<"#!/bin/bash"<<endl;
        write<<"source /home/tinh/root/root_install/bin/thisroot.sh"<<endl;
        write<<"source /home/tinh/geant4/geant4.10.06.p02-install/bin/geant4.sh"<<endl<<endl;

       write<<"g++ -o fbpversion1 fbpversion1.cpp `root-config --cflags --libs` -O3 -std=c++0x"<<endl;
       write<<"./fbpversion1 \"Gate/output/" + namefileroot+ "\" 1"<<endl;



    }

}
