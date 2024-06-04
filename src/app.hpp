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

#define CELL_WIDTH 30
#define CELL_HEIGHT 30
#define CELL_GAP 4
#define FACE_GAP 10
#define PADDING 30

class Viewport : public QGraphicsView
{

private:
    QGraphicsScene scene;
    Rubik* rubik;
    int cw = CELL_WIDTH, ch = CELL_HEIGHT, cg = CELL_GAP, fg = FACE_GAP, padding = PADDING;

public:
    Viewport(QWidget *parent = nullptr);
    void draw(Rubik *rubik);

};


class MainWindow : public QMainWindow
{

private:
    Viewport viewport;
    Rubik* rubik;
    void onPressButton(Face, bool);

private slots:
    void pressedButtonF();
    void pressedButtonF_();
    void pressedButtonU();
    void pressedButtonU_();
    void pressedButtonL();
    void pressedButtonL_();
    void pressedButtonR();
    void pressedButtonR_();
    void pressedButtonD();
    void pressedButtonD_();
    void pressedButtonB();
    void pressedButtonB_();

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
