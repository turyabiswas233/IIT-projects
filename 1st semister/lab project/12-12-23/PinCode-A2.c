#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PINFILE "myPinCode.bin"

int main(int argc, const char** argv) {
  int i;
  FILE *fp;
  uint8_t pc[4];

  // write pin
  if (argc > 1) {
    if (argc != 5) {
      printf("Need 4 ints to write a new pin!\n");
      exit(1);
    }

    for (i=0; i<4; i++) pc[i] = atoi(argv[i+1]);

    if ((fp = fopen(PINFILE, "wb")) == NULL) { 
      perror("Error in creating file");
      exit(2);
    }

    fwrite(pc, sizeof(pc), 1, fp);  

    fclose(fp);
    printf("Pin saved.\n");
    return 0;
  }

  // else read existing pin
  if ((fp = fopen(PINFILE, "rb")) == NULL) { 
    perror("Error in reading file");
    exit(3);
  }

  fread(pc, sizeof(pc), 1, fp);  
  fclose(fp);

  printf("Pin: ");
  for (i=0; i<4; i++) printf("%hhu ", pc[i]);
  printf("\n");
  return 0;
}
