#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    cout<<"Load CHROMA"<<endl;
    chromaShader.load("shaders/ChromaAb_GLSL");
    wobbleShader.load("shaders/Wobble_GLSL");
    
    chromaFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    chromaFbo.begin();
    ofClear(0,0,0,0); //Clear the FBO
    chromaFbo.end();
    
    chromaFbo2.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    chromaFbo2.begin();
    ofClear(0,0,0,0); //Clear the FBO
    chromaFbo2.end();
    
    wobbleFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    wobbleFbo.begin();
    ofClear(0,0,0,0); //Clear the FBO
    wobbleFbo.end();
    
    tex1.setTextureWrap(GL_REPEAT, GL_REPEAT);
    tex1.allocate(ofGetWidth(),ofGetHeight(),GL_RGB,GL_RGBA);
    
    
    ofSetCircleResolution(50);
    
    ofDisableDepthTest();

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofBackground(0);
    
    
    ofEnableAlphaBlending();
    
    chromaFbo.begin();
        if( ofGetKeyPressed('c') ){
            ofClear(0,0,0, 0);
        }
        //ofClear(0, 0, 0);
            //ofSetColor(0, 0, 0,10);
            //ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
        
        ofPushMatrix();
            float scaleFactor = 0.99;
            ofTranslate(5, 5);
            ofScale(scaleFactor,scaleFactor);
            ofSetColor(255,255,255,250);
            wobbleFbo.draw(0,0);
        ofPopMatrix();
    
    ofSetColor(255,255,255,255);
    
    ofCircle(mouseX,mouseY,40);
    chromaFbo.end();
    
    
    ofPoint expand;
    expand.x = ofMap(mouseX, 0, ofGetWidth(), 1, 30);
    expand.y = ofMap(mouseY, 0, ofGetHeight(), 1, 30);
    

    
    ofEnableNormalizedTexCoords();
    chromaFbo2.begin();
    
    chromaFbo.getTextureReference().bind();
    chromaShader.begin();
    chromaShader.setUniformTexture("tex", chromaFbo.getTextureReference(), 0);
    chromaShader.setUniform2f("windowSize", 320, 240);
    chromaShader.setUniform2f("offsetRed", expand.x*1*sin(expand.y*ofGetElapsedTimef()), expand.y*1*cos(expand.x*ofGetElapsedTimef()));
    chromaShader.setUniform2f("offsetGreen", expand.x*1.1* sin(0.1+expand.y*ofGetElapsedTimef()), expand.y*1.3*cos(expand.x*ofGetElapsedTimef()));
    chromaShader.setUniform2f("offsetBlue", expand.x*1.1* sin(0.2+expand.y*ofGetElapsedTimef()), expand.y*1.2*cos(1+expand.y*ofGetElapsedTimef()));
    //chromaShader.setUniform1f("offsetALL", 2*sin(30*ofGetElapsedTimef()));
    
    
    ofPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex3f(0,0,0);
    glTexCoord2f(1,0); glVertex3f(ofGetWidth(),0,0);
    glTexCoord2f(1,1); glVertex3f(ofGetWidth(),ofGetHeight(),0);
    glTexCoord2f(0,1); glVertex3f(0,ofGetHeight(),0);
    glEnd();
    ofPopMatrix();
    chromaShader.end();
    chromaFbo.getTextureReference().unbind();
    ofDisableNormalizedTexCoords();
    
    chromaFbo2.end();
    
    wobbleFbo.begin();
    chromaFbo2.draw(0, 0);
    wobbleFbo.end();
    
    //chromaFbo2.draw(0, 0);
    


//    ofEnableNormalizedTexCoords();
//    ofSetColor(255);
//    
//    wobbleFbo.getTextureReference().bind();
//    wobbleShader.begin();
//    wobbleShader.setUniformTexture("image", wobbleFbo.getTextureReference(), 0);
//    wobbleShader.setUniform2f("amp", 10,10); //These settings are finicky. Be careful with your ranges
//    wobbleShader.setUniform2f("freq", .004+(.2*cos(ofGetElapsedTimef())),.004+(.2*sin(ofGetElapsedTimef())));
//    wobbleShader.setUniform1f("radius", 15+(8*sin(ofGetElapsedTimef())));
//    //chromaShader.setUniform1f("offsetALL", 2*sin(30*ofGetElapsedTimef()));
//    
//    
//    ofPushMatrix();
//    //ofTranslate(640,0);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0,0); glVertex3f(0,0,0);
//    glTexCoord2f(1,0); glVertex3f(ofGetWidth(),0,0);
//    glTexCoord2f(1,1); glVertex3f(ofGetWidth(),ofGetHeight(),0);
//    glTexCoord2f(0,1); glVertex3f(0,ofGetHeight(),0);
//    glEnd();
//    ofPopMatrix();
//    wobbleShader.end();
//    wobbleFbo.getTextureReference().unbind();
//    ofDisableNormalizedTexCoords();

   
    
   // wobbleFbo.draw(0,0);


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
