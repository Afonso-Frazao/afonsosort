#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    int i, j, tmp, pos, *arr, placed;
    float N, factor;
    FILE *fp, *fp2;

    fp=fopen("numers.txt", "r");

    fscanf(fp, "%f ", &N);
    arr=(int*)malloc(N*sizeof(int));

    for(i=0; i<N; i++){
        fscanf(fp, "%d ", &arr[i]);
    }

    fclose(fp);

    //is quick sorting time

    qsort(arr, N, 4, cmpfunc);

    fp2=fopen("ordered_numersq.txt", "w");

    fprintf(fp2, "%d \n", (int) N);
    for(i=0; i<N; i++){
        fprintf(fp2, "%d ", arr[i]);
    }

    fclose(fp2);
    free(arr);

    return (0);
}
