#!/bin/bash
source /home/tinh/root/root_install/bin/thisroot.sh
source /home/tinh/geant4/geant4.10.06.p02-install/bin/geant4.sh

g++ -o fbpversion1 fbpversion1.cpp `root-config --cflags --libs` -O3 -std=c++0x
./fbpversion1 "Gate/output/total-2uC-4-4.root" 1
