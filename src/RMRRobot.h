#ifndef RMRROBOT_H
#define RMRROBOT_H

#include "WPILib.h"
#include "RMRComponent.h"
#include "RMRCompressor.h"
#include "RMRDrive.h"
#include <vector>
#include <memory>

class RMRRobot : public IterativeRobot {
	public:
		RMRRobot();
		virtual ~RMRRobot();
		virtual void TeleopPeriodic();
		virtual void TeleopInit();
	protected:
		std::vector<rmr::Component*> m_components;
		Joystick m_controller;
	private:
		rmr::Drive *m_driveComponent;
};

#endif
