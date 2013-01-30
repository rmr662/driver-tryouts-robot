#include "RMRCapturer.h"
#include <iostream>

namespace rmr {
	Capturer::Capturer()
		:m_motor(3, false)
	{

	}
	
	Capturer::~Capturer()
	{

	}
	
	void Capturer::update(Joystick &controller)
	{
		float speed = controller.GetRawAxis(3);
		if (speed < 0) {
			speed = -speed;
		}
		std::cout << speed << '\n';
		m_motor.Set(speed);
	}
} 
