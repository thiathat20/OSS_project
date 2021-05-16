#ifndef HEARDER
    #define HEADER
    #include <stdio.h>
    #include <stdlib.h>
    #include "board.h"
#endif

#include <string.h>

// 1. 게시글 선택후 내용 출력(입력: 게시판 구조체 배열, 출력:)
void selectprintpost(Post *p, int count){
    int num;
    int yesorno;
    num = select_Post_DataNo(p, count);
    p[num].view ++;
    printf("|  제목 : %s  |  작성자 : %s  |  조회수 : %d  |  좋아요수 : %d  |\n내용 : %s\n", p[num].title, p[num].user, p[num].view, p[num].like, p[num].post);
    while(1){
        printf("이 글을 좋아요합니다.(yes = 1 / no = 0)");
        scanf("%d", &yesorno);
        if(yesorno == 0){
            printf("이 글을 좋아요하지 않았습니다.\n");
            printf("현재 좋아요 수는 %d개입니다.\n", p[num].like);
            break;
        }
        else if (yesorno == 1)
        {
            p[num].like ++;
            printf("이 글을 좋아요 수가 증가하였습니다.\n");
            printf("현재 좋아요 수는 %d개입니다.\n", p[num].like);
            break;
        }
        else{
            printf("숫자를 잘못 입력하셨습니다. 다시 입력해주세요.\n");
        }
    }
}

// 2. 게시판 제목 리스트 출력 (입력: 게시판 구조체 배열, 출력:X)
void readPostList(Post *p, int count){
    printf("-------------------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        if(p[i+1].view == -1) continue;
            printf("%2d  ",i+1);
        readOnePost(p[i+1]);
    }
}
void readOnePost(Post p){ // 게시글 리스트 번호 출력
    printf("|  제목 : %s  |  작성자 : %s  |  조회수 : %d  |  좋아요수 : %d  |  등록번호 : %d\n", p.title, p.user, p.view, p.like, p.index);// 게시글의 제목 작성자 조회수 추천수 만 표시
}

// 3. 게시판 글쓰기 (입력: 이용중인 계정 구조체, 카운터(리턴), 게시판 리스트 포인터, 출력: 1 or 0)
//post_crud.c - addpost참고


// 4. 게시글 삭제 (입력: 게시판 구조체 배열 포인터, 계정 구조체, 출력: 1 or 0)
// post_crud.c - deletepost 참고


// 5. 게시글 수정 (입력: 게시판 구조체 배열 포인터, 출력:)
// post_crud.c - updatepost 참고


// 6. 게시글 검색 (제목, 작성자, 내용 키워드)(입력: 게시판 구조체 배열, 출력:)
void searchpost(Post *p, int post_index){
    char search[100];
    int keyword = 0;
    int num = 0;
    while(1){
        clearbuffer();
        printf("제목[1], 작성자[2], 내용[3] 메뉴를 선택해주세요 : ");
        scanf("%d", &keyword);
        if (keyword == 1)
        {
            //제목으로 검색
            printf("\n 게시글의 제목을 입력해주세요 : ");
            scanf("%s", search);
            printf("-------------------------------------------------------------------------------------\n");
            printf("-------------------------------------------------------------------------------------\n");
            for(int i = 0; i < post_index; i ++){
                if(p[i+1].view == -1) continue;
                if(strstr(p[i+1].title, search)){
                    printf("%2d ",i+1);
                    readOneContent(p[i+1]);
                    num ++;
                }
            }
            if(num == 0){
                printf("\n=> 검색된 데이터가 없습니다! \n");
            }
            break;
        }
        else if (keyword == 2)
        {
            //제목으로 검색
            printf("\n 게시글의 작성자를 입력해주세요 : ");
            scanf("%s", search);
            printf("-------------------------------------------------------------------------------------\n");
            printf("-------------------------------------------------------------------------------------\n");
            for(int i = 0; i < post_index; i ++){
                if(p[i+1].view == -1) continue;
                if(strstr(p[i+1].user, search)){
                    printf("%2d ",i+1);
                    readOneContent(p[i+1]);
                    num ++;
                }
            }
            if(num == 0){
                printf("\n=> 검색된 데이터가 없습니다! \n");
            }
            break;
        }
        else if (keyword == 3)
        {
            printf("\n 게시글의 내용을 입력해주세요 : ");
            scanf("%s", search);
            printf("-------------------------------------------------------------------------------------\n");
            printf("-------------------------------------------------------------------------------------\n");
            for(int i = 0; i < post_index; i ++){
                if(p[i+1].view == -1) continue;
                if(strstr(p[i+1].post, search)){
                    printf("%2d ",i+1);
                    readOneContent(p[i+1]);
                    num ++;
                }
            }
            if(num == 0){
                printf("\n=> 검색된 데이터가 없습니다! \n");
            }
            break;
        }
        else{
            printf("\n숫자를 잘못 입력하셨습니다. 다시 입력해주세요\n");
        }
    }
}


// 7. 생성일 , 추천수, 조회수 (높은순, 낮은순) 기준으로 보기 (입력: 게시판 구조체 배열, 출력:)
void sortingnew(Post *p, int index, int updown){
    int i, j;
    Post temp;
    if(updown == 0){ // 0이면 높은순 
        for(i = 0; i < index; i++){
            for(j = 1; j < index - i ; j++){
                if(p[j].index < p[j+1].index){
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    if(updown == 1){ // 1이면 낮은순 
        for(i = 0; i < index; i++){
            for(j = 1; j < index - i ; j++){
                if(p[j].index > p[j+1].index){
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
}
void sortinglike(Post *p, int index, int updown){
    int i, j;
    Post temp;
    if(updown == 0){ // 0이면 높은 순
        for(i = 0; i < index; i++){
            for(j = 1; j < index - i ; j++){
                if(p[j].like < p[j+1].like){
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    if(updown == 1){ // 1이면 낮은 순
        for(i = 0; i < index; i++){
            for(j = 1; j < index - i ; j++){
                if(p[j].like > p[j+1].like){
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }

}
void sortingview(Post *p, int index, int updown){
    int i, j;
    Post temp;
    if(updown == 0){ // 0이면 높은 순
        for(i = 0; i < index; i++){
            for(j = 1; j < index - i ; j++){
                if(p[j].view < p[j+1].view){
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    if(updown == 1){ // 1이면  순
        for(i = 0; i < index; i++){
            for(j = 1; j < index - i ; j++){
                if(p[j].view > p[j+1].view){
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
}
int sortpost(Post *p, int index){
    int select = 0;
    int updown;
    int sort;
    while(1){
        clearbuffer();
        printf("게시글의 정렬 순서를 정합니다.\n");
        printf("생성일 기준(1) | 좋아요 수 기준(2) | 조회수 순(3) | 취소(0)\n");
        printf("번호를 입력해주세요 : \n");
        scanf("%d", &select);
        if (select == 1){
            while(1){
                clearbuffer();
                printf("최신 순은 (0번) | 오래된 순 (1번)\n");
                scanf("%d", &updown);
                if(updown == 1 || updown == 0){
                    break;
                }
            }
            if(updown == 0){
                sort = 1;
                printf("최신 순으로 정렬합니다.\n");
                sortingnew(p, index, updown);
                break;
            }
            if(updown == 1){
                sort = 2;
                printf("오래된 순으로 정렬합니다.\n");
                sortingnew(p, index, updown);
                break;
            }
        }
        else if (select == 2)
        {
            printf("좋아요가 많은 순으로 게시글을 정렬합니다.\n");
            while(1){
                clearbuffer();
                printf("많은 순은 (0번) | 적은 순 (1번)\n");
                scanf("%d", &updown);
                if(updown == 1 || updown == 0){
                    break;
                }
            }
            if(updown == 0){
                sort = 3;
                printf("많은 순으로 정렬합니다.\n");
                sortinglike(p, index, updown);
                break;
            }
            if(updown == 1){
                sort = 4;
                printf("적은 순으로 정렬합니다.\n");
                sortinglike(p, index, updown);
                break;
            }

        }
        else if (select == 3)
        {
            printf("조회수가 많은 순으로 게시글을 정렬합니다.\n");
            while(1){
                clearbuffer();
                printf("많은 순은 (0번) | 적은 순 (1번)\n");
                scanf("%d", &updown);
                if(updown == 1 || updown == 0){
                    break;
                }
            }
            if(updown == 0){
                sort = 5;
                printf("많은 순으로 정렬합니다.\n");
                sortingview(p, index, updown);
                break;
            }
            if(updown == 1){
                sort = 6;
                printf("적은 순으로 정렬합니다.\n");
                sortingview(p, index, updown);
                break;
            }
        }
        else{
            printf("정렬을 취소합니다.\n");
            break;
        }
    }
    return sort;
}

// 8. 게시판 저장 (입력: 게시판 구조체 배열, 출력:)
void saveboard(Post *list, int n){
    sortingnew(list, n, 1);

    FILE* pfile = fopen("postboard.txt", "wt");
	for(int i=0; i<n; i++){
		if(list[i+1].view == -1) continue;
		fprintf(pfile, "%s\n", list[i+1].title);
        fprintf(pfile, "%s\n", list[i+1].user);
        fprintf(pfile, "%s\n", list[i+1].post);
		fprintf(pfile, "%d ", list[i+1].view);
		fprintf(pfile, "%d ", list[i+1].like);
		fprintf(pfile, "\n");
	}
	fclose(pfile);
    printf("저장 완료\n");
}
// 8. 계정 저장
void saveuser(User *list, int n){
    FILE* pfile = fopen("user.txt", "wt");
	for(int i=0; i<n; i++){
		if(list[i].pw == -1) continue;
		fprintf(pfile, "%s\n", list[i].id);
		fprintf(pfile, "%d\n", list[i].pw);
	}
	fclose(pfile);
}
// 게시판 불러오기
int loadboard(Post *list){ // 저장된 리스트파일을 불러오는 함수
	FILE* pfile = fopen("postboard.txt", "rt");
	if(pfile == NULL){
		printf("게시판 파일이 없습니다\n");
		return 0;
	}
	printf("*** 로딩중... *** \n");
	int i=0;
	for(; i<100; i++){
		fscanf(pfile, " %[^\n]s", list[i+1].title);
        if(feof(pfile)) break;
        fscanf(pfile, " %[^\n]s", list[i+1].user);
        fscanf(pfile, " %[^\n]s", list[i+1].post);
        fscanf(pfile, " %d", &list[i+1].view);
        fscanf(pfile, " %d", &list[i+1].like);
        list[i+1].index = i+1;
	}
	printf("*** 로딩 성공 ***\n");
	fclose(pfile);
	return i;
}
// 계정 불러오기
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

// 11. 계정생성(아이디 비번 입력 받아 저장) (입력: 계정 구조체 배열 포인터, 출력:)
// user_crud.h

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

//포스팅 데이터 선택 함수
int select_Post_DataNo(Post *p, int count){
    int no = -1;
 	readPostList(p, count);
    while(1){
        printf("번호는? (취소:0) : ");
 	    scanf("%d", &no);
        if(no > -1){
            break;
        }
        else{
            printf("번호를 잘못 입력하셨습니다. 다시 입력해주세요.\n");
            printf("번호는? (취소:0) : ");
            scanf("%d", &no);// 이거 어떻게 해야하지
        }
        getchar();
    }
    return no;
}

//입력 버퍼로 인한 버그수정을 위해 버퍼 비우는 함수
void clearbuffer(){
    while(getchar() != '\n');
}