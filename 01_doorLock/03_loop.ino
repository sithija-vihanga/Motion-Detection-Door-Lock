
void loop() {
  char customKey = customKeypad.getKey();

  if (customKey){
      Serial.println(customKey);
      printToOled(String(customKey));
  }
  else{
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
      printToOled("detected1");
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
       printToOled("ended2!");
      delay(100);    
      pirState = LOW;
    }
  }

}
}
