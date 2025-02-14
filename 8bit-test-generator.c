#include <stdio.h>

/**
 * @brief Convert a decimal number to a binary string.
 *        Overflow will result in concatenation.
 * 
 * @param num 
 *    The decimal number.
 * @param size 
 *    The size of the string.
 * @param bits 
 *   The string to write to. 
 */
void decimalToBinaryString(int num, unsigned char size, char* bits) {

  for (int i = size - 1; i >= 0; i--) {
    int pos = -(i - size + 1); 

    if ((num >> i) & 1) {
      bits[pos] = '1';
    } else {
      bits[pos] = '0';
    } // if/else
  } // for

  bits[size] = '\0';
}

int main() {
  unsigned char size = 8;
  char bits1[size];
  char bits2[size];


  FILE* f = fopen("file.txt", "w");
  if (f == NULL) {
    printf("Error opening file\n");
    return(1);
  }

  fprintf(f, "x1[8]     x2[8]     co s[8]\n");
  for (int x = 0; x < 256; x++) {
    decimalToBinaryString(x, size, bits1);
    for (int y = 0; y < 256; y++) {
      fprintf(f, "%s", bits1);
      fprintf(f, "  ");
      decimalToBinaryString(y, size, bits2);
      fprintf(f, "%s", bits2);
      fprintf(f, "  ");
      if (x + y > 255) {
        fprintf(f, "1");
      } else {
        fprintf(f, "0");
      }
      fprintf(f, "  ");
      decimalToBinaryString(x + y, size, bits2);
      fprintf(f, "%s\n", bits2);
    }
  }
  
  fclose(f);
}
