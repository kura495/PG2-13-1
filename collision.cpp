#include<collision.h>
collision::collision()
{
}

collision::~collision()
{
}

bool collision::CircleCollision(vec2 Pos1, int Radius1, vec2 Pos2, int Radius2)
{
	float lengthX = Pos1.x - Pos2.x;
	float lengthY = Pos1.y - Pos2.y;
	float length = sqrt(lengthX * lengthX + lengthY * lengthY);
	if (length <= Radius1 + Radius2) {
		return true;
	}
	else {
		return false;
	}
}