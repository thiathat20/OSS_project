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
	int loginflag = -1; // 로그인 상태 확인 
	
	//하나로 합칠 수 있을거 같은데... board.count 이런 느낌?
	// int board_count = loadData(boardlist); // file open/load
	// int user_count = loadData(userlist);
	
	// int board_count = 0; // file open/load
	int user_count = 0;
	// int board_index = board_count;
	int user_index = user_count;

	while(1){
		if(loginflag != -1){
			printf("\n(**로그인 사용자: %s)\n", userlist[loginflag].id);
		}
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
			loginflag = login(userlist, user_index);
		}
		else if(menu == 10){
			if(loginflag == -1){
				printf("로그인이 필요합니다\n");
				continue;
			}
			loginflag = -1;
		}
		else if(menu == 11){
			user_count += addUser(&userlist[user_index++]);
			// addUser(&userlist[0]);
		}
		else if(menu == 12){
			listuser(userlist, user_count);
		}
		else if(menu == 13){
			if(loginflag == -1){
				printf("로그인이 필요합니다\n");
				continue;
			}
			// int no = select_User_DataNo(userlist, user_index); // 마스터 계정이면 실행, 아니면 no에 현제 계정 정보가 들어 가도록 수정
			int no = loginflag; // 일반 사용자 / 위애 코드는 관리자
			if(no != -1){ // 로그인 여부, 로그인 이용자 번호 따로 분리시키기
				updateuser(&userlist[no-1]);
			}
		}
		else if(menu == 14){
			if(loginflag == -1){
				printf("로그인이 필요합니다\n");
				continue;
			}
			// int no = select_User_DataNo(userlist, user_index); // 마스터 계정이면 실행, 아니면 no에 현제 계정 정보가 들어 가도록 수정
   			int no = loginflag; // 일반 사용자 / 위애 코드는 관리자
			if(no != -1){ // 로그인 여부, 로그인 이용자 번호 따로 분리시키기
				int deleteok ;
				printf("정말로 삭제하시겠습니까?(삭제:1)");
				scanf("%d", &deleteok);
				if(deleteok == 1){
					deleteuser(&userlist[no-1]);
					user_count--;
				}
			}
			loginflag = -1; // 삭제와 동시에 로그아웃
		}
	}
	return 0;
}
