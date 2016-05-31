#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <float.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <netdb.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <pthread.h>


typedef struct
{
	char cmd[64];
	char path[256];
	char real_path[256];
	char type[64];
	int code;
	int size;
} exp1_info_type;

void exp1_send_file(int sock, char* filename);
void exp1_send_404(int sock);
void exp1_http_reply(int sock, exp1_info_type *info);
void exp1_check_file(exp1_info_type *info);
void exp1_parse_status(char* status, exp1_info_type *pinfo);
int exp1_parse_header(char* buf, int size, exp1_info_type* info);
int exp1_http_session(int sock);
int exp1_tcp_listen(int port);

FILE * logfile;
