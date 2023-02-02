#pragma once
#include<bullet.h>
class character
{
public:
	character();
	~character();



protected:
	int HP_;
	vec2 Pos_;
	vec2 Speed_;
	int Radius_;
	int Color_;
	
};
