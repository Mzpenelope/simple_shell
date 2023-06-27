#include "main.h"
/**
 * f_data - frees data struct
 * @dsh: data struct
 * Return: no return
 **********************************/
void f_data(phiros_shell *dsh)
{
unsigned int u = 0;
while (dsh->_environ[u])
{
free(dsh->_environ[u]);
u++;
}

free(dsh->_environ);
free(dsh->pid);
}
/**
 * s_data - Initialize data struct
 * @dsh: data struct
 * @av: arg vector
 * Return: no return
 **********************************/
void s_data(phiros_shell *dsh, char **av)
{
unsigned int u = 0;

dsh->av = av;
dsh->input = NULL;
dsh->args = NULL;
dsh->status = 0;
dsh->counter = 1;

while (environ[u])
{
u++;
}

dsh->_environ = malloc(sizeof(char *) * (u + 1));

int i = 0;
while (environ[i])
{
dsh->_environ[i] = pr_strdup(environ[i]);
i++;
}

dsh->_environ[i] = NULL;
dsh->pid = pr_itoa(getpid());
}
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	phiros_shell dsh;
	(void) ac;

	signal(SIGINT, get_sigint);
	s_data(&dsh, av);
	s_loop(&dsh);
	f_data(&dsh);
	if (dsh.status < 0)
		return (255);
	return (dsh.status);
}
