#include "Bullet.h"

Bullet::Bullet()
{
	pos_ = { 0.0f,0.0f };
	radius_ = 15.0f;
	isActive_ = false;
	velocity_ = { 5.0f,5.0f };
	
}


void Bullet::Update()
{
	if (!isActive_)
	{
		return;
	}

	if (pos_.x - radius_ >= 1280.0f)
	{
		isActive_ = false;
	}

	pos_.x += velocity_.x;
}

void Bullet::SetPos(Vector2 pos)
{
	pos_ = pos;
}

void Bullet::SetIsActive(bool isActive)
{
	isActive_ = isActive;
}

void Bullet::SetRadius(float radius)
{
	radius_ = radius;
}

void Bullet::Draw()
{

	if (!isActive_)
	{
		return;
	}

	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		0xFFFFFFFF,
		kFillModeSolid
	);

}
