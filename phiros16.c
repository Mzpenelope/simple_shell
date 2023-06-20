#include "phiros.h"
/**
 * rosodes - add separators and command lines in the lists*
 ** @hs: head of separator list
 ** @hl: head of command lines list
 ** @enter: enter string
 ** Return: no return
 */
void rosodes(phiross **hs, phirosss **hl, char *enter)
{
int u;
char *l;

enter = phillchar(enter, 0);

for (u = 0; enter[u]; u++)
{
if (enter[u] == ';')
phillend(hs, enter[u]);

if (enter[u] == '|' || enter[u] == '&')
{
phillend(hs, enter[u]);
u++;
}
}

l = _rok(enter, ";|&");
do {
l = phillchar(l, 1);
phills(hl, l);
l = _rok(NULL, ";|&");
} while (l != NULL);

}
/**
 * phillext - go to next command line stored
 ** @ls: separator list
 ** @ll: command line list
 ** @dsh: data structure
 ** Return: no return
 **********************************************/
void phillext(phiross **ls, phirosss **ll, phiros_shell *dsh)
{
int l;
phiross *a;
phirosss *b;

l = 1;
a = *ls;
b = *ll;

while (a != NULL && l)
{
if (dsh->status == 0)
{
if (a->s == '&' || a->s == ';')
l = 0;
if (a->s == '|')
b = b->n, a = a->n;
}
else
{
if (a->s == '|' || a->s == ';')
l = 0;
if (a->s == '&')
b = b->n, a = a->n;
}
if (a != NULL && !l)
a = a->n;
}

*ls = a;
*ll = b;
}
/**
 * phillchar - swaps | and & for non-printed chars
 ** @enter: input string
 ** @b: type of swap
 ** Return: swapped string
 **************************************************/
char *phillchar(char *enter, int b)
{
int u;

if (b == 0)
{
for (u = 0; enter[u]; u++)
{
if (enter[u] == '|')
{
if (enter[u + 1] != '|')
enter[u] = 16;
else
u++;
}

if (enter[u] == '&')
{
if (enter[u + 1] != '&')
enter[u] = 12;
else
u++;
}
}
}
else
{
for (u = 0; enter[u]; u++)
{
enter[u] = (enter[u] == 16 ? '|' : enter[u]);
enter[u] = (enter[u] == 12 ? '&' : enter[u]);
}
}
return (enter);
}
/**
 * philliands - splits, executes command lines to ;, | and &
 ** @dsh: data structure
 ** @enter: input string
 ** Return: 0 to exit, 1 to continue
 **************************************************************/
int philliands(phiros_shell *dsh, char *enter)
{

phiross *hs, *ls;
phirosss *hl, *ll;
int l;

hs = NULL;
hl = NULL;

rosodes(&hs, &hl, enter);

ls = hs;
ll = hl;

while (ll != NULL)
{
dsh->enter = ll->l;
dsh->ag = rosline(dsh->enter);
l = roxec(dsh);
free(dsh->ag);

if (l == 0)
break;

phillext(&ls, &ll, dsh);

if (ll != NULL)
ll = ll->n;
}

phily(&hs);
phillly(&hl);

if (l == 0)
return (0);
return (1);
}
/**
 * rosline - tokenizes input string
 ** @enter: enter string.
 ** Return: string splitted.
 ***********************************/
char **rosline(char *enter)
{
roz b;
roz u;
char **tt;
char *t;

b = TOK_BUFSIZE;
tt = malloc(sizeof(char *) * (b));
if (tt == NULL)
{
write(STDERR_FILENO, ": allocation error\n", 18);
exit(EXIT_FAILURE);
}

t = _rok(enter, TOK_DELIM);
tt[0] = t;

for (u = 1; t != NULL; u++)
{
if (u == b)
{
b += TOK_BUFSIZE;
tt =  _roloc(tt, u, sizeof(char *) * b);
if (t == NULL)
{
write(STDERR_FILENO, ": allocation error\n", 18);
exit(EXIT_FAILURE);
}
}
t = _rok(NULL, TOK_DELIM);
tt[u] = t;
}

return (tt);
}
