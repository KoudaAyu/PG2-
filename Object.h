#pragma once
#include"Structer.h"



class Object
{
protected:

	Vector2 pos_;
	Vector2 velocity_;
	bool isActive_;

public:
	Object();
	~Object();

};
