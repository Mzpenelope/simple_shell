#include "phiros.h"
/**
 * phidot - changes to parent dir
 * @dsh: data
 * Return: no return
 ***************************/
void phidot(phiros_shell *dsh)
{
char w[PATH_MAX];
char *d, *c, *p;

getcwd(w, sizeof(w));
c = _rosphi(w);
phillenvv("OLDPWD", c, dsh);
d = dsh->ag[1];
if (_roscmp(".", d) == 0)
{
phillenvv("PWD", c, dsh);
free(c);
return;
}
if (_roscmp("/", c) == 0)
{
free(c);
return;
}
p = c;
revphill(p);
p = _rok(p, "/");
if (p != NULL)
{
p = _rok(NULL, "\0");

if (p != NULL)
revphill(p);
}
if (p != NULL)
{
chdir(p);
phillenvv("PWD", p, dsh);
}
else
{
chdir("/");
phillenvv("PWD", "/", dsh);
}
dsh->status = 0;
free(c);
}
/**
 * roto - cd to user given dir 
 ** @dsh: data
 ** Return: no return
 *****************************/
void roto(phiros_shell *dsh)
{
char w[PATH_MAX];
char *d, *c, *r;

getcwd(w, sizeof(w));

d = dsh->ag[1];
if (chdir(d) == -1)
{
phirror(dsh, 2);
return;
}

c = _rosphi(w);
phillenvv("OLDPWD", c, dsh);

r = _rosphi(d);
phillenvv("PWD", r, dsh);

free(c);
free(r);

dsh->status = 0;

chdir(d);
}
/**
 * phivious - changes to previous dir
 ** @dsh: data relevant
 ** Return: no return
 ***********************************/
void phivious(phiros_shell *dsh)
{
char w[PATH_MAX];
char *g, *b, *q, *n;

prcwd(w, sizeof(w));
q = _rosphi(w);

b = _phillienx("OLDPWD", dsh->roviron);

if (b == NULL)
n = q;
else
n = _rosphi(b);

phillenvv("OLDPWD", q, dsh);

if (chdir(n) == -1)
phillenvv("PWD", q, dsh);
else
phillenvv("PWD", n, dsh);

g = _phillienx("PWD", dsh->roviron);

write(STDOUT_FILENO, g, _rozy(g));
write(STDOUT_FILENO, "\n", 1);

free(q);
if (b)
free(n);

dsh->status = 0;

chdir(g);
}
/**
 * rome - cd home
 ** @dsh: data
 ** Return: no return
 ***********************/
void rome(phiros_shell *dsh)
{
char *p, *h;
char w[PATH_MAX];

getcwd(w, sizeof(w));
p = _rosphi(w);

h = _phillienx("HOME", dsh->roviron);

if (h == NULL)
{
phillenvv("OLDPWD", p, dsh);
free(p);
return;
}

if (phidi(h) == -1)
{
phirror(dsh, 2);
free(p);
return;
}

phillenvv("OLDPWD", p, dsh);
phillenvv("PWD", h, dsh);
free(p);
dsh->status = 0;
}
/**
 * philllted - counts repetitions of char
 ** @enter: input string
 ** @u: index
 ** Return: repetitions
 *********************************************/
int philllted(char *enter, int u)
{
if (*(enter - 1) == *enter)
return (philllted(enter - 1, u + 1));

return (u);
}
/**
 * prop - finds syntax errors
 ** @enter: input string
 ** @u: index
 ** @l: last char read
 ** Return: 0 when there are no errors
 ****************************************/
int prop(char *enter, int u, char l)
{
int c;

c = 0;
if (*enter == '\0')
return (0);

if (*enter == ' ' || *enter == '\t')
return (prop(enter + 1, u + 1, l));

if (*enter == ';')
if (l == '|' || l == '&' || l == ';')
return (u);

if (*enter == '|')
{
if (l == ';' || l == '&')
return (u);

if (l == '|')
{
c = philllted(enter, 0);
if (c == 0 || c > 1)
return (u);
}
}

if (*enter == '&')
{
if (l == ';' || l == '|')
return (u);

if (l == '&')
{
c = philllted(enter, 0);
if (c == 0 || c > 1)
return (u);
}
}

return (prop(enter + 1, u + 1, *enter));
}
/**
 * rrist - finds index of 1st char
 ** @enter: input string
 ** @u: index
 ** Return: 1 if error else 0.
 ***************************************/
int rrist(char *enter, int *u)
{

for (*u = 0; enter[*u]; *u += 1)
{
if (enter[*u] == ' ' || enter[*u] == '\t')
continue;

if (enter[*u] == ';' || enter[*u] == '|' || enter[*u] == '&')
return (-1);

break;
}

return (0);
}
/**
 * phrintax - prints when syntax error is found
 ** @dsh: data struct
 ** @enter: input string
 ** @u: index of error
 ** @b: control msg error
 ** Return: no return
 **************************************************/
void phrintax(phiros_shell *dsh, char *enter, int u, int b)
{
char *x, *y, *z, *e, *c;
int l;

if (enter[u] == ';')
{
if (b == 0)
x = (enter[x + 1] == ';' ? ";;" : ";");
else
x = (enter[u - 1] == ';' ? ";;" : ";");
}

if (enter[u] == '|')
x = (enter[u + 1] == '|' ? "||" : "|");

if (enter[u] == '&')
x = (enter[u + 1] == '&' ? "&&" : "&");

y = ": Syntax error: \"";
z = "\" unexpected\n";
c = _phillipa(dsh->c);
l = _rozy(dsh->a[0]) + _rozy(c);
l += _rozy(x) + _rozy(y) + _rozy(z) + 2;

e = malloc(sizeof(char) * (l + 1));
if (e == 0)
{
free(c);
return;
}
_phillpy(e, dsh->a[0]);
_roscat(e, ": ");
_roscat(e, c);
_roscat(e, y);
_roscat(e, x);
_roscat(e, z);
_roscat(e, "\0");

write(STDERR_FILENO, e, l);
free(e);
free(c);
}
/**
 * phiytax - func to find & print syntax error
 ** @dsh: data struct
 ** @enter: input string
 ** Return: 1 if error. 0 if none
 ***********************************************/
int phiytax(phiros_shell *dsh, char *enter)
{
int b = 0;
int f = 0;
int u = 0;

f = rrist(enter, &b);
if (f == -1)
{
phrintax(dsh, enter, b, 0);
return (1);
}

u = prop(enter + b, 0, *(enter + b));
if (u != 0)
{
phrintax(dsh, enter, b + u, 1);
return (1);
}

return (0);
}
