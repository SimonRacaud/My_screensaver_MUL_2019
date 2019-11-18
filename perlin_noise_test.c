/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** framebuffer Perlin Noise effect
*/

#include "framebuffer.h"
#include <time.h>

static const float unit_g = 1.0f/sqrt(2);

static const float gradient2_g[8][2] =
{
    {unit_g, unit_g},
    {-unit_g, unit_g},
    {unit_g, -unit_g},
    {-unit_g, -unit_g},
    {1, 0},
    {-1, 0},
    {0, 1},
    {0,- 1}
};

static void generate_perm(unsigned int *array, unsigned int size)
{
    unsigned int j;
    unsigned int temp;

    if (size < 2)
        return;
    for (unsigned int i = 0; i < size; i++)
        array[i] = i;
    for (unsigned int i = 0; i < size; i++) {
            j = rand() % (size - 1);
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
    }
}

void framebuffer_perlin_noise(framebuffer_t *fb)
{
    sfColor color = {0, 0, 0, 255};
    unsigned int perm[256];
    float per;

    //generate_perm(perm, 256);
    for (unsigned int y = 0; y < fb->height; y++) {
        for (unsigned int x = 0; x < fb->width; x++) {
            per = (perlin(x, y, 100, perm) + 1) / 2 * 225;
            color.r = per;
            color.g = per;
            color.b = per;
            put_pixel(fb, x, y, &color);
        }
    }
}

static void balance(sfVector2f *xy, sfVector2i *xy0, float *vector, int *gi)
{
    float tempX;
    float tempY;

    //on récupère les vecteurs et on pondère
    tempX = xy->x - xy0->x;
    tempY = xy->y - xy0->y;
    vector[0] = gradient2_g[gi[0]][0] * tempX + gradient2_g[gi[0]][1] * tempY;
    tempX = xy->x- (xy0->x + 1);
    tempY = xy->y - xy0->y;
    vector[1] = gradient2_g[gi[1]][0] * tempX + gradient2_g[gi[1]][1] * tempY;
    tempX = xy->x- xy0->x;
    tempY = xy->y - (xy0->y + 1);
    vector[2] = gradient2_g[gi[2]][0] * tempX + gradient2_g[gi[2]][1] * tempY;
    tempX = xy->x - (xy0->x + 1);
    tempY = xy->y - (xy0->y + 1);
    vector[3] = gradient2_g[gi[3]][0] * tempX + gradient2_g[gi[3]][1] * tempY;
}

static float *get_vectors_value(sfVector2f *xy, sfVector2i *xy0, int *ij,
unsigned int *perm)
{
    int gi[4];
    float *vector = malloc(sizeof(float) * 4);

    //Pour récupérer les vecteurs
    gi[0] = perm[ij[0] + perm[ij[1]]] % 8;
    gi[1] = perm[ij[0] + 1 + perm[ij[1]]] % 8;
    gi[2] = perm[ij[0] + perm[ij[1] + 1]] % 8;
    gi[3] = perm[ij[0] + 1 + perm[ij[1] + 1]] % 8;
    balance(xy, xy0, vector, gi);
    return vector;
}

static float smoothing(sfVector2f *xy, sfVector2i *xy0, float *vectors,
float *li) //Lissage
{
    float tmp;
    sfVector2f c;

    tmp = xy->x - xy0->x;
    c.x = 3 * pow(tmp, 2) - 2 * pow(tmp, 3);
    li[0] = vectors[0] + c.x * (vectors[1] - vectors[0]);
    li[1] = vectors[2] + c.x * (vectors[3] - vectors[2]);
    tmp = xy->y - xy0->y;
    c.y = 3 * pow(tmp, 2) - 2 * pow(tmp, 3);
    return c.y;
}

float perlin(float x, float y, float res, unsigned int *perm)
{
    sfVector2f xy = {x, y};
    sfVector2i xy0;
    int ij[2];
    float li[2];
    float *vectors;
    float cy;

    //Adapter pour la résolution
    xy.x /= res;
    xy.y /= res;
    //On récupère les positions de la grille associée à (x,y)
    xy0.x = (int)(xy.x);
    xy0.y = (int)(xy.y);
    //Masquage
    ij[0] = xy0.x & 255;
    ij[1] = xy0.y & 255;
    vectors = get_vectors_value(&xy, &xy0, ij, perm);
    cy = smoothing(&xy, &xy0, vectors, li);
    free(vectors);
    return li[0] + cy * (li[1] - li[0]);
}
