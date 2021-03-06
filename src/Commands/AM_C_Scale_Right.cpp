#include "AM_C_Scale_Right.h"

AM_C_Scale_Right::AM_C_Scale_Right() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
	AddSequential(new AutoTurn(0,0,0));
	AddSequential(new AutoAccel((39-15)/12,0.3,1,0));
	AddSequential(new AutoTurn((90-14),0.2,1));
	AddSequential(new Delay(1));
	AddSequential(new AutoAccel((123.5-15)/12,0.3,1,90));
	AddSequential(new AutoTurn((-90+14),0.2,1));
	AddSequential(new Delay(1));
	AddSequential(new AutoAccel((260-15)/12,0.3,1,-90));
	AddParallel(new AutoArm(3));
	AddSequential(new AutoTurn((-90+14),0.2,1));
	AddSequential(new JogForward());
	AddSequential(new JogForward());
	AddSequential(new Delay(1));
	AddSequential(new AutoUnGrip);
	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
