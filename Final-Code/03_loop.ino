
void loop() {
  char customKey = customKeypad.getKey();

  if (customKey){
      Serial.println(customKey);
      printToOled(String(customKey),0,30);
  }
  else{
    checkIntruders();
  }
}
