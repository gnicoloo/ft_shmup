// #include <ncurses.h>
// #include <vector>
// #include <unistd.h> // usleep
// #include <cstdlib>  // rand

// struct Entity {
//     int x, y;
//     char sprite;
//     bool alive;
//     Entity(int x_, int y_, char s) : x(x_), y(y_), sprite(s), alive(true) {}
// };

// struct Player : public Entity {
//     Player(int x_, int y_) : Entity(x_, y_, 'A') {}
// };

// struct Enemy : public Entity {
//     Enemy(int x_, int y_) : Entity(x_, y_, 'V') {}
// };

// struct Bullet : public Entity {
//     int dy; // direzione y
//     Bullet(int x_, int y_, int dy_) : Entity(x_, y_, '|'), dy(dy_) {}
// };

// int main() {
//     initscr();
//     noecho();
//     cbreak();
//     curs_set(0);
//     keypad(stdscr, TRUE);
//     nodelay(stdscr, TRUE);

//     int max_y, max_x;
//     getmaxyx(stdscr, max_y, max_x);

//     // HUD altezza 3 righe
//     WINDOW* hud = newwin(3, max_x, 0, 0);
//     WINDOW* gameWin = newwin(max_y-3, max_x, 3, 0);

//     Player player(max_x/2, max_y-6);
//     std::vector<Enemy> enemies;
//     std::vector<Bullet> bullets;

//     int score = 0;
//     int lives = 3;
//     bool running = true;
//     int frame = 0;

//     while(running) {
//         int ch = getch();
//         switch(ch) {
//             case KEY_LEFT: if(player.x>1) player.x--; break;
//             case KEY_RIGHT: if(player.x<max_x-2) player.x++; break;
//             case ' ': bullets.push_back(Bullet(player.x, player.y-1, -1)); break;
//             case 'q': running=false; break;
//         }

//         // Spawn nemici ogni 20 frame
//         if(frame % 1 == 0) enemies.push_back(Enemy(rand() % (max_x-2)+1,1));

//         // Update bullets
//         for(auto &b : bullets) b.y += b.dy;
//         bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
//             [max_y](Bullet &b){ return b.y<=0; }), bullets.end());

//         // Update nemici
//         for(auto &e : enemies) e.y++;
//         enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
//             [max_y](Enemy &e){ return e.y>=max_y-3; }), enemies.end());

//         // Collision bullet-enemy
//         for(auto &b : bullets){
//             for(auto &e : enemies){
//                 if(b.alive && e.alive && b.x==e.x && b.y==e.y){
//                     b.alive=false;
//                     e.alive=false;
//                     score+=10;
//                 }
//             }
//         }
//         bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
//             [](Bullet &b){ return !b.alive; }), bullets.end());
//         enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
//             [](Enemy &e){ return !e.alive; }), enemies.end());

//         // Collision player-enemy
//         for(auto &e : enemies){
//             if(e.x==player.x && e.y==player.y){
//                 lives--;
//                 e.alive=false;
//                 if(lives<=0) running=false;
//             }
//         }

//         // Render HUD
//         werase(hud);
//         box(hud,0,0);
//         mvwprintw(hud,1,2,"Score: %d  Lives: %d  Frame: %d",score,lives,frame);
//         wrefresh(hud);

//         // Render game
//         werase(gameWin);
//         box(gameWin,0,0);
//         mvwaddch(gameWin,player.y,player.x,player.sprite);
//         for(auto &e : enemies) mvwaddch(gameWin,e.y,e.x,e.sprite);
//         for(auto &b : bullets) mvwaddch(gameWin,b.y,b.x,b.sprite);
//         wrefresh(gameWin);

//         usleep(50000); // 50ms ~20 FPS
//         frame++;
//     }

//     delwin(hud);
//     delwin(gameWin);
//     endwin();
//     return 0;
// }




// #include <ncurses.h>
// #include <vector>
// #include <unistd.h>
// #include <cstdlib>

// struct Entity {
//     int x, y;
//     int w, h;       // larghezza e altezza
//     std::vector<std::vector<char>> sprite;
//     bool alive;
//     Entity(int x_, int y_, std::vector<std::vector<char>> s)
//         : x(x_), y(y_), sprite(s), alive(true)
//     {
//         h = sprite.size();
//         w = sprite[0].size();
//     }
// };

// // Disegna una matrice su finestra
// void drawEntity(WINDOW* win, Entity& e) {
//     for(int i=0;i<e.h;i++)
//         for(int j=0;j<e.w;j++)
//             if(e.sprite[i][j] != ' ')
//                 mvwaddch(win, e.y+i, e.x+j, e.sprite[i][j]);
// }

// // Controllo collisione rettangolare
// bool checkCollision(Entity& a, Entity& b) {
//     return !(a.x + a.w <= b.x || b.x + b.w <= a.x ||
//              a.y + a.h <= b.y || b.y + b.h <= a.y);
// }

// int main() {
//     initscr();
//     noecho();
//     cbreak();
//     curs_set(0);
//     keypad(stdscr, TRUE);
//     nodelay(stdscr, TRUE);

//     int max_y, max_x;
//     getmaxyx(stdscr, max_y, max_x);

//     WINDOW* hud = newwin(3, max_x, 0, 0);
//     WINDOW* gameWin = newwin(max_y-3, max_x, 3, 0);

//     std::vector<std::vector<char>> playerSprite = {{'/', '\\'}, {'\\','/'}};
//     std::vector<std::vector<char>> enemySprite  = {{'V','V'}, {'V','V'}};

//     Entity player(max_x/2, max_y-6, playerSprite);
//     std::vector<Entity> enemies;

//     int score = 0;
//     int lives = 3;
//     bool running = true;
//     int frame = 0;

//     while(running) {
//         int ch = getch();
//         switch(ch){
//             case KEY_LEFT: if(player.x>1) player.x--; break;
//             case KEY_RIGHT: if(player.x + player.w < max_x-1) player.x++; break;
//             case 'q': running=false; break;
//         }

//         // spawn nemici ogni 30 frame
//         if(frame % 30 == 0)
//             enemies.push_back(Entity(rand()%(max_x-2-1)+1,1,enemySprite));

//         // muovi nemici
//         for(auto &e: enemies) e.y++;
//         enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
//             [max_y](Entity &e){ return e.y >= max_y-3; }), enemies.end());

//         // collisione player-enemy
//         for(auto &e: enemies){
//             if(checkCollision(player,e)){
//                 lives--;
//                 e.alive=false;
//                 if(lives<=0) running=false;
//             }
//         }
//         enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
//             [](Entity &e){ return !e.alive; }), enemies.end());

//         // Render HUD
//         werase(hud);
//         box(hud,0,0);
//         mvwprintw(hud,1,2,"Score: %d  Lives: %d  Frame: %d",score,lives,frame);
//         wrefresh(hud);

//         // Render game
//         werase(gameWin);
//         box(gameWin,0,0);
//         drawEntity(gameWin,player);
//         for(auto &e: enemies) drawEntity(gameWin,e);
//         wrefresh(gameWin);

//         usleep(50000); // 20 FPS
//         frame++;
//     }

//     delwin(hud);
//     delwin(gameWin);
//     endwin();
//     return 0;
// }




//                    +-----------------------+
//                    |      GameEntity       |  (base class)
//                    +-----------------------+
//                    | - x, y                |
//                    | - w, h                |
//                    | - alive               |
//                    | - sprite (matrix)     |
//                    +-----------------------+
//                    | + update() = 0        |
//                    | + draw(WINDOW*)       |
//                    | + isAlive()           |
//                    | + kill()              |
//                    +-----------------------+
//                              ▲
//           ┌──────────────────┼──────────────────┐
//           │                  │                  │
// +----------------+  +----------------+  +----------------+
// |     Player     |  |     Enemy      |  |     Bullet     |
// +----------------+  +----------------+  +----------------+
// | - lives        |  | - speed        |  | - dy          |
// | - score        |  |                |  |                |
// +----------------+  +----------------+  +----------------+
// | + move(dx,dy)  |  | + update()     |  | + update()     |
// | + shoot()      |  |                |  |                |
// | + update()     |  |                |  |                |
// +----------------+  +----------------+  +----------------+

//                        +----------------+
//                        |      Game      |
//                        +----------------+
//                        | - hud: WINDOW* |
//                        | - gameWin: WINDOW* |
                                                                    //    | - Player       |
                                                                    //    | - vector<Enemy>|
                                                                    //    | - vector<Bullet>|
//                              che sara un vector di puntatori a GameEntity
                //         vect
//                        | - running: bool|
//                        | - frame        |
//                        +----------------+
//                        | + run()        |
//                        | + handleInput()|
//                        | + update()     |
//                        | + render()     |
//                        | + checkCollisions()|
//                        | + init()       |
//                        | + shutdown()   |
//                        +----------------+



// MAIN
//  └── Game
//       ├── Init ncurses + finestre
//       ├── Loop principale
//       │    ├── Input
//       │    │     └── muovi player, spara, quit
//       │    ├── Update
//       │    │     ├── muovi nemici
//       │    │     ├── muovi proiettili
//       │    │     └── spawn nemici/proiettili
//       │    ├── Collision
//       │    │     ├── player-enemy
//       │    │     └── bullet-enemy
//       │    └── Render
//       │          ├── HUD
//       │          └── GAME AREA (draw player, nemici, proiettili)
//       └── Shutdown
//              └── delwin() + endwin()





#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "Library.hpp"

struct Entity {
    int x, y;
    int w, h;
    std::vector<std::vector<char> > sprite;
    bool alive;

    Entity(int x_, int y_, std::vector<std::vector<char> > s)
        : x(x_), y(y_), sprite(s), alive(true)
    {
        h = sprite.size();
        w = (h > 0) ? sprite[0].size() : 0;
    }
};

// Disegna una matrice su finestra
void drawEntity(WINDOW* win, Entity& e) {
    for(int i = 0; i < e.h; i++)
        for(int j = 0; j < e.w; j++)
            if(e.sprite[i][j] != ' ')
                mvwaddch(win, e.y + i, e.x + j, e.sprite[i][j]);
}

// Controllo collisione rettangolare
bool checkCollision(Entity& a, Entity& b) {
    return !(a.x + a.w <= b.x || b.x + b.w <= a.x ||
             a.y + a.h <= b.y || b.y + b.h <= a.y);
}

int main() {
    srand(time(NULL));

    // // Inizializzazione ncurses
    initscr();

    // Configurazione ncurses
    // - noecho: non mostrare i caratteri digitati
    noecho();
    // - cbreak: disabilita buffering, input immediato
    cbreak();
    // - curs_set(0): nascondi cursore
    curs_set(0);
    // - keypad: abilita input da tastiera (frecce)
    keypad(stdscr, TRUE);
    // - nodelay: getch() non blocca se non c'è input
    nodelay(stdscr, TRUE);

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // Creazione finestre
    // parameteri: altezza, larghezza, starty, startx
    WINDOW* hud = newwin(3, max_x, 0, 0);
    WINDOW* gameWin = newwin(max_y - 3, max_x, 3, 0);

    // Sprite player

    // questo sara un matrix block con define di grande variabile con grandezze raw,length e poi push_back di ogni riga, cosi da poter fare sprite piu grandi
    //con spazo tra i caratteri, e non solo 1 char per cella
    std::vector<std::vector<char> > playerSprite;
    playerSprite.push_back(std::vector<char>());
    playerSprite[0].push_back('/');
    playerSprite[0].push_back('\\');

    playerSprite.push_back(std::vector<char>());
    playerSprite[1].push_back('\\');
    playerSprite[1].push_back('/');

    // Sprite enemy
    std::vector<std::vector<char> > enemySprite;
    enemySprite.push_back(std::vector<char>());
    enemySprite[0].push_back('V');
    enemySprite[0].push_back('V');

    enemySprite.push_back(std::vector<char>());
    enemySprite[1].push_back('V');
    enemySprite[1].push_back('V');

    Entity player(max_x / 2, max_y - 6, playerSprite);
    

    //  forse sara una lista
    std::vector<Entity> enemies;

    // Variabili di gioco da spostare in una classe Game con metodi per update, render, input, collisioni
    int score = 0;
    int lives = 3;
    bool running = true;
    int frame = 0;

    while(running) {

        int ch = getch();
        switch(ch) {
            case KEY_LEFT:
                if(player.x > 1)
                    player.x--;
                break;
            case KEY_RIGHT:
                if(player.x + player.w < max_x - 1)
                    player.x++;
                break;
            case 'q':
                running = false;
                break;
                // case ' ': // spara
                //     // bullets.push_back(Entity(player.x + player.w/2, player.y - 1, bulletSprite));
                //     break;

                // quit con q, ma magari meglio con ESC o qualcosa di piu standard, e magari anche con una schermata di conferma "Are you sure? Y/N"
        }

        // spawn nemici ogni 30 frame
        if(frame % 30 == 0) {
            int spawnX = rand() % (max_x - 3) + 1;
            enemies.push_back(Entity(spawnX, 1, enemySprite));
        }

        // muovi nemici
        for(std::vector<Entity>::iterator it = enemies.begin();
            it != enemies.end();
            ++it)
        {
            it->y++;
        }

        // rimuovi nemici fuori schermo
        for(std::vector<Entity>::iterator it = enemies.begin();
            it != enemies.end(); )
        {
            if(it->y >= max_y - 3)
                it = enemies.erase(it);
            else
                ++it;
        }

        // collisione player-enemy
        for(std::vector<Entity>::iterator it = enemies.begin();
            it != enemies.end();
            ++it)
        {
            if(checkCollision(player, *it)) {
                lives--;
                it->alive = false;
                if(lives <= 0)
                    running = false;
            }
        }

        // rimuovi nemici morti
        for(std::vector<Entity>::iterator it = enemies.begin();
            it != enemies.end(); )
        {
            if(!it->alive)
                it = enemies.erase(it);
            else
                ++it;
        }

        // Render HUD
        // werase: pulisce la finestra
        werase(hud);
        // box: disegna un bordo attorno alla finestra
        box(hud, 0, 0);
        // mvwprintw: stampa testo nella finestra hud alla posizione (1,2)
        mvwprintw(hud, 1, 2, "Score: %d  Lives: %d  Frame: %d", score, lives, frame);
        // wrefresh: aggiorna la finestra hud
        wrefresh(hud);


        // Render game
        //perche ?
        // perche se non pulisco la finestra, i nemici lasciano una scia quando si muovono, e il player lascia una scia quando si muove
        // box disegna un bordo attorno alla finestra, se non lo ridisegno ad ogni frame, il bordo scompare
        werase(gameWin);
        box(gameWin, 0, 0);


        // da mofificare per disegnare sprite piu grandi, ora disegna solo 1 char per cella, ma con sprite a matrice devo disegnare tutta la matrice
        drawEntity(gameWin, player);

            // disegnare i nemici, ora disegna solo 1 char per cella, ma con sprite a matrice devo disegnare tutta la matrice
        // drawEntity(gameWin, bullet);
        for(std::vector<Entity>::iterator it = enemies.begin();
            it != enemies.end();
            ++it)
        {
            drawEntity(gameWin, *it);
        }
        // aggiorna la finestra gameWin
        wrefresh(gameWin);

        usleep(50000); // ~20 FPS
        frame++;
    }
    // pulizia ncurses
    exit_cleanup(hud, gameWin);
    return 0;
}