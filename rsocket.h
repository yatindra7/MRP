#ifndef __RSOCKET_H
#define __RSOCKET_H

#include <sys/socket.h>
#include <sys/types.h>

#define SOCK_MRP 15
#define T 2
#define P 0.05
#define TIMEOUT (2 * T)

extern int tot_transm;

int r_socket(int domain, int type, int protocol);
int r_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
ssize_t r_sendto(int sockfd, const void *buf, size_t len, int flags,
                 const struct sockaddr *dest_addr, socklen_t addrlen);
ssize_t r_recvfrom(int sockfd, void *buf, size_t len, int flags,
                   struct sockaddr *src_addr, socklen_t *addrlen);
int r_close(int fd);

int dropMessage(float p);

#endif