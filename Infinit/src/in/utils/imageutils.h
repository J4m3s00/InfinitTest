#pragma once

#include <Infinit.h>
#include <FreeImage.h>
#include <in\utils\log.h>

template <class T> static void INPLACESWAP(T& a, T& b) {
	a ^= b; b ^= a; a ^= b;
}

	static BOOL SwapRedBlue32(FIBITMAP* dib) {
	if (FreeImage_GetImageType(dib) != FIT_BITMAP) {
		return FALSE;
	}

	const unsigned bytesperpixel = FreeImage_GetBPP(dib) / 8;
	if (bytesperpixel > 4 || bytesperpixel < 3) {
		return FALSE;
	}

	const unsigned height = FreeImage_GetHeight(dib);
	const unsigned pitch = FreeImage_GetPitch(dib);
	const unsigned lineSize = FreeImage_GetLine(dib);

	BYTE* line = FreeImage_GetBits(dib);
	for (unsigned y = 0; y < height; ++y, line += pitch) {
		for (BYTE* pixel = line; pixel < line + lineSize; pixel += bytesperpixel) {
			INPLACESWAP(pixel[0], pixel[2]);
		}
	}

	return TRUE;
}

namespace in { namespace utils {

	static INByte* LoadTexture(const INString& path, INUint* width, INUint* height, INUint* bbp, bool flipY = false)
	{
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP* dib = nullptr;
		const char* filename = path.c_str();
		fif = FreeImage_GetFileType(filename, 0);
		if (fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(filename);
		if (fif == FIF_UNKNOWN)
		{
			IN_ERROR("Could not load image '", filename, "'!");
			return nullptr;
		}

		if (FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, filename);

		if (!dib)
		{
			IN_ERROR("Could not load image '", filename, "'!");
			return nullptr;
		}

		FIBITMAP* bitmap = FreeImage_ConvertTo32Bits(dib);
		FreeImage_Unload(dib);

		INByte* pixels = FreeImage_GetBits(bitmap);
		INUint w = FreeImage_GetWidth(bitmap);
		INUint h = FreeImage_GetHeight(bitmap);
		INUint b = FreeImage_GetBPP(bitmap);

		if (flipY)
			FreeImage_FlipVertical(bitmap);

		if (FreeImage_GetRedMask(bitmap) == 0xff0000)
			SwapRedBlue32(bitmap);

		if (width)
			*width = w;
		if (height)
			*height = h;
		if (bbp)
			*bbp = b;

		int size = w * h * (b / 8);
		INByte* result = new INByte[size];
		memcpy(result, pixels, size);
		FreeImage_Unload(bitmap);
		return result;
	}



} }