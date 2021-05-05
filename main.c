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
	int user_index = user_count;

	/*
		메뉴 목록
		printf("\n*** 게시판 ***\n");
		printf("1. 게시글 보기\n");
		printf("2. 게시글 목록 보기\n");
		printf("3. 게시판 글쓰기\n");
		printf("4. 게시글 삭제\n");
		printf("5. 게시글 수정\n");
		printf("6. 게시글 검색\n");
		printf("7. 게시글 정렬 순서\n");
		printf("8. 게시판 저장\n");
		printf("9. 로그인\n");
		printf("10. 로그아웃\n");
		printf("11. 계정 생성\n");
		printf("12. 사용자 목록 확인\n");
		printf("0. 종료\n\n");
		printf("=> 원하는 메뉴는? ");
	*/


	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu != 11)
			if(user_count == 0){
				printf("err: 등록된 사용자가 없습니다.\n");
				continue;
			}
		if(menu == 1){
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
			user_count += addUser(&userlist[user_index++]);
		}
		else if(menu == 12){
			readuser(userlist[0]);
		}
	}
	return 0;
}
