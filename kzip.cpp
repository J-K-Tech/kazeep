#include"etc.h"
int command=-1;
int bits=256;
std::string input;
std::string output;
int main(int argv,char*argc[]){LB

    printf("kzip alpha 0-0 0.0 0_0\
\nthe ultimate compression algorithm\
\nthat can make anything down to 16 bytes\
\nif u got patience to compress it enough ofc\n\n");

    if (!argc[1]){help();printf("\n\nno args\n\n");exit(1);}
    else{
        int aftercmd=-1;
        bool alreadyout=false;
        bool alreadyb=false;
        for (int ii=1;ii<argv;ii++){
        std::string i=argc[ii];
        LB printf(i.c_str());LB
        
            switch (aftercmd)
            {
                
            case 0:
                input=i;
                aftercmd=-1;
                break;
                
            case 1:
                output=i;
                aftercmd=-1;
                break;
                
            case 2:
                bits=atoi(i.c_str());
                aftercmd=-1;
                break;
                
            default:
                if (i=="hi"){
                    printf("fuck you\n\n");
                }
                else if(i=="-c"){
                    if (command==-1){command=0;}else{help();exit(3);}
                    aftercmd=0;
                }
                else if(i=="-d"){
                    if (command==-1){command=1;}else{help();exit(3);}
                    aftercmd=0;
                }
                else if(i=="-o"){
                    if (!alreadyout){alreadyout=true;}else{help();exit(3);}
                    aftercmd=1;
                }
                else if(i=="-b"){
                    if (!alreadyb){alreadyb=true;}else{help();exit(3);}
                    aftercmd=2;
                }
                
                else{
                    help();exit(2);
                }
                break;
            }
        }}
    if (command==0){
        compress(bits,input,output);
    }
    else if (command==1){
        decompress(input,output);
    }

}