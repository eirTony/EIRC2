#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MenuBar;
class MiscActions;
class CentralWidget;
class StatusBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * parent=0);
    ~MainWindow();

    static const MainWindow * pointer(void);
    QAction * quitAction(void) const;

public slots:
    void setup(void);

private:
    static MainWindow * smpThis;
    MenuBar * mpMenuBar = 0;
    MiscActions * mpMiscActions = 0;
    CentralWidget * mpCentralWidget = 0;
    StatusBar * mpStatusBar = 0;
};


#endif // MAINWINDOW_H
