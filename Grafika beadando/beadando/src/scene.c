#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
   
     init_ufo(&(scene->ufo));
    

    load_model(&(scene->talaj), "models/alap.obj");
    scene->texture_id1 = load_texture("textures/ut.png");

    glBindTexture(GL_TEXTURE_2D, scene->texture_id1);


    load_model(&(scene->fold), "models/fold.obj");
    scene->texture_id2 = load_texture("textures/fu.jpg");

    glBindTexture(GL_TEXTURE_2D, scene->texture_id2);

    scene->helpt = load_texture("textures/help.png");
    
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 0.0;

    set_lighting(scene->lighting_level);
    scene->help = false;



    scene->fogColor[0] = 0.5f;
    scene->fogColor[1] = 0.5f;
    scene->fogColor[2] = 0.5f;
    scene->fogColor[3] = 1.0f;
    glEnable(GL_FOG);
    glFogf(GL_FOG_DENSITY, 0.15f);
    glFogfv(GL_FOG_COLOR, scene->fogColor);
}


 void set_lighting(float lighting_level)
{
    float ambient_light[] = { lighting_level, lighting_level, lighting_level, 1.0f };
    float diffuse_light[] = { lighting_level, lighting_level, lighting_level, 1.0f };
    float specular_light[] = { lighting_level, lighting_level, lighting_level, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}


void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{
}

void helping(GLuint tid)
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBindTexture(GL_TEXTURE_2D, tid);
    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-2.0, 2.0, -3);
    glTexCoord2f(1, 0);
    glVertex3f(2.0, 2.0, -3);
    glTexCoord2f(1, 1);
    glVertex3f(2.0, -2.0, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-2.0, -2.0, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}


void render_scene(const Scene* scene)
{
    set_material(&(scene->material));

    glPushMatrix();

    glTranslatef(scene->ufo.pos.x,scene->ufo.pos.y,scene->ufo.pos.z);
    glScalef(0.3,0.3,0.3);
    glBindTexture(GL_TEXTURE_2D, scene->ufo.texture_id);
    draw_model(&(scene->ufo.model));

    glPopMatrix();

   glPushMatrix();

    glTranslatef(0.0,0.0,-0.3);
   // glRotatef(-90, 1, 0, 0);
    glScalef(1.0,1.0,1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id1);
    draw_model(&(scene->talaj));

    glPopMatrix();


   glPushMatrix();

    glTranslatef(0.0,0.0,-1.1);
    glScalef(0.1,0.1,0.1);
    glBindTexture(GL_TEXTURE_2D, scene->texture_id2);
    draw_model(&(scene->fold));

    glPopMatrix();


    if(scene->help == true)
    {
    helping(scene->helpt);
    }    
    
    draw_origin();
    
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
