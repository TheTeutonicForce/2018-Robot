#ifndef AM_L_CloseSwitch_Right_H
#define AM_L_CloseSwitch_Right_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "JogForward.h"
#include "AutoArm.h"
#include "AutoGrip.h"
#include "AutoUnGrip.h"

class AM_L_CloseSwitch_Right : public CommandGroup {
public:
	AM_L_CloseSwitch_Right();
};

#endif  // AM_L_CloseSwitch_Right_H
