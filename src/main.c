#include "exp1.h"
#include "portnum.h"

int main(int argc, char **argv)
{
  int sock_listen;

  sock_listen = exp1_tcp_listen(PORTNUM);

  pid_t process_id = 0;
  pid_t sid = 0;

  logfile = fopen("error.log", "a");

  process_id = fork();

  if (process_id < 0)
  {
    printf("Error: Daemon failed to start\n");
    exit(1);
  } else if (process_id > 0) {
    printf("Daemon successfully started.\n");
    exit(0);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) exit(1);

  //chdir("/");

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

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
