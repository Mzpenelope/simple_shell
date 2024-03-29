#include "phiros.h"

/**
 * a_help - Help info for builtin help.
 * Return: no return
 */
void a_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, pr_strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, pr_strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, pr_strlen(help));
}
/**
 * a_help_alias - Help info for builtin alias.
 * Return: no return
 */
void a_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, pr_strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, pr_strlen(help));
}
/**
 * a_help_cd - Help info for builtin alias.
 * Return: no return
 */
void a_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, pr_strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, pr_strlen(help));
}
