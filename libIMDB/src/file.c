#include "../include/private/file.h"

file_content read_file(FILE *file, char *path) {
  file = fopen(path, "rb");
  if (file == NULL) {
    printf("Err couldn't read file.... exiting\n");
    exit(1);
  }

  fseek(file, 0L, SEEK_END);
  long size = ftell(file);
  fseek(file, 0L, SEEK_SET);
  printf("FILE: '%s' has size of: %li bytes\n", basename(path), size);
  char *bytes = (char *)malloc(size);

  fread(bytes, sizeof(char), size, file);
  fclose(file);
  file_content fc;
  fc.bytes = bytes;
  fc.size = size;
  return fc;
}
