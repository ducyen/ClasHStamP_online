﻿/* File generated by Đức's ClasHStamP */
#define __WindscreenWiper_INTERNAL__
#include "CommonInclude.h"
#include "WindscreenWiper.h"
#include "ObjsBuilder.h"                                        
/** @public @memberof WindscreenWiper */
void WindscreenWiper_moveRight(
    WindscreenWiper* pWindscreenWiper
){
} /* WindscreenWiper_moveRight */

/** @public @memberof WindscreenWiper */
void WindscreenWiper_moveLeft(
    WindscreenWiper* pWindscreenWiper
){
} /* WindscreenWiper_moveLeft */

ImgSprite* WindscreenWiper_Copy( WindscreenWiper* pWindscreenWiper, const WindscreenWiper* pSource ){
    ImgSprite_Copy( ( ImgSprite* )pWindscreenWiper, ( ImgSprite* )pSource );
    pWindscreenWiper->x = pSource->x;
    return ( Sprite* )pWindscreenWiper;
}
