// $Id: be_tmplinst.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "be_visitor_typecode/typecode_defn.h"
#include "ast_interface.h"
#include "ace/Singleton.h"
#include "ace/Synch.h"
#include "ace/Unbounded_Queue.h"

#if defined (ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION)
template class ACE_Singleton<TAO_CodeGen, ACE_SYNCH_RECURSIVE_MUTEX>;
#endif /* ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION */
