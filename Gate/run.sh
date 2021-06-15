#! /bin/bash

source /home/tinh/root/root_install/bin/thisroot.sh
source /home/tinh/geant4/geant4.10.06.p02-install/bin/geant4.sh
export PATH=$PATH:/home/tinh/gate/gate-9.0-install/bin/
env |grep G4

Gate mac/main.mac
