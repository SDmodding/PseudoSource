// File Line: 175
// RVA: 0x117A70
SSMethod *__fastcall SSClosureInfoMethod::get_invokable(SSClosureInfoMethod *this)
{
  SSMethod *result; // rax

  if ( this )
    result = (SSMethod *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 243
// RVA: 0x11A030
__int64 __fastcall SSLiteralClosure::get_type(SSLiteralClosure *this)
{
  return 8 - (unsigned int)(((unsigned __int8 (*)(void))this->i_info_p.i_obj_p->vfptr->is_method)() != 0);
}

