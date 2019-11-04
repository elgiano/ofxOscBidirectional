# ofxOscBidirectional
ofxOsc fork to get replies to your OSC messages.
Integrates work from different sources:
- ofxOsc from openFrameworks 0.10.1: very minimal changes, only in access level of class members (see ofxOsc.diff if curious)
- work from [ERASE](http://www.erase.net/projects/ofxSuperCollider/), who created a ofxOsc fork to permit communication to SuperCollider's server, based on an older version of ofxOsc.
- [ofxOscEvent](https://github.com/satcy/ofxOscEvent), which is included to provide the capability of registering event listeners for OSC replies.

The project is motivated from the need to communicate to SuperCollider server, which needs to happen on the same UPD socket both ways.
Thus, we are using an UdpListeningSocket to send OSC messages too. ERASE's work was a big inspiration here

Here's an example to setup OSC communication with SuperCollider:
```
testApp.h:

#include "ofxOscBidirectional.h"
private:
ofxOscSenderReceiver osc;

testApp.cpp:

void testApp::setup(){
  osc.setup(CLIENT_PORT,HOST,SERVER_PORT);
  ofAddListener(ofxOscEvent::packetIn, this, &OSCMessenger::onMessageReceived);
}

void testApp::onMessageReceived(ofxOscMessage &m){
  std::string address = m.getAddress();
  std::cout << "RECVd " <<  address << std::endl;
}
```
