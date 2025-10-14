#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/*** Parámetros del lienzo ***/
const int H = 150;         // alto en filas
const int W = 100;        // ancho en columnas

/*** Canvas ASCII ***/
char canvas[H][W];

/*** Utilidades ***/
inline double deg2rad(double a){ return a * M_PI / 180.0; }

void clear_canvas() {
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            canvas[i][j] = ' ';
}

void plot(double x, double y) {
    // Origen arriba-izquierda; y crece hacia abajo
    int xi = (int)llround(x);
    int yi = (int)llround(y);
    if (xi >= 0 && xi < W && yi >= 0 && yi < H)
        canvas[yi][xi] = '*';
}

/*** Tortuga ***/
struct Turtle {
    double x, y;      // posición
    double ang;       // grados, 0 = hacia la derecha, CCW positivo

    void turn(double ddeg) { ang += ddeg; }

    // Avanza dibujando una línea con pequeños pasos (sin usar strings)
    void forward(double len) {
        // pasos proporcionales a la longitud, para que no queden huecos
        int steps = (int)max(1.0, len / 1.0); // 1.0 ≈ 1 columna por paso
        double rad = deg2rad(ang);
        double dx = cos(rad) * (len / steps);
        double dy = -sin(rad) * (len / steps); // signo menos porque y crece hacia abajo

        for (int i = 0; i <= steps; ++i) {
            plot(x, y);
            x += dx;
            y += dy;
        }
    }
};

/*** Koch recursivo (puro) ***/
void koch(Turtle &t, int depth, double len) {
    if (depth == 0) {
        t.forward(len);
        return;
    }
    len /= 3.0;
    koch(t, depth - 1, len);
    t.turn(60);
    koch(t, depth - 1, len);
    t.turn(-120);
    koch(t, depth - 1, len);
    t.turn(60);
    koch(t, depth - 1, len);
}

int main() {
    ofstream output;
    output.open("Reportes/grafico.txt", ios::out);
    clear_canvas();

    // Ajusta estos parámetros si quieres centrar/escala diferente
    int depth = 0;                 // 0..5 (con 5 puede ser lento en consola)
    double side = W * 0.60;        // largo de cada lado del triángulo base
    double height = side * sqrt(3) / 2.0;

    // Posición inicial: centrado horizontal, con margen vertical
    Turtle t;
    t.ang = 0;                     // mirando a la derecha
    t.x = (W - side) / 2.0;        // esquina inferior-izquierda del triángulo
    t.y = (H + height * 0.5) / 2.0;

    // Dibuja el copo: 3 curvas de Koch formando un triángulo equilátero
    for (int i = 0; i < 3; ++i) {
        koch(t, depth, side);
        t.turn(-120);
    }

    // Imprimir canvas
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) cout << canvas[i][j];
        cout << '\n';
    }
    return 0;
}
