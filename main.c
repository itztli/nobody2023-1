// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/GPL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "numeric.h"
#include "model.h"
#include "particle.h"

//MKS system

int main(int argn, char **args){

  Integrator trapezio,riemann;
  Model model3body;
  Particle particle1,particle2,particle3;

  double mass1,mass2,mass3;
  double x1,x2,x3, y1,y2,y3, z1,z2,z3;
  double vx1,vx2,vx3, vy1,vy2,vy3, vz1,vz2,vz3;
  //  double ax1,ax2,ax3, ay1,ay2,ay3, az1,az2,az3;

  char name[128];
  int N;

  int integrator; // 0: default (trapezium)
  double dt;

  // Initial conditions
  //integrator
  integrator = 1; //0:trapezium 1:Riemann

  dt = 0.001; //sec
  
  // Model
  //sscanf("3 Body","%s",name);


  N = 3;
  
  //particle 1
  mass1 = 100.0; //Kg
  x1 = 0.0;  //m
  y1 = 0.0;  //m
  z1 = 0.0; //m
  
  vx1 = 0.0;  // m/s
  vy1 = 0.0;  // m/s
  vz1 = 0.0; //  m/s

 
  //particle 2
  mass2 = 100.0; //Kg
  x2 = 0.10;  //m
  y2 = 0.0;  //m
  z2 = 0.0; //m
  
  vx2 = 0.0;  // m/s
  vy2 = 0.0;  // m/s
  vz2 = 0.0; //  m/s

  //particle 3
  mass3 = 100.0; //Kg
  x3 = 0.20;  //m
  y3 = 0.0;  //m
  z3 = 0.0; //m
  
  vx3 = 0.0;  // m/s
  vy3 = 0.0;  // m/s
  vz3 = 0.0; //  m/s

  
  particle1 = new_Particle(mass1, x1, y1, z1, vx1, vy1, vz1);
  particle2 = new_Particle(mass2, x2, y2, z2, vx2, vy2, vz2);
  particle3 = new_Particle(mass3, x3, y3, z3, vx3, vy3, vz3);

  model3body = new_Model("3Body system", N);
  printf("#3body %i\n",model3body.N);
  
  printf("#Welcome to n-body!\n");
  add_Particle_to_Model(&model3body,particle1);
  //printf("model.i=%i\n",model3body.i);
  add_Particle_to_Model(&model3body,particle2);
  //printf("model.i=%i\n",model3body.i);
  add_Particle_to_Model(&model3body,particle3);
  //printf("model.i=%i\n",model3body.i);
  //printf("Integrator %i\n",integrator);
  
  riemann = new_integrator(integrator,dt);

  printf("%i\n",model3body.i);
  for(int i=0; i< 300000;i++){    
    model3body = integrator_solve(riemann, model3body);
    if ((i % 3000) == 0){
      printf("#%i\n",i);
      print_Model(model3body);
    }
  }

  return 0;
}
