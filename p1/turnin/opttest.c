#include <stdio.h>  
#include <unistd.h>  
#include <getopt.h>
#include <stdlib.h>

int main(int argc, char **argv)  
{  
        int ch;  
        opterr = 0;  
        while ((ch = getopt(argc,argv,"a:bcde"))!=-1)  
        //a has to bring a value with it, bcde don't
        {  
                switch(ch)  
                {  
                        case 'a':  
                                printf("option a:'%s'\n",optarg);  
                                break;  
                        case 'b':  
                                printf("option b :b\n");  
                                break;  
                        default:  
                                printf("other option :%c\n",ch);  
                }  
        }  
        printf("optopt +%c\n",optopt);  
}  