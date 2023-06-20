#include "phiros.h"
/**
 * philly - frees a phiros_v list
 ** @h: head of linked list.
 ** Return: no return.
 *********************************/
void philly(phiros **h)
{
phiros *t;
phiros *cu;

if (h != NULL)
{
cu = *h;
while ((t = cu) != NULL)
{
cu = cu->n;
free(t);
}
*h = NULL;
}
}
/**
 * philladd - adds var
 ** @h: head of linked list.
 ** @l: length of var.
 ** @v: value of var.
 ** @lv: length of value.
 ** Return: address of head.
 ********************************/
phiros *philladd(phiros **h, int l, char *v, int lv)
{
phiros *nw, *t;

nw = malloc(sizeof(phiros));
if (nw == NULL)
return (NULL);

nw->l = l;
nw->v = v;
nw->lv = lv;

nw->n = NULL;
t = *h;

if (t == NULL)
{
*h = nw;
}
else
{
while (t->n != NULL)
t = t->n;
t->n = nw;
}

return (*h);
}
