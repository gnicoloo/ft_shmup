/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:16:41 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 16:19:33 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

long long int 	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void exit_cleanup(WINDOW* gameWin, WINDOW* hudWin)
{
    delwin(gameWin);
    delwin(hudWin);
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