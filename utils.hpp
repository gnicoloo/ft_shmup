/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:19:33 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 16:19:42 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP


#include "Library.hpp"



// TIME
long long int 	get_time(void);


// CLEANUP
void            exit_cleanup(WINDOW* gameWin, WINDOW* hudWin);


void            init_screen();
#endif