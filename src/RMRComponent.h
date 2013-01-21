#ifndef RMRCOMPONENT_H
#define RMRCOMPONENT_H

#include "WPILib.h"

namespace rmr {
	class Component {
		public:
			Component();
			virtual ~Component();
			virtual void update(Joystick &controller) = 0;
	};
}

#endif
