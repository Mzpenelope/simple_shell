#include "phiros.h"
/**
 * _phillienx - get env var
 ** @n: name of env var
 ** @r: env var
 ** Return: value of env var else NULL.
 ******************************************/
char *_phillienx(const char *n, char **r)
{
char *p;
int u, m;

p = NULL;
m = 0;

for (u = 0; r[u]; u++)
{
m = phillipvnn(r[u], n);
if (m)
{
p = r[u];
break;
}
}

return (p + m);
}
/**
 * pnv - prints env var
 ** @dsh: data
 ** Return: 1 on success.
 *************************/
int pnv(phiros_shell *dsh)
{
int a, b;

for (a = 0; dsh->roviron[a]; a++)
{

for (b = 0; dsh->roviron[a][b]; b++)
;

write(STDOUT_FILENO, dsh->roviron[a], b);
write(STDOUT_FILENO, "\n", 1);
}
dsh->status = 0;

return (1);
}
