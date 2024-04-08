/* File generated by Đức's ClasHStamP */
#define __ObjsBuilder_INTERNAL__
#include "CommonInclude.h"
#include "ObjsBuilder.h"
#include "Primitive.h"                                          
#include "TranslationConstraint.h"                              
#include "AttachmentConstraint.h"                               
#include "RotationConstraint.h"                                 
#include "TrackToConstraint.h"                                  
#include "ContextImpl.h"                                        
#include "CarWheel.h"                                           
#include "CarBody.h"                                            
#include "MouseListener.h"                                      
#include "WindscreenWiper.h"                                    
#include "MotorRotor.h"                                         
#include "Button.h"                                             
#include "Lever.h"                                              
Sprite* g_objects[] = {
    &WindscreenWiper_Ctor(                                      /* rightWiperArm */
        P( { 0.45530726256983234, 0.3988275637571839, 0.31883172573324003, 0.06776726382902298 } )/* m_iniRect */,
        P( "WindscreenWiper.png" )                              /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */
    ),
    &WindscreenWiper_Ctor(                                      /* leftWiperArm */
        P( { 0.19776536312849158, 0.3994252873563218, 0.31883172573324003, 0.06776726382902298 } )/* m_iniRect */,
        P( "WindscreenWiper.png" )                              /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */
    ),
    &MotorRotor_Ctor(                                           /* rightWiperAxis */
        P( { 0.4480446927374302, 0.44803733387212646, 0.0223463687150838, 0.028735632183908046 } )/* m_iniRect */,
        P( "MotorRotor.png" )                                   /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */
    ),
    &MotorRotor_Ctor(                                           /* leftWiperAxis */
        P( { 0.18994413407821228, 0.4482758620689655, 0.0223463687150838, 0.028735632183908046 } )/* m_iniRect */,
        P( "MotorRotor.png" )                                   /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */
    ),
    &Lever_Ctor(                                                /* wiperLever */
        P( { 0.5770949720670391, 0.5672902074353449, 0.1329608938547486, 0.04597701149425287 } )/* m_iniRect */,
        P( "Lever.png" )                                        /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */
    ),
    &Button_Ctor(                                               /* powerButton */
        P( { 0.4949720670391061, 0.6118304373204023, 0.035754189944134075, 0.04597701149425287 } )/* m_iniRect */,
        P( "Button.png" )                                       /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( &MouseListener_Ctor( CarBody_EventProc, &carBody, CarBody_E_PWR_BTN, 
           &MouseListener_Ctor( ObjsBuilder_updateTransImage, NULL, 0, 
           null ) ) )/* m_mouseListeners */
    ),
    &CarBody_Ctor(                                              /* carBody */
        P( { 0.16424581005586592, 0.7483246901939655, 0.07150837988826815, 0.09195402298850575 } )/* m_iniRect */,
        P( "CarBody.png" )                                      /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */
    )
};
Sprite* getobj( int id ){
    return g_objects[ id ];
}
int ObjsBuilder_startSim(
    void  
){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *imageSurface = NULL;
    SDL_Texture *imageTexture = NULL;

    int nResult = S_OK;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        nResult = S_FALSE;
    }

    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;

    if (nResult == S_OK) {
        // Load image
        char sRelPath[256];
        sprintf(sRelPath, "%s/%s", getInputDir(), "ObjsBuilder/Main.png");
        imageSurface = IMG_Load(sRelPath);
        if (imageSurface == NULL) {
            printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
            nResult = S_FALSE;
        } else {
            SCREEN_WIDTH = imageSurface->w;
            SCREEN_HEIGHT = imageSurface->h;
        }
    }


    if (nResult == S_OK) {
        SDL_RendererInfo rendererInfo;
        int numRenderDrivers = SDL_GetNumRenderDrivers();
        SDL_RendererFlags hardwareAccelerationAvailable = SDL_RENDERER_SOFTWARE;

        for (int i = 0; i < numRenderDrivers; ++i) {
            if (SDL_GetRenderDriverInfo(i, &rendererInfo) == 0) {
                if (rendererInfo.flags & SDL_RENDERER_ACCELERATED) {
                    printf("Hardware acceleration is available for renderer: %s\n", rendererInfo.name);
                    hardwareAccelerationAvailable = SDL_RENDERER_ACCELERATED;
                    break;
                }
            }
        }

        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            nResult = S_FALSE;
        } else {
            renderer = SDL_CreateRenderer(window, -1, hardwareAccelerationAvailable);
            if (renderer == NULL) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
                nResult = S_FALSE;
            }
        }
    }

    if (nResult == S_OK && imageSurface != NULL) {
        // Create a texture from the loaded surface
        imageTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
        if (imageTexture == NULL) {
            printf("Unable to create texture! SDL_Error: %s\n", SDL_GetError());
            nResult = S_FALSE;
        } else{
            // Set the new texture as the render target
            SDL_SetRenderTarget(renderer, imageTexture);

            // Clear screen
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White
            SDL_RenderClear(renderer);

            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_draw0(g_objects[i], renderer);
            }

            // Reset the render target to the default
            SDL_SetRenderTarget(renderer, NULL);
        }
    }

    // Initialize SDL_image
    if (nResult == S_OK && !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        nResult = S_FALSE;
    }

    for( int i = 0; i < sizeof( g_objects ) / sizeof( g_objects[ 0 ] ) && nResult == S_OK; i++ ){
        if( Sprite_load( g_objects[ i ], renderer ) == false ){
            nResult = S_FALSE;
        }
    }

    ContextImpl context = ContextImpl_Ctor( );
    ContextImpl_Start( &context );

    CarBody_Start( carBody );

    SaveAllImages();
    ReleaseAllImages();

    if (nResult == S_OK) {
        bool quit = false;
        SDL_Event e;

        while (!quit) {
            //CarBody_EventProc(carBody, CarBody_TICK, NULL);
            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_update(g_objects[i]);
            }

            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                } else if (e.type ==  SDL_MOUSEBUTTONDOWN){
                    if (e.button.button == SDL_BUTTON_LEFT) {
                        for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                            int mouseX = e.button.x;
                            int mouseY = e.button.y;
                            Sprite_updateMouseState(g_objects[i], mouseX, mouseY, SDL_MOUSEBUTTONDOWN | SDL_BUTTON_LEFT);
                        }
                    }
                    break;

                } else if (e.type == SDL_KEYDOWN) {
                    ResetActionCounter();
                    if (e.key.keysym.sym == SDLK_x) {
                        //ContextImpl_EventProc(&context, ContextImpl_TMOUT, NULL);
                    }else if (e.key.keysym.sym == SDLK_r) {
                        //CarBody_EventProc(carBody, CarBody_R_KEY_HIT, NULL);
                    }else if (e.key.keysym.sym == SDLK_l) {
                        //CarBody_EventProc(carBody, CarBody_L_KEY_HIT, NULL);
                    }
                    SaveAllImages();
                    ReleaseAllImages();
                }
            }

            // Render the image texture
            if (imageTexture != NULL) {
                SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
            }

            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_draw1(g_objects[i], renderer);
            }

            // Update the screen
            SDL_RenderPresent(renderer);

            // Delay to control the animation speed
            SDL_Delay(50);
        }
    }

    for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
        Sprite_free(g_objects[i]);
    }

    // Free resources and close SDL
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(imageSurface);
    ReleaseAllImages();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
} /* ObjsBuilder_startSim */

/** @public @memberof ObjsBuilder */
int ObjsBuilder_updateTransImage(
    ObjsBuilder* pObjsBuilder,
    int y,
    void* z
){
    SaveAllImages();
    ReleaseAllImages();
    return 0;
} /* ObjsBuilder_updateTransImage */

ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource ){
    return ( ObjsBuilder* )pObjsBuilder;
}
