// File Line: 97
// RVA: 0x998F70
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::BinNodeMH::MakeNode(char *start, unsigned __int64 bytes, Scaleform::HeapMH::PageMH *page)
{
  unsigned __int64 v3; // r9
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // rax
  Scaleform::HeapMH::BinNodeMH *result; // rax

  v3 = bytes >> 4;
  v4 = bytes >> 3;
  *(_QWORD *)start ^= ((unsigned __int8)v3 ^ (unsigned __int8)*(_QWORD *)start) & 0xF;
  *(_QWORD *)&start[8 * v4 - 16] = *(_QWORD *)start;
  v5 = (v3 >> 4) | *((_QWORD *)start + 1) & 0xFFFFFFFFFFFFFFF0ui64;
  *((_QWORD *)start + 1) = v5;
  *(_QWORD *)&start[8 * v4 - 8] = v5;
  result = (Scaleform::HeapMH::BinNodeMH *)start;
  if ( (*(_DWORD *)start & 0xF | 16 * (unsigned __int64)(*((_DWORD *)start + 2) & 0xF)) > 2 )
    *((_QWORD *)start + 2) = page;
  return result;
}

