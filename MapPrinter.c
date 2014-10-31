#include "color.h"
#include "myheadfile.h"
static void print(int size){
	int i;
	for(i = 0;i < size;i++){
		printf("-----");
	}
	printf("\n");
}
void init_map(int (*arr)[SIZE],int size){
	int randone = rand()%size;
	int randtwo = rand()%size;
	int randthree = rand()%size;
	int randfour = rand()%size;
	arr[randone][randtwo]=2;
	arr[randthree][randfour]=4;
}
static void print_color(int (*arr)[SIZE],int size,int row,int col){
	switch(arr[row][col]){
		case 0:
			printf("|"BACKGROUND"    "NONE);
			break;
		case 2:
			printf("|"RED_2"2   "NONE);
			break;
		case 4:
			printf("|"GREEN_4"4   "NONE);
			break;
		case 8:
			printf("|"DARKYELLOW_8"8   "NONE);
			break;
		case 16:
			printf("|"BLUE_16"16  "NONE);
			break;
		case 32:
			printf("|"PURPLE_32"32  "NONE);
			break;
		case 64:
			printf("|"LIGHT_ORANGE_64"64  "NONE);
			break;
		case 128:
			printf("|"ORANGE_128"128 "NONE);
			break;
		case 256:
			printf("|"YELLOW_256"256 "NONE);
			break;
		case 512:
			printf("|"LIGHT_PURPLE_512"512 "NONE);
			break;
		case 1024:
			printf("|"PINK_1024"1024"NONE);
			break;
		case 2048:
			printf("|"CAYN_2048"2048"NONE);
			break;
		default:
			break;
	}
}
void map_printer(int (*arr)[SIZE],int size,int *score,int *hightscore){
	int i,j;
	system("clear");
	printf("2048 by Phoenix\n");
	printf("Score:%d\tHightScore:%d\n",*score,*hightscore);
	print(size);
	for(i = 0;i < size;i++){
		for(j = 0;j < size;j++){
				print_color(arr,size,i,j);
		}
		printf("|\n");
		print(size);
	}
}
