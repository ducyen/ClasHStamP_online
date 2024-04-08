/* File generated by Đức's ClasHStamP */
#define __ContextImpl_INTERNAL__
#include "CommonInclude.h"
#include "ContextImpl.h"
#include "ObjsBuilder.h"                                        
const TCHAR* ContextImplEvent_toString( ContextImpl_EVENT value ){
    switch( value ){
    case ContextImpl_E_PWR_OFF: return _T( "E_PWR_OFF" );
    case ContextImpl_E_PWR_ON: return _T( "E_PWR_ON" );
    default: return _T( "ContextImpl_UNKNOWN" );
    }
}
static void MainStm_BgnTrans( ContextImpl *pMainTop, MainStm* pStm, uint64_t targetState, uint64_t initState );
static void MainStm_EndTrans( ContextImpl *pMainTop, MainStm* pStm );
static BOOL MainStm_Reset( ContextImpl* pMainTop, MainStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
static BOOL MainStm_Abort( ContextImpl* pMainTop, MainStm* pStm );
static BOOL MainStm_EventProc( ContextImpl* pMainTop, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams );
static BOOL MainStm_RunToCompletion( ContextImpl* pMainTop, MainStm* pStm );
static void MainStm_PowerOff_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_PowerOff ) ){
        ShowEntry( "Model/ContextImpl/MainStm	467	133	152	107	225	28	1463	1214" );
    }
}
static BOOL MainStm_PowerOff_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_PowerOff;
    ShowDoing( "Model/ContextImpl/MainStm	467	133	152	107	225	28	1463	1214" );
    switch( nEventId ){
    case ContextImpl_E_PWR_ON:{
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_PowerOn, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void MainStm_PowerOff_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_PowerOff ) ){ 
        ShowExit( "Model/ContextImpl/MainStm	467	133	152	107	225	28	1463	1214" );
    }
}
static void MainStm_PowerOn_Entry( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Enterable( &pStm->base, MainStm_PowerOn ) ){
        ShowEntry( "Model/ContextImpl/MainStm	467	354	152	107	225	28	1463	1214" );
    }
}
static BOOL MainStm_PowerOn_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = MainStm_PowerOn;
    ShowDoing( "Model/ContextImpl/MainStm	467	354	152	107	225	28	1463	1214" );
    switch( nEventId ){
    case ContextImpl_E_PWR_OFF:{
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_PowerOff, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    } break;
    default: break;
    }
    return bResult;
}
static void MainStm_PowerOn_Exit( ContextImpl* pContextImpl, MainStm* pStm ){
    if( HdStateMachine_Exitable( &pStm->base, MainStm_PowerOn ) ){ 
        ShowExit( "Model/ContextImpl/MainStm	467	354	152	107	225	28	1463	1214" );
    }
}
static void MainStm_EndTrans( ContextImpl *pContextImpl, MainStm* pStm ){
    pStm->base.nCurrentState = pStm->base.nTargetState;
    pStm->base.bIsExternTrans = FALSE;
    switch( pStm->base.nCurrentState ){
    case MainStm_PowerOff:      MainStm_PowerOff_Entry( pContextImpl, pStm ); break;
    case MainStm_PowerOn:       MainStm_PowerOn_Entry( pContextImpl, pStm ); break;
    default: break;
    }
}
static void MainStm_BgnTrans( ContextImpl *pContextImpl, MainStm* pStm, uint64_t targetState, uint64_t initState ){
    pStm->base.nTargetState = targetState;
    pStm->base.nPseudostate = targetState;
    if( initState ){
        pStm->base.nPseudostate = initState;
    }
    switch( pStm->base.nCurrentState ){
    case MainStm_PowerOff:      MainStm_PowerOff_Exit( pContextImpl, pStm ); break;
    case MainStm_PowerOn:       MainStm_PowerOn_Exit( pContextImpl, pStm ); break;
    default: break;
    }
}
static BOOL MainStm_StateDefaultTrans( ContextImpl* pContextImpl, MainStm* pStm ){
    BOOL bResult = FALSE;
    pStm->base.nSourceState = pStm->base.nCurrentState;
    pStm->base.nLCAState = STATE_UNDEF;
    do{   if( pStm->base.nPseudostate == MainStm_InitialPseudostate0 ){
        MainStm_BgnTrans( pContextImpl, pStm, MainStm_PowerOff, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    }else if( pStm->base.nCurrentState != pStm->base.nPseudostate && IS_IN(pStm->base.nPseudostate, MainStm_MainTop) ){
        MainStm_BgnTrans( pContextImpl, pStm, pStm->base.nPseudostate, STATE_UNDEF );
        MainStm_EndTrans( pContextImpl, pStm );
        bResult = TRUE;
    }else{
    }   }while( FALSE );
    return bResult;
}
static BOOL MainStm_RunToCompletion( ContextImpl* pContextImpl, MainStm* pStm ){
    BOOL bResult;
    do{
        bResult = MainStm_StateDefaultTrans( pContextImpl, pStm );
    } while ( bResult );
    return bResult;
}
static BOOL MainStm_Reset( ContextImpl* pContextImpl, MainStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint ) {
    pStm->base.pParentStm = pParentStm;
    if( nEntryPoint == NULL ){
        if( MainStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = MainStm_InitialPseudostate0;
        }
        return FALSE;
    }else{
    if( !IS_IN( nEntryPoint, MainStm_MainTop ) ){ return FALSE; }
        if( MainStm_IsFinished( &pStm->base ) ){
            pStm->base.nPseudostate = nEntryPoint;
            return FALSE;
        }else{
            pStm->base.nPseudostate = nEntryPoint;
        }
    }
    return TRUE;
}
static BOOL MainStm_EventProc( ContextImpl* pContextImpl, MainStm* pStm, ContextImpl_EVENT nEventId, void* pEventParams ){
    BOOL bResult = FALSE;
    pStm->base.nLCAState = STATE_UNDEF;
    switch( pStm->base.nCurrentState ){
    case MainStm_PowerOff:                      bResult |= MainStm_PowerOff_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    case MainStm_PowerOn:                       bResult |= MainStm_PowerOn_EventProc( pContextImpl, pStm, nEventId, pEventParams ); break;
    default: break;
    }
    MainStm_RunToCompletion( pContextImpl, pStm );
    return bResult;
}
static BOOL MainStm_IsIn( MainStm* pStm, uint64_t nCompositeState ) {
    if( IS_IN( pStm->base.nCurrentState, nCompositeState ) ){ return TRUE; }
    return FALSE;
}
static BOOL MainStm_Abort( ContextImpl* pContextImpl, MainStm* pStm ) {
    pStm->base.nSourceState = MainStm_MainTop;
    MainStm_BgnTrans( pContextImpl, pStm, MainStm_MainTop, STATE_UNDEF );
    MainStm_EndTrans( pContextImpl, pStm );
    return TRUE;
}
int MainStm_IsFinished(MainStm* pMainStm){
    return pMainStm->base.nCurrentState == MainStm_MainTop && pMainStm->base.nCurrentState == pMainStm->base.nPseudostate;
}
BOOL ContextImpl_EventProc( ContextImpl* pContextImpl, ContextImpl_EVENT nEventId, void* pEventParams ){
    return MainStm_EventProc( pContextImpl, &pContextImpl->mainStm, nEventId, pEventParams );
}
BOOL ContextImpl_Start( ContextImpl* pContextImpl ){
    MainStm_Abort( pContextImpl, &pContextImpl->mainStm );
    MainStm_Reset( pContextImpl, &pContextImpl->mainStm, NULL, STATE_UNDEF );
    return MainStm_RunToCompletion( pContextImpl, &pContextImpl->mainStm );
}
BOOL ContextImpl_Reset( ContextImpl* pContextImpl, uint64_t nEntryPoint ){
    return MainStm_Reset( pContextImpl, &pContextImpl->mainStm, NULL, nEntryPoint );
}
BOOL ContextImpl_IsIn( ContextImpl* pContextImpl, uint64_t nState ){
    return MainStm_IsIn( &pContextImpl->mainStm, nState );
}
ContextImpl* ContextImpl_Copy( ContextImpl* pContextImpl, const ContextImpl* pSource ){
    return ( ContextImpl* )pContextImpl;
}
