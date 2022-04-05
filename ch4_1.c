#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
    int niter=100; //sumple number
    double step_size=0.5e0;

    srand((unsigned)time(NULL));
    double x[niter+1], y[niter+1];
    int naccept=0; //accept counter

    double x[0]=0e0;
/*************/
/* Main loop */
/*************/
    for(int i=1;i<niter+1;i++){

    double backup_x = x[i];
    double action_init = 0.5e0*x[i]*x[i];

    double dx =  (double)rand()/RAND_MAX;
    dx = (dx-0.5e0)*step_size*2e0;
    x[i+1]=x[i]+dx;
    
    double action_fin = 0.5e0*x[i+1]*x[i+1];

/*******************/
/* Metropolis test */
/*******************/
    double metropolis = (double)rand()/RAND_MAX;

    if (exp(action_init-action_fin) < metropolis)
        naccept=naccept+1;
    else
        x[i+1] = backup_x;
    
    y[i]=naccept/i
        printf("%.10f %.f\n",x[i],y[i]);}
    
    /* ---- グラフ作成 ---- */
    gp = popen("gnuplot -persist","w");
    fprintf(gp, "set xrange [-6.5:6.5]\n");
    fprintf(gp, "set yrange [-1.5:1.5]\n");
    fprintf(gp, "plot '-' with lines linetype 1 title \"sin\"\n");

    for(i=0; i<=niter+1; i++){
        fprintf(gp,"%f\t%f\n", x[i], y[i]);    // データの書き込み

    }  
    fprintf(gp,"e\n");

    pclose(gp);
    return 0;
}