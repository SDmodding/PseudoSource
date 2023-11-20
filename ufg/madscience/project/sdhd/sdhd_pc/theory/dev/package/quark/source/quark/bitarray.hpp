// File Line: 23
// RVA: 0x2DE1B0
void __fastcall UFG::BitArray::BitArray(UFG::BitArray *this, int numBits)
{
  UFG::BitArray *v2; // rbx
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // rax
  unsigned int v5; // er8

  this->mNumBits = numBits;
  this->vfptr = (UFG::BitArrayVtbl *)&UFG::BitArray::`vftable;
  v2 = this;
  this->mNumWords = ((unsigned int)numBits >> 5) + 1;
  v3 = 4i64 * (((unsigned int)numBits >> 5) + 1);
  if ( !is_mul_ok(((unsigned int)numBits >> 5) + 1, 4ui64) )
    v3 = -1i64;
  v4 = UFG::qMalloc(v3, UFG::gGlobalNewName, 0i64);
  v5 = 4 * v2->mNumWords;
  v2->mData = (unsigned int *)v4;
  UFG::qMemSet(v4, 0, v5);
}

