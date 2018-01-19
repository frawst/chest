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
//  FUNCTIONALITY
//  #########################
//
//  NOTE: THIS PROGRAM HAS A MAJOR MEMORY OVERFLOW ISSUE.
//        The problem is solved in a later iteration of this code.
//        Knowing what problem you are looking for, see if you can't
//        find and solve the bug! I'll be surprised if more of you
//        didn't encounter the same issue with your code - and if you
//        are managing to debug it by looking at this - then awesome!
//        
//        Try having this code convert a very long string into morse and
//        see what happens. :P 
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
//  #########################################################

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

String toMorse(String strToConvert){
  // This function will convert strToConvert to a string of 1's and 0's
  // representing morse code, where each 1 is one unit of 'on', and each
  // 0 is one unit of 'off'. This function will account for all spaces,
  // punctuation, and next-character codes.
  
  String strConverted;  // Will hold the morse code as it is built
  // For each char in string
  for (int h = 0; h < strToConvert.length(); h++){
    //Serial.println(String(strToConvert.length()));
    //Serial.println("DEBUG: string step: " + String(h));
    // is Char part of the alphabet?
    for (int i = 0; i < sizeof(alphaAlphabet); i++){
      if (strToConvert.charAt(h) == alphaAlphabet[i]){
        //Serial.println("DEBUG: Character matched.");
        // Add morse equiv of char to output, and send some debug text to serial.
        //Serial.println("Converting: " + String(strToConvert.charAt(h)) + " == " + alphaAlphabet[i]);
        
        strConverted += morseAlphabet[i];
        // If this is not the last character, then append the 'next char' code
        if ((h < strToConvert.length() - 1) && (strToConvert.charAt(h) != ' ')){
          strConverted += "000";
        }
        // Output some final debug code, then move onto the next character.
        //Serial.println("DEBUG: " + String(strToConvert.charAt(h)) + " converted to: " + morseAlphabet[i]);
        //Serial.println("DEBUG: Output string at step " + String(h) + ": " + strConverted);
        continue;
      }
    }
  }
  // All characters have been checked and (hopefully) converted. Return the
  // final output string.
  Serial.println("DEBUG: returning " + strConverted);
  return strConverted;
}


void blinkMorseCode(String code, int timer){
  for (int i = 0; i < code.length(); i++){
    if (code.charAt(i) == '0'){
      digitalWrite(systemLED, LOW);
    }
    if (code.charAt(i) == '1'){
      digitalWrite(systemLED, HIGH);
    }
    delay(timer);
  }
  digitalWrite(systemLED, LOW);
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
  delay(1000);
}

// DECLARING GLOBAL VARIABLES #######################################

String stringToConvert = "Justyn";
int morseCodeTiming = 100;

// END GLOBAL VARIABLES ############################################

// BEGIN ARDUINO CODE ###
void setup() {
  // Initialize serial port for serial debugging
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  // Ensure the String provided is stored in uppercase
  stringToConvert.toUpperCase();
  // Ensure the systemLED is ready to output
  pinMode(systemLED, OUTPUT);
}

void loop() {
  // Converts the given string to morse, outputs some debug text to Serial, then
  // uses blinkyWait() to indicate that the morse code is about to begin,
  // then calls blinkMorseCode to blink out the message in morse, using
  // morseCodeTiming to determine how long between blinks.
  
  String stringToOutput = toMorse(stringToConvert);
  Serial.println("String to convert: " + stringToConvert);  // Debug output
  Serial.println("String converted: " + stringToOutput);  // Debug output
  blinkyWait(5000, 500);
  blinkMorseCode(stringToOutput, morseCodeTiming);
  while (true); // Do nothing.
}
