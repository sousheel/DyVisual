#include "ofApp.h"
#include "ofEventUtils.h"
#include <stdlib.h>
#include <time.h>
#include "scenes/scenes.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetVerticalSync(true);
//    ofSetWindowShape(1250, 750); //Window size
//    
//    int nOutputs = 2;
//    int nInputs = 2;
//    int sampleRate = 44100;
//    int bufferSize = 256;
//    int nBuffers = 4;
//    
//    //From audio inout example
//    left.assign(bufferSize, 0.0);
//    right.assign(bufferSize, 0.0);
//    volHistory.assign(400, 0.0);
//    
//    bufferCounter	= 0;
//    drawCounter		= 0;
//    smoothedVol     = 0.0;
//    scaledVol		= 0.0;
//    
//    // setup/listen onset object
//    onset.setup();
//    ofAddListener(onset.gotOnset, this, &ofApp::onsetEvent);
//    
//    // setup pitch object
//    pitch.setup();
//    
//    // setup/listen beat object
//    beat.setup();
//    ofAddListener(beat.gotBeat, this, &ofApp::beatEvent);
//    
//    // setup mel bands object
//    bands.setup();
//    
//    //ofSoundStreamListDevices();
//    soundStream.setDeviceID(0);
//    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
//    
//    // setup the gui objects
//    int start = 0;
//    beatGui.setup("ofxAubioBeat", "settings.xml", start + 10, 10);
//    beatGui.add(bpm.setup( "bpm", 0, 0, 250));
//    start += 250;
//    onsetGui.setup("ofxAubioOnset", "settings.xml", start + 10, 10);
//    onsetGui.add(onsetThreshold.setup( "threshold", 0, 0, 2));
//    onsetGui.add(onsetNovelty.setup( "onset novelty", 0, 0, 10000));
//    onsetGui.add(onsetThresholdedNovelty.setup( "thr. novelty", 0, -1000, 1000));
//    // set default value
//    onsetThreshold = onset.threshold;
//    start += 250;
//    pitchGui.setup("ofxAubioPitch", "settings.xml", start + 10, 10);
//    pitchGui.add(midiPitch.setup( "midi pitch", 0, 0, 128));
//    pitchGui.add(pitchConfidence.setup( "confidence", 0, 0, 1));
//    bandsGui.setup("ofxAubioMelBands", "settings.xml", start + 10, 115);
//    for (int i = 0; i < 40; i++) {
//        bandPlot.addVertex( 50 + i * 650 / 40., 240 - 100 * bands.energies[i]);
//    }
//    
//    
//    //Graphics Stuff
//    currentGraphic = "";
//    ofSetFrameRate(30);
//    ofSetBackgroundAuto(false); //Allows you to change background multiple times
//    ofBackground(255); //Sets to white
//    
//    //Triangle Graphic
//    windowWidth = ofGetWindowWidth();
//    windowHeight = ofGetWindowHeight();
//    initTriHeight = windowHeight/3;
//    triVertex1.set(ofGetWindowWidth()/3, 2*(ofGetWindowWidth()/3), 0);
//    triVertex2.set(2*(ofGetWindowWidth()/3), 2*(ofGetWindowWidth()/3), 0);
//    triVertex3.set(ofGetWindowWidth()/2, initTriHeight, 0);
//    srand(time(NULL));
    
    
    // setup for nice jaggy-less rendering
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    // setup the render size (working area)
    transformer.setRenderSize(600, 400);
    
    // turn on transform origin translation and scaling to screen size,
    // disable quad warping, and enable aspect ratio and centering when scaling
    transformer.setTransforms(true, true, false, true, true);
    
    // set the ofxApp transformer so it's automatically applied in draw()
    setTransformer(&transformer);
    
#ifdef HAVE_OFX_GUI
    // setup transform panel with transformer pointer,
    // loads settings & quad warper xml files if found
    panel.setup(&transformer);
#endif
    
    // load scenes
    particleScene = (ParticleScene*) sceneManager.add(new ParticleScene()); // save pointer
    sceneManager.add(new LineScene());
    sceneManager.setup(true); // true = setup all the scenes now (not on the fly)
    ofSetLogLevel("ofxSceneManager", OF_LOG_VERBOSE); // lets see whats going on inside
    
    // start with a specific scene
    // set now to true in order to ignore the scene fade and change now
    sceneManager.gotoScene("Lines", true);
    lastScene = sceneManager.getCurrentSceneIndex();
    
    // overlap scenes when transitioning
    sceneManager.setOverlap(true);
    
    // attach scene manager to this ofxApp so it's called automatically,
    // you can also call the callbacks (update, draw, keyPressed, etc) manually
    // if you don't set it
    //
    // you can also turn off the auto sceneManager update and draw calls with:
    // setSceneManagerUpdate(false);
    // setSceneManagerDraw(false);
    //
    // the input callbacks in your scenes will be called if they are implemented
    //
    setSceneManager(&sceneManager);

}

//void ofApp::exit(){
//    ofSoundStreamStop();
//    ofSoundStreamClose();
//}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
//    // compute onset/pitch detection, beat location, bands
//    onset.audioIn(input, bufferSize, nChannels);
//    pitch.audioIn(input, bufferSize, nChannels);
//    beat.audioIn(input, bufferSize, nChannels);
//    bands.audioIn(input, bufferSize, nChannels);
//    
//    // From Audio Input Example
//    float curVol = 0.0;
//    int numCounted = 0; // samples are "interleaved"
//    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
//    for (int i = 0; i < bufferSize; i++){
//        left[i]		= input[i*2]*0.5;
//        right[i]	= input[i*2+1]*0.5;
//        
//        curVol += left[i] * left[i];
//        curVol += right[i] * right[i];
//        numCounted+=2;
//    }
//    curVol /= (float)numCounted; //this is how we get the mean of rms :)
//    curVol = sqrt( curVol ); // this is how we get the root of rms :)
//    smoothedVol *= 0.93;
//    smoothedVol += 0.07 * curVol;
//    bufferCounter++;
}

//void audioOut(){
//}

//--------------------------------------------------------------
void ofApp::update(){
//    onset.setThreshold(onsetThreshold);
//    
//    //From audio input example
//    //lets scale the vol up to a 0-1 range
//    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
//    //lets record the volume into an array
//    volHistory.push_back( scaledVol );
//    //if we are bigger the the size we want to record - lets drop the oldest value
//    if( volHistory.size() >= 400 ){
//        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
//    }
//    
//    // the current scene is automatically updated before this function
//    
//    #ifdef HAVE_OFX_GUI
//        // update the transform panel when in debug mode
//        if(isDebug()) {
//            panel.update();
//        }
//    #endif
}

//--------------------------------------------------------------
void ofApp::draw(){
//    // update beat info
//    if (gotBeat) {
//        ofSetColor(ofColor::green);
//        ofRect(90,150,50,50);
//        gotBeat = false;
//    }
//    
//    // update onset info
//    if (gotOnset) {
//        ofSetColor(ofColor::red);
//        ofRect(250 + 90,150,50,50);
//        gotOnset = false;
//    }
//    onsetNovelty = onset.novelty;
//    onsetThresholdedNovelty = onset.thresholdedNovelty;
//    
//    // update pitch info
//    pitchConfidence = pitch.pitchConfidence;
//    if (pitch.latestPitch) midiPitch = pitch.latestPitch;
//    bpm = beat.bpm;
//
//    // draw
//    pitchGui.draw();
//    beatGui.draw();
//    onsetGui.draw();
//    
//    ofSetColor(ofColor::orange);
//    ofSetLineWidth(3.);
//    bandsGui.draw();
//    //bandPlot.clear();
//    for (int i = 0; i < bandPlot.size(); i++) {
//        bandPlot[i].y = 240 - 100 * bands.energies[i];
//    }
//    bandPlot.draw();
//    
//    // From Audio Input example (for left/right examples look at audio input example)
//    // draw the average volume:
//    ofPushStyle();
//    ofPushMatrix();
//    ofTranslate(750, 0, 0);
//    
//    ofSetColor(225);
//    ofDrawBitmapString("Scaled average vol (0-100): " + ofToString(scaledVol * 100.0, 0), 4, 18);
//    ofDrawRectangle(0, 0, 400, 400);
//    
//    ofSetColor(245, 58, 135);
//    ofFill();
//    ofDrawCircle(200, 200, scaledVol * 190.0f);
//    
//    //lets draw the volume history as a graph
//    ofBeginShape();
//    for (unsigned int i = 0; i < volHistory.size(); i++){
//        if( i == 0 ) ofVertex(i, 400);
//        
//        ofVertex(i, 400 - volHistory[i] * 70);
//        
//        if( i == volHistory.size() -1 ) ofVertex(i, 400);
//    }
//    ofEndShape(false);		
//    
//    ofPopMatrix();
//    ofPopStyle();
//    
//    

    
//    if (gotBeat)
//    
//    //Triangle Graphic
//    
//    //Random Points
    
    // the current scene is automatically drawn before this function
    
    // show the render area edges with a white rect
    if(isDebug()) {
        ofNoFill();
        ofSetColor(255);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofDrawRectangle(1, 1, getRenderWidth()-2, getRenderHeight()-2);
        ofFill();
    }
    
    // drop out of the auto transform space back to OF screen space
    transformer.pop();
    
    #ifdef HAVE_OFX_GUI
        // draw the transform panel when in debug mode
        if(isDebug()) {
            panel.draw();
        }
    #endif
    
    // draw current scene info using the ofxBitmapString stream interface
    // to ofDrawBitmapString
    ofSetColor(200);
    ofxBitmapString(12, ofGetHeight()-8)
    << "Current Scene: " << sceneManager.getCurrentSceneIndex()
    << " " << sceneManager.getCurrentSceneName() << endl;
    
    // go back to the auto transform space
    //
    // this is actually done automatically if the transformer is set but
    // included here for completeness
    transformer.push();
    
    // the warp editor is drawn automatically after this function
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if( key == 's' ){
//        soundStream.start();
//    }
//    
//    if( key == 'e' ){
//        soundStream.stop();
//    }
    switch(key) {
        //set numbers and first row (q-p) to unique visuals
        case '1': //return to screen with no visuals
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case '0':
            break;
        case 'q':
            break;
        //other unique visuals as needed
        case 'p':
            break;
        //set second row (a-l) and third row (z-m) as settings for visuals
        case 'a': //refresh screen settings
            windowWidth = ofGetWindowWidth();
            windowHeight = ofGetWindowHeight();
            initTriHeight = windowHeight/2;
        case 's': //rotating camera
            break;
        case 'f': //Fullscreen
            ofToggleFullscreen();
            break;
        case 'c': //Colors (change colors randomly)
            ofToggleFullscreen();
            break;
            
        case OF_KEY_LEFT:
            sceneManager.prevScene();
            break;
        case OF_KEY_RIGHT:
            sceneManager.nextScene();
            break;
    }
    
    //how can I map multiple keys together?? like add beat interactivity with colors and shapes
    
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
//    ofPoint p; //create a point and add it to the end of the array every time mouse clicked
//    p = ofPoint(x,y);
//    randPoints.push_back(p);
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

////----
//void ofApp::onsetEvent(float & time) {
//    //ofLog() << "got onset at " << time << " s";
//    gotOnset = true;
//}
//
////----
//void ofApp::beatEvent(float & time) {
//    //ofLog() << "got beat at " << time << " s";
//    gotBeat = true;
//}
