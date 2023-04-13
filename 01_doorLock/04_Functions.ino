void printToOled(String text){
      oled.clearDisplay(); // clear display
      oled.setTextSize(2);          // text size
      oled.setTextColor(WHITE);     // text color
      oled.setCursor(10, 30);        // position to display
      oled.println(text); // text to display
      oled.display();
}
