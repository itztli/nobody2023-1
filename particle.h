// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#ifndef PARTICLE_H
#define PARTICLE_H

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct{
    float mass;
    float p[3];
    float v[3];
    float a[3];
  }Particle;

  Particle new_Particle(int mass, float x, float y, float z, float vx, float vy, float vz);

  void print_Particle(Particle particle);
  
#ifdef __cplusplus
}

#endif

#endif
