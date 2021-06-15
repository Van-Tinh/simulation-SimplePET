#ifndef SOURCES_H
#define SOURCES_H
#include "mainmac.h"



class Sources
{
public:
    Sources();
    void Activitysources(const QString filename, int Activity);
    void Contaniersources(float positionX, float positionY);
    void nhap(int A,  float pX,   float pY);


private:
    int Activity;
    float positionX;
    float positionY;
};

#endif // SOURCES_H
