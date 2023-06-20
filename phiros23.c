#include "phiros.h"
/**
 * crosed - changes cd
 ** @dsh: data
 ** Return: 1 on success
 ****************************/
int crosed(phiros_shell *dsh)
{
char *d;
int a, b, c;

d = dsh->ag[1];

if (d != NULL)
{
a = _roscmp("$HOME", d);
b = _roscmp("~", d);
c = _roscmp("--", d);
}

if (d == NULL || !a || !b || !c)
{
rome(dsh);
return (1);
}

if (_roscmp("-", d) == 0)
{
phivious(dsh);
return (1);
}

if (_roscmp(".", d) == 0 || _roscmp("..", d) == 0)
{
phidot(dsh);
return (1);
}

roto(dsh);

return (1);
}
