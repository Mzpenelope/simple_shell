#include "phiros.h"
/**
 * phillpath - error msg for path and failure denied permission.
 ** @dsh: data (counter, arguments).
 ** Return: string error.
 ****************************************************************/
char *phillpath(phiros_shell *dsh)
{
int l;
char *v_s;
char *e;

v_s = _phillipa(dsh->c);
l = _rozy(dsh->a[0]) + _rozy(v_s);
l += _rozy(dsh->ag[0]) + 24;
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
_roscat(e, ": Permission denied\n");
_roscat(e, "\0");
free(v_s);
return (e);
}
/**
 * phillevn - error message for env
 ** @dsh: data (counter, arguments)
 ** Return: error msg.
 ************************************/
char *phillevn(phiros_shell *dsh)
{
int l;
char *e;
char *v_s;
char *m;

v_s = _phillipa(dsh->c);
m = ": Unable to add/remove from envi\n";
l = _rozy(dsh->a[0]) + _rozy(v_s);
l += _rozy(dsh->ag[0]) + _rozy(m) + 4;
e = malloc(sizeof(char) * (l + 1));
if (e == 0)
{
free(e);
free(v_s);
return (NULL);
}

_phillpy(e, dsh->a[0]);
_roscatt(e, ": ");
_roscat(e, v_s);
_roscat(e, ": ");
_roscat(e, dsh->ag[0]);
_roscat(e, m);
_roscat(e, "\0");
free(v_s);
return (e);
}
