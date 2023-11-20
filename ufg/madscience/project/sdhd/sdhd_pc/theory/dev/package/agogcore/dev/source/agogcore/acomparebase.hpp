// File Line: 124
// RVA: 0x112800
__int64 __fastcall ACompareLogical<SSInvokableClass>::comparison(SSInvokableClass *lhs, SSInvokableClass *rhs)
{
  SSClass *v2; // rax
  SSInvokableClass *v3; // rdi
  SSClass *v4; // rcx
  SSInvokableClass *v5; // rbx
  unsigned int v6; // edx
  unsigned int v7; // er8
  signed int v8; // eax
  eSSInvokeTime v9; // eax
  eSSInvokeTime v10; // ecx
  SSParameters *v11; // rcx
  SSParameters *v12; // rdx
  bool v14; // al

  v2 = lhs->i_class_p;
  v3 = lhs;
  v4 = rhs->i_class_p;
  v5 = rhs;
  if ( v2 != v4 )
  {
    v6 = v2->i_name.i_uid;
    v7 = v4->i_name.i_uid;
    if ( v6 != v7 )
    {
      v8 = 1;
      if ( v6 < v7 )
        v8 = -1;
      if ( v8 == -1 )
        return -1i64;
    }
  }
  v9 = v3->i_invoke_type;
  v10 = v5->i_invoke_type;
  if ( v9 != v10 && v9 < v10 )
    return -1i64;
  v11 = v3->i_params_p.i_obj_p;
  v12 = v5->i_params_p.i_obj_p;
  if ( v11 != v12 && SSParameters::operator<(v11, v12) )
    return -1i64;
  v14 = v3->i_class_p == v5->i_class_p
     && v3->i_invoke_type == v5->i_invoke_type
     && v3->i_params_p.i_obj_p == v5->i_params_p.i_obj_p;
  return 1i64 - v14;
}

