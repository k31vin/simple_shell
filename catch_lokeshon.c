#include "main.h"

	char *catch_lokeshen(char *cmd){
		char *njia, *njia_mfano;
		int cmd_urefu;
		char *pth_tkn;
		int dir_lngth;
		char *fail_pth;
		struct stat buffer;

		njia = getenv("PATH");

		if(njia){
			/* fanya copi ziwe mbili */
			njia_mfano = strdup(njia);
			/* pata urefu wa cmd iliyowekwa */
			cmd_urefu = strlen(cmd);

			/* katanisha njia ya vigezo ili upate
			 * saraka zinazopatikana */
			pth_tkn = strtok(njia_mfano, ":");
			

			while(pth_tkn != NULL){
				/* pata urefu wa saraka */
				dir_lngth = strlen(pth_tkn);
				/* tenga nafasi ya kueka majina ya cmd
				 *  pamoja */
				fail_pth = malloc(cmd_urefu + dir_lngth + 2 );
				/* jenga njia ya cmd */
				strcpy(fail_pth, pth_tkn);
				strcat(fail_pth, "/");
				strcat(fail_pth, cmd);
				strcat(fail_pth, "\0");

				/* angalia kama faili inaexist */
				if (stat(fail_pth, &buffer) == 0){
					/* rudisha nunge kumaanisha njia ni halali */
					/* free memory space b4 retuning de fail pth */
					free(njia_mfano);

					return(fail_pth);
				}
				else{
					/* free de mmory file path to check other paths */
					free(njia_mfano);
					pth_tkn = strtok(NULL, ":");
				}
			}

			/* kama njia inayofaa haijapatikana achilia huru memory */
			free(njia_mfano);

			/*kabla kutoweka bila mafanikio, acha tuone kama cmd ni njia inayo patikana */
			if(stat(cmd, &buffer) == 0 )
			{
				return(cmd);
			}
			return(NULL);
		}
		return (NULL);
	
		}
