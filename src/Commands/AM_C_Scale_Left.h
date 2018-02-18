#ifndef AM_C_Scale_Left_H
#define AM_C_Scale_Left_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "AutoGrip.h"
#include "AutoArm.h"
#include "AutoUnGrip.h"

class AM_C_Scale_Left : public CommandGroup {
public:
	AM_C_Scale_Left();
};

#endif  // AM_C_Scale_Left_H
