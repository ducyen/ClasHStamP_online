#ifndef __Interface1_H__
#define __Interface1_H__
typedef struct tagInterface1 Interface1;
void Interface1_finalMethod( Interface1* pInterface1 );
#endif//__Interface1_H__
#if !defined( Interface1_Init ) && ( defined( __Interface1_INTERNAL__ )  )
/** @memberof Interface1
 * @brief Interface1 auto-generated constructor
 */
#define Interface1_Init()\

#define Interface1_Ctor(  )    ( Interface1 ){ \
    Interface1_Init(  ) \
}
Interface1* Interface1_Copy( Interface1* pInterface1, const Interface1* pSource );
/** @class Interface1
 * @extends 
 */
struct tagInterface1{
#define Interface1_CLASS                                                                        \
    size_t cbSize;                                                                              \

    Interface1_CLASS    
};
#endif//__Interface1_INTERNAL__
