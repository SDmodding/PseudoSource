// File Line: 163
// RVA: 0x11DF80
SSInvokedBase *__fastcall SSObjectId::invoke(
        SSObjectId *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  unsigned int i_flags; // eax
  SSInstance *v7; // rax
  SSInstance *i_obj_p; // rcx
  SSClass *i_class_p; // rcx

  if ( !result_pp )
    return 0i64;
  i_flags = this->i_flags;
  if ( (i_flags & 2) == 0 )
  {
    if ( (i_flags & 4) != 0 )
    {
      i_obj_p = this->i_obj_p.i_obj_p;
      if ( i_obj_p && this->i_obj_p.i_ptr_id == i_obj_p->i_ptr_id )
      {
LABEL_13:
        ++i_obj_p->i_ref_count;
        *result_pp = i_obj_p;
        return 0i64;
      }
      i_class_p = this->i_class_p;
    }
    else
    {
      i_class_p = this->i_class_p;
    }
    i_obj_p = (SSInstance *)((__int64 (__fastcall *)(SSClass *, SSObjectId *, SSInvokedBase *))i_class_p->vfptr[1].is_actor_class)(
                              i_class_p,
                              this,
                              caller_p);
    if ( !i_obj_p )
      i_obj_p = SSBrain::c_nil_p;
    goto LABEL_13;
  }
  v7 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
  if ( v7 != (SSInstance *)-32i64 )
    LODWORD(v7->i_user_data) = this->i_name.i_uid;
  *result_pp = v7;
  return 0i64;
}

// File Line: 229
// RVA: 0x13E760
void __fastcall SSObjectId::track_memory(SSObjectId *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSObjectId", 0x30u, 8u, 0, 0, 1u);
}

