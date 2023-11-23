// File Line: 17
// RVA: 0xC56C80
hkResult *__fastcall hkArrayUtil::_reserve(
        hkResult *result,
        hkMemoryAllocator *mem,
        const void **array,
        int numElem,
        int sizeElem)
{
  int v5; // esi
  hkMemoryAllocatorVtbl *vfptr; // rax
  int v8; // r8d
  __int64 v10; // rdi
  void *v11; // rax
  int v12; // eax

  v5 = sizeElem;
  vfptr = mem->vfptr;
  v8 = *((_DWORD *)array + 3);
  sizeElem *= numElem;
  if ( v8 < 0 )
  {
    v11 = vfptr->bufAlloc(mem, &sizeElem);
    v10 = (__int64)v11;
    if ( v11 )
      memmove(v11, *array, v5 * *((_DWORD *)array + 2));
  }
  else
  {
    v10 = (__int64)vfptr->bufRealloc(mem, (void *)*array, v5 * (v8 & 0x3FFFFFFFu), &sizeElem);
  }
  v12 = sizeElem;
  *array = (const void *)v10;
  *((_DWORD *)array + 3) = v12 / v5;
  result->m_enum = v10 == 0;
  return result;
}

// File Line: 55
// RVA: 0xC56D30
void __fastcall hkArrayUtil::_reserveMore(hkMemoryAllocator *mem, const void **array, int sizeElem)
{
  int v3; // eax
  int v6; // eax
  int v7; // r8d
  hkMemoryAllocatorVtbl *vfptr; // rax
  void *v9; // rbx
  int v10; // [rsp+40h] [rbp+18h] BYREF

  v3 = *((_DWORD *)array + 2);
  if ( v3 )
    v6 = 2 * v3;
  else
    v6 = 1;
  v7 = *((_DWORD *)array + 3);
  v10 = sizeElem * v6;
  vfptr = mem->vfptr;
  if ( v7 < 0 )
  {
    v9 = vfptr->bufAlloc(mem, &v10);
    memmove(v9, *array, sizeElem * *((_DWORD *)array + 2));
    *array = v9;
  }
  else
  {
    *array = vfptr->bufRealloc(mem, (void *)*array, sizeElem * (v7 & 0x3FFFFFFFu), &v10);
  }
  *((_DWORD *)array + 3) = v10 / sizeElem;
}

// File Line: 84
// RVA: 0xC56DD0
void __fastcall hkArrayUtil::_reduce(
        hkMemoryAllocator *mem,
        const void **array,
        int sizeElem,
        char *inplaceMem,
        int requestedCapacity)
{
  int v5; // edi
  int v10; // eax
  int v12; // r8d
  void *v13; // rdx
  int v14; // [rsp+48h] [rbp+10h] BYREF

  v5 = requestedCapacity;
  if ( inplaceMem && (v10 = *((_DWORD *)array + 2), v10 < requestedCapacity) )
  {
    memmove(inplaceMem, *array, sizeElem * v10);
    mem->vfptr->bufFree(mem, (void *)*array, sizeElem * (*((_DWORD *)array + 3) & 0x3FFFFFFF));
    *((_DWORD *)array + 3) = v5 | 0x80000000;
    *array = inplaceMem;
  }
  else
  {
    v12 = *((_DWORD *)array + 3);
    v13 = (void *)*array;
    v14 = requestedCapacity * sizeElem;
    *array = mem->vfptr->bufRealloc(mem, v13, (unsigned int)(sizeElem * v12), &v14);
    *((_DWORD *)array + 3) = v14 / sizeElem;
  }
}

