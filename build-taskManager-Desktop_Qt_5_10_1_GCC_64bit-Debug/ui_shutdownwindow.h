/********************************************************************************
** Form generated from reading UI file 'shutdownwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHUTDOWNWINDOW_H
#define UI_SHUTDOWNWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_shutdownWindow
{
public:
    QPushButton *btCancel;
    QPushButton *btReboot;
    QPushButton *btShutdown;
    QLabel *lbLogo;
    QLabel *lbTip;

    void setupUi(QDialog *shutdownWindow)
    {
        if (shutdownWindow->objectName().isEmpty())
            shutdownWindow->setObjectName(QStringLiteral("shutdownWindow"));
        shutdownWindow->resize(539, 174);
        shutdownWindow->setMinimumSize(QSize(539, 174));
        shutdownWindow->setMaximumSize(QSize(539, 174));
        QFont font;
        font.setFamily(QStringLiteral("Noto Serif CJK SC"));
        font.setPointSize(18);
        shutdownWindow->setFont(font);
        btCancel = new QPushButton(shutdownWindow);
        btCancel->setObjectName(QStringLiteral("btCancel"));
        btCancel->setGeometry(QRect(0, 124, 180, 50));
        btReboot = new QPushButton(shutdownWindow);
        btReboot->setObjectName(QStringLiteral("btReboot"));
        btReboot->setGeometry(QRect(180, 124, 180, 50));
        btShutdown = new QPushButton(shutdownWindow);
        btShutdown->setObjectName(QStringLiteral("btShutdown"));
        btShutdown->setGeometry(QRect(360, 124, 180, 50));
        lbLogo = new QLabel(shutdownWindow);
        lbLogo->setObjectName(QStringLiteral("lbLogo"));
        lbLogo->setGeometry(QRect(10, 10, 131, 101));
        lbLogo->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/reboot.png")));
        lbTip = new QLabel(shutdownWindow);
        lbTip->setObjectName(QStringLiteral("lbTip"));
        lbTip->setGeometry(QRect(180, 40, 201, 41));
        QFont font1;
        font1.setPointSize(20);
        lbTip->setFont(font1);

        retranslateUi(shutdownWindow);

        QMetaObject::connectSlotsByName(shutdownWindow);
    } // setupUi

    void retranslateUi(QDialog *shutdownWindow)
    {
        shutdownWindow->setWindowTitle(QApplication::translate("shutdownWindow", "\346\263\250\346\204\217", nullptr));
        btCancel->setText(QApplication::translate("shutdownWindow", "\345\217\226\346\266\210", nullptr));
        btReboot->setText(QApplication::translate("shutdownWindow", "\351\207\215\345\220\257", nullptr));
        btShutdown->setText(QApplication::translate("shutdownWindow", "\345\205\263\346\234\272", nullptr));
        lbLogo->setText(QString());
        lbTip->setText(QApplication::translate("shutdownWindow", "\350\257\267\345\274\200\345\247\213\344\275\240\347\232\204\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shutdownWindow: public Ui_shutdownWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHUTDOWNWINDOW_H
