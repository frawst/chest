Morse morse = new Morse();
String morse_code = "";
int step = 0;
boolean quit = false;
int quit_step;
String message = "My Name is Camry";  // Modify this to change what is converted to morse

void setup() {
  
  size(400, 800);
  fill(255, 255, 255);
  stroke(0, 0, 0);
  morse_code = morse.pulse(message);
  //println(morse_code);
  //println(morse_code.length());
  textSize(14);
  //noLoop();
}


void draw() {
  
  if (quit == true){delay(3000); exit();}
  
  background(0);
  fill(115, 200, 115);
  text("Message: " + message, 30, 30);
  text("Message as morse: ", 30, 330);
  text(morse_code.substring(0, step), 30, 360, 340, 440);
  if (step < morse_code.length()) {
    if (morse_code.charAt(step) == '1') {
      fill(255);
    } else if (morse_code.charAt(step) == ' ') {
      fill(0);
    } else {
      println("Unexpected behaviour");
    }
    rect(100, 100, 200, 200);
    //println(morse_code);
    step += 1;
    //println(step);
    delay(100);
  }
  
  if (step == morse_code.length()) {
    fill(115, 200, 115);
    text("Done. Quitting in 3 seconds.", 30, 90);
    println("quitting.");
    quit = true;
  }

}