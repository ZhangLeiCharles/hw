// file = 0; split type = patterns; threshold = 100000; total count = 0.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "rmapats.h"

void  hsG_0__0 (struct dummyq_struct * I1308, EBLK  * I1303, U  I692);
void  hsG_0__0 (struct dummyq_struct * I1308, EBLK  * I1303, U  I692)
{
    U  I1568;
    U  I1569;
    U  I1570;
    struct futq * I1571;
    struct dummyq_struct * pQ = I1308;
    I1568 = ((U )vcs_clocks) + I692;
    I1570 = I1568 & ((1 << fHashTableSize) - 1);
    I1303->I737 = (EBLK  *)(-1);
    I1303->I738 = I1568;
    if (0 && rmaProfEvtProp) {
        vcs_simpSetEBlkEvtID(I1303);
    }
    if (I1568 < (U )vcs_clocks) {
        I1569 = ((U  *)&vcs_clocks)[1];
        sched_millenium(pQ, I1303, I1569 + 1, I1568);
    }
    else if ((peblkFutQ1Head != ((void *)0)) && (I692 == 1)) {
        I1303->I740 = (struct eblk *)peblkFutQ1Tail;
        peblkFutQ1Tail->I737 = I1303;
        peblkFutQ1Tail = I1303;
    }
    else if ((I1571 = pQ->I1211[I1570].I752)) {
        I1303->I740 = (struct eblk *)I1571->I751;
        I1571->I751->I737 = (RP )I1303;
        I1571->I751 = (RmaEblk  *)I1303;
    }
    else {
        sched_hsopt(pQ, I1303, I1568);
    }
}
void  hs_0_M_167_21__simv_daidir (UB  * pcode, scalar  val)
{
    if (*(pcode + 0) == val) {
        if (fRTFrcRelCbk) {
            U  I1390 = 0;
            if (fScalarIsForced) {
                I1390 = 29;
            }
            else if (fScalarIsReleased) {
                I1390 = 30;
            }
            if ((fScalarIsForced || fScalarIsReleased) && fRTFrcRelCbk && *(RP  *)((pcode + 128))) {
                RP  I1435 = (RP )(pcode + 128);
                void * I1436 = hsimGetCbkMemOptCallback(I1435);
                if (I1436) {
                    SDaicbForHsimCbkMemOptNoFlagFrcRel(I1436, I1390, -1, -1, -1);
                }
                fScalarIsForced = 0;
                fScalarIsReleased = 0;
            }
        }
        return  ;
    }
    *(pcode + 0) = val;
    if (fRTFrcRelCbk) {
        U  I1390 = 0;
        if (fScalarIsForced) {
            I1390 = 29;
        }
        else if (fScalarIsReleased) {
            I1390 = 30;
        }
        if ((fScalarIsForced || fScalarIsReleased) && fRTFrcRelCbk && *(RP  *)((pcode + 128))) {
            RP  I1435 = (RP )(pcode + 128);
            void * I1436 = hsimGetCbkMemOptCallback(I1435);
            if (I1436) {
                SDaicbForHsimCbkMemOptNoFlagFrcRel(I1436, I1390, -1, -1, -1);
            }
            fScalarIsForced = 0;
            fScalarIsReleased = 0;
        }
    }
    *(pcode + 1) = X4val[val];
    RmaRtlXEdgesHdr  * I949 = (RmaRtlXEdgesHdr  *)(pcode + 8);
    RmaRtlEdgeBlock  * I788;
    U  I5 = I949->I5;
    scalar  I820 = (((I5) >> (16)) & ((1 << (8)) - 1));
    US  I1451 = (1 << (((I820) << 2) + (X4val[val])));
    if (I1451 & 31692) {
        rmaSchedRtlXEdges(I949, I1451, X4val[val]);
    }
    (I5) = (((I5) & ~(((U )((1 << (8)) - 1)) << (16))) | ((X4val[val]) << (16)));
    I949->I5 = I5;
    {
        unsigned long long * I1691 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 96 + 4, I1691, 25U);
    }
    {
        RP  I1495;
        RP  * I728 = (RP  *)(pcode + 128);
        {
            I1495 = *I728;
            if (I1495) {
                hsimDispatchCbkMemOptNoDynElabS(I728, val, 0U);
            }
        }
    }
    {
        U  I1484;
        RP  I1485;
        RP  I1486;
        U  * I1487;
        U  I1440;
        RP  I1488;
        U  I1489 = 0;
        scalar  I1490;
        scalar  I1439 = X4val[val];
        U  I1491 = 0;
        scalar  I1492 = 0;
        scalar  I1493 = 0;
        struct dummyq_struct * pQ;
        U  I1306;
        I1306 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1485 = (RP )(pcode + 136);
        I1486 = (RP )(I1485 + 0U);
        I1487 = (U  *)(I1486 + 24U);
        I1440 = *I1487;
        I1490 = (scalar )((((I1440) >> (0)) & ((1 << (3)) - 1)));
        I1484 = (I1490 << 2) + I1439;
        I1484 = 1 << I1484;
        if (I1484 & 8718) {
            I1492 = 0x1;
        }
        if (I1489 && !I1492) {
            I1492 = 0x3;
        }
        (*I1487) = (((*I1487) & ~(((U )((1 << (3)) - 1)) << (0))) | ((I1439) << (0)));
        if (I1484 & 8718) {
            I1493 |= (0x1 << I1491);
        }
        I1491++;
        I1493 = I1493 | (I1492 << 3);
        if (I1493) {
            (*I1487) = (((*I1487) & ~(((U )((1 << (5)) - 1)) << (3))) | ((I1493) << (3)));
            *(FP1  **)(I1486 + 0U) = (FP1  *)(rmaSched0UpdateEvTrigFnPtr);
            SchedSemiLerTXP_th(pQ, (EBLK  *)I1486);
        }
    }
    RP  * I1483;
    I1483 = (RP  *)(pcode + 184);
    *(pcode + 192) = X4val[val];
    if (*I1483) {
        Wsvvar_sched_virt_intf_eval(I1483);
        Wsvvar_callback_virt_intf(I1483);
    }
    {
        scalar  I1526;
        scalar  I1439;
        U  I1484;
        U  I1534;
        U  I1535;
        EBLK  * I1303;
        struct dummyq_struct * pQ;
        U  I1306;
        I1306 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1439 = X4val[val];
        I1526 = *(pcode + 200);
        *(pcode + 200) = I1439;
        I1484 = (I1526 << 2) + I1439;
        I1484 = 1 << I1484;
        if (I1484 & 2) {
            EBLK  * I1303 = (EBLK  *)((UB  *)(pcode + 208 + 0U));
            UB  * I1078 = (UB  *)I1303->I735;
            RP  I1051 = *(RP  *)(I1078 + 8U);
            if (I1051) {
                if ((I1303->I737 == 0)) {
                    U  I1531 = (X4val[val] << ((sizeof(U ) * 8) - 3));
                    U  I1532 = *(U  *)(I1078 + 4U);
                    I1532 &= ~(0x3 << ((sizeof(U ) * 8) - 3));
                    I1532 |= I1531;
                    *(U  *)(I1078 + 4U) = I1532;
                }
            }
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 208), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 208));
            }
        }
        if (I1484 & 16) {
            EBLK  * I1303 = (EBLK  *)((UB  *)(pcode + 208 + 40U));
            UB  * I1078 = (UB  *)I1303->I735;
            RP  I1051 = *(RP  *)(I1078 + 8U);
            if (I1051) {
                if ((I1303->I737 == 0)) {
                    U  I1531 = (X4val[val] << ((sizeof(U ) * 8) - 3));
                    U  I1532 = *(U  *)(I1078 + 4U);
                    I1532 &= ~(0x3 << ((sizeof(U ) * 8) - 3));
                    I1532 |= I1531;
                    *(U  *)(I1078 + 4U) = I1532;
                }
            }
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 248), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 248));
            }
        }
    }
    {
        scalar  I1526;
        scalar  I1439;
        U  I1484;
        I1439 = X4val[val];
        I1526 = *(pcode + 288);
        *(pcode + 288) = I1439;
        I1484 = (I1526 << 2) + I1439;
        I1484 = 1 << I1484;
        if ((I1484 & 31710)) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion((struct eblk *)(pcode + 296));
            }
            else {
                sched0(pcode + 296);
            }
        }
    }
    {
        pcode += 336;
        {
            *((*(UB  **)(pcode + 8)) + 2) = X4val[val];
            (*txpFnPtr)(pcode, 0);
        }
    }
    {
        scalar  I1526;
        scalar  I1439;
        U  I1484;
        U  I1534;
        U  I1535;
        RP  * I1488;
        US  * I1536;
        RP  I1537;
        EBLK  * I1303;
        struct dummyq_struct * pQ;
        U  I1306;
        I1306 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1439 = X4val[val];
        I1526 = *(pcode + 40);
        *(pcode + 40) = I1439;
        I1484 = (I1526 << 2) + I1439;
        I1484 = 1 << I1484;
        I1488 = *(RP  **)(*(UB  **)(pcode + 48 + 0U + 8U) + 16U);
        I1536 = (US  *)(*(UB  **)(pcode + 48 + 0U + 8U) + 0U);
        if (I1488 && (I1484 & 12)) {
            *((US  *)I1536) |= (US )I1484;
            *(RP  **)(*(UB  **)(pcode + 48 + 0U + 8U) + 16U) = (RP  *)((RP )I1488 | 1);
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 48), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 48));
            }
        }
        I1488 = *(RP  **)(*(UB  **)(pcode + 48 + 40U + 8U) + 16U);
        I1536 = (US  *)(*(UB  **)(pcode + 48 + 40U + 8U) + 0U);
        if (I1488 && (I1484 & 8704)) {
            *((US  *)I1536) |= (US )I1484;
            *(RP  **)(*(UB  **)(pcode + 48 + 40U + 8U) + 16U) = (RP  *)((RP )I1488 | 1);
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 88), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 88));
            }
        }
        I1488 = *(RP  **)(*(UB  **)(pcode + 48 + 80U + 8U) + 16U);
        I1536 = (US  *)(*(UB  **)(pcode + 48 + 80U + 8U) + 0U);
        if (I1488 && (I1484 & 192)) {
            *((US  *)I1536) |= (US )I1484;
            *(RP  **)(*(UB  **)(pcode + 48 + 80U + 8U) + 16U) = (RP  *)((RP )I1488 | 1);
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 128), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 128));
            }
        }
        I1488 = *(RP  **)(*(UB  **)(pcode + 48 + 120U + 8U) + 16U);
        I1536 = (US  *)(*(UB  **)(pcode + 48 + 120U + 8U) + 0U);
        if (I1488 && (I1484 & 4352)) {
            *((US  *)I1536) |= (US )I1484;
            *(RP  **)(*(UB  **)(pcode + 48 + 120U + 8U) + 16U) = (RP  *)((RP )I1488 | 1);
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 168), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 168));
            }
        }
        I1488 = *(RP  **)(*(UB  **)(pcode + 48 + 160U + 8U) + 16U);
        I1536 = (US  *)(*(UB  **)(pcode + 48 + 160U + 8U) + 0U);
        if (I1488 && (I1484 & 18432)) {
            *((US  *)I1536) |= (US )I1484;
            *(RP  **)(*(UB  **)(pcode + 48 + 160U + 8U) + 16U) = (RP  *)((RP )I1488 | 1);
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 208), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 208));
            }
        }
        I1488 = *(RP  **)(*(UB  **)(pcode + 48 + 200U + 8U) + 16U);
        I1536 = (US  *)(*(UB  **)(pcode + 48 + 200U + 8U) + 0U);
        if (I1488 && (I1484 & 2)) {
            *((US  *)I1536) |= (US )I1484;
            *(RP  **)(*(UB  **)(pcode + 48 + 200U + 8U) + 16U) = (RP  *)((RP )I1488 | 1);
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 248), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 248));
            }
        }
        I1488 = *(RP  **)(*(UB  **)(pcode + 48 + 240U + 8U) + 16U);
        I1536 = (US  *)(*(UB  **)(pcode + 48 + 240U + 8U) + 0U);
        if (I1488 && (I1484 & 16)) {
            *((US  *)I1536) |= (US )I1484;
            *(RP  **)(*(UB  **)(pcode + 48 + 240U + 8U) + 16U) = (RP  *)((RP )I1488 | 1);
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 288), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 288));
            }
        }
    }
    {
        scalar  I1693 = X4val[val];
        scalar  I1694 = *(scalar  *)(pcode + 328 + 2U);
        *(scalar  *)(pcode + 328 + 2U) = I1693;
        UB  * I949 = *(UB  **)(pcode + 328 + 8U);
        if (I949) {
            U  I1695 = I1693 * 2;
            U  I1696 = 1 << ((I1694 << 2) + I1693);
            *(pcode + 328 + 0U) = 1;
            while (I949){
                UB  * I1698 = *(UB  **)(I949 + 8U);
                if ((*(US  *)(I949 + 0U)) & I1696) {
                    *(*(UB  **)(I949 + 40U)) = 1;
                    (*(FP  *)(I949 + 24U))((void *)(*(RP  *)(I949 + 32U)), (((*(scalar  *)(I949 + 2U)) >> I1695) & 3));
                }
                I949 = I1698;
            };
            *(pcode + 328 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 328);
        }
    }
}
void  hs_0_M_167_0__simv_daidir (UB  * pcode, scalar  val)
{
    UB  * I1635;
    *(pcode + 0) = val;
    if (*(pcode + 1)) {
        return  ;
    }
    pcode += 16;
    hs_0_M_167_21__simv_daidir(pcode, val);
    fScalarIsReleased = 0;
}
void  hs_0_M_167_1__simv_daidir (UB  * pcode, scalar  val, U  I684, scalar  * I1323, U  did)
{
    U  I1302 = 0;
    *(pcode + 1) = 1;
    *(U  *)(pcode + 8) = did;
    fScalarIsForced = 1;
    pcode += 16;
    hs_0_M_167_21__simv_daidir(pcode, val);
    fScalarIsForced = 0;
}
void  hs_0_M_167_2__simv_daidir (UB  * pcode)
{
    scalar  val;
    fScalarIsReleased = 1;
    val = *(pcode + 0);
    *(pcode + 1) = 0;
    pcode += 16;
    hs_0_M_167_21__simv_daidir(pcode, val);
    fScalarIsReleased = 0;
}
void  hs_0_M_169_21__simv_daidir (UB  * pcode, scalar  val)
{
    if (*(pcode + 0) == val) {
        if (fRTFrcRelCbk) {
            U  I1390 = 0;
            if (fScalarIsForced) {
                I1390 = 29;
            }
            else if (fScalarIsReleased) {
                I1390 = 30;
            }
            if ((fScalarIsForced || fScalarIsReleased) && fRTFrcRelCbk && *(RP  *)((pcode + 128))) {
                RP  I1435 = (RP )(pcode + 128);
                void * I1436 = hsimGetCbkMemOptCallback(I1435);
                if (I1436) {
                    SDaicbForHsimCbkMemOptNoFlagFrcRel(I1436, I1390, -1, -1, -1);
                }
                fScalarIsForced = 0;
                fScalarIsReleased = 0;
            }
        }
        return  ;
    }
    *(pcode + 0) = val;
    if (fRTFrcRelCbk) {
        U  I1390 = 0;
        if (fScalarIsForced) {
            I1390 = 29;
        }
        else if (fScalarIsReleased) {
            I1390 = 30;
        }
        if ((fScalarIsForced || fScalarIsReleased) && fRTFrcRelCbk && *(RP  *)((pcode + 128))) {
            RP  I1435 = (RP )(pcode + 128);
            void * I1436 = hsimGetCbkMemOptCallback(I1435);
            if (I1436) {
                SDaicbForHsimCbkMemOptNoFlagFrcRel(I1436, I1390, -1, -1, -1);
            }
            fScalarIsForced = 0;
            fScalarIsReleased = 0;
        }
    }
    RmaRtlXEdgesHdr  * I949 = (RmaRtlXEdgesHdr  *)(pcode + 8);
    RmaRtlEdgeBlock  * I788;
    U  I5 = I949->I5;
    scalar  I820 = (((I5) >> (16)) & ((1 << (8)) - 1));
    US  I1451 = (1 << (((I820) << 2) + (X4val[val])));
    if (I1451 & 31692) {
        rmaSchedRtlXEdges(I949, I1451, X4val[val]);
    }
    (I5) = (((I5) & ~(((U )((1 << (8)) - 1)) << (16))) | ((X4val[val]) << (16)));
    I949->I5 = I5;
    {
        unsigned long long * I1691 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 96 + 4, I1691, 25U);
    }
    {
        RP  I1495;
        RP  * I728 = (RP  *)(pcode + 128);
        {
            I1495 = *I728;
            if (I1495) {
                hsimDispatchCbkMemOptNoDynElabS(I728, val, 0U);
            }
        }
    }
    {
        scalar  I1526;
        scalar  I1439;
        U  I1484;
        U  I1534;
        U  I1535;
        EBLK  * I1303;
        struct dummyq_struct * pQ;
        U  I1306;
        I1306 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1439 = X4val[val];
        I1526 = *(pcode + 136);
        *(pcode + 136) = I1439;
        I1484 = (I1526 << 2) + I1439;
        I1484 = 1 << I1484;
        if (I1484 & 2) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 144), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 144));
            }
        }
        if (I1484 & 16) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 184), I1306);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 184));
            }
        }
    }
    {
        scalar  I1526;
        scalar  I1439;
        U  I1484;
        I1439 = X4val[val];
        I1526 = *(pcode + 224);
        *(pcode + 224) = I1439;
        I1484 = (I1526 << 2) + I1439;
        I1484 = 1 << I1484;
        if ((I1484 & 31710)) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion((struct eblk *)(pcode + 232));
            }
            else {
                sched0(pcode + 232);
            }
        }
    }
    {
        scalar  I1693 = X4val[val];
        scalar  I1694 = *(scalar  *)(pcode + 272 + 2U);
        *(scalar  *)(pcode + 272 + 2U) = I1693;
        UB  * I949 = *(UB  **)(pcode + 272 + 8U);
        if (I949) {
            U  I1695 = I1693 * 2;
            U  I1696 = 1 << ((I1694 << 2) + I1693);
            *(pcode + 272 + 0U) = 1;
            while (I949){
                UB  * I1698 = *(UB  **)(I949 + 8U);
                if ((*(US  *)(I949 + 0U)) & I1696) {
                    *(*(UB  **)(I949 + 40U)) = 1;
                    (*(FP  *)(I949 + 24U))((void *)(*(RP  *)(I949 + 32U)), (((*(scalar  *)(I949 + 2U)) >> I1695) & 3));
                }
                I949 = I1698;
            };
            *(pcode + 272 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 272);
        }
    }
}
void  hs_0_M_169_0__simv_daidir (UB  * pcode, scalar  val)
{
    UB  * I1635;
    *(pcode + 0) = val;
    if (*(pcode + 1)) {
        return  ;
    }
    pcode += 16;
    hs_0_M_169_21__simv_daidir(pcode, val);
    fScalarIsReleased = 0;
}
void  hs_0_M_169_1__simv_daidir (UB  * pcode, scalar  val, U  I684, scalar  * I1323, U  did)
{
    U  I1302 = 0;
    *(pcode + 1) = 1;
    *(U  *)(pcode + 8) = did;
    fScalarIsForced = 1;
    pcode += 16;
    hs_0_M_169_21__simv_daidir(pcode, val);
    fScalarIsForced = 0;
}
void  hs_0_M_169_2__simv_daidir (UB  * pcode)
{
    scalar  val;
    fScalarIsReleased = 1;
    val = *(pcode + 0);
    *(pcode + 1) = 0;
    pcode += 16;
    hs_0_M_169_21__simv_daidir(pcode, val);
    fScalarIsReleased = 0;
}
void  hs_0_M_217_0__simv_daidir (UB  * pcode, vec32  * I1020, U  I927)
{
    UB  * I1635;
    typedef
    UB
     * TermTypePtr;
    U  I1396;
    U  I1351;
    TermTypePtr  I1354;
    U  I1394;
    vec32  * I1387;
    I1354 = (TermTypePtr )pcode;
    I1396 = *I1354;
    I1354 -= I1396;
    I1351 = 2U;
    pcode = (UB  *)(I1354 + I1351);
    pcode = (UB  *)(((UP )(pcode + 0) + 3U) & ~3LU);
    I1394 = (1 + (((I927) - 1) / 32));
    I1387 = (vec32  *)(pcode + 0);
    {
        U  I1322;
        vec32  * I1356 = I1387 + I1396 * I1394;
        U  I1372 = 0;
        I1322 = 0;
        if (!I1372) {
            for (; I1322 < I1394; I1322++) {
                if (I1020[I1322].I1 != I1356[I1322].I1 || I1020[I1322].I2 != I1356[I1322].I2) {
                    break ;
                }
            }
            if (I1322 == I1394) {
                return  ;
            }
        }
        for (; I1322 < I1394; I1322++) {
            I1356[I1322].I1 = I1020[I1322].I1;
            I1356[I1322].I2 = I1020[I1322].I2;
        }
    }
    I1020 = (vec32  *)(I1387 + I1351 * I1394);
    rmaEvalWunionW(I1020, I1387, I927, I1351);
    U  I1371 = 0;
    pcode += ((I1351 + 1) * I1394 * sizeof(vec32 ) + I1371);
    pcode = (UB  *)(((UP )(pcode + 0) + 7U) & ~7LU);
    I927 = *(U  *)((pcode + 0));
    {
        EBLK  * I1303;
        struct dummyq_struct * pQ;
        U  I1306;
        I1306 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        {
            RmaEblk  * I1303 = (RmaEblk  *)(pcode + 8);
            vec32  * I1586 = (vec32  *)((pcode + 48));
            if (rmaChangeCheckAndUpdateW(I1586, I1020, I927)) {
                if (!(I1303->I737)) {
                    pQ->I1205->I737 = (EBLK  *)I1303;
                    pQ->I1205 = (EBLK  *)I1303;
                    I1303->I737 = (RP )((EBLK  *)-1);
                    if (0 && rmaProfEvtProp) {
                        vcs_simpSetEBlkEvtID(I1303);
                    }
                }
            }
        }
    }
}
void  hs_0_M_217_9__simv_daidir (UB  * pcode, vec32  * I1020)
{
    U  I927;
    I927 = *(U  *)((pcode + 0) - sizeof(RP ));
    I1020 = (vec32  *)(pcode + 40);
    U  I1587 = sizeof(vec32 ) * (1 + (((I927) - 1) / 32));
    pcode = ((UB  *)I1020) + I1587;
    pcode = (UB  *)(((UP )(pcode + 0) + 7U) & ~7LU);
    vec32  * I1400 = 0;
    {
        U  I1394 = (1 + (((I927) - 1) / 32));
        I1400 = (vec32  *)((pcode + 0));
        pcode += (I1394 * sizeof(vec32 ));
        rmaUpdateW(I1400, I1020, I927);
    }
    {
        pcode = (UB  *)((((RP )pcode + 0) + 7) & (~7));
        ((void)0);
        {
            RP  * I728 = (RP  *)(pcode + 0);
            RP  I1495;
            I1495 = *I728;
            if (I1495) {
                U  I1496 = I927;
                hsimDispatchCbkMemOptNoDynElabVector(I728, I1020, 2, I1496);
            }
        }
    }
    RP  * I1483;
    I1483 = (RP  *)(pcode + 8);
    if (*I1483) {
        Wsvvar_callback_virt_intf(I1483);
    }
    pcode = (UB  *)((((RP )pcode + 24) + 7) & (~7));
    ((FPV )(((RmaIbfIp  *)(pcode + 0))->I1019))((void *)((RmaIbfIp  *)(pcode + 0))->I735, (UB  *)I1020);
}
#ifdef __cplusplus
extern "C" {
#endif
void SinitHsimPats(void);
#ifdef __cplusplus
}
#endif
