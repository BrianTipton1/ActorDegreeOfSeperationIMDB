#include "file.h"
#include <msgpack/unpack.h>

#ifndef _LIB_IMDB_MSGPACK_H
#define _LIB_IMDB_MSGPACK_H

typedef struct {
  msgpack_unpack_return ret;
  msgpack_unpacked result;
} msg_pack_result;

msg_pack_result get_msgpack_res(file_content f);
#endif
