#ifndef ASCII_H
#define ASCII_H

#include <fstream>
#include "Bitmap.h"

const int types = 15;
char asciis[] = " .^~;nOQmX8%&@#"; // 13 types
int thresholds[] = {0, 20, 30, 35, 40, 60, 80, 100, 120, 130, 135, 140, 160, 180, 200, 256};

int index(double value) {
   for(int i=0; i<types; ++i) {
      if(thresholds[i]>value) {
         return i;
      }
   } return types-1;
}

double value(RGB rgb) {
   return (rgb.R + rgb.G + rgb.B)/3;
}

void translate(const Bitmap& bmp) {
   std::FILE* ascii = std::fopen("C:\\Users\\Sam\\Desktop\\cowie.txt", "w");

   double val_err = 0.0;
   for(int r=bmp.dims.height-1; r>=0; --r) {
      for(int c=0; c<bmp.dims.width; ++c) {
         val_err += value(bmp.data[r][c]);
         int ind = index(val_err);
         std::fputc(asciis[ind], ascii);
         //val_err -= (thresholds[ind+1]+thresholds[ind])/2;
         val_err=0.0;
      }
      std::fputc('\n', ascii);
   }

   fclose(ascii);
}

void stretch(const Bitmap& bmp, Bitmap& bmp2) {
   bmp2.allocate({bmp.dims.height/2, bmp.dims.width});
   for(int r=0; r<bmp.dims.height/2; ++r) {
      for(int c=0; c<bmp.dims.width; ++c) {
         bmp2.data[r][c].R = (bmp.data[2*r][c].R + bmp.data[2*r+1][c].R)/2;
         bmp2.data[r][c].G = (bmp.data[2*r][c].G + bmp.data[2*r+1][c].G)/2;
         bmp2.data[r][c].B = (bmp.data[2*r][c].B + bmp.data[2*r+1][c].B)/2;
      }
   }
}

#endif
