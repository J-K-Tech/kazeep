#include"etc.h"
#include <fstream>
#include <sys/stat.h>
#include <iosfwd>
#include <stdint.h>
#include <cstddef>
#include<chrono>
#include <iostream>
#include <thread>
int tps=0;
bool cantchange=false;
const int c(int a){return a;}

typedef struct inst{
    int seed;
    int offset;
    int bytes;
} instruction;
instruction generate(int bytes,char bit[]){
    int seed=100;
  time_t seconds;

  seconds = time (NULL);
    instruction inn;
    while(true){
        int correct=0;
        int skip=0;
        while (skip<200000){
            tps++;
            if (seconds!=time(NULL)){seconds=time(NULL);
            printf("tps:%i",tps);tps=0;}
            if(rand()%256==bit[correct]){
                correct++;
                if(correct>=bytes){
                    printf("%s",bit);
                    inn.offset=skip;inn.seed=seed;inn.bytes=bytes;
                    return inn;
                }
            }
            else{
                correct=0;
            skip++;}
        }
        seed++;
        srand(seed);
    }
}
void compress(int bytes, std::string i,std::string o){
    
    int filesize;
    if (true){
    struct stat s;
    if (stat(i.c_str(), &s)) {exit(4);}
    filesize=s.st_size;}
    printf("\n%i\n",filesize);
    if (filesize<bytes){bytes=filesize;
    std::ifstream input(i.c_str(), std::ios::in);
    input.unsetf(std::ios::skipws);
    char file[filesize];
    input.read(file,filesize);
    input.close();
    instruction i=generate(bytes,file);
    printf("seed: %i\noffset: %i\nbytes: %i",i.seed,i.offset,i.bytes);LB
    }
}