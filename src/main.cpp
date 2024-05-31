#include "rubik.hpp"
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

int main() {
    Rubik r;
    r.get(FACE_F);
    r.get(FACE_U);
    r.get(FACE_L);
    r.get(FACE_R);
    r.get(FACE_D);
    r.get(FACE_B);
    r.move(FACE_B, false);
    r.get(FACE_F);
    r.get(FACE_U);
    r.get(FACE_L);
    r.get(FACE_R);
    r.get(FACE_D);
    r.get(FACE_B);
    return 0;
}
