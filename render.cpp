#include <graphics.h>
#include <conio.h>
#include <math.h>


struct Vector3D {
    float x, y, z;

    Vector3D(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
};

Vector3D cubeVertices[8] = {
    { -1, -1, -1 }, { 1, -1, -1 }, { 1, 1, -1 }, { -1, 1, -1 },
    { -1, -1, 1 },  { 1, -1, 1 },  { 1, 1, 1 },  { -1, 1, 1 }
};

int cubeEdges[12][2] = {
    { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 },
    { 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 4 },
    { 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 }
};

Vector3D project(Vector3D point, float d) {
    return Vector3D(d * point.x / point.z, d * point.y / point.z, point.z);
}

Vector3D rotateZ(Vector3D point, float angle) {
    float cosA = cos(angle);
    float sinA = sin(angle);
    return Vector3D(
        point.x * cosA - point.y * sinA,
        point.x * sinA + point.y * cosA,
        point.z
    );
}

void renderCube(Vector3D* vertices, int edges[12][2], float d) {
    for (int i = 0; i < 12; i++) {
        Vector3D p1 = project(vertices[edges[i][0]], d);
        Vector3D p2 = project(vertices[edges[i][1]], d);
        line(320 + p1.x, 240 - p1.y, 320 + p2.x, 240 - p2.y); // 320, 240 is screen center
    }
}

void initGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
}

int main() {
    initGraphics();
    float angle = 0;
    while (!kbhit()) {
        cleardevice();
        for (int i = 0; i < 8; i++) {
            cubeVertices[i] = rotateZ(cubeVertices[i], angle);
        }
        renderCube(cubeVertices, cubeEdges, 100);
        angle += 0.05;
        delay(50);
    }
    closegraph();
    return 0;
}

