#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>

std::string readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string content;
    char c;
    while (file.get(c)) {
        content += c;
    }
    file.close();
    return content;
}

void writeFile(const std::string& fileName, const std::string& content) {
    std::ofstream file(fileName);
    file << content;
    file.close();
}

std::string textToBinary(const std::string& text) {
    std::string binary;
    for (char c : text) {
        binary += std::bitset<8>(c).to_string();
    }
    return binary;
}

std::string encodeBinary(const std::string& binary, int n) {
    // Implementa las reglas de codificación aquí...
    return binary; // Devuelve el mismo valor por ahora
}

int main() {
    int n, method;
    std::string inputFileName, outputFileName;

    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;
    std::cin.ignore(); // Limpiar el búfer del teclado

    std::cout << "Seleccione el metodo de codificacion (1 o 2): ";
    std::cin >> method;
    std::cin.ignore(); // Limpiar el búfer del teclado

    if (method != 1 && method != 2) {
        std::cout << "Metodo de codificacion invalido." << std::endl;
        return 1;
    }

    std::cout << "Ingrese el nombre del archivo de entrada: ";
    std::getline(std::cin, inputFileName);

    std::string text = readFile(inputFileName);
    std::string binary = textToBinary(text);
    std::string encodedBinary = encodeBinary(binary, n);

    std::cout << "Ingrese el nombre del archivo de salida: ";
    std::getline(std::cin, outputFileName);

    writeFile(outputFileName, encodedBinary);
    std::cout << "Archivo codificado correctamente." << std::endl;

    return 0;
}




