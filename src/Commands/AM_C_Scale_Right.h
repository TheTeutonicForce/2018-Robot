#ifndef AM_C_Scale_Right_H
#define AM_C_Scale_Right_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "AutoArm.h"
#include "AutoGrip.h"
#include "AutoUnGrip.h"

class AM_C_Scale_Right : public CommandGroup {
public:
	AM_C_Scale_Right();
};

#endif  // AM_C_Scale_Right_H
