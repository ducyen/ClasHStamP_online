/* File generated by Đức's ClasHStamP */
#define __PhxSimpleMotor_INTERNAL__
#include "CommonInclude.h"
#include "PhxSimpleMotor.h"
/** @public @memberof PhxSimpleMotor */
static void PhxSimpleMotor_apply(
    PhxSimpleMotor* pPhxSimpleMotor,
    Sprite* target
){
} /* PhxSimpleMotor_apply */

PhxJoint* PhxSimpleMotor_Copy( PhxSimpleMotor* pPhxSimpleMotor, const PhxSimpleMotor* pSource ){
    PhxJoint_Copy( ( PhxJoint* )pPhxSimpleMotor, ( PhxJoint* )pSource );
    return ( PhxJoint* )pPhxSimpleMotor;
}
const PhxJointVtbl gPhxSimpleMotorVtbl = {
    .papply                      = PhxSimpleMotor_apply,
};
