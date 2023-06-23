#include "phiros.h"
/**
 * fdiros - frees data struct
 ** @dsh: data struct
 ** Return: no return
 ****************************/
void fdiros(phiros_shell *dsh)
{
unsigned int u;

for (u = 0; dsh->_environ[u]; u++)
{
free(dsh->_environ[u]);
}

free(dsh->_environ);
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

for (u = 0; _environ[u]; u++)
{
dsh->_environ[u] = _rosphi(envi[u]);
}

dsh->_environ[u] = NULL;
dsh->pid = _phillipa(getpid());
}
/**
 * main - Entry point
 ** @c: arg count
 ** @v: arg vector
 ** Return: 0 on success.
 *******************************/
int main(int c, char **v)
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
