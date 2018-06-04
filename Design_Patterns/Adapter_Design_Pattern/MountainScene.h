#pragma once
#include "Scene.h"
#include "Landscape.h"

class MountainScene
	:public Scene
{
protected:
	Landscape *LS;

public:
	MountainScene(int, double);
	virtual void draw();
	MountainScene(const MountainScene& rhs) : Scene(rhs.capture_date)
	{
		*(this->LS) = *rhs.LS;
	}
	
	virtual ~MountainScene() { }
	MountainScene& operator =(const MountainScene& rhs)
	{
		this->capture_date = rhs.capture_date;
		*(this->LS) = *rhs.LS;
	}
};

