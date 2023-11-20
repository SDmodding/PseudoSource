// File Line: 26
// RVA: 0xA6F7C0
void __fastcall CAkIndexable::CAkIndexable(CAkIndexable *this, unsigned int in_ulID)
{
  this->m_lRef = 1;
  this->key = in_ulID;
  this->vfptr = (CAkIndexableVtbl *)&CAkIndexable::`vftable;
}

// File Line: 31
// RVA: 0xA6F7E0
void __fastcall CAkIndexable::~CAkIndexable(CAkIndexable *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkIndexable::`vftable;
}

