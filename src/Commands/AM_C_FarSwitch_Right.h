#ifndef AM_C_FarSwitch_Right_H
#define AM_C_FarSwitch_Right_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "JogForward.h"
#include "AutoGrip.h"
#include "AutoUnGrip.h"
#include "AutoArm.h"

class AM_C_FarSwitch_Right : public CommandGroup {
public:
	AM_C_FarSwitch_Right();
};

#endif  // AM_C_FarSwitch_Right_H
