/* Our own header, to be included before all standard system headers */
 
#ifndef _APUE_H
#define _APUE_H

#if defined(SOLARIS)
#define _XOPEN_SOURCE   500 /* Single UNIX Specification, Version 2  for Solaris 9 */
#define CMSG_LEN(x) _CMSG_DATA_ALIGN(sizeof(struct cmsghdr)+(x))
#elif !defined(BSD)
#define _XOPEN_SOURCE   600 /* Single UNIX Specification, Version 3 */
#endif

#include <sys/types.h>      /* some systems still require this */
#include <sys/stat.h>
#include <sys/termios.h>    /* for winsize */
#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif
#include <stdio.h>      /* for convenience */
#include <stdlib.h>     /* for convenience */
#include <stddef.h>     /* for offsetof */
#include <string.h>     /* for convenience */
#include <unistd.h>     /* for convenience */
#include <signal.h>     /* for SIG_ERR */

#define MAXLINE 4096            /* max line length */


void	err_sys(const char *, ...);

void	log_sys(const char *, ...);

//void	TELL_WAIT(void);
//void	TELL_PARENT(pid_t);
//void	TELL_CHILD(pid_t);

#endif /* _APUE_H */