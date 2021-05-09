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
# define ERR_RTWICE "argument error : only one R(resolution) authorized"
# define ERR_ATWICE "argument error : only one A(ambience) authorized"
# define ERR_RINVARGS "argument error for resolution, usage : R <int:width> <int:height>"
# define ERR_AINVARGS "argument error for ambience, usage : A <double:ratio> <int,int,int:color>"
# define ERR_CINVARGS "argument error for camera, usage : c <double,double,double:coord> <double,double,double:vect> <int:FOV>"
# define ERR_INVID "invalid identifier, identifier available: R A c l pl sp sq cy tr"
# define ERR_INVLINE "invalid line, usage : R <int:width> <int:height>\n\tA <double:ratio> <int,int,int:color>\n\tc <double,double,double:coord> <double,double,double:vect> <int:FOV>\n\t"

void handle_error(char *err, t_rt *rt);

#endif