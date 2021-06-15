#include "mainmac.h"

mainmac::mainmac()
{

}
void mainmac::filemainmac(int timestop, int timeslice, const QString nameoutput){
    QFile main("../Gate/mac/main.mac");
    if(main.open(QIODevice::WriteOnly)){
        QTextStream Write(&main);

Write<<"#/control/execute   mac/visu.mac"<<endl;
Write<<"/control/execute   mac/verbose.mac"<<endl<<endl;


Write<<"#====================================================="<<endl;
Write<<"# GEOMETRY"<<endl;
Write<<"#====================================================="<<endl;

Write<<"/control/execute mac/geometrycpet.mac"<<endl;
Write<<"/control/execute mac/sourcescontainer.mac"<<endl<<endl;

Write<<"/gate/sector/moves/insert  genericMove "<<endl<<endl;
Write<<"/gate/sector/genericMove/setPlacementsFilename mac/positiononestep.placements"<<endl;

Write<<"/gate/cassete/moves/insert  genericMove "<<endl;
Write<<"/gate/cassete/genericMove/setPlacementsFilename mac/positionministep.placements"<<endl;

Write<<"#====================================================="<<endl;
Write<<"# PHYSICS"<<endl;
Write<<"#====================================================="<<endl;
Write<<"/gate/physics/addPhysicsList FTFP_BERT_HP_EMZ"<<endl;

Write<<"/gate/physics/addProcess PhotoElectric"<<endl;
Write<<"/gate/physics/processes/PhotoElectric/setModel StandardModel"<<endl;
Write<<"/gate/physics/addProcess Compton"<<endl;
Write<<"/gate/physics/processes/Compton/setModel StandardModel"<<endl;

Write<<"/gate/physics/addProcess RayleighScattering"<<endl;
Write<<"/gate/physics/processes/RayleighScattering/setModel PenelopeModel"<<endl;

Write<<"/gate/physics/addProcess ElectronIonisation"<<endl;
Write<<"/gate/physics/processes/ElectronIonisation/setModel StandardModel e-"<<endl;
Write<<"/gate/physics/processes/ElectronIonisation/setModel StandardModel e+"<<endl;

Write<<"/gate/physics/addProcess Bremsstrahlung"<<endl;
Write<<"/gate/physics/processes/Bremsstrahlung/setModel StandardModel e-"<<endl;
Write<<"/gate/physics/processes/Bremsstrahlung/setModel StandardModel e+"<<endl;

Write<<"/gate/physics/addProcess PositronAnnihilation"<<endl;

Write<<"/gate/physics/addProcess MultipleScattering e+"<<endl;
Write<<"/gate/physics/addProcess MultipleScattering e-"<<endl;

Write<<"/gate/physics/processList Enabled"<<endl;
Write<<"/gate/physics/processList Initialized"<<endl<<endl;

Write<<"#====================================================="<<endl;
Write<<"# CUTS"<<endl;
Write<<"#====================================================="<<endl<<endl;

Write<<"/gate/physics/Gamma/SetCutInRegion      CsI 1.0 mm"<<endl;
Write<<"/gate/physics/Electron/SetCutInRegion   CsI 1.0 mm"<<endl;
Write<<"/gate/physics/Positron/SetCutInRegion   CsI 1.0 mm"<<endl<<endl;

Write<<"#====================================================="<<endl;
Write<<"# INITIALISATION"<<endl;
Write<<"#====================================================="<<endl<<endl;

Write<<"/gate/run/initialize"<<endl<<endl;


Write<<"/control/execute mac/digitizerPET.mac"<<endl<<endl;

Write<<"#====================================================="<<endl;
Write<<"#    S O U R C E"<<endl;
Write<<"#====================================================="<<endl<<endl;

Write<<"/control/execute mac/sourcesNa22.mac"<<endl<<endl;

Write<<"#====================================================="<<endl;
Write<<"#  D A T A   O U T P U T   "<<endl;
Write<<"#====================================================="<<endl<<endl;

Write<<"/gate/output/root/enable"<<endl;
Write<<"/gate/output/root/setFileName            output/"+nameoutput <<endl;
Write<<"/gate/output/root/setRootHitFlag          1"<<endl;
Write<<"/gate/output/root/setRootSinglesFlag      1"<<endl;
Write<<"/gate/output/root/setRootcutSinglesFlag   1"<<endl;
Write<<"/gate/output/root/setRootCoincidencesFlag 1   "<<endl<<endl;

Write<<"#===================================================="<<endl;
Write<<"#  R A N D O M   E N G I N E  A N D  S E E D"<<endl;
Write<<"#===================================================="<<endl;
Write<<"# JamesRandom Ranlux64 MersenneTwister"<<endl;
Write<<"/gate/random/setEngineName JamesRandom"<<endl;
Write<<"/gate/random/setEngineSeed auto"<<endl;
Write<<"/gate/random/verbose 1"<<endl<<endl;

Write<<"#====================================================="<<endl;
Write<<"#   M E A S U R E M E N T   S E T T I N G S   "<<endl;
Write<<"#====================================================="<<endl<<endl;

Write<<"/gate/application/setTimeSlice   "<<timeslice<<" s"<<endl;
Write<<"/gate/application/setTimeStart   0 s"<<endl;
Write<<"/gate/application/setTimeStop    "<<timestop<<" s"<<endl<<endl;

Write<<"/gate/application/startDAQ"<<endl<<endl;
    }

}
