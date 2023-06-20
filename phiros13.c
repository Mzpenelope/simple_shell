#include "phiros.h"
/**
 ** roget - Handle crtl + c call in prompt
 ** @s: Signal handler
 */
void roget(int s)
{
(void)s;
write(STDOUT_FILENO, "\n^-^ ", 5);
}
/**
 * rosebby - assigns line var
 ** @l: Buffer that store input string
 ** @b: string that is been called to line
 ** @u: size of line
 ** @v: size of buffer
 *******************************************/
void rosebby(char **l, size_t *u, char *b, size_t v)
{

if (*l == NULL)
{
if  (v > BUFSIZE)
*u = v;

else
*u = BUFSIZE;
*l = b;
}
else if (*u < v)
{
if (v > BUFSIZE)
*u = v;
else
*u = BUFSIZE;
*l = b;
}
else
{
_phillpy(*l, b);
free(b);
}
}
/**
 * philyline - Reads input from stream
 ** @l: stores  input
 ** @u: size of lineptr
 ** @m: stream
 ** Return: num of bytes
 ***************************************/
ssize_t philyline(char **l, size_t *u, FILE *m)
{
int a;
static ssize_t enter;
ssize_t r;
char t = 'z';
char *b;


if (enter == 0)
fflush(m);
else
return (-1);
enter = 0;

b = malloc(sizeof(char) * BUFSIZE);
if (b == 0)
return (-1);
while (t != '\n')
{
a = read(STDIN_FILENO, &t, 1);
if (a == -1 || (a == 0 && enter == 0))
{
free(b);
return (-1);
}
if (a == 0 && enter != 0)
{
enter++;
break;
}
if (enter >= BUFSIZE)
b = rolok(b, enter, enter + 1);
b[enter] = t;
enter++;
}
b[enter] = '\0';
rosebby(l, u, b, enter);
r = enter;
if (a != 0)
enter = 0;
return (r);
}
