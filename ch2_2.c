#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int niter=1000; //sumple number
    srand((unsigned)time(NULL));

    double sum_y=0e0;
    int n_in=0; 
/*************/
/* Main loop */
/*************/
    for(int iter=1;iter<niter+1;iter++){

    double x = (double)rand()/RAND_MAX;
    // generattion x,y as random number between 0 and 1
    double y = sqrt(1e0-x*x);
    sum_y=sum_y+y;
        printf("%d %.10f\n",iter,sum_y/iter);}
}