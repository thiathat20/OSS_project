//messageboard.c 메인

#include <stdio.h>
#include "board.h"
#define HEADER

#define DEBUG_MODE


int main(void){
    #ifdef DEBUG_MODE
        printf("==> DEBUG MODE\n");
    #endif

	User userlist[100];
 	// Post boardlist[100];
	int menu;
	
	//하나로 합칠 수 있을거 같은데... board.count 이런 느낌?
	// int board_count = loadData(boardlist); // file open/load
	// int user_count = loadData(userlist);
	
	// int board_count = 0; // file open/load
	int user_count = 0;
	// int board_index = board_count;
	// int user_index = user_count;

	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu != 1)
			if(user_count == 0){
				printf("err: 등록된 사용자가 없습니다.\n");
				continue;
			}
		if(menu == 1){
			addUser(userlist[user_count]);
		}
		else if(menu == 2){
		}
		else if(menu == 3) {
		}
		else if(menu == 4){
		}
		else if(menu == 5){
		}
		else if(menu == 6){
		}
		else if(menu == 7){
		}
		else if(menu == 8){
		}
		else if(menu == 9){
		}
		else if(menu == 10){
		}
		else if(menu == 11){
		}
		else if(menu == 12){
		}
	}
	return 0;
}