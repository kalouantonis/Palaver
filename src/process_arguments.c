#include <process_arguments.h>

struct options *newOpts() {
  struct options *ret = (struct options*)Malloc(sizeof(struct options));
  ret->filename = NULL;
  ret->buffer = NULL;
  ret->speech = NULL;
  ret->startingLine = -1;
  ret->listPartialMatchesP = 0;
  ret->variables = NULL;
  ret->syntaxCheckOnlyP = 0;

  return ret;
}

struct options* processOptions(int argc, char** argv)
{
    struct options *opts = newOpts();
    int opt;

    // In this we will process arguments.
    // And options.

    // List of arguments and options.
    // -f dictionary.dic
    // -s "speech input"
    // -l 0 // line to start on
    // -p // list partial matches. (default 3).
    // -n 10 // list n partial matches.
    // -v "dog=cat;aaa=123" // specify variables to be set if a match is found.
    // -cf dictionary.dic // Do a pure syntax check

    // Also from here the env will be checked for PALVER_variable

    while((opt = getopt(argc,argv, "cpf:s:l:n:v:")) != -1) {
        switch (opt) {
        case 'c':
            opts->syntaxCheckOnlyP = 1;
            break;
        case 'p':
            opts->listPartialMatchesP = 1;
            break;
        case 'f':
            opts->filename = optarg;
            break;
        case 's':
            opts->speech = optarg;
            break;
        case 'v':
            opts->variables = optarg;
            break;
        }
    }

    return opts;
}
