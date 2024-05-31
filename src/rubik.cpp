#include "rubik.hpp"
#include <unistd.h>
#include <cstdio>

void Rubik::moveF(bool clockwise) {
    char bars[4][3];
    char temp[3][3];
    char temp2[3][3];

    rotateFace(grid[FACE_F], clockwise);

    copyBar(bars[0], grid[FACE_U][2], 1);
    {
        copyFace(temp, grid[FACE_L]);
        rotateFace(temp, false);
        copyBar(bars[1], temp[0], 0);
    }
    copyBar(bars[2], grid[FACE_D][0], 0);
    {
        copyFace(temp, grid[FACE_R]);
        rotateFace(temp, true);
        copyBar(bars[3], temp[0], 0);
    }

    rotateBars(bars, clockwise);

    copyBar(grid[FACE_U][2], bars[0], 1);
    {
        copyBar(temp[0], bars[1], 0);
        {
            copyFace(temp2, grid[FACE_L]);
            rotateFace(temp2, false);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, true);
        copyFace(grid[FACE_L], temp);
    }
    copyBar(grid[FACE_D][0], bars[2], 0);
    {
        copyBar(temp[0], bars[3], 0);
        {
            copyFace(temp2, grid[FACE_R]);
            rotateFace(temp2, true);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, false);
        copyFace(grid[FACE_R], temp);
    }
}

void Rubik::moveU(bool clockwise) {
    char bars[4][3];

    rotateFace(grid[FACE_U], clockwise);

    copyBar(bars[0], grid[FACE_F][0], 0);
    copyBar(bars[1], grid[FACE_R][0], 0);
    copyBar(bars[2], grid[FACE_B][2], 1);
    copyBar(bars[3], grid[FACE_L][0], 0);

    rotateBars(bars, clockwise);

    copyBar(grid[FACE_F][0], bars[0], 0);
    copyBar(grid[FACE_R][0], bars[1], 0);
    copyBar(grid[FACE_B][2], bars[2], 1);
    copyBar(grid[FACE_L][0], bars[3], 0);
}

void Rubik::moveL(bool clockwise) {
    char bars[4][3];
    char temp[3][3];
    char temp2[3][3];

    rotateFace(grid[FACE_L], clockwise);

    {
        copyFace(temp, grid[FACE_F]);
        rotateFace(temp, true);
        copyBar(bars[0], temp[0], 0);
    }
    {
        copyFace(temp, grid[FACE_U]);
        rotateFace(temp, true);
        copyBar(bars[1], temp[0], 0);
    }
    {
        copyFace(temp, grid[FACE_B]);
        rotateFace(temp, true);
        copyBar(bars[2], temp[0], 0);
    }
    {
        copyFace(temp, grid[FACE_D]);
        rotateFace(temp, true);
        copyBar(bars[3], temp[0], 0);
    }

    rotateBars(bars, clockwise);

    {
        copyBar(temp[0], bars[0], 0);
        {
            copyFace(temp2, grid[FACE_F]);
            rotateFace(temp2, true);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, false);
        copyFace(grid[FACE_F], temp);
    }
    {
        copyBar(temp[0], bars[1], 0);
        {
            copyFace(temp2, grid[FACE_U]);
            rotateFace(temp2, true);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, false);
        copyFace(grid[FACE_U], temp);
    }
    {
        copyBar(temp[0], bars[2], 0);
        {
            copyFace(temp2, grid[FACE_B]);
            rotateFace(temp2, true);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, false);
        copyFace(grid[FACE_B], temp);
    }
    {
        copyBar(temp[0], bars[3], 0);
        {
            copyFace(temp2, grid[FACE_D]);
            rotateFace(temp2, true);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, false);
        copyFace(grid[FACE_D], temp);
    }
}

void Rubik::moveR(bool clockwise) {
    char bars[4][3];
    char temp[3][3];
    char temp2[3][3];

    rotateFace(grid[FACE_R], clockwise);

    {
        copyFace(temp, grid[FACE_F]);
        rotateFace(temp, false);
        copyBar(bars[0], temp[0], 0);
    }
    {
        copyFace(temp, grid[FACE_D]);
        rotateFace(temp, false);
        copyBar(bars[1], temp[0], 0);
    }
    {
        copyFace(temp, grid[FACE_B]);
        rotateFace(temp, false);
        copyBar(bars[2], temp[0], 0);
    }
    {
        copyFace(temp, grid[FACE_U]);
        rotateFace(temp, false);
        copyBar(bars[3], temp[0], 0);
    }

    rotateBars(bars, clockwise);

    {
        copyBar(temp[0], bars[0], 0);
        {
            copyFace(temp2, grid[FACE_F]);
            rotateFace(temp2, false);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, true);
        copyFace(grid[FACE_F], temp);
    }
    {
        copyBar(temp[0], bars[1], 0);
        {
            copyFace(temp2, grid[FACE_D]);
            rotateFace(temp2, false);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, true);
        copyFace(grid[FACE_D], temp);
    }
    {
        copyBar(temp[0], bars[2], 0);
        {
            copyFace(temp2, grid[FACE_B]);
            rotateFace(temp2, false);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, true);
        copyFace(grid[FACE_B], temp);
    }
    {
        copyBar(temp[0], bars[3], 0);
        {
            copyFace(temp2, grid[FACE_U]);
            rotateFace(temp2, false);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, true);
        copyFace(grid[FACE_U], temp);
    }
}

void Rubik::moveD(bool clockwise) {
    char bars[4][3];

    rotateFace(grid[FACE_D], clockwise);

    copyBar(bars[0], grid[FACE_F][2], 1);
    copyBar(bars[1], grid[FACE_L][2], 1);
    copyBar(bars[2], grid[FACE_B][0], 0);
    copyBar(bars[3], grid[FACE_R][2], 1);

    rotateBars(bars, clockwise);

    copyBar(grid[FACE_F][2], bars[0], 1);
    copyBar(grid[FACE_L][2], bars[1], 1);
    copyBar(grid[FACE_B][0], bars[2], 0);
    copyBar(grid[FACE_R][2], bars[3], 1);
}

void Rubik::moveB(bool clockwise) {
    char bars[4][3];
    char temp[3][3];
    char temp2[3][3];

    rotateFace(grid[FACE_F], clockwise);

    copyBar(bars[0], grid[FACE_U][0], 0);
    {
        copyFace(temp, grid[FACE_R]);
        rotateFace(temp, false);
        copyBar(bars[1], temp[0], 0);
    }
    copyBar(bars[2], grid[FACE_D][2], 1);
    {
        copyFace(temp, grid[FACE_L]);
        rotateFace(temp, true);
        copyBar(bars[3], temp[0], 0);
    }

    rotateBars(bars, clockwise);

    copyBar(grid[FACE_U][0], bars[0], 0);
    {
        copyBar(temp[0], bars[1], 0);
        {
            copyFace(temp2, grid[FACE_R]);
            rotateFace(temp2, false);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, true);
        copyFace(grid[FACE_R], temp);
    }
    copyBar(grid[FACE_D][2], bars[2], 0);
    {
        copyBar(temp[0], bars[3], 0);
        {
            copyFace(temp2, grid[FACE_L]);
            rotateFace(temp2, true);
            copyBar(temp[1], temp2[1], 0);
        }
        {
            copyBar(temp[2], temp2[2], 0);
        }
        rotateFace(temp, false);
        copyFace(grid[FACE_L], temp);
    }
}

Rubik::Rubik() {
}

void Rubik::move(Face face, bool clockwise) {
    switch (face) {
        case FACE_F:
            moveF(clockwise);
            break;
        case FACE_U:
            moveU(clockwise);
            break;
        case FACE_L:
            moveL(clockwise);
            break;
        case FACE_R:
            moveR(clockwise);
            break;
        case FACE_D:
            moveD(clockwise);
            break;
        case FACE_B:
            moveB(clockwise);
            break;
    }
}

char** Rubik::get(Face face) {
    printf(
        "\n%c %c %c\n%c %c %c\n%c %c %c\n\n",
        grid[face][0][0], grid[face][0][1], grid[face][0][2],
        grid[face][1][0], grid[face][1][1], grid[face][1][2],
        grid[face][2][0], grid[face][2][1], grid[face][2][2]
    );
    return NULL;
}

void Rubik::rotateFace(char face[3][3], bool clockwise) {
    char temp1, temp2;
    if(clockwise) {
        temp1 = face[0][0];
        temp2 = face[0][1];

        face[0][0] = face[2][0];
        face[0][1] = face[1][0];

        face[2][0] = face[2][2];
        face[1][0] = face[2][1];

        face[2][2] = face[0][2];
        face[2][1] = face[1][2];

        face[0][2] = temp1;
        face[1][2] = temp2;
    } else {
        temp1 = face[0][0];
        temp2 = face[0][1];

        face[0][0] = face[0][2];
        face[0][1] = face[1][2];

        face[0][2] = face[2][2];
        face[1][2] = face[2][1];

        face[2][2] = face[2][0];
        face[2][1] = face[1][0];

        face[2][0] = temp1;
        face[1][0] = temp2;
    }
}

void Rubik::rotateBars(char bars[4][3], bool clockwise) {
    char temp1, temp2, temp3;
    if (clockwise) {
        temp1 = bars[0][0];
        temp2 = bars[0][1];
        temp3 = bars[0][2];
        for (int i = 0; i < 3; i++) {
            bars[i][0] = bars[i + 1][0];
            bars[i][1] = bars[i + 1][1];
            bars[i][2] = bars[i + 1][2];
        }
        bars[3][0] = temp1;
        bars[3][1] = temp2;
        bars[3][2] = temp3;
    } else {
        temp1 = bars[3][0];
        temp2 = bars[3][1];
        temp3 = bars[3][2];
        for (int i = 2; i >= 0; i--) {
            bars[i + 1][0] = bars[i][0];
            bars[i + 1][1] = bars[i][1];
            bars[i + 1][2] = bars[i][2];
        }
        bars[0][0] = temp1;
        bars[0][1] = temp2;
        bars[0][2] = temp3;
    }
}

void Rubik::copyBar(char dest[3], char src[3], bool revSrc) {
    if(!revSrc) {
        dest[0] = src[0];
        dest[1] = src[1];
        dest[2] = src[2];
    } else {
        dest[0] = src[2];
        dest[1] = src[1];
        dest[2] = src[0];
    }
}

void Rubik::copyFace(char dest[3][3], char src[3][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            dest[i][j] = src[i][j];
}
