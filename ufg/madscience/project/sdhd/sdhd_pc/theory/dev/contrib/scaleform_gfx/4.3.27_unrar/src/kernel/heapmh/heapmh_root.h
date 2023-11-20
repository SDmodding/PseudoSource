// File Line: 214
// RVA: 0x954BE0
Scaleform::HeapMH::NodeMH *__fastcall Scaleform::HeapMH::RootMH::AddToGlobalTree(Scaleform::HeapMH::RootMH *this, char *ptr, unsigned __int64 size, unsigned __int64 align, Scaleform::MemoryHeapMH *heap)
{
  Scaleform::HeapMH::RootMH *v5; // r10
  Scaleform::HeapMH::NodeMH *result; // rax
  unsigned __int64 v7; // rcx
  Scaleform::HeapMH::NodeMH *v8; // rdx
  Scaleform::HeapMH::NodeMH *v9; // rdx
  signed __int64 v10; // r8
  unsigned __int64 v11; // rcx
  signed __int64 v12; // r9
  Scaleform::HeapMH::NodeMH *v13; // rcx

  v5 = this;
  result = (Scaleform::HeapMH::NodeMH *)&ptr[size];
  if ( align )
  {
    if ( align <= 2 || align == 4 )
    {
      v7 = (unsigned __int64)heap;
      goto LABEL_10;
    }
    if ( align == 8 )
    {
      v7 = (unsigned __int64)heap | 1;
      goto LABEL_10;
    }
    if ( align == 16 )
    {
      v7 = (unsigned __int64)heap | 2;
      goto LABEL_10;
    }
  }
  result->Align = align;
  v7 = (unsigned __int64)heap | 3;
LABEL_10:
  result->pHeap = v7;
  v8 = (Scaleform::HeapMH::NodeMH *)&v5->HeapTree;
  result->Child[1] = 0i64;
  result->Child[0] = 0i64;
  result->Parent = 0i64;
  if ( v5->HeapTree.Root )
  {
    v9 = v8->Parent;
    v10 = (signed __int64)result;
    if ( v9 != result )
    {
      while ( 1 )
      {
        v11 = v10;
        v10 *= 2i64;
        v11 >>= 63;
        v12 = (signed __int64)v9 + 8 * v11;
        v13 = v9->Child[v11];
        if ( !v13 )
          break;
        v9 = v13;
        if ( v13 == result )
          return result;
      }
      *(_QWORD *)(v12 + 8) = result;
      result->Parent = v9;
    }
  }
  else
  {
    v8->Parent = result;
    result->Parent = v8;
  }
  return result;
}

