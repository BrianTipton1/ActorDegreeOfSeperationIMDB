#include "../include/public/imdb.h"

void load_all(char *title_path, char *actor_path) {
  load_movies(title_path);
  load_actors(actor_path);
}

const char *get_actor_id_by_name(char *name) {
  Actor *actor;
  actor = get_actor_by_name(name);
  return actor->id;
}

bool actor_starred_in_movie(Actor *actor, const char *movie_id) {
  for (uint32_t i = 0; i < actor->movie_count; ++i) {
    if (strcmp(actor->movies[i]->id, movie_id) == 0) {
      return true;
    }
  }
  return false;
}
