#include "phiros.h"
/**
 * error_env - the error info for env in get_env.
 * @dsh: data relevant (counter, arguments)
 * Return: an error message.
 */
char *e_e(phiros_shell *dsh)
{
	int lth;
	char *e;
	char *v_s;
	char *msg;

	v_s = pr_itoa(dsh->counter);
	msg = ": Unable to add/remove from environment\n";
	lth = pr_strlen(dsh->av[0]) + pr_strlen(v_s);
	lth += pr_strlen(dsh->args[0]) + pr_strlen(msg) + 4;
	e = malloc(sizeof(char) * (lth + 1));
	if (e == 0)
	{
		free(e);
		free(v_s);
		return (NULL);
	}

	pr_strcpy(e, dsh->av[0]);
	pr_strcat(e, ": ");
	pr_strcat(e, v_s);
	pr_strcat(e, ": ");
	pr_strcat(e, dsh->args[0]);
	pr_strcat(e, msg);
	pr_strcat(e, "\0");
	free(v_s);

	return (e);
}
/**
 * e_p_126 - error info for path and failure denied permission.
 * @dsh: data relevant (counter, arguments).
 * Return: error string.
 */
char *e_p_126(phiros_shell *dsh)
{
	int lth;
	char *v_s;
	char *e;

	v_s = pr_itoa(dsh->counter);
	lth = pr_strlen(dsh->av[0]) + pr_strlen(v_s);
	lth += pr_strlen(dsh->args[0]) + 24;
	e = malloc(sizeof(char) * (lth + 1));
	if (e == 0)
	{
		free(e);
		free(v_s);
		return (NULL);
	}
	pr_strcpy(e, dsh->av[0]);
	pr_strcat(e, ": ");
	pr_strcat(e, v_s);
	pr_strcat(e, ": ");
	pr_strcat(e, dsh->args[0]);
	pr_strcat(e, ": Permission denied\n");
	pr_strcat(e, "\0");
	free(v_s);
	return (e);
}
