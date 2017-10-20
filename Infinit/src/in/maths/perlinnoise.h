#pragma once

#include <Infinit.h>

namespace in { namespace maths {

	class PerlinNoise
	{
	private:
		float roughness = 0.3f; // 2.0f
		float octaves = 3;
		int m_Seed;
	public:
		static float AMPLITUDE;
	private:
		float GetRandom(int seed);
	public:
		PerlinNoise(int seed);
		static std::vector<std::vector<float>> GenerateHeights(int vertexCount, int seed);
	private:
		float GetEdgeFactor(float a);
		float GetEdgeFactor(float x, float y);
		float GetInterpolatedNoise(float x, float y);
		float Interpolate(float a, float b, float blend);
		float GetNoise(float x, float y);
		float GetPerlinNoise(float x, float y);
		float GetSmoothNoise(float x, float y);
	};

} }