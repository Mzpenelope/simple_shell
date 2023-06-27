#include "main.h"

/**
 * error_env - the error info for env in get_env.
 * @dsh: data relevant (counter, arguments)
 * Return: an error message.
 */
char *error_env(data_shell *dsh)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(dsh->counter);
	msg = ": Unable to add/remove from environment\n";
	length = pr_strlen(dsh->av[0]) + pr_strlen(ver_str);
	length += pr_strlen(dsh->args[0]) + pr_strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	pr_strcpy(error, dsh->av[0]);
	pr_strcat(error, ": ");
	pr_strcat(error, ver_str);
	pr_strcat(error, ": ");
	pr_strcat(error, ds->args[0]);
	pr_strcat(error, msg);
	pr_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error info for path and failure denied permission.
 * @dsh: data relevant (counter, arguments).
 *
 * Return: error string.
 */
char *error_path_126(data_shell *dsh)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(dsh->counter);
	length = pr_strlen(dsh->av[0]) + pr_strlen(ver_str);
	length += pr_strlen(dsh->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	pr_strcpy(error, dsh->av[0]);
	pr_strcat(error, ": ");
	pr_strcat(error, ver_str);
	pr_strcat(error, ": ");
	pr_strcat(error, dsh->args[0]);
	pr_strcat(error, ": Permission denied\n");
	pr_strcat(error, "\0");
	free(ver_str);
	return (error);
}
