#include "main.h"

void print_list(filenames_t *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> filename);
		    head = head -> link;
	    }
	    //printf("Finished\n");
    }
}
