#include "main.h"

void Display_Database( hash_t *arr, int size )
{
	int i;
	mainnode_t *main_temp;
	subnode_t *sub_temp;

	printf("[Index No]\t[Word]\t[File_count]\t[File_name]\t[Word_count]\n");
	for ( i = 0; i < size; i++ )
	{
		if ( arr[i].link != NULL )
		{
			main_temp = arr[i].link;

			while ( main_temp != NULL )
			{
				printf("%d\t\t%s\t%d\t\t", i, main_temp -> word, main_temp -> file_count);

				sub_temp = main_temp -> subnode_link;
				while ( sub_temp != NULL )
				{
					printf("%s\t%d\n", sub_temp -> f_name, sub_temp -> word_count);
					sub_temp = sub_temp -> link;
					printf(" \t \t \t \t \t");
				}
				printf("\n");
				main_temp = main_temp -> link;
			}

		}
	}
}
