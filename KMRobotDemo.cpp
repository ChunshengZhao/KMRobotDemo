/*
*
* KMRobotDemo.cpp
* Build by Microsoft Visual Studio 2010
* ZhaoChunsheng 2016/08/26
* Needs Moxa PComm Lite - Serial Comm Development Tool
* http://www.moxa.com/product/download_pcommlite_info.htm
*
*/

// KMRobotDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "KMRobot.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Sleep(2000); //延迟2秒
	KMRobot m_kmrobot(6); //串口号6
	m_kmrobot.Open(); //打开串口

	POINT point;
	GetCursorPos(&point);
	HWND hwnd=WindowFromPoint(point); //得到鼠标当前客户区句柄

	//
	m_kmrobot.KeyboardWrite(131,1); //打开开始菜单（徽标键KEY_LEFT_GUI，十进制131）
	//m_kmrobot.KeyboardWrite(65,10); //十个 A
	//m_kmrobot.KeyboardPrint("KMRobot"); //输出 KMRobot
	//m_kmrobot.KeyboardPrint("KMRobot without space"); //输出 KMRobot，因为参数以空格和逗号作为分隔符
	//m_kmrobot.KeyboardPrintln("KMRobot"); // 输出 KMRobot，但 arduino 会接收到回车符

	//m_kmrobot.KeyboardPress(129); //按住 LEFT_SHIFT
	//m_kmrobot.KeyboardPress(97); //按住a
	//m_kmrobot.KeyboardRelease(97); //释放a
	//m_kmrobot.KeyboardReleaseAll(); //释放全部按键, 得到A，受到延迟影响，可能会出现AA，可更改 responseDelay

	//m_kmrobot.MouseMove(-127,-127,0); //左上移动，范围(-127~+127)
	//m_kmrobot.MouseMove(0,0,1);//向上滚动，向下为 -1, 范围(-127~+127)
	//m_kmrobot.MouseSetScreenPos(800,600); //移动屏幕鼠标至：800，600，屏幕坐标移动误差 error<3
	//m_kmrobot.MouseSetScreenPosEx(800,600); //移动屏幕鼠标至：800，600，屏幕坐标移动误差 error 0
	//m_kmrobot.MouseSetClientPos(60,60,int(hwnd)); //移动客户区鼠标至：60，60，客户区移动误差error<3
	//m_kmrobot.MouseSetClientPosEx(60,60,int(hwnd)); //移动客户区鼠标至：60，60，客户区移动误差error 0
	//m_kmrobot.MouseClick("MOUSE_LEFT",2); //左键单击两次（双击）
	//m_kmrobot.MouseClick("MOUSE_RIGHT",1); //右键单击
	//m_kmrobot.MouseClick("MOUSE_MIDDLE",1); //中键单击

	//m_kmrobot.MousePress("MOUSE_RIGHT"); //按住鼠标右键
	//m_kmrobot.MouseMove(-127,-127,0); //左上移动，范围(-127~+127)
	//m_kmrobot.MouseRelease("MOUSE_RIGHT"); //松开鼠标右键
	//

	m_kmrobot.Close();//关闭串口

	//system("pause");
	return 0;
}

