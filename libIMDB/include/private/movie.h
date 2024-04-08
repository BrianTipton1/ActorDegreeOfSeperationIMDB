
#ifndef _MOVIE_H
#define _MOVIE_H
#include "../private/file.h"
#include "../private/msgpack.h"
#include <msgpack/object.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <uthash.h>
typedef struct {
  char *title;
  char *id;
  UT_hash_handle hh;
} Movie;

extern Movie *movies;

void load_movies(char *title_path);
void add_movie(msgpack_object_str *title, msgpack_object_str *id);
Movie *get_movie_by_id(const char *id);

#endif
