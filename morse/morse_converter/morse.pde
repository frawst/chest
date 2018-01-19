class Morse{
  
  /*
  a = 0
  z = 25
  1 = 26
  2 = 27
  9 = 34
  0 = 35
  */

  String[] morse_alphabet = {"1 111", "111 1 1 1", "111 1 111 1", "111 1 1", "1", "1 1 111 1", "111 111 1", "1 1 1 1", "1 1",
                            "1 111 111 111", "111 1 111", "1 111 1 1", "111 111", "111 1", "111 111 111", "1 111 111 1",
                            "111 111 1 111", "1 111 1", "1 1 1", "111", "1 1 111", "1 1 1 111", "1 111 111", "111 1 1 111",
                            "111 1 111 111", "111 111 1 1", "1 111 111 111 111", "1 1 111 111 111", "1 1 1 111 111",
                             "1 1 1 1 111", "111 1 1 1 1", "111 111 1 1 1", "111 111 111 1 1", "111 111 111 111 1",
                             "111 111 111 111 111"};
                             
 String letter_spacer = "   ";
 String word_spacer = "       ";
  
  Morse(){
    // some code
  }
  
  String pulse(String message){
    String morse_string = "";
    message = message.toLowerCase();
    for (int i = 0; i < message.length(); i++){
      if (message.charAt(i) == 'a'){morse_string = morse_string + morse_alphabet[0] + letter_spacer;}
      else if (message.charAt(i) == 'a'){morse_string = morse_string + morse_alphabet[0] + letter_spacer;}
      else if (message.charAt(i) == 'b'){morse_string = morse_string + morse_alphabet[1] + letter_spacer;}
      else if (message.charAt(i) == 'c'){morse_string = morse_string + morse_alphabet[2] + letter_spacer;}
      else if (message.charAt(i) == 'd'){morse_string = morse_string + morse_alphabet[3] + letter_spacer;}
      else if (message.charAt(i) == 'e'){morse_string = morse_string + morse_alphabet[4] + letter_spacer;}
      else if (message.charAt(i) == 'f'){morse_string = morse_string + morse_alphabet[5] + letter_spacer;}
      else if (message.charAt(i) == 'g'){morse_string = morse_string + morse_alphabet[6] + letter_spacer;}
      else if (message.charAt(i) == 'h'){morse_string = morse_string + morse_alphabet[7] + letter_spacer;}
      else if (message.charAt(i) == 'i'){morse_string = morse_string + morse_alphabet[8] + letter_spacer;}
      else if (message.charAt(i) == 'j'){morse_string = morse_string + morse_alphabet[9] + letter_spacer;}
      else if (message.charAt(i) == 'k'){morse_string = morse_string + morse_alphabet[10] + letter_spacer;}
      else if (message.charAt(i) == 'l'){morse_string = morse_string + morse_alphabet[11] + letter_spacer;}
      else if (message.charAt(i) == 'm'){morse_string = morse_string + morse_alphabet[12] + letter_spacer;}
      else if (message.charAt(i) == 'n'){morse_string = morse_string + morse_alphabet[13] + letter_spacer;}
      else if (message.charAt(i) == 'o'){morse_string = morse_string + morse_alphabet[14] + letter_spacer;}
      else if (message.charAt(i) == 'p'){morse_string = morse_string + morse_alphabet[15] + letter_spacer;}
      else if (message.charAt(i) == 'q'){morse_string = morse_string + morse_alphabet[16] + letter_spacer;}
      else if (message.charAt(i) == 'r'){morse_string = morse_string + morse_alphabet[17] + letter_spacer;}
      else if (message.charAt(i) == 's'){morse_string = morse_string + morse_alphabet[18] + letter_spacer;}
      else if (message.charAt(i) == 't'){morse_string = morse_string + morse_alphabet[19] + letter_spacer;}
      else if (message.charAt(i) == 'u'){morse_string = morse_string + morse_alphabet[20] + letter_spacer;}
      else if (message.charAt(i) == 'v'){morse_string = morse_string + morse_alphabet[21] + letter_spacer;}
      else if (message.charAt(i) == 'w'){morse_string = morse_string + morse_alphabet[22] + letter_spacer;}
      else if (message.charAt(i) == 'x'){morse_string = morse_string + morse_alphabet[23] + letter_spacer;}
      else if (message.charAt(i) == 'y'){morse_string = morse_string + morse_alphabet[24] + letter_spacer;}
      else if (message.charAt(i) == 'z'){morse_string = morse_string + morse_alphabet[25] + letter_spacer;}
      else if (message.charAt(i) == '1'){morse_string = morse_string + morse_alphabet[26] + letter_spacer;}
      else if (message.charAt(i) == '2'){morse_string = morse_string + morse_alphabet[27] + letter_spacer;}
      else if (message.charAt(i) == '3'){morse_string = morse_string + morse_alphabet[28] + letter_spacer;}
      else if (message.charAt(i) == '4'){morse_string = morse_string + morse_alphabet[29] + letter_spacer;}
      else if (message.charAt(i) == '5'){morse_string = morse_string + morse_alphabet[30] + letter_spacer;}
      else if (message.charAt(i) == '6'){morse_string = morse_string + morse_alphabet[31] + letter_spacer;}
      else if (message.charAt(i) == '7'){morse_string = morse_string + morse_alphabet[32] + letter_spacer;}
      else if (message.charAt(i) == '8'){morse_string = morse_string + morse_alphabet[33] + letter_spacer;}
      else if (message.charAt(i) == '9'){morse_string = morse_string + morse_alphabet[34] + letter_spacer;}
      else if (message.charAt(i) == '0'){morse_string = morse_string + morse_alphabet[35] + letter_spacer;}
      else if (message.charAt(i) == ' '){morse_string = morse_string + word_spacer;}
      else { println("Unrecognized Character"); }
    }
    return morse_string;
  }
  
}