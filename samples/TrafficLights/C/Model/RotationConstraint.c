/* File generated by Đức's ClasHStamP */
#define __RotationConstraint_INTERNAL__
#include "CommonInclude.h"
#include "RotationConstraint.h"
/** @public @memberof RotationConstraint */
static void RotationConstraint_apply(
    RotationConstraint* pRotationConstraint
){
} /* RotationConstraint_apply */

TransformConstraint* RotationConstraint_Copy( RotationConstraint* pRotationConstraint, const RotationConstraint* pSource ){
    TransformConstraint_Copy( ( TransformConstraint* )pRotationConstraint, ( TransformConstraint* )pSource );
    return ( Constraint* )pRotationConstraint;
}
const ConstraintVtbl gRotationConstraintVtbl = {
    .papply                      = RotationConstraint_apply,
};
