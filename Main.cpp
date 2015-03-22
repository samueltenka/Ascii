#include "Bitmap.h"
#include "Ascii.h"

void main() {
   Bitmap BMP, BMP2;
   BMP.read_from("C:\\Users\\Sam\\Desktop\\lena.bmp");
   stretch(BMP, BMP2);
   BMP2.write_to("C:\\Users\\Sam\\Desktop\\lena_stretched.bmp");
   translate(BMP2);
}
