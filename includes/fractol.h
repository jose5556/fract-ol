/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:03 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 05:51:36 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define HEIGHT	800
# define WIDTH	800
# define FERN_ITERATIONS 300000
# define ERROR_MESSAGE "Wrong name or wrong format, please enter the \
						name of your desired fractal first. \
						If it is the julia set you want, don't forget to \
						include their respective x and y coordinates.\n"
# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define PURPLE				0x800080
# define DARK_BLUE			0x00008B
# define GREEN				0x00FF00
# define GREEN_PLUS			0x007700
# define MEDIUM_GREEN		0x00AA00
# define DARK_GREEN			0x004400
# define ORANGE				0xFFA500
# define GOLDEN_YELLOW		0xFFD700
# define BROWN				0x654321
# define NEON_PINK			0xFF6EC7
# define CYAN_BLUE			0x00E5FF
# define ELECTRIC_VIOLET	0xB000FF
# define LIME_GREEN			0x7FFF00

typedef	struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
typedef struct s_fern
{
	unsigned long	seed;
	int				color;
	int				swap_color;
	int				first_iteration;
	int				px;
	int				py;
}	t_fern;
typedef struct s_fractal
{
	double	hypotenuse;
	int		fractal_iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color1;
	int		color2;
	int		color3;
	t_list	*lst;
	t_fern	fern;
}	t_fractal;
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*name;
	t_img		img;
	t_fractal	fractal;
	t_complex	complex;
}	t_data;
double		linear_interpolation(double minAllowed,
				double maxAllowed, double unscaledNum, double max);
void		fractal_init(t_data *data);
int			render_fractal(void *param);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			hooks_listener(t_data *data);
int			handle_keys(int keycode, t_data *data);
int			close_program(t_data *data);
int			handle_mouse(int button, int x, int y, t_data *data);
void		my_mlx_pixel_put(t_img *vars, int x, int y, int color);
double		ft_atoi_double(const char *nptr);
int			handle_colors(int keycode, t_data *data);
void		populate_color_lst(t_fractal *fractal);
int			smooth_color_interpolation(int color1, int color2,
				int i, int max_iterations);
double		lcg_random(t_fern *fern);
int			render_fern(t_data *data);
void		mandelbrot_julia_handler(t_data *data, char *name);
void		fern_handler(t_data *data, char *name);
int			hooks_listener_bonus(t_data *data);
int			handle_keys_bonus(int keycode, t_data *data);
t_list		*ft_newlst(int content);
void		ft_lstadd_back(t_list **lst, int content);
void		ft_lstclear(t_list **lst);

#endif