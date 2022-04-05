#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    FILE *gp;
    int niter=10000; //sumple number
    srand((unsigned)time(NULL));
    double result_int[niter];

/*************/
/* Main loop */
/*************/
    for(int i=0; i<niter; i++){
        int n_in=0; 
        for(int j=0;j<i;j++){

            double x = (double)rand()/RAND_MAX;
            double y = (double)rand()/RAND_MAX;
        // generattion x,y as random number between 0 and 1

            if (x*x+y*y <1e0){
                n_in=n_in+1;
                result_int[i]=(double)n_in/i;
                //printf("%d %.10f\n",iter,result_int[iter]);
            }
        }
        result_int[i]=(double)n_in/i;
    }

    /* ---- グラフ作成 ---- */
        gp = popen("gnuplot -persist","w");
        fprintf(gp, "set xrange [0:10000]\n");
        //fprintf(gp, "set yrange [-2:2]\n");
        fprintf(gp, "plot '-' with lines ");

        for(int iter=0; iter<niter; iter++){
            fprintf(gp,"%d\t%f\n",iter,result_int[iter]);    // データの書き込み
        }  
        fprintf(gp,"e\n");
        pclose(gp);
        return 0;

}