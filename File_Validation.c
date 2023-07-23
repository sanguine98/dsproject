// ------------------------------- File Validation part -------------------

#include "main.h"

int file_Slist( filenames_t **head, int argc, char **argv)
{

	int i, j, flag;
	FILE *fptr;
	char ch;

	// declaring two struct node pointers
	filenames_t *new, *prev;

	// Data insertion to the newly created node
	for ( i = 1; i < argc; i++ )
	{
		flag = 0;
		//--------------------------------- Duplicate File checking in CLA -----------------
		// loop for checking duplicate filename exists or not if yes return to main function as failure and stop the process
		for ( j = i; j < argc - 1; j++ )
		{
			if ( strcmp(argv[i],argv[j+1]) == 0 )
			{
				printf("printing error since duplicate filenames are entered.\n");
				flag = 1;
				break;
			}
		}
		if ( flag == 1 )
			continue;
		//----------------------------------- Empty File Checking in CLA files --------------------------------------------
		// Block for checking file is empty or not if yes returns to main fun as failure and stops the process
		// opening file and reading
		fptr = fopen( argv[i] ,"r");
		// Error checking on fopen() 
		if (fptr == NULL)
		{
			printf("File is not present\n");
			return FAILURE;
		}
		// while loop to move the cursor to EOF
		while ((ch = fgetc(fptr)) != EOF)
		{
		}
		// condition to check if the cursor is at EOF and value is 0 implies file is empty return to main fun as failure and stop process
		if ( ftell(fptr) == 0 )
		{
			printf("file %s is empty\n", argv[i]);
			continue;
		}
		//----------------------------------------------------Storing CLA i.e, files in Slist---------------------

		// creation of node using dynamic memory allocation
		new = malloc(sizeof(filenames_t));

		// Validation for successful creatiion of node or not
		if (new == NULL)
		{
			return FAILURE;
		}
		// copying CLA file names to new node filename section
		strcpy((new -> filename),argv[i]);

		// condition for link establishment for first node creation with head
		if( *head == NULL )
		{
			*head = new;
			prev = *head;
			prev -> link = NULL;
		}
		// else part for link establishment from 2nd node onwards
		else
		{
			prev -> link = new;
			prev = new;
			new -> link = NULL;
		}
	}
	return SUCCESS;
}
