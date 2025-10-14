// list_tree.cpp
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

/**
 * Lista recursivamente todos los archivos y carpetas
 * dentro de 'ruta', imprimiendo su path absoluto.
 *
 * @param ruta  Directorio inicial a explorar
 */

void listar_recursivo(const fs::path& ruta)
{
    // Imprime la propia ruta (puedes omitir esta línea si solo quieres contenidos)
    std::cout << ruta.string() << '\n';

    // Itera sobre cada entrada dentro del directorio
    for (const fs::directory_entry& entry : fs::directory_iterator(ruta))
    {
        // Si es un directorio, se llama de nuevo a sí misma (recursión)
        if (entry.is_directory())
        {
            listar_recursivo(entry.path());
        }
        else
        {
            // Si es un archivo (u otro tipo), lo muestra
            std::cout << entry.path().string() << '\n';
        }
    }
}

int main(int argc, char* argv[])
{
    try
    {
        // Usa el primer argumento como ruta; si no hay, toma el directorio actual
        fs::path raiz = "/Users/tsutomu/Downloads/data_set";
        cout<<raiz<<endl;
        if (!fs::exists(raiz) || !fs::is_directory(raiz))
        {
            std::cerr << "La ruta especificada no es un directorio válido.\n";
            return 1;
        }

        listar_recursivo(raiz);
    }
    catch (const fs::filesystem_error& e)
    {
        std::cerr << "Error de filesystem: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

