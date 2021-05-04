#include "post_crud.h"
#include "user_crud.h"

// 1. 계정생성(아이디 비번 입력 받아 저장) (입력: 계정 구조체 배열 포인터, 출력:)
    //
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
// 11. 로그인 (입력: 계정 구조체 배열 포인터, 출력:)
int login(User *u);
// 12. 로그아웃 - 로그인 여부 0
int logout();
// 13. 계정 리스트
