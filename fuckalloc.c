#include <errno.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	errno = ENOMEM;
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	errno = ENOMEM;
	return NULL;
}

void *realloc(void *ptr, size_t size)
{
	errno = ENOMEM;
	return NULL;
}
