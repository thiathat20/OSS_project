#ifndef HEARDER
    #define HEADER
    #include <stdio.h>
    #include "board.h"
#endif

#include <string.h>

// 11. 계정생성(아이디 비번 입력 받아 저장) (입력: 계정 구조체 배열 포인터, 출력:)
    // user_crud.h
// 2. 게시글 선택후 내용 출력(입력: 게시판 구조체 배열, 출력:) // 리스트 출력 없이 글 번호만 입력
void selectprintpost(Post *p, int count){
    int num;
    num = select_Post_DataNo(p, count);
    printf("제목 : %s \n 작성자 : %s\n  조회수 : %d \n 좋아요수 : %d\n내용 : %s\n", p[num].title, p[num].user, p[num].view, p[num].like, p[num].post);
}

// 3. 게시판 제목 리스트 출력 (입력: 게시판 구조체 배열, 출력:X)
void printpostlist(Post *p, int count){
    printf("|   제목   |   작성자  |   조회수  |   좋아요수  |\n"); // 크기 조절 해야함
    printf("-------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        if(p[i].view == -1) continue;
            printf("%2d  ",i+1);
        readOnePost(p[i]);
    }
}
void readOnePost(Post p){ // 게시글 리스트 번호 출력
    printf("제목 : %s  작성자 : %s 조회수 : %d 좋아요수 : %d\n", p.title, p.user, p.view, p.like);// 게시글의 제목 작성자 조회수 추천수 만 표시
}

// 4. 게시판 글쓰기 (입력: 이용중인 계정 구조체, 카운터(리턴), 게시판 리스트 포인터, 출력: 1 or 0)
int posting(Post *p, User u){
    int num; //내용 확인할지 물어보기 위해 만듬
    strcpy(p->user, u.id); // 아이디를 할당시켜 줌.
    printf("게시글 제목을 적어주세요. : ");
    scanf("%s", p->title);
    printf("게시글 내용을 적어주세요. (500자까지 입력 가능합니다.)\n");
    scanf("%s", p->title);
    printf("게시글 작성이 완료되었습니다.\n");
    printf("내용을 확인하시려면 1번 아니면 0번을 입력해주세요 : ");
    scanf("%d", &num);
    if(num==1){
        printf("제목 : %s \n 작성자 : %s\n  조회수 : %d \n 좋아요수 : %d\n내용 : %s\n", p->title, p->user, p->view, p->like, p->post);
    }
    else{
        return 1;
    }
    return 1;
}


// 5. 게시글 삭제 (입력: 게시판 구조체 배열 포인터, 계정 구조체, 출력: 1 or 0)
    // crud.h - deletepost
// 6. 게시글 키워드로 삭제 (입력: 게시판 구조체 배열 포인터,  계정 구조체, 출력:)
int deletekeyword(Post *p){
    char search[100];
    
}
// 7. 게시글 수정 (입력: 게시판 구조체 배열 포인터, 출력:)
    // crud.h update
// 8. 게시글 검색 (제목, 작성자, 내용 키워드)(입력: 게시판 구조체 배열, 출력:)
void serchpost(Post *p);
// 9. 생성일 , 추천수, 조회수 (높은순, 낮은순) 기준으로 보기 (입력: 게시판 구조체 배열, 출력:)
void sortpost(Post *p);
// 10. 게시판 저장 (입력: 게시판 구조체 배열, 출력:)
void saveboard(Post *p, int count);
// 9. 로그인 (입력: 계정 구조체 배열 포인터, 출력:)
int login(User *u, int count){
    char temp_id[20];
    int temp_pw;
    printf("아이디를 입력하세요: ");
    getchar();
    scanf("%[^\n]s", temp_id);
    int no;
    for(no = 0; no<count; no++){
        if(u[no].pw == -1) continue;
        if(0 != strcmp(u[no].id, temp_id)){
            printf("없는 계정입니다.\n");
            return -1;
        }
    }
    no--;
    printf("비밀번호를 입력하세요: ");
    getchar();
    scanf("%d", &temp_pw);
    if(u[no].pw != temp_pw){
        printf("%d\n", u[no].pw);
        printf("%d\n", temp_pw);
        printf("잘못된 비밀번호입니다.\n");
        return -1;
    }
    return no;
}
// 10. 로그아웃 - 로그인 여부 0
int logout();
// 12. 계정 목록 출력
void listuser(User *u, int count){
    printf("\n========게시판 사용자 목록========\n");
    for(int i=0; i<count; i++){
        if(u[i].pw == -1) continue;
   		printf("%2d ", i+1);
   		readuser(u[i]);
    }
}

//유저 데이터 선택 함수
int select_User_DataNo(User *u, int count){
    int no;
 	listuser(u, count);
 	printf("번호는? (취소:0)? ");
 	scanf("%d", &no);
    return no;
}

//포스트 데이터 선택 함수
int select_Post_DataNo(Post *p, int count){
    int no;
 	listpost(p, count);
 	printf("번호는? (취소:0)? ");
 	scanf("%d", &no);
    return no;
}