#include <iostream>
#include <string>

#include <SDL/SDL.h>

#include "GraphicsOld.h"
#include "EventManager.h"
#include "Tetromino.h"
#include "Board.h"
#include "Game.h"

//TODO comments

using namespace std;

int main(int argc, char *argv[])
{
    atexit(SDL_Quit);

    // Game settings
    int gameSpeed  = 700;      // number of milliseconds between tetrominos falling movement
    int score      = 0;        // points for full lines

    // Class instances
    Tetromino    tetromino;
    Board        board(10, 16);
    Game         game(&tetromino, &board);
    IGraphics   *graphics;

    graphics = new GraphicsOld(&tetromino, &board);

    // Initializations
    if(!graphics->InitGraphics(30, 16, 10)) return 0;
    graphics->SetWindowTitle(score, (1600 - gameSpeed)/100);
    board.InitBoard();

    EventManager events;

    unsigned long timeStart = SDL_GetTicks();

    //SDL_Event event;
    bool run = true;
	while (run)
	{
	    // Keyboard event handling
	    events.PollEvents();

        if(events.isActualEvent(WINDOW_CLOSE)) break;

        if(events.isKeyPressed(SDLK_ESCAPE)) break;

        if(events.isKeyPressed(SDLK_RIGHT))
        {
            tetromino.GetPotentialTopLeft()->col += 1;
            if(game.CheckCollisionWithBorder())
            {
                tetromino.GetPotentialTopLeft()->col -= 1;
            }
            else
            {
                tetromino.Move();
            }
        }

        if(events.isKeyPressed(SDLK_LEFT))
        {
            tetromino.GetPotentialTopLeft()->col -= 1;
            if(game.CheckCollisionWithBorder())
            {
                tetromino.GetPotentialTopLeft()->col += 1;
            }
            else
            {
                tetromino.Move();
            }
        }

        if(events.isKeyDown(SDLK_DOWN))
        {
            tetromino.GetPotentialTopLeft()->row += 1;
            if(game.CheckCollisionWithLanded())
            {
                tetromino.GetPotentialTopLeft()->row -= 1;
                board.LandShape(&tetromino);

                // Check game over
                if(game.CheckGameOver())
                {
                    run = false;
                }
                else
                {
                    tetromino.NewShape();
                }
            }
            else
            {
                tetromino.Move();
            }
        }

        if(events.isKeyPressed(SDLK_r))
        {
            tetromino.RotatePotential();
            if(!game.CheckCollisionWhenRotated())
            {
                tetromino.Rotate();
            }
        }

        if(events.isKeyPressed(SDLK_PAGEUP))
        {
            if(gameSpeed > 100)
            {
                gameSpeed -= 100;
                graphics->SetWindowTitle(score, (1600 - gameSpeed)/100);
            }
        }

        if(events.isKeyPressed(SDLK_PAGEDOWN))
        {
            if(gameSpeed < 1500)
            {
                gameSpeed += 100;
                graphics->SetWindowTitle(score, (1600 - gameSpeed)/100);
            }
        }

        // Timed vertical movement
        unsigned long timeEnd = SDL_GetTicks();

        if(((timeEnd - timeStart) > unsigned(gameSpeed)))
        {
//            game.CheckCollisionWithBorder();

            tetromino.GetPotentialTopLeft()->row += 1;
            if(game.CheckCollisionWithLanded())
            {
                tetromino.GetPotentialTopLeft()->row -= 1;
                board.LandShape(&tetromino);

                // Check game over
                if(game.CheckGameOver())
                {
                    run = false;
                }
                else
                {
                    tetromino.NewShape();
                }
            }
            else
            {
                tetromino.Move();
            }

            game.DeleteLines(&score);

            graphics->SetWindowTitle(score, (1600 - gameSpeed)/100);

            timeStart = SDL_GetTicks();
        }

        // Rendering
        graphics->Rendering();
	}

	// Game loop for game over state
	graphics->SetWindowTitle(score);
	run = true;
	while(run)
    {
        events.PollEvents();
        if(events.isKeyPressed(SDLK_ESCAPE)) break;
        if(events.isActualEvent(WINDOW_CLOSE)) break;

        // Rendering
        graphics->Rendering();
    }

    // Clean up
    delete graphics;

	return 0;
}
