//////////////////
//  Arduino sketch for Pro Arduino 
//  Chaper 7 Example 1.0 
int button = 8 , ledPin = 13 ;                   //pin assignments: push button on pin 13 LED on pin 2  
boolean oldState = 0 , newState = 0;             //state change variables 
void setup() { 
    pinMode(button, INPUT);                      // set pin I/O types 
    pinMode(ledPin,OUTPUT); 
    Serial.begin(9600);                          //starts serial at baud rate 9600 8N1 No flow control
} // end setup()
void loop() { 
    newState = digitalRead(button);         // save curent button state 
       if(newState != oldState){            //Test for change in button state   
         if (newState  == true)             // For button press send the h character to the serial
            Serial.print('h');  
        if (newState  == false)      // For button release send the l character to the serial  
            Serial.print('l');      
     }//end if(state0 != state1)
    oldState = newState;          //Save new state to old state for comparison
}//end void loop() 
void serialEvent() {
 switch (Serial.read()){
            case 'a': digitalWrite(ledPin, 1);
                 break;
            case 's': digitalWrite(ledPin, 0);
                 break;
 }
 
}
