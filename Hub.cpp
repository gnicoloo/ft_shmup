/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hub.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:54:41 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 13:13:44 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Hub.hpp"

HUD::HUD(int w, int h, int starty, int startx): width(w), height(h)
{
    win = newwin(height, width, starty, startx);
    box(win, 0, 0);
    wrefresh(win);
}

HUD::~HUD()
{
    delwin(win);
}

WINDOW* HUD::getWindow()
{
    return win;
}

void HUD::render(int score, int lives, int frame)
{

 // Colori HUD
    wattron(win, COLOR_PAIR(4)); // HUD info

    // Score e frame
    mvwprintw(win, 1, 2, "Score: %d  Frame: %d  Lives: ", score, frame);

    // Barra delle vite
    wattron(win, COLOR_PAIR(2)); // colore player / vita
    for(int i = 0; i < lives; i++) {
        wprintw(win, "$$$  "); // ogni '|' = 1 vita
    }
    wattroff(win, COLOR_PAIR(2));

    // Vite mancanti (rosso)
    wattron(win, COLOR_PAIR(1)); // rosso per vita persa
    for(int i = lives; i < 3; i++) { // supponiamo max 3 vite
        wprintw(win, "   "); // 3 spazi per ogni vita mancante
    }
    wattroff(win, COLOR_PAIR(1));

    wattroff(win, COLOR_PAIR(4));

    wrefresh(win);
}