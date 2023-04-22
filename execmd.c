#include "main.h"


	void execmd(char **argv){
	char *cmd = NULL;
	
	if(argv){
		/* get de cmd */
		cmd = argv[0];

		/* execute de cmd withe execve **/
		if(execve(cmd, argv, NULL) == -1){
			perror("error occured.......");
		};
	}



	}

