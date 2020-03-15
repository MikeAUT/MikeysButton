#include <MikeysButton.h>

MikeysButton TestButton1; // instantiate class with default values (debounceDelay=20, doubleClickGap=500, holdDelay=1000)

void setup() {
  pinMode(2, INPUT);
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  TestButton1.attach(2); // Defines the digital input pin the instance should look at
  TestButton1.debounceDelay(50); // Overwrites the default debounce delay (in ms), must be lower than doubleClickGap and holdDelay
  TestButton1.doubleClickGap(1000); // Overwrites the default double click gap (in ms)
  TestButton1.holdDelay(2000); // Overwrites the default hold delay (in ms)
}

void loop() {
  TestButton1.update(); // Updates the state of the input PIN, should be called in loop

  bool pressed = TestButton1.pressed(); // Returns 1 when button is pressed after debouncing, as long as the button is pressed
  bool clickedEdge = TestButton1.clickedEdge(); // Returns 1 for one program cycle after debouncing
  bool doubleClicked = TestButton1.doubleClicked(); // Returns 1 for one program cycle when button is pressed twice (after debouncing)
  bool held = TestButton1.held(); // Returns 1 when button is held and holdDelay expired as long as the button is held (after debouncing)
  bool heldEdge = TestButton1.heldEdge(); // Returns 1 for one program cycle when button is held and holdDelay expired (after debouncing)

  if (clickedEdge){
    digitalWrite(6, HIGH);
  }

  if(doubleClicked){
    digitalWrite(7, HIGH);
  }

  if(heldEdge){
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

}
