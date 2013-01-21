#include "RMRLoader.h"

#define SOLENOID_PORT (3)
#define SOLENOID_PORT_REVERSE (4)

namespace rmr {
	Loader::Loader()
		:m_loaderSolenoid(SOLENOID_PORT, SOLENOID_PORT_REVERSE)
	{
		
	}

	Loader::~Loader()
	{

	}

	void Loader::update(Joystick &controller)
	{
		DoubleSolenoid::Value output = controller.GetRawButton(1)?DoubleSolenoid::kReverse:DoubleSolenoid::kForward;
		m_loaderSolenoid.Set(output);
	}
}
