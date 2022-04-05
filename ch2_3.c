#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int niter=100000; //sumple number
    srand((unsigned)time(NULL));

    double pi=asin(1e0)*2e0;
    double sum_z=0e0;
    int n_in=0; 
/*************/
/* Main loop */
/*************/
    for(int iter=1;iter<niter+1;iter++){

    double x = (double)rand()/RAND_MAX;
    double y = (double)rand()/RAND_MAX;
    // generattion x,y as random number between 0 and 1
    if (x*x+y*y <1e0){
        n_in=n_in+1;
        double z=sqrt(1e0-x*x-y*y);
        sum_z=sum_z+z;
    }
        printf("%d %.10f\n",iter,sum_z/n_in*2e0*pi);}
}