#ifndef command_h
#define command_h

#include "student.h"

typedef enum {
    SHELL_OK,
    SHELL_EXIT,
    SHELL_ERROR
} ShellResult;

ShellResult C_get_command(char* command, Student** head, const char* filename); //명령어 읽기

//Client & ADMIN 둘 다 사용
ShellResult C_reload(Student** head, const char* filename);

ShellResult C_find(Student* head, char* args);

ShellResult C_list(Student* head);

ShellResult C_stats(Student* head);

ShellResult C_help(void);

ShellResult C_clear(void);

ShellResult C_exit(void);

#ifdef ADMIN_MODE

// ADMIN만 사용 

ShellResult C_save(Student* head, const char* filename);

ShellResult C_add(Student** head, char* args);

ShellResult C_delete(Student** head, char* args);

ShellResult C_update(Student* head, char* args);

#endif

#endif
