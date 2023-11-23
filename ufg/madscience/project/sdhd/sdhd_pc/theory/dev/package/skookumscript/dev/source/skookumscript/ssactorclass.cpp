// File Line: 93
// RVA: 0x13CEE0
void __fastcall SSActorClass::track_memory(SSActorClass *this, AMemoryStats *mem_stats_p, bool skip_demand_loaded)
{
  SSClass *i_superclass_p; // rcx
  bool v7; // r14
  SSMethodBase **i_array_p; // rbx
  SSMethodBase **i; // rbp
  SSMethodBase **v10; // rbx
  SSMethodBase **j; // rbp
  SSCoroutineBase **v12; // rbx
  SSCoroutineBase **k; // rdi

  v7 = 1;
  if ( (this->i_flags & 2) == 0 )
  {
    i_superclass_p = this->i_superclass_p;
    if ( !i_superclass_p || !SSClass::is_demand_loaded(i_superclass_p) )
      v7 = 0;
  }
  if ( skip_demand_loaded && v7 )
  {
    AMemoryStats::track_memory(
      mem_stats_p,
      "SSActorClass",
      0x148u,
      0,
      8 * this->i_subclasses.i_count + 8,
      8
    * (this->i_subclasses.i_size
     + this->i_data.i_size
     + this->i_data_table.i_size
     + this->i_methods.i_size
     + this->i_coroutines.i_size
     + this->i_class_data.i_size
     + this->i_class_data_table.i_size
     + this->i_class_methods.i_size
     + this->i_instances.i_size)
    + 8,
      1u);
  }
  else
  {
    AMemoryStats::track_memory(
      mem_stats_p,
      "SSActorClass",
      0x148u,
      0,
      8
    * (this->i_class_data.i_count
     + this->i_coroutines.i_count
     + this->i_methods.i_count
     + this->i_data.i_count
     + this->i_class_methods.i_count
     + this->i_subclasses.i_count
     + this->i_data_table.i_count
     + this->i_class_data_table.i_count
     + this->i_instances.i_count)
    + 8,
      8
    * (this->i_subclasses.i_size
     + this->i_data.i_size
     + this->i_data_table.i_size
     + this->i_methods.i_size
     + this->i_coroutines.i_size
     + this->i_class_data.i_size
     + this->i_class_data_table.i_size
     + this->i_class_methods.i_size
     + this->i_instances.i_size)
    + 8,
      1u);
    if ( this->i_data.i_count )
      AMemoryStats::track_memory(mem_stats_p, "SSTypedName", 0x10u, 0, 0, 0, this->i_data.i_count);
    if ( this->i_class_data.i_count )
      AMemoryStats::track_memory(mem_stats_p, "SSTypedData", 0x18u, 0, 0, 0, this->i_class_data.i_count);
    i_array_p = this->i_methods.i_array_p;
    for ( i = &i_array_p[this->i_methods.i_count]; i_array_p < i; ++i_array_p )
    {
      if ( *i_array_p )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*i_array_p)->vfptr[1].get_invoke_type)(
          *i_array_p,
          mem_stats_p);
    }
    v10 = this->i_class_methods.i_array_p;
    for ( j = &v10[this->i_class_methods.i_count]; v10 < j; ++v10 )
    {
      if ( *v10 )
        ((void (__fastcall *)(SSMethodBase *, AMemoryStats *))(*v10)->vfptr[1].get_invoke_type)(*v10, mem_stats_p);
    }
    v12 = this->i_coroutines.i_array_p;
    for ( k = &v12[this->i_coroutines.i_count]; v12 < k; ++v12 )
    {
      if ( *v12 )
        ((void (__fastcall *)(SSCoroutineBase *, AMemoryStats *))(*v12)->vfptr[1].get_invoke_type)(*v12, mem_stats_p);
    }
  }
  if ( v7 )
    AMemoryStats::track_memory(mem_stats_p, "SSActorClass.demand", 0, 0, 0, 0, 1u);
}

// File Line: 169
// RVA: 0x126B50
SSActor *__fastcall SSActorClass::object_id_lookup(SSActorClass *this, SSObjectId *obj_id_p)
{
  SSActor *result; // rax

  result = APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_instances, &obj_id_p->i_name);
  obj_id_p->i_obj_p.i_obj_p = result;
  if ( result )
    obj_id_p->i_obj_p.i_ptr_id = result->i_ptr_id;
  else
    obj_id_p->i_obj_p.i_ptr_id = 0;
  obj_id_p->i_flags |= 4u;
  return result;
}

// File Line: 212
// RVA: 0x113A30
char __fastcall SSActorClass::demand_unload(SSActorClass *this)
{
  unsigned int i_flags; // edx

  i_flags = this->i_flags;
  if ( (this->i_flags & 3) == 3 && (i_flags & 4) == 0 )
  {
    if ( !this->i_instances.i_count )
    {
      SSClass::demand_unload_recurse(this);
      return 1;
    }
    this->i_flags = i_flags | 8;
  }
  return 0;
}

// File Line: 420
// RVA: 0x1268C0
ASymbol *__fastcall SSActorClass::new_instance(SSActorClass *this)
{
  ASymbol *v2; // rbx
  SSActorClass *v3; // rdx

  v2 = (ASymbol *)AMemory::c_malloc_func(0x80ui64, "SSActor");
  if ( v2 )
  {
    v2[18].i_uid = ASymbolX_unnamed.i_uid;
    v3 = SSBrain::c_actor_class_p;
    if ( this )
      v3 = this;
    SSDataInstance::SSDataInstance((SSDataInstance *)v2, v3);
    *(_QWORD *)&v2->i_uid = &SSActor::`vftable;
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
// attributes: thunk
void __fastcall SSActorClass::recurse_class_ctor(SSActorClass *this, SSInvokedMethod *imethod_p)
{
  SSClass::recurse_class_ctor(this, imethod_p);
}

