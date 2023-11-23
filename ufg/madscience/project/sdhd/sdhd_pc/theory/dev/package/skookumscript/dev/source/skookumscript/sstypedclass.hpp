// File Line: 47
// RVA: 0x1064E0
void __fastcall SSTypedClass::SSTypedClass(SSTypedClass *this, SSTypedClass *tclass)
{
  SSClassDescBase *i_item_type_p; // rcx

  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSContextClassBase::`vftable;
  this->i_class_p = tclass->i_class_p;
  this->vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
  i_item_type_p = tclass->i_item_type_p;
  this->i_item_type_p = i_item_type_p;
  if ( i_item_type_p )
    (*(void (__fastcall **)(SSClassDescBase *))i_item_type_p->vfptr->gap8)(i_item_type_p);
}

// File Line: 48
// RVA: 0x1078B0
void __fastcall SSTypedClass::~SSTypedClass(SSTypedClass *this)
{
  SSClassDescBase *i_item_type_p; // rcx

  this->vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
  i_item_type_p = this->i_item_type_p;
  if ( i_item_type_p )
  {
    i_item_type_p->vfptr->dereference_delay(i_item_type_p);
    this->i_item_type_p = 0i64;
  }
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
}

// File Line: 61
// RVA: 0x106550
void __fastcall SSTypedClass::SSTypedClass(SSTypedClass *this, const void **binary_pp)
{
  ASymbol *v4; // rax
  eSSClassType v5; // ecx
  SSClassDescBase *v6; // rbx
  SSClassDescBase *i_item_type_p; // rcx
  ASymbol result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSContextClassBase::`vftable;
  this->vfptr = (SSClassDescBaseVtbl *)&SSTypedClass::`vftable;
  this->i_item_type_p = 0i64;
  v4 = ASymbol::create_from_binary(&result, binary_pp);
  this->i_class_p = SSBrain::get_class(v4);
  v5 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v6 = SSClassDescBase::from_binary_ref(v5, binary_pp);
  (*(void (__fastcall **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
  i_item_type_p = this->i_item_type_p;
  if ( i_item_type_p )
    i_item_type_p->vfptr->dereference_delay(i_item_type_p);
  this->i_item_type_p = v6;
}

