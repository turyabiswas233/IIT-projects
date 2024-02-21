#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct Rec_Hdr2_s
{
  uint32_t fld1;
  uint16_t fld2;
  uint8_t fld3;
} Rec_Hdr2_t;

int main(void)
{
  int i;
  unsigned int j, k = 0x1;
  uint8_t data[100];
  FILE *fp;
  Rec_Hdr2_t rh;

  // printf("size of rh = %ld\n",sizeof(rh));
  if ((fp = fopen("DataFile.bin", "wb")) == NULL)
  {
    perror("DataFile.bin");
    exit(1);
  }

  for (i = 0; i < 5; i++)
  {
    j = k << (i * 4);
    rh.fld1 = (uint32_t)2 * j;
    rh.fld2 = (uint32_t)j;
    rh.fld3 = (uint32_t)i + 1;
    fwrite(&rh, sizeof(rh), 1, fp);
  }

  fclose(fp);
  return 0;
}
