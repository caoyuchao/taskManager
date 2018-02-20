/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gird2;
    QGridLayout *grid;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *_lbDevName;
    QLabel *_lbStartTime;
    QLabel *_lbRunTime;
    QLabel *_lbSysVersion;
    QLabel *_lbCpuInfo;
    QTextBrowser *tbrCpuInfo;
    QLabel *lbDevName;
    QLabel *lbStartTime;
    QLabel *lbRunTime;
    QLabel *lbSysVersion;
    QWidget *tab_3;
    QWidget *tab_2;
    QWidget *tab_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(860, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWindow->sizePolicy().hasHeightForWidth());
        mainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(mainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gird2 = new QGridLayout(centralWidget);
        gird2->setSpacing(6);
        gird2->setContentsMargins(11, 11, 11, 11);
        gird2->setObjectName(QStringLiteral("gird2"));
        grid = new QGridLayout();
        grid->setSpacing(6);
        grid->setObjectName(QStringLiteral("grid"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Noto Serif CJK SC"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        _lbDevName = new QLabel(tab);
        _lbDevName->setObjectName(QStringLiteral("_lbDevName"));
        _lbDevName->setGeometry(QRect(40, 40, 81, 31));
        _lbStartTime = new QLabel(tab);
        _lbStartTime->setObjectName(QStringLiteral("_lbStartTime"));
        _lbStartTime->setGeometry(QRect(40, 80, 81, 31));
        _lbRunTime = new QLabel(tab);
        _lbRunTime->setObjectName(QStringLiteral("_lbRunTime"));
        _lbRunTime->setGeometry(QRect(40, 120, 81, 31));
        _lbSysVersion = new QLabel(tab);
        _lbSysVersion->setObjectName(QStringLiteral("_lbSysVersion"));
        _lbSysVersion->setGeometry(QRect(40, 160, 81, 31));
        _lbCpuInfo = new QLabel(tab);
        _lbCpuInfo->setObjectName(QStringLiteral("_lbCpuInfo"));
        _lbCpuInfo->setGeometry(QRect(40, 210, 81, 31));
        tbrCpuInfo = new QTextBrowser(tab);
        tbrCpuInfo->setObjectName(QStringLiteral("tbrCpuInfo"));
        tbrCpuInfo->setGeometry(QRect(185, 211, 571, 261));
        lbDevName = new QLabel(tab);
        lbDevName->setObjectName(QStringLiteral("lbDevName"));
        lbDevName->setGeometry(QRect(190, 40, 391, 31));
        lbStartTime = new QLabel(tab);
        lbStartTime->setObjectName(QStringLiteral("lbStartTime"));
        lbStartTime->setGeometry(QRect(190, 80, 391, 31));
        lbRunTime = new QLabel(tab);
        lbRunTime->setObjectName(QStringLiteral("lbRunTime"));
        lbRunTime->setGeometry(QRect(190, 120, 391, 31));
        lbSysVersion = new QLabel(tab);
        lbSysVersion->setObjectName(QStringLiteral("lbSysVersion"));
        lbSysVersion->setGeometry(QRect(190, 160, 391, 31));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        grid->addWidget(tabWidget, 0, 0, 1, 1);


        gird2->addLayout(grid, 0, 0, 1, 1);

        mainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font1;
        font1.setPointSize(14);
        statusBar->setFont(font1);
        mainWindow->setStatusBar(statusBar);

        retranslateUi(mainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "\346\233\271\346\260\217\344\273\273\345\212\241\347\256\241\347\220\206\345\231\250", nullptr));
        _lbDevName->setText(QApplication::translate("mainWindow", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        _lbStartTime->setText(QApplication::translate("mainWindow", "\345\220\257\345\212\250\346\227\266\351\227\264", nullptr));
        _lbRunTime->setText(QApplication::translate("mainWindow", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        _lbSysVersion->setText(QApplication::translate("mainWindow", "\347\263\273\347\273\237\347\211\210\346\234\254", nullptr));
        _lbCpuInfo->setText(QApplication::translate("mainWindow", "CPU\344\277\241\346\201\257", nullptr));
        lbDevName->setText(QString());
        lbStartTime->setText(QString());
        lbRunTime->setText(QString());
        lbSysVersion->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mainWindow", "\347\263\273\347\273\237\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("mainWindow", "\350\277\233\347\250\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("mainWindow", "\346\234\215\345\212\241", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("mainWindow", "\346\200\247\350\203\275", nullptr));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
