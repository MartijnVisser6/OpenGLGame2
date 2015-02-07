#ifndef GLOBALS_H
#define GLOBALS_H

//Screen resolution
static int SCREEN_WIDTH = 1024;
static int SCREEN_HEIGHT = 768;

//FPS
static float MAX_FPS = 60.0f;

// The initial colors of the objects
static float initialPlayerColor[] = { 0.0f, 0.6f, 0.2f, 1.0f };
static float initialFoodColor[] = { 0.8f, 0.8f, 1.0f, 1.0f };

// The sizes of the objects
static float PLAYER_SIZE = 0.015f;
static float FOOD_SIZE = 0.005f;

// The speeds of objects
static float PLAYER_SPEED = 0.3f;
static float FOOD_SPEED = 0.1f;

// Field of View
static float FOV = 45.0f;

// Food move rate
static float FOOD_MOVE_RATE = .3f;

#endif