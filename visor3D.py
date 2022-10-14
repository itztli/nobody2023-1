#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

with open('3body.dat') as f:
    lines = f.readlines()

data = []

for line in lines:
    if line[0] != '#':
        data.append(line)

n_particles = int(data[0])

N = len(data)
a = b = k = 0



while True:
    a = 1 + n_particles*k
    b = n_particles*(k+1)
    if b >= N:
        break
    #print(b,N)
    k = k + 1
    subset = np.arange(a,b+1,1)
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    ax.set_zlabel('Z Label')
    plt.xlim([-0.3, 0.3])
    plt.xlim([-0.3, 0.3])
    plt.xlim([-0.3, 0.3])
    for p in subset:
        ms,xs,ys,zs,vxs,vys,vzs = data[p].split()
        m = float(ms)
        x = float(xs)
        y = float(ys)
        z = float(zs)
        vx = float(vxs)
        vy = float(vys)
        vz = float(vzs)
        print(x,y,z)
        ax.scatter(x, y, z)
    plt.savefig("video/squares-"+str(k)+".png")
    print(k)
    

#print('N particles '+str(n_particles))







#plt.show()
