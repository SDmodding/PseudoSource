// File Line: 14
// RVA: 0xA24790
UFG::allocator::free_link *__fastcall UIGfxAllocator::Alloc(UIGfxAllocator *this, unsigned __int64 size, unsigned __int64 align)
{
  return UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, size, "UIGfxAllocator::Alloc", (align & 0xFFFFFF) << 8, 1u);
}

// File Line: 22
// RVA: 0xA26230
void __fastcall UIGfxAllocator::Free(UIGfxAllocator *this, void *ptr, unsigned __int64 size, unsigned __int64 align)
{
  UFG::qMemoryPool::Free(&gScaleformMemoryPool, ptr);
}

// File Line: 29
// RVA: 0xA280E0
UFG::allocator::free_link *__fastcall UIGfxAllocator::Realloc(UIGfxAllocator *this, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 align)
{
  return UFG::qMemoryPool::Realloc(
           &gScaleformMemoryPool,
           oldPtr,
           newSize,
           "UIGfxAllocator::Realloc",
           (align & 0xFFFFFF) << 8);
}

