#include "myheadfile.h"
int main(void){
	srand(time(0));
	int arr[SIZE][SIZE] = {};
	int IsMove,IsPlus,score = 0,hightscore = 0;
	if(open(arr,4,&score,&hightscore)){
		map_printer(arr,4,&score,&hightscore);
	}
	else{
		init_map(arr,4);
		map_printer(arr,4,&score,&hightscore);
	}
	run_map(arr,4,&score,&hightscore,&IsMove,&IsPlus);
	return 0;
}
