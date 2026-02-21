/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hub.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:53:04 by gnicolo           #+#    #+#             */
/*   Updated: 2026/02/21 12:54:19 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_HPP
#define HUD_HPP

#include "Library.hpp"

class HUD {
private:
    WINDOW* win;
    int width;
    int height;

public:
    // Costruttore / Distruttore
    HUD(int w, int h, int starty, int startx);
    ~HUD();

    // Aggiorna le informazioni sullo schermo
    void render(int score, int lives, int frame);

    // Ritorna la finestra ncurses
    // dovro usare questa funzione per disegnare il player, i nemici e i proiettili sulla finestra del gioco, perche la finestra del gioco e diversa da quella dell'hud, quindi devo passare la finestra del gioco alla funzione drawEntity() per disegnare le entita sulla finestra del gioco, e per fare questo devo avere una funzione che mi ritorna la finestra del gioco, che in questo caso e la finestra dell'hud, perche l'hud e la finestra principale del gioco, quindi posso usare la funzione getWindow() per ottenere la finestra dell'hud e passare quella alla funzione drawEntity() per disegnare le entita sulla finestra dell'hud, che in questo caso e anche la finestra del gioco.
    
    WINDOW* getWindow();
};

#endif // HUD_HPP