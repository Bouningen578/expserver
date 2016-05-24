#include "header/exp1.h"
int main(int argc, char **argv)
{
  int sock_listen;

  sock_listen = exp1_tcp_listen(14091);

  while(1){
    struct sockaddr addr;
    int sock_client;
    int len;

    sock_client = accept(sock_listen, &addr, (socklen_t*) &len);
    exp1_http_session(sock_client);

    shutdown(sock_client, SHUT_RDWR);
    close(sock_client);
  }
}
