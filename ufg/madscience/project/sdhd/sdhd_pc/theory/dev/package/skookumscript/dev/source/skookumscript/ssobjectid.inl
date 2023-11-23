// File Line: 61
// RVA: 0x106050
void __fastcall SSObjectId::SSObjectId(SSObjectId *this, const void **binary_pp)
{
  ASymbol *v4; // rax
  ASymbol result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSObjectId::`vftable;
  ASymbol::create_from_binary(&this->i_name, binary_pp);
  this->i_obj_p.i_obj_p = 0i64;
  this->i_obj_p.i_ptr_id = 0;
  v4 = ASymbol::create_from_binary(&result, binary_pp);
  this->i_class_p = SSBrain::get_class(v4);
  this->i_flags = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
}

