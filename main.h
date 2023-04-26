#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


/**
 * execmd - executes a command by creating a child process
 * @argv: array of command line arguments
 */
void execmd(char **argv);

/**
 * catch_lokeshon - returns the user's current location
 * @cmd: the command entered by the user
 *
 * Return: string containing the user's current location
 */
char *catch_lokeshon(char *cmd);
