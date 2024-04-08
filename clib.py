import ctypes
from typing import Callable, Generator, List
from constants import C_LIB_PATH

C_LIB = ctypes.CDLL(C_LIB_PATH)

ActorId = str
MovieId = str

"""
ONE ROW FROM ACTOR
[
'nm0000006',
'Ingrid Bergman',
'1915',
'1982',
'actress,producer,soundtrack',
'tt0034583,tt0036855,tt0038109,tt0038787'
]
"""

"""
ONE ROW FROM MOVIE
[
'tt0000005',
'short',
'Blacksmith Scene',
'Blacksmith Scene',
'0',
'1893',
'\\N',
'1',
'Comedy,
Short'
]
"""


def get_actor_id_by_name_getter():
    C_LIB.get_actor_id_by_name.restype = ctypes.c_char_p
    return lambda name: C_LIB.get_actor_id_by_name(name.encode()).decode()


def get_actors_movies_getter():
    C_LIB.get_actors_movie_ids_by_id.argtypes = [ctypes.c_char_p]
    C_LIB.get_actors_movie_ids_by_id.restype = ctypes.POINTER(
        ctypes.POINTER(ctypes.c_char))

    def get_actor_movie_ids(actor_id):
        actor_id_c = ctypes.c_char_p(actor_id.encode('utf-8'))
        movie_ids_ptr = C_LIB.get_actors_movie_ids_by_id(actor_id_c)
        i = 0
        while movie_ids_ptr[i]:
            movie_str_ptr = movie_ids_ptr[i]
            movie_id = ctypes.cast(
                movie_str_ptr, ctypes.c_char_p).value.decode('utf-8')
            yield movie_id
            i += 1

    return get_actor_movie_ids


def get_all_loader():
    C_LIB.load_all.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
    return (lambda
            title_path,
            actor_path: (C_LIB.load_all(title_path, actor_path)))
