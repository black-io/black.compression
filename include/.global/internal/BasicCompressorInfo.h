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
		@brief
	*/
	class BasicCompressorInfo
	{
	// Public inner types.
	public:
		// Regular single option for compression algorithm.
		using CompressionOptionId = CompressionOptionId;

		// Regular single option for decompression algorithm.
		using DecompressionOptionId = DecompressionOptionId;

	// Public virtual interface.
	public:
		/**
			@brief	Get the name of compressor.
		*/
		virtual std::string_view GetName() const = 0;

		/**
			@brief	Get description about compressor.
		*/
		virtual std::string_view GetDescription() const = 0;

		/**
			@brief	Get version of compressor.
		*/
		virtual uint32_t GetVersion() const = 0;

		/**
			@brief	Get collection of available options the compression algorithm supports.

			@return				The value returned is collection of options the algorithm may consume.
			@retval	{}			Empty list returned in case of algorithm support no options.
		*/
		virtual Black::PlainView<const CompressionOptionId> GetAvailableCompressionOptions() const = 0;

		/**
			@brief	Get collection of available values for given compressor option.

			@param	option_id	Id of option, which available values are interested.
			@return				The value returned is collection of available values for given `option_id`.
			@return	{}			Empty collection indicates the algorithm consumes any value.
		*/
		virtual Black::PlainView<const uint32_t> GetAvailableOptionValues( const CompressionOptionId option_id ) const = 0;

		/**
			@brief	Get collection of available options the decompression algorithm supports.

			@return				The value returned is collection of options the algorithm may consume.
			@retval	{}			Empty list returned in case of algorithm support no options.
		*/
		virtual Black::PlainView<const DecompressionOptionId> GetAvailableDecompressionOptions() const = 0;

		/**
			@brief	Get collection of available values for given compressor option.

			@param	option_id	Id of option, which available values are interested.
			@return				The value returned is collection of available values for given `option_id`.
			@return	{}			Empty collection indicates the algorithm consumes any value.
		*/
		virtual Black::PlainView<const uint32_t> GetAvailableOptionValues( const DecompressionOptionId option_id ) const = 0;
	};
}
}
}
}
