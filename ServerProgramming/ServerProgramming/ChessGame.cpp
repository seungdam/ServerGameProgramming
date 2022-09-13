#include "ChessGame.h"

void CChessGame::InitStage(HINSTANCE& hInst) { // 혹시 나중에 세이브 할 수 도 있으니 파일입출력을 통해 저장하는 기능을 제작.
	// 플레이어 초기 위치를 산출.
	for (int i = 0; i < 2; ++i) rc[i] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1 + i));
	
	for (int row = 0; row < MAP_ROW; ++row) { // row
		for (int col = 0; col < MAP_COL; ++col) { // col
			if (field[row][col] == '@') p1.SetPos(col, row);
		}
	}
}

void CChessGame::Action(int key)
{
	POS temp;
	switch (key) {
	case VK_UP:
	case VK_DOWN:
	case VK_LEFT:
	case VK_RIGHT:
		temp = p1.GetPos();
		p1.move(key);
		Swap(temp.x, temp.y, p1.GetPos().x, p1.GetPos().y);
		break;
	}
	// std::cout << "(" << p1.GetPos().x << p1.GetPos().y << ")" << std::endl;
}

void CChessGame::Swap(int x1, int y1, int x2, int y2)
{
	char temp = field[y1][x1];
	field[y1][x1] = field[y2][x2];
	field[y2][x2] = temp;
}

void CChessGame::SaveGame()
{
	std::ofstream sMapData("map.txt");
	for (int row = 0; row < MAP_ROW; ++row) { // row
		for (int col = 0; col < MAP_COL; ++col) { // col
			sMapData << field[row][col];
		}
		sMapData << '\n';
	}
}

void CChessGame::DrawBitmap(HDC hdc, HBITMAP hBit, int x, int y)
{
	HDC memDC = CreateCompatibleDC(hdc);
	BITMAP bit;
	HBITMAP oldBit = (HBITMAP)SelectObject(memDC, hBit);
	GetObject(hBit, sizeof(BITMAP), &bit);
	BitBlt(hdc, x, y, bit.bmWidth, bit.bmHeight, memDC, 0, 0, SRCCOPY);
	//TransparentBlt(hdc, x, y, bit.bmWidth, bit.bmHeight, memDC, 0, 0, bit.bmWidth, bit.bmHeight, RGB(255, 255, 255));
	SelectObject(memDC, oldBit);
	DeleteDC(memDC);
}

void CChessGame::DrawTransParentBitmap(HDC hdc, HBITMAP hBit, int x, int y)
{
	HDC memDC = CreateCompatibleDC(hdc);
	BITMAP bit;
	HBITMAP oldBit = (HBITMAP)SelectObject(memDC, hBit);
	GetObject(hBit, sizeof(BITMAP), &bit);
	//BitBlt(hdc, x, y, bit.bmWidth, bit.bmHeight, memDC, 0, 0, SRCCOPY);
	TransparentBlt(hdc, x, y, bit.bmWidth, bit.bmHeight, memDC, 0, 0, bit.bmWidth, bit.bmHeight, RGB(255, 255, 255));
	SelectObject(memDC, oldBit);
	DeleteDC(memDC);
}

void CChessGame::DrawScreen(HDC hdc)
{
	DrawBitmap(hdc, rc[1], 0, 0);
	DrawTransParentBitmap(hdc, rc[0], p1.GetPos().x * 75, p1.GetPos().y * 75);
}
