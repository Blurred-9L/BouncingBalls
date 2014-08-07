/**
 *  @file   BBResource.cpp
 *  @author Blurred-9L
 */

#include "BBResource.h"

const float BBResource::DEFAULT_BRICK_WIDTH = 40.0;
const float BBResource::DEFAULT_BRICK_HEIGHT = 20.0;
const unsigned BBResource::DEFAULT_ROWS = 20;
const unsigned BBResource::DEFAULT_COLS = 12;
const float BBResource::DEFAULT_BAR_SPEED = 6.0;
const float BBResource::DEFAULT_BALL_SPEED = 6.0;
const float BBResource::MIN_BALL_SPEED = 1.0;
const float BBResource::BALL_RADIUS = 6.0;
const float BBResource::BAR_WIDTH = 100.0;
const float BBResource::BAR_HEIGHT = 20.0;
const float BBResource::BALL_START_X = 234.0;
const float BBResource::BALL_START_Y = 568.0;
const float BBResource::BAR_START_X = 190.0;
const float BBResource::BAR_START_Y = 580.0;
const unsigned BBResource::MIN_SCENE_WIDTH = 320;
const unsigned BBResource::MIN_SCENE_HEIGHT = 480;
const unsigned BBResource::MAX_SCENE_WIDTH = 480;
const unsigned BBResource::MAX_SCENE_HEIGHT = 640;
const char * BBResource::BALL_IMG = "../img/Ball.png";
const char * BBResource::BAR_IMG = "../img/Bar.png";
const char * BBResource::BRICK_IMGS[NUM_COLORS] =
                                    {"../img/RedBrick.png", "../img/GreenBrick.png", "../img/BlueBrick.png",
                                     "../img/CyanBrick.png", "../img/MagentaBrick.png", "../img/YellowBrick.png",
                                     "../img/SilverBrick.png", "../img/GoldenBrick.png"};
const char * BBResource::LEVEL_NAME_PREFIX = "../levels/level_";
const char * BBResource::BALL_BOUNCE_FILE = "../sound/Bounce.wav";
