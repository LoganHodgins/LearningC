#include <stdio.h>
#include <stdlib.h>

// Memory returned will need to be freed by caller
char *readline(FILE *fp) {
  int offset = 0;
  int bufsize = 4;

  char *buf;
  int c;

  buf = malloc(bufsize);

  if (buf == NULL) // Error check
    return NULL;

  // read until newline or EOF
  while (c = fgetc(fp), c != '\n' && c != EOF) {
    // check if we're out of room in the buffer accounting
    // for the extra byte for the NUL terminator
    if (offset == bufsize - 1) {
      bufsize *= 2;

      char *new_buf = realloc(buf, bufsize);

      if (new_buf == NULL) {
        free(buf); // On error, free and bail
        return NULL;
      }

      buf = new_buf;
    }

    buf[offset++] = c; // Add the byte onto buffer
  }

  // We hit newline or EOF
  if (c == EOF && offset == 0) {
    free(buf);
    return NULL;
  }

  // Shrink to fit
  if (offset < bufsize - 1) {
    char *new_buf = realloc(buf, offset + 1);

    if (new_buf != NULL)
      buf = new_buf;
  }

  // Add the NUL terminator
  buf[offset] = '\0';

  return buf;
}

int main(void) {
  FILE *fp = fopen("foo.txt", "r");

  char *line;

  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line);
  }

  fclose(fp);
}