#ifndef SHUTDOWNWINDOW_H
#define SHUTDOWNWINDOW_H

#include <QDialog>
#include<qstring.h>
namespace Ui {
class shutdownWindow;
}

class shutdownWindow : public QDialog
{
    Q_OBJECT

public:
    explicit shutdownWindow(QWidget *parent = 0);
    ~shutdownWindow();

private:
    Ui::shutdownWindow *ui;
private:
    void cancelButtonClicked();
    void shutdownButtonClicked();
    void rebootButtonClicked();
    bool isPasswordCorrect(const QString& password);
    QString getInputPassword();
};

#endif // SHUTDOWNWINDOW_H
