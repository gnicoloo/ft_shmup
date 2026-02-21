/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntety.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:14:45 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 11:16:50 by gnicolo          ###   ########.fr       */
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
        GameEntety();
        virtual ~GameEntety();
};

#endif
