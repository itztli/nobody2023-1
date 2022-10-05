// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/GPL

#include <stdio.h>
#include <stdlib.h>

//MKS system

int main(int argn, char **args){

  Integrator trapezio;
  Model model3body;
  Particle particle1,particle2,particle3;

  float mass1,mass2,mass3;
  float x1,x2,x3, y1,y2,y3, z1,z2,z3;
  float vx1,vx2,vx3, vy1,vy2,vy3, vz1,vz2,vz3;

  char name[128];
  int N;

  int integrator; // 0: default (trapezium)
  float dt;

  // Initial conditions
  //integrator
  integrator = 0; //trapezium

  dt = 1.0; //sec
  
  // Model
  sscanf("3 Body","%s",name);
  N = 3;
  
  //particle 1
  mass1 = 1000.0; //Kg
  x1 = 0.0;  //m
  y1 = 0.0;  //m
  z1 = 0.0; //m
  
  vx1 = 0.0;  // m/s
  vy1 = 0.0;  // m/s
  vz1 = 0.0; //  m/s

  //particle 2
  mass2 = 1000.0; //Kg
  x2 = 10.0;  //m
  y2 = 0.0;  //m
  z2 = 0.0; //m
  
  vx2 = 0.0;  // m/s
  vy2 = 0.0;  // m/s
  vz2 = 0.0; //  m/s
  
  //particle 3
  mass3 = 1000.0; //Kg
  x3 = 20.0;  //m
  y3 = 0.0;  //m
  z3 = 0.0; //m
  
  vx3 = 0.0;  // m/s
  vy3 = 0.0;  // m/s
  vz3 = 0.0; //  m/s



  
  particle1 = new_Particle(mass1, x1, y1, z1, vx1, vy1, vz1);
  particle2 = new_Particle(mass2, x2, y2, z2, vx2, vy2, vz2);
  particle3 = new_Particle(mass3, x3, y3, z3, vx3, vy3, vz3);

  model3body = new_Model(name, N);
  
  add_Particle_to_Model(&model3body,particle1);
  add_Particle_to_Model(&model3body,particle2);
  add_Particle_to_Model(&model3body,particle3);

  trapezio = Integrator(integrator,dt);

  for(int i=0; i<100;i++){
    model3body = Integrator_solve(&trapecio, model3body);
    print_Model(model3body);
  }
  

  return 0;
}
