#ifndef student_h
#define student_h

typedef struct Student {
    int id;
    char name[32];
    int score;
    struct Student* next;
} Student; //Student 구조체 선언


int S_add(Student** head, int id, const char* name, int score); //학생 추가

int S_delete(Student** head, int id); //학생 삭제

Student* S_find(Student* head, int id); //학생 검색

int S_update(Student* head, int id, int score); //점수 설정

void S_list(Student* head); //전체 학생 출력

void S_stats(Student* head); //통계 출력

void S_free_memory(Student** head); //동적 할당 메모리 해제

#endif
