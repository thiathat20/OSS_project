//messageboard.c 메인

#include <stdio.h>
#include <string.h>
#include "board.h"
#define HEADER

#define DEBUG_MODE


int main(void){
    #ifdef DEBUG_MODE
        printf("==> DEBUG MODE\n");
    #endif

	User userlist[100];
 	Post postlist[100];
	int menu;
	int loginflag = -1; // 로그인 상태 확인 
	
	//하나로 합칠 수 있을거 같은데... board.count 이런 느낌?
	// int post_count = loadData(boardlist); // file open/load
	// int user_count = loadData(userlist);
	
	int post_count = 0; // file open/load
	int user_count = 0; // 로드 구한 하면 계정 갯수 넣기
	
	post_count = loadboard(postlist);
	user_count = loaduser(userlist);

	int post_index = post_count;
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
		if(menu != 9 && menu != 12 && menu != 11)
			if(loginflag == -1){
				printf("로그인이후 이용가능 합니다.\n");
				continue;
			}
		if(menu == 1){ // 게시글 보기
			selectprintpost(postlist, post_index);
		}
		else if(menu == 2){ // 게시글 목록 보기(제목만 보이도록)
			readPostList(postlist, post_index);
		}
		else if(menu == 3) { // 게시글 쓰기
			addpost(&postlist[post_index++], userlist[loginflag].id);
		}
		else if(menu == 4){ // 게시글 삭제
			int no = select_Post_DataNo(postlist, post_index);
			if(0 != strcmp(userlist[loginflag].id, postlist[no-1].user)){
				printf("err: 글은 작성자만 지울수 있습니다.\n");
				continue;
			}
   			if( no > 0){
				int deleteok ;
				printf("선택한 글의 내용입니다\n");
				printf("정말로 삭제하시겠습니까?(삭제:1)");
				scanf("%d", &deleteok);
				if(deleteok == 1){
					deletepost(&postlist[no-1]);
					user_count--;
				}
			}
			
		}
		else if(menu == 5){ // 게시글 수정
			int no = select_Post_DataNo(postlist, post_index);
			if(0 != strcmp(userlist[loginflag].id, postlist[no-1].user)){
				printf("err: 글은 작성자만 수정할 수 있습니다.\n");
				continue;
			}
   			if( no > 0){
				int updateok ;
				printf("기존 글을 지우고 새로 작성 합니다 정말로 수정하시겠습니까?(수정:1)");
				scanf("%d", &updateok);
				if(updateok == 1){
					updatepost(&postlist[no-1]);
				}
			}
		}
		else if(menu == 6){ // 게시글 검색 -- 키워드, 작성자, ...
			searchpost(postlist, post_index);
		}
		else if(menu == 7){ // 게시글 목록 정렬해서 보기

		}
		else if(menu == 8){ // 게시판 저장
			saveboard(postlist, post_index);
			saveuser(userlist, user_index);
		}
		else if(menu == 9){ // 로그안
			if(loginflag != -1) loginflag = logout(); // 기존 로그인 로그이웃
			loginflag = login(userlist, user_index);
		}
		else if(menu == 10){ // 로그아웃
			loginflag = logout();
		}
		else if(menu == 11){ // 계정 생성
			user_count += addUser(&userlist[user_index++]);
		}
		else if(menu == 12){ // 계정 목록 확인
			listuser(userlist, user_index);
		}
		else if(menu == 13){ // 계정 비밀번호 수정
			int no = loginflag;
			if(loginflag != -1){ // 로그인 여부, 로그인 이용자 번호 따로 분리시키기
				updateuser(&userlist[no-1]);
			}
		}
		else if(menu == 14){
			int no = loginflag;
			// if(loginflag != -1){ // 로그인 여부, 로그인 이용자 번호 따로 분리시키기
				int deleteok ;
				printf("정말로 삭제하시겠습니까?(삭제:1)");
				scanf("%d", &deleteok);
				if(deleteok == 1){
					deleteuser(&userlist[no]);
					user_count--;
				}
			// }
			loginflag = -1; // 삭제와 동시에 로그아웃
		}
	}
	return 0;
}
