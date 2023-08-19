
#ifndef CUB3D_H
# define CUB3D_H

#define F_COLOR 10100
#define C_COLOR 878878

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "mlx_linux/mlx.h"
# include <string.h>
# define PI 3.1415926535
# define S_WIDTH 1000
# define S_HEIGHT 1000
# define B_SIZE 100

typedef struct s_ray
{
	double	*hypo;
	double	dist;
	int		wall_height;
	int		f_wall_height;
	char	dir;
}			t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}			t_img;

typedef struct s_text
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
}			t_text;

typedef struct s_player
{
	double	x;
	double	y;
	double	hit1_x;
	double	hit1_y;
	double	hit2_x;
	double	hit2_y;
	double	f_hit_x;
	double	f_hit_y;
	char	dir;
	int		angle;
}			t_player;

typedef struct s_map
{
	int		g_height;
	int		g_width;
	char	**grid;

}			t_map;

typedef struct s_arg
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		nb_line;
	int		nb_empty;
}			t_arg;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		buff01;
	t_img		buff02;
	t_text		text_e;
	t_text		text_w;
	t_text		text_n;
	t_text		text_s;
	t_player	player;
	t_ray		ray;
	t_map		map;
	t_arg		arg;
	int			frame;
}				t_mlx;


void			ft_init_data(t_mlx *mlx);
void			ft_free_grid(t_map *map);
int				ft_exit(t_mlx *mlx);
void			ft_free_text(t_arg *arg);
void			ft_free_colors(t_arg *arg);
void			ft_free_data(t_mlx *mlx);
double			ft_east(t_mlx *mlx);
double			ft_west(t_mlx *mlx);
double			ft_south(t_mlx *mlx);
double			ft_north(t_mlx *mlx);
int				ft_init_texture(t_mlx *mlx);
void			ft_init_ray(t_mlx *mlx);
double			ft_move_angle(double angle, double move);
int				ft_angle(double angle);
double			ft_ray_caster(t_mlx *mlx, double x, double y, double angle);
char			ft_check_hit(t_mlx *mlx, char hit, double x, double y);
void			ft_vector_1(t_mlx *mlx, t_img *buff);
void			ft_vector_2(t_mlx *mlx, double angle, double tmp);
void			ft_init_texture_2(t_mlx *mlx);
double			ft_hit(t_mlx *mlx);
unsigned int	ft_get_pixel(t_mlx *mlx, t_text *text, int w_pix, int w_size);
t_text			*ft_choose_text(t_mlx *mlx);
void			my_pixel_put(t_img *img, int x, int y, int color);
void			ft_draw_col_c(t_img *buff, int x, int len, int color);
void			ft_draw_col_f(t_img *buff, int x, int len, int color);
void			ft_draw_t_col(t_mlx *mlx, t_img *buff, int x, int y);
int				ft_next_frame(int keycode, t_mlx *mlx);
void			ft_keycode(int keycode, t_mlx *mlx);
void			ft_turn(int keycode, t_mlx *mlx);
void			ft_move(int keycode, t_mlx *mlx);
double			ft_se(t_mlx *mlx, double x, double y, double angle);
double			ft_se_1(t_mlx *mlx, double x, double y, double angle);
double			ft_se_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_se_x(t_mlx *mlx, double x, double y, double angle);
double			ft_se_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_se_y(t_mlx *mlx, double x, double y, double angle);
double			ft_se_y_1(t_mlx *mlx, double x, double y, double angle);
double			ft_sw(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_1(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_sw_x(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_sw_y(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_y_1(t_mlx *mlx, double x, double y, double angle);
double			ft_nw(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_1(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_nw_x(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_nw_y(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_y_1(t_mlx *mlx, double x, double y, double angle);
double			ft_ne(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_1(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_ne_x(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_ne_y(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_y_1(t_mlx *mlx, double x, double y, double angle);

#endif
