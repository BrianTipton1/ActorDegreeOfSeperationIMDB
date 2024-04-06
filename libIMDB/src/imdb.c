#include "../include/public/imdb.h"

Movie *movies = NULL;

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

Movie *get_movie_by_id(char *id) {
  Movie *movie;
  HASH_FIND_STR(movies, id, movie);
  return movie;
}
