#include "../include/private/msgpack.h"

msg_pack_result get_msgpack_res(file_content f) {
  msgpack_unpacked result;
  msgpack_unpacked_init(&result);
  size_t off = 0;
  msgpack_unpack_return ret =
      msgpack_unpack_next(&result, f.bytes, f.size, &off);
  msg_pack_result mpr;
  mpr.ret = ret;
  mpr.result = result;
  return mpr;
}
