#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    pdf.load("Kinect_Girls.pdf");
    
//    cam.setPosition(100, 100, 0);
//    cam.lookAt(ofVec3f(0,0,0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //cam.begin();
    
    float app_time = ofGetElapsedTimef();
    float animation_time = fmodf(app_time, 5) / 5;
    
    cout << "app_time: = " << app_time << ", animation_time: " << animation_time << endl;
    
    ofSetColor(255);
    
    // PDFのパスを順番に取り出して ofPolyline で描画する
    for (int i = 0; i < pdf.getNumPath(); i++)
    {
        ofPath& path = pdf.getPathAt(i);
        
        vector<ofPolyline>& polys = path.getOutline();
        for (int k = 0; k < polys.size(); k++)
        {
            ofPolyline poly = polys[k];
            
            poly = poly.getResampledByCount(100);
            
            int target_size = poly.size() * animation_time;
            poly.resize(target_size);
            
            poly.draw();
            //cam.end();
        }
    }
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
