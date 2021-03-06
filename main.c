/************************************
 * #pragma directives...
************************************/
#pragma config FEXTOSC = HS
#pragma config RSTOSC = EXTOSC_4PLL 
#pragma config WDTE = OFF        

/************************************
 * #include directives...
 ************************************/
#include <xc.h>

/************************************
 * #define directives...
 ************************************/
#define _XTAL_FREQ 64000000 

/************************************
/ main function
 * ...
************************************/
void main(void) {    
    // setup pin for output (connected to LED)
    LATDbits.LATD7=0;   //set initial output state
    TRISDbits.TRISD7=0; //set TRIS value for pin (output)
    
    // setup pin for output (connected to LED)
    LATHbits.LATH3=0;   //set initial output state
    TRISHbits.TRISH3=0; //set TRIS value for pin (output)
    
    // setup pin for input (connected to left button)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin  
    
    // setup pin for input (connected to right button)
    TRISFbits.TRISF3=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF3=0; //turn off analogue input on pin 
    
    while (1) { //infinite while loop - repeat forever
        
        while (PORTFbits.RF2 && PORTFbits.RF3); //empty while loop (wait for either button press)
        
        if (!PORTFbits.RF2)
        {   LATDbits.LATD7 = !LATDbits.LATD7;} //toggle LED
        
        if (!PORTFbits.RF3)
        {   LATHbits.LATH3 = !LATHbits.LATH3;} //toggle other LED

        __delay_ms(200); // call built in delay function 
    }
}