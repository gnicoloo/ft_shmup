/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntety.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:14:45 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 14:50:48 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTETY_HPP
#define GAMEENTETY_HPP

class GameEntety
{
    public:
        int x;
        int y;
        int width;
        int height;
        char sprite;
        bool alive;
        GameEntety() : x(0), y(0), width(1), height(1), sprite(' '), alive(true) {}
        GameEntety(int x, int y, int width, int height, char sprite)
            : x(x), y(y), width(width), height(height), sprite(sprite), alive(true) {};
        ~GameEntety() {};
};

#endif
