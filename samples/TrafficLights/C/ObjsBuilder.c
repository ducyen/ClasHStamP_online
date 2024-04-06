/* File generated by Đức's ClasHStamP */
#define __ObjsBuilder_INTERNAL__
#include "CommonInclude.h"
#include "ObjsBuilder.h"
#include "GreenLight.h"                                         
#include "YellowLight.h"                                        
#include "RedLight.h"                                           
#include "Primitive.h"                                          
#include "TranslationConstraint.h"                              
#include "AttachmentConstraint.h"                               
#include "RotationConstraint.h"                                 
#include "TrackToConstraint.h"                                  
#include "ContextImpl.h"                                        
#include "CarWheel.h"                                           
#include "CarBody.h"                                            
Sprite* g_objects[] = {
    &RedLight_Ctor(                                             /* westRedLight */
        P( { 0.3269397889509623, 0.41036806363823086, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "RedLight.png" )                                     /* m_imgPath */,
        P( &AttachmentConstraint_Ctor( &eastRedLight, 1, &TranslationConstraint_Ctor( &eastRedLight, 1, &RotationConstraint_Ctor( &eastRedLight, 1, null ) ) ) )/* m_constraints */
    ),
    &RedLight_Ctor(                                             /* eastRedLight */
        P( { 0.6504034761018004, 0.5204598067574969, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "RedLight.png" )                                     /* m_imgPath */,
        P( &AttachmentConstraint_Ctor( &eastGreenLight, 1, &TranslationConstraint_Ctor( &eastGreenLight, 1, &RotationConstraint_Ctor( &eastGreenLight, 0, null ) ) ) )/* m_constraints */
    ),
    &YellowLight_Ctor(                                          /* westYellowLight */
        P( { 0.27721911855990083, 0.41036806363823086, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "YellowLight.png" )                                  /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &GreenLight_Ctor(                                           /* westGreenLight */
        P( { 0.2280571073867165, 0.41036806363823086, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "GreenLight.png" )                                   /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &YellowLight_Ctor(                                          /* eastYellowLight */
        P( { 0.6984481688392306, 0.5204598067574969, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "YellowLight.png" )                                  /* m_imgPath */,
        P( &TrackToConstraint_Ctor( &eastGreenLight, 1, null )  )/* m_constraints */
    ),
    &GreenLight_Ctor(                                           /* eastGreenLight */
        P( { 0.7476101800124149, 0.5204598067574969, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "GreenLight.png" )                                   /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &GreenLight_Ctor(                                           /* northGreenLight */
        P( { 0.5788950962135322, 0.13438559068191155, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "GreenLight.png" )                                   /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &YellowLight_Ctor(                                          /* northYellowLight */
        P( { 0.5788950962135322, 0.19588999526450318, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "YellowLight.png" )                                  /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &RedLight_Ctor(                                             /* northRedLight */
        P( { 0.5788950962135322, 0.2579392672531836, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "RedLight.png" )                                     /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &RedLight_Ctor(                                             /* southRedLight */
        P( { 0.4180012414649288, 0.5930327219978091, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "RedLight.png" )                                     /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &YellowLight_Ctor(                                          /* southYellowLight */
        P( { 0.4180012414649288, 0.6556782101533617, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "YellowLight.png" )                                  /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &GreenLight_Ctor(                                           /* southGreenLight */
        P( { 0.4180012414649288, 0.7171826147359532, 0.05865921787709497, 0.07268892540356313 } )/* m_iniRect */,
        P( "GreenLight.png" )                                   /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &Primitive_Ctor(                                            /* Rectangle_4fh */
        P( { 0.07610180012414665, 0.06982869839449543, 0.32625698324022345, 0.3241590214067278 } )/* 4fh-26d23a6dbabdf00606cec0dc8ca46101 */,
        P( "Rectangle 000000 line 1 null FFFFFF null" )         /* Rectangle_4fh */
    ),
    &Primitive_Ctor(                                            /* Rectangle_phs */
        P( { 0.6459342023587836, 0.06982869839449542, 0.32625698324022345, 0.3241590214067278 } )/* phs-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Rectangle 000000 line 1 null FFFFFF null" )         /* Rectangle_phs */
    ),
    &Primitive_Ctor(                                            /* Rectangle_ps7 */
        P( { 0.07610180012414665, 0.6371069858562691, 0.32625698324022345, 0.3241590214067278 } )/* ps7-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Rectangle 000000 line 1 null FFFFFF null" )         /* Rectangle_ps7 */
    ),
    &Primitive_Ctor(                                            /* Rectangle_q2m */
        P( { 0.6459342023587836, 0.6371069858562691, 0.32625698324022345, 0.3241590214067278 } )/* q2m-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Rectangle 000000 line 1 null FFFFFF null" )         /* Rectangle_q2m */
    ),
    &Primitive_Ctor(                                            /* Oval_rex */
        P( { 0.3152079453755433, 0.22359455351301585, 0.03910614525139665, 0.05198776758409788 } )/* rex-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_rex */
    ),
    &Primitive_Ctor(                                            /* Oval_rlz */
        P( { 0.307386716325264, 0.25417559326836753, 0.03910614525139665, 0.05198776758409788 } )/* rlz-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_rlz */
    ),
    &Primitive_Ctor(                                            /* Oval_rwe */
        P( { 0.32079453755431425, 0.25417559326836753, 0.03910614525139665, 0.05198776758409788 } )/* rwe-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_rwe */
    ),
    &Primitive_Ctor(                                            /* Rectangle_sbx */
        P( { 0.3286157666045936, 0.29851810091362746, 0.012290502793296089, 0.03211009174311927 } )/* sbx-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Rectangle 000000 line 1 true 996633 null" )         /* Rectangle_sbx */
    ),
    &Primitive_Ctor(                                            /* Oval_swa */
        P( { 0.7375543140906272, 0.24076691038309972, 0.03910614525139665, 0.05198776758409788 } )/* swa-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_swa */
    ),
    &Primitive_Ctor(                                            /* Oval_swb */
        P( { 0.7297330850403478, 0.2713479501384514, 0.03910614525139665, 0.05198776758409788 } )/* swb-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_swb */
    ),
    &Primitive_Ctor(                                            /* Oval_swc */
        P( { 0.7431409062693981, 0.2713479501384514, 0.03910614525139665, 0.05198776758409788 } )/* swc-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_swc */
    ),
    &Primitive_Ctor(                                            /* Rectangle_swd */
        P( { 0.7509621353196775, 0.31569045778371135, 0.012290502793296089, 0.03211009174311927 } )/* swd-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Rectangle 000000 line 1 true 996633 null" )         /* Rectangle_swd */
    ),
    &Primitive_Ctor(                                            /* Oval_tjf */
        P( { 0.718559900682806, 0.7171826147359532, 0.03910614525139665, 0.05198776758409788 } )/* tjf-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_tjf */
    ),
    &Primitive_Ctor(                                            /* Oval_tjg */
        P( { 0.7107386716325266, 0.7477636544913049, 0.03910614525139665, 0.05198776758409788 } )/* tjg-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_tjg */
    ),
    &Primitive_Ctor(                                            /* Oval_tjh */
        P( { 0.7241464928615768, 0.7477636544913049, 0.03910614525139665, 0.05198776758409788 } )/* tjh-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_tjh */
    ),
    &Primitive_Ctor(                                            /* Rectangle_tji */
        P( { 0.7319677219118562, 0.7921061621365649, 0.012290502793296089, 0.03211009174311927 } )/* tji-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Rectangle 000000 line 1 true 996633 null" )         /* Rectangle_tji */
    ),
    &Primitive_Ctor(                                            /* Oval_u0q */
        P( { 0.28504034761018016, 0.7334372610856269, 0.03910614525139665, 0.05198776758409788 } )/* u0q-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_u0q */
    ),
    &Primitive_Ctor(                                            /* Oval_u0r */
        P( { 0.27721911855990083, 0.7640183008409785, 0.03910614525139665, 0.05198776758409788 } )/* u0r-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_u0r */
    ),
    &Primitive_Ctor(                                            /* Oval_u0s */
        P( { 0.2906269397889511, 0.7640183008409785, 0.03910614525139665, 0.05198776758409788 } )/* u0s-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Oval 000000 line 1 true 66FF33 oval" )              /* Oval_u0s */
    ),
    &Primitive_Ctor(                                            /* Rectangle_u0t */
        P( { 0.2984481688392305, 0.8083608084862385, 0.012290502793296089, 0.03211009174311927 } )/* u0t-6f7de2bd597eab2992ffddef9cceacc8 */,
        P( "Rectangle 000000 line 1 true 996633 null" )         /* Rectangle_u0t */
    ),
    &CarWheel_Ctor(                                             /* rearWheels */
        P( { 0.12675356921166978, 0.5632867583036018, 0.02867783985102426, 0.039245667686034685 } )/* m_iniRect */,
        P( "CarWheel.png" )                                     /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &CarWheel_Ctor(                                             /* frontWheels */
        P( { 0.20825574177529488, 0.5630309208290857, 0.02867783985102426, 0.039245667686034685 } )/* m_iniRect */,
        P( "CarWheel.png" )                                     /* m_imgPath */,
        P( null )                                               /* m_constraints */
    ),
    &CarBody_Ctor(                                              /* carBody */
        P( { 0.10837988826815649, 0.46661669374362885, 0.1452513966480447, 0.19877675840978593 } )/* m_iniRect */,
        P( "CarBody.png" )                                      /* m_imgPath */,
        P( &AttachmentConstraint_Ctor( &rearWheels, 1, &TranslationConstraint_Ctor( &rearWheels, 1, &AttachmentConstraint_Ctor( &frontWheels, 1, &TranslationConstraint_Ctor( &frontWheels, 1, null ) ) ) ) )/* m_constraints */
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
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                } else if (e.type == SDL_KEYDOWN) {
                    ResetActionCounter();
                    if (e.key.keysym.sym == SDLK_x) {
                        ContextImpl_EventProc(&context, ContextImpl_TMOUT, NULL);
                    }else if (e.key.keysym.sym == SDLK_r) {
                        CarBody_EventProc(carBody, CarBody_R_KEY_HIT, NULL);
                    }else if (e.key.keysym.sym == SDLK_l) {
                        CarBody_EventProc(carBody, CarBody_L_KEY_HIT, NULL);
                    }
                    SaveAllImages();
                    ReleaseAllImages();
                }
            }

            CarBody_EventProc(carBody, CarBody_TICK, NULL);

            // Render the image texture
            if (imageTexture != NULL) {
                SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
            }

        #if 0
            static int s_pos_x = 0;
            ImgSprite_setOffset( westRedLight, s_pos_x++, 0 );
            if( s_pos_x > SCREEN_WIDTH ){
                s_pos_x = 0;
            }
            static double s_angle = 0;
            ImgSprite_setRotation( westRedLight, s_angle );
            ImgSprite_setRotation( eastRedLight, s_angle += 1. );
        #endif

            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_update(g_objects[i]);
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

ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource ){
    return ( ObjsBuilder* )pObjsBuilder;
}
