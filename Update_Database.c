#include "main.h"

int Update_Database( hash_t *arr, int size, char *backupfile )
{
	char ch, word[WORD_SIZE];
	FILE *fptr;
	//----------------------------------- Empty File Checking in CLA files --------------------------------------------
	// checking file is empty or not if yes returns to main fun as failure and stops the process
	// opening file and reading
	fptr = fopen( backupfile ,"r");
	// Error checking on fopen()
	if (fptr == NULL)
	{
		printf("File is not present\n");
		//	return FAILURE;
	}
	// while loop to move the cursor to EOF
	while ((ch = fgetc(fptr)) != EOF)
	{
	}
	// condition to check if the cursor is at EOF and value is 0 implies file is empty return to main fun as failure and stop process
	if ( ftell(fptr) == 0 )
	{
		printf("Backupfile %s is empty\n", backupfile);
		//return FAILURE;
	}
	/*

	   fseek(fp,0,SEEK_END);
	   if ( ftell(fp) == 0 )
	   return FAILURE;

	   rewind(fp);
	   */
	//------------------------------------------------------------------
	fptr = fopen( backupfile, "r" );
	// Error checking on fopen()
	if (fptr == NULL)
	{
		printf("File is not present\n");
		return FAILURE;
	}
	fseek(fptr,54,SEEK_SET);
	//------------------------------------------------------------------

	static char *token;
	int value = fscanf(fptr,"%s",word);
	int index,node = 0;
	while ( value )
	{
		if ( value == EOF )
			break;
		printf("1\n");
		if( word[0] == '#' )
		{
			node = 0;
			token = strtok(word,"#:");
			printf("%s\n",token);
			index = atoi(token);
			printf("index = %d\n",index);
			token = strtok(NULL,"\t");
		}
		else
		{
			mainnode_t *new = malloc(sizeof(mainnode_t));
			mainnode_t *temp;
			subnode_t *temp1;
			token = strtok(word,"\t");
			printf("word = %s\n",token);
			strcpy( (new -> word), token );
			token = strtok(NULL,"\t");
			int count = atoi(token);
			printf("filecount = %d\n",count);
			new -> file_count = count;
			int sub = 0;



			for ( int i = 0 ; i < count; i++ )
			{
				printf("3\n");
				token = strtok(NULL,"\t");
				subnode_t *new1 = malloc(sizeof(subnode_t));
				printf("filename = %s\n",token);
				strcpy(new1 -> f_name, token);
				token = strtok(NULL,"\t ");
				int count = atoi(token);
				printf("wordcount = %d\n",count);
				new1->word_count = count;
				new1->link = NULL;
				if ( sub == 0 )
				{
					new -> subnode_link = new1;
					//temp1 = new1;
					sub++;
				}
				else
				{
					temp1->link = new1;
					temp1 = new1;
				}
			}

			if ( token != NULL )
				token = strtok(NULL,"\t");
			if ( node == 0 )
			{
				arr[index].link = new;
				node++;
			}
			else
				temp -> link = new;
			new -> link = NULL;
			temp = new;
			printf("\n");
			token = strtok(NULL,"\t");
		}
		if ( token == NULL )
			value = fscanf(fptr,"%s",word);

	}
return SUCCESS;
}
