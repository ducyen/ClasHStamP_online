/* File generated by Đức's ClasHStamP */
#define __Primitive_INTERNAL__
#include "CommonInclude.h"
#include "Primitive.h"
/** @public @memberof Primitive */
static void Primitive_draw0(
    Sprite* pSprite,
    SDL_Renderer* renderer
){
    Primitive* pPrimitive = ( Primitive* )pSprite;
    // Get the size of the renderer
    int width, height;
    if (SDL_GetRendererOutputSize(renderer, &width, &height) != 0) {
        printf("Error getting renderer size: %s\n", SDL_GetError());
    }
    pPrimitive->m_rect = (SDL_Rect){
        pPrimitive->m_iniRect.x * width, 
        pPrimitive->m_iniRect.y * height, 
        pPrimitive->m_iniRect.w * width, 
        pPrimitive->m_iniRect.h * height
    };

	COLORREF lineColor;
	char lineType[ 10 ];
	int lineWidth;
	char isFilled[ 10 ];
	COLORREF fillColor;
	char rectType[ 10 ];

    int numRead = 0; // Number of characters read
    const char *currentPos = pPrimitive->m_imgPath; // Pointer to track position in the input string
    sscanf( currentPos, "%s %n", pPrimitive->primitiveType, &numRead ); currentPos += numRead;
	sscanf( currentPos, "%x %n", &lineColor   , &numRead ); currentPos += numRead;
	sscanf( currentPos, "%s %n", lineType     , &numRead ); currentPos += numRead;
	sscanf( currentPos, "%d %n", &lineWidth   , &numRead ); currentPos += numRead;
	sscanf( currentPos, "%s %n", isFilled     , &numRead ); currentPos += numRead;
	sscanf( currentPos, "%x %n", &fillColor   , &numRead ); currentPos += numRead;
	sscanf( currentPos, "%s %n", rectType     , &numRead ); currentPos += numRead;
    sscanf( currentPos, "%s %n", pPrimitive->fontFace     , &numRead ); currentPos += numRead;
    sscanf( currentPos, "%u %n", &pPrimitive->fontSize    , &numRead ); currentPos += numRead;
    pPrimitive->textLabel = currentPos;

    if( strcmp( pPrimitive->primitiveType, "Rectangle" ) == 0 ){
        int x1 = pPrimitive->m_rect.x;
        int y1 = pPrimitive->m_rect.y;
        int x2 = pPrimitive->m_rect.x + pPrimitive->m_rect.w;
        int y2 = pPrimitive->m_rect.y + pPrimitive->m_rect.h;
        if( strcmp( isFilled, "true" ) == 0 ){
            if( strcmp( rectType, "round" ) == 0 ){
                roundedBoxRGBA(renderer, x1, y1, x2, y2, 10, LOBYTE((fillColor)>>16), LOBYTE(((WORD)(fillColor)) >> 8), LOBYTE(fillColor), 0xFF );
            } else{
                boxRGBA(renderer, x1, y1, x2, y2, LOBYTE((fillColor)>>16), LOBYTE(((WORD)(fillColor)) >> 8), LOBYTE(fillColor), 0xFF );
            }
        } else{
            if( strcmp( rectType, "round" ) == 0 ){
                roundedRectangleRGBA( renderer, x1, y1, x2, y2, 10, LOBYTE((lineColor)>>16), LOBYTE(((WORD)(lineColor)) >> 8), LOBYTE(lineColor), 0xFF );
            } else{
                rectangleRGBA( renderer, x1, y1, x2, y2, LOBYTE((lineColor)>>16), LOBYTE(((WORD)(lineColor)) >> 8), LOBYTE(lineColor), 0xFF );
            }
        }
    }else if( strcmp( pPrimitive->primitiveType, "Oval" ) == 0 ){
        int rx = pPrimitive->m_rect.w / 2;
        int ry = pPrimitive->m_rect.h / 2;
        int x = pPrimitive->m_rect.x + rx;
        int y = pPrimitive->m_rect.y + ry;
        if( strcmp( isFilled, "true" ) == 0 ){
            filledEllipseRGBA( renderer, x, y, rx, ry, LOBYTE((fillColor)>>16), LOBYTE(((WORD)(fillColor)) >> 8), LOBYTE(fillColor), 0xFF );
        } else{
            ellipseRGBA( renderer, x, y, rx, ry, LOBYTE((lineColor)>>16), LOBYTE(((WORD)(lineColor)) >> 8), LOBYTE(lineColor), 0xFF );
        }
    }else if( strcmp( pPrimitive->primitiveType, "Line" ) == 0 ){
        int x1 = pPrimitive->m_rect.x;
        int y1 = pPrimitive->m_rect.y;
        int x2 = pPrimitive->m_rect.w;
        int y2 = pPrimitive->m_rect.h;
        lineRGBA( renderer, x1, y1, x2, y2, LOBYTE((lineColor)>>16), LOBYTE(((WORD)(lineColor)) >> 8), LOBYTE(lineColor), 0xFF );
    }else if( strcmp( pPrimitive->primitiveType, "Text" ) == 0 ){
        int x = pPrimitive->m_rect.x;
        int y = pPrimitive->m_rect.y;
        const char* text = pPrimitive->textLabel;
        SDL_Color textColor = { 0, 0, 0, 255 }; // White color
        static char fontPath[1024];
        sprintf( fontPath, "%s/../../../../resources/Arial.ttf", getInputDir());
        TTF_Font* font = TTF_OpenFont(fontPath, pPrimitive->fontSize);
        if (!font) {
            printf("Failed to load font: %s\n", TTF_GetError());
        }
        char* next_line;
        char copy[1024]; // Ensure your buffer is large enough to hold the text
        strncpy(copy, text, sizeof(copy));
        copy[sizeof(copy) - 1] = '\0';
        char* line = strtok_r(copy, "\n", &next_line);
        while (line != NULL) {
            SDL_Surface* surface = TTF_RenderText_Solid(font, line, textColor);
            if (surface != NULL) {
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                if (texture != NULL) {
                    SDL_Rect dstRect = { x, y, surface->w, surface->h };
                    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                    SDL_DestroyTexture(texture);
                    y += surface->h; // Move y down for the next line
                }
                SDL_FreeSurface(surface);
            }
            line = strtok_r(NULL, "\n", &next_line);
        }
        TTF_CloseFont(font);        
    }
    
} /* Primitive_draw0 */

/** @public @memberof Primitive */
static void Primitive_update(
    Sprite* pSprite
){
    Primitive* pPrimitive = ( Primitive* )pSprite;
} /* Primitive_update */

/** @public @memberof Primitive */
static void Primitive_draw1(
    Sprite* pSprite,
    SDL_Renderer* renderer
){
    Primitive* pPrimitive = ( Primitive* )pSprite;
    // Get the size of the renderer

    pPrimitive->textLabel = "Hello";

    if( strcmp( pPrimitive->primitiveType, "Rectangle" ) == 0 ){
    }else if( strcmp( pPrimitive->primitiveType, "Oval" ) == 0 ){
    }else if( strcmp( pPrimitive->primitiveType, "Line" ) == 0 ){
    }else if( strcmp( pPrimitive->primitiveType, "Text" ) == 0 ){
        int x = pPrimitive->m_rect.x;
        int y = pPrimitive->m_rect.y;
        const char* text = pPrimitive->textLabel;
        SDL_Color textColor = { 0, 0, 0, 255 }; // White color
        static char fontPath[1024];
        sprintf( fontPath, "%s/../../../../resources/Arial.ttf", getInputDir());
        TTF_Font* font = TTF_OpenFont(fontPath, pPrimitive->fontSize);
        if (!font) {
            printf("Failed to load font: %s\n", TTF_GetError());
        }
        char* next_line;
        char copy[1024]; // Ensure your buffer is large enough to hold the text
        strncpy(copy, text, sizeof(copy));
        copy[sizeof(copy) - 1] = '\0';
        char* line = strtok_r(copy, "\n", &next_line);
        while (line != NULL) {
            SDL_Surface* surface = TTF_RenderText_Solid(font, line, textColor);
            if (surface != NULL) {
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                if (texture != NULL) {
                    SDL_Rect dstRect = { x, y, surface->w, surface->h };
                    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                    SDL_DestroyTexture(texture);
                    y += surface->h; // Move y down for the next line
                }
                SDL_FreeSurface(surface);
            }
            line = strtok_r(NULL, "\n", &next_line);
        }
        TTF_CloseFont(font);        
    }
} /* Primitive_draw1 */

/** @public @memberof Primitive */
static bool Primitive_load(
    Sprite* pSprite,
    SDL_Renderer* renderer
){
    Primitive* pPrimitive = ( Primitive* )pSprite;
    return true;
} /* Primitive_load */

/** @public @memberof Primitive */
static void Primitive_free(
    Sprite* pSprite
){
    Primitive* pPrimitive = ( Primitive* )pSprite;
} /* Primitive_free */

Sprite* Primitive_Copy( Primitive* pPrimitive, const Primitive* pSource ){
    Sprite_Copy( ( Sprite* )pPrimitive, ( Sprite* )pSource );
    return ( Sprite* )pPrimitive;
}
const SpriteVtbl gPrimitiveVtbl = {
    .pdraw0                      = Primitive_draw0,
    .pupdate                     = Primitive_update,
    .pdraw1                      = Primitive_draw1,
    .pload                       = Primitive_load,
    .pfree                       = Primitive_free,
};
