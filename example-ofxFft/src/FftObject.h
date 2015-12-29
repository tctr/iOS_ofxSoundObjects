#pragma once

#include "ofMain.h"
#include "ofxFft.h"
#include "ofxSoundObjects.h"

class FftObject : public ofxSoundObject {
public:
    FftObject();
    ~FftObject();
	void setup(unsigned int bufferSize = 2048);
	void plot(vector<float>& buffer, const ofRectangle &r, bool bDrawLogScale = true);
    void process(ofSoundBuffer &input, ofSoundBuffer &output);
    void draw(const ofRectangle & r, bool bDrawLogScale = true);

    unsigned int bufferSize;

    void setBins(int numChans);
    
	ofxFft* fft;
	
	ofMutex soundMutex;
	vector<vector<float> >drawBins, middleBins, audioBins;

    int numChannels;
    bool bIsProcessed;
};
