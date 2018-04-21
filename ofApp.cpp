#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(180);

	float radius = 350;
	float small_radius = 50;
	ofPoint start, end;

	ofSetColor(239, 39, 39);
	for (int deg = 0; deg <= 360; deg += 1) {

		start = make_point(radius, small_radius, deg, deg * 8 + ofGetFrameNum());
		end = make_point(radius, small_radius, deg + 10, deg * 8 + ofGetFrameNum());

		ofDrawLine(start, end);
		ofDrawSphere(start, 2);
		ofDrawSphere(end, 2);
	}

	ofSetColor(39, 39, 239);
	for (int deg = 0; deg <= 360; deg += 1) {
	
		start = make_point(radius, small_radius, deg, deg * 8 + ofGetFrameNum() + 180);
		end = make_point(radius, small_radius, deg + 10, deg * 8 + ofGetFrameNum() + 180);

		ofDrawLine(start, end);
		ofDrawSphere(start, 2);
		ofDrawSphere(end, 2);
	}

	this->cam.end();
}

//--------------------------------------------------------------
ofPoint ofApp::make_point(float radius, float small_radius, float deg, float small_deg) {

	float x_1 = radius * cos(deg * DEG_TO_RAD);
	float y_1 = radius * sin(deg * DEG_TO_RAD);

	float x_2 = small_radius * cos(small_deg * DEG_TO_RAD) * cos(deg * DEG_TO_RAD);
	float y_2 = small_radius * cos(small_deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD);

	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = small_radius * sin(small_deg * DEG_TO_RAD);

	return ofPoint(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}