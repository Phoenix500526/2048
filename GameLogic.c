#include "myheadfile.h"
//向上移动
void move_top(int (*arr)[SIZE],int size,int* score,int* IsPlus,int *IsMove){
	int i,j,k;
	for(i = 0;i < size;i++){
		k=0;
		while(arr[k][i]&&k<size){	//找到同列不同行中值为0的数并得到行号
			k++;
		}
		for(j = k+1;j < size;j++){
			if(arr[j][i]!=0){
				arr[k][i] = arr[j][i];
				arr[j][i] = 0;
				k++;
				*IsMove = 2;
			}
		}
		for(k=0;k<size-1;k++){
			if(arr[k][i] == arr[k+1][i]&&arr[k][i]!=0){
				arr[k][i] *= 2;
				*score += arr[k][i];
				arr[k+1][i] = 0;
				*IsPlus = 1;
				*IsMove = 1;
			}
		}
	}
	for(i = 0;i < size;i++){
		k=0;
		while(arr[k][i]&&k<size){
			k++;
		}
		for(j = k+1;j < size;j++){
			if(arr[j][i]!=0){
				arr[k][i] = arr[j][i];
				arr[j][i] = 0;
				k++;
				*IsMove = 1;
			}
		}
	}
}
//向下移动
void move_down(int (*arr)[SIZE],int size,int* score,int* IsPlus,int* IsMove){
	int i,j,k;
	for(i = 0;i < size;i++){
		k=size-1;
		while(arr[k][i]&&k>=0){	//找到同列不同行中值为0的数并得到行号
			k--;
		}
		for(j = k-1;j >= 0;j--){
			if(arr[j][i]!=0){
				arr[k][i] = arr[j][i];
				arr[j][i] = 0;
				k--;
				*IsMove = 1;
			}
		}
		for(k=size-1;k>0;k--){
			if(arr[k][i] == arr[k-1][i]&&arr[k][i]!=0){
				arr[k][i] *= 2;
				*score += arr[k][i];
				arr[k-1][i] = 0;
				*IsPlus = 1;
				*IsMove = 1;
			}
		}
	}
	for(i = 0;i < size;i++){
		k=size-1;
		while(arr[k][i]&&k>=0){
			k--;
		}
		for(j = k-1;j >= 0;j--){
			if(arr[j][i]!=0){
				arr[k][i] = arr[j][i];
				arr[j][i] = 0;
				k--;
				*IsMove = 1;
			}
		}
	}
}
//向左移动
void move_left(int (*arr)[SIZE],int size,int* score,int* IsPlus,int* IsMove){
	int i,j,k;
	for(i = 0;i < size;i++){
		k = 0;
		while(arr[i][k]&&k<size){	//找到同列不同行中值为0的数并得到行号
			k++;
		}
		for(j = k+1;j < size;j++){
			if(arr[i][j]!=0){
				arr[i][k] = arr[i][j];
				arr[i][j] = 0;
				k++;
				*IsMove = 1;
			}
		}
		for(k=0;k<size-1;k++){
			if(arr[i][k] == arr[i][k+1]&&arr[i][k]!=0){
				arr[i][k] *= 2;
				*score += arr[i][k];
				arr[i][k+1] = 0;
				*IsPlus = 1;
				*IsMove = 1;
			}
		}
	}
	for(i = 0;i < size;i++){
		k=0;
		while(arr[i][k]&&k<size){
			k++;
		}
		for(j = k+1;j < size;j++){
			if(arr[i][j]!=0){
				arr[i][k] = arr[i][j];
				arr[i][j] = 0;
				k++;
				*IsMove = 1;
			}
		}
	}
}
//向右移动先移动，再判断相加，最后再移动一次
void move_right(int (*arr)[SIZE],int size,int* score,int* IsPlus,int* IsMove){
	int i,j,k;
	for(i = 0;i < size;i++){
		k=size-1;
		while(arr[i][k]&&k>=0){	//找到同列不同行中值为0的数并得到行号
			k--;
		}
		//向右移动
		for(j = k-1;j >= 0;j--){
			if(arr[i][j]!=0){
				arr[i][k] = arr[i][j];
				arr[i][j] = 0;
				k--;
				*IsMove = 1;
			}
		}
		/****************************************************************/
		//判断相加
		for(k=size-1;k>0;k--){
			if(arr[i][k] == arr[i][k-1]&&arr[i][k]!=0){
				arr[i][k] *= 2;
				*score += arr[i][k];
				arr[i][k-1] = 0;
				*IsPlus = 1;
				*IsMove = 1;
			}
		}
		/******************************************************************/
	}
	//移动
	for(i = 0;i < size;i++){
		k=size-1;
		while(arr[i][k]&&k>=0){
			k--;
		}
		for(j = k-1;j >= 0;j--){
			if(arr[i][j]!=0){
				arr[i][k] = arr[i][j];
				arr[i][j] = 0;
				k--;
				*IsMove = 1;
			}
		}
	}
}
/************************************************************************/
void insert_num(int (*arr)[SIZE],int size){
	int randX,randY,randnum;
	randnum = rand()%2;			//randnum的值为0或1,0表示在，1表示4
	do{
		randX=rand()%size;
		randY=rand()%size;
		if(arr[randX][randY] == 0){
			if(randnum == 0){
				arr[randX][randY] = 2;
				break;
			}
			else{
				arr[randX][randY] = 4;
				break;
			}
		}
	}while(1);
}
void run_map(int (*arr)[SIZE],int size,int *score,int *hightscore,int *IsMove,int *IsPlus){
	char input;
	int i,j;
	int save = 0;
	while(1){
		*IsMove = 0;
		*IsPlus = 0;
		scanf("%c",&input);
		scanf("%*[^\n]");
		scanf("%*c");
		switch(input){
			case 'w':
				move_top(arr,4,score,IsPlus,IsMove);
				break;
			case 's':
				move_down(arr,4,score,IsPlus,IsMove);
				break;
			case 'a':
				move_left(arr,4,score,IsPlus,IsMove);
				break;
			case 'd':
				move_right(arr,4,score,IsPlus,IsMove);
				break;
			case 'q':
				printf("Saving……,Please wait!!\n");
				save = save_game(arr,size,*score);
				sleep(1);
				if(save){
					printf("The game has been saved\n");
					exit(0);
				}
				else{
					printf("Save failed!!\n");
				}
				break;
			default:
				printf("Input error!!\n");
				break;
		}
		if(*IsMove){
			insert_num(arr,4);
		}
		map_printer(arr,4,score,hightscore);
		if(success_judge(arr,4)){
			printf("You Win!!\n");
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					arr[i][j] = 0;
				}
			}
			save_hightscore(*score);	//保存最高分数
			*score = 0;
			save_game(arr,size,*score);
			exit(0);
		}
		if(fail_judge(arr,4,*IsMove,*IsPlus)){
			printf("You Lose!!\n");
			for(i=0;i<size;i++){
				for(j=0;j<size;j++){
					arr[i][j] = 0;
				}
			}
			save_hightscore(*score);	//保存最高分
			*score = 0;
			save_game(arr,size,*score);
			exit(0);
		}
	}
}
