#ifndef _RAND_H_
#define _RAND_H_

//Generates a uniform random integer value in [a,b)
int randInt(int a, int b);

//Generates a uniform random integer value in [0,b)
int RandInt(int b);

//Generates a uniform random integer value in [a,b]
int closedRandInt(int a, int b);

//Generates a uniform random integer value in [0,b]
int closedRandInt(int b);

#endif