#ifndef BallController_hpp
#define BallController_hpp value

#include <Axilya/AXMain.h>

class BallController : public CustomComponent<BallController>{
	Math::Vector2D velocity;
public:
	void start();
	void update();
};

#endif