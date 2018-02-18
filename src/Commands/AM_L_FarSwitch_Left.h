#ifndef AM_L_FarSwitch_Left_H
#define AM_L_FarSwitch_Left_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "JogForward.h"
#include "AutoArm.h"
#include "AutoGrip.h"
#include "AutoUnGrip.h"

class AM_L_FarSwitch_Left : public CommandGroup {
public:
	AM_L_FarSwitch_Left();
};

#endif  // AM_L_FarSwitch_Left_H
