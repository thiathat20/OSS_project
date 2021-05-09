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
    num = select_Post_DataNo(p, count) - 1;
    printf("제목 : %s \n 작성자 : %s\n  조회수 : %d \n 좋아요수 : %d\n내용 : %s\n", p[num].title, p[num].user, p[num].view, p[num].like, p[num].post);
}

// 3. 게시판 제목 리스트 출력 (입력: 게시판 구조체 배열, 출력:X)
void postlist(Post *p, int count){
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
    //post_crud.c
// 5. 게시글 삭제 (입력: 게시판 구조체 배열 포인터, 계정 구조체, 출력: 1 or 0)
    // crud.h - deletepost
// 6. 게시글 키워드로 삭제 (입력: 게시판 구조체 배열 포인터,  계정 구조체, 출력:)
int deletekeyword(Post *p){
    char search[100];
    return 1; // 임시 리턴(warring제거용) -- 필요에 따라 수정 할것
}
// 7. 게시글 수정 (입력: 게시판 구조체 배열 포인터, 출력:)
    // crud.h update
// 8. 게시글 검색 (제목, 작성자, 내용 키워드)(입력: 게시판 구조체 배열, 출력:)
void serchpost(Post *p);
// 9. 생성일 , 추천수, 조회수 (높은순, 낮은순) 기준으로 보기 (입력: 게시판 구조체 배열, 출력:)
void sortpost(Post *p);
// 10. 게시판 저장 (입력: 게시판 구조체 배열, 출력:)
void saveboard(Post *list, int n){
    FILE* pfile = fopen("postboard.txt", "wt");
	for(int i=0; i<n; i++){
		if(list[i].view == -1) continue;
		fprintf(pfile, "%s\n", list[i].title);
        fprintf(pfile, "%s\n", list[i].user);
        fprintf(pfile, "%s\n", list[i].post);
		fprintf(pfile, "%d ", list[i].view);
		fprintf(pfile, "%d ", list[i].like);
		fprintf(pfile, "%d ", list[i].index);
		fprintf(pfile, "\n");
	}
	fclose(pfile);
    printf("저장 완료\n");
}
void saveuser(User *list, int n){
    FILE* pfile = fopen("user.txt", "wt");
	for(int i=0; i<n; i++){
		if(list[i].pw == -1) continue;
		fprintf(pfile, "%s\n", list[i].id);
		fprintf(pfile, "%d\n", list[i].pw);
	}
	fclose(pfile);
}
int loadboard(Post *list){ // 저장된 리스트파일을 불러오는 함수
	FILE* pfile = fopen("postboard.txt", "rt");
	if(pfile == NULL){
		printf("게시판 파일이 없습니다\n");
		return 0;
	}
	printf("*** 로딩중... *** \n");
	int i=0;
	for(; i<100; i++){
		fscanf(pfile, " %[^\n]s", list[i].title);
        if(feof(pfile)) break;
        fscanf(pfile, " %[^\n]s", list[i].user);
        fscanf(pfile, " %[^\n]s", list[i].post);
        fscanf(pfile, " %d", &list[i].view);
        fscanf(pfile, " %d", &list[i].like);
        fscanf(pfile, " %d", &list[i].index);
	}
	printf("*** 로딩 성공 ***\n");
	fclose(pfile);
	return i;
}
int loaduser(User *list){ // 저장된 리스트파일을 불러오는 함수
	FILE* pfile = fopen("user.txt", "rt");
	if(pfile == NULL){
		printf("등록된 계정이 없습니다\n");
		return 0;
	}
	int i=0;
	for(; i<100; i++){
		fscanf(pfile, " %s", list[i].id);
        if(feof(pfile)) break;
        fscanf(pfile, " %d", &list[i].pw);
	}
	fclose(pfile);
	return i;
}

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
        if(0 == strcmp(u[no].id, temp_id)){ // 아이디가 일치하면
            // no--;
            printf("비밀번호를 입력하세요: ");
            getchar();
            scanf("%d", &temp_pw);
            // for(no = 0; no<count; no++){
            if(u[no].pw == temp_pw) return no; // 비밀번호가 일치하면
            // }
            printf("잘못된 비밀번호입니다.\n");
            return -1;
        }
    }
    printf("없는 계정입니다.\n");
    return -1;
}
// 10. 로그아웃 - 로그인 여부 0
int logout(){
    printf("로그아웃 되었습니다.\n");
    return -1;
}
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
int select_User_DataNo(User *u, int count){ // 작성자로 검색할때 사용해야지
    int no;
 	listuser(u, count);
 	printf("번호는? (취소:0)? ");
 	scanf("%d", &no);
    return no;
}

//포스트 데이터 선택 함수
int select_Post_DataNo(Post *p, int count){
    int no;
 	postlist(p, count);
 	printf("번호는? (취소:0)? ");
 	scanf("%d", &no);
    return no;
}

