#include <QApplication>
#include <QAbstractEventDispatcher>
#include "dicwin.h"

#ifdef WINDOWS
#include <windows.h>
bool event_fliter(void * msg);
#endif 

dicwin * g_dic;

int main(int argc, char *argv[])
{	

	QApplication a(argc, argv);

	g_dic = new dicwin();

#ifdef WINDOWS
	ATOM at = GlobalAddAtom(TEXT("YouDao Web Dictionary"));
	if(!RegisterHotKey(NULL, at, 0, VK_F2))
		MessageBoxA(0, "Hot Key Regist Failed.", "ERROR", 0);

	QAbstractEventDispatcher::instance()->setEventFilter(event_fliter);
#endif


	
	if(argc > 1)
		g_dic->search(QString::fromLocal8Bit(argv[1]));


	g_dic->show();

	a.exec();

#ifdef WINDOWS
	UnregisterHotKey(NULL, at);
	GlobalDeleteAtom(at);
#endif

	delete g_dic;
	return 0;
}

#ifdef WINDOWS
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
#endif
