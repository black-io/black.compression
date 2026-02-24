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
		@brief	Interface of regular compressor.

		Interface declares the common interaction layer between entire framework and particular implementation of compression algorithm.
		Each implementation should support both compression and decompression algorithm functions.

		Each implementation of this interface should be totally headless. It should not rely on internal state while perform the compression or decompression.
		It should not store some information in thread-local storage. Only stack and non-shared heap storage may be used by algorithm to work.
		Both compression and decompression functions may be invoked at any time, in any order and at any thread.
	*/
	class BasicCompressor : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Regular buffer to be spent by algorithm while forming the output buffer.
		using SpendingBuffer = Black::PlainView<std::byte>;

		// Regular buffer to store the result of algorithm work.
		using OutputBuffer = Black::PlainView<std::byte>;

		// Regular buffer to feed the algorithm with data.
		using InputBuffer = Black::PlainView<const std::byte>;

		// Regular single option for compression algorithm.
		using CompressionOption = CompressionOption;

		// List of options to be used as configuration for compression algorithm.
		using CompressionOptions = Black::PlainView<const CompressionOption>;

		// Regular single option for decompression algorithm.
		using DecompressionOption = DecompressionOption;

		// List of options to be used as configuration for decompression algorithm.
		using DecompressionOptions = Black::PlainView<const DecompressionOption>;

		// Type of compressor information.
		using BasicInfo = BasicCompressorInfo;

	// Public virtual interface.
	public:
		/**
			@brief	Get the information about compressor.
		*/
		virtual const BasicInfo& GetInfo() const = 0;

		/**
			@brief	Perform the compression algorithm.

			For each implementation this method should perform valid compression of given `source` memory.
			The `destination` memory should be used only to store the compressed payload right from beginning of `destination`.
			It is valid case to store less data than length of `destination`. But it is not valid if `destination` carries not enough memory.
			In any case of incomplete compression or invalid result of compression the implementation should return empty output buffer.

			@param	destination	Buffer of consequent memory to store the result of compression.
			@param	source		Buffer filled with payload that should be compressed.
			@param	options		List of options to configure the compression algorithm.
			@return				The value returned is buffer of `destination` memory that store compressed payload.
			@retval	{}			In case the compression is failed or `destination` supplies not enough memory.
		*/
		virtual OutputBuffer Compress( SpendingBuffer&& destination, const InputBuffer& source, const CompressionOptions& options ) const = 0;

		/**
			@brief	Perform the decompression algorithm.

			For each implementation this method should perform the inversion of compression process, restoring the original payload from compressed data.
			The `destination` memory should be used only to store the decompressed payload right from beginning of `destination`.
			It is valid case to store less data than length of `destination`. But it is not valid if `destination` carries not enough memory.
			In any case of incomplete decompression or invalid result of decompression the implementation should return empty output buffer.

			@param	destination	Buffer of consequent memory to store the result of decompression.
			@param	source		Buffer filled of previously compressed payload, that should be now decompressed.
			@return				The value returned is buffer of `destination` memory that store uncompressed payload.
			@retval	{}			In case the compression failed or `destination` supplies not enough memory.
		*/
		virtual OutputBuffer Decompress( SpendingBuffer&& destination, const InputBuffer& source, const DecompressionOptions& options ) const = 0;
	};
}
}
}
}
