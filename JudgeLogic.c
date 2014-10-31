#include "myheadfile.h"
int success_judge(int (*arr)[SIZE],int size){
	int i,j,success = 0;
	for(i = 0;i < size;i++){
		for(j = 0;j < size;j++){
			if(arr[i][j] == 2048){
				success = 1;	
			}
		}
	}
	return success;
}
int fail_judge(int (*arr)[SIZE],int size,int IsMove,int IsPlus){
	int i,j,tmp = 0,fail = 0,col = 0,row = 0;
	//循环判断数组中是否还有空位，有则tmp=1,无则tmp=0
	for(i = 0;i < size;i++)
		for(j = 0;j < size;j++){
			if(!arr[i][j])
				tmp = 1;
		}
	for(i = 0;i < size;i++)
		for(j = 0;j < size-1;j++){
			if(arr[i][j] == arr[i][j+1] && arr[i][j] != 0){
				col = 1;
			}
			if(arr[j][i] == arr[j+1][i] && arr[j][i] != 0){
				row = 1;
			}
		}
	if(!IsMove && !IsPlus && !tmp && !col && !row){
		fail = 1;
	}
	return fail;
}
