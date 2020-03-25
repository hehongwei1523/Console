#pragma once
#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "time.h"

#include <windows.h>
#include <string.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS 

#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")

#define BG_X 20
#define BG_Y 12
unsigned char background[20][15] =
{
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

};
unsigned char background_default[20][15] =
{
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
/*
unsigned char sharpe[][4] =
{
	{0,0,0,0},
	{1,1,1,0},
	{0,0,1,0},
	{0,0,1,0}
};
*/


const unsigned char figure[][4][4] =
{
	{
		{0,0,0,0},
		{1,1,1,0},
		{1,0,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,1,0,0}
	},
	{
		{0,0,0,0},
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	//--------------------
	{
		{0,0,0,0},
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0}
	},
	{
		{0,1,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{1,0,0,0}
	},
	//--------------------
	{
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0}
	},
	//--------------------
	{
		{0,0,0,0},
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	//--------------------
	{
		{0,0,0,0},
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{1,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,0},
		{0,1,0,0}
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,1,0,0}
	},
	//--------------------
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	},
	{
		{0,1,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{0,0,0,0}
	},
	//--------------------
	{
		{0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},

};