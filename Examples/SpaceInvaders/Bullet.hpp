#ifndef Bullet_hpp
#define Bullet_hpp

#include <Axilya/AXMain.h>
#include "PlayerController.hpp"
class Bullet : public AXCustomComponent<Bullet>{
	bool hasScored = false;
public:
	PlayerController* pc;
	void update();
	void onCollision(AXEntity* e);
	void onWorldCollision(int direction);
	void onDestroy();
};
#endif