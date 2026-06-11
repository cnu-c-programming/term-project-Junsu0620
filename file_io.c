#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_io.h"
#include "student.h"

nt load_students(const char* filename, Student** head)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char line[256];

    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        return 0;
    }

    line[strcspn(line, "\r\n")] = '\0';

    if (strcmp(line, "id,name,score") != 0) {
        fclose(fp);
        return -1;
    }

    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        int id, score;
        char name[32];

        line[strcspn(line, "\r\n")] = '\0';

        if (sscanf(line, "%d,%31[^,],%d", &id, name, &score) != 3) {
            continue;
        }

        if (score < 0 || score > 100) {
            continue;
        }

        if (add_student(head, id, name, score)) {
            count++;
        }
    }

    fclose(fp);
    return count;
}

int save_students(const char* filename, Student* head)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    fprintf(fp, "id,name,score\n");

    Student* p = head;
    int count = 0;

    while (p != NULL) {
        fprintf(fp, "%d,%s,%d\n", p->id, p->name, p->score);

        count++;
        p = p->next;
    }

    fclose(fp);
    return count;
}