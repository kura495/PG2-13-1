#include<enemy.h>
enemy::enemy()
{
	enemyCount++;
}

enemy::~enemy()
{
	enemyCount--;
}

void enemy::Move()
{
	if (HP_ > 0) {
		Pos_.x += Speed_.x;
	}
	PosLimit();
}

void enemy::Initialize(vec2 Pos, vec2 Speed, int Radius, int Color, int HP)
{
	Pos_ = Pos;
	Speed_ = Speed;
	Radius_ = Radius;
	Color_ = Color;
	HP_ = HP;
}


void enemy::PosLimit()
{
	if (Pos_.x + Radius_ >= MaxWidth) {
		Speed_.x *= -1;
	}
	if (Pos_.x - Radius_ <= MinWidth) {
		Speed_.x *= -1;
	}
	if (Pos_.y + Radius_ >= MaxWidth) {
		Speed_.y *= -1;
	}
	if (Pos_.y - Radius_ <= MinWidth) {
		Speed_.y *= -1;
	}
}
void enemy::DrawEnemy()
{
	Novice::DrawEllipse(Pos_.x, Pos_.y, Radius_, Radius_,0.0f, Color_, kFillModeSolid);
}
void enemy::OnCollision()
{
	HP_ = 0;
	Pos_ = { -1000,-1000 };
}


