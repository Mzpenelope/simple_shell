#include "phiros.h"
/**
 * rovarx - check if the typed var is $$ or $?
 ** @hh: head of linked list
 ** @h: input string
 ** @l: last status of the Shell
 ** @phirose: data structure
 ** Return: no return
 ***********************************************/
int rovarx(phiros **hh, char *h, char *l, phiros_shell *phirose)
{
int u, q, o;

q = _rozy(l);
o = _rozy(phirose->pid);

for (u = 0; h[u]; u++)
{
if (h[u] == '$')
{
if (h[u + 1] == '?')
philladd(hh, 2, l, q), u++;
else if (h[u + 1] == '$')
philladd(hh, 2, phirose->pid, o), u++;
else if (h[u + 1] == '\n')
philladd(hh, 0, NULL, 0);
else if (h[u + 1] == '\0')
philladd(hh, 0, NULL, 0);
else if (h[u + 1] == ' ')
philladd(hh, 0, NULL, 0);
else if (h[u + 1] == '\t')
philladd(hh, 0, NULL, 0);
else if (h[u + 1] == ';')
philladd(hh, 0, NULL, 0);
else
crosina(hh, h + u, phirose);
}
}
return (u);
}
/**
 * crosina - checks if the typed var is an env var
 ** @hh: head of linked list
 ** @h: input string
 ** @phirose: data structure
 ** Return: no return
 ****************************************************/
void crosina(phiros **hh, char *h, phiros_shell *phirose)
{
int r, c, y, v;
char **e;

e = phirose->envi;
for (r = 0; e[r]; r++)
{
for (y = 1, c = 0; e[r][c]; c++)
{
if (e[r][c] == '=')
{
v = _rozy(e[r] + c + 1);
philladd(hh, y, e[r] + c + 1, v);
return;
}

if (h[y] == e[r][c])
y++;
else
break;
}
}

for (y = 0; h[y]; y++)
{
if (h[y] == ' ' || h[y] == '\t' || h[y] == ';' || h[y] == '\n')
break;
}

philladd(hh, y, NULL, 0);
}
/**
 * rosyput - replaces string into var
 ** @h: head of linked list
 ** @enter: input string
 ** @t: new input string (replaced)
 ** @n: new length
 ** Return: replaced string
 ***************************************/
char *rosyput(phiros **h, char *enter, char *t, int n)
{
phiros *x;
int a, b, c;

x = *h;
for (b = a = 0; a < n; a++)
{
if (enter[b] == '$')
{
if (!(x->l) && !(x->lv))
{
t[a] = enter[b];
b++;
}
else if (x->l && !(x->lv))
{
for (c = 0; c < x->l; c++)
b++;
a--;
}
else
{
for (c = 0; c < x->lv; c++)
{
t[a] = x->v[c];
a++;
}
b += (x->l);
a--;
}
x = x->n;
}
else
{
t[a] = enter[b];
b++;
}
}
return (t);
}
/**
 * rosvar - calls functions to replace string into vars
 ** @enter: input string
 ** @dsh: data structure
 ** Return: replaced string
 **********************************************************/
char *rosvar(char *enter, phiros_shell *dsh)
{
phiros *h, *x;
char *status, *t;
int m, n;

status = _phillipa(dsh->status);
h = NULL;

m = rovarx(&h, enter, status, dsh);

if (h == NULL)
{
free(status);
return (enter);
}

x = h;
n = 0;

while (x != NULL)
{
n += (x->lv - x->l);
x = x->n;
}

n += m;

t = malloc(sizeof(char) * (n + 1));
t[n] = '\0';

t = rosyput(&h, enter, t, n);

free(enter);
free(status);
philly(&h);

return (t);
}
