#include "shell.h"
#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../libc/string.h"
#include "../libc/mem.h"

#include <stdint.h>

void shell() {
    clear_screen(); // this sets the stage and starts the blinking cursor
    
    isr_install();
    irq_install(); // this enables the keyboard input

    asm("int $2");
    asm("int $3");

    kprint("\n> ");
}

void user_input(char *input) {
    if (strcmp(input, "end") == 0) {
      haltCPU();
    } else if (strcmp(input, "page") == 0) {
      page();
    }
    else if (strcmp(input, "info") == 0) {
	    kprint("Peanut OS\nVersion 0.0\n"); 		
	  }
    if (strcmp(input, "echo") == 0) {
      // todo		
	  }

    kprint("\n> ");
}
