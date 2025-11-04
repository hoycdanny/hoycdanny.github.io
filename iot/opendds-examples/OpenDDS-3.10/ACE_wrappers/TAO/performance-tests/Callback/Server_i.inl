// $Id: Server_i.inl 14 2007-02-01 15:49:12Z mitza $

ACE_INLINE
Server_i::Server_i (void)
  : done_ (0)
{
}

ACE_INLINE int
Server_i::done (void)
{
  return this->done_;
}
