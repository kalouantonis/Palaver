#include <utils.h>

void print_error(const char* msg) {
    // Grab error message from OS
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

void fatalerror(const char* msg) {
    print_error(msg);

    // Exit the program with return code of 1
    // 
    // TODO: Add global cleanup routines 
    exit(1);
}

void *Malloc(size_t size) {
  void *ret = malloc(size);

  if(ret == NULL) {
      // Memory allocation problems should be fatal
      fatalerror("Memory error");
  }

  return ret;
}
