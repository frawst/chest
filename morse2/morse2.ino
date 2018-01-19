// BEGIN SKETCH
// (c) 2018 Justyn Chaykowski
//  CS207 UofR Student ID 200 320 034
//
//  DISCLAIMER
//  #####################################
//
//  USE OF THIS PROGRAM FOR ANYTHING OTHER THAN EDUCATIONAL PURPOSES
//  IS STRICTLY FORBIDDEN. IF YOU ARE A CLASSMATE WHO HAS STUMBLED ONTO
//  THIS PROJECT BEFORE IT WAS UPLOADED TO THE CLASS REPOSITORY
//  PLEASE BE WARNED THAT ALL THIS CODE HAS BEEN UPLOADED TO A PUBLIC
//  SERVER WHICH TRACKS THE DATE, TIME, AND ALL CHANGES THAT HAVE BEEN
//  MADE TO THE CODE -- COPYING MY WORK WILL NOT BE TOLERATED.
//
//  IF THE CODE FOUND WITHIN THIS SOFTWARE IS SAFE TO ITERATE IN YOUR OWN
//  PORJECTS IT WILL BE AVAILABLE AT GITHUB.COM/FRAWST/CS207-CHAYKOWJ
//  AND THIS TEXT WILL NOT BE VISIBLE.
//
//  IF YOU RETRIEVED THIS FROM ANYWHERE ELSE, DO NOT READ FURTHER
//  OR RISK ACADEMIC CONSEQUENCES.
//
// #####################################################
//
//  OTHER NOTES:
//
//  This code used to create one long string of 1's and 0's representing
//  morse code in one function, and then it would pass that string
//  to another function which would blink the message out in it's entirety.
//  This did not work, and was a difficult problem to solve. However,
//  once I realized that the string was overflowing memory at a certain point
//  I came up with this new solution, which instead of building a large string
//  to send to the blinker, it instead sends the morse in tiny snippits while
//  the conversion is still occurring -
//  each snippit represents a small piece of the morse message, including
//  character terminator's, characters, and spaces.
//
//  This software MAY be FURTHER OPTIMIZED by removing the morseAlphabet
//  and alphaAlphabet lists and instead checking the input String for
//  contents, and converting to morse in a large if/else if block.
//  Instead of iterating through the lists, we would instead check if the
//  current character matches any letter/marking we can replicate in
//  morse ONE by ONE (is A? is B? is C? etc.) and when the match is found,
//  directly pass the morse for that letter to the blinker function INSTEAD
//  of storing it as a variable.  HOWEVER, this may or may not do anything
//  since the strings may not be any more memory efficient by not being
//  declared as variables since the function itself likely reserves that memory
//  for those constants.
//
//  TODO: Test the above optimization when it's not too late at night for this.
//
// IF YOU READ NOTHING ELSE PLEASE READ THE REST OF THIS COMMENT BLOCK <<<<
//
//  Some extensive testing with tools which I do not own would be required
//  to determine whether or not the LED message being blinked out is being
//  blinked in the appropriate time scaling - however - a timer output
//  from the code seems to indicate that if the timing is off at all,
//  it is off by too small of a margin for a human mind to interpret the
//  difference.
//  #########################################################
//
//  FUNCTIONALITY
//  #########################
//
//  This program will blink a given input string as morse code to the given
//  LED, defined as systemLED.
//
//  This program will blink slowly and then very quickly to indicate that
//  the morse message is about to start. The light will then go dark until
//  the morse message begins. Once the morse message has ended the light will
//  remain dark.
//
//  TO USE THIS PROGRAM
//    - Scroll down to the DEFINING GLOBAL VARIABLES line
//    - Alter stringToConvert and morseCodeTiming to suit your needs
//
//  stringToConvert = the string which will be converted to morse.
//  morseCodeTiming = amount of time in ms between each tick of morse
//                    or in other words, morseCodeTiming*1 = a dot
//                    and morseCodeTiming*3 = a dash.
//
//  You may also wish to alter the line #define systemLED &&&&
//  to better suit your current arduino arrangement.
//  This variable is explained below, and is set to the arduino
//  LED_BUILTIN by default!

// TODO: Implement a system where if more than one LED is provided, then
//       one LED will serve as a 'working' and 'wait' LED, while the other
//       provides all the actual data output.

// systemLED will refer to the primary output LED for the program.
// This is set to LED_BUILTIN by default but may be changed to suit
// your particular needs.

#define systemLED LED_BUILTIN

// DECLARING GLOBAL LISTS

char alphaAlphabet[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
  'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  '.', ',', '?', '/', '@', ' '
};

String morseAlphabet[] = {
  "10111", "111010101", "11101011101", "1110101", "1",
  "101011101", "111011101", "1010101", "101", "1011101110111",
  "111010111", "101110101", "1110111", "11101", "11101110111",
  "10111011101", "1110111010111", "1011101", "10101", "111",
  "1010111", "101010111", "101110111", "11101010111",
  "1110101110111", "11101110101", "1110111011101110111",
  "10111011101110111", "101011101110111", "1010101110111",
  "10101010111", "101010101", "11101010101", "1110111010101",
  "111011101110101", "11101110111011101", "10111010111010111",
  "1110111010101110111", "101011101110101", "1110101011101",
  "10111011101011101", "0000"
};


// DECLARING AND BUILDING FUNCTIONS

void toMorse(String strToConvert, int timer){
  // Moves through an input string one character at a time, checking
  // for that character in alphaAlphabet which is paired up with
  // morseAlphabet character for character. The index of the alphabetic
  // character found is used to send one of the strings inside
  // morseAlphabet to the LED blinker function blinkCodeBit which will
  // blink out the morse according to the parameters set in the GLOBAL
  // VARIABLE declarations below.
  
  // For each char in string
  for (int h = 0; h < strToConvert.length(); h++){
    for (int i = 0; i < sizeof(alphaAlphabet); i++){
      
      // Is character h the same as this index of the alphabet?
      if (strToConvert.charAt(h) == alphaAlphabet[i]){
        
        // Then notify my by Serial and blink the morse
        Serial.println("Blinking: " + String(strToConvert.charAt(h)));
        blinkCodeBit(morseAlphabet[i], timer);
        
        // If this is not the last character, then also blink the next char code
        if ((h < strToConvert.length() - 1) && (strToConvert.charAt(h) != ' ')){
          blinkCodeBit("000", timer);
        }
        continue;  // Move to next character in input string
      }
    }
  }
}

void blinkCodeBit(String code, int timer){
  Serial.println(code);
  for (int i = 0; i < code.length(); i++){
    if (code.charAt(i) == '0'){
      digitalWrite(systemLED, LOW);
    }
    if (code.charAt(i) == '1'){
      digitalWrite(systemLED, HIGH);
    }
    delay(timer);
  }
}


void blinkyWait(int ms, int del){
  int loops = (ms / del) / 2;
  for (int i = 0; i < loops; i++){
    digitalWrite(systemLED, HIGH);
    delay(del);
    digitalWrite(systemLED, LOW);
    delay(del);
  }
  
  for (int i = 0; i < 30; i++){
    digitalWrite(systemLED, HIGH);
    delay(25);
    digitalWrite(systemLED, LOW);
    delay(25);
  }
  delay(2000);
}

// DECLARING GLOBAL VARIABLES #######################################

// ALTER THESE TO ALTER THE OUTPUT  <<<<<<<<

String stringToConvert = "JUST TESTING A MUCH LONGER OUTPUT WITH THE NEW OUTPUT SYSTEM WHICH SHOULD CONSERVE MEMORY.";
int morseCodeTiming = 100;

// END GLOBAL VARIABLES ############################################

// BEGIN ARDUINO CODE ###
void setup() {
  // Initialize serial port for serial debugging
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  stringToConvert.toUpperCase();  // Ensure the String provided is stored in uppercase
  pinMode(systemLED, OUTPUT);  // Ensure the systemLED is ready to output
}

void loop() {
  // Sends the 'message about to start' blinks with blinkyWait()
  // and then begins converting input string with toMorse()
  // which uses blinkCodeBit() to actually send the morse
  // pulses.
  
  blinkyWait(2500, 500);
  toMorse(stringToConvert, morseCodeTiming);
  Serial.println("DONE.");
  digitalWrite(systemLED, LOW);
  while (true); // Do nothing.
}
