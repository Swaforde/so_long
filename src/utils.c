/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:11 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:05 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	init(t_content *c)
{
	char	*chad;
	char	*wall;
	char	*erase;
	char	*exit;
	char	*coin;

	chad = "./ressources/chad.xpm";
	wall = "./ressources/wall.xpm";
	erase = "./ressources/erase.xpm";
	exit = "./ressources/exit.xpm";
	coin = "./ressources/coin.xpm";
	c->exit.x = 0;
	c->exit.y = 0;
	c->player.score = 0;
	c->player.move_count = 0;
	c->i.ch = mlx_xpm_file_to_image(c->mlx, chad, &c->i.pw, &c->i.ph);
	c->i.w = mlx_xpm_file_to_image(c->mlx, wall, &c->i.pw, &c->i.ph);
	c->i.e = mlx_xpm_file_to_image(c->mlx, erase, &c->i.pw, &c->i.ph);
	c->i.ex = mlx_xpm_file_to_image(c->mlx, exit, &c->i.pw, &c->i.ph);
	c->i.c = mlx_xpm_file_to_image(c->mlx, coin, &c->i.pw, &c->i.ph);
}

int	tab_allocation(t_content *cont, char *argv)
{
	t_map		map;
	char		**tab;
	char		**tabtest;

	map.map_path = argv;
	map.height = ft_get_height(map);
	map.width = ft_get_width(map);
	cont->map = map;
	tab = ft_calloc (sizeof(char *), (cont->map.height + 1));
	if (!tab)
		return (0);
	*tab = ft_calloc (sizeof(char), (cont->map.width + 1));
	if (!*tab)
		return (0);
	tabtest = ft_calloc (sizeof(char *), (cont->map.height + 1));
	if (!tabtest)
		return (0);
	*tabtest = ft_calloc (sizeof(char), (cont->map.width + 1));
	if (!*tabtest)
		return (0);
	cont->tab = tab;
	cont->tabTest = tabtest;
	map_parsing(cont->tab, cont->map);
	map_parsing(cont->tabTest, cont->map);
}

int	arguement_check(int argc)
{
	if (argc == 1)
	{
		ft_printf("Error\nVeuillez renseigner un fichier .ber !");
		return (0);
	}
	return (1);
}

void	reset_value(t_content *cont)
{
	cont->exit.x = 0;
	cont->exit.y = 0;
}

int	error_message(int code)
{
	if (code == 1)
		ft_printf(" Error\nL'extension de fichier est invalide !");
	if (code == 2)
		ft_printf("Error\nLa map ne correspond pas au format !");
	if (code == 3)
		ft_printf("Error\nLa map contient trop de giga chad ! (player)");
	if (code == 4)
		ft_printf("Error\nLa map ne contient aucun player");
	if (code == 5)
		ft_printf("Error\nLa map contient trop plusieurs sorties !");
	if (code == 6)
		ft_printf("Error\nLa map ne contient aucune sortie !");
	if (code == 7)
		ft_printf("Error\nLa map contient des charactère interdit !");
	return (0);
}
