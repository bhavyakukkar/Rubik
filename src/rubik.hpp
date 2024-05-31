
enum Face {
    FACE_F,
    FACE_U,
    FACE_L,
    FACE_R,
    FACE_D,
    FACE_B
};

class Rubik
{

private:
    //F, U, L, R, D, B
    char grid[6][3][3] = {
        {{'W','W','W'}, {'W','W','W'}, {'W','W','W'},},
        {{'O','O','O'}, {'O','O','O'}, {'O','O','O'},},
        {{'G','G','G'}, {'G','G','G'}, {'G','G','G'},},
        {{'B','B','B'}, {'B','B','B'}, {'B','B','B'},},
        {{'R','R','R'}, {'R','R','R'}, {'R','R','R'},},
        {{'Y','Y','Y'}, {'Y','Y','Y'}, {'Y','Y','Y'},},
    };

    static void copyBar(char[3], char[3], bool);
    static void copyFace(char[3][3], char[3][3]);

    void moveF(bool);
    void moveU(bool);
    void moveL(bool);
    void moveR(bool);
    void moveD(bool);
    void moveB(bool);

public:
    static void rotateBars(char[4][3], bool);
    static void rotateFace(char[3][3], bool);
    Rubik();
    void move(Face, bool);
    char** get(Face);
};

