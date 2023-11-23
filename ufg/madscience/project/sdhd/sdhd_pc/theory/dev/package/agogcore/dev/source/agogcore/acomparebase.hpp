// File Line: 124
// RVA: 0x112800
__int64 __fastcall ACompareLogical<SSInvokableClass>::comparison(SSInvokableClass *lhs, SSInvokableClass *rhs)
{
  SSClass *i_class_p; // rax
  SSClass *v4; // rcx
  unsigned int i_uid; // edx
  unsigned int v7; // r8d
  int v8; // eax
  eSSInvokeTime i_invoke_type; // eax
  eSSInvokeTime v10; // ecx
  SSParameters *i_obj_p; // rcx
  SSParameters *v12; // rdx
  bool v14; // al

  i_class_p = lhs->i_class_p;
  v4 = rhs->i_class_p;
  if ( i_class_p != v4 )
  {
    i_uid = i_class_p->i_name.i_uid;
    v7 = v4->i_name.i_uid;
    if ( i_uid != v7 )
    {
      v8 = 1;
      if ( i_uid < v7 )
        v8 = -1;
      if ( v8 == -1 )
        return -1i64;
    }
  }
  i_invoke_type = lhs->i_invoke_type;
  v10 = rhs->i_invoke_type;
  if ( i_invoke_type != v10 && i_invoke_type < v10 )
    return -1i64;
  i_obj_p = lhs->i_params_p.i_obj_p;
  v12 = rhs->i_params_p.i_obj_p;
  if ( i_obj_p != v12 && SSParameters::operator<(i_obj_p, v12) )
    return -1i64;
  v14 = lhs->i_class_p == rhs->i_class_p
     && lhs->i_invoke_type == rhs->i_invoke_type
     && lhs->i_params_p.i_obj_p == rhs->i_params_p.i_obj_p;
  return 1i64 - v14;
}

