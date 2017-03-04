#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	webcam.setDeviceID(1);
	webcam.setup(WIDTH,HEIGHT);


	gui.setup("slit scan", "settings.xml");
	
	gui.add(scanSpeed.setup("scanSpeed",1,1,30));
	gui.add(scanSlitWidth.setup("scanSlitWidth", 1,1,30));
	gui.add(saveScreen.setup("saveScreen",false ));
	gui.add(saveEveryFrames.setup("saveEveryFrames", 3,1,200));

	gui.loadFromFile("settings.xml");

	scanCursor = 0;

	for (int i = 0;i < webcam.getWidth();i++) {
		ofFbo fboS;
		fboS.allocate(1, webcam.getHeight(), GL_RGB);
		fboSlice.push_back(fboS);
	}

	for (int i = 0;i < webcam.getWidth();i++) {
			ofFbo fboS;
			fboS.allocate(webcam.getHeight(), webcam.getHeight(), GL_RGB);
			pastFrames.push_back(fboS);
			//cout << i << endl;
	}


	scanForwardBackward = true;
	frameSaved = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(120);

	webcam.update();

	pastFrames[scanCursor].begin();
	ofClear(0, 0, 0, 0);
	webcam.draw(0, 0);
	pastFrames[scanCursor].end();

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	

	/*

	if (scanForwardBackward) {
		cout << "scan cursor" << scanCursor << endl;
		for (int i = 0;i < fboSlice.size();i++) {
				if(scanCursor-i >= 0){ //if(i<scanCursor){
					fboSlice[i].begin();
					ofClear(0, 0, 0, 0);	
					pastFrames[scanCursor - i].draw(-i, 0, webcam.getWidth(), webcam.getHeight());
					fboSlice[i].end();
				}
		}

		scanCursor += scanSpeed;
		if (scanCursor >= webcam.getWidth()) {//+scanSlitWidth
			scanForwardBackward = false;
			scanCursor = webcam.getWidth();
			cout << "forward" << endl;
		}
		
	}
	else {
		//cout << "break1" << endl;
		/*
		for (int i = fboSlice.size() ; i>0 ;i--) {
			if (scanCursor < i) {
				fboSlice[i].begin();
				ofClear(0, 0, 0, 0);
				//pastFrames[scanCursor -i].draw(-i, 0, webcam.getWidth(), webcam.getHeight());
				//cout << "break2//: " <<i<< endl;
				fboSlice[i].end();
			}
		}
		*/
	/*
		for (int i = 0;i < fboSlice.size();i++) {
			int iInvert=ofMap(i, 0, fboSlice.size(), fboSlice.size(), 0);
			if(i<scanCursor){//if (scanCursor - i >= 0) { 
				fboSlice[iInvert].begin();
				ofClear(0, 0, 0, 0);
				//pastFrames[scanCursor - iInvert].draw(-i, 0, webcam.getWidth(), webcam.getHeight());
				fboSlice[iInvert].end();
			}
		}

		scanCursor -= scanSpeed;
		if (scanCursor  <= 0) {//+ scanSlitWidth
			scanForwardBackward = true;
			scanCursor = 0;
		
		}
		
	}

	*/


	for (int i = 0;i < fboSlice.size();i++) {
		
			/*
			if (scanForwardBackward == false) {

				int iInvert = ofMap(i, 0, fboSlice.size(), fboSlice.size(), 0);

				if (scanCursor - iInvert >= 0) { //if(i<scanCursor){
					fboSlice[i].begin();
					ofClear(0, 0, 0, 0);
					pastFrames[iInvert - i].draw(-i, 0, webcam.getWidth(), webcam.getHeight());
					fboSlice[i].end();
				}
				
			}
			else {
				*/


		if (scanCursor - i >= 0) { //if(i<scanCursor){
			fboSlice[i].begin();
			ofClear(0, 0, 0, 0);
			pastFrames[scanCursor - i].draw(-i, 0, webcam.getWidth(), webcam.getHeight());
			fboSlice[i].end();

			//cout << "Scan cursor" << scanCursor - i <<" i"<<i<< endl;
		}
		else {
			fboSlice[i].begin();
			ofClear(0, 0, 0, 0);
			pastFrames[(webcam.getWidth()+scanCursor)-i].draw(-i, 0, webcam.getWidth(), webcam.getHeight());
			fboSlice[i].end();

			//cout << "else" << i << endl;
		}
			//}
			
			
			
		//}
	}

	scanCursor += scanSpeed;
	if (scanCursor >= webcam.getWidth()) {//+scanSlitWidth
		scanForwardBackward != scanForwardBackward;
		scanCursor = 0;// webcam.getWidth();
		//cout << "forward" << endl;
	}



	for (int i = 0;i < fboSlice.size();i++) {
		fboSlice[i].draw(i, 0, fboSlice[i].getWidth(), fboSlice[i].getHeight());
	}

	

	if (saveScreen) {
		if (frameSaved % saveEveryFrames == 0) {
			// n is a multiple of 8
			ofSaveScreen(ofToString(frameSaved) + ".jpg");
		}
		gui.draw();
		//if(frameSaved/saveEveryFrames==1)
		//ofSaveScreen(ofToString(frameSaved)+".png");
		frameSaved++;
	}
	else { gui.draw(); }

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

//--------------------------------------------------------------
void ofApp::exit() {
	gui.saveToFile("settings.xml");
}