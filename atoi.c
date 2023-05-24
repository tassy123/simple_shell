#include "shell.h"
#include <stdlib.h>

/**
* _atoi - converts a string to an integer
* @r: The string to convert
* Return: The integer value of the string.
*/

int _atoi(const char *r)
{
int p, s = 1, res = 0, u;
unsigned int e = 0;
for (p = 0; r[p] != '\0' && res != 2; p++)
{
if (r[p] == '-')
s *= -1;
if (r[p] >= '0' && r[p] <= '9')
{
res = 1;
e = e * 10 + (r[p] - '0');
}
else if (res == 1)
{
res = 2;
}
}
u = (s == -1) ? -e : e;
return (u);
}

/**
* _realloc - reallocates a block of memory
* @ptr: Pointer to the memory previously allocated
* @old_size: byte size of old memory block
* @new_size: byte size of new memory block
* Return: Pointer to the reallocated memory block
*/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
if (new_size == old_size)
return (ptr);
if (ptr == NULL)
{
void *new_ptr = malloc(new_size);
return (new_ptr);
}
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
void *new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);
char *src = ptr;
char *dest = new_ptr;
size_t s;
for (s = 0; s < old_size; s++)
dest[s] = src[s];
free(ptr);
return (new_ptr);
}

/**
* _memset - fills memory with a constant byte
* @s: A pointer to the memory area to be filled.
* @c: the byte to be filled  with
* @n: the amount of bytes to be filled
* Return: (s) a pointer to the memory area s
*/
void *_memset(void *s, int c, size_t n)
{
unsigned int index;
unsigned char *memory = s;
unsigned char value = (unsigned char)c;
for (size_t index = 0; index < n; index++)
memory[index] = value;
return (s);
}

/**
* _memcpy - function that copies memory area
* @dest: buffer where to copy to
* @src: what code to copy
* @n: how many bytes to copy
* Return: Always 0 (success)
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int t;
for (t = 0; t < n; t++)
{
dest[t] = src[t];
}
return (dest);
}

/**
* _calloc - a function that allocates memory
*it is basically the equivalent to
*malloc followed by memset
* @nmemb: size of array
* @size: size of each element
* Return: pointer with new allocated memory
*or NULL if it fails
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
if (nmemb == 0 || size == 0)
return (NULL);
void *ptr = malloc(nmemb * size);
if (ptr == NULL)
return (NULL);
_memset(ptr, 0, nmemb * size);
return (ptr);
}
