import ctypes
from constants import C_MOVIE_BIN_PATH, C_LIB_PATH, C_ACTOR_BIN_PATH

C_LIB = ctypes.CDLL(C_LIB_PATH)

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


def get_movie_loader():
    C_LIB.load_movies.argtypes = [ctypes.c_char_p]
    return lambda x: C_LIB.load_movies(x)


def get_actor_loader():
    C_LIB.load_actors.argtypes = [ctypes.c_char_p]
    return lambda x: C_LIB.load_actors(x)


if __name__ == "__main__":
    movie_loader = get_movie_loader()
    # actor_loader = get_actor_loader()
    movie_loader(C_MOVIE_BIN_PATH)
    # actor_loader(C_ACTOR_BIN_PATH)
