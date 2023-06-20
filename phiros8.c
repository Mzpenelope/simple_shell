#include "phiros.h"
/**
 * isphilly - checks ":" in cd
 ** @p: char pointer
 ** @u: int pointer
 ** Return: 1 if p is searchable in cd, else 0
 **************************************************/
int isphilly(char *p, int *u)
{
if (p[*u] == ':')
return (1);

while (p[*u] != ':' && p[*u])
{
*u += 1;
}

if (p[*u])
*u += 1;

return (0);
}
/**
 *roich - locates command
 ** @c: command name
 ** @n: env var
 ** Return: location of command.
 **********************************/
char *roich(char *c, char **n)
{
char *p, *h, *t, *d;
int r, l, u;
struct stat pr;

p = _phillienx("PATH", n);
if (p)
{
h = _rosphi(p);
l = _rozy(c);
t = _rok(h, ":");
u = 0;
while (t != NULL)
{
if (isphilly(p, &u))
if (stat(c, &pr) == 0)
return (c);
r = _rozy(t);
d = malloc(r + l + 2);
_phillpy(d, t);
_roscat(d, "/");
_roscat(d, c);
_roscat(d, "\0");
if (stat(d, &pr) == 0)
{
free(h);
return (d);
}
free(d);
t = _rok(NULL, ":");
}
free(h);
if (stat(c, &pr) == 0)
return (c);
return (NULL);
}
if (c[0] == '/')
if (stat(c, &pr) == 0)
return (c);
return (NULL);
}
/**
 * rosutable - determines if is an executable
 ** @dsh: data struct
 ** Return: 0 if false, other number if true
 ********************************************/
int rosutable(phiros_shell *dsh)
{
struct stat pr;
int u;
char enter;

enter = dsh->ag[0];
for (u = 0; enter[u]; u++)
{
if (enter[u] == '.')
{
if (enter[u + 1] == '.')
return (0);
if (enter[u + 1] == '/')
continue;
else
break;
}
else if (enter[u] == '/' && u != 0)
{
if (enter[u + 1] == '.')
continue;
u++;
break;
}
else
break;
}
if (u == 0)
return (0);

if (stat(enter + u, &pr) == 0)
{
return (u);
}
phirror(dsh, 127);
return (-1);
}
/**
 * pheck - checks if user has permissions to access
 ** @d: destination dir
 ** @dsh: data struct
 ** Return: 1 if there is an error, 0 if not
 ****************************************************/
int pheck(char *d, phiros_shell *dsh)
{
if (d == NULL)
{
phirror(dsh, 127);
return (1);
}

if (_roscmp(dsh->ag[0], d) != 0)
{
if (access(d, X_OK) == -1)
{
phirror(dsh, 126);
free(d);
return (1);
}
free(d);
}
else
{
if (access(dsh->ag[0], X_OK) == -1)
{
phirror(dsh, 126);
return (1);
}
}

return (0);
}
/**
 * phexec - executes command lines
 ** @dsh: data
 ** Return: 1 on success.
 ***********************************/
int phexec(phiros_shell *dsh)
{
pid_t a;
pid_t b;
int s;
int e;
char *d;
(void) b;

e = rosutable(dsh);
if (e == -1)
return (1);
if (e == 0)
{
d = roich(dsh->ag[0], dsh->roviron);
if (pheck(d, dsh) == 1)
return (1);
}

a = fork();
if (a == 0)
{
if (e == 0)
d = roich(dsh->ag[0], dsh->roviron);
else
d = dsh->ag[0];
execve(d + e, dsh->ag, dsh->roviron);
}
else if (a < 0)
{
perror(dsh->a[0]);
return (1);
}
else
{
do {
b = waitpid(a, &s, WUNTRACED);
} while (!WIFEXITED(s) && !WIFSIGNALED(s));
}

dsh->status = s / 256;
return (1);
}

