/*
*
* KMRobotDemo.cpp
* Build by Microsoft Visual Studio 2010
* ZhaoChunsheng 2016/08/26
* Needs Moxa PComm Lite - Serial Comm Development Tool
* http://www.moxa.com/product/download_pcommlite_info.htm
*
*/

// KMRobotDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "KMRobot.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Sleep(2000); //�ӳ�2��
	KMRobot m_kmrobot(6); //���ں�6
	m_kmrobot.Open(); //�򿪴���

	POINT point;
	GetCursorPos(&point);
	HWND hwnd=WindowFromPoint(point); //�õ���굱ǰ�ͻ������

	//
	m_kmrobot.KeyboardWrite(131,1); //�򿪿�ʼ�˵����ձ��KEY_LEFT_GUI��ʮ����131��
	//m_kmrobot.KeyboardWrite(65,10); //ʮ�� A
	//m_kmrobot.KeyboardPrint("KMRobot"); //��� KMRobot
	//m_kmrobot.KeyboardPrint("KMRobot without space"); //��� KMRobot����Ϊ�����Կո�Ͷ�����Ϊ�ָ���
	//m_kmrobot.KeyboardPrintln("KMRobot"); // ��� KMRobot���� arduino ����յ��س���

	//m_kmrobot.KeyboardPress(129); //��ס LEFT_SHIFT
	//m_kmrobot.KeyboardPress(97); //��סa
	//m_kmrobot.KeyboardRelease(97); //�ͷ�a
	//m_kmrobot.KeyboardReleaseAll(); //�ͷ�ȫ������, �õ�A���ܵ��ӳ�Ӱ�죬���ܻ����AA���ɸ��� responseDelay

	//m_kmrobot.MouseMove(-127,-127,0); //�����ƶ�����Χ(-127~+127)
	//m_kmrobot.MouseMove(0,0,1);//���Ϲ���������Ϊ -1, ��Χ(-127~+127)
	//m_kmrobot.MouseSetScreenPos(800,600); //�ƶ���Ļ�������800��600����Ļ�����ƶ���� error<3
	//m_kmrobot.MouseSetScreenPosEx(800,600); //�ƶ���Ļ�������800��600����Ļ�����ƶ���� error 0
	//m_kmrobot.MouseSetClientPos(60,60,int(hwnd)); //�ƶ��ͻ����������60��60���ͻ����ƶ����error<3
	//m_kmrobot.MouseSetClientPosEx(60,60,int(hwnd)); //�ƶ��ͻ����������60��60���ͻ����ƶ����error 0
	//m_kmrobot.MouseClick("MOUSE_LEFT",2); //����������Σ�˫����
	//m_kmrobot.MouseClick("MOUSE_RIGHT",1); //�Ҽ�����
	//m_kmrobot.MouseClick("MOUSE_MIDDLE",1); //�м�����

	//m_kmrobot.MousePress("MOUSE_RIGHT"); //��ס����Ҽ�
	//m_kmrobot.MouseMove(-127,-127,0); //�����ƶ�����Χ(-127~+127)
	//m_kmrobot.MouseRelease("MOUSE_RIGHT"); //�ɿ�����Ҽ�
	//

	m_kmrobot.Close();//�رմ���

	//system("pause");
	return 0;
}

