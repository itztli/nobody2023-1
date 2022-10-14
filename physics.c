// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#include "physics.h"
#include <math.h>

double R(double x1,double y1,double z1,double x2,double y2,double z2){
  double result;
  result = sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
  return result;
}

double F1D(double m1,double m2, double r, double u){
  double result;
  double G_gravity = 6.67430e-11; //MKS system
  result = G_gravity*m1*m2*u/pow(r,3);
  return result;
}

double E1D(double m2, double r, double u){
  double result;
  double G_gravity = 6.67430e-11; //MKS system
  result = G_gravity*m2*u/pow(r,3);
  return result;
}

vector3D U(double x1, double y1,double z1,double x2,double y2,double z2){
  vector3D u;
  u.x = x2 - x1;
  u.y = y2 - y1;
  u.z = z2 - z1;
  return u;
}
