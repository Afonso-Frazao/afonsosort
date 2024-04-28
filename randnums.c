#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
    int i, N, m, M, r;
    FILE *fp;

    if(argc!=2 && argc!=4){
        exit(1);
    }

    N=atoi(argv[1]);

    if(argc==2){
        r=N;
		m=1;
    }
    else if(argc==4){
		m=atoi(argv[2]);
		M=atoi(argv[3]);
		r=M-m;
    }

    fp=fopen("numers.txt", "w");

    srand(time(NULL));

    fprintf(fp, "%d \n", N);
    for(i=0; i<N; i++){
        fprintf(fp, "%d ", m+(rand()%r));
    }

    fclose(fp);

    return 0;
}
