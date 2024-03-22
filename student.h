#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "std.h"

///this file contain the student attributes (id, year, courses ids and grades)
///which are defined inside a struct called 'StudentModel'

typedef struct
{
    uint32 StudentID;
    uint32 Studentyear;

    uint32 Course1ID;
    uint32 Course1Grade;

    uint32 Course2ID;
    uint32 Course2Grade;

    uint32 Course3ID;
    uint32 Course3Grade;

} StudentModel;


#endif // STUDENT_H_INCLUDED
