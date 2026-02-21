/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:16:41 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 12:26:51 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"


unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void exit_cleanup(WINDOW* hud, WINDOW* gameWin)
{
    delwin(hud);
    delwin(gameWin);
    endwin();
}