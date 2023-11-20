// File Line: 56
// RVA: 0x107900
void __fastcall SSTypedName::~SSTypedName(SSTypedName *this)
{
  SSClassDescBase *v1; // rcx

  v1 = this->i_type_p.i_obj_p;
  if ( v1 )
    (*(void (**)(void))&v1->vfptr->gap8[8])();
}

