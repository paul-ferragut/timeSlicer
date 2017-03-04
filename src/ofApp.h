#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define WIDTH 1280
#define HEIGHT 720

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();

		ofVideoGrabber webcam;

		//ofPixels pix;


		//ofShader shader;

		//ofImage pastImage;
		//ofImage currentImage;
		//ofImage sliceImage;

		//ofFbo maskFbo;
		//ofFbo fbo;

		//ofFbo previousFbo;

		ofxPanel gui;
		ofxFloatSlider scanSpeed;
		ofxIntSlider scanSlitWidth;
		ofxToggle saveScreen;
		ofxIntSlider saveEveryFrames;

		vector<ofFbo>fboSlice;
		vector<ofFbo>pastFrames;

			float scanCursor;

			bool scanForwardBackward;
			int frameSaved;
};
