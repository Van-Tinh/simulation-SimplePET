#include "position.h"

position::position()
{

}
float position::degtoradian(float deg){
      float r;
      r = deg*Pi/180;
    return(r);

}
void position::positionministep(int timeslice, float Axisrotation, float Fanrotation){

    totaltime = 0;
    rotationdeg = Fanrotation;
    numberminiStep = Langang/Axisrotation;
    numberoneStep = 360/Fanrotation;
    radiusFOV = (sin(degtoradian(Langang/2)))*(distancecrystal/2);

   QFile fileministep("../Gate/mac/positionministep.placements");
   if (fileministep.open(QIODevice::WriteOnly)){
       QTextStream Write(&fileministep);
    Write<<"####### List of placement (translation and rotation) according to time"<<endl;
    Write<<"###### Column 1      is Time in s (second)"<<endl;
    Write<<"###### Column 2      is rotationAngle in degree"<<endl;
    Write<<"###### Columns 3,4,5 are rotation axis"<<endl;
    Write<<"###### Columns 6,7,8 are translation in mm"<<endl;
    Write<<"Time s"<<endl<<"Rotation deg"
    <<endl<<"Translation mm"<<endl;

    float TransitionX =0 , TransitionY = 0, TransitionZ = 0;

    for(int i = 0; i < numberoneStep ; i++){
        rotationdeg = Langang/2;
        theta = degtoradian(rotationdeg);
        for (int j = 0; j < numberminiStep; j++){

             TransitionX = (1 - cos(theta))*(distancecrystal/2);
             TransitionY = sin(theta)*(distancecrystal/2);

             Write <<totaltime<<" "<<rotationdeg<<" 0 0 1 "<<TransitionX<<" "<<TransitionY<<" "<<TransitionZ<<endl;
             totaltime = totaltime + timeslice;
             rotationdeg = rotationdeg - Fanrotation;
             theta = degtoradian(rotationdeg);
    }
}}
   QFile filedataparamete("../Gate/output/dataparameter.mac");
   if(filedataparamete.open(QIODevice::WriteOnly)){
   QTextStream filedataparameters(&filedataparamete);
   filedataparameters << " distancecrystal "<< distancecrystal<<endl;
   filedataparameters <<" TopAng " << Axisrotation <<endl;
   filedataparameters <<" BotAng " << Fanrotation<<endl;
   filedataparameters <<" LangeAng " << Langang<<endl;
   filedataparameters <<" numberminiStep " << numberminiStep<<endl;
   filedataparameters <<" numberoneStep " << numberoneStep<<endl;
   filedataparameters <<" Radius FOV "<< radiusFOV<<endl;
   totaltime=totaltime-timeslice;
   filedataparameters <<" totaltime " << totaltime << endl;
   filedataparameters <<" timeStep " << timeslice <<endl;
   //cout<<"timeStop "<<totaltime<<" s"<<endl;
   //cout<<"radiusFOV "<<radiusFOV<<" mm"<<endl;
}
}

void position::dataparameter(int *timestop){
    *timestop=totaltime;
}



void position::positiononestep(int timeslice, float Axisrotation, float Fanrotation){
    QFile fileonestep("../Gate/mac/positiononestep.placements");
    if (fileonestep.open(QIODevice::WriteOnly)){
        QTextStream Write(&fileonestep);
     Write<<"####### List of placement (translation and rotation) according to time"<<endl;
     Write<<"###### Column 1      is Time in s (second)"<<endl;
     Write<<"###### Column 2      is rotationAngle in degree"<<endl;
     Write<<"###### Columns 3,4,5 are rotation axis"<<endl;
     Write<<"###### Columns 6,7,8 are translation in mm"<<endl;
     Write<<"Time s"<<endl<<"Rotation deg"
     <<endl<<"Translation mm"<<endl;
     totaltime = 0;
     rotationdeg = Fanrotation;
     numberminiStep = Langang/Axisrotation;
     numberoneStep = 360/Fanrotation;
     radiusFOV = (sin(degtoradian(Langang/2)))*(distancecrystal/2);
     for(int i = 0; i < numberoneStep; i++){
         for(int j = 0; j < numberminiStep; j++){
             Write <<totaltime<<" "<<rotationdeg<<" 0 0 1 "<<"0 0 0 "<<endl;
             totaltime = totaltime + timeslice;
     }
         rotationdeg = rotationdeg - Fanrotation;
     }

}}

