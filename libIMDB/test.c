#include "./include/public/imdb.h"
#include <assert.h>
#include <stdio.h>
void start_yellow() { printf("\x1b[33m"); }
void start_green() { printf("\x1b[32m"); }
void start_red() { printf("\x1b[31m"); }
void reset_color() { printf("\x1b[0m"); }

#define ACTORS_MSG_PACK                                                        \
  "/home/brian/Documents/School/CS456/CA5/data/msgpack/actors.msgpack"
#define MOVIES_MSG_PACK                                                        \
  "/home/brian/Documents/School/CS456/CA5/data/msgpack/movies.msgpack"

void test_actor_getter() {
  start_yellow();
  printf("--------------RUNNING ACTOR TESTS--------------\n");
  reset_color();

  Actor *actor1 = get_actor_by_id("nm0000691");

  start_red();
  assert(strcmp(actor1->name, "John Waters") == 0);
  reset_color();

  start_green();
  printf("Actor: %s, Id: %s. OKAY\n", actor1->name, actor1->id);
  reset_color();

  Actor *actor2 = get_actor_by_id("nm9993704");

  start_red();
  assert(strcmp(actor2->name, "Wojciech Kolodziej") == 0);
  reset_color();

  start_green();
  printf("Actor: %s, Id: %s. OKAY\n", actor2->name, actor2->id);
  reset_color();

  start_yellow();
  printf("--------------END ACTOR TESTS--------------\n");
  reset_color();
}

void test_movie_getter() {
  start_yellow();
  printf("--------------RUNNING MOVIE TESTS--------------\n");
  reset_color();

  Movie *movie1 = get_movie_by_id("tt0002746");

  start_red();
  assert(strcmp(movie1->title, "Checkers") == 0);
  reset_color();

  start_green();
  printf("Title: %s, Id: %s. OKAY\n", movie1->title, movie1->id);
  reset_color();

  Movie *movie2 = get_movie_by_id("tt9916754");

  start_red();
  assert(strcmp(movie2->title, "Chico Albuquerque - Revelações") == 0);
  reset_color();

  start_green();
  printf("Title: %s, Id: %s. OKAY\n", movie2->title, movie2->id);
  reset_color();

  start_yellow();
  printf("--------------END MOVIE TESTS--------------\n");
  reset_color();
}

int main() {
  load_movies(MOVIES_MSG_PACK);
  test_movie_getter();
  printf("\n");
  load_actors(ACTORS_MSG_PACK);
  test_actor_getter();
}
