from clib import (
    get_actors_movies_getter,
    get_all_loader,
    get_actor_id_by_name_getter,
)
from constants import C_MOVIE_BIN_PATH, C_ACTOR_BIN_PATH

if __name__ == "__main__":
    load_all = get_all_loader()
    load_all(C_MOVIE_BIN_PATH, C_ACTOR_BIN_PATH)
    get_actor_id_by_name = get_actor_id_by_name_getter()
    a1 = get_actor_id_by_name('John Waters')
    a2 = get_actor_id_by_name('An Actor')
    print('Actor1 test successful' if a1 ==
          'nm0000691' else f'Actor 1 failed to get correct id, actual : {a1}')
    print('Actor2 test successful' if a2 ==
          'nm1453828' else f'Actor 2 failed to get correct id, actual : {a2}')
