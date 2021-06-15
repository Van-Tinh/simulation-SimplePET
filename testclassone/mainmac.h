#ifndef MAINMAC_H
#define MAINMAC_H
#include <QString>
#include<QFile>
#include<QTextStream>
#include<string>
#include<cmath>



class mainmac
{
public:
    mainmac();
    void filemainmac(int timestop, int  timeslice, const QString nameoutput);
};

#endif // MAINMAC_H
