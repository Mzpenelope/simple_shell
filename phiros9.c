#include "phiros.h"
/**
 * _rosy - copies info b/w void pointers.
 ** @np: destination pointer.
 ** @p: source pointer.
 ** @s: size of new pointer
 ** Return: no return.
 *****************************************/
void _rosy(void *np, const void *p, unsigned int s)
{
char *rosp = (char *)p;
char *rosnp = (char *)np;
unsigned int u;

for (u = 0; u < s; u++)
rosnp[u] = rosp[u];
}
/**
 * _roloc - reallocates memblock of double pointer.
 ** @ptr: double pointer to previous mem
 ** @os: size, in bytes, of p.
 ** @ns: size, in bytes, ofnew memblock.
 ** Return: p.
 ** if ns == os, returns p without changes.
 ** if malloc fails, returns NULL.
 ***************************************************/
char **_roloc(char **p, unsigned int os, unsigned int ns)
{
char **np;
unsigned int u;

if (p == NULL)
return (malloc(sizeof(char *) * ns));

if (ns == os)
return (p);

np = malloc(sizeof(char *) * ns);
if (np == NULL)
return (NULL);

for (u = 0; u < os; u++)
np[u] = p[u];

free(p);

return (np);
}
/**
 * rolok - reallocates memblock.
 ** @p: pointer to the mem previously allocated.
 ** @os: size, in bytes, of allocated space of p.
 ** @ns: size, in bytes, of new memblock.
 ** Return: p.
 ** if ns == os, returns p without changes.
 ** if malloc fails, returns NULL.
 ***************************************************/
void *rolok(void *p, unsigned int os, unsigned int ns)
{
void *np;

if (p == NULL)
return (malloc(ns));

if (ns == 0)
{
free(p);
return (NULL);
}

if (ns == os)
return (p);

np = malloc(ns);
if (np == NULL)
return (NULL);

if (ns < os)
_rosy(np, p, ns);
else
_rosy(np, p, os);

free(p);
return (np);
}
