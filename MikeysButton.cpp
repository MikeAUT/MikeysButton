#include "Arduino.h"
#include "MikeysButton.h"


// PUBLIC
  MikeysButton::MikeysButton() {
      _debounceDelay = 20;
      _doubleClickGap = 500;
      _holdDelay = 1000;
      _lastMillisDebounce = 0;
      _lastMillisDoubleClick = 0;
    }
	
	  void MikeysButton::attach(int pin) {
      _pinNr = pin;
    }
	
	  void MikeysButton::debounceDelay(int debounceDelay) {
      _debounceDelay = (unsigned long)debounceDelay;
    }

    void MikeysButton::doubleClickGap(int doubleClickGap) {
      _doubleClickGap = doubleClickGap;
    }
	
	void MikeysButton::holdDelay(int holdDelay){
		_holdDelay = holdDelay;
	}
	
	  void MikeysButton::update() {
      bool _actState = digitalRead(_pinNr);
      if (_actState) {
        if (millis() - _lastMillisDebounce >= _debounceDelay) {
          _debouncedState = true;
        } else {
          _debouncedState = false;
        }
      } else {
        _debouncedState = false;
        _lastMillisDebounce = millis();
      }
      __clickedEdge();
      __doubleClick();
      __held();
      __heldEdge();
    }
	
	   bool MikeysButton::pressed() {
      return _debouncedState;
    }

    bool MikeysButton::clickedEdge() {
      return _clickedEdge;
    }

    bool MikeysButton::doubleClicked() {
      return _doubleClicked;
    }

    bool MikeysButton::held() {
      return _held;
    }

    bool MikeysButton::heldEdge() {
      return _heldEdge;
    }
	
// PRIVATE
    void MikeysButton::__clickedEdge() {
      if (_debouncedState) {
        if (!_clickedLastState) {
          _clickedEdge = true;
          _clickedLastState = _debouncedState;
        } else if (_clickedLastState) {
          _clickedEdge = false;
        }
      } else {
        _clickedLastState = _debouncedState;
        _clickedEdge = false;
      }
    }

    void MikeysButton::__doubleClick() {
      if (_clickedEdge && !_doubleClickFirst) {
        _doubleClickFirst = true;
        _lastMillisDoubleClick = millis();
      } else if (_clickedEdge && _doubleClickFirst) {
        _doubleClicked = true;
        _doubleClickFirst = false;
      } else if (_doubleClicked) {
        _doubleClicked = false;
      }
      if (_doubleClickFirst && (millis() - _lastMillisDoubleClick > _doubleClickGap)) {
        _doubleClickFirst = false;
        _lastMillisDoubleClick = 0;
      }
    }

    void MikeysButton::__held() {
      if (_debouncedState) {
        if (millis() - _lastMillisHold > _holdDelay) {
          _held = true;
        } else {
          _held = false;
        }
      } else {
        _lastMillisHold = millis();
        _held = false;
      }
    }

    void MikeysButton::__heldEdge() {
      if (_held) {
        if (!_heldLastState) {
          _heldEdge = true;
          _heldLastState = _held;
        } else if (_heldLastState) {
          _heldEdge = false;
        }
      } else {
        _heldLastState = _held;
        _heldEdge = false;
      }
    }