#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "resource.h"

// #pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")
#pragma comment(lib,"msimg32.lib")
#define MAP_COL 8
#define MAP_ROW  8


class CChessGame
{
	char field[MAP_COL][MAP_ROW];
	CPlayer p1;
	HBITMAP rc[2]; // 맵이랑 플레이어
public:
	CChessGame() {
		std::ifstream mapData("map.txt");
		for (int row = 0; row < MAP_ROW; ++row) { // row
			for (int col = 0; col < MAP_COL; ++col) { // col
				mapData >> field[row][col];
			}
			
		}
	};
	void InitStage(HINSTANCE&);
	void DrawScreen(HDC);
	void DrawBitmap(HDC, HBITMAP, int, int);
	void DrawTransParentBitmap(HDC, HBITMAP, int, int);
	void Action(int);
	void Swap(int, int, int, int); // 배열값 교환
	void SaveGame();
	~CChessGame() { };
};

