#include<bullet.h>
bullet::bullet()
{
}

bullet::~bullet()
{
}


void bullet::Initialize(int Speed, int Radius, int Color)
{
	Speed_ = Speed;
	Radius_ = Radius;
	Color_ = Color;
}

void bullet::BulletUpdate()
{
	if (Flag_ == true) {
		Pos_.y += Speed_;
	}
	posLimit();
}

void bullet::DrawBullet()
{
	if (Flag_ == true) {
		Novice::DrawEllipse(Pos_.x, Pos_.y, Radius_, Radius_, 0.0f, Color_, kFillModeSolid);
	}
}

void bullet::posLimit()
{
	if (Flag_ == true) {
		if (Pos_.y + Radius_ <= MinHeight) {
			Flag_ = false;
		}
		if (Pos_.y - Radius_ >= MaxHeight) {
			Flag_ = false;
		}
	}
}

void bullet::setStatus(vec2 Pos, int Speed, int Radius, int Color)
{
	Pos_ = Pos;
	Speed_ = Speed;
	Radius_ = Radius;
	Color_ = Color;
	Flag_ = true;
}

void bullet::OnCollision()
{
	Flag_ = false;
	Pos_ = { -500,-500 };
}
