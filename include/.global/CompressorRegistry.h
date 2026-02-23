#pragma once


namespace Black
{
inline namespace Compression
{
inline namespace Global
{
	/**
		@brief	Compressor registry implementation.

		Object of this type can be created at any time and used widely. It does not directly represent the storage of compressor registry.
		The registry is organized statically, using `Black::StaticList`. All compressors are registered also statically.
		Any implementation of `Black::BasicCompressor` can be registered using the `CompressorDefinition` inner template.

		Once the instance of `CompressorRegistry` is used, it build the cache of registry only once. After the cache is built,
		the `CompressorRegistry` instance can be used to find or enumerate the available compressors.
	*/
	class CompressorRegistry final
	{
	// Public inner types.
	public:
		// Basic compressor. All particular compressors should be derived from this type.
		using BasicCompressor = Internal::BasicCompressor;

		// Particular compressor class definition. Allows to register the particular compressor in registry.
		template< typename TCompressor >
		using CompressorDefinition = Configuration::CompressorDefinition<TCompressor>;

	// Public interface.
	public:
		/**
			@brief	Find the compressor by given `class_name`.

			This method return hypothesis. It may be empty if there is no compressor is registered with given `class_name`.

			@param	class_name	Name of class the desired compressor should be.
			@return				The value returned is hypothesis of the compressor found.
		*/
		Black::Hypothetical<const BasicCompressor&> FindCompressor( std::string_view class_name ) const;


		/**
			@brief	Enumerate all the registered compressors.

			Performs the visiting all registered compressors with given `visitor`. As result, all currently possible compressors may be known through `visitor`.

			@tparam	TVisitor	Type of `visitor`.
			@param	visitor		Given visitor to be used on compressor visit.
		*/
		template< typename TVisitor >
		inline void EnumerateCompressors( TVisitor&& visitor ) const;

	// Private interface.
	private:
		// Ensure the cache of compressor registry is built.
		void EnsureRegistryCached() const;

		// Perform the compressor registry caching.
		void BuildCache() const;

	// Private non-state.
	private:
		mutable std::vector<const Configuration::BasicRegistryItem*> m_cache; // Cache of registry.
	};
}
}
}
