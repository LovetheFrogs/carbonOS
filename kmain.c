#include "drivers/framebuffer.h"
#include "drivers/serial_port.h"
#include "segmentation/memory_segments.h"
#include "interrupts/keyboard.h"
#include "interrupts/interrupts.h"
#include "user_mode/start_program.h"
#include "paging.h"


/*function to intialize interrupts and segments*/
void init(){
	segments_install_gdt();
	interrupts_install_idt();
	enable_paging();

}

/*kernal main funcion*/
void kmain(){

	init();   //initialize interrunpts and segments
	//run_custom_program(ebx);      //run the user program


}
