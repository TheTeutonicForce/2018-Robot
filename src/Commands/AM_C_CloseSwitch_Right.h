#ifndef AM_C_CloseSwitch_Right_H
#define AM_C_CloseSwitch_Right_H

#include <Commands/CommandGroup.h>
#include "AutoAccel.h"
#include "AutoTurn.h"
#include "AutoGrip.h"
#include "AutoArm.h"
#include "AutoUnGrip.h"

class AM_C_CloseSwitch_Right : public CommandGroup {
public:
	AM_C_CloseSwitch_Right();
};

#endif  // AM_C_CloseSwitch_Right_H
