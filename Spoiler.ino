/*
 * Include our own Libraries
 */
#include <Parser.h> // Connects to and speaks with the CAN bus
#include <Spoiler.h> // Moves the Spoiler

int forwardsPin = 5;
int backwardsPin = 6;
int resistorPin = A0;

/**
 * Initiate Libraries
 */
Parser parser;
Spoiler spoiler(forwardsPin, backwardsPin, resistorPin);

void setup() {
  // Define safe bounds for the spoiler
  // these represent resistor values
  spoiler.POT_MIN = 100;
  spoiler.POT_MAX = 600;

  // Init libraries
  parser.init();
  spoiler.init();
}

void loop() {
  // Update values
  parser.listen();

  // Set the Spoiler angle
  int angle = map(parser.speed,0, 75, 100, 600);
  spoiler.setPosition(angle);
}
