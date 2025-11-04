// $Id: ping_i.inl 14 2007-02-01 15:49:12Z mitza $

ACE_INLINE
PingObject_i::PingObject_i (CORBA::ORB_ptr orb,
                            PortableServer::POA_ptr poa)
  :  orb_ (CORBA::ORB::_duplicate (orb)),
     poa_ (PortableServer::POA::_duplicate (poa))
{
}
