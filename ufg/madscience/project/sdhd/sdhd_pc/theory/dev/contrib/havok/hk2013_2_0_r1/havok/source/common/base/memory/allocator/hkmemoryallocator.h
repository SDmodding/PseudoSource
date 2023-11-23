// File Line: 187
// RVA: 0x1B94C0
unsigned int *__fastcall hkMemoryAllocator::_bufAlloc<unsigned int>(hkMemoryAllocator *this, int *reqNumInOut)
{
  unsigned int *result; // rax
  int v4; // [rsp+30h] [rbp+8h] BYREF

  v4 = 4 * *reqNumInOut;
  result = (unsigned int *)this->vfptr->bufAlloc(this, &v4);
  *reqNumInOut = v4 / 4;
  return result;
}

