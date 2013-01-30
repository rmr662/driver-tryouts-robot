#ifndef RMRCAPTURER_H
#define RMRCAPTURER_H

#include "WPILib.h"
#include "RMRComponent.h"
#include "RMRInvertableJaguar.h"

namespace rmr {
	class Capturer : public Component {
		public:
			Capturer();
			virtual ~Capturer();
			virtual void update(Joystick &controller);
		protected:
			InvertableJaguar m_motor;
	};
}

#endif
