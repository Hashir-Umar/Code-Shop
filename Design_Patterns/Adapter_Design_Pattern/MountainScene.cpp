#include "MountainScene.h"


MountainScene::MountainScene(int CD, double area) : Scene(CD)
{
	LS = new Landscape(area);
}

void MountainScene::draw()
{
	this->LS->render();
}