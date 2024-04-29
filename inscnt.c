#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv){
	int i;
	DIR *dir;
	char callg_name[15]={"callgrind.out."};
	FILE *fp, *fp2;
	long insn;
	char *lbuff, nbuff[15];

	lbuff=(char*)malloc(100);

	struct dirent *filename;

	dir=opendir(".");

	if(dir==NULL){
		return(1);
	}

	while((filename=readdir(dir))!=NULL){
		for(i=0; i<14; i++){
			if(filename->d_name[i]!=callg_name[i]){
				break;
			}
		}
		if(i==14){
			break;
		}
	}

	if(filename==NULL){
		return 1;
	}

	fp=fopen(filename->d_name, "r");

	fseek(fp, -14, SEEK_END);

	fgets(lbuff, 100, fp);

	while(lbuff[0]<48 || lbuff[0]>57){
		lbuff++;
	}

	sscanf(lbuff, "%ld", &insn);

	fclose(fp);

	fp2=fopen(argv[1], "a");

	fprintf(fp, "%ld, ", insn);

	return 0;
}
