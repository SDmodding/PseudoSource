// File Line: 11
// RVA: 0x12BAAD0
__int64 _vdecl_sin2()
{
  JUMPOUT(_isa_available, 2, _sse4_sin2);
  return _sse2_sin2();
}

