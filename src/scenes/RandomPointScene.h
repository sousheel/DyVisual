//
//  RandomPointScene.h
//  DyVisual
//
//  Created by Sousheel Vunnam on 6/10/17.
//
//

#ifndef RandomPointScene_h
#define RandomPointScene_h

#include <ofxAppUtils.h>

class RandomPointScene : public ofxFadeScene {
    
public:
    //General
    int windowHeight;
    int windowWidth;
    ofxApp *app;
    bool gotBeat;
    
    //Random Points
    vector<ofPoint> randPoints;
    
    // set the scene name through the base class initializer
    RandomPointScene() : ofxFadeScene("RandomPoints"){
        setSingleSetup(false); // call setup each time the scene is loaded
        setFade(1000, 1000); // 1 second fade in/out
    }
    
    // scene setup
    void setup() {
        //General
        app =ofxGetAppPtr();
        windowWidth = app->getRenderWidth();
        windowHeight = app->getRenderHeight();
        
        gotBeat = true;
        
    }
    
    // called when scene is entering, this is just a demo and this
    // implementation is not required for this class
    void updateEnter() {
        
        // called on first enter update
        if(isEnteringFirst()) {
            ofLogNotice("RandomPointScene") << "update enter";
        }
        
        // fade scene calculates normalized alpha value for us
        ofxFadeScene::updateEnter();
        
        // finished entering?
        if(!isEntering()) {
            ofLogNotice("RandomPointScene") << "update enter done";
        }
    }
    
    // normal update
    void update() {
        //General
        app = ofxGetAppPtr();
    }
    
    // called when scene is exiting, this is just a demo and this
    // implementation is not required for this class
    void updateExit() {
        
        // called on first exit update
        if(isExitingFirst()) {
            ofLogNotice("RandomPointScene") << "update exit";
        }
        
        // fade scene calculates normalized alpha value for us
        ofxFadeScene::updateExit();
        
        // finished exiting?
        if(!isExiting()) {
            ofLogNotice("RandomPointScene") << "update exit done";
        }
    }
    
    // draw
    void draw() {
        ofEnableAlphaBlending();
        ofSetColor(255, 0, 0, 255*alpha);	// alpha member variable for fade in/out
            if (gotBeat) {
                ofDrawBitmapString("WAbAM", 0, 0);
                gotBeat = false;
                //Random Points
                randPoints.push_back(ofPoint(ofRandom(windowWidth), ofRandom(windowHeight))); //adds random points!!!
        
            }
            //Random Points
            //Incorporate random line wiggling in this
//            ofSetColor(255, 0, 0);
            ofNoFill(); //Doesn't fill shapes (only makes outlines)
            ofBeginShape(); //Start making path
            for(int i = 0; i < randPoints.size(); i++){ //adds vertex for every beat
                ofVertex(randPoints[i]);
            }
            ofEndShape(false); //finish the path, the false means don't close the loop.
        ofDisableAlphaBlending();
    }
    
    // cleanup
    void exit() {
        //    ofSoundStreamStop();
        //    ofSoundStreamClose();
    }
};


#endif /* RandomPointScene_h */
