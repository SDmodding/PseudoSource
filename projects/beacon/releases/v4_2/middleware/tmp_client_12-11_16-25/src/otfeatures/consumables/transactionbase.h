// File Line: 17
// RVA: 0x132F3CC
__int64 __fastcall OSuitePrivate::ZConsumableTransactionBase::GetId(OSuitePrivate::ZConsumableTransactionBase *this)
{
  return 924933i64;
}

// File Line: 18
// RVA: 0x132F710
__int64 __fastcall OSuitePrivate::ZConsumableTransactionBase::GetState(OSuitePrivate::ZConsumableTransactionBase *this)
{
  return (unsigned int)this->m_eState;
}

// File Line: 19
// RVA: 0x133073C
__int64 __fastcall OSuitePrivate::ZConsumableTransactionBase::SetState(OSuitePrivate::ZConsumableTransactionBase *this, OSuite::ITransactionState state)
{
  this->m_eState = state;
  return 0i64;
}

