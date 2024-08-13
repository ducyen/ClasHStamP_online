﻿/* File generated by Đức's ClasHStamP */
#define __AttachmentConstraint_INTERNAL__
#include "CommonInclude.h"
#include "AttachmentConstraint.h"
/** @public @memberof AttachmentConstraint */
static void AttachmentConstraint_apply(
    Constraint* pConstraint,
    Sprite* target
){
    AttachmentConstraint* pAttachmentConstraint = ( AttachmentConstraint* )pConstraint;
    if( pAttachmentConstraint->m_influence == 0 ){
        return;
    }

    ImgSprite* child  = ( ImgSprite* )*pAttachmentConstraint->m_source;
    ImgSprite* parent = ( ImgSprite* )target;
    SDL_Point* childOfs  = ImgSprite_getOffset( child  );
    //SDL_Point* parentOfs = ImgSprite_getOffset( parent );

    // Calculate the new position of the child based on the parent's transformation
    double angleRad = ImgSprite_getRotation( parent ) * M_PI / 180.0f;
    double cosAngle = cos(angleRad);
    double sinAngle = sin(angleRad);

    // Calculate the initial offset between child and parent
    const SDL_Rect* childRect  = ImgSprite_getBoundary( child  );
    const SDL_Rect* parentRect = ImgSprite_getBoundary( parent );
    double offsetX = childRect->x+childRect->w/2 - parentRect->x-parentRect->w/2;
    double offsetY = childRect->y+childRect->h/2 - parentRect->y-parentRect->h/2;

    int deltaX = parentRect->x+parentRect->w/2 + offsetX * cosAngle - offsetY * sinAngle - childRect->x-childRect->w/2;
    int deltaY = parentRect->y+parentRect->h/2 + offsetX * sinAngle + offsetY * cosAngle - childRect->y-childRect->h/2;

    ImgSprite_setOffset( child, childOfs->x + deltaX, childOfs->y + deltaY );
} /* AttachmentConstraint_apply */

TransformConstraint* AttachmentConstraint_Copy( AttachmentConstraint* pAttachmentConstraint, const AttachmentConstraint* pSource ){
    TransformConstraint_Copy( ( TransformConstraint* )pAttachmentConstraint, ( TransformConstraint* )pSource );
    return ( Constraint* )pAttachmentConstraint;
}
const ConstraintVtbl gAttachmentConstraintVtbl = {
    .papply                      = AttachmentConstraint_apply,
};
