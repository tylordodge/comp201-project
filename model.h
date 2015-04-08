#ifndef _MODEL_H
#define _MODEL_H
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>



enum State { RUN, SEEK };
enum Direction { UP, DOWN, LEFT, RIGHT, STILL };


// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
	void go(Direction d);
	void move();
    // Is the game over?
    bool gameOver();
	//Make the object move
	// Move (if the next spot is a wall d = STILL)
	Direction direction;
	void move_pac();
	// Move the ghosts (if the next spot is a wall, switch direction)
	void move_ghost();
	//Next spot detection
	
	void new_path();
	bool ghostcollision();
	bool overlap(SDL_Rect c, SDL_Rect d);
	
    // instantiate objects
	SDL_Rect pacman;
	SDL_Rect Rect[32];
	// Locations of the pills
	SDL_Rect pills[124];
	// Is the pill being shown?
	bool pillShown[124];
	// ghosts 
	
	SDL_Rect ghost1;
	SDL_Rect ghost2;
	bool SPshown[5];
	SDL_Rect SPloc[5];
	Direction ghostd;
	Direction last_d;
	// big food pill
	
	int width;
	int height;
	
private:
	SDL_Rect checkblock, offset, middle, middle2;
	bool paccollision();
	bool Collision(SDL_Rect a, SDL_Rect b);
	int score;
};

#endif