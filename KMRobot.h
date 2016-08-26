/*
 *
 * KMRobot.h
 * Build by Microsoft Visual Studio 2010
 * ZhaoChunsheng 2016/08/26
 * Needs Moxa PComm Lite - Serial Comm Development Tool
 * http://www.moxa.com/product/download_pcommlite_info.htm
 *
 */

#ifndef _KMROBOT_H_  
#define _KMROBOT_H_  

class KMRobot
{
private:
	int port;
	int responseDelay;
	char str_mouseSpeed[16];
public:

    KMRobot(int port);
    int Open();
	void Close();

	void KeyboardWrite(int key, int times);
	void KeyboardPrint(char str[512]);
	void KeyboardPrintln(char str[512]);
	void KeyboardPress(int key);
	void KeyboardRelease(int key);
	void KeyboardReleaseAll();
	
	void MousePress(char button[8]);
	void MouseRelease(char button[8]);
	void MouseMove(int x,int y, int wheel);
	void MouseSetScreenPos(int x,int y);
	void MouseSetClientPos(int x,int y,int hwnd);
	void MouseSetScreenPosEx(int x,int y);
	void MouseSetClientPosEx(int x,int y,int hwnd);
	void MouseClick(char button[8],int times);
};


#endif