#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f // if touched change METER_PER_PIXEL too
#define METER_PER_PIXEL 0.02f // this is 1 / PIXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)

class b2World;
class b2Body;


// TODO 5: Create a small class that keeps a pointer to the b2Body
// and has a method to request the position
// then write the implementation in the .cpp
// Then make your circle creation function to return a pointer to that class

class PhysBody
{
private:

	b2Body * body = nullptr;

public:

	PhysBody() {};
	//~PhysBody();
	PhysBody(b2Body* b) : body(b) {};
	p2Point<float> GetPosition();
	double GetRotation();
	

};



class ModulePhysics : public Module
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	// TODO 3: Move body creation to 3 functions to create circles, rectangles and chains

	PhysBody* createCircle(float radius);
	PhysBody* createBox(float hx, float hy);
	PhysBody* createChain(int vector[], int size);

	int rick_head[80] = {
		41, 0,
		55, 10,
		67, 22,
		75, 31,
		81, 22,
		84, 14,
		87, 5,
		93, 16,
		94, 26,
		94, 40,
		112, 35,
		105, 57,
		106, 62,
		117, 66,
		109, 75,
		110, 81,
		109, 88,
		106, 94,
		111, 100,
		103, 105,
		101, 117,
		105, 121,
		106, 126,
		99, 127,
		94, 139,
		85, 147,
		72, 149,
		60, 146,
		49, 137,
		46, 132,
		35, 137,
		40, 127,
		23, 125,
		31, 115,
		8, 103,
		29, 92,
		0, 77,
		30, 63,
		13, 36,
		42, 39
	};

private:

	bool debug;
	b2World* world;
};