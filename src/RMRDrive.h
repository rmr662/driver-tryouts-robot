#ifndef RMRDRIVE_H
#define RMRDRIVE_H

#include "WPILib.h"
#include "RMRComponent.h"
#include "RMRInvertableJaguar.h"
#include <memory>

namespace rmr {
	class Drive : public Component {
		public:
			typedef enum {
				kArcade,
				kTank
			} ControlType;
			typedef enum {
				kController,
				kJoystick
			} HardwareType;
			Drive();
			virtual ~Drive();
			virtual void update(Joystick &controller);
			void setControlType(ControlType controlType) { m_controlType = controlType; };
			ControlType getControlType() { return m_controlType; };
			void setHardwareType(HardwareType hardwareType) { m_hardwareType = hardwareType; };
			HardwareType getHardwareType() { return m_hardwareType; };
		protected:
			InvertableJaguar m_leftMotor;
			InvertableJaguar m_rightMotor;
			std::unique_ptr<RobotDrive> m_robotDrive;
			Joystick leftJoystick;
			Joystick rightJoystick;
		private:
			ControlType m_controlType;
			HardwareType m_hardwareType;
	};
}

#endif
