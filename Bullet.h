#pragma once
#include"Object.h"
#include"Enumuration.h"

class Bullet : public Object
{
private:
	float radius_;

public:

	Bullet();

	Vector2 GetPos(){ return pos_; };
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	bool GetIsActive() { return isActive_; };
	float GetRadius() { return radius_; };

	void SetPos(Vector2 pos);
	void SetIsActive(bool isActive);
	void SetRadius(float radius);

	void Update();
	void Draw();

};