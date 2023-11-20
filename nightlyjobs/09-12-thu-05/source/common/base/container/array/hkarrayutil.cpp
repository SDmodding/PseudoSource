// File Line: 17
// RVA: 0xC56C80
hkResult *__fastcall hkArrayUtil::_reserve(hkResult *result, hkMemoryAllocator *mem, void *array, int numElem, int sizeElem)
{
  int v5; // esi
  hkMemoryAllocatorVtbl *v6; // rax
  _QWORD *v7; // rbx
  int v8; // er8
  hkResult *v9; // r14
  __int64 v10; // rdi
  void *v11; // rax
  int v12; // eax

  v5 = sizeElem;
  v6 = mem->vfptr;
  v7 = array;
  v8 = *((_DWORD *)array + 3);
  v9 = result;
  sizeElem *= numElem;
  if ( v8 < 0 )
  {
    v11 = v6->bufAlloc(mem, &sizeElem);
    v10 = (__int64)v11;
    if ( v11 )
      memmove(v11, (const void *)*v7, v5 * *((_DWORD *)v7 + 2));
  }
  else
  {
    v10 = (__int64)v6->bufRealloc(mem, (void *)*v7, v5 * (v8 & 0x3FFFFFFFu), &sizeElem);
  }
  v12 = sizeElem;
  *v7 = v10;
  *((_DWORD *)v7 + 3) = v12 / v5;
  v9->m_enum = v10 == 0;
  return v9;
}

// File Line: 55
// RVA: 0xC56D30
void __fastcall hkArrayUtil::_reserveMore(hkMemoryAllocator *mem, void *array, int sizeElem)
{
  int v3; // eax
  int v4; // esi
  const void **v5; // rdi
  int v6; // eax
  int v7; // er8
  hkMemoryAllocatorVtbl *v8; // rax
  void *v9; // rbx
  int v10; // [rsp+40h] [rbp+18h]

  v3 = *((_DWORD *)array + 2);
  v4 = sizeElem;
  v5 = (const void **)array;
  if ( v3 )
    v6 = 2 * v3;
  else
    v6 = 1;
  v7 = *((_DWORD *)array + 3);
  v10 = v4 * v6;
  v8 = mem->vfptr;
  if ( v7 < 0 )
  {
    v9 = v8->bufAlloc(mem, &v10);
    memmove(v9, *v5, v4 * *((_DWORD *)v5 + 2));
    *v5 = v9;
  }
  else
  {
    *(_QWORD *)array = v8->bufRealloc(mem, *(void **)array, v4 * (v7 & 0x3FFFFFFFu), &v10);
  }
  *((_DWORD *)v5 + 3) = v10 / v4;
}

// File Line: 84
// RVA: 0xC56DD0
void __fastcall hkArrayUtil::_reduce(hkMemoryAllocator *mem, void *array, int sizeElem, char *inplaceMem, int requestedCapacity)
{
  int v5; // edi
  char *v6; // rsi
  int v7; // ebp
  void **v8; // rbx
  hkMemoryAllocator *v9; // r14
  int v10; // eax
  int v11; // eax
  int v12; // er8
  void *v13; // rdx
  int v14; // [rsp+48h] [rbp+10h]

  v5 = requestedCapacity;
  v6 = inplaceMem;
  v7 = sizeElem;
  v8 = (void **)array;
  v9 = mem;
  if ( inplaceMem && (v10 = *((_DWORD *)array + 2), v10 < requestedCapacity) )
  {
    memmove(inplaceMem, *(const void **)array, sizeElem * v10);
    v9->vfptr->bufFree(v9, *v8, v7 * (*((_DWORD *)v8 + 3) & 0x3FFFFFFF));
    *((_DWORD *)v8 + 3) = v5 | 0x80000000;
    *v8 = v6;
  }
  else
  {
    v11 = sizeElem;
    v12 = *((_DWORD *)array + 3);
    v13 = *(void **)array;
    v14 = requestedCapacity * v11;
    *v8 = mem->vfptr->bufRealloc(mem, v13, v7 * v12, &v14);
    *((_DWORD *)v8 + 3) = v14 / v7;
  }
}

