// Server side implementation of UDP client-server model
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <json/json.h>
#include <json/value.h>
#include <fstream>
#include <string>  
#define PORT 8080

int sockfd,buffer;
struct sockaddr_in servaddr,cliaddr;
socklen_t len = sizeof(cliaddr);

void recvdatafromclient(){

    recvfrom(sockfd, &buffer, sizeof(int), MSG_WAITALL, (struct sockaddr *)&cliaddr,&len);

}

int main(int argc, char *argv[])
{
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

     
    return 0;
}
