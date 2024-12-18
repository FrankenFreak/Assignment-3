// PHYS 30762 Programming in C++
// Assignment 3
// Practice with C++ classes and their interactions
// Author: Clive Marvelousu (10916086)
// Date: 3/3/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cctype>
#include<algorithm>
#include "particle.h"
#include "detector.h"

#define light_spd 2.99792458e8 // m/s
using std::string;

// Functions and constants
void lowercase(std::string& input);

// Main program
int main()
{
  double electron_mass{0.5}; // MeV
  double muon_mass{106}; // MeV
  double tau_mass{1777}; // MeV

  // Create the following particles: 
  // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau
  std::vector<particle> particle_data;
  particle_data.push_back(particle{"electron", electron_mass, -1, 2.1e8});
  particle_data.push_back(particle("electron", electron_mass, -1, 2e8));
  particle_data.push_back(particle_data[0].antiparticle(1.5e8));
  particle_data.push_back(particle("muon", muon_mass, -1, 1.8e8));
  particle_data.push_back(particle("muon", muon_mass, -1, 1.9e8));
  particle_data.push_back(particle("muon", muon_mass, -1, 2.9e8));
  particle_data.push_back(particle("muon", muon_mass, -1, 1e8));
  particle_data.push_back(particle_data[3].antiparticle(1.7e8));
  particle_data.push_back(particle("tau", tau_mass, -1, 1.98e8));
  particle_data.push_back(particle("tau", tau_mass, -1, 1.5e8));
  particle_data.push_back(particle("tau", tau_mass, -1, 2.98e8));
  particle_data.push_back(particle_data[8].antiparticle(2.4e8));

  // Create the following detectors: a tracker, a calorimeter, a muon chamber
  detector tracker{"tracker", 1};
  detector calorimeter{"calorimeter", 1};
  detector muon_chamber{"muon chamber", 1};

  // Print out the data from all the particles (put them in a vector)
  for(auto particle_it=particle_data.begin(); particle_it!=particle_data.end(); ++particle_it)
  {
    particle_it->print_data();
  }

  // Detect particles
  for(auto particle_it=particle_data.begin(); particle_it!=particle_data.end(); ++particle_it)
  {
    tracker.detect(*particle_it);
    calorimeter.detect(*particle_it);
    muon_chamber.detect(*particle_it);
  }

  // Turn off detectors
  tracker.set_status(0);
  calorimeter.set_status(0);
  muon_chamber.set_status(0);

  // Print a summary of how many particles were detected
  std::cout<<std::endl;
  tracker.print_data();
  calorimeter.print_data();
  muon_chamber.print_data();
  std::cout<<std::endl;

  return 0;
}

void lowercase(string& input) 
{
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {return std::tolower(c);});
    return;
}