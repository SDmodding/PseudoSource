// File Line: 47
// RVA: 0x1064E0
void __fastcall SSTypedClass::SSTypedClass(SSTypedClass *this, SSTypedClass *tclass)
{
  SSTypedClass *v2; // rbx
  SSClassDescBase *v3; // rcx

  v2 = this;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable';
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSContextClassBase::`vftable';
  this->i_class_p = tclass->i_class_p;
  this->vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable';
  v3 = tclass->i_item_type_p;
  v2->i_item_type_p = v3;
  if ( v3 )
    (*(void (__cdecl **)(SSClassDescBase *))v3->vfptr->gap8)(v3);
}

// File Line: 48
// RVA: 0x1078B0
void __fastcall SSTypedClass::~SSTypedClass(SSTypedClass *this)
{
  SSTypedClass *v1; // rbx
  SSClassDescBase *v2; // rcx

  v1 = this;
  this->vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable';
  v2 = this->i_item_type_p;
  if ( v2 )
  {
    ((void (__cdecl *)(SSClassDescBase *))v2->vfptr->dereference_delay)(v2);
    v1->i_item_type_p = 0i64;
  }
  v1->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
}

// File Line: 61
// RVA: 0x106550
void __fastcall SSTypedClass::SSTypedClass(SSTypedClass *this, const void **binary_pp)
{
  const void **v2; // rbx
  SSTypedClass *v3; // rdi
  ASymbol *v4; // rax
  eSSClassType v5; // ecx
  SSClassDescBase *v6; // rbx
  SSClassDescBase *v7; // rcx
  ASymbol result; // [rsp+48h] [rbp+10h]

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable';
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSContextClassBase::`vftable';
  this->vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable';
  this->i_item_type_p = 0i64;
  v4 = ASymbol::create_from_binary(&result, binary_pp);
  v3->i_class_p = SSBrain::get_class(v4);
  v5 = *(unsigned __int8 *)*v2;
  *v2 = (char *)*v2 + 1;
  v6 = SSClassDescBase::from_binary_ref(v5, v2);
  (*(void (__fastcall **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
  v7 = v3->i_item_type_p;
  if ( v7 )
    ((void (__cdecl *)(SSClassDescBase *))v7->vfptr->dereference_delay)(v7);
  v3->i_item_type_p = v6;
}

