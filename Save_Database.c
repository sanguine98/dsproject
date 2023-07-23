#include "main.h"

int Save_Database( hash_t *arr, int size)
{
	char ch[20] = {};
	printf("Enter the filename to which the Database is to be stored : ");
	scanf("%s", ch);
	int i;
	FILE *fptr;
	mainnode_t *main_temp;
	subnode_t *sub_temp;

	fptr = fopen(ch,"w");
	if ( fptr == NULL )
	{
		printf("backup file %s is not opened in write mode\n", ch);
		return FAILURE;
	}

	fprintf( fptr,"#[Index]\t[Word]\t[File_count]\t[File_name]\t[word_count]#\n");
	for ( i = 0; i < size; i++ )
	{
		if ( arr[i].link != NULL )
		{
			main_temp = arr[i].link;

			while ( main_temp != NULL )
			{
				fprintf(fptr,"#:%d\t\t%s\t%d\t\t", i, main_temp -> word, main_temp -> file_count);

				sub_temp = main_temp -> subnode_link;
				while ( sub_temp != NULL )
				{
					fprintf(fptr,"%s\t%d\n", sub_temp -> f_name, sub_temp -> word_count);
					sub_temp = sub_temp -> link;
					fprintf(fptr," \t \t \t \t \t");
				}
				fprintf(fptr,"\t \t#\n");
				main_temp = main_temp -> link;
			}

		}
	}
	fclose(fptr);
	return SUCCESS;
}
