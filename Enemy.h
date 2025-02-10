#pragma once
#include"Object.h"

class Enemy : public Object
{
public:

	bool isAlive_;
	Vector2 size_;

	Enemy();
	~Enemy();

	Vector2 GetPos() { return pos_; };
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	bool GetIsAlive() { return isAlive_; };

	void SetPos(Vector2 pos);
	void SetIsAlive(bool isAlive);

	void Update();
	void Draw();

};
