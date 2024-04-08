#ifndef _LIB_IMBD_H
#define _LIB_IMBD_H
#include "../private/actor.h"
#include "../private/file.h"
#include "../private/movie.h"
#include "../private/msgpack.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <uthash.h>

#define NUM_ACTORS 3110191
#define NUM_MOVIES 676520
#define MAX_COMB 89689271433378

// Loaders
void load_all(char *title_path, char *actor_path);
void add_to_visited(char *id);

// Helpers
const char *get_actor_id_by_name(char *name);
bool actor_starred_in_movie(Actor *actor, const char *movie_id);

#endif
