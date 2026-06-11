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
                *head = p->next;
            else
                prev->next = p->next;

            free(p);

            return 1;
        }

        prev = p;
        p = p->next;
    }

    return 0;
}

Student* find_student(Student* head, int id) {
    Student* p = head;

        while (p != NULL) {

            if (p->id == id)
                return p;

            p = p->next;
    }

    return NULL;
}

int update_student(Student* head, int id, int score) {
    Student* student = find_student(head, id);

    if (student == NULL)
        return 0;

    student->score = score;

    return 1;
}

void list_student(Student* head) {
    Student* p = head;

    if (p == NULL) {
        printf("student not found.\n");
        return;
    }

    printf("ID Name Score\n");

    while (p != NULL) {

        printf("%d %s %d\n", p->id, p->name, p->score);

        p = p->next;
    }
}

void stats_student(Student* head) {
    if (head == NULL) {
        printf("student not found.\n");
        return;
    }

    int count = 0;
    int sum = 0;

    int max = head->score;
    int min = head->score;

    Student* p = head;

    while (p != NULL) {

        count++;
        sum += p->score;

        if (p->score > max)
            max = p->score;

        if (p->score < min)
            min = p->score;

        p = p->next;
    }

    printf("Count: %d\n", count);
    printf("Average: %.1f\n", (double)sum / count);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

void free_memory(Student** head) {
    Student* p = *head;

    while (p != NULL) {

        Student* temp = p;

        p = p->next;

        free(temp);
    }

    *head = NULL;
}
