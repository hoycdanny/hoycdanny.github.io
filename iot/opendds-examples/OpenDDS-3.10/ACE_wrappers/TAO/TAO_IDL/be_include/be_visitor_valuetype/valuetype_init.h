/* -*- c++ -*- */
//=============================================================================
/**
 *  @file    valuetype_init.h
 *
 *  $Id: valuetype_init.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  Coomon visitor for the Valuetype node.
 *  This one provides code generation for valuetype factory construct.
 *
 *
 *
 *  @author Boris Kolpackov <bosk@ipmce.ru>
 */
//=============================================================================


#ifndef _BE_VALUETYPE_VALUETYPE_INIT_H_
#define _BE_VALUETYPE_VALUETYPE_INIT_H_


/**
 * @class be_visitor_valuetype_init
 *
 * @brief be_visitor_valuetype_init
 *
 * This is a common visitor to generate valuetype factory constructs.
 */
class be_visitor_valuetype_init : public be_visitor_valuetype
{

public:
  /// constructor
  be_visitor_valuetype_init (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_valuetype_init (void);

public:

  void begin_public (void);
  void begin_private (void);
};

#endif /* _BE_VALUETYPE_VALUETYPE_INIT_H_ */
