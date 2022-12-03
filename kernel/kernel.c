#include "../drivers/screen.h"
#include "util.h"

void main() {
    clear_screen();
	
    kprint_at("Welcome to Peanut OS", 32, 1);
}
