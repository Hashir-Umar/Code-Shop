#pragma once
#include "Scene.h"

class CityScene :
	public Scene
{
public:
	CityScene(int);
	virtual void draw();
	~CityScene();
};

