/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:31:09 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 14:39:08 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Library.hpp"

class GameState
{

    public:
            int score;
            int lives;
            bool running;
            int frame;
        GameState(): score(0), lives(3), running(true), frame(0) {};
        ~GameState();

        // check collisioni
};



#endif