#include <stdio.h>
#include <stdlib.h>

struct numbers {
  int number;
  int occurences;
};

int main(int argc, char **argv) {
  int i, j, k, N, size, aux, increment, hashtablesize;
  int *arr;
  FILE *fp, *fp2;
  struct numbers *arr2, *arr3, tmp;

  fp = fopen("numers.txt", "r");

  fscanf(fp, "%d ", &N);

  arr = (int *)malloc(N * sizeof(int));

  for (i = 0; i < N; i++) {
    fscanf(fp, "%d ", &arr[i]);
  }

  fclose(fp);

  // arr2=(int*)malloc(N*sizeof(int)); //number
  // arr3=(int*)calloc(N, sizeof(int)); //number of occurences

  if (argc > 1) { // hashing is faster when the has table size is a prime number
    size = atoi(argv[1]); // size of the hash table
  } else {
    size = N;
  }
  arr2 = (struct numbers *)calloc(size, sizeof(struct numbers));

  if (argc > 2) { // the increment should be a prime number too
    increment = atoi(argv[2]);
  } else {
    if (size > 3) {
      increment = 3;
    } else {
      increment = 1;
    }
  }

  // is afonso sorting time

  // printf("Hashing with size %d and increment %d\n", size, increment);

  hashtablesize = 0;
  for (i = 0; i < size; i++) { // hashing time
    aux = arr[i] % N;
    if (arr2[aux].number == arr[i]) {
      arr2[aux].occurences++;
    } else if (arr2[aux].occurences == 0) {
      arr2[aux].number = arr[i];
      arr2[aux].occurences = 1;
      hashtablesize++;
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
        hashtablesize++;
      }
    }
  }

  arr3 = (struct numbers *)malloc(hashtablesize * sizeof(struct numbers));

  for (i = 0, j = 0; j < hashtablesize;
       i++) { // create a copy of the arr2 without the empty array values
    if (arr2[i].occurences != 0) {
      arr3[j].number = arr2[i].number;
      arr3[j].occurences = arr2[i].occurences;
      j++;
    }
  }

  free(arr2);

  for (i = 1; i < hashtablesize; i++) { // insertion sort
    for (j = i - 1, k = i, tmp = arr3[i]; j >= 0; k = j, j--) {
      if (arr3[j].number > tmp.number) {
        arr3[k] = arr3[j];
      } else {
        break;
      }
    }
    arr3[k] = tmp;
  }

  for (i = 0, k = 0; i < hashtablesize; i++) { // write back the sorted array
    for (j = arr3[i].occurences; j != 0; j--) {
      arr[k] = arr3[i].number;
      k++;
    }
  }

  free(arr3);

  fp2 = fopen("ordered_numers.txt", "w+");

  for (i = 0; i < size; i++) {
    fprintf(fp2, "%d ", arr[i]);
  }
  fprintf(fp, "\n");

  fclose(fp2);
  free(arr);

  return 0;
}
