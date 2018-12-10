#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define	SERVER_IP	"127.0.0.1"
#define SERVER_PORT	60000

int main(int argc, char *argv[]){
    int	sock_send;
    struct sockaddr_in	addr_send;
    int	i;
    char text[80],buf[BUF_SIZE];
    int	send_len,bytes_sent;
    sock_send=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_send < 0){
        printf("socket() failed\n");
        exit(0);
    }
    memset(&addr_send, 0, sizeof (addr_send)); 
    addr_send.sin_family = AF_INET; 
    addr_send.sin_addr.s_addr = inet_addr(SERVER_IP);
    addr_send.sin_port = htons((unsigned short)SERVER_PORT);
    i=connect(sock_send, (struct sockaddr *) &addr_send, sizeof (addr_send));
    if (i < 0){
        printf("connect() failed\n");
        exit(0);
    }
    while (1){
        printf("Send? ");
        scanf("%s",text);
        if (strcmp(text,"finish") == 0)
        {
        	strcpy(buf,text);
        	send_len=strlen(text);
        	bytes_sent=send(sock_send,buf,send_len,0);
        	break;
        }
        strcpy(buf,text);
        send_len=strlen(text);
        bytes_sent=send(sock_send,buf,send_len,0);
    }
    close(sock_send);
}
