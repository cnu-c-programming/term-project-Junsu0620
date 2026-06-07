#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

int add_student(Student** head, int id,const char* name, int score) {
    Student* p = *head;

    while (p != NULL) {
        if (p->id == id)
            return 0;

        p = p->next;
    }

    Student* newNode =
        (Student*)malloc(sizeof(Student));

    if (newNode == NULL)
        return -1;

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->score = score;

    newNode->next = *head;
    *head = newNode;

    return 1;
}

int delete_student(Student** head, int id) {
    Student* p = *head;
    Student* prev = NULL;

    while (p != NULL) {

        if (p->id == id) {

            if (prev == NULL)
                *head = cur->next;
            else
                prev->next = cur->next;

            free(p);

            return 1;
        }

        prev = p;
        p = p->next;
    }

    return 0;
}

Student* find_student(Student* head, int id) {

}

int update_student(Student* head, int id, int score) {

}

void list_student(Student* head) {

}

void stats_student(Student* head) {

}

void free_memory(Student** head) {

}
