// $Id: be_union_label.h 1861 2011-08-31 16:18:08Z mesnierp $

#ifndef BE_UNION_LABEL_H
#define BE_UNION_LABEL_H

#include "ast_union_label.h"

class be_visitor;

class be_union_label : public virtual AST_UnionLabel
{
public:
  be_union_label (AST_UnionLabel::UnionLabel ul,
                  AST_Expression *v);

  // Visiting.
  virtual int accept (be_visitor *visitor);

  // Cleanup.
  virtual void destroy (void);
};

#endif
