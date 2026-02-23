#pragma once


namespace Black
{
inline namespace Compression
{
inline namespace Global
{
inline namespace Compression
{
namespace Configuration
{
	inline BasicRegistryItem::BasicRegistryItem( std::string_view name ) noexcept
		: m_name_hash{ std::hash<std::string_view>{}( name ) }
		, m_name{ name }
	{
	}

	template< typename TCompressor >
	inline Black::DebugName CompressorStorageItem<TCompressor>::GetDebugName()
	{
		return Black::DebugName{ Black::FormatString( "Storage for compressor '{}'", std::string_view{ TCompressor::CLASS_ID } ) };
	}

	template< typename TCompressor >
	inline CompressorStorageItem<TCompressor>::CompressorStorageItem() noexcept
		: BasicRegistryItem{ std::string_view{ TCompressor::CLASS_ID } }
	{
	}

	template< typename TCompressor >
	const Black::BasicCompressor& CompressorStorageItem<TCompressor>::GetCompressor() const
	{
		return m_compressor;
	}
}
}
}
}
}
