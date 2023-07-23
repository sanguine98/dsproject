// ------------- Header file --------------

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WORD_SIZE 30
#define FNAME_SIZE 30
#define SIZE 27

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define LIST_NOT_EMPTY -3
#define DATA_FOUND -4
#define DATA_NOT_FOUND -5

typedef struct node
{
	struct mainnode *link;
}hash_t;

typedef struct file
{
	char filename[WORD_SIZE];
	struct file *link;
}filenames_t;


//----- Creation of main and sub nodes

typedef struct sub
{
	int word_count;
	char f_name[FNAME_SIZE];
	struct sub *link;
}subnode_t;

typedef struct mainnode
{
	int file_count;
	char word[WORD_SIZE];
	struct mainnode *link;
	struct sub *subnode_link;
}mainnode_t;


//---------- Function Prototypes ------------

int file_Slist(filenames_t **, int, char **array_of_pointes_of_argv);
void print_list(filenames_t *head);
int create_database( int argc, char **argv, hash_t *arr, int size );
void Display_Database( hash_t *arr, int size );
int Search_data( hash_t *arr, int size, char *data );
int Save_Database( hash_t *arr, int size );
int Update_Database( hash_t *arr, int size, char *backupfile );
#endif
