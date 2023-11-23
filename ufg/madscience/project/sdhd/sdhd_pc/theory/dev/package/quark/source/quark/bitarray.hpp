// File Line: 23
// RVA: 0x2DE1B0
void __fastcall UFG::BitArray::BitArray(UFG::BitArray *this, unsigned int numBits)
{
  unsigned __int64 v3; // rax
  unsigned int *v4; // rax
  unsigned int v5; // r8d

  this->mNumBits = numBits;
  this->vfptr = (UFG::BitArrayVtbl *)&UFG::BitArray::`vftable;
  this->mNumWords = (numBits >> 5) + 1;
  v3 = 4i64 * ((numBits >> 5) + 1);
  if ( !is_mul_ok((numBits >> 5) + 1, 4ui64) )
    v3 = -1i64;
  v4 = (unsigned int *)UFG::qMalloc(v3, UFG::gGlobalNewName, 0i64);
  v5 = 4 * this->mNumWords;
  this->mData = v4;
  UFG::qMemSet(v4, 0, v5);
}

