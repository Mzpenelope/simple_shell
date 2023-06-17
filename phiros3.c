#include "phiros.h"
/**
 * rosina_cd - concatenates message for cd error
 ** @dsh: data (dir)
 ** @e: output message
 ** @m: print message
 ** @v_s: counter lines
 ** Return: error message
 ****************************************************/
char *rosina_cd(phiros_shell *dsh, char *m, char *e, char *v_s)
{
char *bad_f;
_phillpy(e, dsh->a[0]);
_roscat(e, v_s);
_roscat(e, ": ");
_roscat(e, dsh->ag[0]);
_roscat(e, ": ");
_roscat(e, m);
if (dsh->ag[1][0] == '-')
{
bad_f = malloc(3);
bad_f[0] = '-';
bad_f[1] = dsh->ag[1][1];
bad_f[2] = '\0';
_roscat(e, bad_f);
free(bad_f);
}
else
{
_roscat(e, dsh->ag[1]);
}

_roscat(e, "\n");
_roscat(e, "\0");
return (e);
}
/**
 * e_g_cd - error message for cd 
 ** @dsh: data (dir)
 ** Return: Error message
 *********************************/
char *e_g_cd(phiros_shell *dsh)
{
int l, ros_lenid;
char *e, *v_s, *m;

v_s = _phillipa(dsh->c);
if (dsh->ag[1][0] == '-')
{
m = ": no way ";
ros_lenid = 2;
}
else
{
m = ": failed ";
ros_lenid = _rozy(dsh->ag[1]);
}

l = _rozy(dsh->a[0]) + _rozy(dsh->ag[0]);
l += _rozy(v_s) + _rozy(m) + ros_lenid + 5;
e = malloc(sizeof(char) * (l + 1));

if (e == 0)
{
free(v_s);
return (NULL);
}

e = rosina_cd(dsh, m, e, v_s);

free(v_s);

return (e);
}
/**
 * ros_xll - error message for exit
 ** @dsh: data (counter, arguments)
 ** Return: Error message
 ************************************/
char *ros_xll(phiros_shell *dsh)
{
int l;
char *v_s;
char *e;
v_s = _phillipa(dsh->c);
l = _rozy(dsh->a[0]) + _rozy(v_s);
l += _rozy(dsh->ag[0]) + _rozy(dsh->ag[1]) + 23;
e = malloc(sizeof(char) * (l + 1));
if (e == 0)
{
free(v_s);
return (NULL);
}
_phillpy(e, dsh->a[0]);
_roscat(e, ": ");
_roscat(e, v_s);
_roscat(e, ": ");
_roscat(e, dsh->ag[0]);
_roscat(e, ": Illegal num: ");
_roscat(e, dsh->ag[1]);
_roscat(e, "\n\0");
free(v_s);

return (e);
}
/**
* ros_nd - error message for command not found
** @dsh: data (counter, arguments)
** Return: Error message
****************************************************************/
char *ros_nd(phiros_shell *dsh)
{
int l;
char *e;
char *v_s;

v_s = _phillipa(dsh->c);
l = _rozy(dsh->a[0]) + _rozy(v_s);
l += _rozy(dsh->ag[0]) + 16;
e = malloc(sizeof(char) * (l + 1));
if (e == 0)
{
free(e);
free(v_s);
return (NULL);
}
_phillpy(e, dsh->a[0]);
_roscat(e, ": ");
_roscat(e, v_s);
_roscat(e, ": ");
_roscat(e, dsh->ag[0]);
_roscat(e, ": not found\n");
_roscat(e, "\0");
free(v_s);
return (e);
}
