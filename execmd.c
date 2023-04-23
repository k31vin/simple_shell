#include "main.h"


	void execmd(char **argv){
	char *cmd = NULL;
	char *actual_command = NULL;

	
	if(argv){
		/* get de cmd */
		cmd = argv[0];
		
		actual_command = catch_lokeshon(cmd);

		/* execute de cmd withe execve **/
		if(execve(actual_command, argv, NULL) == -1){
			perror("error occured:__");
		};
	}



	}

