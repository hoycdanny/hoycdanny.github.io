/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    native_ch.h
 *
 *  $Id: native_ch.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  Concrete visitor for Native generating code in the client header.
 *
 *
 *  @author Johnny Willemsen
 */
//=============================================================================


#ifndef _BE_VISITOR_NATIVE_NATIVE_CH_H_
#define _BE_VISITOR_NATIVE_NATIVE_CH_H_

/**
 * @class be_visitor_native_ch
 *
 * @brief be_visitor_native_ch
 *
 * This is the base visitor for enum for the header file
 */
class be_visitor_native_ch : public be_visitor_scope
{
public:
  /// conenumor
  be_visitor_native_ch (be_visitor_context *ctx);

  /// deenumor
  ~be_visitor_native_ch (void);

  /// visit native.
  virtual int visit_native (be_native *node);
};

#endif /* _BE_VISITOR_NATIVE_NATIVE_CH_H_ */
