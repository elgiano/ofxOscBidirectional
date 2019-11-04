/*
 *  ofxOscSenderReceiver.h
 *  openFrameworks
 *
 *  Created by Daniel Jones on 17/11/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _ofxOscSENDERRECEIVER_H
#define _ofxOscSENDERRECEIVER_H

#include "ofxOscSender.h"
#include "ofxOscReceiver.h"
#include "ofxOscEvent.h"

class ofxOscSenderReceiver : public ofxOscSender, public ofxOscEvent
{

public:
	void setup(int listen_port, std::string send_host, int send_port);
};

#endif
