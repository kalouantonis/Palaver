#include <process_arguments.h>

int main(int argc, char** argv)
{
    struct options* opts = processOptions(argc, argv);

    printf("Filename: %s\nSpeech: %s\nStarting Line: %i\nVariables: %s\n", 
            opts->filename, opts->speech, opts->startingLine, opts->variables);

    return 0;
}
