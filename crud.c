#include <stdio.h>
#include "crud.h"

int selectMenu(){ // 원하는 기능을 선택하는 함수
    int menu;
    printf("\n*** 과일 스토어 관리 ***\n");
    printf("1. 계정 생성\n");
    printf("2. 게시글 보기\n");
    printf("3. 게시글 목록 보기\n");
    printf("4. 게시판 글쓰기\n");
	printf("5. 게시글 삭제\n");
	printf("6. 게시글 수정\n");
	printf("7. 게시글 검색\n");
	printf("8. 게시글 정렬 순서\n");
	printf("9. 게시판 저장\n");
    printf("10. 로그인\n");
    printf("11. 로그아웃\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 글 추가하는 함수
int addpost(Post *p);
// 하나의 글을 출력하는 함수
void readpost(Post p);
// 글을 수정하는 함수
int updatepost(Post *p);
// 글을 목록에서 삭제하는 함수
int deletepost(Post *p);
