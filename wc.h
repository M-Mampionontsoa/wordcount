#include <stdio.h>
void Open_File(FILE **file,int argc,char *argv[]);
void wc(FILE *file) ;
void Option_l(FILE *file);
void Option_w(FILE *file);
void Option_m(FILE *file);
void Option_c(FILE *file);
void Option_L(FILE *file);
void option(FILE *file,int argc,char *argv[]);
void Close_File(FILE *file);