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
    int x = 0, y = 0;

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
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        return 4;
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

}

int finishPrinter(){
	close(fbfd);
	return 0;
}

void printChar(char a, int X, int Y, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha){
    long int location = 0;
// Figure out where in memory to put the pixel
    for (y = Y; y < charpixmatrix_height; y++)
        for (x = X; x < charpixmatrix_width; x++) {

            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset) * finfo.line_length;

            if (vinfo.bits_per_pixel == 32) {
                *(fbp + location) = B;        // Some blue
                *(fbp + location + 1) = G;     //  green
                *(fbp + location + 2) = R;    //  red
                *(fbp + location + 3) = alpha;      // alpha
        //location += 4;
            } else  { //assume 16bpp
                int b = B/8;
                int g = G/8;     // A little green
                int r = R/8;    // A lot of red
                unsigned short int t = r<<11 | g << 5 | b;
                *((unsigned short int*)(fbp + location)) = t;
            }

        }
    munmap(fbp, screensize);
}

void hapusScreen(){
	int i;
	for (i=0;i<screensize;i++){
		*(fbp+i)=0;
	}
}
