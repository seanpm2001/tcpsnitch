#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>

/* Debugging functions */

typedef enum DebugLevel
{
	INFO,
	WARN,
	ERROR
} DebugLevel;

const char *string_from_debug_level(DebugLevel lvl);

void lib_log(DebugLevel debug_lvl, const char *formated_str, const char *file, int line); 

#define DEBUG(debug_level, format, args...) {\
	char formated_string[1024];\
	snprintf(formated_string, sizeof(formated_string), format, ##args);\
	lib_log(debug_level, formated_string, __FILE__, __LINE__);\
}

void die_with_system_msg(const char *msg);

/* Helper functions */

bool is_socket(int fd);
bool is_inet_socket(int fd);
bool is_tcp_socket(int fd);
#define MEMBER_SIZE(type, member) sizeof(((type *)0)->member)

/* Other */
int append_string_to_file(const char *str, const char *path);

char *build_addr_str_from_sockaddr(const struct sockaddr_storage *addr); 
char *build_port_str_from_sockaddr(const struct sockaddr_storage *addr);
char *build_full_str_from_sockaddr(const struct sockaddr *addr);
char *build_path(const char *file_name);
char *build_pcap_path();
char *build_log_path();
char *build_json_path();
char *build_cmdline(char **app_name);
char *build_kernel();

time_t get_time_sec();
unsigned long get_time_micros();
long get_long_env(const char *env_var);

#endif

