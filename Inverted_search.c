/* Documentation
Name: Manoj BK
Date: 14/1/2023
Description: Inverted Search for storing file content in database
Sample I/P: 
Sample O/P:
*/

#include "main.h"

int create_hashtable( hash_t *arr, int size)
{
	for ( int i=0; i < size; i++ )
	{
		arr[i].link = NULL;
	}
}

int main( int argc, char *argv[] )
{
	int res, choice, size;
	size = SIZE;
	char ch = 'y';
	char data[] = {}, backupfile[20];

	// Declaring array of structures of type hash_t which forms hash table
	hash_t arr[SIZE];
	// calling create hashtable function to create hash table
	create_hashtable( arr, size );
	// initializing header to NULL 
	filenames_t *head = NULL;

	// Condition checking for CLA are passed or not
	if ( argc > 1 )
	{
		printf("File(s) is(are) passed through CLA\n");
		if (res = file_Slist(&head, argc, argv) == SUCCESS)
		{
			printf("SUCCESSFULL : inserting file name(s) : ");
			print_list(head);
			printf(" into file linked list\n");
		}
		else
			printf("files storing into slist failed\n");

		while ( ch == 'y' || ch == 'Y' )
		{
			printf("\n1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Databse\n6. Print filenames\n");
			printf("\nSelect your choice among following options : ");
			scanf("%d", &choice);

			switch(choice)
			{
				case 1:
					if ( res = create_database( argc, argv, arr, size) == SUCCESS )
					{
						printf("Successful : Creation of Database of file: ");
						print_list(head);
						printf("\n");
					}
					else
						printf("FAILURE : Creation of Database\n");
					break;
				case 2:
					Display_Database(arr,size);
					break;
				case 3:
					printf("Read the word to be searched in Database : ");
					scanf("%s", data);
					if ( Search_data(arr,size,data) == FAILURE )
						printf("The word %s is not present in the Database\n", data);
					break;
				case 4:
					if ( Save_Database(arr,size) == SUCCESS )
						printf("Database is SUCCESSFULLY saved to backup file\n");
					else
						printf("Database is not saved to backup file\n");
					break;
				case 5:
					printf("Enter the backupfile name : ");
					scanf("%s", backupfile);
					if ( res = Update_Database( arr, size, backupfile) == SUCCESS )
						printf("SUCCESSFULL : Database updated with backup file %s\n", backupfile );
					else
						printf("FAILURE : Backup file %s not updated\n", backupfile);
					break;
				case 6:
					print_list(head);
					printf("\n");
					break;
				default :
					printf("Invalid choice, Please enter proper choice\n");
			}

			printf("\nDo you want to continue ?\nEnter y/Y to continue or n/N to discontinue\n");
			scanf(" %c", &ch);	
		}
		return SUCCESS;
	}
	else
	{
		printf("No files are passed through CLA\nUSAGE : Please pass the CLA as ./a.out file1.txt file2.txt etc\n");
	}
return SUCCESS;
}
