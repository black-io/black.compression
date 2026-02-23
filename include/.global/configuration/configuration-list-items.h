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
		@brief	Abstraction of regular item for registry of compressors.
	*/
	class BasicRegistryItem : private Black::NonTransferable
	{
	// Public interface.
	public:
		// Get the hash of compressor name.
		inline const size_t GetNameHash() const			{ return m_name_hash; };

		// Get the name of stored compressor.
		inline const std::string_view GetName() const	{ return m_name; };

	// Public virtual interface.
	public:
		// Get the compressor instance stored by this item.
		virtual const Internal::BasicCompressor& GetCompressor() const = 0;

	// Heirs interface.
	protected:
		inline BasicRegistryItem( std::string_view name ) noexcept;

	// private state.
	private:
		size_t				m_name_hash;	// Hash of stored compressor name.
		std::string_view	m_name;			// Name of stored compressor.
	};

	/**
		@brief	Storage template to place the instance of given compressor into registry.

		@tparam	TCompressor	Compressor class to be stored in registry.
	*/
	template< typename TCompressor >
	class CompressorStorageItem final : public BasicRegistryItem
	{
		static_assert(
			std::is_base_of_v<Internal::BasicCompressor, TCompressor>,
			"Given `TCompressor` should be derived from `Black::CompressorRegistry::BasicCompressor` type."
		);

	// Public static interface.
	public:
		// Get the debug name.
		static inline Black::DebugName GetDebugName();

	// Public life-time management.
	public:
		inline CompressorStorageItem() noexcept;

	// Private interface.
	private:
		/// @see	BasicRegistryItem::GetCompressor
		const Internal::BasicCompressor& GetCompressor() const override;

	// Private state.
	private:
		TCompressor m_compressor; // Instance of stored compressor.
	};
}
}
}
}
