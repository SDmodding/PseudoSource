// File Line: 21
// RVA: 0x12DD750
void __fastcall std::_Init_locks::_Init_locks(std::_Init_locks *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  __int64 v2; // rdi

  if ( !_InterlockedIncrement(&init) )
  {
    v1 = mtx;
    v2 = 4i64;
    do
    {
      Mtxinit(v1++);
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 28
// RVA: 0x12DD7DC
void __fastcall std::_Init_locks::~_Init_locks(std::_Init_locks *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  __int64 v2; // rdi

  if ( _InterlockedAdd(&init, 0xFFFFFFFF) < 0 )
  {
    v1 = mtx;
    v2 = 4i64;
    do
    {
      Mtxdst(v1++);
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 49
// RVA: 0x15DEEAC
__int64 std::_dynamic_initializer_for__initlocks__()
{
  std::_Init_locks::_Init_locks(&initlocks);
  return atexit((int (__fastcall *)())std::_dynamic_atexit_destructor_for__initlocks__);
}

// File Line: 64
// RVA: 0x12DD79C
void __fastcall std::_Lockit::_Lockit(std::_Lockit *this, int kind)
{
  this->_Locktype = kind;
  if ( kind )
  {
    if ( kind < 4 )
      Mtxlock(&mtx[kind]);
  }
  else
  {
    lock(12);
  }
}

// File Line: 72
// RVA: 0x12DD818
void __fastcall std::_Lockit::~_Lockit(std::_Lockit *this)
{
  __int64 Locktype; // rax

  Locktype = this->_Locktype;
  if ( (_DWORD)Locktype )
  {
    if ( (int)Locktype < 4 )
      Mtxunlock(&mtx[Locktype]);
  }
  else
  {
    unlock(12);
  }
}

