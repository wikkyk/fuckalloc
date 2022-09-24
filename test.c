#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *ret;

	errno = 0;
	ret = malloc(42);
	if(ret){
		puts("malloc did not return NULL");
		return 1;
	}
	if(errno != ENOMEM){
		puts("malloc did not set errno to ENOMEM");
		return 1;
	}

	errno = 0;
	ret = calloc(69, 42);
	if(ret){
		puts("calloc did not return NULL");
		return 1;
	}
	if(errno != ENOMEM){
		puts("calloc did not set errno to ENOMEM");
		return 1;
	}

	errno = 0;
	ret = realloc(ret, 42);
	if(ret){
		puts("realloc did not return NULL");
		return 1;
	}
	if(errno != ENOMEM){
		puts("realloc did not set errno to ENOMEM");
		return 1;
	}

	puts("ok");
}
