// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#include <stdio.h>
#include "particle.h"

Particle new_Particle(int mass, double x, double y, double z, double vx, double vy, double vz){
  Particle particle;
  particle.mass = mass;
  particle.p[0] = x;
  particle.p[1] = y;
  particle.p[2] = z;
  particle.v[0] = vx;
  particle.v[1] = vy;
  particle.v[2] = vz;
  return particle;
}

void print_Particle(Particle particle){
  printf("%le\t%le\t%le\t%le\t%le\t%le\t%le\n",particle.mass, particle.p[0],particle.p[1],particle.p[2],particle.v[0],particle.v[1],particle.v[2]);
}
