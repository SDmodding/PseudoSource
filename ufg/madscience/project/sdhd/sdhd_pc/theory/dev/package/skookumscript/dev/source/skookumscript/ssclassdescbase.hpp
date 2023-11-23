// File Line: 88
// RVA: 0x106CF0
void __fastcall SSClassDescBase::~SSClassDescBase(SSClassDescBase *this)
{
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
}

// File Line: 130
// RVA: 0x11E6F0
bool __fastcall SSClassDescBase::is_actor_instance(SSClassDescBase *this)
{
  return this->vfptr->is_actor_class(this) && !this->vfptr->is_metaclass(this);
}

// File Line: 201
// RVA: 0x117AD0
hkSeekableStreamReader *__fastcall Assembly::GetRCX(void *this)
{
  return (hkSeekableStreamReader *)this;
}

