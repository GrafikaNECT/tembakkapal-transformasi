#include "printchar.h"
#include "char.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

//global variables
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    long int location = 0;

int initializePrinter(){

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        return 1;
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        return 2;
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        return 3;
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = finfo.smem_len;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        return 4;
    }
    printf("The framebuffer device was mapped to memory successfully.\n");
    printf("%d", vinfo.xres*vinfo.yoffset);
}

int finishPrinter(){
    munmap(fbp, screensize);
	close(fbfd);
}

void printChar(char a, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha){

	charpixmatrix_type pixelmatrix = getcharpixmatrix(a);
    long int location = 0;

    int i = 0, x = X, k, l;

    // Figure out where in memory to put the pixel
    while (i < charpixmatrix_width) {        
        int j = 0, y = Y;
            while (j < charpixmatrix_height) {
                location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                           (y+vinfo.yoffset) * finfo.line_length;
                
                for (k = 0; k < size; ++k) {
                    if (pixelmatrix.tab[j][i]) {
                        if (vinfo.bits_per_pixel == 32) {
                            *(fbp + location) = B;        // Some blue
                            *(fbp + location + 1) = G;     // A little green
                            *(fbp + location + 2) = R;    // A lot of red
                            *(fbp + location + 3) = alpha;      // No transparency
                        } else  { //assume 16bpp
                            int b = B/8;
                            int g = G/8;     // A little green
                            int r = R/8;    // A lot of red
                            unsigned short int t = r<<11 | g << 5 | b;
                            *((unsigned short int*)(fbp + location)) = t;
                        }
                    }
                    location = location + (1+vinfo.xoffset) * (vinfo.bits_per_pixel/8);
                }
                j++;
                y++;
            }
            i++;
            x++;
    }
}

void hapusScreen(){
    int x = 0, y = 0;       // Where we are going to put the pixel

    // Figure out where in memory to put the pixel
    for (y = 0; y < vinfo.yres; y++)
        for (x = 0; x < vinfo.xres; x++) {

            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset) * finfo.line_length;

            if (vinfo.bits_per_pixel == 32) {
                *(fbp + location) = 255;        // Some blue
                *(fbp + location + 1) = 255;     // A little green
                *(fbp + location + 2) = 255;    // A lot of red
                *(fbp + location + 3) = 255;      // No transparency
            } else  { //assume 16bpp
                int b = 0;
                int g = 0;     // A little green
                int r = 0;    // A lot of red
                unsigned short int t = r<<11 | g << 5 | b;
                *((unsigned short int*)(fbp + location)) = t;
            }

        }
}
