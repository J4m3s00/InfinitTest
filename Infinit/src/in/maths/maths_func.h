#pragma once

#include <Infinit.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "vec3.h"

namespace in { namespace maths {

	inline float toRadians(float value)
	{
		return (float)(value * (M_PI / 180.0f));
	}

	inline vec3 CalculateTerrainNormal(float heightL, float heightR, float heightD, float heightU)
	{
		return vec3(heightL - heightR, 2.0f, heightD - heightU).Normalize();
	}

} }