//messageboard.c 메인

#include <stdio.h>
#include <string.h>
#include <unistd.h>
//#include "manager.h"
#define DEBUG_MODE


int main(void){
    #ifdef DEBUG_MODE
        printf("==> DEBUG MODE\n");
    #endif

	user userlist[100];
 	board boardlist[100];
	int index = 0;
	int count = 0, menu;
	board_count = loadData(boardlist);
	user_count = loadData(userlist);
	index = count;

    	while (1){
        	menu = selectMenu();
        	if (menu == 0) break; //만약 0이면 취소 
        	if (menu == 1){
          		//글 추가 함수
        	}
       		else if (menu == 2){
        		//하나의 글을 출력하는 함수
        	}
        	else if (menu == 3){
        		//글을 수정하는 함수
        	}
        	else if (menu == 4){
        		//글을 목록에서 삭제하는 함수
        	}
        	else if (menu == 5){
        		//함수넣기
        	}
		else if (menu == 6){
        		//함수넣기
		}
        	else if (menu == 7){
        		//함수넣기
        	}
        	else if (menu == 8){
        		//함수넣기
        	}
	}
	printf("종료됨!\n");
	return 0;
}
