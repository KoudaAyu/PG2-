#pragma once
#include"Object.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Conster.h"

class Player : public Object
{
private:

	bool isAlive_;
	Bullet bullets_[kMaxBullet];
	Vector2 size_;
	float coolTimes_;
	Enemy* enemy_ = nullptr;
	int score_;

public:

	
	
	Player(Vector2 pos);
	~Player();

	Vector2 GetPos(){ return pos_; };
	bool GetIsAlive() { return isAlive_; };
	float GetSize() { return size_.x; };
	int GetScore() { return score_; };


	void SetIsAlive(bool isAlive);
	void SetScore(int score);

	
	Bullet* GetBullets();

	void Move(char*keys);



	void Draw();

};