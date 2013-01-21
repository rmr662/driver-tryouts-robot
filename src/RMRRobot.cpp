#include "RMRRobot.h"
#include "RMRDrive.h"
#include "RMRLoader.h"
#include "RMRPneumatics.h"
#include <iostream>
#include <string>

extern "C" {
void _start() {
	std::cout << "Error! _start called!" << '\n';
}
}

RMRRobot::RMRRobot()
	:m_controller(3)
{
	SmartDashboard::init();
	rmr::Drive *driveComponent = new rmr::Drive();
	m_driveComponent = driveComponent;
	//rmr::Loader *loaderComponent = new rmr::Loader();
	//rmr::Pneumatic *pneumaticComponent = new rmr::Pneumatic();
	m_components.push_back(driveComponent);
	//m_components.push_back(loaderComponent);
	//m_components.push_back(pneumaticComponent);
}

RMRRobot::~RMRRobot()
{
	// destructor
}

void RMRRobot::TeleopInit()
{
	Preferences *prefs = Preferences::GetInstance();
	char buf[128];
	memset(buf, 0, 128 * sizeof(char));
	int status = prefs->GetString("layout", buf, 128 * sizeof(char), "arcade");
	if (buf[0] == 't') {
		m_driveComponent->setControlType(rmr::Drive::kTank);
	} else {
		m_driveComponent->setControlType(rmr::Drive::kArcade);
	}
	std::cout << buf << '\n';
	memset(buf, 0, 128 * sizeof(char));
	status = prefs->GetString("controller", buf, 128 * sizeof(char), "controller");
	if (buf[0] == 'j') {
		m_driveComponent->setHardwareType(rmr::Drive::kJoystick);
	} else {
		m_driveComponent->setHardwareType(rmr::Drive::kController);
	}
	std::cout << buf << '\n';
}

void RMRRobot::TeleopPeriodic()
{
	for (std::vector<rmr::Component*>::iterator it = m_components.begin(); it != m_components.end(); ++it) {
		(*it)->update(m_controller);
	}
}

START_ROBOT_CLASS(RMRRobot);
