#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main()
{
        int ssock, ssocket, randnum, y;
        struct sockaddr_in ss_addr, cl_addr;

        ssock = socket(AF_INET, SOCK_STREAM, 0);
        if(ssock<0)
                perror("Error! Socket Denied");
                ss_addr.sin_family = AF_INET;
                ss_addr.sin_addr.s_addr = INADDR_ANY;
                ss_addr.sin_port = htons(8000);

                if(bind(ssock,(struct sockaddr *) &ss_addr, sizeof(ss_addr))<0)
                        perror("Access Denied");
                        listen(ssock, 3);

                        socklen_t cl_length = sizeof(cl_addr);
                        ssocket = accept(ssock, (struct sockaddr *) &cl_addr, &cl_length>

                                if(ssocket<0)
                                        perror("Error to accept");

                                char buffer[400];
                                srand(time(NULL));
                                randnum = (rand() % 900)+100;
                                sprintf(buffer,"%d", randnum);
                                y = write(ssocket, buffer, sizeof(buffer));

                        close(ssocket);
                close(ssock);
                return 0;
}

void error(const char *notice)
{
        perror(notice);
        exit(1);
}

