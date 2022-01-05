#pragma once

/**
 * Screen Resolution
 */
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 768

/**
 * State Timeout Constants
 */
#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
#define SPLASH_STATE_SHOW_TIME 1.0

/**
 * Bird States
 */
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

/**
 * Bird Flying Constants
 */
#define BIRD_ANIMATION_DURATION 1.4f
#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f

/**
 * Pipe Specifications
 */
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.5f

/**
 * Medals for Different Scores
 */
#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 20
#define PLATINUM_MEDAL_SCORE 50

/**
 * Medal FilePaths
 */
#define BRONZE_MEDAL_FILEPATH "resources/img/bronze-medal.png"
#define SILVER_MEDAL_FILEPATH "resources/img/silver-medal.png"
#define GOLD_MEDAL_FILEPATH "resources/img/gold-medal.png"

/**
 * State FilePaths
 */
#define SPLASH_SCENE_BACKGROUND_FILEPATH "resources/img/splash-background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "resources/img/menu-background.png"
#define GAME_BACKGROUND_FILEPATH "resources/img/gamescreen-background.png"
#define GAME_OVER_BACKGROUND_FILEPATH "resources/img/menu-background.png"

/**
 * Text Assets Filepath
 */
#define GAME_TITLE_FILEPATH "resources/img/game-title.png"
#define GAME_OVER_TITLE_FILEPATH "resources/img/gameover-title.png"
#define GAME_OVER_BODY_FILEPATH "resources/img/gameover-body.png"

/**
 * Play Buttons Filepath
 */
#define PLAY_BUTTON_FILEPATH "resources/img/play-button.png"
#define GAME_OVER_RETRY_BUTTON_FILEPATH "resources/img/retry-button.png"

/**
 * Game Assets FilePath
 */
#define PIPE_UP_FILEPATH "resources/img/pipe-up.png"
#define PIPE_DOWN_FILEPATH "resources/img/pipe-down.png"
#define SCORING_PIPE_FILEPATH "resources/img/invisible-scoringpipe.png"
#define LAND_FILEPATH "resources/img/land.png"

/**
 * Bird Animation Frames FilePath
 */
#define BIRD_FRAME_1_FILEPATH "resources/img/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "resources/img/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "resources/img/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "resources/img/bird-04.png"

/**
 * Sounds Filepath
 */
#define HIT_SOUND_FILEPATH "resources/audio/hit.wav"
#define POINT_SOUND_FILEPATH "resources/audio/point.wav"
#define WING_SOUND_FILEPATH "resources/audio/wing.wav"
#define BACKGROUND_SOUND_FILEPATH "resources/audio/background.wav"

/**
 * Highscore Text FilePath
 */
#define HIGHSCORE_FILEPATH "resources/Highscore.txt"

/**
 * PokeFont Filepath
 */
#define POKE_FONT_FILEPATH "resources/fonts/PokeFont.ttf"

/**
 * Different GameStates
 */
enum GameStates {
    eReady,
    ePlaying,
    eGameOver
};
