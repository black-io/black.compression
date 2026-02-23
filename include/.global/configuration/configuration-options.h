#pragma once


namespace Black
{
inline namespace Compression
{
inline namespace Global
{
namespace Configuration
{
	/**
		@brief	Regular definition for any particular compressor to be stored in registry.
	*/
	template< typename TCompressor >
	class CompressorDefinition final : private Black::NonTransferable
	{
	// Public life-time management.
	public:
		inline CompressorDefinition() noexcept = default;

	// Private state.
	private:
		RegistryStorage::Node<CompressorStorageItem<TCompressor>> m_node; // Node to store the compressor.
	};
}
}
}
}
