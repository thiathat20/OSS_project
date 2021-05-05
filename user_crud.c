#ifndef HEARDER
    #define HEADER
    #include <stdio.h>
    #include "user_crud.h"
#endif
#include <string.h>

int addUser(User *u){
    printf("생성할 ID 입력: ");
    getchar();
    scanf("%[^\n]s", u->id);
    printf("생성할 비밀번호(숫자) 입력: ");
    scanf("%d", &u->pw);
    printf("계정이 생성 되었습니다.\n");
    return 1;
}
// 하나의 계정을 출력하는 함수
void readuser(User u){
    if(u.pw == -1){
        printf("계정이 없습니다...\n"); // 추후 다중 데이터에서는 삭제
        return;
    }
    printf("\t- %s\n", u.id);
}
// 계정을 수정하는 함수
int updateuser(User *u){
    int temp_pw;
    printf("기존 비밀번호를 입력 하세요: ");
    scanf("%d", &temp_pw);
    if(temp_pw != u->pw){ 
        printf("비밀번호가 잘못 되었습니다.\n");
        return 0;
    }
    printf("새 비밀번호를 입력 하세요: ");
    scanf("%d", &temp_pw);
    u->pw = temp_pw;
    printf("변경 되었습니다.\n");
    return 1;
}
// 계정을 목록에서 삭제하는 함수
int deleteuser(User *u){
    u->pw = -1;
    // strcpy(u->id, NULL); -- 버그 있음
    printf("계정이 삭제 되었습니다.\n");
    return 1;
}