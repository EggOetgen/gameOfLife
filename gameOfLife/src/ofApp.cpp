#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
   // ofSetWindowShape(600, 600);
    ofSetBackgroundColor(25);
   
    width = 1;
    
    //how quickly the 'virus' will spread
    virusStrenth = 0.5;
    
    //spawn rate of the red squiglies
    lifeRate = 0.00001;
    gol.setup(width, virusStrenth, lifeRate);
    
  // ofSetBackgroundAuto(false);
    
    }

//--------------------------------------------------------------
void ofApp::update(){
  
    gol.generate();
   
}

//--------------------------------------------------------------
void ofApp::draw(){

    gol.display();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        //reset program
        gol.clear();
        gol.init();
    }else if(key == '1'){
        //toggles if normal game of life will show when respawned
        gol.drawNorm = !gol.drawNorm;
    }else {
        //set random cell to red squigly
        int x = ofRandom(gol.cols);
        int y = ofRandom(gol.rows);
        gol.cellGrid[x][y]->state = 2;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    gol.virusStrength = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.1, 1);
    gol.lifeRate = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.0000001, 0.000005);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}