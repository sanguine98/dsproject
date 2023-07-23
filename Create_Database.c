#include "main.h"

int create_database( int argc, char **argv, hash_t *arr, int size )
{
	int i, j, index, flag;
	char ch, word[WORD_SIZE];
	FILE *fptr;

	mainnode_t *main_temp, *main_new, *main_prev;
	subnode_t *sub_temp, *sub_new, *sub_prev;

	for ( i = 1; i < argc; i++ )
	{
		//---------------------------------------------------------------------------------
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
		//--------------------------------------------------------------------------------
		fptr = fopen( argv[i], "r" );
		// Error checking on fopen()
		if (fptr == NULL)
		{
			printf("File is not present\n");
			return FAILURE;
		}
		while (!feof(fptr))	
		{ 
			fscanf( fptr, "%s", word );
			if ( (word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z') )
			{
				ch = toupper(word[0]);
				index = ch % 65;
			}
			else
			{
				ch = word[0];
				index = ch % 65;
			}

			if ( index >= 0 && index <= 25 )
			{

				//------------------------------------creating database---------------------------------------------------//

				if ( arr[index].link == NULL )
				{
					//Create main node
					//mainnode_t *main_temp, *main_new;
					main_new = malloc(sizeof(mainnode_t));

					// validation for new hash structure is created successfully or not
					if ( main_new == NULL )
					{
						return FAILURE;
					}

					//subnode_t *sub_temp, *sub_new;
					sub_new = malloc(sizeof(subnode_t));

					// validation for new hash structure is created successfully or not
					if ( sub_new == NULL )
					{
						return FAILURE;
					}

					arr[index].link = main_new;

					// Assigning values to members of mainnode_t structure pointer
					main_new -> file_count = 1;
					strcpy((main_new -> word), word);
					main_new -> link = NULL;
					main_new -> subnode_link = sub_new;

					// Assigning values to members of subnode_t structure pointer
					sub_new -> word_count = 1;
					strcpy((sub_new -> f_name), argv[i]);
					sub_new -> link = NULL;


					// printf condition to check for myself
					//printf("%d %s %p %p\n", main_new -> file_count, main_new -> word, main_new -> link, main_new ->subnode_link);
					//printf("%d %s %p \n", sub_new -> word_count, sub_new -> f_name, sub_new -> link);

				}
				// if the hash table has a link already with a word checking if it is same word or not
				else
				{
					main_temp = arr[index].link;

					while ( main_temp != NULL )
					{
						// if the word is present it will return 0 so not of 0 is 1 it continues inside and checks file name
						if ( strcmp(main_temp -> word,word) == 0 )
						{
							// checking the file name in sub nodes
							sub_temp = main_temp -> subnode_link;

							while ( sub_temp != NULL )
							{
								if ( strcmp(sub_temp -> f_name,argv[i]) == 0 )
								{
									(sub_temp -> word_count)++;
									// printf condition to check for myself
									//printf("%d \n", sub_temp -> word_count);
									break;
								}
								sub_prev = sub_temp;
								sub_temp = sub_temp -> link;
							}

							if ( sub_temp == NULL )
							{
								// if the file is not present create a subnode and update with file name and word count
								//subnode_t *sub_temp, *sub_new;
								sub_new = malloc(sizeof(subnode_t));

								// validation for new hash structure is created successfully or not
								if ( sub_new == NULL )
								{
									return FAILURE;
								}

								// Assigning values to members of subnode_t structure pointer
								sub_new -> word_count = 1;
								strcpy((sub_new -> f_name), argv[i]);
								sub_new -> link = NULL;
								// linking newley created sub node to last subnode already present
								sub_prev -> link = sub_new;
								(main_temp -> file_count)++;

								// printf condition to check for myself
								//printf("%d %d %s %p \n", sub_new -> word_count, main_temp -> file_count, sub_new -> f_name, sub_new -> link);
								break;

							}
						}
						if ( strcmp(main_temp -> word,word) != 0 )
						{
							main_prev = main_temp;
							main_temp = main_temp -> link;
						}
						else
							break;
					}

					if ( main_temp == NULL )
					{
						// repeate create main node and sub node
						main_new = malloc(sizeof(mainnode_t));

						// validation for new hash structure is created successfully or not
						if ( main_new == NULL )
						{
							return FAILURE;
						}

						//subnode_t *sub_temp, *sub_new;
						sub_new = malloc(sizeof(subnode_t));

						// validation for new hash structure is created successfully or not
						if ( sub_new == NULL )
						{
							return FAILURE;
						}
						// Assigning values to members of mainnode_t structure pointer
						main_new -> file_count = 1;
						strcpy((main_new -> word), word);
						main_new -> link = NULL;
						main_new -> subnode_link = sub_new;

						// Assigning values to members of subnode_t structure pointer
						sub_new -> word_count = 1;
						strcpy((sub_new -> f_name), argv[i]);
						sub_new -> link = NULL;

						// linking newly created main_node to last main_node link
						main_prev -> link = main_new;
						// printf condition to check for myself
						//printf("%d %s %p %p\n", main_new -> file_count, main_new -> word, main_new -> link, main_new ->subnode_link);
						//printf("%d %s %p \n", sub_new -> word_count, sub_new -> f_name, sub_new -> link);

					}
				}

			}
			//--------------------- else part for 26th index repeat all the above steps
			else
			{
				//------------------------------------creating database---------------------------------------------------//
				if ( arr[26].link == NULL )
				{
					//Create main node
					main_new = malloc(sizeof(mainnode_t));
					// validation for new hash structure is created successfully or not
					if ( main_new == NULL )
					{
						return FAILURE;
					}
					//subnode_t *sub_temp, *sub_new;
					sub_new = malloc(sizeof(subnode_t));
					// validation for new hash structure is created successfully or not
					if ( sub_new == NULL )
					{
						return FAILURE;
					}
					arr[26].link = main_new;

					// Assigning values to members of mainnode_t structure pointer
					main_new -> file_count = 1;
					strcpy((main_new -> word), word);
					main_new -> link = NULL;
					main_new -> subnode_link = sub_new;

					// Assigning values to members of subnode_t structure pointer
					sub_new -> word_count = 1;
					strcpy((sub_new -> f_name), argv[i]);
					sub_new -> link = NULL;

				}
				// if the hash table has a link already with a word checking if it is same word or not
				else
				{
					main_temp = arr[26].link;

					while ( main_temp != NULL )
					{
						// if the word is present it will return 0 so not of 0 is 1 it continues inside and checks file name
						if ( strcmp(main_temp -> word,word) == 0 )
						{
							// checking the file name in sub nodes
							sub_temp = main_temp -> subnode_link;

							while ( sub_temp != NULL )
							{
								if ( strcmp(sub_temp -> f_name,argv[i]) == 0 )
								{
									(sub_temp -> word_count)++;
									// printf condition to check for myself
									//printf("%d \n", sub_temp -> word_count);
									break;
								}
								sub_prev = sub_temp;
								sub_temp = sub_temp -> link;
							}

							if ( sub_temp == NULL )
							{
								// if the file is not present create a subnode and update with file name and word count
								//subnode_t *sub_temp, *sub_new;
								sub_new = malloc(sizeof(subnode_t));

								// validation for new hash structure is created successfully or not
								if ( sub_new == NULL )
								{
									return FAILURE;
								}

								// Assigning values to members of subnode_t structure pointer
								sub_new -> word_count = 1;
								strcpy((sub_new -> f_name), argv[i]);
								sub_new -> link = NULL;
								// linking newley created sub node to last subnode already present
								sub_prev -> link = sub_new;
								(main_temp -> file_count)++;
								break;
							}
						}
						if ( strcmp(main_temp -> word,word) != 0 )
						{
							main_prev = main_temp;
							main_temp = main_temp -> link;
						}
						else
							break;
					}

					if ( main_temp == NULL )
					{
						// repeate create main node and sub node
						main_new = malloc(sizeof(mainnode_t));

						// validation for new hash structure is created successfully or not
						if ( main_new == NULL )
						{
							return FAILURE;
						}

						//subnode_t *sub_temp, *sub_new;
						sub_new = malloc(sizeof(subnode_t));

						// validation for new hash structure is created successfully or not
						if ( sub_new == NULL )
						{
							return FAILURE;
						}
						// Assigning values to members of mainnode_t structure pointer
						main_new -> file_count = 1;
						strcpy((main_new -> word), word);
						main_new -> link = NULL;
						main_new -> subnode_link = sub_new;

						// Assigning values to members of subnode_t structure pointer
						sub_new -> word_count = 1;
						strcpy((sub_new -> f_name), argv[i]);
						sub_new -> link = NULL;

						// linking newly created main_node to last main_node link
						main_prev -> link = main_new;
					}
				}
			}
			//---------------------------------------------------------------------------------------//
		} // while fptr brackt
		fclose(fptr);
	} // for argc bracket

	return SUCCESS;
}
