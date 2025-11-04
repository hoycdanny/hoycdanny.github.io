// $Id: Callback_i.inl 14 2007-02-01 15:49:12Z mitza $

ACE_INLINE
Callback_i::Callback_i (int expected_samples)
  : history_ (expected_samples)
  , remaining_samples_ (expected_samples)
{
}

ACE_INLINE ACE_Sample_History&
Callback_i::sample_history (void)
{
  return this->history_;
}
