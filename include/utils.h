#ifndef _UTILS_H_
#define _UTILS_H_

// Put includes here for now, will move this later
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// For error handeling
#include <errno.h>
#include <string.h>

void error(const char* msg);
void* Malloc(size_t size);


#endif
