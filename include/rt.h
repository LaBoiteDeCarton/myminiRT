#ifndef RT_H
# define RT_H
# include "libft.h"

typedef struct s_rt			t_rt;
typedef struct s_color		t_color;
typedef struct s_coord		t_coord;
typedef struct s_vect		t_vect;
typedef struct s_resolution	t_resolution;
typedef struct s_ambience	t_ambience;
typedef struct s_obj		t_obj;
typedef struct s_plan		t_plan;

typedef enum s_flag
{
	save,
	window,
} t_flag;

typedef enum s_typeobj
{
	pl,
	sp
} t_typeobj;

struct s_coord
{
	double x;
	double y;
	double z;
};

struct s_color
{
	int r;
	int g;
	int b;
};

struct s_vect
{
	double x;
	double y;
	double z;
};

struct s_resolution
{
	int x;
	int y;
};

struct s_ambience
{
	double ratio;
	t_color *color;
};


struct s_rt
{
	t_flag flag;
	t_resolution resolution;
	t_ambience ambience;
	t_list *cams;
	t_list *objs;
};

struct s_plan
{
	t_color *color;
	t_typeobj type;
	t_coord position;
	t_vect ortogonal;
};

t_rt *rt_new();
void rt_start(t_rt *rt);
void rt_delete(t_rt *rt);
void rt_addflag(char *flag, t_rt *rt);

#endif