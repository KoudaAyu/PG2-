#pragma once
#include"Enumuration.h"

class Scene
{
private:
	float frame_;


public:

	static SCENE sceneNo_;

	float GetFrame() { return frame_; };
	void SetFrame(float frame);

	Scene();
	~Scene();

};