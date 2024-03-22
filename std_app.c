
#include <stdio.h>
#include "std.h"
#include "student.h"
#include "stb.h"

///this file contains lots of function used in input/output operations
///like print the menu to the user
///then scanf the input of the user
///and so on....

///this function takes the user choice
///and call the responding function for this
///choice
///Also this function is static to prevent calling it from other files
static void SDB_action (uint8 choice);

///this function take a Student struct as a parameters
///and print its data to the user
///Also this function is static to prevent calling it from other files
static void printStudent(StudentModel student);

///this function used to read student data from the user
///and return it
///Also this function is static to prevent calling it from other files
static StudentModel scanStudent();

///this is DataBase instance which store the database
///Also variable is static to prevent accessing it from other files
static LinkedDataBase database;

/// this is the function which responsible for printing menu to the user
void application()
{
    //this variable store the user choice
    uint8 userChoice=-1;

    //initialize the database (header = NULL, usedSize = 0)
    database = initializeDataBase();

    //super_loop
    while(1)
    {
        printf(">> To add entry, enter 1\n"
               ">> To get used size in database, enter 2\n"
               ">> To read student data, enter 3 \n"
               ">> To get the list of all student IDs, enter 4\n"
               ">> To check is ID is existed, enter 5 \n"
               ">> To delete student data, enter 6\n"
               ">> To check is database is full, enter 7\n"
               ">> To exit enter 0\n\n");

        printf("SELECT: ");
        scanf("%u",&userChoice);

        //send the user choice to SDB_action
        SDB_action(userChoice);
        printf("\n\n");
    }
}


static void SDB_action (uint8 choice)
{
    //those some temporary variables used in different situations
    StudentModel tempS;
    boolean tempBool;
    uint32 tempUint,i;
    uint32 tempUintArr[MAX_SIZE];

    switch(choice)
    {
    case 0:
        printf("Best Wishes");
        exit(0); //close the application
        break;
    case 1:
        //get student from user
        tempS = scanStudent();
        //send the student to the database and store the function return in tempBool
        tempBool = SDB_AddEntry(&database,tempS);
        if(tempBool == false)
        {
            printf("Faile to Add Entry :(\n");
        }
        else
        {
            printf("Entry Added Successfully :)\n");
        }
        break;
    case 2:
        //get the size of database
        tempUint = SDB_GetUsedSize(&database);
        printf("Used Size = %d \n",tempUint);
        break;

    case 3:
        //read the id to search about
        printf("Enter ID to read: ");
        scanf("%u",&tempUint);

        //search in the database and store the function return in tempBool
        //also store the student in tempS whose address send to the function as an argument
        tempBool = SDB_GetEntry(&database,tempUint,&tempS);
        if(tempBool == false)
        {
            printf("Student With ID = %d not Found :(\n",tempUint);
        }
        else
        {
            //print the student if found
            printStudent(tempS);
        }
        break;

    case 4:
        //get the IDs list from database
        //store the size in tempUint
        //store the array itself in tempUintArr
        SDB_GetList(&database,&tempUint,tempUintArr);

        printf("There Are %u Student\nIDS:(",tempUint);
        for(i=0; i<tempUint; i++)
        {
            printf("%u, ",tempUintArr[i]);
        }
        printf(")\n");
        break;

    case 5:
       //read the id from the user to check if exits or not
        printf("Enter ID to check: ");
        scanf("%u",&tempUint);

        //check if ID exits or not
        tempBool = SDB_IsIdExist(&database,tempUint);
        if(tempBool == false)
        {
            printf("Student With ID = %d not Exist :(\n",tempUint);
        }
        else
        {
            printf("Student With ID = %d Exists :)\n",tempUint);
        }
        break;

    case 6:
        //read the id from the user
        printf("Enter ID to delete: ");
        scanf("%u",&tempUint);

        //remove the id from the database
        tempBool = SDB_DeletEntry(&database,tempUint);
        if(tempBool == false)
        {
            //if the ID is not removed or if ID is not found in the database
            printf("Student With ID = %d not Deleted :(\n",tempUint);
        }
        else
        {
            //if removed successfully from the database
            printf("Student With ID = %d Deleted Successfully :)\n",tempUint);
        }
        break;
    case 7:
        //check if database is full or not
        tempBool = SDB_IsFull(&database);
        if(tempBool == true)
        {
            printf("DataBase if FULL :(\n");
        }
        else
        {
            printf("DataBase if Not FULL :)\n");
        }
        break;

    default:
        printf("Wrong Choice :(\n");
        break;
    }
}

///this function used to read student data from the user
///and return it
///Also this function is static to prevent calling it from other files
static StudentModel scanStudent()
{
    StudentModel student;

    printf("Enter Student Id <Unique ID> : ");
    scanf("%u",&student.StudentID);

    printf("Enter Student Year: ");
    scanf("%u",&student.Studentyear);

    printf("Enter Course 1 Id and Grade (respectively): ");
    scanf("%u %u",&student.Course1ID,&student.Course1Grade);

    printf("Enter Course 2 Id and Grade (respectively): ");
    scanf("%u %u",&student.Course2ID,&student.Course2Grade);

    printf("Enter Course 3 Id and Grade (respectively): ");
    scanf("%u %u",&student.Course3ID,&student.Course3Grade);
    return student;
}


///this function take a Student struct as a parameters
///and print its data to the user
///Also this function is static to prevent calling it from other files
static void printStudent(StudentModel student)
{
    printf("Student ID = %u, At Year = %u\n",student.StudentID,student.Studentyear);
    printf("Course_1 ID = %u, Grade = %u\n",student.Course1ID,student.Course1Grade);
    printf("Course_2 ID = %u, Grade = %u\n",student.Course2ID,student.Course2Grade);
    printf("Course_3 ID = %u, Grade = %u\n",student.Course3ID,student.Course3Grade);
}


