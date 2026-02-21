/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:19:33 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 17:48:53 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP


#include "Library.hpp"

struct Entity;


// TIME
long long int 	get_time(void);


// CLEANUP
void            exit_cleanup(WINDOW* gameWin, WINDOW* hudWin);

void            print_entity(Entity& e, WINDOW* win);

void            init_screen();
#endif