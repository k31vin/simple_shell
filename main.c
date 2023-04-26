#include "main.h"
/**
 * main - simple shell program entry point
 * Description: simple shell program written in C
 * for UNIX based systems. Program written by
 * Antony Muga and Nicholas Oyengo
 * Return:Status code 0 if successful
 */
int main(int ac, char **argv)
{
	char *prompt = "(Terminal) $ ";
	char *user_input = NULL;      /*holds user input*/
	char *user_input_copy = NULL; /* holds copy of the string to be          tokenized */
	char *tkn;
	int i = 0;
    	int tkn_num = 0;
    	size_t n = 0;
    	ssize_t rd_chars;
	const char *delimita = " \n";
	
    	/* declaring void variables */
    	(void)ac;
	;		
	
    	/* create an infinite loop */
    	while (1)
    	{
        	printf("%s", prompt);
        	rd_chars = getline(&user_input, &n, stdin);

        /* checks getline functionality i.e whether it reached eof or           used keyboard hot keys ctrl + D*/
        if (rd_chars == -1)
        {
            printf("Quiting Terminal______________\n");
            return (-1);
        }

        /* memory allocation for the user_input_copy */
        user_input_copy = malloc(sizeof(char) * rd_chars);
        if (user_input_copy == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }

        /* copy user_input to user_input_copy */
        strcpy(user_input_copy, user_input);

        /*split the user_input into an array of words
         * and calculate the number of tokens  */
        tkn = strtok(user_input, delimita);

        while (tkn != NULL)
        {
            tkn_num++;
            tkn = strtok(NULL, delimita);
        }
        tkn_num++;

        /* allocate memory to hold the array of strings */
        argv = malloc(sizeof(char *) * tkn_num);

        /* store each of the tkns in the argv array */
        tkn = strtok(user_input_copy, delimita);

        for (i = 0; tkn != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(tkn));
            strcpy(argv[i], tkn);

            tkn = strtok(NULL, delimita);
        }
        argv[i] = NULL;


	/* cmd execution */
	execmd(argv);
    }
		
        /* frees up memory*/
	if (user_input_copy != NULL){
		free(user_input_copy);
	}
	if (user_input != NULL)
        {
            free(user_input);
        }
	    
    return (0);
}
