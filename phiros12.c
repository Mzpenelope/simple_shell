#include "phiros.h"
/**
 * phiroselp - get help messages according builtin
 ** @dsh: data struct
 ** Return: Return 0
 *************************************************/
int phiroselp(phiros_shell *dsh)
{

if (dsh->ag[1] == 0)
rosgen();
else if (_roscmp(dsh->ag[1], "setenv") == 0)
rostenv();
else if (_roscmp(dsh->ag[1], "env") == 0)
rosenv();
else if (_roscmp(dsh->ag[1], "unsetenv") == 0)
rosuntenv();
else if (_roscmp(dsh->ag[1], "help") == 0)
roselp();
else if (_roscmp(dsh->ag[1], "exit") == 0)
roxit();
else if (_roscmp(dsh->ag[1], "cd") == 0)
roselpx();
else if (_roscmp(dsh->ag[1], "alias") == 0)
roselps();
else
write(STDERR_FILENO, dsh->ag[0],
_rozy(dsh->ag[0]));

dsh->status = 0;
return (1);
}
/**
 * phirror - calls error
 ** @dsh: data struct
 ** @ev: error value
 ** Return: error
 ***************************/
int phirror(phiros_shell *dsh, int ev)
{
char *e;

switch (ev)
{
case -1:
e = phillevn(dsh);
break;
case 126:
e = phillpath(dsh);
break;
case 127:
e = phillif(dsh);
break;
case 2:
if (_roscmp("exit", dsh->ag[0]) == 0)
e = rosexitz(dsh);
else if (_roscmp("cd", dsh->ag[0]) == 0)
e = rosegetz(dsh);
break;
}

if (e)
{
write(STDERR_FILENO, e, _rozy(e));
free(e);
}

dsh->status = ev;
return (ev);
}
/**
 * rosintine - builtin
 * @c: command
 * Return: function pointer of builtin command
 ***********************************************/
int (*rosintine(char *c))(phiros_shell *)
{
b_t b[] = {
{ "env", phnv },
{ "exit", phit },
{ "setenv", phenv },
{ "unsetenv", phunv },
{ "cd", phcd },
{ "help", phlp },
{ NULL, NULL }
};
int u;

for (u = 0; b[u].n; u++)
{
if (_roscmp(b[u].n, c) == 0)
break;
}

return (b[u].p);
}
