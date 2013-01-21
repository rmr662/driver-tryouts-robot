#ifndef RMRPNEUMATIC_H
#define RMRPNEUMATIC_H

#include "WPILib.h"
#include "RMRCompressor.h"
#include "RMRComponent.h"

namespace rmr {
	class Pneumatic : public Component {
		public:
			Pneumatic();
			virtual ~Pneumatic();
			virtual void update(Joystick &controller);
		private:
			RMRCompressor m_compressor;
			DigitalInput m_disableSwitch;
	};
}

#endif
