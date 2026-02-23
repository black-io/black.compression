#pragma once


namespace Black
{
inline namespace Compression
{
inline namespace Global
{
inline namespace Compression
{
	/**
	*/
	class CompressorRegistry final : private Black::NonTransferable
	{
	// Public interface.
	public:
		/**
		*/
		Black::Hypothetical<const BasicCompressor&> FindCompressor( std::string_view compressor_name ) const;


		/**
		*/
		template< typename TVisiter >
		inline void EnumerateCompressors( TVisiter&& visiter ) const;

	// Private interface.
	private:
		//
		void EnsureRegistryCached() const;

		//
		void BuildCache() const;

	// Private non-state.
	private:
		mutable std::vector<const BasicCompressor*> m_cache; // Cache of registry.
	};
}
}
}
}
