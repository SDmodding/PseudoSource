// File Line: 56
// RVA: 0x107900
void __fastcall SSTypedName::~SSTypedName(SSTypedName *this)
{
  SSClassDescBase *i_obj_p; // rcx

  i_obj_p = this->i_type_p.i_obj_p;
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
}

