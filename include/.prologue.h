#pragma once


// External dependencies.
#include <black/core/algorithms.h>
#include <black/core/static-lists.h>


// The library namespace definition.
#include ".bootstrap/namespace.h"

// Most global stuff.

// Generic compression algorithm.
#include ".global/compression/internal/constants.h"
#include ".global/compression/internal/structures.h"

#include ".global/compression/BasicCompressor.h"

// Compressor registry.
#include ".global/compression/configuration/configuration-list-items.h"
#include ".global/compression/configuration/aliases.h"
#include ".global/compression/configuration/configuration-options.h"
#include ".global/compression/CompressorRegistry.h"
