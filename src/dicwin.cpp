#include <QPainter>
#include <QKeyEvent>
#include <QBitmap>
#include <QPixmap>
#include <QBitArray>
#include <QDomDocument>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QDomComment>
#include <QNetworkReply>
#include <QMovie>
#include "dicwin.h"

dicwin::dicwin(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);   //设置窗体无边框
	setAttribute(Qt::WA_TranslucentBackground);//设置背景透明

	pic.load(":/image/bg.png");//加载图像

	this->resize(pic.size());
	connect(lineEdit, SIGNAL(returnPressed ()), this, SLOT(finished()));

	movie = new QMovie(this);
	movie->setFileName(":/image/ld.gif");
	label->setMovie(movie);
	label->hide();

	lineEdit->setStyleSheet("background-color: rgba(0, 0, 0, 0);border: 0px none; color: rgb(255, 252, 213);");
	textEdit->setStyleSheet("background-color: rgba(0, 0, 0, 0);border: 0px none; color: rgb(188, 188, 188);");

	qnam = new QNetworkAccessManager(this); //新建QNetworkAccessManager对象 
	connect(qnam,SIGNAL(finished(QNetworkReply*)), this,SLOT(replyFinished(QNetworkReply*)));

	hide_key = new QShortcut(this);
	hide_key->setKey(Qt::Key_Escape);
	connect(hide_key, SIGNAL(activated ()), this, SLOT(event_to_hide()));
}

dicwin::~dicwin()
{

}

void dicwin::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, pic);
}

void dicwin::finished()
{
	search(lineEdit->text());
}

void dicwin::search(QString & text)
{
	if(text.size() <= 0)
		return ;

	/*   效果  */
	textEdit->setText("");
	lineEdit->setText(text);
	label->show();
	movie->start();
	/***************/

	QString res = "http://fanyi.youdao.com/openapi.do?keyfrom=jsjrzx&key=1150801073&type=data&doctype=xml&version=1.1&q=%1";
	QUrl url(res.arg(text));
	QNetworkReply * reply = qnam->get(QNetworkRequest(url));
	connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
}

void dicwin::event_to_hide()
{
	this->hide();
	lineEdit->selectAll();
}

void dicwin::httpReadyRead()
{
	movie->stop();
	label->hide();

	QNetworkReply * reply = static_cast <QNetworkReply *> (sender());
	QByteArray fields =  reply->readAll();

	QDomDocument doc;
	QDomElement root;
	doc.setContent(fields);
	root = doc.documentElement();
	textEdit->setText(root.tagName());

	int errorCode = root.firstChildElement("errorCode").text().toInt();
	
	if(errorCode == 0)
	{
		QString text;
		text += QString::fromLocal8Bit("<strong>音标: </strong>");
		text += root.firstChildElement("basic").firstChildElement("phonetic").text();
		
		text += QString::fromLocal8Bit("<br><strong>解释: </strong><ul>");
		QDomElement explanRoot = root.firstChildElement("basic").firstChildElement("explains");
		QDomNodeList explans = explanRoot.elementsByTagName("ex");
		for(int i=0; i<explans.size(); i++)
		{
			text += "<li>";
			text += explans.item(i).toElement().text();
			text += "</li>";
		}

		text += "</ul>";

		text += QString::fromLocal8Bit("<hr><strong>网络解释: </strong>");

		QDomElement webRoot = root.firstChildElement("web");
		QDomNodeList webExp = webRoot.elementsByTagName("explain");

		for(int i=0; i<webExp.size(); i++)
		{
			QDomElement eml = webExp.item(i).toElement();

			text += "<li>";
			text += "<strong>" + eml.firstChildElement("key").text() + "</strong><ul>";
			QDomNodeList values = eml.firstChildElement("value").elementsByTagName("ex"); 
			for(int j=0; j<values.size(); j++)
			{
				text += "<li>" + values.item(j).toElement().text() + "</li>";
			}
			text += "</ul></li>";
		}

		text += "</ul>";

		textEdit->setText(text);
	}
	else
	{
		textEdit->setText(QString::fromLocal8Bit("翻译失败"));
	}
}

void dicwin::replyFinished(QNetworkReply *reply)
{
	reply->deleteLater();

	movie->stop();
	label->hide();
}

void dicwin::mousePressEvent(QMouseEvent *event)    
{    
	//按住左键可以托动窗口，按下右键关闭程序    
	if(event->button() == Qt::LeftButton)    
	{    
		curPos = event->globalPos() - frameGeometry().topLeft();    
		event->accept();    
	}
}    

void dicwin::mouseMoveEvent(QMouseEvent *event)    
{    
	if (event->buttons() && Qt::LeftButton)    
	{    
		move(event->globalPos() - curPos);    
		event->accept();    
	}    
} 