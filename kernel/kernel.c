#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../user/libc/string.h"
#include "../user/libc/mem.h"

#include "../user/user.h"

#include <stdint.h>

char *systemCommands[] = {"end", "page"};
int numUserCommands = 2;
char *userCommands[] = {"echo", "info"};

void kernel_main() {
    clear_screen(); // this sets the stage and starts the blinking cursor
    
    isr_install();
    irq_install(); // this enables the keyboard input

    asm("int $2");
    asm("int $3");

    //kprint("Welcome To Peanut OS \n> ");
    kprint("\n> ");
}

void user_input(char *input) {
    if (strcmp(input, "end") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    } else if (strcmp(input, "page") == 0) {
        /* Lesson 22: Code to test kmalloc, the rest is unchanged */
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
    }
    else if (strcmp(input, "info") == 0) {
	    kprint("Peanut OS\nVersion 0.0\nWritten by James Park"); 		
	}

    char *command = strtok(input, ' ');
    
    int i;
    for (i = 0; i < numUserCommands; i++) {
        if (strcmp(command, userCommands[i]) == 0) {
            //kprint(splitStr(input, strlen(command)+1));
            char *asd = splitStr("asd", 7);
            kprint(asd);
            break;
            //parseUser(command, "asd");
        }
    } 
    kprint("\n> ");
}
