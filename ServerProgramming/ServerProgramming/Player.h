#pragma once

struct POS {
	int x;
	int y;
};


class CPlayer
{
	POS pos;
public:
	CPlayer() :pos{ 0, 0 } {};
	CPlayer(int x, int y) : pos{ x,y } {};
	void move(int);
	void SetPos(int x, int y) { pos.x = x; pos.y = y; };
	POS GetPos() { return pos; };
	~CPlayer() {};
};

