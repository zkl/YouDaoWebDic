#include <windows.h>
#include <QApplication>
#include <QAbstractEventDispatcher>
#include "dicwin.h"

dicwin * g_dic;
bool event_fliter(void * msg);

int main(int argc, char *argv[])
{	
	ATOM at = GlobalAddAtom(TEXT("YouDao Web Dictionary"));
	if(!RegisterHotKey(NULL, at, 0, VK_F2))
		MessageBoxA(0, "Hot Key Regist Failed.", "ERROR", 0);

	QApplication a(argc, argv);
	
	g_dic = new dicwin();

	QAbstractEventDispatcher::instance()->setEventFilter(event_fliter);
	
	if(argc > 1)
		g_dic->search(QString::fromLocal8Bit(argv[1]));

	a.exec();

	UnregisterHotKey(NULL, at);
	GlobalDeleteAtom(at);

	delete g_dic;
	return 0;
}

bool event_fliter(void * parm)
{
	MSG * msg = (MSG *)parm;
	if(msg->message == WM_HOTKEY)
	{
		g_dic->show();
		SetForegroundWindow((HWND)(g_dic->winId()));
		return true;
	}
	return false;
}
