/*
 *  ofxOscSenderReceiver.cpp
 *  openFrameworks
 *
 *  Created by Daniel Jones on 17/11/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxOscSenderReceiver.h"

void ofxOscSenderReceiver::setup(int listen_port, std::string send_host, int send_port)
{
	ofxOscEvent::setup(listen_port);
	ofxOscSender::setup(send_host, send_port);
	this->listenSocket.get()->Connect(osc::IpEndpointName( send_host.c_str(), send_port ),true);
	this->sendSocket.reset((osc::UdpTransmitSocket *) this->listenSocket.get());
}
