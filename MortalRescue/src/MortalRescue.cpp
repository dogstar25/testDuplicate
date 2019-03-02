// MortalRescue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

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
	while (game->running()) {

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

		//std::cout << "FPS is " << game->clock.fps << "\n";
		
	}
	
	delete game;
	//game->clean();

	//_CrtDumpMemoryLeaks();

	return 0;

}


