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

typedef struct {
  char *title;
  char *id;
  UT_hash_handle hh;
} Movie;

typedef struct {
  const char *id;
  const char *name;
  Movie **movies;
  uint32_t movie_count;
  UT_hash_handle hh;
} Actor;

// Movie defs
void load_movies(char *title_path);
void add_movie(msgpack_object_str *title, msgpack_object_str *id);
Movie *get_movie_by_id(const char *id);

/// Actor Defs
void load_actors(char *actor_path);
void add_actor(msgpack_object_str *name, msgpack_object_str *id,
               msgpack_object_array *movies);
Actor *get_actor_by_id(const char *id);
#endif
