#include <stdio.h>
#include "wc.h"
#include "wc.c"


int main(int argc,char *argv[])
{
    FILE *file=NULL;
    Open_File(&file,argc,argv);
    option(file,argc,argv);
    Close_File(file);

    return (0);
}
