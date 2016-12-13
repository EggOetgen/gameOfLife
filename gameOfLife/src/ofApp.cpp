#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetWindowShape(600, 600);
    
   
    width = 1;
    gol.setup(width);
    }

//--------------------------------------------------------------
void ofApp::update(){

    gol.generate();
}

//--------------------------------------------------------------
void ofApp::draw(){

    gol.display();
    cout << gol.cols << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
    gol.init();
    }else {
        int x = ofRandom(gol.cols);
        int y = ofRandom(gol.rows);
        virus newVirus;
        newVirus.setup();
        gol.grid[x][y] = newVirus;
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