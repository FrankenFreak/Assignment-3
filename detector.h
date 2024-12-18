// Clive Marvelous, last updated 3/3/24

#ifndef DETECTOR_H
#define DETECTOR_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cctype>
#include<algorithm>

#define light_spd 2.99792458e8 // m/s
using std::string;

// Functions and constants
void lowercase(std::string& input);
const std::vector<string> detector_types{"tracker", "calorimeter", "muon chamber"};

// Beginning of detector class
class detector
{
private:
  string type; 
  bool status; // true if detector is turn on
  int n_particles; // Total number of particles detected
  int n_electron; // Number of electrons detected
  int n_positron; // Number of positron detected
  int n_muon; // Number of muon detected
  int n_antimuon; // Number of antimuon detected
 
  // Validation function
  string validate_type(string input) 
  {
    // Ensure input in lowercase
    lowercase(input);

    // Check for invalid name
    for(auto iterator=detector_types.begin(); iterator!=detector_types.end(); ++iterator)
    {
      if(input == *iterator) return input;
    }
    throw std::invalid_argument("Detector type is invalid."); 
  }

public:
  // Constructors
  detector() : type{}, status{}, n_particles{}, n_electron{}, n_positron{}, n_muon{}, n_antimuon{} {}
  detector(string detector_type, bool detector_status) : 
    type{validate_type(detector_type)}, status{detector_status}, n_particles{}, n_electron{}, n_positron{}, n_muon{}, n_antimuon{} {}
  // Destructor
  ~detector(){std::cout<<"Destroying "<<type<<std::endl;}

  // Setter functions, to change value of data members
  void set_type(string type_in) {type=validate_type(type_in);} 
  void set_status(double status_in) {status=status_in;}

  // Detect function
  int detect(const particle& p)
  {
    if(status && type == "tracker")
    {
      if(p.get_name() == "electron") 
      {
        ++n_electron;
        ++n_particles;
        std::cout<<"Electron was detected"<<std::endl;
        return 1;
      }
      else if(p.get_name() == "positron")
      {
        ++n_positron;
        ++n_particles;
        std::cout<<"Positron was detected"<<std::endl;
        return 1;
      }
      else if(p.get_name() == "muon")
      {
        ++n_muon;
        ++n_particles;
        std::cout<<"Muon was detected"<<std::endl;
        return 1;
      }
      else if(p.get_name() == "antimuon") 
      {
        ++n_antimuon;
        ++n_particles;
        std::cout<<"Antimuon was detected"<<std::endl;
        return 1;
      }
      else return 0;
    }
    else if(status && type == "calorimeter")
    {
      if(p.get_name() == "electron") 
      {
        ++n_electron;
        ++n_particles;
        std::cout<<"Electron was detected"<<std::endl;
        return 1;
      }
      else if(p.get_name() == "positron") 
      {
        ++n_positron;
        ++n_particles;
        std::cout<<"Positron was detected"<<std::endl;
        return 1;
      }
      else return 0;
    }
    else if(status && type == "muon chamber") 
    {
      if(p.get_name() == "muon") 
      {
        ++n_muon;
        ++n_particles;
        std::cout<<"Muon was detected"<<std::endl;
        return 1;
      }
      else if(p.get_name() == "antimuon") 
      {
        ++n_antimuon;
        ++n_particles;
        std::cout<<"Antimuon was detected"<<std::endl;
        return 1;
      }
      else return 0;
    }
    else return 0;
  }

  // Print data
  void print_data();
};

#endif