#include "rubik.hpp"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

#ifndef APP_H
#define APP_H

class MainWindow : public QWidget
{

private:
    QWidget window;

public:
    MainWindow();

};



class App : public QApplication
{

private:
    Rubik r;
    MainWindow window;

public:
    App(int argc, char **argv);

};


#endif
