#pragma once
#include<character.h>
class player :public character
{
public:
	player();
	~player();

	void Initialize(vec2 Pos, vec2 Speed, int Radius, int Color, int HP);
	/// <summary>
	/// �ړ�
	/// </summary>
	/// <param name="keys"></param>
	void Move(char keys[256]);
	/// <summary>
	/// �ʑł�
	/// </summary>
	/// <param name="keys"></param>
	void BulletShot(char keys[256], char preKeys[256]);
	/// <summary>
	/// ���@�{��
	/// </summary>
	void DrawPlayer();
	/// <summary>
	/// �����������̏���
	/// </summary>
	void OnCollision();

	void OnCollisionBullet();

	//�Q�b�^�[
	vec2 getPosBullet() { return Bullet_->getPos(); };
	int getPosBulletY() { return Bullet_->getPosY(); };
	int getRadiusBullet() { return Bullet_->getRadius(); };
	vec2 getPos() { return Pos_; };
	int getRadius() { return Radius_; };

private:
	bullet* Bullet_;
};

