#include "phiros.h"
/**
 * roxit - Help info for exit
 ** Return: no return
 *****************************/
void roxit(void)
{
char *h = "exit: exit [n]\n Exit shell.\n";

write(STDOUT_FILENO, h, _rozy(h));
h = "Exits shell with status of N. If N is ommited, the exit";
write(STDOUT_FILENO, h, _rozy(h));
h = "status is the last command executed\n";
write(STDOUT_FILENO, h, _rozy(h));
}
/**
 * rosenv - Help info for env
 ** Return: no return
 *************************************/
void rosenv(void)
{
char *h = "env: env [option] [name=value] [command [ag]]\n\t";

write(STDOUT_FILENO, h, _rozy(h));
h = "Print envir of shell.\n";
write(STDOUT_FILENO, h, _rozy(h));
}
/**
 * rosuntenv - Help info for unsetenv
 ** Return: no return
 *************************************/
void rosuntenv(void)
{
char *h = "unsetenv: unsetenv (const char *name)\n\t";

write(STDOUT_FILENO, h, _rozy(h));
h = "Remove entry from envi\n";
write(STDOUT_FILENO, h, _rozy(h));
}
/**
 * rosgen - Entry point for help inf for help
 * Return: no return
 */
void rosgen(void)
{
char *h = "^-^ bash, version 1.0(1)-release\n";

write(STDOUT_FILENO, h, _rozy(h));
h = "These commands are defined internally.Type 'help' to see the list";
write(STDOUT_FILENO, h, _rozy(h));
h = "Type 'help name' to find out more about the function 'name'.\n\n ";
write(STDOUT_FILENO, h, _rozy(h));
h = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
write(STDOUT_FILENO, h, _rozy(h));
h = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
write(STDOUT_FILENO, h, _rozy(h));
h = "[ag]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
write(STDOUT_FILENO, h, _rozy(h));
h = "unsetenv [variable]\n";
write(STDOUT_FILENO, h, _rozy(h));
}
/**
 * rostenv - Help info for setenv
 ** Return: no return
 *******************************************/
void rostenv(void)
{
char *h = "setenv: setenv (const char *name, const char *value,";

write(STDOUT_FILENO, h, _rozy(h));
h = "int replace)\n\t";
write(STDOUT_FILENO, h, _rozy(h));
h = "Add new definition t envi\n";
write(STDOUT_FILENO, h, _rozy(h));
}
