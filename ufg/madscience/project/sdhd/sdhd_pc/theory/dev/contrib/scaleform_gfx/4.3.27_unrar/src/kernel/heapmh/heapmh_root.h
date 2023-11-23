// File Line: 214
// RVA: 0x954BE0
Scaleform::HeapMH::NodeMH *__fastcall Scaleform::HeapMH::RootMH::AddToGlobalTree(
        Scaleform::HeapMH::RootMH *this,
        char *ptr,
        unsigned __int64 size,
        unsigned __int64 align,
        Scaleform::MemoryHeapMH *heap)
{
  Scaleform::HeapMH::NodeMH *result; // rax
  Scaleform::MemoryHeapMH *v7; // rcx
  Scaleform::HeapMH::NodeMH *p_HeapTree; // rdx
  Scaleform::HeapMH::NodeMH *Parent; // rdx
  __int64 v10; // r8
  unsigned __int64 v11; // rcx
  char *v12; // r9
  Scaleform::HeapMH::NodeMH *v13; // rcx

  result = (Scaleform::HeapMH::NodeMH *)&ptr[size];
  if ( align )
  {
    if ( align <= 2 || align == 4 )
    {
      v7 = heap;
      goto LABEL_10;
    }
    if ( align == 8 )
    {
      v7 = (Scaleform::MemoryHeapMH *)((unsigned __int64)heap | 1);
      goto LABEL_10;
    }
    if ( align == 16 )
    {
      v7 = (Scaleform::MemoryHeapMH *)((unsigned __int64)heap | 2);
      goto LABEL_10;
    }
  }
  result->Align = align;
  v7 = (Scaleform::MemoryHeapMH *)((unsigned __int64)heap | 3);
LABEL_10:
  result->pHeap = (unsigned __int64)v7;
  p_HeapTree = (Scaleform::HeapMH::NodeMH *)&this->HeapTree;
  result->Child[1] = 0i64;
  result->Child[0] = 0i64;
  result->Parent = 0i64;
  if ( this->HeapTree.Root )
  {
    Parent = p_HeapTree->Parent;
    v10 = (__int64)result;
    if ( Parent != result )
    {
      while ( 1 )
      {
        v11 = v10;
        v10 *= 2i64;
        v12 = (char *)Parent + 8 * (v11 >> 63);
        v13 = (Scaleform::HeapMH::NodeMH *)*((_QWORD *)v12 + 1);
        if ( !v13 )
          break;
        Parent = (Scaleform::HeapMH::NodeMH *)*((_QWORD *)v12 + 1);
        if ( v13 == result )
          return result;
      }
      *((_QWORD *)v12 + 1) = result;
      result->Parent = Parent;
    }
  }
  else
  {
    p_HeapTree->Parent = result;
    result->Parent = p_HeapTree;
  }
  return result;
}

