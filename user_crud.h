#define ID_len 20

//계정
typedef struct{
        char id[ID_len];
        int pw;
}User;

// 계정 추가하는 함수
// int addUser(User *u);
int addUser(User *u, int);
// 하나의 계정을 출력하는 함수
void readuser(User u);
// 계정을 수정하는 함수
int updateuser(User *u);
// 계정을 목록에서 삭제하는 함수
int deleteuser(User *u);

//아이디 중복 여부 확인하는 함수
int idcheck(char *scanid, User *u, int);