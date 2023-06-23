#include "phiros.h"
/**
 * rophiline - reads the input string.
 ** @u: return value of getline function
 ** Return: input string
 ******************************************/
char *rophiline(int *u)
{
char *enter = NULL;
size_t bufsize = 0;

*u = getline(&enter, &bufsize, stdin);

return (enter);
}
/**
 * roment - deletes comments from input
 ** @h: input string
 ** Return: input without comments
 ****************************************/
char *roment(char *h)
{
int a, u;

u = 0;
for (a = 0; h[a]; a++)
{
if (h[a] == '#')
{
if (a == 0)
{
free(h);
return (NULL);
}

if (h[a - 1] == ' ' || h[a - 1] == '\t' || h[a - 1] == ';')
u = a;
}
}

if (u != 0)
{
h = rolok(h, a, u + 1);
h[u] = '\0';
}

return (h);
}
/**
 * phillrop - Loop of shell
 ** @dsh: data (a, enter, ag)
 ** Return: no return.
 ********************************/
void phillrop(phiros_shell *dsh)
{
int l, u;
char *enter;

l = 1;
while (l == 1)
{
write(STDIN_FILENO, "^-^ ", 4);
enter = rophiline(&u);
if (u != -1)
{
enter = roment(enter);
if (enter == NULL)
continue;

if (phiytax(dsh, enter) == 1)
{
dsh->status = 2;
free(enter);
continue;
}
enter = rosvar(enter, dsh);
l = philliands(dsh, enter);
dsh->c += 1;
free(enter);
}
else
{
l = 0;
free(enter);
}
}
}
