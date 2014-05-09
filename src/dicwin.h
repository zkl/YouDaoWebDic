#ifndef DICWIN_H
#define DICWIN_H

#include <QtGui/QMainWindow>
#include <QNetworkAccessManager>
#include <QMovie>
#include <QShortcut>
#include "ui_dicwin.h"

class dicwin : public QMainWindow, public Ui_dicwinClass
{
	Q_OBJECT

public:
	dicwin(QWidget *parent = 0, Qt::WFlags flags = 0);
	~dicwin();

	void search(QString & text);

private slots:
	void event_to_hide();
	void finished();
	void replyFinished(QNetworkReply*);
	void httpReadyRead();

private:
	void paintEvent(QPaintEvent *);

	void mousePressEvent(QMouseEvent *event);    
	void mouseMoveEvent(QMouseEvent *event); 
	

private:
	QPixmap pic;
	QPoint curPos; 
	QMovie * movie;
	QShortcut * hide_key;
	QNetworkAccessManager * qnam;
};

#endif // DICWIN_H
