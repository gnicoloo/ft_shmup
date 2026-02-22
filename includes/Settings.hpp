#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 40

//Particles
#define PARTICLE_SPEED 6
#define PARTICLE_GRAVITY 9.81f
#define PARTICLE_ANIMATION "|\0\\\0-\0/\0|\0\\\0-\0/"
#define ALT_PARTICLE_ANIMATION "O\0o\0.\0o\0O\0o\0.\0o"
#define PARTICLE_AMOUNT 9
#define PARTICLE_RANDOM_OFFSET (false)

//HUD
#define HUD_WIDTH 20
#define HUD_HEIGHT 10
#define LOGO_HEIGHT 0
#define UPGRADES_WIDTH 30
#define UPGRADES_HEIGHT 30

//ENEMIES
#define INITIAL_SPAWN_TIME 3.5f
#define INITIAL_SHOOT_COOLDOWN 3.5f
#define INITIAL_MOVEMENT_COOLDOWN 1.0f
#define ENEMY_BULLET_SPEED 0.75f
#define BASE_ENEMY_SPRITE " _\n/O\\\n^ ^"

#define WIDE_ENEMY_SPRITE "   ___\n]-{' '}-[\n   ^ ^"

#define MARIO " o\n/|\\\n/ \\\n"
#define MARIO_SPEED 1.0f
#define STAR_SPRITE "*"
#define STAR_SPEED 0.35f
#define STAR_POINTS 50

//PLAYER
#define PLAYER_SPEED 2
#define PLAYER_INVINCIBILITY_SECONDS 1.0f
#define PLAYER_SHOOT_COOLDOWN 1.0f
#define PLAYER_BULLET_SPEED 2.0f
#define PLAYER_ANIMATION ")OO[^]OO(\0)oO[^]Oo(\0)-O[^]O-(\0)-o[^]o-(\0)--[^]--("

//CHESTS
#define CHEST_SPRITE "+=+\n|?|\n+=+"
#define CHEST_COOLDOWN 30
#define CHEST_SPEED 0.5f

#endif