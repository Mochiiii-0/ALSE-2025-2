// Parcial 1 - Cálculo de distancias en 2D
// Completa las funciones para: leer puntos, calcular distancias y hallar el punto más cercano.

#include <iostream>
#include <cmath>
#include <cctype> // tolower()

// Estructura básica para representar un punto en 2D
struct Point {
    double x, y;
};

// Distancia euclidiana entre dos puntos.
// Se pasan por referencia constante para no copiar memoria y evitar modificaciones.
double calcularDistancia(const Point &p1, const Point &p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx*dx + dy*dy);
}

// Lee 'n' puntos: si el usuario responde 's', se ingresan manualmente;
// de lo contrario, se cargan puntos predeterminados de ejemplo.
void leerPuntos(Point puntos[], int n) {
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    if (std::tolower(respuesta) == 's') {
        for (int i = 0; i < n; i++) {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    } else {
        std::cout << "Usando puntos predeterminados...\n";
        // Ejemplos simples para permitir probar el flujo sin ingreso manual.
        puntos[0] = {0, 0};
        if (n > 1) puntos[1] = {3, 4};
        if (n > 2) puntos[2] = {6, 8};
        if (n > 3) puntos[3] = {9, 12};
        // Si n > 4, el resto quedará sin inicializar; en prácticas reales se debería completar.
    }
}

// Recorre el arreglo y devuelve la distancia mínima al punto del usuario.
// También entrega por referencia el índice del punto más cercano encontrado.
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano) {
    double distanciaMinima = calcularDistancia(pUsuario, puntos[0]);
    indiceMasCercano = 0;

    for (int i = 1; i < n; i++) {
        double d = calcularDistancia(pUsuario, puntos[i]);
        if (d < distanciaMinima) {
            distanciaMinima = d;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;
}

// Muestra el punto más cercano y su distancia correspondiente.
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia) {
    std::cout << "El punto más cercano es: ("
              << puntos[indiceMasCercano].x << ", "
              << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: "
              << distancia << std::endl;
}

int main() {
    int n;
    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    std::cin >> n;

    // Validación mínima solicitada: al menos 2 puntos.
    if (n < 2) {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    // Nota: usar arreglo automático sigue la plantilla base dada en clase.
    // En C++ moderno se podría preferir std::vector<Point> para portabilidad.
    Point puntos[n];

    // 1) Leer puntos (manual o predeterminado)
    leerPuntos(puntos, n);

    // 2) Leer el punto de referencia del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    // 3) Calcular el más cercano y 4) mostrar resultado
    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);
    mostrarResultado(puntos, indiceMasCercano, distancia);

    return 0;
}