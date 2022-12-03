#include "../drivers/screen.h"
#include "util.h"

void main() {
    clear_screen();
	
    kprint_at("Welcome to cosmOS", 32, 1);
}
