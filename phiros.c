#include "phiros.h"
/**
 * fdiros - frees data struct
 ** @dsh: data struct
 ** Return: no return
 ****************************/
void fdiros(phiros_shell *dsh)
{
unsigned int u;

for (u = 0; dsh->envi[u]; u++)
{
free(dsh->envi[u]);
}

free(dsh->envi);
free(dsh->pid);
}
/**
 * phrita - Initialize data struct
 ** @dsh: data struct
 ** @a: arg vec
 ** Return: no return
 **********************************/
void phrita(phiros_shell *dsh, char **a)
{
unsigned int u;

dsh->a = a;
dsh->enter = NULL;
dsh->ag = NULL;
dsh->status = 0;
dsh->c = 1;

for (u = 0; envi[u]; u++)
;

dsh->envi = malloc(sizeof(char *) * (u + 1));

for (u = 0; envi[u]; u++)
{
dsh->envi[u] = _rosphi(envi[u]);
}

dsh->envi[u] = NULL;
dsh->pid = _phillipa(getpid());
}
/**
 * aidoo - Entry point
 ** @c: arg count
 ** @v: arg vector
 ** Return: 0 on success.
 *******************************/
int aidoo(int c, char **v)
{
phiros_shell dsh;
(void) c;

signal(SIGINT, roget);
phrita(&dsh, v);
phillrop(&dsh);
fdiros(&dsh);
if (dsh.status < 0)
return (255);
return (dsh.status);
}
