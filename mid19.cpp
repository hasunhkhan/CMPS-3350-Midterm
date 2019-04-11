// Program created by: Hasun Khan
//         Date: 03/11/2019
//         Course: CMPS 3350
//Unit test for Vector length function
//https://github.com/hasunhkhan/CMPS-3350-Midterm

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "data.h"

//type defines
typedef double Flt;
typedef Flt Vec[3];

//prototype
Flt vec_length(Vec v);

//Array of vector values
const Flt arr[] = {
   1.0,   0.0,
   1.0,   1.0,
  -1.2,   2.5,
  99.9,  99.9,
   2.2,  -1.2,
   0.0,   0.0
};

void unitTest(Vec v,double tolerance){ 
    printf("                                    \n");
    printf("3350 software engineering           \n");
    printf("                                    \n");
    printf("Calculation of vector lengths:      \n");
    printf("                                    \n");
    printf("     x         y         length     actual\n");
    printf("     --------  --------  ---------- ---------- \n");
    int errors = 0;
    int i = 0;
    do {
        Flt ret = vec_length(v);
        printf("%3i  %8.5lf  %8.5lf %10.5lf  %10.5lf", i+1, v[0], v[1], expected[i], ret);
        if(expected[i] - ret > tolerance) {
            printf(" <---- error \n");
            errors++;
        }
        else 
            printf("\n");
        ++i;
        v[0] = dataVec[i*2+0];
        v[1] = dataVec[i*2+1];
       } while (!(v[0]==0.0 && v[1]==0.0));
    printf("Unit test complete. \n");
    printf("errors found: ");
    printf("%3i", errors);
}


int main(int argc, char *argv[])
{
    double tolerance;
    if (argc > 1) {
        tolerance = atof(argv[1]);
        printf("Tolerance: %10.2f", tolerance);
    }
    Vec vu = { dataVec[0], dataVec[1] };
    unitTest(vu,tolerance);

    //Program to calculate vector normalization and length.
	//
    printf("                                    \n");
    printf("3350 software engineering           \n");
    printf("                                    \n");
    printf("Calculation of vector lengths:      \n");
    printf("                                    \n");
    printf("     x         y         length     \n");
    printf("     --------  --------  ---------- \n");
    //read until sentinel found.
    int i=0;
    Vec v = { arr[i*2+0], arr[i*2+1] };
    do {
        Flt ret = vec_length(v);
        printf("%3i  %8.5lf  %8.5lf  %10.5lf\n", i+1, v[0], v[1], ret);
        ++i;
        v[0] = arr[i*2+0];
        v[1] = arr[i*2+1];
    } while (!(v[0]==0.0 && v[1]==0.0));
    //
    printf("\nProgram complete.\n\n");
    return 0;
}

Flt vec_length(Vec v)
{
    //Normalize a vector.
    //Return the original length of the vector.
    //
    //input: the 2 components of a vector
    //output: the pre-normalized vector length is returned
    //        the vector argument is scaled to a length of 1.0
    //
    //A degenerate vector causes an error condition.
    //It will return a length of 0.0
    //and an arbitrary vector with length 1.0.
    //
    //calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //check for degenerate vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        //printf("ERROR vector magnitude is zero.\n");
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //vector has a magnitude so continue.
    Flt len = sqrt(dot);
    Flt oolen = 1.0 / len;
    v[0] *= oolen;
    v[1] *= oolen;
    return len;
}

