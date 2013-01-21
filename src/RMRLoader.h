#ifndef RMRLOADER_H
#define RMRLOADER_H

#include "WPILib.h"
#include "RMRComponent.h"

namespace rmr {
	class Loader : public Component {
		public:
			Loader();
			virtual ~Loader();
			virtual void update(Joystick &controller);
		protected:
			DoubleSolenoid m_loaderSolenoid;
	};
}

#endif
