// File Line: 53
// RVA: 0x12C66F8
__int64 _isa_available_init()
{
  int v5; // er8
  int v21; // eax
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx

  _isa_enabled = 2;
  _RAX = 1i64;
  _isa_available = 1;
  __asm { cpuid; Get CPU ID }
  if ( _bittest((const signed int *)&_RCX, 0x14u) )
  {
    _isa_available = 2;
    _isa_enabled = 6;
    if ( _bittest((const signed int *)&_RCX, 0x1Cu) )
    {
      _isa_available = 3;
      _isa_enabled = 14;
    }
  }
  v5 = _favor;
  _RAX = 7i64;
  __asm { cpuid; Get CPU ID }
  if ( _bittest((const signed int *)&_RBX, 9u) )
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
      || (v22 = (unsigned int)(v21 - 198224), (unsigned int)v22 <= 0x20) && (v23 = 4295032833i64, _bittest64(&v23, v22)) )
    {
      _favor = v5 | 1;
    }
  }
  return 0i64;
}

