#pragma once
#include<character.h>
class enemy :public character
{
public:
	enemy();
	~enemy();
	static int enemyCount;

	void Move();
	void Initialize(vec2 Pos, vec2 Speed, int Radius, int Color, int HP);
	void PosLimit();
	void DrawEnemy();
	void OnCollision();

	vec2 getPos() { return Pos_; };
	int getRadius() { return Radius_; };
	int getHP() { return HP_; };

private:

	
};