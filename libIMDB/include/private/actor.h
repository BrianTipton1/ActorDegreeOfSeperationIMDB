#ifndef _ACTOR_H
#define _ACTOR_H
#include "../private/file.h"
#include "../private/msgpack.h"
#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <uthash.h>

typedef struct {
  const char *id;
  const char *name;
  Movie **movies;
  uint32_t movie_count;
  UT_hash_handle hh;
} Actor;

extern Actor *actors;

void load_actors(char *actor_path);
void add_actor(msgpack_object_str *name, msgpack_object_str *id,
               msgpack_object_array *movies);
Actor *get_actor_by_id(const char *id);
char **get_actors_movie_ids_by_id(const char *id);
Actor *get_actor_by_name(const char *name);

#endif
