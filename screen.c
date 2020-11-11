#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

#define DEFAULT_FRAMEBUFFER "/dev/fb0"
#define DEFAULT_TTY_DEV "/dev/tty"

//https://github.com/BartekLew/fblib/blob/fb-example/fbgrad.c

int framebuffersize = 0, 
    fbfd = 0, ttyfd = 0;
struct fb_fix_screeninfo fixinfo;
struct fb_var_screeninfo varinfo;
struct pixel_rgb {
    u_int8_t red;
    u_int8_t green;
    u_int8_t blue;
};
char *buffer = NULL;

void init();
void init_fb();
void print_fb_var();
void empty();
void sync_buffer();
void light();
int fill_pixel(struct pixel_rgb pixel);
void fill_color(struct pixel_rgb pixel);

int main()
{
    init();
    print_fb_var();
    // empty();
    light();
    while(1){
        // printf("OK\n");
        light();
        sleep(1);
        // struct pixel_rgb pixel;
        // pixel.red = 255;
        // pixel.blue = 255;
        // pixel.green = 255;
        // fill_color(pixel);
        // empty();
    };
    if (ioctl (ttyfd, KDSETMODE, KD_TEXT) == -1)
        printf("Не могу установить текстовый режим");
}


void init(){
    ttyfd = open(DEFAULT_TTY_DEV, O_RDWR);
    if(ioctl (ttyfd, KDSETMODE, KD_GRAPHICS) == -1)
        printf("Не могу установить графический режим");
    fbfd = open(DEFAULT_FRAMEBUFFER, O_RDWR | O_SYNC | O_TRUNC);

    if(fbfd > 0)
        init_fb();
    else
        printf("Ошибка открытия файла\n");
}

void init_fb(){
    ioctl(fbfd, FBIOGET_FSCREENINFO, &fixinfo);
    ioctl(fbfd, FBIOGET_VSCREENINFO, &varinfo);

    framebuffersize = varinfo.xres * varinfo.yres * (int)(varinfo.bits_per_pixel/8);

    if(buffer != NULL)
        free(buffer);

    buffer = (void*)malloc(framebuffersize);
}

void print_fb_var(){
    struct fb_fix_screeninfo fixinfo;
    struct fb_var_screeninfo varinfo;

    ioctl(fbfd, FBIOGET_FSCREENINFO, &fixinfo);
    ioctl(fbfd, FBIOGET_VSCREENINFO, &varinfo);

    printf("Уствройство : %s\n", fixinfo.id);
    printf("Ширина : %d\n", varinfo.xres);
    printf("Высота : %d\n", varinfo.yres);
    printf("Виртуальная ширина : %d\n", varinfo.xres_virtual);
    printf("Виртуальная высота : %d\n", varinfo.yres_virtual);
    printf("Размер фреймбуфера : %d\n", framebuffersize);
    printf("Смещение зеленого : %d\n", varinfo.green.offset);
    printf("Длина зеленого : %d\n", varinfo.green.length);
    printf("Смещение красного : %d\n", varinfo.red.offset);
    printf("msb красного : %d\n", varinfo.red.msb_right);
    printf("Длина красного : %d\n", varinfo.red.length);
    printf("Смещение синего : %d\n", varinfo.blue.offset);
    printf("Длина синего : %d\n", varinfo.blue.length);
    printf("msb синего : %d\n", varinfo.blue.msb_right);

    if(varinfo.grayscale == 1)
        printf("Монохромный режим\n");
    else
        printf("Цветной режим\n");

    printf("Смещение прозрачности : %d\n", varinfo.transp.offset);
    printf("Длина прозрачности : %d\n", varinfo.transp.length);
    printf("msb прозрачности : %d\n", varinfo.transp.msb_right);
    printf("Количество бит на пиксель : %d\n", varinfo.bits_per_pixel);
    printf("Отступ X: %d\n", varinfo.xoffset);
    printf("Отступ Y: %d\n", varinfo.yoffset);
    printf("Аддресс memory mapped %d.\n Длина memory mapped %d\n", fixinfo.mmio_start, fixinfo.mmio_len);
}

void empty(){
    struct pixel_rgb pixel;

    pixel.red = 0;
    pixel.green = 0;
    pixel.blue = 0;

    fill_color(pixel);
}

void light(){
    struct pixel_rgb pixel;

    pixel.red = 255;
    pixel.green = 255;
    pixel.blue = 255;

    fill_color(pixel);
}

void fill_color(struct pixel_rgb pixel){
    memset(buffer, fill_pixel(pixel), framebuffersize);
    sync_buffer();
}

int fill_pixel(struct pixel_rgb pixel){
    return 
        ((u_int32_t)(pixel.red >> (8 - varinfo.red.length)) << varinfo.red.offset) | 
        ((u_int32_t)(pixel.green >> (8 - varinfo.green.length)) << varinfo.green.offset) |
        ((u_int32_t)(pixel.blue >> (8 - varinfo.blue.length)) << varinfo.blue.offset)
    ;
}

void sync_buffer(){
    int len_write = write(fbfd, (void *)buffer, (ssize_t)framebuffersize);
    
    sync();
    ioctl(fbfd, FBIOPAN_DISPLAY);
    if(len_write && NULL)
        perror("error: ");
}
