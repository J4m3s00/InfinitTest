#include "perlinnoise.h"
#include "maths_func.h"

namespace in { namespace maths {

	float PerlinNoise::AMPLITUDE = 10.0f; // 20.0f

	PerlinNoise::PerlinNoise(int seed)
		: roughness(0.3f), octaves(3)
	{
		m_Seed = seed;
	}

	std::vector<std::vector<float>> PerlinNoise::GenerateHeights(int vertexCount, int seed)
	{
		std::vector<std::vector<float>> heights;
		heights.resize(vertexCount);
		PerlinNoise noise(seed);
		for (int z = 0; z < vertexCount; z++)
		{
			heights[z].resize(vertexCount);
			for (int x = 0; x < vertexCount; x++)
			{
				float value = noise.GetPerlinNoise((float)x, (float)z) + AMPLITUDE;
				
				heights[z][x] = value;
			}
		}


		return heights;
	}

	float PerlinNoise::GetRandom(int seed)
	{
		srand(seed);
		return (rand() % 10000) / 10000.0f;
	}

	float PerlinNoise::GetPerlinNoise(float x, float y)
	{
		//float smoothFactor = 4.0f;
		//return GetInterpolatedNoise(x / roughness, y / roughness) * height;
		float total = 0.0f;
		float d = powf(2, octaves - 1);
		for (int i = 0; i < octaves; i++)
		{
			float freq = (float)(powf(2, (float)i) / d);
			float ampl = (float)powf(roughness, (float)i) * AMPLITUDE;
			float noise = GetInterpolatedNoise(x * freq, y * freq);
			total += noise * ampl;
		}
		float edgeFactor = GetEdgeFactor(x, y);
		return total + (1 - edgeFactor) * -1;
	}

	float PerlinNoise::GetSmoothNoise(float x, float y)
	{
		float corners = (GetNoise(x - 1, y - 1) + GetNoise(x + 1, y - 1) + GetNoise(x - 1, y + 1) + GetNoise(x + 1, y + 1)) / 16.0f;
		float sides = (GetNoise(x - 1, y) + GetNoise(x, y - 1) + GetNoise(x + 1, y) + GetNoise(x, y + 1)) / 8.0f;
		float center = GetNoise(x, y) / 4.0f;
		return corners + sides + center;
	}

	float PerlinNoise::GetNoise(float x, float y)
	{
		return (float)GetRandom((int)(x * 19872 + y * 21973 + m_Seed * 127)) * 2.0f - 1.0f;
	}

	float PerlinNoise::GetInterpolatedNoise(float x, float y)
	{
		int intX = (int)x;
		float fracX = x - intX;
		int intY = (int)y;
		float fracY = y - intY;

		float v1 = GetSmoothNoise((float)intX, (float)intY);
		float v2 = GetSmoothNoise((float)intX + 1, (float)intY);
		float v3 = GetSmoothNoise((float)intX, (float)intY + 1);
		float v4 = GetSmoothNoise((float)intX + 1, (float)intY + 1);
		float i1 = Interpolate(v1, v2, fracX);
		float i2 = Interpolate(v3, v4, fracX);
		return Interpolate(i1, i2, fracY);
	}

	float PerlinNoise::Interpolate(float a, float b, float blend)
	{
		double ft = blend * M_PI;
		float f = (float)((1.0f - cosf((float)ft)) * 0.5f);
		return a * (1.0f - f) + b * f;
	}

	float PerlinNoise::GetEdgeFactor(float x, float y)
	{
		float xFactor = GetEdgeFactor(x);
		float yFactor = GetEdgeFactor(y);
		return xFactor > yFactor ? yFactor : xFactor;
	}

	float PerlinNoise::GetEdgeFactor(float a)
	{
		//float disFromEdge;
		//float farEdge = WORLD_VERTEX_COUNT - 1;
		//if (a > farEdge / 2.0f)
		//	disFromEdge = farEdge - a;
		//else
		//	disFromEdge = a;
		//float edgePercent = farEdge * 0.09f;
		//float factor = disFromEdge / edgePercent;
		//return factor > 1 ? 1 : factor;
		return 0;
	}

} }