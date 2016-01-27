#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>

//PROCEDURES AND FUNCTIONS
int sign(int x1, int x2);
void initialization();
void drawHorizontalLine(int _x, int _y, int width, int weight, int red, int green, int blue);
void drawLine(int x1, int y1, int x2, int y2, int red, int green, int blue);
void setColor(int red, int green, int blue);

//GLOBAL VARIABLE
int fbfd = 0;
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long int screensize = 0;
char *fbp = 0;
int x = 0, y = 0;
long int location = 0;

int main()
{
    initialization();
    
    x = 300; y = 100;       // Where we are going to put the pixel

    // Figure out where in memory to put the pixel

    drawHorizontalLine(100,100,500,5,255,0,0);
    drawHorizontalLine(200,200,500,5,0,255,0);
    drawHorizontalLine(300,300,500,5,0,0,255);
    
    // Make an Red A
    int pos_x = 400;
    int pos_y = 400;
    int width = 50;

    drawHorizontalLine(pos_x,pos_y,width,5,255,0,0);
    int i;
    for (i = 0; i < 8; i++) {
        drawHorizontalLine(400,400,50,5,255,0,0);
    }

    drawLine(10,10,100,100,255,0,0);

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}

void initialization() {
        // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }

    printf("The framebuffer device was mapped to memory successfully.\n");


}

int sign(int x1, int x2) {
    int res;
    if (x1 > x2) {
        res = -1;
    } else {
        res = 1;
    }
    return res;
}

void drawHorizontalLine(int _x, int _y, int width, int weight, int red, int green, int blue) {
    // Figure out where in memory to put the pixel
    for (y = _y; y < weight+_y; y++) {
        for (x = _x; x < width+_x; x++) {

            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
            (y+vinfo.yoffset) * finfo.line_length;

            setColor(red,green,blue);

        }
    }
}

void drawLine(int x1, int y1, int x2, int y2, int red, int green, int blue) {
    int deltaX = abs(x1-x2);
    int deltaY = abs(y1-y2);
    double error = 0;
    int y;
    int x;

    /*if (deltaX = 0) {
        x = x1;
        for (y = y1; y < y2; y++) {
            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                (y+vinfo.yoffset) * finfo.line_length;
            setColor(red,green,blue);
        }

    } else {
*/
        double deltaerr = abs(deltaY/deltaX); //For deltaX!=0 (not a vertical line)
        y = y1;
        for (x = x1; x < x2; x++) {
            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                (y+vinfo.yoffset) * finfo.line_length;
            setColor(red,green,blue);
            error = error + deltaerr;
            while (error >= 0.5) {
                location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                (y+vinfo.yoffset) * finfo.line_length;
                setColor(red,green,blue);
                y = y + sign(y1,y2);
                error = error - 1.0;
            }        
        }

//    }
    
}

void setColor(int red, int green, int blue) {
    if (vinfo.bits_per_pixel == 32) {
        *(fbp + location) = blue;        // Blue
        *(fbp + location + 1) = green;     // Green
        *(fbp + location + 2) = red;    // Red
        *(fbp + location + 3) = 0;      // No transparency
        } 
    else  { //assume 16bpp
        int b = 10;
        int g = (x-100)/6;     // A little green
        int r = 31-(y-100)/16;    // A lot of red
        unsigned short int t = r<<11 | g << 5 | b;
        *((unsigned short int*)(fbp + location)) = t;
    }

}