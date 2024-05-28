#include "ufo.h"

void init_ufo(Ufo *ufo)
{
    load_model(&(ufo->model), "models/ufo.obj");
    ufo->texture_id = load_texture("textures/ufot.png");

    


    ufo->pos.x = 0.0; 
    ufo->pos.y = 0.0;
    ufo->pos.z = 0.5;

    ufo->speed.x = 0.0;
    ufo->speed.y = 0.0;
    ufo->speed.z = 0.0;

    


}

void ufo_kezdop(Ufo *ufo)
{
    ufo->pos.x = 0.0;
    ufo->pos.y = 0.0;
    ufo->pos.z = 0.5;

    ufo->speed.x = 0.0;
    ufo->speed.y = 0.0;
    ufo->speed.z = 0.0;

 
}




void set_ufo_speedy(Ufo *ufo, double speed)
{
    ufo->speed.y = -speed;
}

void set_ufo_speedx(Ufo *ufo, double speed)
{
    ufo->speed.x = speed;
}

void set_ufo_speedz(Ufo *ufo, double speed)
{
    ufo->speed.z = speed;
}

void move_ufo(Ufo *ufo, double time)
{
    ufo->pos.x += ufo->speed.x * time;
    ufo->pos.y += ufo->speed.y * time;
    ufo->pos.z += ufo->speed.z * time;

}
