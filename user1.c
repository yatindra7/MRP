#include <arpa/inet.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "rsocket.h"

#define PORT_1 50016
#define PORT_2 50017
#define MAX_MSG_LEN 100

int main() {
    int sockfd;
    if ((sockfd = r_socket(AF_INET, SOCK_MRP, 0)) < 0) {
        perror("r_socket");
        exit(1);
    }

    struct sockaddr_in u1_addr, u2_addr;

    memset(&u1_addr, 0, sizeof(u1_addr));
    u1_addr.sin_family = AF_INET;
    u1_addr.sin_port = htons(PORT_1);
    u1_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    memset(&u2_addr, 0, sizeof(u2_addr));
    u2_addr.sin_family = AF_INET;
    u2_addr.sin_port = htons(PORT_2);
    int s = inet_aton("127.0.0.1", &u2_addr.sin_addr);
    if (s <= 0) {
        perror("Unable to convert IP address\n");
        exit(1);
    }

    if (r_bind(sockfd, (struct sockaddr *)&u1_addr, sizeof(u1_addr)) < 0) {
        perror("r_bind");
        exit(1);
    }

    char msg[MAX_MSG_LEN];
    memset(msg, 0, MAX_MSG_LEN);
    printf("Enter a message: ");
    scanf("%[^\n]s", msg);
    int msg_len = strlen(msg);
    for (int i = 0; i < msg_len; i++) {
        int ret = r_sendto(sockfd, &msg[i], 1, 0, (struct sockaddr *)&u2_addr, sizeof(u2_addr));
        if (ret < 0) {
            perror("r_sendto");
            exit(1);
        }
    }

    // To ensure that all unacknowledged packets are delivered since we are never calling r_close
    while (1)
        ;
}