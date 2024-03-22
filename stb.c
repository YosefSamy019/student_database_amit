#include <stdlib.h>
#include "student.h"

#include "stb.h"

///this file contain the definition of 'stb.h' file

///initialize the database struct --> usedSize = 0, head = NULL
///and return an instance from the struct
LinkedDataBase initializeDataBase()
{
    LinkedDataBase instance = {NULL,0};
    return instance;
}


///this function takes the database as a parameter
///and return the number of nodes added to the database
uint32 SDB_GetUsedSize(LinkedDataBase* db)
{
    return db->usedSize;
}

///this function takes the database as a parameter
/// and check if the database full or not
boolean SDB_IsFull(LinkedDataBase* db)
{
    ///MAX_SIZE is a Macro defined in 'stb.h' file
    return db->usedSize >= MAX_SIZE;
}

///this function takes the database as a parameter and the new student data
///then insert the student to the database at the end,
///return true if the student is added successfully, otherwise return false
boolean SDB_AddEntry(LinkedDataBase* db, StudentModel newStudent)
{
    //The variable whose value is the return of the function
    boolean output = true;
    //newNode is a pointer to the new student
    //temp is the iterator pointer used in while loop
    Node *newNode,*temp;

    //initialize the newNode pointer
    newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newStudent;
    newNode->next = NULL;

    //student insertion fail if the malloc returned null or if the database is full
    if (newNode == NULL || db->usedSize >= MAX_SIZE)
    {
        output = false;
    }
    //check if the ID is already exits in the data
    //the ID can not be added twice to the database
    else if ( SDB_IsIdExist(db,newStudent.StudentID) == true)
    {
        output = false;
    }
    //check if the database was completely empty(header = NULL),
    else if ( db->head ==NULL)
    {
        db->head = newNode;
        db->usedSize++; //increase the used size of database by one
    }
    else
    {
        //temp is the iterator pointer used in while loop
        //which goes through the database nodes until reach the last node
        //when reach there, the student will be added successfully
        temp = db->head ;
        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next = newNode;
        db->usedSize++; //increase the used size of database by one
    }


    return output;
}

///this function takes the database as a parameter and the ID
///to check if the ID exists or not
///return true if the ID exists, otherwise return false
boolean SDB_IsIdExist(LinkedDataBase* db,uint32 id)
{
    //The variable whose value is the return of the function
    boolean output = false;
    //iterator pointer which goes through the database
    Node* iterator = db->head;


    while(iterator!=NULL)
    {
        //check the current iterator equals the id or not
        if(iterator->data.StudentID == id)
        {
            output = true;
            break;
        }
        iterator = iterator->next;
    }
    return output;
}

///this function takes the database as a parameter
///And take (*count) a pointer of integer which equal the number of students added to database
///And take (*list) a pointer of array which store the IDs list
///this function store the count of the database to count pointer
///and store the IDs list found in the database to list pointer
void SDB_GetList(LinkedDataBase* db, uint8* count, uint32* list)
{
    //iterator pointer which goes through the database
    Node* iterator = db->head;
    *count = 0;//initially count is Zero

    while(iterator!=NULL)
    {
        //store the id in the list pointer
        list[*count] = iterator->data.StudentID;
        //increase the count by 1
        *count = *count+1;
        iterator = iterator->next;
    }
}

///this function takes the database as a parameter
///And take the id that will be searched about
///And take (*StudentModel) a pointer of student which store student data
///if the ID is found in the database, the function will return true
///and also will pass the student to outputStudent pointer
///But if the ID is not found, the function returns false
boolean SDB_GetEntry(LinkedDataBase* db, uint32 id, StudentModel* outputStudent)
{
    //The variable whose value is the return of the function
    boolean output = false;

    //iterator pointer which goes through the database
    Node* iterator = db->head;

    while(iterator!=NULL)
    {
        //check if the student, with specific id, found or not
        if(iterator->data.StudentID == id)
        {
            output = true;
            //pass the student to the '*outputStudent' parameter
            *outputStudent = iterator->data;
            break;
        }
        iterator = iterator->next;
    }
    return output;
}


///this function takes the database as a parameter
///And take the id that will be removed from the database
///if the ID is found in the database, the function will
///remove the student data and return true
///But if the ID is not found, the function returns false
boolean SDB_DeletEntry(LinkedDataBase* db, uint32 id)
{
    //The variable whose value is the return of the function
    boolean output = false;
    //temp is a pointer which hold the student which will be free from the memory
    Node* temp;
    //iterator and previous, both are pointers to goes through the database
    Node *iterator,*previous;

    //first check if the database is not empty
    if(db->usedSize >0 )
    {
        //check if the first student in database is the student wanted to be removed
        if(db->head->data.StudentID == id)
        {
            //hold the student before free him
            temp = db->head ;
            //change the head of the database
            db->head = db->head->next;
            //free the student
            free(temp);
            //decrease the size of database by 1
            db->usedSize--;
            output  = true;

        }
        else
        {
            //iterator and previous, both are pointers to goes through the database
            previous = db->head;
            iterator = db->head->next;

            //loop through the database until find the id or reach the end of database
            while(iterator != NULL && iterator->data.StudentID != id)
            {
                previous = iterator;
                iterator = iterator->next;
            }
            //if iterator reached the end of the database
            //this means the ID is not found
            if(iterator ==NULL)
            {
                //nothing here
            }
            else
            {
                //if iterator != NULL, this means the id is found

                //change the next of the node
                previous->next = iterator->next;
                //free the student from the memory
                free(iterator);
                //decrease the size by 1
                db->usedSize--;
                output  = true;
            }

        }
    }
    return output;
}

