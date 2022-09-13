#include "Player.h"


void CPlayer::move(int key)
{
	switch (key) {
	case 0x26: // up
		if (pos.y >= 1) pos.y -= 1;
		break;
	case 0x28: // down
		if (pos.y < 7) pos.y += 1;
		break;
	case 0x25: // left
		if (pos.x >= 1) pos.x -= 1;
		break;
	case 0x27: // right
		if (pos.x < 7) pos.x += 1;
		break;
	}

}
