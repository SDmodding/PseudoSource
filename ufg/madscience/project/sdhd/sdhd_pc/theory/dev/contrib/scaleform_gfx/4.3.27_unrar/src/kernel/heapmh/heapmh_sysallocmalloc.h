// File Line: 69
// RVA: 0x49C60
void *__fastcall Scaleform::SysAllocMalloc::Alloc(
        Scaleform::SysAllocMalloc *this,
        unsigned __int64 size,
        unsigned __int64 align)
{
  return aligned_malloc(size, align);
}

// File Line: 74
// RVA: 0x4E1A0
void __fastcall Scaleform::SysAllocMalloc::Free(
        Scaleform::SysAllocMalloc *this,
        void *ptr,
        unsigned __int64 size,
        unsigned __int64 align)
{
  aligned_free(ptr);
}

// File Line: 80
// RVA: 0x531B0
void *__fastcall Scaleform::SysAllocMalloc::Realloc(
        Scaleform::SysAllocMalloc *this,
        void *oldPtr,
        size_t oldSize,
        size_t newSize,
        unsigned __int64 align)
{
  size_t v5; // rbx
  void *v9; // rax
  void *v10; // rdi

  v5 = newSize;
  if ( newSize == oldSize )
    return oldPtr;
  v9 = aligned_malloc(newSize, align);
  v10 = v9;
  if ( v9 )
  {
    if ( oldSize < v5 )
      v5 = oldSize;
    memmove(v9, oldPtr, v5);
    aligned_free(oldPtr);
  }
  return v10;
}

