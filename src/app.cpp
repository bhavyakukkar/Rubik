#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QRect>
#include <QtCore/QPoint>
#include <QtGui/QPainter>
#include <iostream>

#include "app.hpp"


Viewport::Viewport(QWidget *parent)
    : QGraphicsView(parent), scene(parent)
{
    std::cout << "viewport constructed\n";
    setScene(&scene);
    scene.setSceneRect(0, 0, 800, 800);
}

void Viewport::resizeEvent(QResizeEvent *event)
{
    std::cout << "viewport resized\n";
    QGraphicsView::resizeEvent(event);
    scene.setSceneRect(0, 0, event->size().width(), event->size().height());
}

void Viewport::draw(Rubik *rubik)
{
    std::cout << "viewport drawn\n";
    QColor colorOf(char);
    QPen pen(Qt::black);
    QBrush brush(Qt::blue);

    //B
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_B, y, x)));
            scene.addRect((x*34)+102+10, (y*34), CELL_WIDTH, CELL_HEIGHT, pen, color);
        }

    //U
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_U, y, x)));
            scene.addRect((x*34)+102+10, (y*34)+102+10, CELL_WIDTH, CELL_HEIGHT, pen, color);
        }

    //L
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_L, y, x)));
            scene.addRect((x*34), (y*34)+102+10+102+10, CELL_WIDTH, CELL_HEIGHT, pen, color);
        }

    //F
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_F, y, x)));
            scene.addRect((x*34)+102+10, (y*34)+102+10+102+10, CELL_WIDTH, CELL_HEIGHT, pen, color);
        }

    //R
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_R, y, x)));
            scene.addRect((x*34)+102+10+102+10, (y*34)+102+10+102+10, CELL_WIDTH, CELL_HEIGHT, pen, color);
        }

    //D
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_D, y, x)));
            scene.addRect((x*34)+102+10, (y*34)+102+10+102+10+102+10, CELL_WIDTH, CELL_HEIGHT, pen, color);
        }

    //setScene(&scene);
}

QColor colorOf(char c)
{
    switch(c) {
        case 'W':
            return Qt::white;
        case 'O':
            return Qt::darkRed;
        case 'G':
            return Qt::green;
        case 'B':
            return Qt::blue;
        case 'R':
            return Qt::red;
        case 'Y':
            return Qt::yellow;
    }
}

MainWindow::MainWindow(QWidget *parent, Rubik *_rubik)
    : QMainWindow(parent), viewport(parent)
{
    std::cout << "main-window constructed\n";

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(&viewport);
    rubik = _rubik;
    //viewport.show();

    QWidget *buttons = new QWidget(this);
    QHBoxLayout *buttonsLayout = new QHBoxLayout(buttons);
    buttonF = new QPushButton("F", this);
    buttonsLayout->addWidget(buttonF);
    connect(buttonF, &QPushButton::pressed, this, &MainWindow::on_buttonF_pressed);
    buttonU = new QPushButton("U", this);
    buttonsLayout->addWidget(buttonU);
    connect(buttonU, &QPushButton::pressed, this, &MainWindow::on_buttonU_pressed);
    buttonL = new QPushButton("L", this);
    buttonsLayout->addWidget(buttonL);
    connect(buttonL, &QPushButton::pressed, this, &MainWindow::on_buttonL_pressed);
    buttonR = new QPushButton("R", this);
    buttonsLayout->addWidget(buttonR);
    connect(buttonR, &QPushButton::pressed, this, &MainWindow::on_buttonR_pressed);
    buttonD = new QPushButton("D", this);
    buttonsLayout->addWidget(buttonD);
    connect(buttonD, &QPushButton::pressed, this, &MainWindow::on_buttonD_pressed);
    buttonB = new QPushButton("B", this);
    buttonsLayout->addWidget(buttonB);
    connect(buttonB, &QPushButton::pressed, this, &MainWindow::on_buttonB_pressed);

    layout->addWidget(buttons);
    layout->setStretch(0, 0);
    layout->setStretch(1, 1);

    setCentralWidget(centralWidget);
    viewport.draw(rubik);
}

void MainWindow::onPressButton(Face face) {
    std::cout << "main-window button clicked\n";
    rubik->move(face, true);
    viewport.draw(rubik);
}

void MainWindow::on_buttonF_pressed() { onPressButton(FACE_F); }
void MainWindow::on_buttonU_pressed() { onPressButton(FACE_U); }
void MainWindow::on_buttonL_pressed() { onPressButton(FACE_L); }
void MainWindow::on_buttonR_pressed() { onPressButton(FACE_R); }
void MainWindow::on_buttonD_pressed() { onPressButton(FACE_D); }
void MainWindow::on_buttonB_pressed() { onPressButton(FACE_B); }

App::App(int argc, char **argv) : QApplication(argc, argv), r(), window(nullptr, &r)
{
    std::cout << "app constructed\n";
    window.setFixedSize(400, 600);
    window.setWindowTitle("Pixylene");
    window.show();
}
