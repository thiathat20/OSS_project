// CRUD 프로젝트 헤더파일

#define ID_len 20
#define title_len 200

//게시판
typedef struct{
        char title[title_len];
        char user[ID_len];
        char post[1000]; // 500자
        int view;
        int like;
        int index;
}Post;

int selectMenu(); // 원하는 기능을 선택하는 함수

// 글 추가하는 함수
int addpost(Post *p, char *user_account, int post_index);
// 하나의 글을 출력하는 함수
void readpost(Post p);
// 글을 수정하는 함수
int updatepost(Post *p);
// 글을 목록에서 삭제하는 함수
int deletepost(Post *p);
// 하나의 글을 출력하는 함수
void readOneContent(Post p);