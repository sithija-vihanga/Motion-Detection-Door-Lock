void printToOled(String text, int x, int y){
      oled.clearDisplay(); // clear display
      oled.setTextSize(2);          // text size
      oled.setTextColor(WHITE);     // text color
      oled.setCursor(10, 30);        // position to display
      oled.println(text); // text to display
      oled.display();
}


void checkPassword(){
    String pin = "";
    int cursorX = 10;

    //oled.clearDisplay(); // clear display
    printToOled("Enter pin:",0,40);
    delay(500);
    bool pinProtected = true;
    while(pinProtected){
      char customKey = customKeypad.getKey();
      if (customKey){
        if(cursorX>=58){
          if(pin == password){
            oled.clearDisplay(); // clear display
            printToOled("Access Granted!",0,15);
            delay(500);
            //doorLock(true);
            break;
          }
          else{
            oled.clearDisplay(); // clear display
            printToOled("Access Denied!",0,15);
            delay(500);
            break;
          }
        }
        if(customKey == '#'){
          oled.clearDisplay(); // clear display
          printToOled("Canceled",0,0);
          break;
        }
        else{
        Serial.println(customKey);
        printToOled(String(customKey),cursorX,20);
        pin+=customKey;
        cursorX+=12;
        Serial.println(pin);
        //Serial.println(cursorX);
        }
      }
  }
  

}


void checkIntruders(){
  val = digitalRead(inputPin);  // read input value
  
  if (val == HIGH)  // check if the input is HIGH
  {            
    digitalWrite(ledPin, HIGH);  // turn LED ON
  
    if (pirState == LOW) 
  {
      Serial.println("Motion detected!"); // print on output change
//      oled.clearDisplay(); // clear display
//      oled.setTextSize(2);          // text size
//      oled.setTextColor(WHITE);     // text color
//      oled.setCursor(10, 30);        // position to display
//      oled.println("detected!"); // text to display
//      oled.display();
      printToOled("detected1",0,20);
      delay(100);    
      pirState = HIGH;
    }
  } 
  else 
  {
    digitalWrite(ledPin, LOW); // turn LED OFF
  
    if (pirState == HIGH)
  {
      Serial.println("Motion ended!");  // print on output change
//      oled.clearDisplay(); // clear display
//      oled.setTextSize(2);          // text size
//      oled.setTextColor(WHITE);     // text color
//      oled.setCursor(10, 30);        // position to display
//      oled.println("ended!"); // text to display
//      oled.display();
       printToOled("ended2!",0,20);
      delay(100);    
      pirState = LOW;
    }
  }

  }
