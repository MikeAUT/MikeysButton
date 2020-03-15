/* This Library provides debouncing of digital inputs and also double presses, rising edges and helds
default values debounceDelay=20, doubleClickGap=500, holdDelay=1000
*/

#ifndef MikeysButton_h
#define MikeysButton_h
#include "Arduino.h"

class MikeysButton {
	public:
		MikeysButton();
		void attach(int pin);
        void debounceDelay(int debounceDelay);
		void doubleClickGap(int doubleClickGap);
		void holdDelay(int holdDelay);
		void update();
		bool pressed();
		bool clickedEdge();
		bool doubleClicked();
		bool held();
		bool heldEdge();
  
	
	private:
		unsigned int _pinNr, _debounceDelay, _doubleClickGap, _holdDelay;
		unsigned long _lastMillisDebounce, _lastMillisDoubleClick, _lastMillisHold;
		bool _debouncedState, _clickedLastState, _clickedEdge, _doubleClickFirst, _doubleClicked, _held, _heldLastState, _heldEdge;
		
		void __clickedEdge();
		void __doubleClick();
		void __held();
		void __heldEdge();
};
#endif
