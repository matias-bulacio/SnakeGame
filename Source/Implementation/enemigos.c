#include <enemigos.h>

void Enemigo_Avanzar(Enemigo *e, int velocidad, float frame_time) {
	e->coordenadas.y += velocidad * frame_time;
}
