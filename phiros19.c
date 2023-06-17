#include "phiros.h"
/**
 * _phillipa - converts int to string.
 ** @v: int number
 ** Return: String.
 **************************************/
char *_phillipa(int v)
{
unsigned int an;
int l = rosi_l(v);
char *b;

b = malloc(sizeof(char) * (l + 1));
if (b == 0)
return (NULL);

*(b + l) = '\0';

if (v < 0)
{
an = v * -1;
b[0] = '-';
}
else
{
an = v;
}

l--;
do {
*(b + l) = (an % 10) + '0';
an = an / 10;
l--;
}
while (an > 0)
;
return (b);
}
/**
 * _rosina - converts string to int.
 ** @v: input string.
 ** Return: integer.
 *********************************************/
int _rosina(char *v)
{
unsigned int ct = 0, s = 0, nn = 0, rn = 1, n = 1, u;

while (*(v + ct) != '\0')
{
if (s > 0 && (*(v + ct) < '0' || *(v + ct) > '9'))
break;

if (*(v + ct) == '-')
rn *= -1;

if ((*(v + ct) >= '0') && (*(v + ct) <= '9'))
{
if (s > 0)
n *= 10;
s++;
}
ct++;
}

for (u = ct - s; u < ct; u++)
{
nn = nn + ((*(v + u) - 48) * n);
n /= 10;
}
return (nn * rn);
}
/**
 * rosi_l - Get lenght of num.
 ** @v: type int number.
 ** Return: Lenght of num.
 *******************************/
int rosi_l(int v)
{
unsigned int an;
int l = 1;

if (v < 0)
{
l++;
an = v * -1;
}
else
{
an = v;
}
while (an > 9)
{
l++;
an = an / 10;
}

return (l);
}
