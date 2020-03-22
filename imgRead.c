#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
   FILE *img = fopen("img.bmp", "rb");

   unsigned char info[54];
   fread(info, sizeof(unsigned char), 54, img); // read the 54-byte header

   // extract image height and width from header
   int imgWidth = *(int*)&info[18];
   int imgHeight = *(int*)&info[22];
   printf("Size: %d %d\n", imgWidth, imgHeight);
   
   int imgSize = imgWidth * imgHeight;
   unsigned char* data = (unsigned char*)malloc(3*imgSize*sizeof(unsigned char)); // allocate 3 bytes per pixel
   fread(data, sizeof(unsigned char), 3*imgSize, img); // read the rest of the data at once
   fclose(img);

}