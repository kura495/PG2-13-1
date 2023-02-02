#pragma once
#include<option.h>
class bullet
{
public:
	bullet();
	~bullet();

	void Initialize(int Speed, int Radius, int Color);
	/// <summary>
	/// 玉更新
	/// フラグオンで動く
	/// </summary>
	void BulletUpdate();
	/// <summary>
	/// 玉描画
	/// フラグオンの時描画
	/// </summary>
	void DrawBullet();
	/// <summary>
	/// 移動制限
	/// </summary>
	void posLimit();
	/// <summary>
	/// 情報入力
	/// </summary>
	/// <param name="Pos">座標</param>
	/// <param name="Speed">スピード</param>
	/// <param name="Radius">半径</param>
	/// <param name="Color">色</param>
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

