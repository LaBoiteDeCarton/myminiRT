#ifndef HANDLE_ERRORS
# define HANDLE_ERRORS

# include <stdio.h>
# include <stdlib.h>
# include "rt.h"

# define EXEC_PROTO "miniRT <file-path> <flags>"
# define ERR_ARGUMENTMISSING "missing argument <file-path> in : miniRT <file-path> <flags>"
# define ERR_TOOMUCHARGUMENT "too much arguments in : miniRT <file-path> <flags>"
# define ERR_BADEXTENTIONFILE "wrong file extention, .rt file only in : miniRT <file-path> <flags>"
# define ERR_UNABLETOOPENFILE "unable to open file from <file-path> in : miniRT <file-path> <flags>"
# define ERR_READINGFILEERROR "error while reading file : read(fd, buff, BUFFER_SIZE)"
# define ERR_MALLOC "memory allocation failed"
# define ERR_WRONGFLAGARG "wrong argument <flags> in : miniRT <file-path> <flags>"
# define ERR_RTWICE "file argument error : only one R(resolution) authorized"
# define ERR_ATWICE "file argument error : only one A(ambience) authorized"
# define ERR_RINVARGS "file argument error for resolution, usage : R <int:width> <int:height>"
# define ERR_AINVARGS "file argument error for ambience, usage : A <double:ratio> <int,int,int:color>"
# define ERR_CINVARGS "file argument error for camera, usage : c <double,double,double:coord> <double,double,double:vect> <int:FOV>"

void handle_error(char *err, t_rt *rt);

#endif