// File Line: 139
// RVA: 0x10DF60
void __fastcall SSActorClass::append_instance(SSActorClass *this, SSActor *actor)
{
  SSActor *v2; // rdi
  SSActorClass *i; // rbx

  v2 = actor;
  for ( i = this; v2->i_name.i_uid != ASymbol::get_null()->i_uid; i = (SSActorClass *)i->i_superclass_p )
  {
    APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&i->i_instances.i_count,
      v2,
      0i64);
    if ( !((unsigned __int8 (*)(void))i->i_superclass_p->vfptr->is_actor_class)() )
      break;
  }
}

// File Line: 165
// RVA: 0x13BDB0
void __fastcall SSActorClass::remove_instance(SSActorClass *this, SSActor *actor)
{
  SSActor *v2; // rsi
  SSActorClass *v3; // rbx
  APSortedLogical<SSActor,ASymbol> *v4; // rdi
  __int64 v5; // rdx
  SSActor **v6; // rax
  unsigned int find_pos_p; // [rsp+48h] [rbp+10h]

  v2 = actor;
  v3 = this;
  if ( actor->i_name.i_uid != ASymbol::get_null()->i_uid )
  {
    v4 = &v3->i_instances;
    if ( APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::find_elem(
           (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&v3->i_instances.i_count,
           v2,
           &find_pos_p,
           0,
           0xFFFFFFFF) )
    {
      v5 = find_pos_p;
      v6 = v3->i_instances.i_array_p;
      memmove(&v6[v5], &v6[v5 + 1], 8i64 * (unsigned int)(--v4->i_count - v5));
    }
    if ( ((unsigned __int8 (*)(void))v3->i_superclass_p->vfptr->is_actor_class)() )
      SSActorClass::remove_instance((SSActorClass *)v3->i_superclass_p, v2);
    if ( !v4->i_count )
    {
      APSizedArrayBase<SSActor>::compact((APSizedArrayBase<SSActor> *)&v3->i_instances.i_count);
      if ( v3->i_flags & 8 )
        ((void (__fastcall *)(SSActorClass *))v3->vfptr[1].find_common_type)(v3);
    }
  }
}

