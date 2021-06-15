#ifndef POSITION_H
#define POSITION_H
#include "mainmac.h"
#include "sources.h"




class position
{
public:
    position();
    double Pi=3.14;
    float degtoradian(float deg);
    void positionministep(int timeslice, float Axisrotation, float Fanrotation);
    void positiononestep(int timeslice, float Axisrotation, float Fanrotation);
    void dataparameter(int *timestop);

private:
 float distancecrystal = 60;
 float Langang =45;
 int totaltime;
 float rotationdeg;
 int numberminiStep;
 int numberoneStep;
 float radiusFOV;
 double theta;
};
#endif // POSITION_H
