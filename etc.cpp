#include"etc.h"


void help(){

    printf("please just use this thing files\nfor now there is no support for folders\n\
    so you might want to zip the folder first (just store is enough, so you wont waste time)");
    LB LB
    printf("-h or --help or empty or wrong to see this");LB
    printf("-c to compress");LB
    printf("-d to decompress");LB
    printf("-o output file");LB
    printf("-b size of target chunks in bits (standard: 2048), the higher the more compressed but slower to compress");LB
    printf("example: kzip -c thicc -o thin.kz"); LB
    printf("other example: kzip -d thin.kz -o thicc");
    LB LB
}