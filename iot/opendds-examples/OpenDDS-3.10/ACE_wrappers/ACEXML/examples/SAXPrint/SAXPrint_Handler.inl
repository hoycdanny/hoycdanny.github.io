// -*- C++ -*-  $Id: SAXPrint_Handler.inl 14 2007-02-01 15:49:12Z mitza $

ACEXML_INLINE void
ACEXML_SAXPrint_Handler::inc_indent (void)
{
  this->indent_ += 1;
}

ACEXML_INLINE void
ACEXML_SAXPrint_Handler::dec_indent (void)
{
  this->indent_ -= 1;
}
