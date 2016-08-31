/********************************************************************************
** Form generated from reading UI file 'affinityform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFINITYFORM_H
#define UI_AFFINITYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AffinityForm
{
public:
    QPushButton *pushButtonStart1;
    QPushButton *pushButtonStart2;
    QPushButton *pushButtonStart3;
    QLineEdit *lineEditResultThread1;
    QLineEdit *lineEditResultThread2;
    QLineEdit *lineEditResultThread3;
    QFrame *frameCoresThread1;
    QCheckBox *checkBoxThread1Core4;
    QCheckBox *checkBoxThread1Core2;
    QCheckBox *checkBoxThread1Core3;
    QCheckBox *checkBoxThread1Core1;
    QFrame *frameCoresThread2;
    QCheckBox *checkBoxThread2Core4;
    QCheckBox *checkBoxThread2Core2;
    QCheckBox *checkBoxThread2Core3;
    QCheckBox *checkBoxThread2Core1;
    QFrame *frameCoresThread3;
    QCheckBox *checkBoxThread3Core4;
    QCheckBox *checkBoxThread3Core2;
    QCheckBox *checkBoxThread3Core3;
    QCheckBox *checkBoxThread3Core1;

    void setupUi(QWidget *AffinityForm)
    {
        if (AffinityForm->objectName().isEmpty())
            AffinityForm->setObjectName(QStringLiteral("AffinityForm"));
        AffinityForm->resize(443, 252);
        pushButtonStart1 = new QPushButton(AffinityForm);
        pushButtonStart1->setObjectName(QStringLiteral("pushButtonStart1"));
        pushButtonStart1->setGeometry(QRect(20, 40, 111, 41));
        pushButtonStart2 = new QPushButton(AffinityForm);
        pushButtonStart2->setObjectName(QStringLiteral("pushButtonStart2"));
        pushButtonStart2->setGeometry(QRect(20, 110, 111, 41));
        pushButtonStart3 = new QPushButton(AffinityForm);
        pushButtonStart3->setObjectName(QStringLiteral("pushButtonStart3"));
        pushButtonStart3->setGeometry(QRect(20, 180, 111, 41));
        lineEditResultThread1 = new QLineEdit(AffinityForm);
        lineEditResultThread1->setObjectName(QStringLiteral("lineEditResultThread1"));
        lineEditResultThread1->setGeometry(QRect(320, 40, 113, 41));
        lineEditResultThread2 = new QLineEdit(AffinityForm);
        lineEditResultThread2->setObjectName(QStringLiteral("lineEditResultThread2"));
        lineEditResultThread2->setGeometry(QRect(320, 110, 113, 41));
        lineEditResultThread3 = new QLineEdit(AffinityForm);
        lineEditResultThread3->setObjectName(QStringLiteral("lineEditResultThread3"));
        lineEditResultThread3->setGeometry(QRect(320, 180, 113, 41));
        frameCoresThread1 = new QFrame(AffinityForm);
        frameCoresThread1->setObjectName(QStringLiteral("frameCoresThread1"));
        frameCoresThread1->setGeometry(QRect(140, 40, 171, 41));
        frameCoresThread1->setFrameShape(QFrame::StyledPanel);
        frameCoresThread1->setFrameShadow(QFrame::Raised);
        checkBoxThread1Core4 = new QCheckBox(frameCoresThread1);
        checkBoxThread1Core4->setObjectName(QStringLiteral("checkBoxThread1Core4"));
        checkBoxThread1Core4->setGeometry(QRect(130, 10, 41, 22));
        checkBoxThread1Core2 = new QCheckBox(frameCoresThread1);
        checkBoxThread1Core2->setObjectName(QStringLiteral("checkBoxThread1Core2"));
        checkBoxThread1Core2->setGeometry(QRect(50, 10, 41, 22));
        checkBoxThread1Core3 = new QCheckBox(frameCoresThread1);
        checkBoxThread1Core3->setObjectName(QStringLiteral("checkBoxThread1Core3"));
        checkBoxThread1Core3->setGeometry(QRect(90, 10, 41, 22));
        checkBoxThread1Core1 = new QCheckBox(frameCoresThread1);
        checkBoxThread1Core1->setObjectName(QStringLiteral("checkBoxThread1Core1"));
        checkBoxThread1Core1->setGeometry(QRect(10, 10, 41, 22));
        frameCoresThread2 = new QFrame(AffinityForm);
        frameCoresThread2->setObjectName(QStringLiteral("frameCoresThread2"));
        frameCoresThread2->setGeometry(QRect(140, 110, 171, 41));
        frameCoresThread2->setFrameShape(QFrame::StyledPanel);
        frameCoresThread2->setFrameShadow(QFrame::Raised);
        checkBoxThread2Core4 = new QCheckBox(frameCoresThread2);
        checkBoxThread2Core4->setObjectName(QStringLiteral("checkBoxThread2Core4"));
        checkBoxThread2Core4->setGeometry(QRect(130, 10, 41, 22));
        checkBoxThread2Core2 = new QCheckBox(frameCoresThread2);
        checkBoxThread2Core2->setObjectName(QStringLiteral("checkBoxThread2Core2"));
        checkBoxThread2Core2->setGeometry(QRect(50, 10, 41, 22));
        checkBoxThread2Core3 = new QCheckBox(frameCoresThread2);
        checkBoxThread2Core3->setObjectName(QStringLiteral("checkBoxThread2Core3"));
        checkBoxThread2Core3->setGeometry(QRect(90, 10, 41, 22));
        checkBoxThread2Core1 = new QCheckBox(frameCoresThread2);
        checkBoxThread2Core1->setObjectName(QStringLiteral("checkBoxThread2Core1"));
        checkBoxThread2Core1->setGeometry(QRect(10, 10, 41, 22));
        frameCoresThread3 = new QFrame(AffinityForm);
        frameCoresThread3->setObjectName(QStringLiteral("frameCoresThread3"));
        frameCoresThread3->setGeometry(QRect(140, 180, 171, 41));
        frameCoresThread3->setFrameShape(QFrame::StyledPanel);
        frameCoresThread3->setFrameShadow(QFrame::Raised);
        checkBoxThread3Core4 = new QCheckBox(frameCoresThread3);
        checkBoxThread3Core4->setObjectName(QStringLiteral("checkBoxThread3Core4"));
        checkBoxThread3Core4->setGeometry(QRect(130, 10, 41, 22));
        checkBoxThread3Core2 = new QCheckBox(frameCoresThread3);
        checkBoxThread3Core2->setObjectName(QStringLiteral("checkBoxThread3Core2"));
        checkBoxThread3Core2->setGeometry(QRect(50, 10, 41, 22));
        checkBoxThread3Core3 = new QCheckBox(frameCoresThread3);
        checkBoxThread3Core3->setObjectName(QStringLiteral("checkBoxThread3Core3"));
        checkBoxThread3Core3->setGeometry(QRect(90, 10, 41, 22));
        checkBoxThread3Core1 = new QCheckBox(frameCoresThread3);
        checkBoxThread3Core1->setObjectName(QStringLiteral("checkBoxThread3Core1"));
        checkBoxThread3Core1->setGeometry(QRect(10, 10, 41, 22));

        retranslateUi(AffinityForm);

        QMetaObject::connectSlotsByName(AffinityForm);
    } // setupUi

    void retranslateUi(QWidget *AffinityForm)
    {
        AffinityForm->setWindowTitle(QApplication::translate("AffinityForm", "AffinityTest", 0));
        pushButtonStart1->setText(QApplication::translate("AffinityForm", "Start Thread1", 0));
        pushButtonStart2->setText(QApplication::translate("AffinityForm", "Start Thread2", 0));
        pushButtonStart3->setText(QApplication::translate("AffinityForm", "Start Thread3", 0));
        checkBoxThread1Core4->setText(QApplication::translate("AffinityForm", "4", 0));
        checkBoxThread1Core2->setText(QApplication::translate("AffinityForm", "2", 0));
        checkBoxThread1Core3->setText(QApplication::translate("AffinityForm", "3", 0));
        checkBoxThread1Core1->setText(QApplication::translate("AffinityForm", "1", 0));
        checkBoxThread2Core4->setText(QApplication::translate("AffinityForm", "4", 0));
        checkBoxThread2Core2->setText(QApplication::translate("AffinityForm", "2", 0));
        checkBoxThread2Core3->setText(QApplication::translate("AffinityForm", "3", 0));
        checkBoxThread2Core1->setText(QApplication::translate("AffinityForm", "1", 0));
        checkBoxThread3Core4->setText(QApplication::translate("AffinityForm", "4", 0));
        checkBoxThread3Core2->setText(QApplication::translate("AffinityForm", "2", 0));
        checkBoxThread3Core3->setText(QApplication::translate("AffinityForm", "3", 0));
        checkBoxThread3Core1->setText(QApplication::translate("AffinityForm", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class AffinityForm: public Ui_AffinityForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFINITYFORM_H
