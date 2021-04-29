// CRUD 프로젝트 헤더파일

#define ID_len 20
#define title_len 200

//계정
typedef struct{
	char id[ID_len];
	int pw;
}user;

//게시판
typedef struct{
	char title[title];
	char user[ID_len];
	char post[1000]; // 500자
	int view;
	int like;
	int index;
}board;

int selectMenu(); // 원하는 기능을 선택하는 함수

// 글 추가하는 함수
int addpost(post *p);
// 하나의 글을 출력하는 함수
void readpost(post p);
// 글을 수정하는 함수
int updatepost(post *p);
// 글을 목록에서 삭제하는 함수
int deletepost(post *p);
