#pragma once


namespace Black
{
inline namespace Compression
{
inline namespace Global
{
	template< typename TVisitor >
	inline void CompressorRegistry::EnumerateCompressors( TVisitor&& visitor ) const
	{
		static_assert( std::is_function_v<std::decay_t<TVisitor>>, "Type of given visitor should be functional." );
		static_assert(
			std::is_invocable_v<std::decay_t<TVisitor>, const Black::CompressorRegistry::BasicCompressor& >,
			"Given visitor should satisfy the signature `void ( const Black::CompressorRegistry::BasicCompressor& )`."
		);


		EnsureRegistryCached();
		for( const Configuration::BasicRegistryItem* registry_item : m_cache )
		{
			EXPECTS_DEBUG( registry_item != nullptr );
			visitor( registry_item->GetCompressor() );
		}
	}
}
}
}
