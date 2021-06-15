#include "sources.h"


Sources::Sources()
{

}
void Sources::nhap(int A, float pX, float pY){
    Activity=A; positionX=pX; positionY=pY;
}

void Sources::Contaniersources(float positionX,float positionY)
{
 QFile file("../Gate/mac/sourcescontainer.mac");
    if (file.open(QIODevice::WriteOnly)){
        QTextStream Write(&file);
        Write<<"# SOURCECONTAINER"<<endl;
        Write<<"      /gate/CPET/daughters/name                          container"<<endl;
        Write<<"      /gate/CPET/daughters/insert                        cylinder"<<endl;
        Write<<"      /gate/container/placement/setTranslation            "<<positionX<<" "<<positionY<<" 0.0 mm"<<endl;
        Write<<"      /gate/container/geometry/setRmin                    0 mm"<<endl;
        Write<<"      /gate/container/geometry/setRmax                    5 mm"<<endl;
        Write<<"      /gate/container/geometry/setHeight                  2 mm"<<endl;
        Write<<"      /gate/container/geometry/setPhiStart                0 deg"<<endl;
        Write<<"      /gate/container/geometry/setDeltaPhi                360 deg"<<endl;
        Write<<"      /gate/container/setMaterial                         PMMA"<<endl;
        Write<<"      /gate/container/vis/setVisible                      1"<<endl;
        Write<<"      /gate/container/vis/forceWireframe                    "<<endl;
        Write<<"      /gate/container/vis/setColor                        grey"<<endl;
    } else {qWarning("could not read file Container");}
}

void Sources::Activitysources(const QString filename, int Activity){
    QFile filesources("../Gate/mac/sourcesNa22.mac");
    if (filesources.open(QIODevice::WriteOnly)){
        QTextStream Write(&filesources);
        Write<<"/gate/source/addSource Na22 gps"<<endl;
        Write<<"       /gate/source/Na22/gps/particle       ion"<<endl;
        Write<<"       /gate/source/Na22/gps/ion             11 22 0 0"<<endl;
        Write<<"       /gate/source/Na22/setForcedUnstableFlag true"<<endl;
        Write<<"       /gate/source/Na22/useDefaultHalfLife "<<endl;
        Write<<"       /gate/source/Na22/setActivity           "<<Activity<<" Bq"<<endl;
        Write<<"       /gate/source/Na22/gps/type          Volume"<<endl;
        Write<<"       /gate/source/Na22/gps/shape         Cylinder"<<endl;
        Write<<"       /gate/source/Na22/gps/radius        0.5 mm"<<endl;
        Write<<"       /gate/source/Na22/gps/halfz         0.5 mm"<<endl;
        Write<<"       /gate/source/Na22/gps/angtype       iso"<<endl;
        Write<<"       /gate/source/Na22/attachTo          container"<<endl;

        Write<<"      /gate/source/Na22/visualize  200 blue 3"<<endl;

    }

}
