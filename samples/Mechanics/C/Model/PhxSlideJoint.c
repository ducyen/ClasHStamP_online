/* File generated by Đức's ClasHStamP */
#define __PhxSlideJoint_INTERNAL__
#include "CommonInclude.h"
#include "PhxSlideJoint.h"
#include "PhxSprite.h"                                          
/** @public @memberof PhxSlideJoint */
static void PhxSlideJoint_apply(
    PhxJoint* pPhxJoint,
    Sprite* target
){
    PhxSlideJoint* pPhxSlideJoint = ( PhxSlideJoint* )pPhxJoint;
    cpSpace *space = ObjsBuilder_getPhxSpace();
    PhxSprite* pTarget = ( PhxSprite* )target;
    cpBody* pBodyTgt = PhxSprite_getBody( pTarget );
    cpBody* pBodySrc;
    if( pPhxSlideJoint->m_source == null ){
        pBodySrc = cpSpaceGetStaticBody( space );
    }else{
        PhxSprite* pSource = ( PhxSprite* )( *pPhxSlideJoint->m_source );
        pBodySrc = PhxSprite_getBody( pSource );
    }

    cpVect anchorSrc = cpvzero;
    if( pPhxSlideJoint->m_anchorSrc != null){
        const SDL_Point* pCenter = Sprite_getCenter( *pPhxSlideJoint->m_anchorSrc );
        cpVect center = cpv( pCenter->x, ObjsBuilder_getScreenHeight() - pCenter->y );
        anchorSrc = cpBodyWorldToLocal( pBodySrc, center );
    }

    cpVect anchorTgt = cpvzero;
    if( pPhxSlideJoint->m_anchorTgt != null){
        const SDL_Point* pCenter = Sprite_getCenter( *pPhxSlideJoint->m_anchorTgt );
        cpVect center = cpv( pCenter->x, ObjsBuilder_getScreenHeight() - pCenter->y );
        anchorTgt = cpBodyWorldToLocal( pBodyTgt, center );
    }
    if( pPhxSlideJoint->m_cpJoint == null ){
        pPhxSlideJoint->m_cpJoint = cpSpaceAddConstraint(
            space, 
            cpSlideJointNew(
                pBodySrc, 
                pBodyTgt, 
                anchorSrc, 
                anchorTgt,
                pPhxSlideJoint->min,
                pPhxSlideJoint->max
            )
        );
    }
} /* PhxSlideJoint_apply */

PhxJoint* PhxSlideJoint_Copy( PhxSlideJoint* pPhxSlideJoint, const PhxSlideJoint* pSource ){
    PhxJoint_Copy( ( PhxJoint* )pPhxSlideJoint, ( PhxJoint* )pSource );
    pPhxSlideJoint->min = pSource->min;
    pPhxSlideJoint->max = pSource->max;
    pPhxSlideJoint->m_next0 = pSource->m_next0;
    return ( PhxJoint* )pPhxSlideJoint;
}
const PhxJointVtbl gPhxSlideJointVtbl = {
    .papply                      = PhxSlideJoint_apply,
};
