// $Id: test_i.inl 2371 2014-10-08 20:50:17Z mesnierp $

ACE_INLINE
Callback_i::Callback_i (CORBA::ORB_ptr orb)
  :  orb_ (CORBA::ORB::_duplicate (orb))
{
}

ACE_INLINE
Simple_Server_i::Simple_Server_i (CORBA::ORB_ptr orb,
                                  int no_iterations)
  :  orb_ (CORBA::ORB::_duplicate (orb)),
     flag_ (0),
     invoker_ (),
     no_iterations_ (no_iterations)
{
}
