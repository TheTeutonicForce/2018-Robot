#ifndef AM_L_FarSwitch_Right_H
#define AM_L_FarSwitch_Right_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "JogForward.h"
#include "AutoArm.h"
#include "AutoUnGrip.h"

class AM_L_FarSwitch_Right : public CommandGroup {
public:
	AM_L_FarSwitch_Right();
};

#endif  // AM_L_FarSwitch_Right_H
