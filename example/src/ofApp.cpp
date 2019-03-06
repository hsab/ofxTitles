#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
   ofBackground(0);

   mVid.loadMovie("fingers.mov");
   mVid.play();

   mTitles.bindVideo(&mVid);
   mTitles.add("Subtitle 1\nSub2", 1, 5000, 10000);

   // subtitles are automatically sorted by their start
   // time so they can be added in any order
   //mTitles.add("Subtitle 6", 6, 9500, 11500);
   //mTitles.add("Subtitle 5", 5, 9000, 8500);  // this won't display
   //mTitles.add("Subtitle 3", 3, 6000, 8000);
   //mTitles.add("Subtitle 2", 7, 3500, 5500);
   //mTitles.add("Subtitle 4", 4, 8500, 8500);  // this won't display

   mTitles.loadFont("Tahoma.ttf", 20);
   mTitles.setLoopState(OF_LOOP_NORMAL);
   mTitles.play();
}

//--------------------------------------------------------------
void ofApp::update() {
   mVid.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
   mVid.draw(10, 10);
   // draw inside a bounding box - good for subtitles
   ofColor sub(255, 245, 0);
   mTitles.draw(10, 10, ofGetWidth(), ofGetHeight(), sub);

   // you can adjust the vertical layout using a percentage (0.0 - 1.0)
   // default is 0.9
   mVid.draw(10, mVid.getHeight() + 20);
   mTitles.draw(10, mVid.getHeight() + 20, mVid.getWidth(), mVid.getHeight(), sub, 0.5);

   mTitles.drawCenter(ofGetWidth() / 2, ofGetWidth() / 2, ofGetHeight() - 100, sub);

   // shaky title, absolutely positioned
   int x = (rand() % 5) + 20;
   int y = (rand() % 5) + (mVid.getHeight() * 2) + 80;
   mTitles.setDisplayNumber(true);
   mTitles.draw(x, y, sub);
   mTitles.setDisplayNumber(false);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}
