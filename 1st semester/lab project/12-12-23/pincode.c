#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define PINFILE "myPinCode.bin"

typedef struct { uint8_t a, b, c, d; } Pin_Code_t;

int main(int argc, const char** argv) {
  FILE *fp;
  Pin_Code_t pc;

  // write pin
  if (argc > 1) {
    if (argc != 5) {
      printf("Need 4 ints to write a new pin!\n");
      exit(1);
    }

    pc.a = atoi(argv[1]);
    pc.b = atoi(argv[2]);
    pc.c = atoi(argv[3]);
    pc.d = atoi(argv[4]);

    if ((fp = fopen(PINFILE, "wb")) == NULL) { 
      perror("Error in creating file");
      exit(2);
    }

    // write one Pin_Code_t object pc to the file *fp
    fwrite(&pc, sizeof(Pin_Code_t), 1, fp);  

    fclose(fp);
    printf("Pin saved.\n");
    return 0;
  }

  // else read existing pin
  if ((fp = fopen(PINFILE, "rb")) == NULL) { 
    perror("Error in reading file");
    exit(3);
  }

  // read one Pin_Code_t object pc from the file *fp
  fread(&pc, sizeof(Pin_Code_t), 1, fp);
  fclose(fp);

  printf("Pin: ");
  printf("%hhu ", pc.a);
  printf("%hhu ", pc.b);
  printf("%hhu ", pc.c);
  printf("%hhu\n", pc.d);
  return 0;
}
