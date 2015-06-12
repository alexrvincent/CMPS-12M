// $Id: catbyline.c,v 1.4 2013-04-23 18:29:11-07 - - $

//
// NAME
//    catbyline - example of simple cat to display files
//
// SYNOPSIS
//    catbyline [filename...]
//
// DESCRIPTION
//    Uses fgets to read lines from files and prints to stdout.
//    If no filenames are specified, reads stdin.  Does not consider
//    whether input buffer is too short.
//

#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *program_name = NULL;
int exit_status = EXIT_SUCCESS;
#define STDIN_NAME "-"

typedef int bool;
#define true 1;
#define false 0;

typedef struct options {
    bool ignore_case;
    bool filenames_only;
    bool number_lines;
    } options;

void scan_options (int argc, char **argv, options *opts){
    opts -> ignore_case = false;
    opts -> filenames_only = false;
    opts -> number_lines = false;
    opterr = false;
        for (;;) {
        int opt = getopt (argc, argv, "ilm");
        if (opt == EOF) break;
        switch(opt) {
        case 'i':
            opts -> ignore_case = true;
            break;
        case 'l':
            opts->filenames_only = true;
            break;
        case 'm':
            opts->number_lines = true;
            break;

        default:
            exit_status = EXIT_FAILURE;
            fflush((NULL));
            fprintf(stderr, "%s: -%c: invalid option\n",
                     program_name, opt);
            break;
        }
    }
}

const char *strbool (bool value){
    return value ? "true" : "false";
}

void catbyline (FILE *input, char *filename) {
   char buffer[1024]; //create a string buffer
   printf ("FILE %s:\n", filename); //print the file name
   for (int linenr = 1;; ++linenr) { //for every line in the file
      char *buf = fgets (buffer, sizeof buffer, input);//(where str is stored, # of chars to be read, where to read from
      //^ returns the same buffer file, but stores it in a char pointer
      if (buf == NULL) break;
      printf ("%6d: %s", linenr, buf); //print the linenumber and the line
   }
}

int main (int argc, char **argv) {
   options opts;
   program_name = basename (argv[0]);
   if (argc == 1) { //if no files, read from keyboard
      catbyline (stdin, STDIN_NAME);
   }else {
      for (int argi = 1; argi < argc; ++argi) { //for every file listed
         char *filename = argv[argi];// make a filename point to the option
         if (strcmp (filename, STDIN_NAME) == 0) {//if the filename is '-'
            catbyline (stdin, STDIN_NAME);// read from keyboard
         }else {
            FILE *input = fopen (filename, "r"); //create a pointer to the file in reading mode
            if (input != NULL) { //if input points at something
               catbyline (input, filename); //perform catbyline on the input
               fclose (input);
            }else {
               exit_status = EXIT_FAILURE; //otherwise quit the program
               fflush (NULL);
               fprintf (stderr, "%s: %s: %s\n", program_name,
                        filename, strerror (errno));
               fflush (NULL);
            }
         }
      }
   }
   return exit_status;
}
