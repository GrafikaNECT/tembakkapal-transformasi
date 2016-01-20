#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <stdlib.h>

int main() {
	int fbfd = 0;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	long int screensize = 0;
	char *fbp = 0;
	int x = 0, y = 0;
	long int location = 0;
	int itest;

	/* Buka berkas untuk baca dan tulis */
	fbfd = open("/dev/fb0", O_RDWR);
	if (!fbfd) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	printf("The framebuffer device was opened successfully.\n");

	/* Memperoleh informasi layar yang tetap */
	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
	printf("Error reading fixed information.\n");
	exit(2);
	}

	/* Memperoleh informasi layar variabel */
	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
	printf("Error reading variable information.\n");
	exit(3);
	}

	/* Membuat ukuran layar dalam byte */
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	/* Pemetaan device ke memori */
	fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE,
	MAP_SHARED, fbfd, 0);
	if ((int)fbp == -1) {
	printf("Error: failed to map framebuffer device to memory.\n");
	exit(4);
	}
	printf("The framebuffer device was mapped to memory successfully.\n");
	for (itest = 0; itest < 255; itest++) {
	for (y = 0; y < 240; y++)
	{
	for (x = 0; x < 320; x++)
	{
	//x = 100; y = 100; /* Where we are going to put the pixel */

	/* Figure out where in memory to put the pixel */
	location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
	(y+vinfo.yoffset) * finfo.line_length;

	*(fbp + location) = itest; //Paint a black pixel.
	*(fbp + location + 1) = itest;
	*(fbp + location + 2) = itest;
	*(fbp + location + 3) = 0;
	}
	}
	usleep(1000);
	}

	munmap(fbp, screensize);
	close(fbfd);

	return 0;
}
