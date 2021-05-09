#ifndef HEARDER
    #define HEADER
    #include <stdio.h>
    #include "post_crud.h"
#endif

#include <string.h>


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
    printf("13. 계정 비밀번호 수정\n");
    printf("14. 계정 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

// 글 추가하는 함수 이미 board.c 에서 구현 되어 있기 때문에 사용해야 하는 건지 모르겠음.
int addpost(Post *p, char *user_account, int post_index){ // 작성중인 유저 정보가 필요합니다.
    printf("게시글 제목을 적어주세요. : ");
    getchar();
    scanf("%[^\n]s", p->title);
    printf("게시글 내용을 적어주세요. (500자까지 입력 가능합니다.)\n");
    getchar();
    scanf("%[^\n]s", p->post);
    strcpy(p->user, user_account); // user_account작성자중인 아이디를 알아야함. (작성자)
    p->index = post_index;
    int num; //내용 확인할지 물어보기 위해 만듬
    printf("게시글 작성이 완료되었습니다.\n");
    printf("내용을 확인하시려면 1번 아니면 0번을 입력해주세요 : ");
    scanf("%d", &num);
    if(num==1){
        printf("제목 : %s \n등록번호 : %d\n작성자 : %s\n조회수 : %d \n좋아요수 : %d\n내용 : %s\n", p->title, p->index, p->user, p->view, p->like, p->post);
    }
    else{
        return 1;
    }

    return 1;
}

// 하나의 글을 출력하는 함수
void readOneContent(Post p){
    printf(" |  제목 : %s  |  작성자 : %s  |  조회수 : %d  |  좋아요수 : %d  |\n내용 : %s\n", p.title, p.user, p.view, p.like, p.post);
}

// 글을 수정하는 함수 (내용은 모두 지워지고 새로 작성하게 된다.)
int updatepost(Post *p){
    //권한 확인 함수 호출 할 필요가 있음.
    printf("게시글 제목을 적어주세요. : ");
    getchar();
    scanf("%[^\n]s", p->title);
    printf("게시글 내용을 적어주세요. (500자까지 입력 가능합니다.)\n");
    getchar();
    scanf("%[^\n]s", p->post);
    printf("수정성공!\n");
    return 1;
}


// 글을 목록에서 삭제하는 함수
int deletepost(Post *p){
    //권한 확인 함수 호출 할 필요가 있음.
    p->title[0] = '\0';
    p->user[0] = '\0';
    p->post[0] = '\0';
    p->view = -1;
    p->like = -1;
    printf("=> 삭제됨!\n");
  return 1;
}


//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/* 이건 board.c 로 가야함.
// 모든 게시글 목록을 출력하는 함수
void readPostList(Post *p, int index){
    printf("|   제목   |   작성자  |   조회수  |   좋아요수  |\n"); // 크기 조절 해야함
    printf("-------------------------------------------------\n");
    for(int i = 0; i < index; i++){
        if(p[i].view == -1) continue;
            printf("%2d  ",i+1);
        readOnePost(p[i]);
    }
}

// 게시글의 제목 작성자 조회수 추천수 만 표시
void readOnePost(Post p){
    printf("제목 : %s \n 작성자 : %s \n내용 : %s \n\n  조회수 : %d \n 좋아요수 : %d\n", p.title, p.user, p.post, p.view, p.like);
}




// 하나의 글을 출력하는 함수
void readOneContent(Post p){
    printf("제목 : %s \n 작성자 : %s \n내용 : %s \n\n  조회수 : %d \n 좋아요수 : %d\n내용 : %s\n", p.title, p.user, p.post, p.view, p.like, p.post);
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

// 데이터 번호를 입력받는 함수
int selectDataNo(Post *p, int index){
  listProduct(p, index);
  int no;
  printf("번호는(취소:0)?");
  scanf("%d",&no);
  return no;
}
*/

/*
    스트럭트 Post 데이터 목록
    char title[title_len];
    char user[ID_len];
    char post[1000]; // 500자
    int view;
    int like;
    int index;
*/