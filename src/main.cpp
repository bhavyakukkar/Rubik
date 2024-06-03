#include "rubik.hpp"
#include "app.hpp"
#include <cstdio>


void printFace(char face[3][3]) {
    printf(
        "\n%c %c %c\n%c %c %c\n%c %c %c\n\n",
        face[0][0], face[0][1], face[0][2],
        face[1][0], face[1][1], face[1][2],
        face[2][0], face[2][1], face[2][2]
    );
}


void printBars(char bars[3][3]) {
    printf(
        "\n%c %c %c %c %c %c %c %c %c %c %c %c\n\n",
        bars[0][0], bars[0][1], bars[0][2],
        bars[1][0], bars[1][1], bars[1][2],
        bars[2][0], bars[2][1], bars[2][2],
        bars[3][0], bars[3][1], bars[3][2]
    );
}

int main(int argc, char **argv) {
    App a(argc, argv);
    return a.exec();
}
