//
//  TriangleScene.h
//  DyVisual
//
//  Created by Sousheel Vunnam on 6/10/17.
//
//

#ifndef TriangleScene_h
#define TriangleScene_h

#include <ofxAppUtils.h>

class TriangleScene : public ofxFadeScene {
    
public:
    
    //General
    int windowHeight;
    int windowWidth;
    ofxApp *app;
    bool gotBeat;
    
    //Triangle Graphic
    ofPoint triVertex1;
    ofPoint triVertex2;
    ofPoint triVertex3;
    int initTriHeight;
    vector<ofPoint> triPoints;
    
    // set the scene name through the base class initializer
    TriangleScene() : ofxFadeScene("Triangles"){
        setSingleSetup(false); // call setup each time the scene is loaded
        setFade(1000, 1000); // 1 second fade in/out
    }
    
    // scene setup
    void setup() {
        //General
        app =ofxGetAppPtr();
        windowWidth = app->getRenderWidth();
        windowHeight = app->getRenderHeight();
        
        //sound
        gotBeat = true;
        
        //Triangle Graphic
        initTriHeight = windowHeight/3;
        triVertex1.set(windowWidth/3, 2*(windowWidth/3), 0);
        triVertex2.set(2*(windowWidth/3), 2*(windowWidth/3), 0);
        triVertex3.set(windowWidth/2, initTriHeight, 0);
//      srand(time(NULL));
    }
    
    // called when scene is entering, this is just a demo and this
    // implementation is not required for this class
    void updateEnter() {
        
        // called on first enter update
        if(isEnteringFirst()) {
            ofLogNotice("TriangleScene") << "update enter";
        }
        
        // fade scene calculates normalized alpha value for us
        ofxFadeScene::updateEnter();
        
        // finished entering?
        if(!isEntering()) {
            ofLogNotice("TriangleScene") << "update enter done";
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
            ofLogNotice("TriangleScene") << "update exit";
        }
        
        // fade scene calculates normalized alpha value for us
        ofxFadeScene::updateExit();
        
        // finished exiting?
        if(!isExiting()) {
            ofLogNotice("TriangleScene") << "update exit done";
        }
    }
    
    // draw
    void draw() {
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, 255*alpha);
            if (gotBeat) {
                ofDrawBitmapString("WAbAM", 0, 0);
                gotBeat = false;
        
                //Triangle Graphic
                ofPoint newVertex(windowWidth/2, windowWidth/3);
                triPoints.push_back(newVertex);
             }
        
            //Triangle Graphic
            //Make a struct for triangledata
            triVertex1.set(windowWidth/3, 2*(windowWidth/3));
            triVertex2.set(2*(windowWidth/3), 2*(windowWidth/3));
            triVertex3.set(windowWidth/2, initTriHeight);
//            ofSetColor(255, 0, 0);
            ofFill();
            ofSetLineWidth(1);
            ofDrawTriangle(triVertex1, triVertex2, triVertex3);
        
            for (int i=0; i<triPoints.size(); i++){
                triPoints[i].set(windowWidth/2, triPoints[i].y + 3);
                if (triPoints[i].y >= windowHeight){
                    triPoints.erase(triPoints.begin() + i);//remove point
                }
                else{
                    int red = rand()%255; //use ofRandom instead
                    int green = rand()%255;
                    int blue = rand()%255;
                    ofSetColor(red, green, blue);
                    ofDrawTriangle(triPoints[i], triVertex1, triVertex2);
                }
            }
        ofDisableAlphaBlending();

    }
    
    // cleanup
    void exit() {
        //    ofSoundStreamStop();
        //    ofSoundStreamClose();
    }
};
#endif /* TriangleScene_h */
