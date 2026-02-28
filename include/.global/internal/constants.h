#pragma once


namespace Black
{
inline namespace Compression
{
inline namespace Global
{
namespace Internal
{
	/**
		@brief	Enumeration of posable compression options.
	*/
	enum class CompressionOptionId : uint32_t
	{
		AlgorithmId		= 0,	// Internal selection of algorithm supported by compressor.
		AlgorithmLevel,			// Level of selected algorithm.
		WindowLength,			// Internal meaning of compression window length.
	};

	/**
		@brief	Enumeration of posable decompression options.
	*/
	enum class DecompressionOptionId : uint32_t
	{
		WindowLength	= 0,	// Internal meaning of decompression window length.
	};
}
}
}
}
