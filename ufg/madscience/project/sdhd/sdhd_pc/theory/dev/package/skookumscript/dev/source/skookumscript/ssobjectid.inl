// File Line: 61
// RVA: 0x106050
void __fastcall SSObjectId::SSObjectId(SSObjectId *this, const void **binary_pp)
{
  const void **v2; // rbx
  SSObjectId *v3; // rdi
  ASymbol *v4; // rax
  ASymbol result; // [rsp+48h] [rbp+10h]

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSObjectId::`vftable;
  ASymbol::create_from_binary(&this->i_name, binary_pp);
  v3->i_obj_p.i_obj_p = 0i64;
  v3->i_obj_p.i_ptr_id = 0;
  v4 = ASymbol::create_from_binary(&result, v2);
  v3->i_class_p = SSBrain::get_class(v4);
  v3->i_flags = *(unsigned __int8 *)*v2;
  *v2 = (char *)*v2 + 1;
}

