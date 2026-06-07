#ifndef student_h
#define student_h

typedef struct Student {
    int id;
    char name[32];
    int score;
    struct Student* next;
} Student; //Student 구조체 선언


int add_student(Student** head, int id, const char* name, int score); //학생 추가

int delete_student(Student** head, int id); //학생 삭제

Student* find_student(Student* head, int id); //학생 검색

int update_student(Student* head, int id, int score); //점수 설정

void list_student(Student* head); //전체 학생 출력

void stats_student(Student* head); //통계 출력

void free_memory(Student** head); //동적 할당 메모리 해제

#endif
