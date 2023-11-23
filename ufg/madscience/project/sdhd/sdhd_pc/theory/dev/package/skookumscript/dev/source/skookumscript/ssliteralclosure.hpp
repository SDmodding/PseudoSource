// File Line: 175
// RVA: 0x117A70
SSMethod *__fastcall SSClosureInfoMethod::get_invokable(SSClosureInfoMethod *this)
{
  if ( this )
    return &this->SSMethod;
  else
    return 0i64;
}

// File Line: 243
// RVA: 0x11A030
__int64 __fastcall SSLiteralClosure::get_type(SSLiteralClosure *this)
{
  return 8 - (unsigned int)this->i_info_p.i_obj_p->vfptr->is_method(this->i_info_p.i_obj_p);
}

