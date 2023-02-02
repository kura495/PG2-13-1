#include<player.h>

player::player()
{
	Bullet_ = new bullet();
}

player::~player()
{
	delete Bullet_;
}

void player::Initialize(vec2 Pos, vec2 Speed, int Radius, int Color, int HP)
{
	Pos_ = Pos;
	Speed_ = Speed;
	Radius_ = Radius;
	Color_ = Color;
	HP_ = HP;
	Bullet_->Initialize(-5, 16, RED);
}

void player::Move(char keys[256])
{
	int PressX = 0;
	int PressY = 0;
	if (keys[DIK_W])
	{
		PressY = -1;
	}
	if (keys[DIK_S])
	{
		PressY = 1;
	}
	if (keys[DIK_A])
	{
		PressX = -1;
	}
	if (keys[DIK_D])
	{
		PressX = 1;
	}
	float length = sqrt(PressX * PressX + PressY * PressY);
	float PlusX = 0;
	float PlusY = 0;
	if (length != 0) {
		PlusX = (PressX / length) * Speed_.x;
		PlusY = (PressY / length) * Speed_.y;
	}
	Pos_.x += PlusX;
	Pos_.y += PlusY;
}

void player::BulletShot(char keys[256], char preKeys[256])
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0 && Bullet_->getFlag() == false) {
		Bullet_->setStatus({ Pos_.x, Pos_.y, }, -5, 16, WHITE);
	}
	Bullet_->BulletUpdate();
}

void player::DrawPlayer()
{
	Novice::DrawEllipse(Pos_.x, Pos_.y, Radius_, Radius_, 0.0f, Color_, kFillModeSolid);
	Bullet_->DrawBullet();
}

void player::OnCollision()
{
	HP_ -= 1;
	Color_ = BLUE;
}

void player::OnCollisionBullet()
{
	Bullet_->OnCollision();
}