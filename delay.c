//#include "pch.h"


#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "tchar.h"


#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")


void DelayMs(unsigned int ms)
{
    Sleep(ms);
}


void DelayTest(void)
{
    int counter = 0;
    while (1)
    {
        printf("DelayTest:%d......\n", counter++);
        DelayMs(1000);
    }
}


void WINAPI onTimeFunc(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dwl, DWORD dw2)
{
    printf("time out\n");
    return;
}


int TimerTest(void)
{
    MMRESULT timer_id;
    int n = 0;
    timer_id = timeSetEvent(5000, 1, (LPTIMECALLBACK)onTimeFunc, (DWORD)1, TIME_PERIODIC);
    if (NULL == timer_id)
    {
        printf("timeSetEvent() failed with error %d\n", GetLastError());
        return 0;
    }
    while (n < 1000)
    {
        printf("Hello World\n");
        Sleep(2000);
        n++;
    }
    timeKillEvent(timer_id);//ÊÍ·Å¶¨Ê±Æ÷
    return 0;
}

