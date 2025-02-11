/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:23:51 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/11 09:10:02 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# include <stdlib.h> // TESTING PURPOSES
# include <stdio.h> // TESTING PURPOSES

# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define WIN_W 1920
# define WIN_H 1080

						/*------- COLORS -------*/

# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define RED 0xFF0000FF
# define BLUE 0x0000FFFF
# define GOLD 0xFFD700FF



				/*	The struckt for the map	*/
				/*	Width = horizontal line	*/
				/*	Heigth = vertical line	*/
		/*	Array holds the the values which will determine	*/
		/*		the height of that point in the 3d image	*/

typedef struct s_points
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_points;

typedef struct s_fdf
{
	int				width;
	int				height;
	int				offset_x;
	int				offset_y;
	int				**z_array;
	float			scale_x;
	float			scale_y;
	float			scale;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_points		points;
}			t_fdf;

bool	arg_validation(int argc, char **argv);
bool	valid_file(char *file);

void	read_map(t_fdf *fdf, char *file);

void	init_array_mem(t_fdf *fdf);
void	init_array_data(t_fdf *fdf, char *file);
void	insert_data(t_fdf *fdf, char *line, int row);
void	ft_free_array(char **array);
void	ft_free_int_array(t_fdf *fdf);

int		get_width(t_fdf *fdf, char *line);
void	get_height_and_width(t_fdf *fdf, char *file);

void	calc_points(t_fdf *fdf, int x, int y, int z);

void	draw(t_fdf *fdf);
void	draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf);
void	init_fdf(t_fdf *fdf);


void	calc_isometric(int *x, int *y, int z);


#endif
