/* File generated by Đức's ClasHStamP */
#define __TrackToConstraint_INTERNAL__
#include "CommonInclude.h"
#include "TrackToConstraint.h"
/** @public @memberof TrackToConstraint */
static void TrackToConstraint_apply(
    TrackToConstraint* pTrackToConstraint
){
} /* TrackToConstraint_apply */

TransformConstraint* TrackToConstraint_Copy( TrackToConstraint* pTrackToConstraint, const TrackToConstraint* pSource ){
    TransformConstraint_Copy( ( TransformConstraint* )pTrackToConstraint, ( TransformConstraint* )pSource );
    return ( Constraint* )pTrackToConstraint;
}
const ConstraintVtbl gTrackToConstraintVtbl = {
    .papply                      = TrackToConstraint_apply,
};
