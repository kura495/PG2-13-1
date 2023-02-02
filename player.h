#pragma once
#include<character.h>
class player :public character
{
public:
	player();
	~player();

	void Initialize(vec2 Pos, vec2 Speed, int Radius, int Color, int HP);
	/// <summary>
	/// 移動
	/// </summary>
	/// <param name="keys"></param>
	void Move(char keys[256]);
	/// <summary>
	/// 玉打つ
	/// </summary>
	/// <param name="keys"></param>
	void BulletShot(char keys[256], char preKeys[256]);
	/// <summary>
	/// 自機＋玉
	/// </summary>
	void DrawPlayer();
	/// <summary>
	/// 当たった時の処理
	/// </summary>
	void OnCollision();

	void OnCollisionBullet();

	//ゲッター
	vec2 getPosBullet() { return Bullet_->getPos(); };
	int getPosBulletY() { return Bullet_->getPosY(); };
	int getRadiusBullet() { return Bullet_->getRadius(); };
	vec2 getPos() { return Pos_; };
	int getRadius() { return Radius_; };

private:
	bullet* Bullet_;
};

