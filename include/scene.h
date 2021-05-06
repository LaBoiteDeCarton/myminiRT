#ifndef STRUCT_H
# define STRUCT_H
# include "libft.h"
# include "ft_str_utils.h"
# include "mlx.h"

typedef struct s_coord		t_coord;
typedef struct s_color		t_color;
typedef struct s_scene		t_scene;
typedef struct s_vector		t_vector;
typedef struct s_sphere		t_sphere;
typedef struct s_cylindre	t_cylindre;
typedef struct s_triangle	t_triangle;
typedef struct s_plan		t_plan;
typedef struct s_objet		t_objet;
typedef struct s_resolution	t_resolution;
typedef struct s_camera		t_camera;

typedef enum e_objtype
{
	l,
	c,
	sp,
	cl,
	tr,
	pl,
	sq,
	cy,
}	t_objtype;

struct s_coord
{
	float x;
	float y;
	float z;
};

struct s_vector
{
	float x;
	float y;
	float z;
};

struct s_color
{
	unsigned short int r;
	unsigned short int g;
	unsigned short int b;
};

struct s_camera
{
	t_coord *position;
	t_vector vector;
	short int fov;
};

struct s_sphere
{
	t_coord *position;
	float diam;
};

struct s_cylindre
{
	t_coord *position;
	t_vector vector;
	float diam;
	float height;
};

struct s_triangle
{
	t_coord *coords;
};

struct s_plan
{
	t_coord *position;
	t_vector vector;
};

struct s_objet
{
	t_color color;
	t_objtype objtype;
	void *obj;
};

struct s_resolution
{
	int x;
	int y;
};

struct s_scene
{
	t_resolution resolution;
	t_list *cams;
	t_list *objets;
};

void	complete_default_scene(t_scene *scene);
void	put_scene(void *mlx_ptr, void *mlx_win, t_scene *scene);
void	delete_scene(t_scene *scene);

#endif