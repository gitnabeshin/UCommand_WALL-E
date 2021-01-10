/**************************************************************
 //  walle_control.c
 //  IR Control for WALL-E by Raspberry Pi3 with wiringPI
 //
 //  Created by Nabeshin on 2017/05/25.
 **************************************************************/

/*
 * gcc ./wall-e_control.c -o ./wall-e_control.out -lwiringPi
 */

#include <wiringPi.h>
#include <stdio.h>      // for printf()

#define PIN_IRLED        (23)    // 赤外線LEDピン (物理PIN 16)

#define COSTOM_CODE      "1010"

#define JOYSTICK_FORWARD  "1111111011111110"
#define JOYSTICK_BACKWARD "1111110111111101"
#define BUTTON_AHEAD      "1010111010101110"
#define BUTTON_TURN       "1010110010101100"
#define BUTTON_ROTATE     "1010110110101101"
#define BUTTON_CIRCLE     "1010101110101011"
#define BUTTON_LIGHT      "1010010010100100"
#define BUTTON_DANCE      "1010011010100110"
#define BUTTON_MUSIC      "1010010110100101"
#define BUTTON_EYES       "1010011110100111"
#define BUTTON_TALK       "1010101010101010"
#define BUTTON_MECHA      "1010100110101001"

#define MENU_QUIT         "0"


/*
 Turn LED ON [num] times @44kHz, 1/3Duty
 */
void send_on(int num){
    int i=0;
    for(i = 0; i < num; i++){
        
        /*
         44kHz -> 1/44*1000(sec/clock) -> 23(usec/clock)
         1/3Duty -> ON:23*1/3=8(usec/clock), OFF:23*2/3=15(usec/clock)
         */
        digitalWrite( PIN_IRLED, 1 );  // ON
        delayMicroseconds(8);          // wait 8 usec
        digitalWrite( PIN_IRLED, 0 );  // OFF
        delayMicroseconds(15);         // wait 15 usec
    }
}

/*
 Send bit code
 1: +1500 -500
 0: +500 -1500
 */
void send_bytes(char* bytes, int byte_length){
    char* byteData = bytes;
    int i=0;
    for (i = 0; i < byte_length; i++){
        if('1' == byteData[i]){
            send_on(65);              // ON (blink 1500/23 = 22 times)
            delayMicroseconds(500);   // wait 500 usec
        } else {
            send_on(22);              // ON (blink 500/23 = 22 times)
            delayMicroseconds(1500);  // wait 1500 usec
        }
    }
}


/*
 Send Command
 */
void send_command(char* command){
    
    /* LEADER CODE signal(+6000, -2000) usec  */
    send_on(264);             // ON (blink 6000/23 = 264 times)
    delayMicroseconds(2000);  // OFF
    
    /*
     fixed data: 4 bits
     variable data: 8 bits (repeated twice)
     */
    send_bytes(COSTOM_CODE, 4);   // fix code (Fixed Size 4bit)
    send_bytes(command, 16);      // variable command(Fixed Size 16bit)
    
    /* STOP CODE signal(+2000, -****) usec */
    send_on(87);               // ON (blink 2000/23 = 87 time)
    delayMicroseconds(123500); // OFF for enough time
}

/*
 Exec Command
 */
void exec_command(int command){

    /*
     char* menuStr = "MENU \n"
     " 1: BUTTON_AHEAD\n"
     " 2: BUTTON_LIGHT\n"
     " 3: BUTTON_TURN\n"
     " 4: BUTTON_ROTATE\n"
     " 5: BUTTON_CIRCLE\n"
     " 6: BUTTON_DANCE\n"
     " 7: BUTTON_MUSIC\n"
     " 8: BUTTON_EYES\n"
     " 9: BUTTON_TALK\n"
     "10: BUTTON_MECHA\n"
     "11: JOYSTICK_FORWARD\n"
     "12: JOYSTICK_BACKWARD\n"
     " 0: QUIT\n"
     "INPUT COMMAND>";
     */
    
    switch (command) {
        case 1:
            send_command( BUTTON_LIGHT );
            send_command( BUTTON_LIGHT );
            send_command( BUTTON_LIGHT );
            delayMicroseconds(1523500); // OFF for enough time
            break;
        case 2:
            send_command( BUTTON_AHEAD );
            send_command( BUTTON_AHEAD );
            send_command( BUTTON_AHEAD );
            delayMicroseconds(1523500); // OFF for enough time
            break;
        case 3:
            send_command( BUTTON_TURN );
            send_command( BUTTON_TURN );
            send_command( BUTTON_TURN );
            delayMicroseconds(6123500); // OFF for enough time
            break;
        case 4:
            send_command( BUTTON_ROTATE );
            send_command( BUTTON_ROTATE );
            send_command( BUTTON_ROTATE );
            delayMicroseconds(6123500); // OFF for enough time
            break;
        case 5:
            send_command( BUTTON_CIRCLE );
            send_command( BUTTON_CIRCLE );
            send_command( BUTTON_CIRCLE );
            delayMicroseconds(6123500); // OFF for enough time
            break;
        case 6:
            send_command( BUTTON_MUSIC );
            send_command( BUTTON_MUSIC );
            send_command( BUTTON_MUSIC );
            delayMicroseconds(12123500); // OFF for enough time
            break;
        case 7:
            send_command( BUTTON_DANCE );
            send_command( BUTTON_DANCE );
            send_command( BUTTON_DANCE );
            delayMicroseconds(12123500); // OFF for enough time
            break;
        case 8:
            send_command( BUTTON_EYES );
            send_command( BUTTON_EYES );
            send_command( BUTTON_EYES );
            delayMicroseconds(6123500); // OFF for enough time
            break;
        case 9:
            send_command( BUTTON_TALK );
            send_command( BUTTON_TALK );
            send_command( BUTTON_TALK );
            delayMicroseconds(12123500); // OFF for enough time
            break;
        case 10:
            send_command( BUTTON_MECHA );
            send_command( BUTTON_MECHA );
            send_command( BUTTON_MECHA );
            delayMicroseconds(6123500); // OFF for enough time
            break;
        default:
            printf("NO COMMAND....\n");
            break;
    }
}

/*
 setup Wiring PI
 */
void setup(void){
    
    // Set up Wiring Pi
    wiringPiSetupGpio();
    // Set GPIO as Output
    pinMode( PIN_IRLED, OUTPUT );
}

/**
 * Main
 */
int main(int argc, const char * argv[]) {
    
    // Setup wiring Pi
    setup();

    char* menuStr = "ウォーリー　そうさメニュー \n"
    " 1: スイッチオン\n"
    " 2: 前に進む\n"
    " 3: 左に曲がる\n"
    " 4: 後ろを向く\n"
    " 5: ぐるっと１回転\n"
    " 6: いろんな音\n"
    " 7: ダンス\n"
    " 8: 起きる\n"
    " 9: しゃべる\n"
    "10: ロボットの音\n"
    " 0: 終わり\n"
    "番号を選んでください>";
    
    int command;
    
    while (1){
        printf("%s", menuStr);
        scanf("%d", &command);
        
        if(0 == command){
            break;
        }
        exec_command(command);
    }
    
    printf("bye.....\n");
    
    return 0;
}
