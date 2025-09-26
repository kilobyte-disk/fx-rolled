#include <gint/display.h>
#include <gint/keyboard.h>
#include <unistd.h>

extern bopti_image_t f00;

int main(void)
{
	dclear(C_BLACK);

	dimage(0, 0, &f00);

	dupdate();

	getkey();
	return 1;
}
