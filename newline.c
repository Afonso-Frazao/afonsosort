#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fp;

	fp=fopen(argv[1], "a");

	fprintf(fp, "\n");

	fclose(fp);

	return 0;
}
