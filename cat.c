#include <sys/fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<inttypes.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(int argc, char **argv){
  uint8_t buf[4096];
  ssize_t nread;

  int fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    fprintf(stderr, "cannot open %s: %s¥n", argv[1], strerror(errno));
    exit(1);
  }

  while((nread = read(0,  buf, sizeof(buf))) > 0)
    write(1, buf, nread);
  return 0;

}
