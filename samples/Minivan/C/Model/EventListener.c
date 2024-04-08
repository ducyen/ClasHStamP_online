/* File generated by Đức's ClasHStamP */
#define __EventListener_INTERNAL__
#include "CommonInclude.h"
#include "EventListener.h"
/** @public @pure @memberof EventListener */
void EventListener_actionPerformed(
    EventListener* pEventListener,
    Sprite* target
){
    if( pEventListener->vTbl == NULL || pEventListener->vTbl->pactionPerformed == NULL ){ return; }
    pEventListener->vTbl->pactionPerformed( pEventListener, target );
} /* EventListener_actionPerformed */

/** @public @memberof EventListener */
EventListener* EventListener_getNext(
    EventListener* pEventListener
){
    return pEventListener->m_next;
} /* EventListener_getNext */

EventListener* EventListener_Copy( EventListener* pEventListener, const EventListener* pSource ){
    pEventListener->m_action = pSource->m_action;
    pEventListener->m_source = pSource->m_source;
    pEventListener->m_event = pSource->m_event;
    pEventListener->m_next = pSource->m_next;
    return ( EventListener* )pEventListener;
}
