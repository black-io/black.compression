#pragma once


// External dependencies.
#include <black/core/algorithms.h>
#include <black/core/static-lists.h>


// The library namespace definition.
#include ".bootstrap/namespace.h"

// Most global stuff.

// Generic compression algorithm.
#include ".global/internal/constants.h"
#include ".global/internal/structures.h"
#include ".global/internal/BasicCompressor.h"

// Configuration of library.
#include ".global/configuration/configuration-list-items.h"
#include ".global/configuration/aliases.h"
#include ".global/configuration/configuration-options.h"

// Implementation of registry.
#include ".global/CompressorRegistry.h"
