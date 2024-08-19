/* File generated by Đức's ClasHStamP */
#define __EventListener_INTERNAL__
#include "CommonInclude.h"
#include "EventListener.h"
/** @public @memberof EventListener */
void EventListener_actionPerformed(
    EventListener* pEventListener,
    Sprite* target,
    void* pEventParams
){
    if( pEventListener->m_action != null ){
        if( pEventListener->m_source != null ){
            pEventListener->m_action( *pEventListener->m_source, pEventListener->m_event, pEventParams );
        } else{
            pEventListener->m_action( target, pEventListener->m_event, pEventParams );
        }
    }
} /* EventListener_actionPerformed */

/** @public @memberof EventListener */
int EventListener_getType(
    EventListener* pEventListener
){
    return pEventListener->m_type;
} /* EventListener_getType */

/** @public @memberof EventListener */
EventListener* EventListener_getNext(
    EventListener* pEventListener
){
    return pEventListener->m_next;
} /* EventListener_getNext */

EventListener* EventListener_Copy( EventListener* pEventListener, const EventListener* pSource ){
    pEventListener->m_type = pSource->m_type;
    pEventListener->m_action = pSource->m_action;
    pEventListener->m_source = pSource->m_source;
    pEventListener->m_event = pSource->m_event;
    pEventListener->m_next = pSource->m_next;
    return ( EventListener* )pEventListener;
}
