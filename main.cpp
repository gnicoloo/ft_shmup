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