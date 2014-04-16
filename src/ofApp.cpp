#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowTitle("Main Window");
    
    // get the main window
    mainWindow = glfwGetCurrentContext();
    
    // get the position and dimenstions of the main window
    int xpos, ypos;
    int winw, winh;
    glfwGetWindowSize(mainWindow, &winw, &winh);
    glfwGetWindowPos(mainWindow, &xpos, &ypos);
    
    
    // start the auxiliar window
    auxWindow = glfwCreateWindow(320, 240, "Auxiliar window", NULL, mainWindow);
    
    // move the auxilar window
    glfwSetWindowPos(auxWindow, xpos+winw, ypos);

    // open the video
    video.loadMovie("video.mov");
    video.play();

}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // change to main window and draw video
    video.draw(0,0,ofGetWidth(), ofGetHeight());
    
    // change to auxiliar window and draw video
    glfwMakeContextCurrent(auxWindow);
    int width, height;
    glfwGetFramebufferSize(auxWindow, &width, &height);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,1,-1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    video.draw(-1,-1,2,2);
    glfwSwapBuffers(auxWindow);
    glfwPollEvents();
    glfwMakeContextCurrent(mainWindow);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
