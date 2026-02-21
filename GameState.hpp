/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:31:09 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 17:30:31 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Library.hpp"
#include "utils.hpp"

class Eentity;

class GameState
{

    public:
            int score;
            int lives;
            bool running;
            int frame;
            int pressed;
            long long int time;
            long long int startTime;
            WINDOW* gameWin;
            std::list<Eentity*> entities;
        GameState(long long int startTime_, int max_y_, int max_x_): score(0), lives(3), running(true), frame(0), pressed(0), time(0), startTime(startTime_)
        {
            gameWin = newwin(max_y_ - 3, max_x_, 3, 0);
        };
        ~GameState();
        bool isKeyPressed(int key){return pressed==key;}
        // check collisioni
};



#endif