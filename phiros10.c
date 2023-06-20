#include "phiros.h"
/**
 * phifo - copies info
 ** @n: name
 ** @v: value
 ** Return: nw.
 ************************/
char *phifo(char *n, char *v)
{
char *nw;
int me, ue, l;

me = _rozy(n);
ue = _rozy(v);
l = me + ue + 2;
nw = malloc(sizeof(char) * (l));
_roscat(nw, n);
_roscat(nw, "=");
_roscat(nw, v);
_roscat(nw, "\0");

return (nw);
}
/**
 * phillenvv - sets environment var
 * @n: name of environment var
 * @v: value of environment var
 * @dsh: data struct
 * Return: no return
 */
void phillenvv(char *n, char *v, phiros_shell *dsh)
{
int z;
char *r, *p;

for (z = 0; dsh->envi[z]; z++)
{
r = _rosphi(dsh->envi[z]);
p = _rok(r, "=");
if (_roscmp(p, n) == 0)
{
free(dsh->envi[z]);
dsh->envi[z] = phifo(p, v);
free(r);
return;
}
free(r);
}

dsh->envi = _roloc(dsh->envi, z, sizeof(char *) * (z + 2));
dsh->envi[z] = phifo(n, v);
dsh->envi[z + 1] = NULL;
}
/**
 * rossenvv - compares env var names
 ** @dsh: data relevant
 ** Return: 1 on success.
 ************************************/
int rossenvv(phiros_shell *dsh)
{

if (dsh->ag[1] == NULL || dsh->ag[2] == NULL)
{
phirror(dsh, -1);
return (1);
}

phillenvv(dsh->ag[1], dsh->ag[2], dsh);

return (1);
}
/**
 * unrosee - deletes env var
 ** @dsh: data
 ** Return: 1 on success.
 *****************************/
int unrosee(phiros_shell *dsh)
{
char **z;
char *r, *p;
int a, b, c;

if (dsh->ag[1] == NULL)
{
phirror(dsh, -1);
return (1);
}
c = -1;
for (a = 0; dsh->envi[a]; a++)
{
r = _rosphi(dsh->envi[a]);
p = _rok(r, "=");
if (_roscmp(p, dsh->ag[1]) == 0)
{
c = a;
}
free(r);
}
if (c == -1)
{
phirror(dsh, -1);
return (1);
}
z = malloc(sizeof(char *) * (a));
for (a = b = 0; dsh->envi[a]; a++)
{
if (a != c)
{
z[b] = dsh->envi[a];
b++;
}
}
z[b] = NULL;
free(dsh->envi[c]);
free(dsh->envi);
dsh->envi = z;
return (1);
}
/**
 * phillipvnn - compares env var
 ** @v: name of environment var
 ** @e: name passed
 ** Return: 0 or another value
 ********************************/
int phillipvnn(const char *v, const char *e)
{
int u;

for (u = 0; v[u] != '='; u++)
{
if (v[u] != e[u])
{
return (0);
}
}

return (u + 1);
}

