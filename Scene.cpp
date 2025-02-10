#include"Scene.h"

SCENE Scene::sceneNo_ = SCENE_TITLE;



Scene::Scene()
{
	frame_ = 0.0f;
}

Scene::~Scene()
{
}

void Scene::SetFrame(float frame)
{
	frame_ = frame;
}