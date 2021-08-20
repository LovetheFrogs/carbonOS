#include "io.h"
#include "framebuffer.h"

     char *fb = (char *) 0x000B8000;
     unsigned int writing_state = 800;
     unsigned int cursor_state=400;
    void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
    {
        fb[i] = c;
        fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
    }
    
        void fb_move_cursor(unsigned short pos)
    {
        outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
        outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        outb(FB_DATA_PORT,    pos & 0x00FF);
    }
    
    int fb_write(char *buf, unsigned int len){
	    for (unsigned int i=0; i<len;i++){
	   
	      fb_write_cell((writing_state+(i*2)), *(buf+i), 0, 1);
	   	 
	   	 }
		writing_state+=len*2;
		cursor_state+=len;
		fb_move_cursor(cursor_state);
	   	 return 0;
    }
