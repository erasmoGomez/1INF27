#include "src/RussianRoulette.hpp"

int main() {
    int n = 7;
    int ganador = russian_roulette(n, (int)time(nullptr));
    cout << "Ganador : " << ganador << "\n";
    return 0;
}
