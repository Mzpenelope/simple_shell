#include "phiros.h"
/**
 * revphill - reverses string.
 ** @ss: input string.
 ** Return: no return.
 *****************************/
void revphill(char *ss)
{
int c = 0, x, y;
char *s, t;

while (c >= 0)
{
if (ss[c] == '\0')
break;
c++;
}
s = ss;

for (x = 0; x < (c - 1); x++)
{
for (y = x + 1; y > 0; y--)
{
t = *(s + y);
*(s + y) = *(s + (y - 1));
*(s + (y - 1)) = t;
}
}
}
