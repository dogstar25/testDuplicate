// MortalRescue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <crtdbg.h>


#include "game.h"
#include <math.h>

Game* game = 0;
using namespace std;

int main(int argc, char *args[])

{
    cout << "Mortal Rescue Begins\n"; 

	game = new Game();
	game->init();

	float fps = 0.;

	std::chrono::duration<double> milisecsPerUpdate = std::chrono::milliseconds(16);
	steady_clock::time_point previous_time = steady_clock::now();
	
	/*
	Main Game loop
	*/
	while (game->gameState != game->QUIT) {

		game->clock.tick();

		//Calculate how many steps to update physics and objects
		steady_clock::time_point current_time = steady_clock::now();
		std::chrono::duration<double> time_diff = current_time - previous_time;
		
		//handle input
		game->handleEvents();

		//cout << "timeDiff is " << time_diff.count() << " clocktimeaccum is " << game->clock.fps_time_accum.count();
		//Only update and render if we have passed the 60 fps time passage
		if (time_diff >= milisecsPerUpdate)
		{
			previous_time = current_time;

			//Handle updating objects positions and physics
			game->update();

			//render everything
			game->render();

			game->clock.tick();
			game->clock.current_frame_cnt++;
			game->clock.calcFps();
		}

	}
	
	delete game;

	return 0;

}


