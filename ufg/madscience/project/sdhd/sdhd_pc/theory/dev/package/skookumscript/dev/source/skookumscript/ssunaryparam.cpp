// File Line: 39
// RVA: 0x107930
void __fastcall SSUnaryParam::~SSUnaryParam(SSUnaryParam *this)
{
  SSExpressionBase *i_default_p; // rcx
  SSClassDescBase *i_obj_p; // rcx

  this->vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
  i_default_p = this->i_default_p;
  if ( i_default_p )
    i_default_p->vfptr->__vecDelDtor(i_default_p, 1u);
  i_obj_p = this->i_type_p.i_obj_p;
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
  this->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
}

// File Line: 76
// RVA: 0x1066B0
void __fastcall SSUnaryParam::SSUnaryParam(
        SSUnaryParam *this,
        eSSParameter type,
        unsigned __int8 type_info,
        const void **binary_pp)
{
  eSSClassType v8; // ecx
  SSClassDescBase *v9; // rax
  SSClassDescBase *v10; // rdi
  SSClassDescBase *i_obj_p; // rcx
  ASymbol result; // [rsp+58h] [rbp+10h] BYREF

  this->i_name = (ASymbol)ASymbol::create_from_binary(&result, binary_pp)->i_uid;
  this->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
  this->vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
  this->i_type_p.i_obj_p = 0i64;
  v8 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v9 = SSClassDescBase::from_binary_ref(v8, binary_pp);
  v10 = v9;
  if ( this->i_type_p.i_obj_p != v9 )
  {
    if ( v9 )
      (*(void (__fastcall **)(SSClassDescBase *))v9->vfptr->gap8)(v9);
    i_obj_p = this->i_type_p.i_obj_p;
    if ( i_obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
    this->i_type_p.i_obj_p = v10;
  }
  if ( type == SSParameter_unary_default )
  {
    *binary_pp = (char *)*binary_pp + 2;
    this->i_default_p = SSExpressionBase::from_binary_new((eSSExprType)type_info, binary_pp);
  }
  else
  {
    this->i_default_p = 0i64;
  }
}

// File Line: 251
// RVA: 0x10F090
SSParameterBase *__fastcall SSUnaryParam::as_finalized_generic(SSUnaryParam *this, SSClassDescBase *scope_type)
{
  __int64 v4; // rdi
  SSExpressionBase *i_default_p; // rcx
  _DWORD *v6; // rbx
  SSClassDescBase *v7; // rax
  SSClass *v8; // rcx

  v4 = 0i64;
  i_default_p = this->i_default_p;
  if ( i_default_p )
    v4 = (*((__int64 (__fastcall **)(SSExpressionBase *))&i_default_p->vfptr->__vecDelDtor + 1))(i_default_p);
  v6 = AMemory::c_malloc_func(0x20ui64, "SSUnaryParam");
  if ( !v6 )
    return 0i64;
  v7 = this->i_type_p.i_obj_p->vfptr->as_finalized_generic(this->i_type_p.i_obj_p, scope_type);
  v6[2] = this->i_name.i_uid;
  *(_QWORD *)v6 = &SSParameterBase::`vftable;
  *(_QWORD *)v6 = &SSUnaryParam::`vftable;
  v8 = SSBrain::c_object_class_p;
  if ( v7 )
    v8 = (SSClass *)v7;
  *((_QWORD *)v6 + 2) = v8;
  if ( v8 )
    (*(void (__fastcall **)(SSClass *))v8->vfptr->gap8)(v8);
  *((_QWORD *)v6 + 3) = v4;
  return (SSParameterBase *)v6;
}

// File Line: 284
// RVA: 0x11EE10
__int64 __fastcall Scaleform::DelegatedFile::Read(SSUnaryParam *this)
{
  return ((__int64 (__fastcall *)(SSClassDescBase *))this->i_type_p.i_obj_p->vfptr->is_generic)(this->i_type_p.i_obj_p);
}

// File Line: 317
// RVA: 0x13E870
void __fastcall SSUnaryParam::track_memory(SSUnaryParam *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_default_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSUnaryParam", 0x20u, 0, 0, 0, 1u);
  i_default_p = this->i_default_p;
  if ( i_default_p )
    i_default_p->vfptr->track_memory(i_default_p, mem_stats_p);
}

