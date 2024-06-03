#include "rubik.hpp"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtGui/QResizeEvent>

#ifndef APP_H
#define APP_H

#define CELL_WIDTH 32
#define CELL_HEIGHT 32

class Viewport : public QGraphicsView
{

private:
    QGraphicsScene scene;
    Rubik* rubik;

public:
    Viewport(QWidget *parent = nullptr);
    void draw(Rubik *rubik);

protected:
    void resizeEvent(QResizeEvent*) override;
    //void paintEvent(QPaintEvent*) override;

};


class MainWindow : public QMainWindow
{

private:
    Viewport viewport;
    Rubik* rubik;

    QPushButton *buttonF;
    QPushButton *buttonU;
    QPushButton *buttonL;
    QPushButton *buttonR;
    QPushButton *buttonD;
    QPushButton *buttonB;
    void onPressButton(Face);

private slots:
    void on_buttonF_pressed();
    void on_buttonU_pressed();
    void on_buttonL_pressed();
    void on_buttonR_pressed();
    void on_buttonD_pressed();
    void on_buttonB_pressed();

public:
    MainWindow(QWidget *parent = nullptr, Rubik *rubik = nullptr);
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
