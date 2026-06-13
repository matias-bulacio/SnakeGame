#include <enemigos.h>
#include <raylib.h>
#include <shooter.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

Enemigo *arreglo_de_enemigos;
Image image;
Texture2D texture;
size_t cantidad_enemigos = 5;

int shooter(bool setup) {
    if (setup) { // Seting up
        if (arreglo_de_enemigos == NULL)
            free(arreglo_de_enemigos);
        cantidad_enemigos = 5;

        arreglo_de_enemigos =
            calloc(cantidad_enemigos, sizeof(*arreglo_de_enemigos));

        if (arreglo_de_enemigos == NULL) {
            return -1; // Error
        }

        for (size_t i = 0; i < cantidad_enemigos; i++) {
            Enemigo *e = &arreglo_de_enemigos[i];
            e->coordenadas.y = 0;
            e->coordenadas.x = 50 + 175 * i;
        }
        if (IsTextureValid(texture)) {
            UnloadTexture(texture);
        }
        image = LoadImage("Resources/Animals/tiger.png");
		ImageResizeNN(&image, 100, 100);
		texture = LoadTextureFromImage(image);
    }
    ClearBackground(BEIGE);

    for (size_t i = 0; i < cantidad_enemigos; i++) {
        Enemigo *e = &arreglo_de_enemigos[i];
        Enemigo_Avanzar(e, 100, GetFrameTime());
        DrawTexture(texture, e->coordenadas.x - 50, e->coordenadas.y - 50, WHITE);
        /* DrawRectangle(e->coordenadas.x - 50, e->coordenadas.y - 50, 100, 100,
                      RED);*/
    }
    return 1;
}
