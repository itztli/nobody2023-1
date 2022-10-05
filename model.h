// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#ifndef MODEL_H
#define MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "particle.h"
  
  typedef struct{
    char name[128];
    int N; //number of particles
    int i; //index of the last n-particle.
    Particle *particles; //set of particles
  }Model;

  void new_Model(Model *model, char name[], int N);
  
  void add_Particle_to_Model(Model *model, Particle particle);

  void print_Model(Model *model);
  
#ifdef __cplusplus
}

#endif

#endif
