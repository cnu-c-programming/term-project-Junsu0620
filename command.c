#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "file_io.h"
#include "student.h"

ShellResult C_get_command(char* command, Student** head, const char* filename)
{
    char* c = strtok(command, " \n");

    if (c == NULL)
        return SHELL_ERROR;

    if (strcmp(c, "reload") == 0)
        return C_reload(head, filename);

    if (strcmp(c, "find") == 0)
        return C_find(*head, strtok(NULL, "\n"));

    if (strcmp(c, "list") == 0)
        return C_list(*head);

    if (strcmp(c, "stats") == 0)
        return C_stats(*head);

    if (strcmp(c, "help") == 0)
        return C_help();

    if (strcmp(c, "clear") == 0)
        return C_clear();

    if (strcmp(c, "exit") == 0)
        return C_exit();

#ifdef ADMIN_MODE

    if (strcmp(c, "save") == 0)
        return C_save(*head, filename);

    if (strcmp(c, "add") == 0)
        return C_add(head, strtok(NULL, "\n"));

    if (strcmp(c, "delete") == 0)
        return C_delete(head, strtok(NULL, "\n"));

    if (strcmp(c, "update") == 0)
        return C_update(*head, strtok(NULL, "\n"));

#endif

    return SHELL_ERROR;
}

ShellResult C_reload(Student** head, const char* filename)
{
    free_memory(head);

    if (load_students(filename, head) < 0)
        return SHELL_ERROR;

    return SHELL_OK;
}

ShellResult C_find(Student* head, char* args)
{
    if (args == NULL)
        return SHELL_ERROR;

    int id = atoi(args);

    Student* p = find_student(head, id);

    if (p == NULL) {

        printf("student not found\n");

        return SHELL_ERROR;
    }

    printf("%d %s %d\n",p->id, p->name, p->score);

    return SHELL_OK;
}

ShellResult C_list(Student* head)
{
    list_student(head);

    return SHELL_OK;
}

ShellResult C_stats(Student* head)
{
    stats_student(head);

    return SHELL_OK;
}

ShellResult C_help(void)
{
    printf("reload\n");
    printf("find <id>\n");
    printf("list\n");
    printf("stats\n");
    printf("help\n");
    printf("clear\n");
    printf("exit\n");

#ifdef ADMIN_MODE
    printf("save\n");
    printf("add (id) (name) (score)\n");
    printf("delete (id)\n");
    printf("update (id) (score)\n");
#endif

    return SHELL_OK;
}

ShellResult C_clear(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    return SHELL_OK;
}

ShellResult C_exit(void)
{
    return SHELL_EXIT;
}

ShellResult C_save(Student* head, const char* filename) {}

ShellResult C_add(Student** head, char* args) {}

ShellResult C_delete(Student** head, char* args) {}

ShellResult C_update(Student* head, char* args) {}
