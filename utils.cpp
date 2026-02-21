/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:16:41 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 13:02:27 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"


unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void exit_cleanup(WINDOW* gameWin)
{
    delwin(gameWin);
    endwin();
}

void init_screen()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}