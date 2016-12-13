#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
   // ofSetWindowShape(600, 600);
    ofSetBackgroundColor(25);
   
    width = 10;
    gol.setup(width);
    
    
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
    gol.init();
    }else {
        
        int x = ofRandom(gol.cols);
        int y = ofRandom(gol.rows);
    //    virus newVirus;
      //  newVirus.setup();
        gol.cellGrid[x][y]->state = 2;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    gol.addCell(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    gol.addCell(x, y);
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