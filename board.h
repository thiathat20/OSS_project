#include "post_crud.h"
#include "user_crud.h"

// 1. 계정생성(아이디 비번 입력 받아 저장) (입력: 계정 구조체 배열 포인터, 출력:)
    //
// 2. 게시글 선택후 내용 출력(입력: 게시판 구조체 배열, 출력:) // 리스트 출력 없이 글 번호만 입력
void selectprintpost(Post *p, int count); // 리스트에서 고르고 내용을 출력해야해서 리스트를 출력하고 번호를 고르는 함수 하나 추가함
// 3. 게시판 제목 리스트 출력 (입력: 게시판 구조체 배열, 출력:X)
void printpostlist(Post *p, int count); // VS listpost()??
void readOnePost(Post p); // 게시글의 제목(내용x)를 출력하는 함수.
// 4. 게시판 글쓰기 (입력: 이용중인 계정 구조체, 카운터(리턴), 게시판 리스트 포인터, 출력: 1 or 0)
int posting(Post *p, User u);
// 5. 게시글 삭제 (입력: 게시판 구조체 배열 포인터, 계정 구조체, 출력: 1 or 0)
    // crud.h - deletepost
// 6. 게시글 키워드로 삭제 (입력: 게시판 구조체 배열 포인터,  계정 구조체, 출력:)
int deletekeyword(Post *p);
// 7. 게시글 수정 (입력: 게시판 구조체 배열 포인터, 출력:)
    // crud.h update
// 8. 게시글 검색 (제목, 작성자, 내용 키워드)(입력: 게시판 구조체 배열, 출력:)
void searchpost(Post *p, int post_index);
// 9. 생성일 , 추천수, 조회수 (높은순, 낮은순) 기준으로 보기 (입력: 게시판 구조체 배열, 출력:)
void sortpost(Post *p);
// 10. 게시판 저장 (입력: 게시판 구조체 배열, 출력:)
void saveboard(Post *p, int count);
void saveuser(User *u, int count);
int loadboard(Post *p);
int loaduser(User *u);
// 11. 로그인 (입력: 계정 구조체 배열 포인터, 출력:)
int login(User *u, int count);
// 12. 로그아웃 - 로그인 여부 0
int logout();
// 12. 계정 목록 출력
void listuser(User *u, int count);

//데이터 선택 함수
int select_User_DataNo(User u[], int count);
int select_Post_DataNo(Post p[], int count);