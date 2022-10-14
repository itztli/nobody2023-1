// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#include <stdio.h>
#include <stdlib.h>
#include "numeric.h"
#include "model.h"
#include "physics.h"


Integrator new_integrator(int numeric_method, double dt){
  Integrator integrator;
  integrator.numeric_method = numeric_method;
  integrator.dt=dt;
  return integrator;
}
  
Model integrator_solve(Integrator integrator, Model model){
  int numeric_method = integrator.numeric_method;
  double x1,y1,z1,x2,y2,z2,x3,y3,z3,m1,m2;
  double sumx,sumy,sumz;
  double dt = integrator.dt;
  double vx,vy,vz,r_ij,r;
  double Fx,Fy,Fz;
  int N;
  vector3D u;
  
  //printf("Numeric method %i\n",numeric_method);
  switch(numeric_method)
    {

    case 0: //trapezium
      N= model.i;
      //printf("We are using the Trapezium Method %i\n",N);
      
      for(int i = 0; i < N; i++){
	
	//printf("%i\n",i);
	m1 = model.particles[i].mass;
	x1 = model.particles[i].p[0];
	y1 = model.particles[i].p[1];
	z1 = model.particles[i].p[2];
	sumx=sumy=sumz = 0.0;
	
	for(int j = 0; j < N; j++){
	  if (i != j){
	    m2 = model.particles[j].mass;
	    x2 = model.particles[j].p[0];
	    y2 = model.particles[j].p[1];
	    z2 = model.particles[j].p[2];
	    
	    r_ij = R(x1,y1,z1,x2,y2,z2);
	    
	    u = U(x1,y1,z1,x2,y2,z2);
	    Fx = F1D(m1,m2,r_ij,u.x);
	    Fy = F1D(m1,m2,r_ij,u.y);
	    Fz = F1D(m1,m2,r_ij,u.z);
	    
	    sumx += Fx + model.backup_particles[j].F[0];
	    sumy += Fy + model.backup_particles[j].F[1];
	    sumz += Fz + model.backup_particles[j].F[2];	  
	  }
	}

	printf("%i:%f\n",i,sumx);
	vx = sumx * dt / (2.0*m1);
	vy = sumy * dt / (2.0*m1);
	vz = sumz * dt / (2.0*m1);
	
	printf("%i:%f\n",i,vx);
	
	model.particles[i].F[0] = sumx;
	model.particles[i].F[1] = sumy;
	model.particles[i].F[2] = sumz;
	
	model.particles[i].v[0] += vx;
	model.particles[i].v[1] += vy;
	model.particles[i].v[2] += vz;
	
	model.particles[i].p[0] += model.particles[i].v[0]*dt;
	model.particles[i].p[1] += model.particles[i].v[1]*dt;
	model.particles[i].p[2] += model.particles[i].v[2]*dt;
      }
      
      for(int i = 0; i < model.i; i++){
	model.backup_particles[i].F[0] =model.particles[i].F[0];
	model.backup_particles[i].F[1] =model.particles[i].F[1];
	model.backup_particles[i].F[2] =model.particles[i].F[2];
	
	model.backup_particles[i].v[0] =model.particles[i].v[0];
	model.backup_particles[i].v[1] =model.particles[i].v[1];
	model.backup_particles[i].v[2] =model.particles[i].v[2];
	
	model.backup_particles[i].p[0] =model.particles[i].p[0];
	model.backup_particles[i].p[1] =model.particles[i].p[1];
	model.backup_particles[i].p[2] =model.particles[i].p[2];
	
      }
      break;
    
    case 1: //Riemann

      for (int i=0; i< model.i;i++){
	m1 = model.particles[i].mass;
	x1 = model.particles[i].p[0];
	y1 = model.particles[i].p[1];
	z1 = model.particles[i].p[2];	
	//printf("1:%le,%le,%le,%le\n",m1,x1,y1,z1);
	for (int j=0; j< model.i;j++){
	  
	  if (i!=j){
	    m2 = model.particles[j].mass;
	    x2 = model.particles[j].p[0];
	    y2 = model.particles[j].p[1];
	    z2 = model.particles[j].p[2];
	    //printf("\t2:%le,%le,%le,%le\n",m2,x2,y2,z2);
	    r = R(x1,y1,z1,x2,y2,z2);
	    //printf("\t\t r:%le\n",r);
	    u = U(x1,y1,z1,x2,y2,z2);
	    model.particles[i].v[0] += E1D(m2,r,u.x)*dt;
	    model.particles[i].v[1] += E1D(m2,r,u.y)*dt;
	    model.particles[i].v[2] += E1D(m2,r,u.z)*dt;
	  }	  
	}

	for (int i=0; i< model.i;i++){
	  model.particles[i].p[0] += model.particles[i].v[0] * dt;
	  model.particles[i].p[1] += model.particles[i].v[1] * dt;
	  model.particles[i].p[2] += model.particles[i].v[2] * dt;		
	}

	
      }

      
      break;
      
    }

  return model;
  
}

