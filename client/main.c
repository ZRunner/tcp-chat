#include <stdio.h>
#include "../utils/lectureSecurisee.h"
#include "../utils/request.h"

int main(int argc, char const *argv[])
{
    struct request request;
    struct sockaddr_in adr_s, adr_c;
    unsigned int sock, lg;
    /* Request creation */
    request.type = -2;
    strcpy(request.data,"MySuper/Password");

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // Creation socket
    /* Client adress init */
    bzero(&adr_c,sizeof(adr_c));
    adr_c.sin_family = AF_INET; 
    adr_c.sin_port = htons(UDP_PORT);
    adr_c.sin_addr.s_addr = htonl(INADDR_ANY);
    /* Server adress init */
    bzero(&adr_s,sizeof(adr_s));
    adr_s.sin_family = AF_INET;
    adr_s.sin_port = htons(UDP_PORT);
    adr_s.sin_addr.s_addr = htonl(INADDR_ANY);
    /* Attachement socket */
    bind (sock, (struct sockaddr *) &adr_c, sizeof(adr_c));
    /* Sending informations */
    sendto (sock, (void *) &request, sizeof(struct request), 0, (struct sockaddr *) &adr_s, sizeof(adr_s)); 
    lg = sizeof(adr_s);
    if (recvfrom (sock, &request, sizeof(struct request), 0, (struct sockaddr *) &adr_s, &lg)>0){
        printf("%s\n",request.data);
    }
    //Close socket
    close(sock);

    return 0;
}
