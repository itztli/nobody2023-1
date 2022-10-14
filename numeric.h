// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#ifndef NUMERIC_H
#define NUMERIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "model.h"

  typedef struct{
    int numeric_method; //0: trapezium
    double dt;
  }Integrator;

  Integrator new_integrator(int numeric_method, double dt);
  
  Model integrator_solve(Integrator integrator, Model model);

#ifdef __cplusplus
}

#endif

#endif
