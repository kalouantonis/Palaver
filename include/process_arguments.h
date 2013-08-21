#ifndef _PROCESS_ARGUMENTS_H_
#define _PROCESS_ARGUMENTS_H_

#include <utils.h>

struct options {
  char *filename;  // Filename OR buffer are set, not both. 
  char *buffer;    // If both are, then buffer takes presedence.
  char *speech;     // Speech gathered from espeak?
  int startingLine; 
  int listPartialMatchesP;
  char *variables;  // Other variables captured from the command line
  int syntaxCheckOnlyP;
};

struct options* processOptions(int argc, char** argv);

#endif
