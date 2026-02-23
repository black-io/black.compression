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
		@brief	Regular option for compression algorithm.
	*/
	struct CompressionOption final
	{
		// Type of option identifier.
		using Id = CompressionOptionId;


		Id			id;		// Id used to identify the semantics of value.
		uint32_t	value;	// Usable value.
	};

	/**
		@brief	Regular option for decompression algorithm.
	*/
	struct DecompressionOption final
	{
		// Type of option identifier.
		using Id = DecompressionOptionId;


		Id			id;		// Id used to identify the semantics of value.
		uint32_t	value;	// Usable value.
	};
}
}
}
}
