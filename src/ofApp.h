#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofTexture tex1;
    ofTexture tex2;
    
    ofFbo       chromaFbo;      //For storing the FBO contents of the chromatic abberation shader
    ofFbo       chromaFbo2;      //For storing the FBO contents of the chromatic abberation shader
    ofFbo       wobbleFbo;      //For storing the FBO contents of the chromatic abberation shader
    
    
    ofShader chromaShader, chromaShader2;      //Poor mans chromatic abberation
    
    ofShader wobbleShader;
		
};
