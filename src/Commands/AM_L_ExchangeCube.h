#ifndef AM_L_ExchangeCube_H
#define AM_L_ExchangeCube_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "AutoArm.h"
#include "AutoGrip.h"
#include "AutoUnGrip.h"

class AM_L_ExchangeCube : public CommandGroup {
public:
	AM_L_ExchangeCube();
};

#endif  // AM_L_ExchangeCube_H
