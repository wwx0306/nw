#ifndef _UTIL_H_
#define _UTIL_H_
/* util */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#define IPV4NAMESIZE 20
#define BUFLEN 512
#define NEXT_ARG() \
	do { \
		argv++; \
		if (--argc < 0) { \
			fprintf(stderr, "missing parameter for %s\n", *argv); \
			exit(EXIT_FAILURE);\
		}\
	} while(0)

#define NEXT_ARG_OK() (argc - 1 > 0)
#define NEXT_ARG_FWD() do { argv++; argc--; } while(0)
#define PREV_ARG() do { argv--; argc++; } while(0)
void invarg(const char *msg, const char *arg);
bool matches(const char *prefix,const char *str);
int get_unsigned16(unsigned short *val, const char *arg, int base);
int get_unsigned32(unsigned int *val, const char *arg, int base);
void duparg(const char *key, const char *arg);
void duparg2(const char *key, const char *arg);
int check_ifname(const char *name);
int check_ipv4(const char *);
int check_nw_if(char *);
int nw_mptcp(char *);
void trim(char *, const char *);
void blank_del(char *);
int check_filepath(char *);
#endif 