// File Line: 167
// RVA: 0x113B00
void __fastcall ARefCountMix<SSInstance>::dereference(ARefCountMix<SSInstance> *this)
{
  if ( this->i_ref_count-- == 1 )
  {
    this->i_ref_count = 0x80000000;
    (*(void (__fastcall **)(ARefCountMix<SSInstance> *))(*(_QWORD *)&this[-4].i_ref_count + 112i64))(this - 4);
  }
}

// File Line: 263
// RVA: 0x106980
void __fastcall ARefPtr<SSClosureInfoBase>::~ARefPtr<SSClosureInfoBase>(ARefPtr<SSClosureInfoBase> *this)
{
  SSClosureInfoBase *i_obj_p; // rax

  i_obj_p = this->i_obj_p;
  if ( this->i_obj_p )
  {
    if ( i_obj_p->i_ref_count-- == 1 )
    {
      i_obj_p->i_ref_count = 0x80000000;
      if ( i_obj_p != (SSClosureInfoBase *)-8i64 )
      {
        if ( i_obj_p )
          i_obj_p->vfptr->__vecDelDtor(i_obj_p, 1u);
      }
    }
  }
}

// File Line: 301
// RVA: 0x107A70
ARefPtr<SSClassDescBase> *__fastcall ARefPtr<SSClassDescBase>::operator=(
        ARefPtr<SSClassDescBase> *this,
        SSClassDescBase *obj_p)
{
  if ( this->i_obj_p != obj_p )
  {
    if ( obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))obj_p->vfptr->gap8)(obj_p);
    if ( this->i_obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))&this->i_obj_p->vfptr->gap8[8])(this->i_obj_p);
    this->i_obj_p = obj_p;
  }
  return this;
}

