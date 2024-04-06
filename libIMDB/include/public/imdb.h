#include "../private/file.h"
#include "../private/msgpack.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <uthash.h>

#ifndef _LIB_IMBD_H
#define _LIB_IMBD_H

#define NUM_ACTORS 13393228
#define NUM_MOVIES 676520
#define MAX_TITLE_LENGTH 100
#define MAX_ID_LENGTH 20
#define MAX_NAME_LENGTH 100

typedef struct {
  char *title;
  char *id;
  UT_hash_handle hh;
} Movie;

typedef struct {
  const char *id;
  const char *name;
  Movie **movies;
  UT_hash_handle hh;
} Actor;

void load_movies(char *title_path);
void add_movie(msgpack_object_str *title, msgpack_object_str *id);
Movie *get_movie_by_id(char *id);

// void load_actors(char *actor_path);
#endif
