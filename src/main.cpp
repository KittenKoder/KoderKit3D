#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

//#define GLEW_STATIC

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL_opengl.h>
//#include <gl\glu.h>
#include <stdio.h>
#include <string>

#include "../koderkit/objects/camera.hpp"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 480;

int main ( int argc, char** argv ) {
    kk3d::objects::Camera3D new_object(NULL, 1);
    int tt = new_object.getTypeFlags();
    printf( "Value: %d\n", tt );

    //The window we'll be rendering to
    SDL_Window *window = NULL;

    //The surface contained by the window
    SDL_GLContext screenSurface = NULL;

    //Initialize SDL

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    } else {

        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL );
        if( window == NULL ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        } else {

            //SDL_SetWindowResizable(window, SDL_TRUE);
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

            //Get window surface
            screenSurface = SDL_GL_CreateContext( window );

            //SDL_GL_GetAttribute(attr, &value)
            GLenum glewError = glewInit();
            if (GLEW_OK != glewError)
            {
                fprintf(stderr, "Error: %s\n", glewGetErrorString(glewError));
            }

            //Update the surface
            SDL_UpdateWindowSurface( window );

            // load an image
            SDL_Surface* bmp = SDL_LoadBMP("cb.bmp");
            if (!bmp) {
                printf("Unable to load bitmap: %s\n", SDL_GetError());
                return 1;
            }

            // centre the bitmap on screen
            SDL_Rect dstrect;
            dstrect.x = (SCREEN_WIDTH - bmp->w) / 2;
            dstrect.y = (SCREEN_HEIGHT - bmp->h) / 2;

            // program main loop
            bool done = false;
            while (!done) {
                // message processing loop
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    // check for messages
                    switch (event.type) {
                    // exit if the window is closed
                    case SDL_QUIT:
                        done = true;
                        break;

                    // check for keypresses
                    case SDL_KEYDOWN: {
                        // exit if ESCAPE is pressed
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                            done = true;
                        break;
                    }
                    } // end switch
                } // end of message processing

                // DRAWING STARTS HERE



                // DRAWING ENDS HERE

                // finally, update the screen :)
                SDL_UpdateWindowSurface( window );

            } // end main loop
            SDL_FreeSurface( bmp );



            //Wait two seconds
            //SDL_Delay( 2000 );
        }
    }

    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    printf("Exited cleanly\n");
    return 0;
}
