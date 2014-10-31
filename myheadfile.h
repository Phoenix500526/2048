#ifndef __MYHEADFILE__H
#define __MYHEADFILE__H
//共享的宏变量定义
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 4
#define FILENAME map.txt
#define FILESCORE score.bin
//函数声明
//GameLogic.c
void move_top(int (*)[],int,int*,int*,int*);
void move_down(int (*)[],int,int*,int*,int*);
void move_left(int (*)[],int,int*,int*,int*);
void move_right(int (*)[],int,int*,int*,int*);
void insert_num(int (*)[],int);
void run_map(int (*)[],int,int*,int*,int*,int*);
//FileOperate.c
int open(int (*)[],int,int*,int*);
int save_hightscore(int);
int save_game(int (*)[],int,int);
//MapPrinter.c
void init_map(int (*)[],int);
void map_printer(int (*)[SIZE],int,int*,int*);
//JudgeLogic.c
int success_judge(int (*)[],int);
int fail_judge(int (*)[],int,int,int);
#endif
