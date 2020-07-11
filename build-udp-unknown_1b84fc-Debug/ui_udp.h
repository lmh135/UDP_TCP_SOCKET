/********************************************************************************
** Form generated from reading UI file 'udp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDP_H
#define UI_UDP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_udp
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditport;
    QTextEdit *TextEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *SendBtn;
    QPushButton *exitBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *udp)
    {
        if (udp->objectName().isEmpty())
            udp->setObjectName(QStringLiteral("udp"));
        udp->resize(684, 531);
        centralWidget = new QWidget(udp);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 11, 521, 451));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditip = new QLineEdit(layoutWidget);
        lineEditip->setObjectName(QStringLiteral("lineEditip"));

        horizontalLayout->addWidget(lineEditip);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditport = new QLineEdit(layoutWidget);
        lineEditport->setObjectName(QStringLiteral("lineEditport"));

        horizontalLayout_2->addWidget(lineEditport);


        verticalLayout->addLayout(horizontalLayout_2);

        TextEdit = new QTextEdit(layoutWidget);
        TextEdit->setObjectName(QStringLiteral("TextEdit"));

        verticalLayout->addWidget(TextEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        SendBtn = new QPushButton(layoutWidget);
        SendBtn->setObjectName(QStringLiteral("SendBtn"));

        horizontalLayout_3->addWidget(SendBtn);

        exitBtn = new QPushButton(layoutWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout_3->addWidget(exitBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        udp->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(udp);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 684, 23));
        udp->setMenuBar(menuBar);
        mainToolBar = new QToolBar(udp);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        udp->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(udp);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        udp->setStatusBar(statusBar);

        retranslateUi(udp);

        QMetaObject::connectSlotsByName(udp);
    } // setupUi

    void retranslateUi(QMainWindow *udp)
    {
        udp->setWindowTitle(QApplication::translate("udp", "udp", Q_NULLPTR));
        label->setText(QApplication::translate("udp", "ip\345\234\260\345\235\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("udp", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        SendBtn->setText(QApplication::translate("udp", "\345\217\221\351\200\201", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("udp", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class udp: public Ui_udp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDP_H
