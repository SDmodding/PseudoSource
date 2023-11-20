// File Line: 167
// RVA: 0x113B00
void __fastcall ARefCountMix<SSInstance>::dereference(ARefCountMix<SSInstance> *this)
{
  bool v1; // zf

  v1 = this->i_ref_count-- == 1;
  if ( v1 )
  {
    this->i_ref_count = 2147483648;
    (*(void (__fastcall **)(ARefCountMix<SSInstance> *))(*(_QWORD *)&this[-4].i_ref_count + 112i64))(this - 4);
  }
}

// File Line: 263
// RVA: 0x106980
void __fastcall ARefPtr<SSClosureInfoBase>::~ARefPtr<SSClosureInfoBase>(ARefPtr<SSClosureInfoBase> *this)
{
  SSClosureInfoBase *v1; // rax
  bool v2; // zf

  v1 = this->i_obj_p;
  if ( this->i_obj_p )
  {
    v2 = v1->i_ref_count-- == 1;
    if ( v2 )
    {
      v1->i_ref_count = 2147483648;
      if ( v1 != (SSClosureInfoBase *)-8i64 && &v1->i_ref_count != (unsigned int *)8 )
        v1->vfptr->__vecDelDtor(v1, 1u);
    }
  }
}

// File Line: 301
// RVA: 0x107A70
ARefPtr<SSClassDescBase> *__fastcall ARefPtr<SSClassDescBase>::operator=(ARefPtr<SSClassDescBase> *this, SSClassDescBase *obj_p)
{
  SSClassDescBase *v2; // rdi
  ARefPtr<SSClassDescBase> *v3; // rbx

  v2 = obj_p;
  v3 = this;
  if ( this->i_obj_p != obj_p )
  {
    if ( obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))obj_p->vfptr->gap8)(obj_p);
    if ( v3->i_obj_p )
      (*(void (**)(void))&v3->i_obj_p->vfptr->gap8[8])();
    v3->i_obj_p = v2;
  }
  return v3;
}

