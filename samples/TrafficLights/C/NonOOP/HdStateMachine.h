#ifndef __HdStateMachine_H__
#define __HdStateMachine_H__
typedef struct tagHdStateMachine HdStateMachine;
int HdStateMachine_Enterable( HdStateMachine* pHdStateMachine, uint64_t nThisState );
int HdStateMachine_Exitable( HdStateMachine* pHdStateMachine, uint64_t nThisState );
#endif//__HdStateMachine_H__
#if !defined( HdStateMachine_Init ) && ( defined( __HdStateMachine_INTERNAL__ )  )
/** @memberof HdStateMachine
 * @brief HdStateMachine auto-generated constructor
 */
#define HdStateMachine_Init(_nCurrentState, _nPseudostate)\
    .pParentStm = NULL,\
    .nCurrentState = _nCurrentState,\
    .nLCAState = STATE_UNDEF,\
    .nTargetState = STATE_UNDEF,\
    .nSourceState = STATE_UNDEF,\
    .nPseudostate = _nPseudostate,\
    .bIsExternTrans = false,\

#define HdStateMachine_Ctor( _nCurrentState, _nPseudostate )    ( HdStateMachine ){ \
    HdStateMachine_Init( P( _nCurrentState ), P( _nPseudostate ) ) \
}
HdStateMachine* HdStateMachine_Copy( HdStateMachine* pHdStateMachine, const HdStateMachine* pSource );
/** @class HdStateMachine
 * @extends 
 */
#define HdStateMachine_CLASS                                                                    \
    size_t cbSize;                                                                              \
    HdStateMachine* pParentStm;                                 \
    uint64_t nCurrentState;                                                                                           \
    uint64_t nLCAState;                                                                                                   \
    uint64_t nTargetState;                                                                                             \
    uint64_t nSourceState;                                                                                             \
    uint64_t nPseudostate;                                                                                             \
    bool bIsExternTrans;                                                                                                 \

typedef struct tagHdStateMachine{
    HdStateMachine_CLASS    
}HdStateMachine;
#endif//__HdStateMachine_INTERNAL__
