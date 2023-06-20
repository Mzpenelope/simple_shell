#include "phiros.h"
/**
 * _roscat - concatenate two strings
 ** @d: char pointer d of the copied s
 ** @s: const char pointer source of s
 ** Return: the dest
 ***************************************/
char *_roscat(char *d, const char *s)
{
int x;
int y;

for (x = 0; d[x] != '\0'; x++)
;

for (y = 0; s[y] != '\0'; y++)
{
d[x] = s[y];
x++;
}

d[x] = '\0';
return (d);
}
/**
 * _phillpy - Copies string pointed to by s.
 * @d: Type char pointer d of copied s
 * @s: Type char pointer source of s
 * Return: d.
 *************************************/
char *_phillpy(char *d, char *s)
{

size_t m;

for (m = 0; s[m] != '\0'; m++)
{
d[m] = s[m];
}
d[m] = '\0';

return (d);
}
/**
 * _roscmp - Function that compares two strings.
 * @p: type p compared
 * @r: type r compared
 * Return: Always 0.
 *****************************************************/
int _roscmp(char *p, char *r)
{
int u;

for (u = 0; p[u] == r[u] && p[u]; u++)
if (p[u] > r[u])
return (1);
if (p[u] < r[u])
return (-1);
return (0);
}
/**
 * _phillchr - locates a character in a string,
 ** @m: string.
 ** @n: character.
 ** Return: the pointer to the first occurrence of the character c.
 **********************************************************************/
char *_phillchr(char *m, char n)
{
unsigned int u = 0;

for (; *(m + u) != '\0'; u++)
if (*(m + u) == n)
return (m + u);
if (*(m + u) == n)
return (m + u);
return ('\0');
}
/**
 * _phillpn - gets length of a prefix substring.
 ** @l: initial segment.
 ** @a: accepted bytes.
 ** Return: num of accepted bytes.
 *************************************************/
int _phillpn(char *l, char *a)
{
int x, y, b;

for (x = 0; *(l + x) != '\0'; x++)
{
b = 1;
for (y = 0; *(a + y) != '\0'; y++)
{
if (*(l + x) == *(a + y))
{b = 0;
break;
}
}
if (b == 1)
break;
}
return (x);
}
