#include "phiros.h"
/**
 * phillly - frees phirosss
 ** @h: head of the linked list.
 ** Return: no return.
 ***************************************/
void phillly(phirosss **h)
{
phirosss *t;
phirosss *cu;

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
 * phillend - adds separator
 ** @h: head of linked list.
 ** @s: separator found (; | &).
 ** Return: address of the head.
 ***************************************/
phiross *phillend(phiross **h, char s)
{
phiross *nw, *t;

nw = malloc(sizeof(phiross));
if (nw == NULL)
return (NULL);

nw->s = s;
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
/**
 * phills - adds a command line
 ** @h: head of linked list.
 ** @l: command line.
 ** Return: address of h.
 *********************************/
phirosss *phills(phirosss **h, char *l)
{
phirosss *nw, *t;

nw = malloc(sizeof(phirosss));
if (nw == NULL)
return (NULL);

nw->l = l;
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
/**
 * phily - frees a sep_list
 ** @h: head of the linked list.
 ** Return: no return.
 ***************************************/
void phily(phiross **h)
{
phiross *t;
phiross *cu;

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
