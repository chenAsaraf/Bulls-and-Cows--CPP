#pragma once
#include <iostream>

namespace bullpgia {
	class Chooser {
		public:
			uint length;
			virtual std::string choose(uint length)=0;
	};
}