// Clive Marvelous, last updated 3/3/24

#ifndef PARTICLE_H
#define PARTICLE_H

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

// Beginning of particle class
class particle
{
private:
  string type;
  double rest_mass; // MeV
  int charge;
  double velocity; // m/s
  double beta; // velocity/speed_of_light
  
  // Validation functions
  double validate_velocity(const double velocity_in) 
  {
    // Velocity cannot be greater than light_spd
    if(velocity_in>light_spd) throw std::invalid_argument("Velocity must not be greater than the speed of light.");
    // Velocity cannot be negative
    else if(velocity_in<0) throw std::invalid_argument("Velocity cannot be negative.");
    return velocity_in; 
  }
  
  string validate_type(string type_in) 
  {
    // Ensure input in lowercase
    lowercase(type_in);
    return type_in;
  }

  int validate_charge(const int charge_in) 
  {
    if(charge_in != 1 && charge_in != -1) throw std::invalid_argument("Charge must be either +1 or -1.");
    return charge_in; 
  }

  double validate_mass(const double mass_in) 
  {
    if(mass_in<0) throw std::invalid_argument("Rest mass cannot be negative.");
    return mass_in; 
  }
  
public:
  // Constructors
  particle() : type{}, rest_mass{}, charge{}, velocity{}, beta{} {}
  particle(string particle_type, double particle_rest_mass, int particle_charge, double particle_velocity) :
    type{validate_type(particle_type)}, rest_mass{validate_mass(particle_rest_mass)}, 
    charge{validate_charge(particle_charge)}, velocity{validate_velocity(particle_velocity)}, beta{velocity/light_spd}
  {}
  // Destructor
  ~particle(){std::cout<<"Destroying "<<type<<std::endl;}

  // Getter functions (accessors) to 
  string get_name() const {return type;}
  double get_mass() const {return rest_mass;}
  int get_charge() const {return charge;}
  double get_velocity() const {return velocity;}
  double get_beta() const {return beta;}

  // Setter functions, to change value of data members
  void set_type(string type_in) {type=validate_type(type_in);} 
  void set_mass(double mass_in) {rest_mass=validate_mass(mass_in);}
  void set_charge(int charge_in) {charge=validate_charge(charge_in);}
  void set_velocity(double velocity_in) 
  {
    velocity=validate_velocity(velocity_in);
    beta=velocity/light_spd;
  }

  // antiparticle function
  particle antiparticle(double v) const 
  {
    // Make a copy of the current object
    particle antipart = *this;

    // Update name and charge
    if (type == "electron") antipart.type = "positron";
    else if (type == "positron") antipart.type = "electron";
    else if (type == "muon") antipart.type = "antimuon";
    else if (type == "antimuon") antipart.type = "muon";
    else if (type == "tau") antipart.type = "antitau";
    else if (type == "antitau") antipart.type = "tau";
    antipart.charge = -charge; 
    antipart.velocity = v;

    return antipart; 
  }

  // Function to print info about a particle
  void print_data();

};

#endif