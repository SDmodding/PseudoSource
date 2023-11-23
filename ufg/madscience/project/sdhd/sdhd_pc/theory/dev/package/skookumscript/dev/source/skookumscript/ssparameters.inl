// File Line: 96
// RVA: 0x118500
SSParameters *__fastcall SSParameters::get_or_create(const void **binary_pp)
{
  SSParameters *v1; // rbx
  SSParameters params_p; // [rsp+28h] [rbp-40h] BYREF

  SSParameters::SSParameters(&params_p, binary_pp);
  v1 = SSParameters::get_or_create(&params_p);
  APCompactArrayBase<SSParameterBase>::free_all(&params_p.i_params);
  APCompactArrayBase<SSTypedName>::free_all(&params_p.i_return_params);
  if ( params_p.i_result_type_p.i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])(params_p.i_result_type_p.i_obj_p);
  AMemory::c_free_func(params_p.i_return_params.i_array_p);
  AMemory::c_free_func(params_p.i_params.i_array_p);
  return v1;
}

