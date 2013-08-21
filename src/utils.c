#include <utils.h>

void error(const char* msg) {
    // Grab error message from OS
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

void *Malloc(size_t size) {
  void *ret = malloc(size);

  if(ret == NULL) {
    error("Memory Error!\n");
  }

  return ret;
}
