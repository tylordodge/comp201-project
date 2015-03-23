#include "model.h"
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;

// Constructor initializes the object
Model::Model() {
	
}



//TODO: make everything go in a direction
void Model::go(Direction d){
	d = d;
};

//TODO: make pacman move.
//*if next coordinate is a barrier, direction is STILL
void Model::move_pac(){
};


//TODO: detect next tile
void Model::next_spot(Coordinate c, Direction last_d){
	switch(last_d) {
		case UP:
			c.y--; 
			break;
		case DOWN: 
			c.y++; 
			break;
		case LEFT: 
			c.x--; 
			break;
		case RIGHT: 
			c.x++; 			
			break;
	}
}


//TODO: make the ghosts move relative to pacman
//*if next coordinate is barrier, the ghost chooses another direction
void Model::move_ghost(Coordinate pac, Coordinate &ghost, Direction &d){
	
	int path1, path2, path3, path4;
	Coordinate c1,c2,c3,c4;
	
	
	//TODO: find shortest path
	c1 = ghost; c1.y--; //up
	c2 = ghost; c2.y++; //down
	c3 = ghost; c3.x--; //left
	c4 = ghpst; c4.x++; //right
	
	if(c1!=wall){
		path1 = abs (c1.x - pac.x) + abs (c1.y - pac.y);
	}else{
		path1 == 1000;
	}
	if(c2!=wall){
		path = abs (c2.x - pac.x) + abs (c2.y - pac.y);
	}else{
		path2 == 1001;
	}
	if(c3!=wall){
		path3 = abs (c3.x - pac.x) + abs (c3.y - pac.y);
	}else{
		path3 == 1003;
	}
	if(c4!=wall){
		path4 = abs (c4.x - pac.x) + abs (c4.y - pac.y);
	}else{
		path4 == 1004;
	}
	
	
	
	if (next_spot(ghost, d)!= wall){
			//Switch statements to update the ghost coordinate
		switch(d) {
			case UP:
			ghost.y--; 
			break;
		case DOWN: 
			ghost.y++; 
			break;
		case LEFT: 
			ghost.x--; 
			break;
		case RIGHT: 
			ghost.x++; 			
			break;
		
		}
	}
	else{
		if (path1 < path2 && path1 < path3 && path1 < path4){
			d = UP;
		}
		if (path2 < path1 && path2 < path3 && path2 < path4){
			d = DOWN;
		}
		if (path3 < path2 && path3 < path1 && path3 < path4){
			d = LEFT;
		}
		else{
			d = RIGHT;
		}
	
	}
	
};


// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return false;
}
