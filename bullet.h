#pragma once
#include<option.h>
class bullet
{
public:
	bullet();
	~bullet();

	void Initialize(int Speed, int Radius, int Color);
	/// <summary>
	/// �ʍX�V
	/// �t���O�I���œ���
	/// </summary>
	void BulletUpdate();
	/// <summary>
	/// �ʕ`��
	/// �t���O�I���̎��`��
	/// </summary>
	void DrawBullet();
	/// <summary>
	/// �ړ�����
	/// </summary>
	void posLimit();
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="Pos">���W</param>
	/// <param name="Speed">�X�s�[�h</param>
	/// <param name="Radius">���a</param>
	/// <param name="Color">�F</param>
	void setStatus(vec2 Pos, int Speed, int Radius, int Color);

	void OnCollision();

	vec2 getPos() { return Pos_; };
	int getPosY() { return Pos_.y; };
	int getRadius() { return Radius_; };
	int getFlag() { return Flag_; };

private:
	vec2 Pos_;
	int Speed_;
	int Radius_;
	int Color_;
	int Flag_ = false;
};

