// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#ifndef PHYSICS_H
#define PHYSICS_H

#ifdef __cplusplus
extern "C" {
#endif
  typedef struct{
    double x;
    double y;
    double z;
  }vector3D;

  
  double R(double x1,double y1,double z1,double x2,double y2,double z2);
  double F1D(double m1,double m2, double r, double u);
  double E1D(double m2, double r, double u);

  vector3D U(double x1, double y1,double z1,double x2,double y2,double z2);




#ifdef __cplusplus
}

#endif

#endif
