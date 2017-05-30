#pragma once

#include "ofMain.h"
#include "ofxAubio.h"
#include "ofxGui.h"

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
    
        ofSoundStream soundStream;
        void audioIn(float * input, int bufferSize, int nChannels);
        //void audioOut();
    
        void onsetEvent(float & time);
        void beatEvent(float & time);
    
        //left/right audio channels (from audio listening example)
        vector <float> left;
        vector <float> right;
        vector <float> volHistory;
        int bufferCounter;
        int drawCounter;
        float smoothedVol;
        float scaledVol;
    
        //Graphics stuff
        string currentGraphic;
        vector<ofPoint> points;
    
    private:
        //Aubio
        ofxAubioOnset onset;
        ofxAubioPitch pitch;
        ofxAubioBeat beat;
        ofxAubioMelBands bands;
    
        //GUI
        ofxPanel pitchGui;
        ofxFloatSlider midiPitch;
        ofxFloatSlider pitchConfidence;
        ofxPanel beatGui;
        bool gotBeat;
        ofxFloatSlider bpm;
        ofxPanel onsetGui;
        bool gotOnset;
        ofxFloatSlider onsetThreshold;
        ofxFloatSlider onsetNovelty;
        ofxFloatSlider onsetThresholdedNovelty;
        ofxPanel bandsGui;
        ofPolyline bandPlot;
		
};
