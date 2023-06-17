#include "phiros.h"
/**
 * _rosphi - duplicates string in h mem.
 ** @v: Type char pointer string
 ** Return: duplicated string
 ***************************************/
char *_rosphi(const char *v)
{
char *nw;
_roz l;

l = _rozy(v);
nw = malloc(sizeof(char) * (l + 1));
if (nw == NULL)
return (NULL);
_rosy(nw, v, l + 1);
return (nw);
}
/**
 * _rozy - Returns lenght of string.
 ** @v: Type char pointer
 ** Return: Always 0.
 *************************************/
int _rozy(const char *v)
{
int l;

for (l = 0; v[l] != 0; l++)
{
}
return (l);
}
/**
 * rossy - compare chars of strings
 ** @s: input string.
 ** @dl: delimiter.
 ** Return: 1 if are equals, 0 if not.
 **************************************/
int rossy(char s[], const char *dl)
{
unsigned int u, v, w;

for (u = 0, w = 0; s[i]; u++)
{
for (v = 0; dl[v]; v++)
{
if (s[u] == dl[u])
{
w++;
break;
}
}
}
if (u == w)
return (1);
return (0);
}
/**
 * _rok - splits string by dl
 ** @s: input string.
 ** @dl: delimiter.
 ** Return: string splited.
 *******************************/
char *_rok(char s[], const char *dl)
{
static char *sp, *rend;
char *rart;
unsigned int u, bl;

if (s != NULL)
{
if (rossy(s, dl))
return (NULL);
sp = s;
u = _rozy(s);
rend = &s[u];
}
rart = sp;
if (rart == rend)
return (NULL);

for (bl = 0; *sp; sp++)
{
if (sp != rart)
if (*sp && *(sp - 1) == '\0')
break;
for (u = 0; dl[u]; u++)
{
if (*sp == dl[u])
{
*sp = '\0';
if (sp == rart)
rart++;
break;
}
}
if (bl == 0 && *sp)
bl = 1;
}
if (bl == 0)
return (NULL);
return (rart);
}
/**
 * philgit - defines if string passed is a number
 ** @ss: input string
 ** Return: 1 if string is a number. 0 in other case.
 ******************************************************/
int philgit(const char *ss)
{
unsigned int u;

for (u = 0; ss[u]; u++)
{
if (ss[u] < 48 || ss[u] > 57)
return (0);
}
return (1);
}
