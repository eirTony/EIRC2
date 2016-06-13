#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MenuBar;
class Settings;
class MiscActions;
class CentralWidget;
class StatusBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * parent=0);
    ~MainWindow();

    static MainWindow * pointer(void);
    MenuBar * menu(void) const;
    Settings & settings(void) const;
    QAction * quitAction(void) const;

public slots:
    void setup(void);

private:
    static MainWindow * smpThis;
    MiscActions * mpMiscActions = 0;
    Settings * mpSettings = 0;

    MenuBar * mpMenuBar = 0;
    CentralWidget * mpCentralWidget = 0;
    StatusBar * mpStatusBar = 0;
};


#endif // MAINWINDOW_H
