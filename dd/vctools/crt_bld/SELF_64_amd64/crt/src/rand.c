// File Line: 36
// RVA: 0x12B2174
void __fastcall srand(unsigned int seed)
{
  getptd()->_holdrand = seed;
}

// File Line: 60
// RVA: 0x12B2148
__int64 __fastcall rand()
{
  _tiddata *v0; // rax
  unsigned int v1; // ecx

  v0 = getptd();
  v1 = 214013 * v0->_holdrand + 2531011;
  v0->_holdrand = v1;
  return HIWORD(v1) & 0x7FFF;
}

