﻿/* File generated by Đức's ClasHStamP */
#define __Aggregration_INTERNAL__
#include "CommonInclude.h"
#include "Aggregration.h"
Aggregration* Aggregration_Copy( Aggregration* pAggregration, const Aggregration* pSource ){
    pAggregration->attribute2 = pSource->attribute2;
    return ( Aggregration* )pAggregration;
}
