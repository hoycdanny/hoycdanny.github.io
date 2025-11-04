// $Id: Compressor_Factory.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "tao/Compression/Compressor_Factory.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  CompressorFactory::CompressorFactory (::Compression::CompressorId
                                        compressor_id)
    : compressor_id_ (compressor_id)
  {
  }

  ::Compression::CompressorId
  CompressorFactory::compressor_id (void)
  {
    return compressor_id_;
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL
