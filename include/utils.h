#ifndef _UTILS_H_
#define _UTILS_H_

// Put includes here for now, will move this later
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// For error handeling
#include <errno.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BOOL int8_t

void print_error(const char* msg);
void fatalerror(const char* msg);

void* Malloc(size_t size);


#endif
