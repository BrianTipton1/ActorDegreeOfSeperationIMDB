#include "../include/public/imdb.h"

Movie *movies = NULL;
Actor *actors = NULL;

#pragma region MOVIE_REGION

void add_movie(msgpack_object_str *title, msgpack_object_str *id) {
  Movie *movie = malloc(sizeof(Movie));
  if (movie == NULL) {
    return;
  }
  movie->title = strndup(title->ptr, title->size);
  movie->id = strndup(id->ptr, id->size);
  HASH_ADD_KEYPTR(hh, movies, movie->id, strlen(movie->id), movie);
}

void load_movies(char *title_path) {
  FILE *f = fopen(title_path, "r");
  if (f == NULL) {
    return;
  }

  file_content fc = read_file(f, title_path);
  fclose(f);

  msg_pack_result msgp_res = get_msgpack_res(fc);
  if (msgp_res.ret == MSGPACK_UNPACK_SUCCESS) {
    if (msgp_res.result.data.type == MSGPACK_OBJECT_ARRAY) {
      const msgpack_object_array *movieList = &msgp_res.result.data.via.array;
      for (uint32_t i = 0; i < movieList->size; i++) {
        const msgpack_object_array *row = &movieList->ptr[i].via.array;
        if (row->size == 2) {
          msgpack_object_str id = row->ptr[0].via.str;
          msgpack_object_str title = row->ptr[1].via.str;
          add_movie(&title, &id);
        } else {
          printf("Invalid Row size of: %d\n", row->size);
        }
      }
    }
  }

  msgpack_unpacked_destroy(&msgp_res.result);
  free(fc.bytes);
}

Movie *get_movie_by_id(const char *id) {
  Movie *movie;
  HASH_FIND_STR(movies, id, movie);
  return movie;
}

#pragma endregion MOVIE_REGION

#pragma region ACTOR_REGION

void load_actors(char *actor_path) {
  FILE *f = fopen(actor_path, "r");
  if (f == NULL) {
    return;
  }

  file_content fc = read_file(f, actor_path);
  fclose(f);

  msg_pack_result msgp_res = get_msgpack_res(fc);
  if (msgp_res.ret == MSGPACK_UNPACK_SUCCESS) {
    if (msgp_res.result.data.type == MSGPACK_OBJECT_ARRAY) {
      const msgpack_object_array *actor_list = &msgp_res.result.data.via.array;

      for (uint32_t i = 0; i < actor_list->size; i++) {

        const msgpack_object_array *row = &actor_list->ptr[i].via.array;

        if (row->size == 3) {
          msgpack_object_str id = row->ptr[0].via.str;
          msgpack_object_str title = row->ptr[1].via.str;
          msgpack_object_array starred_in = row->ptr[2].via.array;
          add_actor(&title, &id, &starred_in);
        } else {
          printf("Invalid Row size of: %d\n", row->size);
        }
      }
    }
  }

  msgpack_unpacked_destroy(&msgp_res.result);
  free(fc.bytes);
}

void add_actor(msgpack_object_str *name, msgpack_object_str *id,
               msgpack_object_array *starred_in) {

  Actor *actor = malloc(sizeof(Actor));
  actor->movies = malloc(sizeof(Movie *) * starred_in->size);
  actor->movie_count = starred_in->size;

  if (actor == NULL) {
    return;
  }
  actor->name = strndup(name->ptr, name->size);
  actor->id = strndup(id->ptr, id->size);
  for (uint32_t i = 0; i < starred_in->size; i++) {
    const char *movie_id = strndup(starred_in->ptr[i].via.str.ptr,
                                   starred_in->ptr[i].via.str.size);
    actor->movies[i] = get_movie_by_id(movie_id);
    free((char *)movie_id);
  }
  HASH_ADD_KEYPTR(hh, actors, actor->id, strlen(actor->id), actor);
}

Actor *get_actor_by_id(const char *id) {
  Actor *actor;
  HASH_FIND_STR(actors, id, actor);
  return actor;
}

#pragma endregion ACTOR_REGION
