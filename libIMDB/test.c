#include "./include/public/imdb.h"
#include <assert.h>
#include <stdio.h>

#define ACTORS_MSG_PACK                                                        \
  "/home/brian/Documents/School/CS456/CA5/data/msgpack/actors.msgpack"
#define MOVIES_MSG_PACK                                                        \
  "/home/brian/Documents/School/CS456/CA5/data/msgpack/movies.msgpack"

void test_movie_getter() {
  Movie *movie1 = get_movie_by_id("tt0002746");
  assert(strcmp(movie1->title, "Checkers") == 0);
  printf("Title: %s, Id: %s. OKAY\n", movie1->title, movie1->id);
  ///

  Movie *movie2 = get_movie_by_id("tt9916754");
  assert(strcmp(movie2->title, "Chico Albuquerque - Revelações") == 0);
  printf("Title: %s, Id: %s. OKAY\n", movie2->title, movie2->id);
}

int main() {
  load_movies(MOVIES_MSG_PACK);
  test_movie_getter();
}
