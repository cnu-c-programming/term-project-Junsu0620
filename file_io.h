#ifndef file_io_h
#define file_io_h

#include "student.h"

int load_students(const char* filename, Student** head);

int save_students(const char* filename, Student* head);

#endif
