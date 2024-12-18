// Clive Marvelous, last updated 3/3/24

#include<iostream>
#include "particle.h"
#include "detector.h"

// Implementation of print_data function for particle class
void particle::print_data()
{
  std::cout<<"Particle: [type, rest mass (MeV), charge, velocity (m/s), beta] = ["<<type<<", "<< rest_mass
	   <<", "<<charge<<", ";
  std::cout.precision(3);
  std::cout<<velocity<<", "<<beta<<"]"<<std::endl;
  return;
}

// Implementation of print_data function for detector class
void detector::print_data()
{
  std::cout<<"Detector type: "<<type<<std::endl;
  std::cout<<"Total particles detected: "<<n_particles<<std::endl;
  std::cout<<"Electrons detected: "<<n_electron<<std::endl;
  std::cout<<"Positrons detected: "<<n_positron<<std::endl;
  std::cout<<"Muons detected: "<<n_muon<<std::endl;
  std::cout<<"Antimuons detected: "<<n_antimuon<<std::endl;
  return;
}