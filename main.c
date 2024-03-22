#include <stdio.h>
#include <stdlib.h>

/*!
---AMIT-C Programming Project---

    Student Name:- Yosef Samy Yosef
    Group:- Embedded Maadi 534
    IDE:- CodeBlocks
    WhatsApp:- +201030296141
*/

/*!
PROJECT DOCUMENTATION

The project files are :-

    --> std.h      this file contain primitive typedef like uint32.

    --> student.h  this file contain the structure data of student

    --> stb.h      this header contain the function which
                are related to database operation like
                (SDB_IsFull, SDB_GetUsedSize, .......)

    --> stb.c      this source file contain the definition
                of the stb.h (mentioned above)

    --> std_app.h  this header contain the prototype "void application()"
                which is the entry point to the project

    --> std_app.c  this source file contain the definition of
                "void application()" which is mentioned above
                and also there are other functions which are related
                to input/output operations

    --> main.c     Of Course, this is the artery of the application


 All of these files, I have commented them as much as i can,
 I want you to read them on order in which i mentioned them above.

 Also the DataBase is based on Singly Linked List Data Structure

 If there are problem or unexpected error,
 please inform me with a ticket or WhatsApp (+201030296141)

*/

#include "std_app.h"

int main()
{
    printf("Welcome AMIT,\n"
           "This project is coded by Youssef Samy, Maadi 534\n"
           "If you find any error, Could you inform me please :)\n"
           "just To send you another update of this project\n"
           "-----------------------------------------------------------\n\n"
           );


    ///application function is responsible for print
    ///the menu to the user on the screen
    ///this function is in 'std_app.h' file
    application();
    return 0;
}
