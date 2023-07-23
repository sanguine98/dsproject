#include "main.h"

int Search_data( hash_t *arr, int size, char *data )
{
	int i;
	char ch;
	ch = toupper(data[0]);
	i = ch % 65;

	mainnode_t *main_temp;
	subnode_t *sub_temp;

	if ( arr[i].link != NULL )
	{
		main_temp = arr[i].link;
		while ( main_temp != NULL )
		{
			if ( strcmp(main_temp -> word,data) == 0 )
			{
				printf("word %s is found at the Database and it is present in %d files\n", data, main_temp -> file_count);
				sub_temp = main_temp -> subnode_link;
				while ( sub_temp != NULL )
				{
					printf("In file %s %d time(s)\n", sub_temp -> f_name, sub_temp -> word_count);
					sub_temp = sub_temp -> link;
					if ( sub_temp == NULL)
						return SUCCESS;
				}
			}
			main_temp = main_temp -> link;
		}
		if ( main_temp == NULL )
			return FAILURE;
		else
			return SUCCESS;
	}
	return FAILURE;
}
