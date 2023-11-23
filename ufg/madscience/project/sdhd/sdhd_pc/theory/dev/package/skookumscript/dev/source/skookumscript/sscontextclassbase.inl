// File Line: 30
// RVA: 0x113B40
void __fastcall SSContextClassBase::dereference(SSContextClassBase *this)
{
  if ( this->i_ref_count-- == 1 )
  {
    this->i_ref_count = 0x80000000;
    ((void (__fastcall *)(SSContextClassBase *))this->vfptr[1].find_common_type)(this);
  }
}

// File Line: 86
// RVA: 0x117B20
ANamed *__fastcall SSContextClassBase::get_key_class_name(SSContextClassBase *this)
{
  return &this->i_class_p->ANamed;
}

// File Line: 96
// RVA: 0x117F60
SSMetaClass *__fastcall SSContextClassBase::get_metaclass(SSContextClassBase *this)
{
  return &this->i_class_p->i_metaclass;
}

// File Line: 133
// RVA: 0x10E180
void __fastcall SSContextClassBase::append_method(SSContextClassBase *this, SSMethodBase *method_p)
{
  this->i_class_p->vfptr[1].__vecDelDtor(this->i_class_p, (unsigned int)method_p);
}

// File Line: 171
// RVA: 0x10DE80
void __fastcall SSContextClassBase::append_coroutine(SSContextClassBase *this, SSCoroutineBase *coroutine_p)
{
  (*(void (__fastcall **)(SSClass *, SSCoroutineBase *))&this->i_class_p->vfptr[1].gap8[8])(
    this->i_class_p,
    coroutine_p);
}

// File Line: 194
// RVA: 0x11EBF0
__int64 __fastcall SSContextClassBase::is_coroutine_valid(SSContextClassBase *this, ASymbol *method_name)
{
  return (*(__int64 (__fastcall **)(SSClass *, ASymbol *))this->i_class_p->vfptr[1].gap8)(this->i_class_p, method_name);
}

// File Line: 205
// RVA: 0x11EB70
SSClassDescBase *__fastcall SSContextClassBase::is_coroutine_registered(
        SSContextClassBase *this,
        SSClassDescBase *coroutine_name)
{
  return this->i_class_p->vfptr[1].as_finalized_generic(this->i_class_p, coroutine_name);
}

// File Line: 222
// RVA: 0x10DF40
SSTypedName *__fastcall SSContextClassBase::append_data_member(
        SSContextClassBase *this,
        ASymbol *name,
        SSClassDescBase *type_p)
{
  return (SSTypedName *)((__int64 (__fastcall *)(SSClass *, ASymbol *, SSClassDescBase *))this->i_class_p->vfptr[1].as_unary_class)(
                          this->i_class_p,
                          name,
                          type_p);
}

// File Line: 241
// RVA: 0x115310
SSClass *__fastcall SSContextClassBase::find_data_scope(SSContextClassBase *this, ASymbol *name, __int64 check_path)
{
  return (SSClass *)((__int64 (__fastcall *)(SSClass *, ASymbol *, __int64))this->i_class_p->vfptr[1].as_unary_class)(
                      this->i_class_p,
                      name,
                      check_path);
}

