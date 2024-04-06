#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _LIB_IMDB_FILE_H
#define _LIB_IMDB_FILE_H

typedef struct {
  char *bytes;
  long size;
} file_content;

file_content read_file(FILE *file, char *path);
#endif
