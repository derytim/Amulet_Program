#pragma once

#include "../Animation.h"

class AnimCylon : public Animation
{
public:
	virtual void init()
	{
  LOG_LV1("LED", "Cylon::init( %d, %d )", animation_p1, animation_p2);
  gHue = animation_p1;
  fill_solid(gLeds, RGB_LED_COUNT, CHSV(gHue, 255, 0));
	}

	virtual void step(const int frame, const float deltaTime, const float sourceDistance) override
	{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy(gLeds, 4, 20);
  int pos = beatsin16(26, 0, 4 - 1);
  gLeds[pos] += CHSV(gHue, 255, 192);
  mirror();
  gHue += animation_p2;
	}
};