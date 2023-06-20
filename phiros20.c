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
