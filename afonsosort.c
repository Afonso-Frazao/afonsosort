#include <stdio.h>
#include <stdlib.h>

struct numbers {
  int number;
  int occurences;
};

int main(int argc, char **argv) {
  int i, j, k, N, size, aux, tmp, increment;
  int *arr;
  FILE *fp, *fp2, *fp3;
  struct numbers *arr2, tmp2;

  fp = fopen("numers.txt", "r");

  fscanf(fp, "%d ", &N);

  arr = (int *)malloc(N * sizeof(int));

  for (i = 0; i < N; i++) {
    fscanf(fp, "%d ", &arr[i]);
  }

  fclose(fp);

  // arr2=(int*)malloc(N*sizeof(int)); //number
  // arr3=(int*)calloc(N, sizeof(int)); //number of occurences

  size = atoi(argv[1]);

  arr2 = (struct numbers *)calloc(size, sizeof(struct numbers));

  // is afonso sorting time

  if (argc == 2) {
    fp3 = fopen("out.txt", "r");

    fscanf(fp3, "%d\n", &increment);

    fclose(fp3);
  } else {
    increment = atoi(argv[2]);
  }

  printf("Hashing with size %d and increment %d\n", size, increment);

  for (i = 0; i < N; i++) {
    aux = arr[i] % N;
    if (arr2[aux].number == arr[i]) {
      arr2[aux].occurences++;
    } else if (arr2[aux].occurences == 0) {
      arr2[aux].number = arr[i];
      arr2[aux].occurences = 1;
    } else {
      for (; arr2[aux].number != arr[i] && arr2[aux].number != 0;) {
        aux += increment;
        if (aux >= N) {
          aux -= N;
        }
      }

      if (arr2[aux].number == arr[i]) {
        arr2[aux].occurences++;
      } else {
        arr2[aux].number = arr[i];
        arr2[aux].occurences = 1;
      }
    }
  }

  for (i = 1; i < size; i++) {
    for (j = i - 1, k = i, tmp2 = arr2[i]; j >= 0; k = j, j--) {
      if (arr2[j].number < tmp) {
        arr2[k] = arr2[j];
      } else {
        break;
      }
    }
    arr2[k] = tmp2;
  }

  for (i = 0, k = 0; i < size; i++) {
    for (j = arr2[i].occurences; j != 0; j--) {
      arr[k] = arr2[i].number;
      k++;
    }
  }

  free(arr2);

  fp2 = fopen("ordered_numersf.txt", "w");

  for (i = 0; i < N; i++) {
    fprintf(fp2, "%d ", arr[i]);
  }

  fclose(fp2);
  free(arr);

  return 0;
}
