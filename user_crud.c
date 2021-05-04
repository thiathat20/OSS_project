#ifndef HEARDER
    #define HEADER
    #include <stdio.h>
    #include "user_crud.h"
#endif

void addUser(User u){
    printf("생성할 ID 입력: ");
    getchar();
    scanf("%[^\n]s", u.id);
    printf("생성할 비밀번호(숫자) 입력: ");
    scanf("%d", &u.pw);
    printf("계정이 생성 되었습니다.\n");
}
// 하나의 계정을 출력하는 함수
void readuser(User p);
// 계정을 수정하는 함수
int updateuser(User *p);
// 계정을 목록에서 삭제하는 함수
int deleteuser(User *p);