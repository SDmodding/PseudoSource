// File Line: 163
// RVA: 0x11DF80
SSInvokedBase *__fastcall SSObjectId::invoke(SSObjectId *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // rdi
  SSObjectId *v5; // rbx
  unsigned int v6; // eax
  SSInstance *v7; // rax
  SSInstance *v8; // rcx
  SSClass *v9; // rcx

  v4 = result_pp;
  v5 = this;
  if ( !result_pp )
    return 0i64;
  v6 = this->i_flags;
  if ( !(v6 & 2) )
  {
    if ( v6 & 4 )
    {
      v8 = this->i_obj_p.i_obj_p;
      if ( v8 && v5->i_obj_p.i_ptr_id == v8->i_ptr_id )
      {
LABEL_13:
        ++v8->i_ref_count;
        *v4 = v8;
        return 0i64;
      }
      v9 = v5->i_class_p;
    }
    else
    {
      v9 = this->i_class_p;
    }
    v8 = (SSInstance *)((__int64 (__fastcall *)(SSClass *, SSObjectId *, SSInvokedBase *))v9->vfptr[1].is_actor_class)(
                         v9,
                         v5,
                         caller_p);
    if ( !v8 )
      v8 = SSBrain::c_nil_p;
    goto LABEL_13;
  }
  v7 = SSInstance::pool_new(SSBrain::c_symbol_class_p);
  if ( v7 != (SSInstance *)-32i64 )
    LODWORD(v7->i_user_data) = v5->i_name.i_uid;
  *v4 = v7;
  return 0i64;
}

// File Line: 229
// RVA: 0x13E760
void __fastcall SSObjectId::track_memory(SSObjectId *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSObjectId", 0x30u, 8u, 0, 0, 1u);
}

