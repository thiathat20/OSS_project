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
	int menu = -1; // '입력 버퍼 제거' 버그 수정을 위해 프로그램이 첫 가동인지 확인
	int loginflag = -1; // 로그인 상태 확인 
	
	int post_count = 0; // file open/load
	int user_count = 0; // 로드 구한 하면 계정 갯수 넣기
	
	post_count = loadboard(postlist);
	user_count = loaduser(userlist);

	int post_index = post_count;
	int user_index = user_count;

	int sort = 2; // 정렬 순서를 정합니다.

	while(1){

		if(menu != -1){
			clearbuffer(); // 처음을 제외하고 계속 버퍼를 비워라 -- 무한반복 막기
		}
		
		if(sort == 1)
			sortingnew(postlist, post_index, 0);
		else if(sort == 2)
			sortingnew(postlist, post_index, 1);
		else if(sort == 3)
			sortinglike(postlist, post_index, 0);
		else if(sort == 4)
			sortinglike(postlist, post_index, 1);
		else if(sort == 5)
			sortingview(postlist, post_index, 0);
		else if(sort == 6)
			sortingview(postlist, post_index, 1);


		if(loginflag != -1){ // 현재 이용중인 사용자 표시
			printf("\n(** 로그인 사용자: \"%s\" **)\n", userlist[loginflag].id);
		}
		menu = selectMenu(); // 기능 메뉴 선택
		if(menu == 0) break;
		if(menu != 11)
			if(user_count == 0){
				printf("err: 등록된 사용자가 없습니다.\n");
				continue;
			}
		if(menu != 9 && menu != 12 && menu != 11) // 로그인 상태가 아니면 이용 가능한 메뉴 제약
			if(loginflag == -1){
				printf("로그인이후 이용가능 합니다.\n");
				continue;
			}
		if(menu == 1){ // 게시글 내용 보기
			if(post_index == 0){
				printf("err: 등록된 게시글이 없습니다.\n");
				continue;
			}
			else
				selectprintpost(postlist, post_index);
		}
		else if(menu == 2){ // 게시글 목록 보기(제목만 보이도록)
			if(post_index == 0){
				printf("err: 등록된 게시글이 없습니다.\n");
				continue;
			}
			else
				readPostList(postlist, post_index);
			
		}
		else if(menu == 3) { // 게시글 쓰기
			post_index++;
			addpost(&postlist[post_index], userlist[loginflag].id, post_index);
		}
		else if(menu == 4){ // 게시글 삭제
			if(post_index == 0){
				printf("err: 등록된 게시글이 없습니다.\n");
				continue;
			}
			else{
				int slt;
				int no = 0;
				printf("( 번호로 삭제하기:0 / 키워드로 삭제하기:1 ): ");
				getchar();
				scanf("%d", &slt);
				if(slt == 0){ // 번호로 삭제하기
					printf("삭제할 게시글의 번호를 입력해주세요\n");
					no = select_Post_DataNo(postlist, post_index);
				}
				else if(slt == 1){ // 키워드로 삭제하기
					printf("삭제할 게시글의 번호를 입력해주세요\n");
					searchpost(postlist, post_index);
					printf("번호는? (취소:0)? ");
 					scanf("%d", &no);
				}
				else printf("잘못된 입력입니다.\n");
				if(0 != strcmp(userlist[loginflag].id, postlist[no].user)){
					printf("err: 글은 작성자만 지울수 있습니다.\n");
					continue;
				}
				else if(no > 0){
					int deleteok ;
					printf("정말로 삭제하시겠습니까?(삭제:1 / 취소:0)");
					scanf("%d", &deleteok);
					if(deleteok == 1){
						deletepost(&postlist[no]);
						post_count--;
					}
				}
			}
		}
		else if(menu == 5){ // 게시글 수정
			if(post_index == 0){
				printf("err: 등록된 게시글이 없습니다.\n");
				continue;
			}
			else{
				int no = select_Post_DataNo(postlist, post_index);
				if(0 != strcmp(userlist[loginflag].id, postlist[no].user)){
					printf("err: 글은 작성자만 수정할 수 있습니다.\n");
					continue;
				}
				if( no > 0){
					int updateok ;
					printf("기존 글을 지우고 새로 작성 합니다 정말로 수정하시겠습니까?(수정:1)");
					scanf("%d", &updateok);
					if(updateok == 1){
						updatepost(&postlist[no]);
					}
				}
			}
		}
		else if(menu == 6){ // 게시글 검색 -- 키워드, 작성자, ...
			if(post_index == 0){
				printf("err: 등록된 게시글이 없습니다.\n");
				continue;
			}
			else
				searchpost(postlist, post_index);
		}
		else if(menu == 7){ // 게시글 목록 정렬해서 보기
			if(post_index == 0){
				printf("err: 등록된 게시글이 없습니다.\n");
				continue;
			}
			else{
				// 뭔가 해야하는데 ㅋㅋ
				sort = sortpost(postlist, post_index);
			}
			
		}
		else if(menu == 8){ // 게시판 저장
			if(post_index == 0){
				printf("err: 등록된 게시글이 없습니다.\n");
				continue;
			}
			else{
				saveboard(postlist, post_index);
				saveuser(userlist, user_index);
			}
		}
		else if(menu == 9){ // 로그안
			if(loginflag != -1) loginflag = logout(); // 기존 로그인 로그이웃
			loginflag = login(userlist, user_index);
		}
		else if(menu == 10){ // 로그아웃
			loginflag = logout();
		}
		else if(menu == 11){ // 계정 생성
			if(addUser(userlist, user_index)){
				user_index++;
				user_count++;
			}
		}
		else if(menu == 12){ // 계정 목록 확인
			listuser(userlist, user_index);
		}
		else if(menu == 13){ // 계정 비밀번호 수정
			int no = loginflag;
			if(loginflag != -1){
				updateuser(&userlist[no]);
			}
		}
		else if(menu == 14){ // 계정 삭제
			int no = loginflag;
			int deleteok ;
			printf("정말로 삭제하시겠습니까?(삭제:1)");
			scanf("%d", &deleteok);
			if(deleteok == 1){
				deleteuser(&userlist[no]);
				user_count--;
			}
			loginflag = -1; // 삭제와 동시에 로그아웃
		}
	}
	return 0;
}
