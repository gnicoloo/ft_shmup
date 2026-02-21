/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hub.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:54:41 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 17:19:05 by gnicolo          ###   ########.fr       */
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

void HUD::render(GameState& gameState)
{
    int score = gameState.score;
    int lives = gameState.lives;
    int frame = gameState.frame;
    long long int time = (( get_time() - gameState.startTime) / 1000); // tempo in secondi

 // Colori HUD
    wattron(win, COLOR_PAIR(4)); // HUD info
    // Score e frame
    mvwprintw(win, 1, 2, "Score: %d   ||  Frame: %d    ||  Time: %lld   || lives: ", score, frame, time);
    wattron(win, COLOR_PAIR(2));
    for(int i = 0; i < lives; i++)
    {
        wprintw(win, "$$$  ");
    }
    wattroff(win, COLOR_PAIR(2));

    wattron(win, COLOR_PAIR(1));
    for(int i = lives; i < 3; i++) {
        wprintw(win, "   "); 
    }
    wattroff(win, COLOR_PAIR(1));
    wattroff(win, COLOR_PAIR(4));
    wrefresh(win);
}


void HUD::update(GameState &gameState)
{
    // In futuro, potresti voler aggiornare dinamicamente le informazioni dell'HUD qui
    werase(getWindow());
    box(getWindow(), 0, 0);
    render(gameState);
    wrefresh(getWindow());
}