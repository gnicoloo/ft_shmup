/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:19:33 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 13:02:44 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP


#include "Library.hpp"



// TIME
unsigned long	get_time(void);


// CLEANUP
void            exit_cleanup(WINDOW* gameWin);


void            init_screen();
#endif