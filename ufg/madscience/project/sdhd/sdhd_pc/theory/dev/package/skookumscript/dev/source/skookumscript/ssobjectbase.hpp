// File Line: 99
// RVA: 0x104EA0
void __fastcall SSData::SSData(SSData *this)
{
  this->i_name = (ASymbol)ASymbol::get_null()->i_uid;
}

// File Line: 129
// RVA: 0xBD660
void __fastcall SSObjectBase::~SSObjectBase(SSObjectBase *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
}

