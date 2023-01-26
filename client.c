#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
        int csock;
        struct sockaddr_in ss_addr;

        csock = socket(AF_INET, SOCK_STREAM, 0);
        if(csock<0)
                perror("Error! Socket Denied");
                ss_addr.sin_family = AF_INET;
                ss_addr.sin_addr.s_addr = inet_addr("192.168.195.136");
                ss_addr.sin_port = htons(8000);

                if(connect (csock, (struct sockaddr *)&ss_addr,sizeof(ss_addr))<0)
                        perror("Access Denied");

                        char buffer[400];
                        int y = read(csock, buffer, sizeof(buffer)-1);
                        if(y<0)
                                perror("Error reading");
                                printf("Random number: %s\n", buffer);

        close(csock);
        return 0;
}

void error(const char *notice)
{
        perror(notice);
        exit(1);
}
