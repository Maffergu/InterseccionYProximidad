#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct Point {
    double x, y;
};

// Función para verificar si dos segmentos se intersectan
bool doSegmentsIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Calcula las orientaciones de los puntos
    double o1 = (q1.x - p1.x) * (p2.y - p1.y) - (q1.y - p1.y) * (p2.x - p1.x);
    double o2 = (q1.x - p1.x) * (q2.y - p1.y) - (q1.y - p1.y) * (q2.x - p1.x);
    double o3 = (q2.x - p2.x) * (p1.y - p2.y) - (q2.y - p2.y) * (p1.x - p2.x);
    double o4 = (q2.x - p2.x) * (q1.y - p2.y) - (q2.y - p2.y) * (q1.x - p2.x);

    // Verifica si los segmentos son colineales
    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
        // Los segmentos son colineales, verifica si se solapan
        if (p1.x >= min(p2.x, q2.x) && p1.x <= max(p2.x, q2.x) && p1.y >= min(p2.y, q2.y) && p1.y <= max(p2.y, q2.y)) {
            return true;
        }
        if (q1.x >= min(p2.x, q2.x) && q1.x <= max(p2.x, q2.x) && q1.y >= min(p2.y, q2.y) && q1.y <= max(p2.y, q2.y)) {
            return true;
        }
        if (p2.x >= min(p1.x, q1.x) && p2.x <= max(p1.x, q1.x) && p2.y >= min(p1.y, q1.y) && p2.y <= max(p1.y, q1.y)) {
            return true;
        }
        if (q2.x >= min(p1.x, q1.x) && q2.x <= max(p1.x, q1.x) && q2.y >= min(p1.y, q1.y) && q2.y <= max(p1.y, q1.y)) {
            return true;
        }
    }

    // Verifica si los puntos p1 y q1 están en lados opuestos de la línea formada por p2 y q2
    if (o1 * o2 < 0 && o3 * o4 < 0) {
        return true;
    }

    return false; // Si no se cumplen las condiciones anteriores, los segmentos no se intersectan
}

int main() {
    int numPairs;
    cout << "Ingrese el número de pares de segmentos de recta a comparar: ";
    cin >> numPairs;
    cin.ignore(); // Para eliminar el salto de línea pendiente

    vector<Point> points(numPairs * 4); // Cada par de segmentos consta de 4 puntos

    for (int i = 0; i < numPairs; i++) {
        cout << "Ingrese las coordenadas de los 4 puntos (x1, y1 x2, y2 x3, y3 x4, y4) para el par " << i + 1 << ": ";
        string input;
        getline(cin, input);

        istringstream iss(input);
        iss >> points[i * 4].x >> points[i * 4].y >> points[i * 4 + 1].x >> points[i * 4 + 1].y >> points[i * 4 + 2].x >> points[i * 4 + 2].y >> points[i * 4 + 3].x >> points[i * 4 + 3].y;
    }

    // Verifica la intersección de los segmentos
    for (int i = 0; i < numPairs; i++) {
        Point p1 = points[i * 4];
        Point q1 = points[i * 4 + 1];
        Point p2 = points[i * 4 + 2];
        Point q2 = points[i * 4 + 3];

        if (doSegmentsIntersect(p1, q1, p2, q2)) {
            cout << "Los segmentos " << i + 1 << " se intersectan." << endl;
        } else {
            cout << "Los segmentos " << i + 1 << " no se intersectan." << endl;
        }
    }

    return 0;
}