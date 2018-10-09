#ifndef SIGNAL_UTIL_H
#define SIGNAL_UTIL_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>

/*
 * Reliable version of singal(), using POSIX sigaction().
 */
typedef void Sigfunc(int);

Sigfunc*
signal(int signo, Sigfunc *func);

void
pr_mask(const char*);

#endif
