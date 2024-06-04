#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMenuBar>
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
}

void Viewport::draw(Rubik *rubik)
{
    std::cout << "viewport drawn\n";
    QColor colorOf(char);
    QPen pen(Qt::black);
    scene.clear();

    int total_width = padding+3*(3*cw + 2*cg)+2*fg+padding;
    int total_height = padding+4*(3*cw + 2*cg)+3*fg+padding;

    //Background
    QBrush bg(Qt::darkGray);
    scene.addRect(0, 0, total_width, total_height, pen, bg);
    scene.setSceneRect(0, 0, total_width, total_height);

    //B
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_B, y, x)));
            scene.addRect(
                padding + (x*(cw + cg))+(3*cw + 2*cg)+fg,
                padding + (y*(ch + cg)),
                cw, ch, pen, color
            );
        }

    //L
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_L, y, x)));
            scene.addRect(
                padding + (x*(cw + cg)),
                padding + (y*(ch + cg))+2*(3*ch + 2*cg)+2*fg,
                cw, ch, pen, color
            );
        }

    //U
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_U, y, x)));
            scene.addRect(
                padding + (x*(cw + cg))+(3*cw + 2*cg)+fg,
                padding + (y*(ch + cg))+(3*ch + 2*cg)+fg,
                cw, ch, pen, color
            );
        }

    //F
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_F, y, x)));
            scene.addRect(
                padding + (x*(cw + cg))+(3*cw + 2*cg)+fg,
                padding + (y*(ch + cg))+2*(3*ch + 2*cg)+2*fg,
                cw, ch, pen, color
            );
        }

    //R
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_R, y, x)));
            scene.addRect(
                padding + (x*(cw + cg))+2*(3*cw + 2*cg)+2*fg,
                padding + (y*(ch + cg))+2*(3*ch + 2*cg)+2*fg,
                cw, ch, pen, color
            );
        }

    //D
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++) {
            QBrush color(colorOf(rubik->get(FACE_D, y, x)));
            scene.addRect(
                padding + (x*(cw + cg))+(3*cw + 2*cg)+fg,
                padding + (y*(ch + cg))+3*(3*ch + 2*cg)+3*fg,
                cw, ch, pen, color
            );
        }
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
    return Qt::white;
}

MainWindow::MainWindow(QWidget *parent, Rubik *_rubik)
    : QMainWindow(parent), viewport(parent)
{
    QPushButton *buttonF, *buttonU, *buttonL, *buttonR, *buttonD, *buttonB;
    QPushButton *buttonF_, *buttonU_, *buttonL_, *buttonR_, *buttonD_, *buttonB_;
    std::cout << "main-window constructed\n";
    QMenuBar *menu = new QMenuBar;

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(&viewport);
    rubik = _rubik;

    QWidget *buttons = new QWidget(this);
    QHBoxLayout *buttonsLayout = new QHBoxLayout(buttons);

    //todo: use arrays
    {
        QWidget *buttonsF = new QWidget(this);
        QVBoxLayout *buttonsFLayout = new QVBoxLayout(buttonsF);

        buttonF = new QPushButton("F", this);
        connect(buttonF, &QPushButton::pressed, this, &MainWindow::pressedButtonF);
        buttonsFLayout->addWidget(buttonF);

        buttonF_ = new QPushButton("F'", this);
        connect(buttonF_, &QPushButton::pressed, this, &MainWindow::pressedButtonF_);
        buttonsFLayout->addWidget(buttonF_);
        buttonsLayout->addWidget(buttonsF);
    }
    {
        QWidget *buttonsU = new QWidget(this);
        QVBoxLayout *buttonsULayout = new QVBoxLayout(buttonsU);

        buttonU = new QPushButton("U", this);
        connect(buttonU, &QPushButton::pressed, this, &MainWindow::pressedButtonU);
        buttonsULayout->addWidget(buttonU);

        buttonU_ = new QPushButton("U'", this);
        connect(buttonU_, &QPushButton::pressed, this, &MainWindow::pressedButtonU_);
        buttonsULayout->addWidget(buttonU_);
        buttonsLayout->addWidget(buttonsU);
    }
    {
        QWidget *buttonsL = new QWidget(this);
        QVBoxLayout *buttonsLLayout = new QVBoxLayout(buttonsL);

        buttonL = new QPushButton("L", this);
        connect(buttonL, &QPushButton::pressed, this, &MainWindow::pressedButtonL);
        buttonsLLayout->addWidget(buttonL);

        buttonL_ = new QPushButton("L'", this);
        connect(buttonL_, &QPushButton::pressed, this, &MainWindow::pressedButtonL_);
        buttonsLLayout->addWidget(buttonL_);
    }
    {
        QWidget *buttonsR = new QWidget(this);
        QVBoxLayout *buttonsRLayout = new QVBoxLayout(buttonsR);

        buttonR = new QPushButton("R", this);
        connect(buttonR, &QPushButton::pressed, this, &MainWindow::pressedButtonR);
        buttonsRLayout->addWidget(buttonR);

        buttonR_ = new QPushButton("R'", this);
        connect(buttonR_, &QPushButton::pressed, this, &MainWindow::pressedButtonR_);
        buttonsRLayout->addWidget(buttonR_);
        buttonsLayout->addWidget(buttonsR);
    }
    {
        QWidget *buttonsD = new QWidget(this);
        QVBoxLayout *buttonsDLayout = new QVBoxLayout(buttonsD);

        buttonD = new QPushButton("D", this);
        connect(buttonD, &QPushButton::pressed, this, &MainWindow::pressedButtonD);
        buttonsDLayout->addWidget(buttonD);

        buttonD_ = new QPushButton("D'", this);
        connect(buttonD_, &QPushButton::pressed, this, &MainWindow::pressedButtonD_);
        buttonsDLayout->addWidget(buttonD_);
        buttonsLayout->addWidget(buttonsD);
    }
    {
        QWidget *buttonsB = new QWidget(this);
        QVBoxLayout *buttonsBLayout = new QVBoxLayout(buttonsB);

        buttonB = new QPushButton("B", this);
        connect(buttonB, &QPushButton::pressed, this, &MainWindow::pressedButtonB);
        buttonsBLayout->addWidget(buttonB);

        buttonB_ = new QPushButton("B'", this);
        connect(buttonB_, &QPushButton::pressed, this, &MainWindow::pressedButtonB_);
        buttonsBLayout->addWidget(buttonB_);
        buttonsLayout->addWidget(buttonsB);
    }

    layout->addWidget(buttons);
    layout->setStretch(0, 1);
    layout->setStretch(1, 0);

    setCentralWidget(centralWidget);
    viewport.draw(rubik);
}

void MainWindow::onPressButton(Face face, bool clockwise)
{
    std::cout << "main-window button clicked\n";
    rubik->move(face, clockwise);
    viewport.draw(rubik);
}

void MainWindow::pressedButtonF()   { onPressButton(FACE_F, true); }
void MainWindow::pressedButtonF_()  { onPressButton(FACE_F, false); }
void MainWindow::pressedButtonU()   { onPressButton(FACE_U, true); }
void MainWindow::pressedButtonU_()  { onPressButton(FACE_U, false); }
void MainWindow::pressedButtonL()   { onPressButton(FACE_L, true); }
void MainWindow::pressedButtonL_()  { onPressButton(FACE_L, false); }
void MainWindow::pressedButtonR()   { onPressButton(FACE_R, true); }
void MainWindow::pressedButtonR_()  { onPressButton(FACE_R, false); }
void MainWindow::pressedButtonD()   { onPressButton(FACE_D, true); }
void MainWindow::pressedButtonD_()  { onPressButton(FACE_D, false); }
void MainWindow::pressedButtonB()   { onPressButton(FACE_B, true); }
void MainWindow::pressedButtonB_()  { onPressButton(FACE_B, false); }

App::App(int argc, char **argv) : QApplication(argc, argv), r(), window(nullptr, &r)
{
    std::cout << "app constructed\n";
    window.setFixedSize(400, 600);
    window.setWindowTitle("Pixylene");
    window.show();
}
