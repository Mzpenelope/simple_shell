#include "phiros.h"
/**
 * rphill - exits shell
 ** @dsh: data 
 ** Return: 0 on success.
 *************************/
int rphill(phiros_shell *dsh)
{
unsigned int a;
int t;
int n;
int r;

if (dsh->ag[1] != NULL)
{
a = _rosina(dsh->ag[1]);
t = philgit(dsh->ag[1]);
n = _rozy(dsh->ag[1]);
r = a > (unsigned int)INT_MAX;
if (!t || n > 10 || r)
{
phirror(dsh, 2);
dsh->status = 2;
return (1);
}
dsh->status = (a % 256);
}
return (0);
}
/**
 * roxec - finds builtins and commands
 ** @dsh: data
 ** Return: 1 on success.
 ***************************************/
int roxec(phiros_shell *dsh)
{
int (*b)(phiros_shell *dsh);

if (dsh->ag[0] == NULL)
return (1);

b = rosintine(dsh->ag[0]);

if (b != NULL)
return (phrotin(dsh));

return (phexec(dsh));
}
