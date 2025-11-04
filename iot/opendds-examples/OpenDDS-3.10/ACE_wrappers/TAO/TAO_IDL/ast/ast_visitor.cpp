// $Id: ast_visitor.cpp 2504 2015-04-30 15:41:17Z mitza $

#include "ast_visitor.h"
#include "ace/config-all.h"

ast_visitor::ast_visitor (void)
{
}

ast_visitor::~ast_visitor (void)
{
}

int ast_visitor::visit_fixed (AST_Fixed *)
{
  return 0;
}
