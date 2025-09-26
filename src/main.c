#include <gint/display.h>
#include <gint/keyboard.h>
#include <gint/keycodes.h>
#include <gint/clock.h>
#include <unistd.h>

#define FRAMES 12
#define FRAME_DT 60000 // Microseconds

/* Linked objects */
/* super lazy, but whatever */
extern bopti_image_t f00, f01, f02, f03, f04, f05, f06, f07, f08, f09, f10, f11;

/* Variables */
bool exitProgram = false;
int frame = 0;
const bopti_image_t *frames[FRAMES] = {&f00, &f01, &f02, &f03, &f04, &f05, &f06, &f07, &f08, &f09, &f10, &f11};


static void procinput() {
	pollevent();

	if (keydown(KEY_EXIT) > 0) {
		exitProgram = true;
	}
}

static void logic() {
	frame++;

	if (frame >= FRAMES) {
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

	while (!exitProgram) {
		procinput();
		logic();
		render();

		sleep_us(FRAME_DT);
	}

	return 1;
}
