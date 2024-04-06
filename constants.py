from os import path

PROJECT_PATH = path.realpath(path.dirname(__file__))
C_LIB_PATH = path.join(PROJECT_PATH, 'libIMDB', 'libIMDB.so')
ACTOR_TSV_PATH = path.join(PROJECT_PATH, 'data', 'raw', 'name.basics.tsv')
MOVIE_TSV_PATH = path.join(PROJECT_PATH, 'data', 'raw', 'title.basics.tsv')

ACTOR_BIN_PATH = path.join(PROJECT_PATH, 'data', 'msgpack', 'actors.msgpack')
MOVIE_BIN_PATH = path.join(PROJECT_PATH, 'data', 'msgpack', 'movies.msgpack')

C_ACTOR_TSV_PATH = ACTOR_TSV_PATH.encode('utf-8')
C_MOVIE_TSV_PATH = MOVIE_TSV_PATH.encode('utf-8')

C_ACTOR_BIN_PATH = ACTOR_BIN_PATH.encode('utf-8')
C_MOVIE_BIN_PATH = MOVIE_BIN_PATH.encode('utf-8')
