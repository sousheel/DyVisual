#pragma once

#include "ofMain.h"
#include "ofxAubio.h"
#include "ofxGui.h"

#include "ofxAppUtils.h"

#ifdef HAVE_OFX_GUI
    #include "ofxGui.h"
    #include "ofxTransformPanel.h"
#endif

// we only specify a pointer to the Particle Scene here, so tell the compiler
// that it exists as a class and we can include the class header in ofApp.cpp
class ParticleScene;

class ofApp : public ofxApp{

	public:
		ofApp() {}
    
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
        int windowHeight;
        int windowWidth;
    
        //Triangle Graphic
        ofPoint triVertex1;
        ofPoint triVertex2;
        ofPoint triVertex3;
        int initTriHeight;
        vector<ofPoint> triPoints;
    
        //Random Points
        vector<ofPoint> randPoints;
    
    
        //Scene Management
        // rendering transformer
        ofxTransformer transformer;
    
        // handles the scenes
        ofxSceneManager sceneManager;
        int lastScene;
    
        // keep a pointer to the Particle Scene, so we can modify it more easily
        ParticleScene *particleScene;
    
        #ifdef HAVE_OFX_GUI
            ofxTransformPanel panel;
        #endif
    
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
