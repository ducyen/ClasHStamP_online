#ifndef __ObjsBuilder_H__
#define __ObjsBuilder_H__
#include "Sprite.h"
typedef struct tagObjsBuilder ObjsBuilder;
extern Sprite* g_objects[];
enum {
#define carBody                 ( g_objects[ _carBody ] )
    _carBody,
#define toggleBtn               ( g_objects[ _toggleBtn ] )
    _toggleBtn,
#define Text_1sh                ( g_objects[ _Text_1sh ] )
    _Text_1sh
};
int ObjsBuilder_startSim( void   );
void ObjsBuilder_showEntry( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showDoing( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showExit( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showDiagram( void* pObj, void* pStm_, char* pMsg, char r, char g, char b );
#endif//__ObjsBuilder_H__
#if !defined( ObjsBuilder_Init ) && ( defined( __ObjsBuilder_INTERNAL__ )  )
/** @memberof ObjsBuilder
 * @brief ObjsBuilder auto-generated constructor
 */
#define ObjsBuilder_Init()\

#define ObjsBuilder_Ctor(  )    ( ObjsBuilder ){ \
    ObjsBuilder_Init(  ) \
}
ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource );
/** @class ObjsBuilder
 * @extends 
 */
struct tagObjsBuilder{
#define ObjsBuilder_CLASS                                                                       \
    size_t cbSize;                                                                              \

    ObjsBuilder_CLASS    
};
#endif//__ObjsBuilder_INTERNAL__
