/********************************************************************************
** Form generated from reading UI file 'dicwin.ui'
**
** Created: Fri May 9 08:55:00 2014
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICWIN_H
#define UI_DICWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dicwinClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QMainWindow *dicwinClass)
    {
        if (dicwinClass->objectName().isEmpty())
            dicwinClass->setObjectName(QString::fromUtf8("dicwinClass"));
        dicwinClass->resize(450, 342);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        dicwinClass->setFont(font);
        centralWidget = new QWidget(dicwinClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 25, 151, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        lineEdit->setMouseTracking(true);
        lineEdit->setFocusPolicy(Qt::WheelFocus);
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 252, 213);"));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 70, 391, 221));
        QFont font2;
        font2.setPointSize(10);
        textEdit->setFont(font2);
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 110, 311, 111));
        label->setStyleSheet(QString::fromUtf8("background-color:argb(255, 0, 0, 0);\n"
"border-color: argb(255, 0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        dicwinClass->setCentralWidget(centralWidget);
        textEdit->raise();
        label->raise();
        lineEdit->raise();

        retranslateUi(dicwinClass);

        QMetaObject::connectSlotsByName(dicwinClass);
    } // setupUi

    void retranslateUi(QMainWindow *dicwinClass)
    {
        dicwinClass->setWindowTitle(QApplication::translate("dicwinClass", "dicwin", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        textEdit->setHtml(QApplication::translate("dicwinClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-style:italic;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dicwinClass: public Ui_dicwinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICWIN_H
