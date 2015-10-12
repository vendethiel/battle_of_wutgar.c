#include "main.h"

void* xmalloc(size_t size) {
  void* ptr = malloc(size);
  if (!ptr) {
    error_fatal("Malloc failed\n");
  }
  return ptr;
}

void	error_fatal(char *msg)
{
	printf(COLOR_RED "%s", msg);
	exit(1);
}
