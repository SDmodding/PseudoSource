// File Line: 39
// RVA: 0x107930
void __fastcall SSUnaryParam::~SSUnaryParam(SSUnaryParam *this)
{
  SSUnaryParam *v1; // rbx
  SSExpressionBase *v2; // rcx
  SSClassDescBase *v3; // rcx

  v1 = this;
  this->vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable';
  v2 = this->i_default_p;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v3 = v1->i_type_p.i_obj_p;
  if ( v3 )
    (*(void (__cdecl **)(SSClassDescBase *))&v3->vfptr->gap8[8])(v3);
  v1->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
}

// File Line: 76
// RVA: 0x1066B0
void __fastcall SSUnaryParam::SSUnaryParam(SSUnaryParam *this, eSSParameter type, char type_info, const void **binary_pp)
{
  const void **v4; // rsi
  unsigned __int8 v5; // r14
  eSSParameter v6; // ebp
  SSUnaryParam *v7; // rbx
  eSSClassType v8; // ecx
  SSClassDescBase *v9; // rax
  SSClassDescBase *v10; // rdi
  SSClassDescBase *v11; // rcx
  ASymbol result; // [rsp+58h] [rbp+10h]

  v4 = binary_pp;
  v5 = type_info;
  v6 = type;
  v7 = this;
  this->i_name = (ASymbol)ASymbol::create_from_binary(&result, binary_pp)->i_uid;
  v7->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
  v7->vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable';
  v7->i_type_p.i_obj_p = 0i64;
  v8 = *(unsigned __int8 *)*v4;
  *v4 = (char *)*v4 + 1;
  v9 = SSClassDescBase::from_binary_ref(v8, v4);
  v10 = v9;
  if ( v7->i_type_p.i_obj_p != v9 )
  {
    if ( v9 )
      (*(void (__fastcall **)(SSClassDescBase *))v9->vfptr->gap8)(v9);
    v11 = v7->i_type_p.i_obj_p;
    if ( v11 )
      (*(void (__cdecl **)(SSClassDescBase *))&v11->vfptr->gap8[8])(v11);
    v7->i_type_p.i_obj_p = v10;
  }
  if ( v6 == 1 )
  {
    *v4 = (char *)*v4 + 2;
    v7->i_default_p = SSExpressionBase::from_binary_new((eSSExprType)v5, v4);
  }
  else
  {
    v7->i_default_p = 0i64;
  }
}

// File Line: 251
// RVA: 0x10F090
SSParameterBase *__fastcall SSUnaryParam::as_finalized_generic(SSUnaryParam *this, SSClassDescBase *scope_type)
{
  SSClassDescBase *v2; // rbp
  SSUnaryParam *v3; // rsi
  __int64 v4; // rdi
  SSExpressionBase *v5; // rcx
  _DWORD *v6; // rbx
  __int64 v7; // rax
  SSClass *v8; // rcx

  v2 = scope_type;
  v3 = this;
  v4 = 0i64;
  v5 = this->i_default_p;
  if ( v5 )
    v4 = (*((__int64 (__cdecl **)(SSExpressionBase *))&v5->vfptr->__vecDelDtor + 1))(v5);
  v6 = AMemory::c_malloc_func(0x20ui64, "SSUnaryParam");
  if ( !v6 )
    return 0i64;
  v7 = (__int64)v3->i_type_p.i_obj_p->vfptr->as_finalized_generic(v3->i_type_p.i_obj_p, v2);
  v6[2] = v3->i_name.i_uid;
  *(_QWORD *)v6 = &SSParameterBase::`vftable';
  *(_QWORD *)v6 = &SSUnaryParam::`vftable';
  v8 = SSBrain::c_object_class_p;
  if ( v7 )
    v8 = (SSClass *)v7;
  *((_QWORD *)v6 + 2) = v8;
  if ( v8 )
    (*(void (__cdecl **)(SSClass *))v8->vfptr->gap8)(v8);
  *((_QWORD *)v6 + 3) = v4;
  return (SSParameterBase *)v6;
}

// File Line: 284
// RVA: 0x11EE10
__int64 __fastcall Scaleform::DelegatedFile::Read(SSUnaryParam *this)
{
  return ((__int64 (*)(void))this->i_type_p.i_obj_p->vfptr->is_generic)();
}

// File Line: 317
// RVA: 0x13E870
void __fastcall SSUnaryParam::track_memory(SSUnaryParam *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSUnaryParam *v3; // rbx
  SSExpressionBase *v4; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSUnaryParam", 0x20u, 0, 0, 0, 1u);
  v4 = v3->i_default_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
}

