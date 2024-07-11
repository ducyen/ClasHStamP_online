/* File generated by Đức's ClasHStamP */
#define __ClawMachine_INTERNAL__
#include "CommonInclude.h"
#include "ClawMachine.h"
#include "PhxSprite.h"                                          
#include "ObjsBuilder.h"
const TCHAR* ClawMachineEvent_toString( ClawMachine_EVENT value ){
    switch( value ){
    case ClawMachine_ClawBtnPressed: return _T( "ClawBtnPressed" );
    case ClawMachine_LeftBtnDown: return _T( "LeftBtnDown" );
    case ClawMachine_LeftBtnUp: return _T( "LeftBtnUp" );
    case ClawMachine_RightBtnDown: return _T( "RightBtnDown" );
    case ClawMachine_RightBtnUp: return _T( "RightBtnUp" );
    case ClawMachine_TICK: return _T( "TICK" );
    default: return _T( "ClawMachine_UNKNOWN" );
    }
}
static void ClawMachineStm_BgnTrans( ClawMachine *pClawMachineTop, ClawMachineStm* pStm, uint64_t targetState, uint64_t initState );
static void ClawMachineStm_EndTrans( ClawMachine *pClawMachineTop, ClawMachineStm* pStm );
static BOOL ClawMachineStm_Reset( ClawMachine* pClawMachineTop, ClawMachineStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
static BOOL ClawMachineStm_Abort( ClawMachine* pClawMachineTop, ClawMachineStm* pStm );
static BOOL ClawMachineStm_EventProc( ClawMachine* pClawMachineTop, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams );
static BOOL ClawMachineStm_RunToCompletion( ClawMachine* pClawMachineTop, ClawMachineStm* pStm );
static void ClawMachineStm_Ready_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_Ready ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	132	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_Ready_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_Ready;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	132	220	89	0	0	972	586" );
    switch( nEventId ){
    case ClawMachine_ClawBtnPressed:{
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_GoingDown, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    } break;
    case ClawMachine_LeftBtnDown:{
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_GoingLeft, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    } break;
    case ClawMachine_RightBtnDown:{
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_GoingRight, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void ClawMachineStm_Ready_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_Ready ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	132	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_GoingLeft_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_GoingLeft ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	41	302	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_GoingLeft_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_GoingLeft;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	41	302	220	89	0	0	972	586" );
    switch( nEventId ){
    case ClawMachine_LeftBtnUp:{
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_JunctionPoint0, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    } break;
    case ClawMachine_TICK:{
        cpBodySetForce(
            PhxSprite_getBody( arm_main_hanger ),
            cpv( -2, 0 )
        );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void ClawMachineStm_GoingLeft_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_GoingLeft ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	41	302	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_GoingRight_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_GoingRight ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	302	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_GoingRight_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_GoingRight;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	302	220	89	0	0	972	586" );
    switch( nEventId ){
    case ClawMachine_RightBtnUp:{
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_JunctionPoint0, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    } break;
    case ClawMachine_TICK:{
        cpBodySetForce(
            PhxSprite_getBody( arm_main_hanger ),
            cpv( 2, 0 )
        );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void ClawMachineStm_GoingRight_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_GoingRight ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	302	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_GoingDown_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_GoingDown ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	132	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_GoingDown_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_GoingDown;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	132	220	89	0	0	972	586" );
    return bResult;
}
static void ClawMachineStm_GoingDown_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_GoingDown ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	132	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_Clawing_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_Clawing ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	302	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_Clawing_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_Clawing;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	302	220	89	0	0	972	586" );
    return bResult;
}
static void ClawMachineStm_Clawing_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_Clawing ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	302	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_GoingUp_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_GoingUp ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	472	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_GoingUp_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_GoingUp;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	472	220	89	0	0	972	586" );
    return bResult;
}
static void ClawMachineStm_GoingUp_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_GoingUp ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	707	472	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_GoingToGate_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_GoingToGate ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	472	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_GoingToGate_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_GoingToGate;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	472	220	89	0	0	972	586" );
    return bResult;
}
static void ClawMachineStm_GoingToGate_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_GoingToGate ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	390	472	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_GoingHome_Entry( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, ClawMachineStm_GoingHome ) ){
        ObjsBuilder_showEntry( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	42	132	220	89	0	0	972	586" );
    }
}
static BOOL ClawMachineStm_GoingHome_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = ClawMachineStm_GoingHome;
    ObjsBuilder_showDoing( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	42	132	220	89	0	0	972	586" );
    return bResult;
}
static void ClawMachineStm_GoingHome_Exit( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, ClawMachineStm_GoingHome ) ){ 
        ObjsBuilder_showExit( pClawMachine, pStm, "Model/ClawMachine/ClawMachineStm	42	132	220	89	0	0	972	586" );
    }
}
static void ClawMachineStm_EndTrans( ClawMachine *pClawMachine, ClawMachineStm* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case ClawMachineStm_Ready:  ClawMachineStm_Ready_Entry( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingLeft:ClawMachineStm_GoingLeft_Entry( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingRight:ClawMachineStm_GoingRight_Entry( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingDown:ClawMachineStm_GoingDown_Entry( pClawMachine, pStm ); break;
    case ClawMachineStm_Clawing:ClawMachineStm_Clawing_Entry( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingUp:ClawMachineStm_GoingUp_Entry( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingToGate:ClawMachineStm_GoingToGate_Entry( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingHome:ClawMachineStm_GoingHome_Entry( pClawMachine, pStm ); break;
    default: break;
    }
}
static void ClawMachineStm_BgnTrans( ClawMachine *pClawMachine, ClawMachineStm* pStm, uint64_t targetState, uint64_t initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case ClawMachineStm_Ready:  ClawMachineStm_Ready_Exit( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingLeft:ClawMachineStm_GoingLeft_Exit( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingRight:ClawMachineStm_GoingRight_Exit( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingDown:ClawMachineStm_GoingDown_Exit( pClawMachine, pStm ); break;
    case ClawMachineStm_Clawing:ClawMachineStm_Clawing_Exit( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingUp:ClawMachineStm_GoingUp_Exit( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingToGate:ClawMachineStm_GoingToGate_Exit( pClawMachine, pStm ); break;
    case ClawMachineStm_GoingHome:ClawMachineStm_GoingHome_Exit( pClawMachine, pStm ); break;
    default: break;
    }
}
static BOOL ClawMachineStm_StateDefaultTrans( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    do{   if( pStm->base.nPseudostate == ClawMachineStm_InitialPseudostate0 ){
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_GoingHome, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    }else if( pStm->base.nPseudostate == ClawMachineStm_JunctionPoint0 ){
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_Ready, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    }else if( pStm->base.nPseudostate == ClawMachineStm_GoingDown ){
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_Clawing, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    }else if( pStm->base.nPseudostate == ClawMachineStm_Clawing ){
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_GoingUp, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    }else if( pStm->base.nPseudostate == ClawMachineStm_GoingUp ){
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_GoingToGate, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    }else if( pStm->base.nPseudostate == ClawMachineStm_GoingHome ){
        ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_Ready, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, ClawMachineStm_ClawMachineTop) ){
        ClawMachineStm_BgnTrans( pClawMachine, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        ClawMachineStm_EndTrans( pClawMachine, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL ClawMachineStm_RunToCompletion( ClawMachine* pClawMachine, ClawMachineStm* pStm ){
    BOOL bResult;
    do{
        bResult = ClawMachineStm_StateDefaultTrans( pClawMachine, pStm );
    } while ( bResult );
    return bResult;
}
static int ClawMachineStm_IsFinished(ClawMachineStm* pClawMachineStm){
    return pClawMachineStm->base.nCurrentState == ClawMachineStm_ClawMachineTop && pClawMachineStm->base.nCurrentState == pClawMachineStm->base.nPseudostate;
}
static BOOL ClawMachineStm_Reset( ClawMachine* pClawMachine, ClawMachineStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( ClawMachineStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = ClawMachineStm_InitialPseudostate0;
        }
        return FALSE;
    }else{
    if( !IS_IN( nEntryPoint, ClawMachineStm_ClawMachineTop ) ){ return FALSE; }
        if( ClawMachineStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    return TRUE;
}
static BOOL ClawMachineStm_EventProc( ClawMachine* pClawMachine, ClawMachineStm* pStm, ClawMachine_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    switch( pStm->base.nCurrentState ){
    case ClawMachineStm_Ready:                  bResult |= ClawMachineStm_Ready_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    case ClawMachineStm_GoingLeft:              bResult |= ClawMachineStm_GoingLeft_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    case ClawMachineStm_GoingRight:             bResult |= ClawMachineStm_GoingRight_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    case ClawMachineStm_GoingDown:              bResult |= ClawMachineStm_GoingDown_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    case ClawMachineStm_Clawing:                bResult |= ClawMachineStm_Clawing_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    case ClawMachineStm_GoingUp:                bResult |= ClawMachineStm_GoingUp_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    case ClawMachineStm_GoingToGate:            bResult |= ClawMachineStm_GoingToGate_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    case ClawMachineStm_GoingHome:              bResult |= ClawMachineStm_GoingHome_EventProc( pClawMachine, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    ClawMachineStm_RunToCompletion( pClawMachine, pStm );
    return bResult;
}
static BOOL ClawMachineStm_IsIn( ClawMachineStm* pStm, uint64_t nCompositeState ) {
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL ClawMachineStm_Abort( ClawMachine* pClawMachine, ClawMachineStm* pStm ) {
    pStm->base.nSourceState = ClawMachineStm_ClawMachineTop;
    ClawMachineStm_BgnTrans( pClawMachine, pStm, ClawMachineStm_ClawMachineTop, STATE_UNDEF );
    ClawMachineStm_EndTrans( pClawMachine, pStm );
    return TRUE;
}
BOOL ClawMachine_EventProc( ClawMachine* pClawMachine, ClawMachine_EVENT nEventId, void* pEventParams ){
    return ClawMachineStm_EventProc( pClawMachine, &pClawMachine->mainStm, nEventId, pEventParams );
}
BOOL ClawMachine_Start( ClawMachine* pClawMachine ){
    ClawMachineStm_Abort( pClawMachine, &pClawMachine->mainStm );
    ClawMachineStm_Reset( pClawMachine, &pClawMachine->mainStm, NULL, STATE_UNDEF );
    return ClawMachineStm_RunToCompletion( pClawMachine, &pClawMachine->mainStm );
}
BOOL ClawMachine_Reset( ClawMachine* pClawMachine, uint64_t nEntryPoint ){
    return ClawMachineStm_Reset( pClawMachine, &pClawMachine->mainStm, NULL, nEntryPoint );
}
BOOL ClawMachine_IsIn( ClawMachine* pClawMachine, uint64_t nState ){
    return ClawMachineStm_IsIn( &pClawMachine->mainStm, nState );
}
Sprite* ClawMachine_Copy( ClawMachine* pClawMachine, const ClawMachine* pSource ){
    Sprite_Copy( ( Sprite* )pClawMachine, ( Sprite* )pSource );
    return ( Sprite* )pClawMachine;
}
