// $Id: test_dsi.inl 14 2007-02-01 15:49:12Z mitza $

ACE_INLINE
DSI_Simple_Server::DSI_Simple_Server (CORBA::ORB_ptr orb,
                                      CORBA::Object_ptr target,//Simple_Server_ptr target,
                                      PortableServer::POA_ptr poa)
  :  orb_ (CORBA::ORB::_duplicate (orb)),
     target_ (CORBA::Object::_duplicate (target)),//Simple_Server::_duplicate (target)),
     poa_ (PortableServer::POA::_duplicate (poa))
{
}
