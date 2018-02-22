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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gird2;
    QGridLayout *grid;
    QTabWidget *tabWidgets;
    QWidget *tbSysInfo;
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
    QWidget *tbProcess;
    QGridLayout *gridLayout;
    QTableWidget *tbwProInfo;
    QWidget *tbService;
    QRadioButton *rbutton;
    QLineEdit *lnEdQuery;
    QPushButton *btQuery;
    QTextBrowser *tbrDetails;
    QLineEdit *lnEdNewPro;
    QPushButton *btNewPro;
    QWidget *tbRecord;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbCpuHis;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbCpu100;
    QLabel *lbCpu75;
    QLabel *lbCpu50;
    QLabel *lbCpu25;
    QLabel *lbCpu0;
    QLabel *lbCpuHisLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbMemHis;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbMem100;
    QLabel *lbMem75;
    QLabel *lbMem50;
    QLabel *lbMem25;
    QLabel *lbMem0;
    QLabel *lbMemHisLine;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(954, 600);
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
        tabWidgets = new QTabWidget(centralWidget);
        tabWidgets->setObjectName(QStringLiteral("tabWidgets"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidgets->sizePolicy().hasHeightForWidth());
        tabWidgets->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Noto Serif CJK SC"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tabWidgets->setFont(font);
        tabWidgets->setElideMode(Qt::ElideNone);
        tbSysInfo = new QWidget();
        tbSysInfo->setObjectName(QStringLiteral("tbSysInfo"));
        _lbDevName = new QLabel(tbSysInfo);
        _lbDevName->setObjectName(QStringLiteral("_lbDevName"));
        _lbDevName->setGeometry(QRect(90, 40, 81, 31));
        _lbStartTime = new QLabel(tbSysInfo);
        _lbStartTime->setObjectName(QStringLiteral("_lbStartTime"));
        _lbStartTime->setGeometry(QRect(90, 80, 81, 31));
        _lbRunTime = new QLabel(tbSysInfo);
        _lbRunTime->setObjectName(QStringLiteral("_lbRunTime"));
        _lbRunTime->setGeometry(QRect(90, 120, 81, 31));
        _lbSysVersion = new QLabel(tbSysInfo);
        _lbSysVersion->setObjectName(QStringLiteral("_lbSysVersion"));
        _lbSysVersion->setGeometry(QRect(90, 160, 81, 31));
        _lbCpuInfo = new QLabel(tbSysInfo);
        _lbCpuInfo->setObjectName(QStringLiteral("_lbCpuInfo"));
        _lbCpuInfo->setGeometry(QRect(90, 210, 81, 31));
        tbrCpuInfo = new QTextBrowser(tbSysInfo);
        tbrCpuInfo->setObjectName(QStringLiteral("tbrCpuInfo"));
        tbrCpuInfo->setGeometry(QRect(235, 211, 571, 261));
        lbDevName = new QLabel(tbSysInfo);
        lbDevName->setObjectName(QStringLiteral("lbDevName"));
        lbDevName->setGeometry(QRect(240, 40, 391, 31));
        lbStartTime = new QLabel(tbSysInfo);
        lbStartTime->setObjectName(QStringLiteral("lbStartTime"));
        lbStartTime->setGeometry(QRect(240, 80, 391, 31));
        lbRunTime = new QLabel(tbSysInfo);
        lbRunTime->setObjectName(QStringLiteral("lbRunTime"));
        lbRunTime->setGeometry(QRect(240, 120, 391, 31));
        lbSysVersion = new QLabel(tbSysInfo);
        lbSysVersion->setObjectName(QStringLiteral("lbSysVersion"));
        lbSysVersion->setGeometry(QRect(240, 160, 391, 31));
        tabWidgets->addTab(tbSysInfo, QString());
        tbProcess = new QWidget();
        tbProcess->setObjectName(QStringLiteral("tbProcess"));
        gridLayout = new QGridLayout(tbProcess);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tbwProInfo = new QTableWidget(tbProcess);
        if (tbwProInfo->columnCount() < 5)
            tbwProInfo->setColumnCount(5);
        tbwProInfo->setObjectName(QStringLiteral("tbwProInfo"));
        tbwProInfo->setLineWidth(1);
        tbwProInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbwProInfo->setSelectionMode(QAbstractItemView::SingleSelection);
        tbwProInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbwProInfo->setShowGrid(true);
        tbwProInfo->setRowCount(0);
        tbwProInfo->setColumnCount(5);
        tbwProInfo->horizontalHeader()->setCascadingSectionResizes(false);
        tbwProInfo->horizontalHeader()->setDefaultSectionSize(150);
        tbwProInfo->horizontalHeader()->setHighlightSections(false);
        tbwProInfo->horizontalHeader()->setMinimumSectionSize(100);
        tbwProInfo->horizontalHeader()->setStretchLastSection(true);
        tbwProInfo->verticalHeader()->setDefaultSectionSize(35);
        tbwProInfo->verticalHeader()->setMinimumSectionSize(35);
        tbwProInfo->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tbwProInfo->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tbwProInfo, 0, 0, 1, 1);

        tabWidgets->addTab(tbProcess, QString());
        tbService = new QWidget();
        tbService->setObjectName(QStringLiteral("tbService"));
        rbutton = new QRadioButton(tbService);
        rbutton->setObjectName(QStringLiteral("rbutton"));
        rbutton->setGeometry(QRect(90, 90, 111, 31));
        lnEdQuery = new QLineEdit(tbService);
        lnEdQuery->setObjectName(QStringLiteral("lnEdQuery"));
        lnEdQuery->setGeometry(QRect(200, 90, 441, 31));
        btQuery = new QPushButton(tbService);
        btQuery->setObjectName(QStringLiteral("btQuery"));
        btQuery->setGeometry(QRect(660, 90, 111, 31));
        tbrDetails = new QTextBrowser(tbService);
        tbrDetails->setObjectName(QStringLiteral("tbrDetails"));
        tbrDetails->setGeometry(QRect(200, 200, 591, 241));
        lnEdNewPro = new QLineEdit(tbService);
        lnEdNewPro->setObjectName(QStringLiteral("lnEdNewPro"));
        lnEdNewPro->setGeometry(QRect(200, 140, 441, 31));
        btNewPro = new QPushButton(tbService);
        btNewPro->setObjectName(QStringLiteral("btNewPro"));
        btNewPro->setGeometry(QRect(660, 140, 111, 31));
        tabWidgets->addTab(tbService, QString());
        tbRecord = new QWidget();
        tbRecord->setObjectName(QStringLiteral("tbRecord"));
        gridLayout_3 = new QGridLayout(tbRecord);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbCpuHis = new QLabel(tbRecord);
        lbCpuHis->setObjectName(QStringLiteral("lbCpuHis"));
        lbCpuHis->setMaximumSize(QSize(16777215, 35));
        lbCpuHis->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbCpuHis);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lbCpu100 = new QLabel(tbRecord);
        lbCpu100->setObjectName(QStringLiteral("lbCpu100"));
        lbCpu100->setMinimumSize(QSize(60, 30));
        lbCpu100->setMaximumSize(QSize(60, 30));

        verticalLayout_2->addWidget(lbCpu100);

        lbCpu75 = new QLabel(tbRecord);
        lbCpu75->setObjectName(QStringLiteral("lbCpu75"));
        lbCpu75->setMinimumSize(QSize(60, 30));
        lbCpu75->setMaximumSize(QSize(60, 30));

        verticalLayout_2->addWidget(lbCpu75);

        lbCpu50 = new QLabel(tbRecord);
        lbCpu50->setObjectName(QStringLiteral("lbCpu50"));
        lbCpu50->setMinimumSize(QSize(60, 30));
        lbCpu50->setMaximumSize(QSize(60, 30));

        verticalLayout_2->addWidget(lbCpu50);

        lbCpu25 = new QLabel(tbRecord);
        lbCpu25->setObjectName(QStringLiteral("lbCpu25"));
        lbCpu25->setMinimumSize(QSize(60, 30));
        lbCpu25->setMaximumSize(QSize(60, 30));

        verticalLayout_2->addWidget(lbCpu25);

        lbCpu0 = new QLabel(tbRecord);
        lbCpu0->setObjectName(QStringLiteral("lbCpu0"));
        lbCpu0->setMinimumSize(QSize(60, 30));
        lbCpu0->setMaximumSize(QSize(60, 30));

        verticalLayout_2->addWidget(lbCpu0);


        horizontalLayout_4->addLayout(verticalLayout_2);

        lbCpuHisLine = new QLabel(tbRecord);
        lbCpuHisLine->setObjectName(QStringLiteral("lbCpuHisLine"));
        lbCpuHisLine->setMinimumSize(QSize(842, 200));
        lbCpuHisLine->setMaximumSize(QSize(842, 200));

        horizontalLayout_4->addWidget(lbCpuHisLine);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbMemHis = new QLabel(tbRecord);
        lbMemHis->setObjectName(QStringLiteral("lbMemHis"));
        lbMemHis->setMaximumSize(QSize(16777215, 35));
        lbMemHis->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lbMemHis);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lbMem100 = new QLabel(tbRecord);
        lbMem100->setObjectName(QStringLiteral("lbMem100"));
        lbMem100->setMinimumSize(QSize(60, 30));
        lbMem100->setMaximumSize(QSize(60, 30));

        verticalLayout_3->addWidget(lbMem100);

        lbMem75 = new QLabel(tbRecord);
        lbMem75->setObjectName(QStringLiteral("lbMem75"));
        lbMem75->setMinimumSize(QSize(60, 30));
        lbMem75->setMaximumSize(QSize(60, 30));

        verticalLayout_3->addWidget(lbMem75);

        lbMem50 = new QLabel(tbRecord);
        lbMem50->setObjectName(QStringLiteral("lbMem50"));
        lbMem50->setMinimumSize(QSize(60, 30));
        lbMem50->setMaximumSize(QSize(60, 30));

        verticalLayout_3->addWidget(lbMem50);

        lbMem25 = new QLabel(tbRecord);
        lbMem25->setObjectName(QStringLiteral("lbMem25"));
        lbMem25->setMinimumSize(QSize(60, 30));
        lbMem25->setMaximumSize(QSize(60, 30));

        verticalLayout_3->addWidget(lbMem25);

        lbMem0 = new QLabel(tbRecord);
        lbMem0->setObjectName(QStringLiteral("lbMem0"));
        lbMem0->setMinimumSize(QSize(60, 30));
        lbMem0->setMaximumSize(QSize(60, 30));

        verticalLayout_3->addWidget(lbMem0);


        horizontalLayout_5->addLayout(verticalLayout_3);

        lbMemHisLine = new QLabel(tbRecord);
        lbMemHisLine->setObjectName(QStringLiteral("lbMemHisLine"));
        lbMemHisLine->setMinimumSize(QSize(842, 200));
        lbMemHisLine->setMaximumSize(QSize(842, 200));

        horizontalLayout_5->addWidget(lbMemHisLine);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidgets->addTab(tbRecord, QString());

        grid->addWidget(tabWidgets, 0, 0, 1, 1);


        gird2->addLayout(grid, 0, 0, 1, 1);

        mainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font1;
        font1.setPointSize(14);
        statusBar->setFont(font1);
        mainWindow->setStatusBar(statusBar);

        retranslateUi(mainWindow);

        tabWidgets->setCurrentIndex(0);


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
        tabWidgets->setTabText(tabWidgets->indexOf(tbSysInfo), QApplication::translate("mainWindow", "\347\263\273\347\273\237\344\277\241\346\201\257", nullptr));
        tabWidgets->setTabText(tabWidgets->indexOf(tbProcess), QApplication::translate("mainWindow", "\350\277\233\347\250\213", nullptr));
#ifndef QT_NO_TOOLTIP
        rbutton->setToolTip(QApplication::translate("mainWindow", "\351\200\211\344\270\255\351\200\232\350\277\207\350\277\233\347\250\213\345\220\215\347\247\260\346\237\245\350\257\242", nullptr));
#endif // QT_NO_TOOLTIP
        rbutton->setText(QApplication::translate("mainWindow", "\350\277\233\347\250\213pid\345\217\267", nullptr));
        btQuery->setText(QApplication::translate("mainWindow", "\346\237\245\350\257\242", nullptr));
        btNewPro->setText(QApplication::translate("mainWindow", "\345\273\272\347\253\213\346\226\260\350\277\233\347\250\213", nullptr));
        tabWidgets->setTabText(tabWidgets->indexOf(tbService), QApplication::translate("mainWindow", "\346\234\215\345\212\241", nullptr));
        lbCpuHis->setText(QApplication::translate("mainWindow", "CPU\344\275\277\347\224\250\345\216\206\345\217\262\346\233\262\347\272\277", nullptr));
        lbCpu100->setText(QApplication::translate("mainWindow", "100%", nullptr));
        lbCpu75->setText(QApplication::translate("mainWindow", "75%", nullptr));
        lbCpu50->setText(QApplication::translate("mainWindow", "50%", nullptr));
        lbCpu25->setText(QApplication::translate("mainWindow", "25%", nullptr));
        lbCpu0->setText(QApplication::translate("mainWindow", "0%", nullptr));
        lbCpuHisLine->setText(QString());
        lbMemHis->setText(QApplication::translate("mainWindow", "\345\206\205\345\255\230\344\275\277\347\224\250\345\216\206\345\217\262\346\233\262\347\272\277", nullptr));
        lbMem100->setText(QApplication::translate("mainWindow", "100%", nullptr));
        lbMem75->setText(QApplication::translate("mainWindow", "75%", nullptr));
        lbMem50->setText(QApplication::translate("mainWindow", "50%", nullptr));
        lbMem25->setText(QApplication::translate("mainWindow", "25%", nullptr));
        lbMem0->setText(QApplication::translate("mainWindow", "0%", nullptr));
        lbMemHisLine->setText(QString());
        tabWidgets->setTabText(tabWidgets->indexOf(tbRecord), QApplication::translate("mainWindow", "\346\200\247\350\203\275", nullptr));
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
