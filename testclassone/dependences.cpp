#include "dependences.h"

dependences::dependences()
{

}

void dependences::parameter(char **argv)
{
    QString a, b;
    a= argv[1];
    QFile sinogram("../dependences.sh");
    if(sinogram.open(QIODevice::WriteOnly));
    QTextStream write(&sinogram);
    write<<"#!/bin/bash"<<endl;
    write<<"./sinogram ";

    char s[]= "aas ";





}
