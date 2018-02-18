#ifndef AM_C_ExchangeCube_H
#define AM_C_ExchangeCube_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "AutoGrip.h"
#include "AutoArm.h"
#include "AutoUnGrip.h"

class AM_C_ExchangeCube : public CommandGroup {
public:
	AM_C_ExchangeCube();
};

#endif  // AM_C_ExchangeCube_H
