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
  SSClassDescBase *v1; // rbx

  v1 = this;
  return ((unsigned __int8 (*)(void))this->vfptr->is_actor_class)() && !v1->vfptr->is_metaclass(v1);
}

// File Line: 201
// RVA: 0x117AD0
hkSeekableStreamReader *__fastcall Assembly::GetRCX(void *this)
{
  return (hkSeekableStreamReader *)this;
}

