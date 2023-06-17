#include "phiros.h"
/**
 * roselpx - Help information for the builtin alias.
 * Return: no return
 ****************************************************/
void roselpx(void)
{
	char *h = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, h, _rozy(h));
	h = "\tChange shell working directory.\n ";
	write(STDOUT_FILENO, h, _rozy(h));
}
/**
 * roselp - Help information for builtin help.
 ** Return: no return
 ***********************************************/
void roselp(void)
{
	char *h = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, h, _rozy(h));
	h = "\tDisplay info about builtin commands.\n ";
	write(STDOUT_FILENO, h, _rozy(h));
	h = "Display summaries of builtin commands.\n";
	write(STDOUT_FILENO, h, _rozy(h));
}
/**
 * roselps - Help information for the builtin alias.
 * Return: no return
 ****************************************************/
void roselps(void)
{
	char *h = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, h, _rozy(h));
	h = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, h, _rozy(h));
}
