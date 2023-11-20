// File Line: 69
// RVA: 0x49C60
void *__fastcall Scaleform::SysAllocMalloc::Alloc(Scaleform::SysAllocMalloc *this, unsigned __int64 size, unsigned __int64 align)
{
  return aligned_malloc(size, align);
}

// File Line: 74
// RVA: 0x4E1A0
void __fastcall Scaleform::SysAllocMalloc::Free(Scaleform::SysAllocMalloc *this, void *ptr, unsigned __int64 size, unsigned __int64 align)
{
  aligned_free(ptr);
}

// File Line: 80
// RVA: 0x531B0
void *__fastcall Scaleform::SysAllocMalloc::Realloc(Scaleform::SysAllocMalloc *this, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 align)
{
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rbp
  void *v7; // rsi
  void *v9; // rax
  void *v10; // rdi

  v5 = newSize;
  v6 = oldSize;
  v7 = oldPtr;
  if ( newSize == oldSize )
    return oldPtr;
  v9 = aligned_malloc(newSize, align);
  v10 = v9;
  if ( v9 )
  {
    if ( v6 < v5 )
      v5 = v6;
    memmove(v9, v7, v5);
    aligned_free(v7);
  }
  return v10;
}

