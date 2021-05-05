#ifndef HEARDER
    #define HEADER
    #include <stdio.h>
    #include "post_crud.h"
#endif


int selectMenu(){ // 원하는 기능을 선택하는 함수
    int menu;
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
    scanf("%d", &menu);
    return menu;
}

// 글 추가하는 함수
int addpost(Post *p, user_account){ // 작성중인 유저 정보가 필요합니다.
    printf("게시글 제목을 적어주세요. : ");
    scanf("%s", p->title);
    printf("게시글 내용을 적어주세요. (500자까지 입력 가능합니다.)\n");
    scanf("%s", p->title);
    p->user = user_account; // 작성자중인 아이디를 알아야함. (작성자)
    return 1;
}
// 하나의 글을 출력하는 함수
void readpost(Post p){
    printf("제목 : %s \n 작성자 : %s \n내용 : %s \n\n  조회수 : %d \n 좋아요수 : %d\n", p.title, p.user, p.post, p.view, p.like);
}

// 모든 글을 출력하는 함수
void listpost(Post *p, int index){
    printf("|   제목   |   작성자  |   조회수  |   좋아요수  |\n"); // 크기 조절 해야함
    printf("-------------------------------------------------\n");
    for(int i = 0; i < index; i++){
        if(p[i].view == -1) continue;
            printf("%2d  ",i+1);
        readProduct(p[i]);
    }
}

// 글을 찾는 함수
void searchPost(Post *p, int index){
    int num = 0;
    char search[200];
    printf("검색할 게시글의 제목은? ");
    scanf("%s", search);
    printf("\n================================\n");
    for(int i = 0; i < index; i ++){
        if(p[i].view == -1) continue;
        if(strstr(p[i].title, search)){
            printf("%2d ",i+1);
            readPost(p[i]);
            num ++;
        }
    }
    if(num <= 0){
        printf("\n=> 검색된 데이터가 없습니다! \n");
    }
    else{
        printf("\n=> 총 %d 개의 결과가 있습니다. \n", num);
    }
}

// 글을 수정하는 함수 (내용은 모두 지워지고 새로 작성하게 된다.)
int updatepost(Post *p);


// 글을 목록에서 삭제하는 함수
int deletepost(Post *p);


/*
    스트럭트 Post 데이터 목록
    char title[title_len];
    char user[ID_len];
    char post[1000]; // 500자
    int view;
    int like;
    int index;
*/