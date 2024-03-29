#include "phiros.h"
/**
 * pr_bring_line - assigns the line var for get_line
 * @lptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @i: size of line
 * @k: size of buffer
 */
void pr_bring_line(char **lptr, size_t *i, char *buffer, size_t k)
{

	if (*lptr == NULL)
	{
		if  (k > BUFSIZE)
			*i = k;

		else
			*i = BUFSIZE;
		*lptr = buffer;
	}
	else if (*i < k)
	{
		if (k > BUFSIZE)
			*i = k;
		else
			*i = BUFSIZE;
		*lptr = buffer;
	}
	else
	{
		pr_strcpy(*lptr, buffer);
		free(buffer);
	}
}
/**
 * pr_get_line - Read inpt from stream
 * @lptr: buffer that stores the input
 * @i: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t pr_get_line(char **lptr, size_t *i, FILE *stream)
{
	int n;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		n = read(STDIN_FILENO, &t, 1);
		if (n == -1 || (n == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (n == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = pr_realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	pr_bring_line(lptr, i, buffer, input);
	retval = input;
	if (n != 0)
		input = 0;
	return (retval);
}
