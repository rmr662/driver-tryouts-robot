#include "RMRDrive.h"

namespace rmr {
	Drive::Drive()
		:Component::Component(), m_leftMotor(1, false), m_rightMotor(2, true), m_robotDrive(new RobotDrive(&m_leftMotor, &m_rightMotor)), leftJoystick(1), rightJoystick(2)
	{
		setControlType(kArcade);	
	}

	Drive::~Drive()
	{

	}

	void Drive::update(Joystick &controller)
	{
		if (getHardwareType() == kController) {
			switch (getControlType()) {
			case kArcade:
				m_robotDrive->ArcadeDrive(controller, 2, controller, 4, true);
				break;
			case kTank:
				m_robotDrive->TankDrive(controller, 2, controller, 5, true);
			}
		} else {
			switch (getControlType()) {
			case kArcade:
				m_robotDrive->ArcadeDrive(leftJoystick, true);
				break;
			case kTank:
				m_robotDrive->TankDrive(leftJoystick, rightJoystick, true);
			}
		}
	}
}
