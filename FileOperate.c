#include "myheadfile.h"
int open(int (*arr)[SIZE],int size,int *score,int *hightscore){
	FILE *p_file =  fopen("SaveMap.bin","r");
	int i,j,failed = 0;
	if(NULL == p_file){
		printf("File open error!!\n");
		return 0;
	}
	else{
		for(i = 0;i < size;i++){
			failed = fread(arr[i],sizeof(int),size,p_file);
		}
		for(i = 0;i < size;i++){
			for(j = 0;j < size-1;j++){
				if(arr[i][j] == arr[i][j-1] && !arr[i][j]){
					failed = 0;
				}
				else{
					failed = 1;
				}
			}
		}
		fclose(p_file);
		p_file = fopen("SaveScore.bin","r");
		if(NULL == p_file){
			printf("ERROR:Can not read SaveScore.bin\n");
			return 0;
		}
		else{
			fread(score,sizeof(int),1,p_file);
			fclose(p_file);
			p_file = fopen("HistoryHightscore.bin","r");
			if(NULL == p_file){
				printf("ERROR:Can not read HistoryHightscore.bin\n");
				return 0;
			}
			else{
				fread(hightscore,sizeof(int),1,p_file);
				printf("11111111111111111:%d\n",*hightscore);
				fclose(p_file);
				p_file = NULL;
			}
		}
		return failed;
	}
}
int save_hightscore(int score){
	FILE *p_file = fopen("HistoryHightscore.bin","r+");
	int hightscore;
	if(NULL == p_file){
		printf("ERROR:Can not open HistoryHightscore.bin!!\n");
		return 0;
	}
	else{
		fread(&hightscore,sizeof(int),1,p_file);
		if(score > hightscore){
			rewind(p_file);
			fwrite(&score,sizeof(int),1,p_file);
		}
		fclose(p_file);
		p_file = NULL;
		return 1;
	}
}
int save_game(int (*arr)[SIZE],int size,int score){
	FILE *p_file = fopen("SaveMap.bin","w");
	int i;
	if(NULL == p_file){
		printf("ERROR:Can not open SaveMap.bin!!\n");
		return 0;
	}
	else{
		for(i = 0;i < size;i++){
			fwrite(arr[i],sizeof(int),size,p_file);
		}
		fclose(p_file);
		p_file = fopen("SaveScore.bin","w");
		if(NULL == p_file){
			printf("ERROR:Can not open SaveScore.bin!!\n");
			return 0;
		}
		else{
			fwrite(&score,sizeof(int),1,p_file);
			fclose(p_file);
			p_file = NULL;
			return 1;
		}
	}
}
