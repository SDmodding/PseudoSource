// File Line: 222
// RVA: 0x11F220
bool __fastcall SSExpressionBase::is_nil(SSExpressionBase *this)
{
  return this == 0i64;
}

// File Line: 515
// RVA: 0x11F030
bool __fastcall SSLoop::is_loop(SSLoop *this, ASymbol *loop_name)
{
  return loop_name->i_uid == -1 || loop_name->i_uid == this->i_name.i_uid;
}

