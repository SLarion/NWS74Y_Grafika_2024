#ifndef UFO_H
#define UFO_H
#include <obj/load.h>
#include <obj/draw.h>
#include "texture.h"
#include "utils.h"
#include "camera.h"
#include <stdbool.h>

typedef struct Ufo
{
    GLuint texture_id;
    Model model;
    vec3 pos;
    vec3 speed;
   

} Ufo;

void init_ufo(Ufo* ufo);

void ufo_kezdop(Ufo* ufo);


void set_ufo_speedy(Ufo* ufo, double speed);


void set_ufo_speedx(Ufo* ufo, double speed);


void set_ufo_speedz(Ufo* ufo, double speed);



void move_ufo(Ufo* ufo, double time);

#endif /*UFO_H*/
