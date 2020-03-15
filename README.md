# MikeysButton
Arduino library which provides debouncing of digital inputs and also and also double presses, rising edges and helds

## Usage
**MikeysButton SomeButton;**

instantiate class with default values (debounceDelay=20, doubleClickGap=500, holdDelay=1000)

**void attach(int pin);**

Defines the digital input pin the instance should look at

**void debounceDelay(int debounceDelay);**

Overwrites the default debounce delay (in ms), must be lower than doubleClickGap and holdDelay

**void doubleClickGap(int doubleClickGap);**

Overwrites the default double click gap (in ms)

**void holdDelay(int holdDelay);**

Overwrites the default hold delay (in ms)

**void update();**

Updates the state of the input PIN, should be called in loop

**bool pressed();**

Returns 1 when button is pressed after debouncing, as long as the button is pressed

**bool clickedEdge();**

Returns 1 for one program cycle after debouncing

**bool doubleClicked();**

Returns 1 for one program cycle when button is pressed twice (after debouncing)

**bool held();**

Returns 1 when button is held and holdDelay expired as long as the button is held (after debouncing)

**bool heldEdge();**

Returns 1 for one program cycle when button is held and holdDelay expired (after debouncing)
