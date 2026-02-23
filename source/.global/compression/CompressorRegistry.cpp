#include <black/compression.h>


namespace Black
{
inline namespace Compression
{
inline namespace Global
{
inline namespace Compression
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/Compression/Registry";
}


	Black::Hypothetical<const BasicCompressor&> CompressorRegistry::FindCompressor( std::string_view class_name ) const
	{
		EnsureRegistryCached();

		const size_t name_hash = std::hash<std::string_view>{}( class_name );
		return Black::FindItem(
			m_cache,
			[name_hash]( const Configuration::BasicRegistryItem* registry_item )
			{
				EXPECTS_DEBUG( registry_item != nullptr );
				return registry_item->GetNameHash() == name_hash;
			}
		).Transform(
			[class_name]( const Configuration::BasicRegistryItem* registry_item ) -> const Black::BasicCompressor&
			{
				EXPECTS_DEBUG( registry_item != nullptr );
				ENSURES_DEBUG( registry_item->GetName() == class_name );
				return registry_item->GetCompressor();
			}
		);
	}

	void CompressorRegistry::EnsureRegistryCached() const
	{
		CRET( !m_cache.empty() );
		BuildCache();
	}

	void CompressorRegistry::BuildCache() const
	{
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Perform the caching of Compressor registry." );

		Configuration::RegistryStorage registry{};
		CRETD( registry.IsEmpty(), , LOG_CHANNEL, "No entities stored in registry." );

		m_cache.clear();
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Reading the Compressor registry." );
		for( const Configuration::BasicRegistryItem& registry_item : registry )
		{
			m_cache.emplace_back( &registry_item );
		}

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Compressor registry cached with {} entities.", m_cache.size() );
	}
}
}
}
}
