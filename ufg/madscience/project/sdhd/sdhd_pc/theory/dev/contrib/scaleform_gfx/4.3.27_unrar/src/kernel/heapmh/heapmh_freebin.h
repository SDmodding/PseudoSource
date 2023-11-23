// File Line: 97
// RVA: 0x998F70
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::BinNodeMH::MakeNode(
        Scaleform::HeapMH::BinNodeMH *start,
        unsigned __int64 bytes,
        Scaleform::HeapMH::PageMH *page)
{
  unsigned __int64 v3; // r9
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // rax
  Scaleform::HeapMH::BinNodeMH *result; // rax

  v3 = bytes >> 4;
  v4 = bytes >> 3;
  start->Prev ^= ((unsigned __int8)v3 ^ (unsigned __int8)start->Prev) & 0xF;
  *((_QWORD *)start + v4 - 2) = start->Prev;
  v5 = (v3 >> 4) | start->Next & 0xFFFFFFFFFFFFFFF0ui64;
  start->Next = v5;
  *((_QWORD *)start + v4 - 1) = v5;
  result = start;
  if ( (start->Prev & 0xF | (16 * (unsigned __int64)(start->Next & 0xF))) > 2 )
    start->Page = page;
  return result;
}

