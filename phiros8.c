#include "main.h"

/**
 * get_len - Get the lenght of the number.
 * @n: the type int number.
 * Return: the lenght of the number.
 */
int get_len(int n)
{
	unsigned int n1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}
/**
 * aux_itoa - function changes int to string.
 * @n: the type int number
 * Return: a String.
 */
char *aux_itoa(int n)
{
	unsigned int n1;
	int lenght = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - changes a string to an integer.
 * @s: the input string.
 * Return: an integer.
 */
int _atoi(char *s)
{
	unsigned int tally = 0, size = 0, oi = 0, pn = 1, m = 1, r;

	while (*(s + tally) != '\0')
	{
		if (size > 0 && (*(s + tally) < '0' || *(s + tally) > '9'))
			break;

		if (*(s + tally) == '-')
			pn *= -1;

		if ((*(s + tally) >= '0') && (*(s + tally) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		tally++;
	}

	for (r = tally - size; r < tally; r++)
	{
		oi = oi + ((*(s + r) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
