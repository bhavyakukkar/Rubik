#include <QtWidgets/QVBoxLayout>

#include "app.hpp"


MainWindow::MainWindow() {
    QVBoxLayout layout;
    //layout.addWidget((QWidget*) &console);
    //console.setUndoRedoEnabled(true);
    window.setLayout((QLayout*) &layout);
    window.setGeometry(100, 100, 200, 300);
    window.setWindowTitle("Pixylene");
    window.show();
}

App::App(int argc, char **argv) : QApplication(argc, argv) {
}
