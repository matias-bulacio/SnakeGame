#pragma once

#include <raylib.h>
typedef struct {
	Vector2 coordenadas;
} Enemigo;

void Enemigo_Avanzar(Enemigo *e, int velocidad, float frame_time);
