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
#ifdef __cplusplus
extern "C" {
#endif
void SinitHsimPats(void);
#ifdef __cplusplus
}
#endif
