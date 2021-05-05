#ifndef HEARDER
    #define HEADER
    #include <stdio.h>
    #include "board.h"
#endif



// 11. 계정생성(아이디 비번 입력 받아 저장) (입력: 계정 구조체 배열 포인터, 출력:)
    // user_crud.h
// 2. 게시글 선택후 내용 출력(입력: 게시판 구조체 배열, 출력:) // 리스트 출력 없이 글 번호만 입력
void printpost(Post p);
// 3. 게시판 제목 리스트 출력 (입력: 게시판 구조체 배열, 출력:X)
void printpostlist(Post *p, int count);
// 4. 게시판 글쓰기 (입력: 이용중인 계정 구조체, 카운터(리턴), 게시판 리스트 포인터, 출력: 1 or 0)
int posting(Post *p, User u);
// 5. 게시글 삭제 (입력: 게시판 구조체 배열 포인터, 계정 구조체, 출력: 1 or 0)
    // crud.h - deletepost
// 6. 게시글 키워드로 삭제 (입력: 게시판 구조체 배열 포인터,  계정 구조체, 출력:)
int deletekeyword(Post *p);
// 7. 게시글 수정 (입력: 게시판 구조체 배열 포인터, 출력:)
    // crud.h update
// 8. 게시글 검색 (제목, 작성자, 내용 키워드)(입력: 게시판 구조체 배열, 출력:)
void serchpost(Post *p);
// 9. 생성일 , 추천수, 조회수 (높은순, 낮은순) 기준으로 보기 (입력: 게시판 구조체 배열, 출력:)
void sortpost(Post *p);
// 10. 게시판 저장 (입력: 게시판 구조체 배열, 출력:)
void saveboard(Post *p, int count);
// 9. 로그인 (입력: 계정 구조체 배열 포인터, 출력:)
int login(User *u);
// 10. 로그아웃 - 로그인 여부 0
int logout();
// 12. 계정 목록 출력
int listuser(User *u, int count){
    printf("\n========게시판 사용자 목록========\n");
    for(int i=0; i<count; i++){
        if(u[i].pw == -1) continue;
   		printf("%2d ", i+1);
   		readuser(u[i]);
    }
    return 0;
}

//데이터 선택 함수
int select_User_DataNo(User *u, int count){
    int no;
 	listuser(u, count);
 	printf("번호는? (취소:0)? ");
 	scanf("%d", &no);
    return no;
}