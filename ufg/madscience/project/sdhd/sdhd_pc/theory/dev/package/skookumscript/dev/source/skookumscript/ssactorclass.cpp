// File Line: 93
// RVA: 0x13CEE0
void __fastcall SSActorClass::track_memory(SSActorClass *this, AMemoryStats *mem_stats_p, bool skip_demand_loaded)
{
  SSActorClass *v3; // rdi
  bool v4; // bl
  AMemoryStats *v5; // rsi
  SSClass *v6; // rcx
  bool v7; // r14
  SSMethodBase **v8; // rbx
  unsigned __int64 i; // rbp
  SSMethodBase **v10; // rbx
  unsigned __int64 j; // rbp
  SSCoroutineBase **v12; // rbx
  unsigned __int64 k; // rdi

  v3 = this;
  v4 = skip_demand_loaded;
  v5 = mem_stats_p;
  v7 = 1;
  if ( !(this->i_flags & 2) )
  {
    v6 = this->i_superclass_p;
    if ( !v6 || !SSClass::is_demand_loaded(v6) )
      v7 = 0;
  }
  if ( v4 && v7 )
  {
    AMemoryStats::track_memory(
      v5,
      "SSActorClass",
      0x148u,
      0,
      8 * v3->i_subclasses.i_count + 8,
      8
    * (v3->i_subclasses.i_size
     + v3->i_data.i_size
     + v3->i_data_table.i_size
     + v3->i_methods.i_size
     + v3->i_coroutines.i_size
     + v3->i_class_data.i_size
     + v3->i_class_data_table.i_size
     + v3->i_class_methods.i_size
     + v3->i_instances.i_size)
    + 8,
      1u);
  }
  else
  {
    AMemoryStats::track_memory(
      v5,
      "SSActorClass",
      0x148u,
      0,
      8
    * (v3->i_class_data.i_count
     + v3->i_coroutines.i_count
     + v3->i_methods.i_count
     + v3->i_data.i_count
     + v3->i_class_methods.i_count
     + v3->i_subclasses.i_count
     + v3->i_data_table.i_count
     + v3->i_class_data_table.i_count
     + v3->i_instances.i_count)
    + 8,
      8
    * (v3->i_subclasses.i_size
     + v3->i_data.i_size
     + v3->i_data_table.i_size
     + v3->i_methods.i_size
     + v3->i_coroutines.i_size
     + v3->i_class_data.i_size
     + v3->i_class_data_table.i_size
     + v3->i_class_methods.i_size
     + v3->i_instances.i_size)
    + 8,
      1u);
    if ( v3->i_data.i_count )
      AMemoryStats::track_memory(v5, "SSTypedName", 0x10u, 0, 0, 0, v3->i_data.i_count);
    if ( v3->i_class_data.i_count )
      AMemoryStats::track_memory(v5, "SSTypedData", 0x18u, 0, 0, 0, v3->i_class_data.i_count);
    v8 = v3->i_methods.i_array_p;
    for ( i = (unsigned __int64)&v8[v3->i_methods.i_count]; (unsigned __int64)v8 < i; ++v8 )
    {
      if ( *v8 )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*v8)->vfptr[1].get_invoke_type)(*v8, v5);
    }
    v10 = v3->i_class_methods.i_array_p;
    for ( j = (unsigned __int64)&v10[v3->i_class_methods.i_count]; (unsigned __int64)v10 < j; ++v10 )
    {
      if ( *v10 )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*v10)->vfptr[1].get_invoke_type)(*v10, v5);
    }
    v12 = v3->i_coroutines.i_array_p;
    for ( k = (unsigned __int64)&v12[v3->i_coroutines.i_count]; (unsigned __int64)v12 < k; ++v12 )
    {
      if ( *v12 )
        ((void (__fastcall *)(SSCoroutineBase *, AMemoryStats *))(*v12)->vfptr[1].get_invoke_type)(*v12, v5);
    }
  }
  if ( v7 )
    AMemoryStats::track_memory(v5, "SSActorClass.demand", 0, 0, 0, 0, 1u);
}

// File Line: 169
// RVA: 0x126B50
SSActor *__fastcall SSActorClass::object_id_lookup(SSActorClass *this, SSObjectId *obj_id_p)
{
  SSObjectId *v2; // rbx
  SSActor *result; // rax

  v2 = obj_id_p;
  result = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
             (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&this->i_instances.i_count,
             &obj_id_p->i_name);
  v2->i_obj_p.i_obj_p = (SSInstance *)&result->vfptr;
  if ( result )
    v2->i_obj_p.i_ptr_id = result->i_ptr_id;
  else
    v2->i_obj_p.i_ptr_id = 0;
  v2->i_flags |= 4u;
  return result;
}

// File Line: 212
// RVA: 0x113A30
char __fastcall SSActorClass::demand_unload(SSActorClass *this)
{
  unsigned int v1; // edx

  v1 = this->i_flags;
  if ( (this->i_flags & 3) == 3 && !((v1 >> 2) & 1) )
  {
    if ( !this->i_instances.i_count )
    {
      SSClass::demand_unload_recurse((SSClass *)&this->vfptr);
      return 1;
    }
    this->i_flags = v1 | 8;
  }
  return 0;
}

// File Line: 420
// RVA: 0x1268C0
ASymbol *__fastcall SSActorClass::new_instance(SSActorClass *this)
{
  SSActorClass *v1; // rdi
  ASymbol *v2; // rbx
  SSActorClass *v3; // rdx

  v1 = this;
  v2 = (ASymbol *)AMemory::c_malloc_func(0x80ui64, "SSActor");
  if ( v2 )
  {
    v2[18].i_uid = ASymbolX_unnamed.i_uid;
    v3 = SSBrain::c_actor_class_p;
    if ( v1 )
      v3 = v1;
    SSDataInstance::SSDataInstance((SSDataInstance *)v2, (SSClass *)&v3->vfptr);
    *(_QWORD *)&v2->i_uid = &SSActor::`vftable';
    v2[20].i_uid = 0;
    *(_QWORD *)&v2[22].i_uid = 0i64;
    v2[24].i_uid = 0;
    v2[26].i_uid = 0;
    *(_QWORD *)&v2[28].i_uid = 0i64;
    v2[30].i_uid = 0;
    v2[19].i_uid = 4;
  }
  else
  {
    v2 = 0i64;
  }
  ++v2[4].i_uid;
  return v2;
}

// File Line: 436
// RVA: 0x131D90
void __fastcall SSActorClass::recurse_class_ctor(SSActorClass *this, SSInvokedMethod *imethod_p)
{
  SSClass::recurse_class_ctor((SSClass *)&this->vfptr, imethod_p);
}

