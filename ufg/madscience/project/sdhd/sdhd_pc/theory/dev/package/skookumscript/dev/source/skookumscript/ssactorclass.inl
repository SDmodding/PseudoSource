// File Line: 139
// RVA: 0x10DF60
void __fastcall SSActorClass::append_instance(SSActorClass *this, SSActor *actor)
{
  for ( ; actor->i_name.i_uid != ASymbol::get_null()->i_uid; this = (SSActorClass *)this->i_superclass_p )
  {
    APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(&this->i_instances, actor, 0i64);
    if ( !this->i_superclass_p->SSClass::vfptr->is_actor_class(this->i_superclass_p) )
      break;
  }
}

// File Line: 165
// RVA: 0x13BDB0
void __fastcall SSActorClass::remove_instance(SSActorClass *this, SSActor *actor)
{
  APSortedLogical<SSActor,ASymbol> *p_i_instances; // rdi
  __int64 v5; // rdx
  SSActor **i_array_p; // rax
  unsigned int find_pos_p; // [rsp+48h] [rbp+10h] BYREF

  if ( actor->i_name.i_uid != ASymbol::get_null()->i_uid )
  {
    p_i_instances = &this->i_instances;
    if ( APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::find_elem(
           &this->i_instances,
           actor,
           &find_pos_p,
           0,
           0xFFFFFFFF) )
    {
      v5 = find_pos_p;
      i_array_p = this->i_instances.i_array_p;
      memmove(&i_array_p[v5], &i_array_p[v5 + 1], 8i64 * (unsigned int)(--p_i_instances->i_count - v5));
    }
    if ( this->i_superclass_p->SSClass::vfptr->is_actor_class(this->i_superclass_p) )
      SSActorClass::remove_instance((SSActorClass *)this->i_superclass_p, actor);
    if ( !p_i_instances->i_count )
    {
      APSizedArrayBase<SSActor>::compact(&this->i_instances);
      if ( (this->i_flags & 8) != 0 )
        ((void (__fastcall *)(SSActorClass *))this->vfptr[1].find_common_type)(this);
    }
  }
}

