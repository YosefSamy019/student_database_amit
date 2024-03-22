#ifndef STB_H_INCLUDED
#define STB_H_INCLUDED
#include "student.h"


///this file contains --> Linked List implementation
///and its operation like read, write and delete

#define MAX_SIZE 10
#define MIN_SIZE 3

///---IMPORTANT---
///my implementation of Linked list differs from what are explained in the
///lecture
///my implementation contain Node Struct and LinkedDataBase Struct

///the Node is the smallest unit in linked list
///it contains the data ,student model, and the pointer to next node

///LinkedDataBase is like an encapsulation for the entire database in one structure
///it has a pointer to the first node called 'Head'
///and has the usedSize which is number of nodes added to it,

///To explain my opinion more:-
///     if i have a 3 students in database
///     so i have 3 nodes, each node contain one student and a
///     pointer to the next student
///     But at all, I have only one variable from 'LinkedDataBase'
///     which has the pointer to the first node and the number of
///     students stored in database which is 3.


 typedef struct Node
{
    StudentModel data;
    struct Node* next;
} Node;

typedef struct LinkedDataBase
{
    Node* head;    ///must be initialized with NULL
    int usedSize;  ///must be initialized with 0

} LinkedDataBase;



///here the prototypes of database functions
///the definition are in 'stb.c' file

///initialize the database struct --> usedSize = 0, head =NULL
LinkedDataBase initializeDataBase();

///get the number of added nodes in the database struct
uint32 SDB_GetUsedSize(LinkedDataBase* db);

///check the database struct if full or not
boolean SDB_IsFull(LinkedDataBase* db);

///add new student to the database
boolean SDB_AddEntry(LinkedDataBase* db, StudentModel newStudent);

///check if the database contains a specific ID
boolean SDB_IsIdExist(LinkedDataBase* db,uint32 id);

///get an count and array of the IDS added to the database
void SDB_GetList(LinkedDataBase* db, uint8* count, uint32* list);

///get a student from database using a specific ID
boolean SDB_GetEntry(LinkedDataBase* db, uint32 id, StudentModel* outputStudent);

///remove a student from database using a specific ID
boolean SDB_DeletEntry(LinkedDataBase* db, uint32 id);
#endif // STB_H_INCLUDED
