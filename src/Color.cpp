#include "color.h"
#include "ofMain.h"

void ofSetColor(Color color)
{
	ofSetColor(
        (color & Red) == Red ? 255 : 0,
		(color & Green) == Green ? 178 : 0,
		(color & Blue) == Blue ? 255 : 0);
}
