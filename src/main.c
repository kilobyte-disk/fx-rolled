#include <gint/display.h>
#include <gint/keyboard.h>
#include <gint/keycodes.h>
#include <gint/clock.h>
#include <unistd.h>
#include <bool.h>

#define FRAMES 12
#define FRAME_DT 40000 // Microseconds

/* Linked objects */
/* super lazy, but whatever */
extern bopti_image_t f00, f01, f02, f03, f04, f05, f06, f07, f08, f09, f10, f11;

/* Variables */
bool exit = false;
int frame = 0;
static *bopti_image_t frames[FRAMES] = {&f00, &f01, &f02, &f03, &f04, &f05, &f06, &f07, &f08, &f09, &f10, &f11};


static void procinput() {
	if (keydown(KEY_EXIT) > 0) {
		exit = true;
	}
}

static void logic() {
	frame++;

	if (frame > FRAMES) {
		frame = 0;
	}
}

static void render() {
	dclear(C_BLACK);

	/* 384x216 resolution */
	/* image 220x220 */
	dimage(82, 0, frames[frame]);

	dupdate();
}

int main(void)
{
	dclear(C_BLACK);

	do
	{
		procinput();
		logic();
		render();

		sleep_us(FRAME_DT);
	}
	while (!exit);

	return 0;
}
