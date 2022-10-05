// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#include <stdio.h>
#include <stdlib.h>

#include "model.h"
#include "particle.h"

void new_Model(Model *model, char name[], int N){
  //Model model;
  sscanf(name,"%s",(*model).name);
  (*model).N = N;
  (*model).i = 0;
  (*model).particles = malloc(sizeof(Particle)*N);
}
  
void add_Particle_to_Model(Model *model, Particle particle){
  if ((*model).i < (*model).N){
    (*model).particles[(*model).i] = particle;
    (*model).i++;
  }else{
    printf("Warning: Not enough space for a new particle! %i\n",(*model).i);
  }
}

void print_Model(Model *model){
  for(int i; i< (*model).i; i++){
    print_Particle((*model).particles[i]);
  }
}
