// $Id: test_i.inl 14 2007-02-01 15:49:12Z mitza $

ACE_INLINE
Database_i::Database_i (CORBA::ORB_ptr orb,
                        Test::Index max_range)
  :  orb_ (CORBA::ORB::_duplicate (orb)),
     max_range_ (max_range)
{
  ACE_NEW (this->elements_, Test::OctetSeq[this->max_range_]);
}
