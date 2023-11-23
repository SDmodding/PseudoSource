// File Line: 53
// RVA: 0x12C66F8
__int64 _isa_available_init()
{
  int v5; // r8d
  int v21; // eax
  unsigned __int64 v22; // rax
  __int64 v23; // rcx

  _isa_enabled = 2;
  _RAX = 1i64;
  _isa_available = 1;
  __asm { cpuid; Get CPU ID }
  if ( (_RCX & 0x100000) != 0 )
  {
    _isa_available = 2;
    _isa_enabled = 6;
    if ( (_RCX & 0x10000000) != 0 )
    {
      _isa_available = 3;
      _isa_enabled = 14;
    }
  }
  v5 = _favor;
  _RAX = 7i64;
  __asm { cpuid; Get CPU ID }
  if ( (_RBX & 0x200) != 0 )
  {
    v5 = _favor | 2;
    _favor |= 2u;
  }
  _RAX = 0i64;
  __asm { cpuid; Get CPU ID }
  if ( (_DWORD)_RBX == 1970169159 && (_DWORD)_RDX == 1231384169 && (_DWORD)_RCX == 1818588270 )
  {
    _RAX = 1i64;
    __asm { cpuid; Get CPU ID }
    v21 = _RAX & 0xFFF3FF0;
    if ( v21 == 67264
      || v21 == 132704
      || v21 == 132720
      || (v22 = (unsigned int)(v21 - 198224), (unsigned int)v22 <= 0x20)
      && (v23 = 0x100010001i64, _bittest64(&v23, v22)) )
    {
      _favor = v5 | 1;
    }
  }
  return 0i64;
}

