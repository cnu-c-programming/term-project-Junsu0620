#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "file_io.h"
#include "command.h"

#define BUFFER_SIZE 256

void run_shell(const char *csv_path) {
    Student* head = NULL;

    load_students(csv_path, &head);

    char command[BUFFER_SIZE];

    while (1)
    {
        printf(">> ");

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        ShellResult result = C_get_command(command, &head, csv_path);

        if (result == SHELL_EXIT)
            break;
    }

#ifdef ADMIN_MODE
    save_students(csv_path, head);
#endif

    free_memory(&head);
}

void run_command_file(const char *cmd_file, const char *csv_path) {
    Student* head = NULL;

    load_students(csv_path, &head);

    FILE* fp = fopen(cmd_file, "r");

    if (fp == NULL)
    {
        printf("Cannot open %s\n", cmd_file);

        free_memory(&head);

        return;
    }

    char command[BUFFER_SIZE];

    while (fgets(command, sizeof(command), fp) != NULL)
    {
        ShellResult result = C_get_command(command, &head, csv_path);

        if (result == SHELL_EXIT)
            break;
    }

    fclose(fp);

#ifdef ADMIN_MODE
    save_students(csv_path, head);
#endif

    free_memory(&head);
}

int main(int argc, char *argv[])
{
    const char *csv_path = "students.csv";
    const char *cmd_file = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            cmd_file = argv[++i];
        }
        else {
            csv_path = argv[i];
        }
    }

#ifdef ADMIN_MODE

    if (cmd_file)
        run_command_file(cmd_file, csv_path);
    else
        run_shell(csv_path);

#elif defined(CLIENT_MODE)

    if (cmd_file)
        run_command_file(cmd_file, csv_path);
    else
        run_shell(csv_path);

#else
#error "Define <-DADMIN_MODE> or <-DCLIENT_MODE>"
#endif

    return 0;
}
