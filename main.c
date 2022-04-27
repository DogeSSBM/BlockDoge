#include "Includes.h"

int main(int argc, char **argv)
{
    if(argc == 2 && strcmp(argv[1], "client") == 0){
        client();
    }else if(argc == 2 && strcmp(argv[1], "server") == 0){
        server();
    }else{
        fprintf(stderr, "Usage:\n\t%s <client|server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
