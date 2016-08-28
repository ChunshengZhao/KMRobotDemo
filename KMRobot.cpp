/*
*
* KMRobot.cpp
* Build by Microsoft Visual Studio 2010
* ZhaoChunsheng 2016/08/26
* Needs Moxa PComm Lite - Serial Comm Development Tool
* http://www.moxa.com/product/download_pcommlite_info.htm
*
*/

#include "stdafx.h"
#include "KMRobot.h"
#include <Windows.h>            // PComm.h needs this include file
#include "PCOMM\PComm.h"		// Moxa PComm Lite


KMRobot::KMRobot(int port)
{
	responseDelay=500;
	this->port=port;
	strcpy_s(str_mouseSpeed,"0.7645");
}

int KMRobot::Open()
{
	int ret = sio_open (port);
	if (ret == SIO_OK)
	{
		sio_ioctl (port, B9600, P_NONE | BIT_8 | STOP_1 );
		return 1;
	}
	else
	{
		return 0;
	}
}

void KMRobot::Close()
{
	sio_close (port);
}

void KMRobot::KeyboardWrite(int key, int times)
{
	char cmd[256]="Keyboard.write,";
	char str_key[8]="";
	char str_times[8]="";
	_itoa_s(key,str_key,10);
	_itoa_s(times,str_times,10);
	strcat_s(cmd,str_key);
	strcat_s(cmd,",");
	strcat_s(cmd,str_times);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::KeyboardPrint(char str[512])
{
	char cmd[512]="Keyboard.print,";
	strcat_s(cmd,str);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::KeyboardPrintln(char str[512])
{
	char cmd[512]="Keyboard.println,";
	strcat_s(cmd,str);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::KeyboardPress(int key)
{
	char cmd[256]="Keyboard.press,";
	char str_key[8]="";
	_itoa_s(key,str_key,10);
	strcat_s(cmd,str_key);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::KeyboardRelease(int key)
{
	char cmd[256]="Keyboard.release,";
	char str_key[8]="";
	_itoa_s(key,str_key,10);
	strcat_s(cmd,str_key);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::KeyboardReleaseAll()
{
	char cmd[256]="Keyboard.releaseAll";
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}


void KMRobot::MousePress(char button[8])
{
	char cmd[256]="Mouse.press,";
	strcat_s(cmd,button);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::MouseRelease(char button[8])
{
	char cmd[256]="Mouse.release,";
	strcat_s(cmd,button);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::MouseClick(char button[8],int times)
{
	char cmd[256]="Mouse.click,";
	char str_times[8]="";
	_itoa_s(times,str_times,10);
	strcat_s(cmd,button);
	strcat_s(cmd,",");
	strcat_s(cmd,str_times);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::MouseMove(int x,int y, int wheel)
{
	char cmd[256]="Mouse.move,";
	char str_x[8]="";
	char str_y[8]="";
	char str_wheel[8]="";
	_itoa_s(x,str_x,10);
	_itoa_s(y,str_y,10);
	_itoa_s(wheel,str_wheel,10);
	strcat_s(cmd,str_x);
	strcat_s(cmd,",");
	strcat_s(cmd,str_y);
	strcat_s(cmd,",");
	strcat_s(cmd,str_wheel);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay);
}

void KMRobot::MouseSetScreenPos(int x,int y)
{
	char cmd[256]="Mouse.setPos,";
	POINT pointScreen;
	char str_x[8]="";
	char str_y[8]="";
	GetCursorPos(&pointScreen);
	_itoa_s(pointScreen.x-x,str_x,10);
	_itoa_s(pointScreen.y-y,str_y,10);
	strcat_s(cmd,str_x);
	strcat_s(cmd,",");
	strcat_s(cmd,str_y);
	strcat_s(cmd,",");
	strcat_s(cmd,str_mouseSpeed);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay + abs(pointScreen.x-x) + abs(pointScreen.y-y));

}

void KMRobot::MouseSetScreenPosEx(int x,int y)
{
	POINT pointScreen;

	MouseSetScreenPos(x,y);

	do
	{
		GetCursorPos(&pointScreen);

		if(pointScreen.x<x)
		{
			MouseMove(2,0,0);
		}
		else if(pointScreen.x>x)
		{
			MouseMove(-2,0,0);
		}
		if(pointScreen.y<y)
		{
			MouseMove(0,2,0);
		}
		else if(pointScreen.y>y)
		{
			MouseMove(0,-2,0);
		}
	}
	while(pointScreen.x!=x || pointScreen.y!=y);


}

void KMRobot::MouseSetClientPos(int x,int y,int hwnd)
{
	char cmd[256]="Mouse.setPos,";
	POINT pointScreen,ptClient;
	char str_x[8]="";
	char str_y[8]="";
	ptClient.x=x;
	ptClient.y=y;
	ClientToScreen(HWND(hwnd),&ptClient);

	GetCursorPos(&pointScreen);
	_itoa_s(pointScreen.x-ptClient.x,str_x,10);
	_itoa_s(pointScreen.y-ptClient.y,str_y,10);
	strcat_s(cmd,str_x);
	strcat_s(cmd,",");
	strcat_s(cmd,str_y);
	strcat_s(cmd,",");
	strcat_s(cmd,str_mouseSpeed);
	sio_write (port, cmd, strlen(cmd));
	Sleep(responseDelay + abs(pointScreen.x-ptClient.x) + abs(pointScreen.y-ptClient.y));

}

void KMRobot::MouseSetClientPosEx(int x,int y,int hwnd)
{
	POINT pointScreen,ptClient;

	MouseSetClientPos(x,y,hwnd);
	ptClient.x=x;
	ptClient.y=y;
	ClientToScreen(HWND(hwnd),&ptClient);

	do
	{
		GetCursorPos(&pointScreen);

		if(pointScreen.x<ptClient.x)
		{
			MouseMove(2,0,0);
		}
		else if(pointScreen.x>ptClient.x)
		{
			MouseMove(-2,0,0);
		}
		if(pointScreen.y<ptClient.y)
		{
			MouseMove(0,2,0);
		}
		else if(pointScreen.y>ptClient.y)
		{
			MouseMove(0,-2,0);
		}
	}
	while(pointScreen.x!=ptClient.x || pointScreen.y!=ptClient.y);

}


