// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model.h"
#include "particle.h"

Model new_Model(char *name, int N){
  Model model;
  //sscanf(name,"%s",(*model).name);
  strcpy(model.name,name);
  model.N = N;
  model.i = 0;
  model.particles = malloc(sizeof(Particle)*N);
  model.backup_particles = malloc(sizeof(Particle)*N);
  return model;
}
  
void add_Particle_to_Model(Model *model, Particle particle){
  if ((*model).i < (*model).N){
    //printf("adding particle to model\n");
    (*model).particles[(*model).i] = particle;    
    (*model).backup_particles[(*model).i] = particle;
    (*model).i++;
  }else{
    printf("Warning: Not enough space for a new particle! %i\n",(*model).i);
  }
}

void print_Model(Model model){
  //printf("Printing model %i\n",(*model).i);
  for(int i; i< model.i; i++){
    print_Particle(model.particles[i]);
  }
}
