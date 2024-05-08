/* File generated by Đức's ClasHStamP */
#define __FlexButton_INTERNAL__
#include "CommonInclude.h"
#include "FlexButton.h"
/** @public @memberof FlexButton */
static bool FlexButton_load(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    // Get the size of the renderer
    int width, height;
    if (SDL_GetRendererOutputSize(renderer, &width, &height) != 0) {
        printf("Error getting renderer size: %s\n", SDL_GetError());
    }

    pFlexButton->m_rect = (SDL_Rect){
        pFlexButton->m_iniRect.x * width, 
        pFlexButton->m_iniRect.y * height, 
        pFlexButton->m_iniRect.w * width, 
        pFlexButton->m_iniRect.h * height
    };

    FlexButton_Start( pFlexButton );
} /* FlexButton_load */

/** @public @memberof FlexButton */
static void FlexButton_draw0(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    FlexButton_EventProc( pFlexButton, FlexButton_DRAW0, renderer );
} /* FlexButton_draw0 */

/** @public @memberof FlexButton */
static void FlexButton_draw1(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    FlexButton_EventProc( pFlexButton, FlexButton_DRAW1, renderer );
} /* FlexButton_draw1 */

/** @public @memberof FlexButton */
static void FlexButton_updateMouseState(
    FlexButton* pFlexButton,
    int x,
    int y,
    int mouseEvent
){
    FlexButton* sprite = pFlexButton;
    int mouseX = x;
    int mouseY = y;
    EventListener* pCurListener = sprite->m_mouseListeners;
    MouseEventParams mouseEventParams = { .pos.x = mouseX, .pos.y = mouseY };
    while( pCurListener != null ){
        if( EventListener_getType( pCurListener ) == mouseEvent ){
            EventListener_actionPerformed( pCurListener, sprite, &mouseEventParams );
        }
        pCurListener = EventListener_getNext( pCurListener );
    }
} /* FlexButton_updateMouseState */

/** @public @memberof FlexButton */
bool FlexButton_IsInRect(
    FlexButton* pFlexButton,
    MouseEventParams* pEventPrams
){
    FlexButton* sprite = pFlexButton;
    int mouseX = pEventPrams->pos.x;
    int mouseY = pEventPrams->pos.y;
    SDL_Rect rect = sprite->m_rect;
    rect.x += sprite->m_offset.x;
    rect.y += sprite->m_offset.y;

    if (mouseX >= rect.x && mouseX < rect.x + rect.w &&
        mouseY >= rect.y && mouseY < rect.y + rect.h
    ) {
        return true;
    }
    return false;
} /* FlexButton_IsInRect */

/** @public @memberof FlexButton */
bool FlexButton_OnPushBtnPressed(
    FlexButton* pFlexButton
){
    pFlexButton->m_value = pFlexButton->m_valueTmp;
    FlexButton* sprite = pFlexButton;
    EventListener* pCurListener = sprite->m_buttonListeners;
    while( pCurListener != null ){
        if( EventListener_getType( pCurListener ) == MDD_ON_CLICK ){
            EventListener_actionPerformed( pCurListener, sprite, null );
        }
        pCurListener = EventListener_getNext( pCurListener );
    }
} /* FlexButton_OnPushBtnPressed */

/** @public @memberof FlexButton */
void FlexButton_DrawPushStyle(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    int x = pFlexButton->m_rect.x + pFlexButton->m_rect.w/2;
    int y = pFlexButton->m_rect.y + pFlexButton->m_rect.h/2;
    int r = pFlexButton->m_rect.w > pFlexButton->m_rect.h ? pFlexButton->m_rect.h / 2 : pFlexButton->m_rect.w / 2;
    circleRGBA( renderer, x, y, r, 0x00, 0x00, 0x00, 0xFF );
    filledCircleRGBA( renderer, x, y, r-4, 0x00, 0x00, 0x00, 0xFF );

} /* FlexButton_DrawPushStyle */

/** @public @memberof FlexButton */
void FlexButton_DrawSelectStyle(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    int x = pFlexButton->m_rect.x + pFlexButton->m_rect.w/2;
    int r = pFlexButton->m_rect.h / ( pFlexButton->m_valueMax * 2 );
    for( int i = 0; i < pFlexButton->m_valueMax; i++ ){
        int y = pFlexButton->m_rect.y + r + i * 2 * r;
        circleRGBA( renderer, x, y, r, 0x00, 0x00, 0x00, 0xFF );
    }
} /* FlexButton_DrawSelectStyle */

/** @public @memberof FlexButton */
void FlexButton_DrawToggleStyle(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    int r = pFlexButton->m_rect.h / 2;
    int x1 = pFlexButton->m_rect.x + r;
    int y = pFlexButton->m_rect.y + r;
    arcRGBA( renderer, x1, y, r, 90, 279, 0x00, 0x00, 0x00, 0xFF );

    int x2 = pFlexButton->m_rect.x + pFlexButton->m_rect.w - r;
    arcRGBA( renderer, x2, y, r, -90, 90, 0x00, 0x00, 0x00, 0xFF );
    
    y = pFlexButton->m_rect.y;
    lineRGBA( renderer, x1, y, x2, y, 0x00, 0x00, 0x00, 0xFF );

    y = pFlexButton->m_rect.y + pFlexButton->m_rect.h;
    lineRGBA( renderer, x1, y, x2, y, 0x00, 0x00, 0x00, 0xFF );
} /* FlexButton_DrawToggleStyle */

/** @public @memberof FlexButton */
void FlexButton_DrawSlideStyle(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    int r = pFlexButton->m_rect.h / 2;
    int x1 = pFlexButton->m_rect.x + r;
    int y = pFlexButton->m_rect.y + r;
    arcRGBA( renderer, x1, y, r, 90, 279, 0x00, 0x00, 0x00, 0xFF );

    int x2 = pFlexButton->m_rect.x + pFlexButton->m_rect.w - r;
    arcRGBA( renderer, x2, y, r, -90, 90, 0x00, 0x00, 0x00, 0xFF );
    
    y = pFlexButton->m_rect.y;
    lineRGBA( renderer, x1, y, x2, y, 0x00, 0x00, 0x00, 0xFF );

    y = pFlexButton->m_rect.y + pFlexButton->m_rect.h;
    lineRGBA( renderer, x1, y, x2, y, 0x00, 0x00, 0x00, 0xFF );
} /* FlexButton_DrawSlideStyle */

/** @public @memberof FlexButton */
void FlexButton_DrawPressed(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    int currentValue = pFlexButton->m_valueTmp;
    if( pFlexButton->m_rect.h >= pFlexButton->m_rect.w ){
        int x = pFlexButton->m_rect.x + pFlexButton->m_rect.w/2;
        int r = pFlexButton->m_rect.w / 2;
        int clampKnopY = pFlexButton->m_knobPos.y - (pFlexButton->m_rect.y + r);
        if( clampKnopY < 0 ){
            clampKnopY = 0;
        }
        if( clampKnopY > pFlexButton->m_rect.h - 2*r ){
            clampKnopY = pFlexButton->m_rect.h - 2*r;
        }
        pFlexButton->m_valueTmp = 0;
        if ((pFlexButton->m_rect.h - 2*r) != 0){
            pFlexButton->m_valueTmp = (( pFlexButton->m_valueMax-1) * clampKnopY + (pFlexButton->m_rect.h - 2*r)/2)/ (pFlexButton->m_rect.h - 2*r);
            clampKnopY = (pFlexButton->m_valueTmp * (pFlexButton->m_rect.h - 2*r) + ( pFlexButton->m_valueMax-1)/2)/ ( pFlexButton->m_valueMax-1);
        }
        int y = pFlexButton->m_rect.y + r + clampKnopY;
        r = r - 4;
        filledCircleRGBA( renderer, x, y, r, 0xFF, 0xFF, 0xFF, 0xFF );
        circleRGBA( renderer, x, y, r, 0x00, 0x00, 0x00, 0xFF );
    }else{
        int y = pFlexButton->m_rect.y + pFlexButton->m_rect.h/2;
        int r = pFlexButton->m_rect.h / 2;
        int clampKnopX = pFlexButton->m_knobPos.x - (pFlexButton->m_rect.x + r);
        if( clampKnopX < 0 ){
            clampKnopX = 0;
        }
        if( clampKnopX > pFlexButton->m_rect.w - 2*r ){
            clampKnopX = pFlexButton->m_rect.w - 2*r;
        }
        pFlexButton->m_valueTmp = 0;
        if( (pFlexButton->m_rect.w - 2*r) != 0 ){
            pFlexButton->m_valueTmp = (( pFlexButton->m_valueMax-1) * clampKnopX + (pFlexButton->m_rect.w - 2*r)/2 )/ (pFlexButton->m_rect.w - 2*r);
            clampKnopX = (pFlexButton->m_valueTmp * (pFlexButton->m_rect.w - 2*r) + ( pFlexButton->m_valueMax-1)/2 )/ ( pFlexButton->m_valueMax-1);
        }
        int x = pFlexButton->m_rect.x + r + clampKnopX;
        r = r - 4;
        filledCircleRGBA( renderer, x, y, r, 0xFF, 0xFF, 0xFF, 0xFF );
        circleRGBA( renderer, x, y, r, 0x00, 0x00, 0x00, 0xFF );
    }
    if( currentValue != pFlexButton->m_valueTmp ){
        FlexButton* sprite = pFlexButton;
        EventListener* pCurListener = sprite->m_buttonListeners;
        while( pCurListener != null ){
            if( EventListener_getType( pCurListener ) == MDD_ON_VALUE_CHANGED ){
                pFlexButton->m_value = pFlexButton->m_valueTmp;
                EventListener_actionPerformed( pCurListener, sprite, null );
            }
            pCurListener = EventListener_getNext( pCurListener );
        }        
    }
} /* FlexButton_DrawPressed */

/** @public @memberof FlexButton */
void FlexButton_DrawKnob(
    FlexButton* pFlexButton,
    SDL_Renderer* renderer
){
    if( pFlexButton->m_rect.h >= pFlexButton->m_rect.w ){
        int x = pFlexButton->m_rect.x + pFlexButton->m_rect.w/2;
        int r = pFlexButton->m_rect.w / 2;
        int clampKnopY = 0;
        if ((pFlexButton->m_rect.h - 2*r) != 0){
            clampKnopY = (pFlexButton->m_value * (pFlexButton->m_rect.h - 2*r) + ( pFlexButton->m_valueMax-1)/2)/ ( pFlexButton->m_valueMax-1);
        }
        int y = pFlexButton->m_rect.y + r + clampKnopY;
        r = r - 4;
        filledCircleRGBA( renderer, x, y, r, 0x00, 0x00, 0x00, 0xFF );
    }else{
        int y = pFlexButton->m_rect.y + pFlexButton->m_rect.h/2;
        int r = pFlexButton->m_rect.h / 2;
        int clampKnopX = 0;
        if( (pFlexButton->m_rect.w - 2*r) != 0 ){
            clampKnopX = (pFlexButton->m_value * (pFlexButton->m_rect.w - 2*r) + ( pFlexButton->m_valueMax-1)/2 )/ ( pFlexButton->m_valueMax-1);
        }
        int x = pFlexButton->m_rect.x + r + clampKnopX;
        r = r - 4;
        filledCircleRGBA( renderer, x, y, r, 0x00, 0x00, 0x00, 0xFF );
    }
} /* FlexButton_DrawKnob */

const TCHAR* FlexButtonEvent_toString( FlexButton_EVENT value ){
    switch( value ){
    case FlexButton_DRAW0: return _T( "DRAW0" );
    case FlexButton_DRAW1: return _T( "DRAW1" );
    case FlexButton_MOUSE_DOWN: return _T( "MOUSE_DOWN" );
    case FlexButton_MOUSE_MOVE: return _T( "MOUSE_MOVE" );
    case FlexButton_MOUSE_UP: return _T( "MOUSE_UP" );
    default: return _T( "FlexButton_UNKNOWN" );
    }
}
static void Ready_Region1_BgnTrans( FlexButton *pReady, Ready_Region1* pStm, uint64_t targetState, uint64_t initState );
static void Ready_Region1_EndTrans( FlexButton *pReady, Ready_Region1* pStm );
static BOOL Ready_Region1_Reset( FlexButton* pReady, Ready_Region1* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
static BOOL Ready_Region1_Abort( FlexButton* pReady, Ready_Region1* pStm );
static BOOL Ready_Region1_EventProc( FlexButton* pReady, Ready_Region1* pStm, FlexButton_EVENT nEventId, void* pEventParams );
static BOOL Ready_Region1_RunToCompletion( FlexButton* pReady, Ready_Region1* pStm );
static void Ready_Region1_Hold_Entry( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, Ready_Region1_Hold ) ){
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	514	280	231	304	-126	-25	1199	764" );
    }
}
static BOOL Ready_Region1_Hold_EventProc( FlexButton* pFlexButton, Ready_Region1* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = Ready_Region1_Hold;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	514	280	231	304	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_MOUSE_MOVE:{
        MouseEventParams* pParams = ( MouseEventParams* )pEventParams;
        pFlexButton->m_knobPos = pParams->pos;
        if (FlexButton_IsIn( pFlexButton, FlexBtnStm_SlideStyle )) {
            pStm->base.bIsExternTrans = TRUE;
            Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Pressed, STATE_UNDEF );
            Ready_Region1_EndTrans( pFlexButton, pStm );
            bResult = TRUE;
        } else if (FlexButton_IsInRect( pFlexButton, pEventParams )) {
            pStm->base.bIsExternTrans = TRUE;
            Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Pressed, STATE_UNDEF );
            Ready_Region1_EndTrans( pFlexButton, pStm );
            bResult = TRUE;
        } else {
            pStm->base.bIsExternTrans = TRUE;
            Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_UnPressed, STATE_UNDEF );
            Ready_Region1_EndTrans( pFlexButton, pStm );
            bResult = TRUE;
        }
    } break;
    case FlexButton_MOUSE_UP:{
        Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Idle, STATE_UNDEF );
        Ready_Region1_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void Ready_Region1_Hold_Exit( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, Ready_Region1_Hold ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	514	280	231	304	-126	-25	1199	764" );
    }
}
static void Ready_Region1_UnPressed_Entry( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, Ready_Region1_UnPressed ) ){
        Ready_Region1_Hold_Entry( pFlexButton, pStm );
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	538	483	181	77	-126	-25	1199	764" );
    }
}
static BOOL Ready_Region1_UnPressed_EventProc( FlexButton* pFlexButton, Ready_Region1* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = Ready_Region1_UnPressed;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	538	483	181	77	-126	-25	1199	764" );
    return bResult ? bResult : Ready_Region1_Hold_EventProc( pFlexButton, pStm, nEventId, pEventParams );
}
static void Ready_Region1_UnPressed_Exit( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, Ready_Region1_UnPressed ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	538	483	181	77	-126	-25	1199	764" );
        Ready_Region1_Hold_Exit( pFlexButton, pStm );
    }
}
static void Ready_Region1_Pressed_Entry( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, Ready_Region1_Pressed ) ){
        Ready_Region1_Hold_Entry( pFlexButton, pStm );
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	540	305	181	86	-126	-25	1199	764" );
    }
}
static BOOL Ready_Region1_Pressed_EventProc( FlexButton* pFlexButton, Ready_Region1* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = Ready_Region1_Pressed;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	540	305	181	86	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_DRAW1:{
        FlexButton_DrawPressed(
            pFlexButton,
            ( SDL_Renderer* )pEventParams
        );
        bResult = TRUE;
    } break;
    case FlexButton_MOUSE_UP:{
        Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Idle, STATE_UNDEF );
        FlexButton_OnPushBtnPressed( pFlexButton );
        Ready_Region1_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : Ready_Region1_Hold_EventProc( pFlexButton, pStm, nEventId, pEventParams );
}
static void Ready_Region1_Pressed_Exit( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, Ready_Region1_Pressed ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	540	305	181	86	-126	-25	1199	764" );
        Ready_Region1_Hold_Exit( pFlexButton, pStm );
    }
}
static void Ready_Region1_Idle_Entry( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, Ready_Region1_Idle ) ){
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	513	120	231	106	-126	-25	1199	764" );
        pFlexButton->m_knobPos.x = pFlexButton->m_rect.x + pFlexButton->m_rect.w/2;
        pFlexButton->m_knobPos.y = pFlexButton->m_rect.y + pFlexButton->m_rect.h/2;
    }
}
static BOOL Ready_Region1_Idle_EventProc( FlexButton* pFlexButton, Ready_Region1* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = Ready_Region1_Idle;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	513	120	231	106	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_MOUSE_DOWN:{
        if (FlexButton_IsInRect( pFlexButton, pEventParams )) {
            Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Pressed, STATE_UNDEF );
            Ready_Region1_EndTrans( pFlexButton, pStm );
            bResult = TRUE;
        } else {
            Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Missed, STATE_UNDEF );
            Ready_Region1_EndTrans( pFlexButton, pStm );
            bResult = TRUE;
        }
    } break;
    default: break;
    }
    return bResult;
}
static void Ready_Region1_Idle_Exit( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, Ready_Region1_Idle ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	513	120	231	106	-126	-25	1199	764" );
    }
}
static void Ready_Region1_Missed_Entry( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, Ready_Region1_Missed ) ){
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	337	121	91	50	-126	-25	1199	764" );
    }
}
static BOOL Ready_Region1_Missed_EventProc( FlexButton* pFlexButton, Ready_Region1* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = Ready_Region1_Missed;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	337	121	91	50	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_MOUSE_UP:{
        Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Idle, STATE_UNDEF );
        Ready_Region1_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void Ready_Region1_Missed_Exit( FlexButton* pFlexButton, Ready_Region1* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, Ready_Region1_Missed ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	337	121	91	50	-126	-25	1199	764" );
    }
}
static void Ready_Region1_EndTrans( FlexButton *pFlexButton, Ready_Region1* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case Ready_Region1_Hold:    Ready_Region1_Hold_Entry( pFlexButton, pStm ); break;
    case Ready_Region1_UnPressed:Ready_Region1_UnPressed_Entry( pFlexButton, pStm ); break;
    case Ready_Region1_Pressed: Ready_Region1_Pressed_Entry( pFlexButton, pStm ); break;
    case Ready_Region1_Idle:    Ready_Region1_Idle_Entry( pFlexButton, pStm ); break;
    case Ready_Region1_Missed:  Ready_Region1_Missed_Entry( pFlexButton, pStm ); break;
    default: break;
    }
}
static void Ready_Region1_BgnTrans( FlexButton *pFlexButton, Ready_Region1* pStm, uint64_t targetState, uint64_t initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case Ready_Region1_Hold:    Ready_Region1_Hold_Exit( pFlexButton, pStm ); break;
    case Ready_Region1_UnPressed:Ready_Region1_UnPressed_Exit( pFlexButton, pStm ); break;
    case Ready_Region1_Pressed: Ready_Region1_Pressed_Exit( pFlexButton, pStm ); break;
    case Ready_Region1_Idle:    Ready_Region1_Idle_Exit( pFlexButton, pStm ); break;
    case Ready_Region1_Missed:  Ready_Region1_Missed_Exit( pFlexButton, pStm ); break;
    default: break;
    }
}
static BOOL Ready_Region1_StateDefaultTrans( FlexButton* pFlexButton, Ready_Region1* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    do{   if( pStm->base.nPseudostate == Ready_Region1_InitialReadyRegion1 ){
        Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Idle, STATE_UNDEF );
        Ready_Region1_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, Ready_Region1_Ready) ){
        Ready_Region1_BgnTrans( pFlexButton, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        Ready_Region1_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL Ready_Region1_RunToCompletion( FlexButton* pFlexButton, Ready_Region1* pStm ){
    BOOL bResult;
    do{
        bResult = Ready_Region1_StateDefaultTrans( pFlexButton, pStm );
    } while ( bResult );
    return bResult;
}
static int Ready_Region1_IsFinished(Ready_Region1* pReady_Region1){
    return pReady_Region1->base.nCurrentState == Ready_Region1_Ready && pReady_Region1->base.nCurrentState == pReady_Region1->base.nPseudostate;
}
static BOOL Ready_Region1_Reset( FlexButton* pFlexButton, Ready_Region1* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( Ready_Region1_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = Ready_Region1_InitialReadyRegion1;
        }
        return FALSE;
    }else{
    if( !IS_IN( nEntryPoint, Ready_Region1_Ready ) ){ return FALSE; }
        if( Ready_Region1_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    return TRUE;
}
static BOOL Ready_Region1_EventProc( FlexButton* pFlexButton, Ready_Region1* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    switch( pStm->base.nCurrentState ){
    case Ready_Region1_Hold:                    bResult |= Ready_Region1_Hold_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case Ready_Region1_UnPressed:               bResult |= Ready_Region1_UnPressed_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case Ready_Region1_Pressed:                 bResult |= Ready_Region1_Pressed_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case Ready_Region1_Idle:                    bResult |= Ready_Region1_Idle_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case Ready_Region1_Missed:                  bResult |= Ready_Region1_Missed_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    Ready_Region1_RunToCompletion( pFlexButton, pStm );
    return bResult;
}
static BOOL Ready_Region1_IsIn( Ready_Region1* pStm, uint64_t nCompositeState ) {
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL Ready_Region1_Abort( FlexButton* pFlexButton, Ready_Region1* pStm ) {
    pStm->base.nSourceState = Ready_Region1_Ready;
    Ready_Region1_BgnTrans( pFlexButton, pStm, Ready_Region1_Ready, STATE_UNDEF );
    Ready_Region1_EndTrans( pFlexButton, pStm );
    return TRUE;
}
static void FlexBtnStm_BgnTrans( FlexButton *pStateMachine0, FlexBtnStm* pStm, uint64_t targetState, uint64_t initState );
static void FlexBtnStm_EndTrans( FlexButton *pStateMachine0, FlexBtnStm* pStm );
static BOOL FlexBtnStm_Reset( FlexButton* pStateMachine0, FlexBtnStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
static BOOL FlexBtnStm_Abort( FlexButton* pStateMachine0, FlexBtnStm* pStm );
static BOOL FlexBtnStm_EventProc( FlexButton* pStateMachine0, FlexBtnStm* pStm, FlexButton_EVENT nEventId, void* pEventParams );
static BOOL FlexBtnStm_RunToCompletion( FlexButton* pStateMachine0, FlexBtnStm* pStm );
static void FlexBtnStm_Ready_Entry( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, FlexBtnStm_Ready ) ){
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	32	57	759	565	-126	-25	1199	764" );
        Ready_Region1_Reset( pFlexButton, &pStm->ReadyReady_Region1, &pStm->base, STATE_UNDEF );
    }
}
static BOOL FlexBtnStm_Ready_EventProc( FlexButton* pFlexButton, FlexBtnStm* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = FlexBtnStm_Ready;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	32	57	759	565	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_DRAW1:{
        FlexButton_DrawKnob(
            pFlexButton,
            ( SDL_Renderer* )pEventParams
        );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void FlexBtnStm_Ready_Exit( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, FlexBtnStm_Ready ) ){ 
        Ready_Region1_Abort( pFlexButton, &pStm->ReadyReady_Region1 );
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	32	57	759	565	-126	-25	1199	764" );
    }
}
static void FlexBtnStm_PushStyle_Entry( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, FlexBtnStm_PushStyle ) ){
        FlexBtnStm_Ready_Entry( pFlexButton, pStm );
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	132	200	96	-126	-25	1199	764" );
        pStm->nReadyHistory = FlexBtnStm_PushStyle;
    }
}
static BOOL FlexBtnStm_PushStyle_EventProc( FlexButton* pFlexButton, FlexBtnStm* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = FlexBtnStm_PushStyle;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	132	200	96	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_DRAW0:{
        FlexButton_DrawPushStyle(
            pFlexButton,
            ( SDL_Renderer* )pEventParams
        );
        bResult = TRUE;
    } break;
    case FlexButton_DRAW1:{
        if (FlexButton_IsIn(pFlexButton, Ready_Region1_Pressed)) {
            bResult = TRUE;
        }
    } break;
    default: break;
    }
    return bResult ? bResult : FlexBtnStm_Ready_EventProc( pFlexButton, pStm, nEventId, pEventParams );
}
static void FlexBtnStm_PushStyle_Exit( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, FlexBtnStm_PushStyle ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	132	200	96	-126	-25	1199	764" );
        FlexBtnStm_Ready_Exit( pFlexButton, pStm );
    }
}
static void FlexBtnStm_SelectStyle_Entry( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, FlexBtnStm_SelectStyle ) ){
        FlexBtnStm_Ready_Entry( pFlexButton, pStm );
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	256	200	77	-126	-25	1199	764" );
        pStm->nReadyHistory = FlexBtnStm_SelectStyle;
    }
}
static BOOL FlexBtnStm_SelectStyle_EventProc( FlexButton* pFlexButton, FlexBtnStm* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = FlexBtnStm_SelectStyle;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	256	200	77	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_DRAW0:{
        FlexButton_DrawSelectStyle(
            pFlexButton,
            ( SDL_Renderer* )pEventParams
        );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : FlexBtnStm_Ready_EventProc( pFlexButton, pStm, nEventId, pEventParams );
}
static void FlexBtnStm_SelectStyle_Exit( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, FlexBtnStm_SelectStyle ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	256	200	77	-126	-25	1199	764" );
        FlexBtnStm_Ready_Exit( pFlexButton, pStm );
    }
}
static void FlexBtnStm_SlideStyle_Entry( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, FlexBtnStm_SlideStyle ) ){
        FlexBtnStm_Ready_Entry( pFlexButton, pStm );
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	484	200	77	-126	-25	1199	764" );
        pStm->nReadyHistory = FlexBtnStm_SlideStyle;
    }
}
static BOOL FlexBtnStm_SlideStyle_EventProc( FlexButton* pFlexButton, FlexBtnStm* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = FlexBtnStm_SlideStyle;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	484	200	77	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_DRAW0:{
        FlexButton_DrawSlideStyle(
            pFlexButton,
            ( SDL_Renderer* )pEventParams
        );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : FlexBtnStm_Ready_EventProc( pFlexButton, pStm, nEventId, pEventParams );
}
static void FlexBtnStm_SlideStyle_Exit( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, FlexBtnStm_SlideStyle ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	484	200	77	-126	-25	1199	764" );
        FlexBtnStm_Ready_Exit( pFlexButton, pStm );
    }
}
static void FlexBtnStm_ToggleStyle_Entry( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, FlexBtnStm_ToggleStyle ) ){
        FlexBtnStm_Ready_Entry( pFlexButton, pStm );
        ObjsBuilder_showEntry( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	370	200	77	-126	-25	1199	764" );
        pStm->nReadyHistory = FlexBtnStm_ToggleStyle;
    }
}
static BOOL FlexBtnStm_ToggleStyle_EventProc( FlexButton* pFlexButton, FlexBtnStm* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = FlexBtnStm_ToggleStyle;
    ObjsBuilder_showDoing( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	370	200	77	-126	-25	1199	764" );
    switch( nEventId ){
    case FlexButton_DRAW0:{
        FlexButton_DrawToggleStyle(
            pFlexButton,
            ( SDL_Renderer* )pEventParams
        );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult ? bResult : FlexBtnStm_Ready_EventProc( pFlexButton, pStm, nEventId, pEventParams );
}
static void FlexBtnStm_ToggleStyle_Exit( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, FlexBtnStm_ToggleStyle ) ){ 
        ObjsBuilder_showExit( pFlexButton, pStm, "Model/FlexButton/FlexBtnStm	63	370	200	77	-126	-25	1199	764" );
        FlexBtnStm_Ready_Exit( pFlexButton, pStm );
    }
}
static void FlexBtnStm_EndTrans( FlexButton *pFlexButton, FlexBtnStm* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case FlexBtnStm_Ready:      FlexBtnStm_Ready_Entry( pFlexButton, pStm ); break;
    case FlexBtnStm_PushStyle:  FlexBtnStm_PushStyle_Entry( pFlexButton, pStm ); break;
    case FlexBtnStm_SelectStyle:FlexBtnStm_SelectStyle_Entry( pFlexButton, pStm ); break;
    case FlexBtnStm_SlideStyle: FlexBtnStm_SlideStyle_Entry( pFlexButton, pStm ); break;
    case FlexBtnStm_ToggleStyle:FlexBtnStm_ToggleStyle_Entry( pFlexButton, pStm ); break;
    default: break;
    }
}
static void FlexBtnStm_BgnTrans( FlexButton *pFlexButton, FlexBtnStm* pStm, uint64_t targetState, uint64_t initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case FlexBtnStm_Ready:      FlexBtnStm_Ready_Exit( pFlexButton, pStm ); break;
    case FlexBtnStm_PushStyle:  FlexBtnStm_PushStyle_Exit( pFlexButton, pStm ); break;
    case FlexBtnStm_SelectStyle:FlexBtnStm_SelectStyle_Exit( pFlexButton, pStm ); break;
    case FlexBtnStm_SlideStyle: FlexBtnStm_SlideStyle_Exit( pFlexButton, pStm ); break;
    case FlexBtnStm_ToggleStyle:FlexBtnStm_ToggleStyle_Exit( pFlexButton, pStm ); break;
    default: break;
    }
}
static BOOL FlexBtnStm_StateDefaultTrans( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    bResult |= Ready_Region1_StateDefaultTrans( pFlexButton, &pStm->ReadyReady_Region1 );
    do{   if( pStm->base.nPseudostate == FlexBtnStm_InitialReady ){
        if( pStm->nReadyHistory && pStm->nReadyHistory != FlexBtnStm_Ready ){
            FlexBtnStm_BgnTrans( pFlexButton, pStm, pStm->nReadyHistory, STATE_UNDEF );
            FlexBtnStm_EndTrans( pFlexButton, pStm );
            bResult = TRUE;
            break;
        }
        FlexBtnStm_BgnTrans( pFlexButton, pStm, FlexBtnStm_PushStyle, STATE_UNDEF );
        FlexBtnStm_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    }else if( pStm->base.nPseudostate == FlexBtnStm_InitialMain ){
        FlexBtnStm_BgnTrans( pFlexButton, pStm, FlexBtnStm_Ready, FlexBtnStm_InitialReady );
        pStm->nReadyHistory = pFlexButton->m_style;
        FlexBtnStm_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, FlexBtnStm_StateMachine0) ){
        FlexBtnStm_BgnTrans( pFlexButton, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        FlexBtnStm_EndTrans( pFlexButton, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL FlexBtnStm_RunToCompletion( FlexButton* pFlexButton, FlexBtnStm* pStm ){
    BOOL bResult;
    do{
        bResult = FlexBtnStm_StateDefaultTrans( pFlexButton, pStm );
    } while ( bResult );
    return bResult;
}
static int FlexBtnStm_IsFinished(FlexBtnStm* pFlexBtnStm){
    return pFlexBtnStm->base.nCurrentState == FlexBtnStm_StateMachine0 && pFlexBtnStm->base.nCurrentState == pFlexBtnStm->base.nPseudostate;
}
static BOOL FlexBtnStm_Reset( FlexButton* pFlexButton, FlexBtnStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( FlexBtnStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = FlexBtnStm_InitialMain;
        }
        return FALSE;
    }else{
    if( Ready_Region1_Reset( pFlexButton, &pStm->ReadyReady_Region1, &pStm->base, nEntryPoint ) ){ return TRUE; }
    if( !IS_IN( nEntryPoint, FlexBtnStm_StateMachine0 ) ){ return FALSE; }
        if( FlexBtnStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    return TRUE;
}
static BOOL FlexBtnStm_EventProc( FlexButton* pFlexButton, FlexBtnStm* pStm, FlexButton_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    bResult |= Ready_Region1_EventProc( pFlexButton, &pStm->ReadyReady_Region1, nEventId, pEventParams );
    switch( pStm->base.nCurrentState ){
    case FlexBtnStm_Ready:                      bResult |= FlexBtnStm_Ready_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case FlexBtnStm_PushStyle:                  bResult |= FlexBtnStm_PushStyle_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case FlexBtnStm_SelectStyle:                bResult |= FlexBtnStm_SelectStyle_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case FlexBtnStm_SlideStyle:                 bResult |= FlexBtnStm_SlideStyle_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    case FlexBtnStm_ToggleStyle:                bResult |= FlexBtnStm_ToggleStyle_EventProc( pFlexButton, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    FlexBtnStm_RunToCompletion( pFlexButton, pStm );
    return bResult;
}
static BOOL FlexBtnStm_IsIn( FlexBtnStm* pStm, uint64_t nCompositeState ) {
if( Ready_Region1_IsIn( &pStm->ReadyReady_Region1, nCompositeState ) ){ return TRUE; }
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL FlexBtnStm_Abort( FlexButton* pFlexButton, FlexBtnStm* pStm ) {
    pStm->base.nSourceState = FlexBtnStm_StateMachine0;
    FlexBtnStm_BgnTrans( pFlexButton, pStm, FlexBtnStm_StateMachine0, STATE_UNDEF );
    FlexBtnStm_EndTrans( pFlexButton, pStm );
    return TRUE;
}
BOOL FlexButton_EventProc( FlexButton* pFlexButton, FlexButton_EVENT nEventId, void* pEventParams ){
    return FlexBtnStm_EventProc( pFlexButton, &pFlexButton->mainStm, nEventId, pEventParams );
}
BOOL FlexButton_Start( FlexButton* pFlexButton ){
    FlexBtnStm_Abort( pFlexButton, &pFlexButton->mainStm );
    FlexBtnStm_Reset( pFlexButton, &pFlexButton->mainStm, NULL, STATE_UNDEF );
    return FlexBtnStm_RunToCompletion( pFlexButton, &pFlexButton->mainStm );
}
BOOL FlexButton_Reset( FlexButton* pFlexButton, uint64_t nEntryPoint ){
    return FlexBtnStm_Reset( pFlexButton, &pFlexButton->mainStm, NULL, nEntryPoint );
}
BOOL FlexButton_IsIn( FlexButton* pFlexButton, uint64_t nState ){
    return FlexBtnStm_IsIn( &pFlexButton->mainStm, nState );
}
Sprite* FlexButton_Copy( FlexButton* pFlexButton, const FlexButton* pSource ){
    Sprite_Copy( ( Sprite* )pFlexButton, ( Sprite* )pSource );
    pFlexButton->m_value = pSource->m_value;
    pFlexButton->m_valueMax = pSource->m_valueMax;
    pFlexButton->m_valueTmp = pSource->m_valueTmp;
    pFlexButton->m_style = pSource->m_style;
    pFlexButton->m_knobPos = pSource->m_knobPos;
    pFlexButton->m_mouseListeners = pSource->m_mouseListeners;
    pFlexButton->m_buttonListeners = pSource->m_buttonListeners;
    return ( Sprite* )pFlexButton;
}
const SpriteVtbl gFlexButtonVtbl = {
    .pload                       = FlexButton_load,
    .pdraw0                      = FlexButton_draw0,
    .pdraw1                      = FlexButton_draw1,
    .pupdateMouseState           = FlexButton_updateMouseState,
};
