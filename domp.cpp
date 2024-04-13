#include"etc.h"
#include <fstream>
#include <sys/stat.h>
#include <iosfwd>
#include <stdint.h>
#include <cstddef>

void decompress( std::string i,std::string o){
    printf("decompressing\n");
    std::ifstream input(o.c_str(), std::ios::out);
    int seed=92;
    int offset=1652;
    int bytes=6;
    
    char bs[bytes];
    srand(seed);
    while (offset>=0){offset--;rand()%256;}
    for (int i=0;i<=bytes;i++){
        bs[i]=rand()%256;
        
    }
    
    printf("%s",bs);
}