#include "RMRPneumatics.h"

namespace rmr {
	Pneumatic::Pneumatic()
		:m_disableSwitch(12)
	{

	}

	Pneumatic::~Pneumatic()
	{

	}

	void Pneumatic::update(Joystick &controller)
	{
		if (m_disableSwitch.Get() && m_compressor.Enabled()) {
			m_compressor.Stop();
		}
		if (!m_disableSwitch.Get() && !m_compressor.Enabled()) {
			m_compressor.Start();
		}
	}
}
