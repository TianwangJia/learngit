#ifndef _BOXADL_H_
#define _BOXADL_H_

void deletebox(MINDBOX (*editp)[16], int ho, int ve);

void movebox(MINDBOX *former, MINDBOX *latter);

void vanbox(MINDBOX *clrbox);

#endif // !_BOXADL_H_