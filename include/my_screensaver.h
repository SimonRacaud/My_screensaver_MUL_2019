/*
** EPITECH PROJECT, 2019
** my_screensaver_2019
** File description:
** header
*/

#ifndef H_MY_SCREENSAVER
#define H_MY_SCREENSAVER

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "framebuffer.h"

#define TITLE_W "My Screensave Simon RACAUD"
#define ERR_PARA "\033[31m./my_screensaver: bad arguments: 0 given but 1 is \
required\nretry with -h\n\033[0m"
#define MAX_ID 8

static const int FRAMERATE = 60;
static const int W_WIDTH = 1920;
static const int W_HEIGHT = 1080;

typedef struct window {
    sfRenderWindow *window;
    framebuffer_t *fb;
    framebuffer_t *fb2;
    framebuffer_t *fb3;
    framebuffer_t *fb4;
    int nb_fb;
    unsigned int height;
    unsigned int width;
} window_t;

void usage(void);
void description(void);
int check_get_id(char *str);

window_t *create_window(int nb_fb);
int create_framebuffer(window_t *w);
void destroy_window(window_t *w);
void destroy_framebuffer(window_t *w);

void event_manager(window_t *w, sfEvent *e);
int run(int id);

int run01(void);
int run02(void);
int run03(void);

#endif
