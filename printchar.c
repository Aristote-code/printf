#include "main.h"
#include <unistd.h>

/**
  * printchar - Writes the character s to stdout
  * @s: Character to write
  *
  * Return: 1 on success, -1 on error.
  */
int printchar(char s)
{
	return (write(1, &s, 1));
}
