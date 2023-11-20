// File Line: 25
// RVA: 0x9EFC20
void __fastcall Scaleform::Render::FontCacheHandleRef::releaseFont(Scaleform::Render::FontCacheHandleRef *this)
{
  _RBX = 0i64;
  __asm { xchg    rbx, [rcx]; Exchange Register/Memory with Register }
  if ( _RBX )
  {
    Scaleform::Render::FontCacheHandleManager::fontLost(_RBX, this);
    if ( !_InterlockedDecrement(&_RBX->RefCount) )
      _RBX->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&_RBX->vfptr, 1u);
  }
}

// File Line: 45
// RVA: 0x99FC10
void __fastcall Scaleform::Render::FontCacheHandleManager::ProcessKillList(Scaleform::Render::FontCacheHandleManager *this)
{
  Scaleform::Render::FontCacheHandleManager *v1; // r14
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *v3; // rsi
  Scaleform::Render::FontCacheHandle *v4; // rdi
  char v5; // r15
  Scaleform::Render::FontCacheHandle *v6; // rbp
  Scaleform::Render::GlyphCache *v7; // rcx

  v1 = this;
  v2 = &this->FontLock.cs;
  EnterCriticalSection(&this->FontLock.cs);
  v3 = &v1->Fonts[1];
  v4 = v1->Fonts[1].Root.pNext;
  if ( v4 != (Scaleform::Render::FontCacheHandle *)&v1->Fonts[1] )
  {
    v5 = 0;
    do
    {
      v6 = v4->pNext;
      v7 = v1->pCache;
      if ( v7 )
      {
        Scaleform::Render::GlyphCache::CleanUpFont(v7, v4);
        v5 = 1;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      v4 = v6;
    }
    while ( v6 != (Scaleform::Render::FontCacheHandle *)v3 );
    v3->Root.pPrev = (Scaleform::Render::FontCacheHandle *)v3;
    v1->Fonts[1].Root.pNext = (Scaleform::Render::FontCacheHandle *)&v1->Fonts[1];
    if ( v5 )
      Scaleform::Render::GlyphQueue::MergeEmptySlots(&v1->pCache->Queue);
  }
  LeaveCriticalSection(v2);
}

// File Line: 53
// RVA: 0x96D540
void __fastcall Scaleform::Render::FontCacheHandleManager::DestroyAllFonts(Scaleform::Render::FontCacheHandleManager *this)
{
  Scaleform::Render::FontCacheHandleManager *v1; // rbp
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *v3; // rsi
  Scaleform::Render::FontCacheHandle *v4; // rdi
  char v5; // r15
  Scaleform::Render::FontCacheHandle *v6; // r14
  Scaleform::Render::GlyphCache *v7; // rcx
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *v8; // rsi
  Scaleform::Render::FontCacheHandle *v9; // rdi
  Scaleform::Render::FontCacheHandle *v10; // rbx
  Scaleform::Lock *v14; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = &this->FontLock.cs;
  v14 = &this->FontLock;
  EnterCriticalSection(&this->FontLock.cs);
  v3 = &v1->Fonts[1];
  v4 = v1->Fonts[1].Root.pNext;
  if ( v4 != (Scaleform::Render::FontCacheHandle *)&v1->Fonts[1] )
  {
    v5 = 0;
    do
    {
      v6 = v4->pNext;
      v7 = v1->pCache;
      if ( v7 )
      {
        Scaleform::Render::GlyphCache::CleanUpFont(v7, v4);
        v5 = 1;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      v4 = v6;
    }
    while ( v6 != (Scaleform::Render::FontCacheHandle *)v3 );
    v3->Root.pPrev = (Scaleform::Render::FontCacheHandle *)v3;
    v1->Fonts[1].Root.pNext = (Scaleform::Render::FontCacheHandle *)&v1->Fonts[1];
    if ( v5 )
      Scaleform::Render::GlyphQueue::MergeEmptySlots(&v1->pCache->Queue);
  }
  v8 = v1->Fonts;
  v9 = v1->Fonts[0].Root.pNext;
  if ( v9 != (Scaleform::Render::FontCacheHandle *)v1->Fonts )
  {
    do
    {
      v10 = v9->pNext;
      v9->pFont->hRef.pFontHandle = 0i64;
      _RAX = v9->pFont;
      _RCX = 0i64;
      __asm { xchg    rcx, [rax+28h]; Exchange Register/Memory with Register }
      if ( _RCX && !_InterlockedDecrement((volatile signed __int32 *)(_RCX + 8)) )
        (**(void (__fastcall ***)(__int64, signed __int64))_RCX)(_RCX, 1i64);
      v9->pFont = 0i64;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
      v9 = v10;
    }
    while ( v10 != (Scaleform::Render::FontCacheHandle *)v8 );
    v8->Root.pPrev = (Scaleform::Render::FontCacheHandle *)v8;
    v1->Fonts[0].Root.pNext = (Scaleform::Render::FontCacheHandle *)v1->Fonts;
    v2 = &v14->cs;
  }
  LeaveCriticalSection(v2);
}

// File Line: 62
// RVA: 0x9E3270
void __fastcall Scaleform::Render::FontCacheHandleManager::fontLost(Scaleform::Render::FontCacheHandleManager *this, Scaleform::Render::FontCacheHandleRef *href)
{
  Scaleform::Render::FontCacheHandleRef *v2; // rbx
  Scaleform::Render::FontCacheHandleManager *v3; // rdi
  Scaleform::Render::FontCacheHandle *v4; // r8
  _RTL_CRITICAL_SECTION *v5; // [rsp+40h] [rbp+8h]

  v2 = href;
  v3 = this;
  v5 = &this->FontLock.cs;
  EnterCriticalSection(&this->FontLock.cs);
  v4 = v2->pFontHandle;
  if ( v4 )
  {
    v4->pPrev->pNext = v4->pNext;
    v4->pNext->pPrev = v4->pPrev;
    v4->pPrev = (Scaleform::Render::FontCacheHandle *)-1i64;
    v4->pNext = (Scaleform::Render::FontCacheHandle *)-1i64;
    v4->pPrev = v3->Fonts[1].Root.pPrev;
    v4->pNext = (Scaleform::Render::FontCacheHandle *)&v3->Fonts[1];
    v3->Fonts[1].Root.pPrev->pNext = v4;
    v3->Fonts[1].Root.pPrev = v4;
    v4->pFont = 0i64;
  }
  LeaveCriticalSection(v5);
}

// File Line: 121
// RVA: 0x9A7470
Scaleform::Render::FontCacheHandle *__fastcall Scaleform::Render::FontCacheHandleManager::RegisterFont(Scaleform::Render::FontCacheHandleManager *this, Scaleform::Render::Font *font)
{
  Scaleform::Render::Font *v2; // rbx
  Scaleform::Render::FontCacheHandleManager *v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::FontCacheHandle *v6; // rdx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+48h] [rbp+10h]

  v2 = font;
  v3 = this;
  if ( !font->hRef.pManager.Value )
  {
    _InterlockedExchangeAdd(&this->RefCount, 1u);
    font->hRef.pManager.Value = this;
  }
  if ( !font->hRef.pFontHandle )
  {
    lpCriticalSection = &this->FontLock.cs;
    EnterCriticalSection(&this->FontLock.cs);
    v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->pRenderHeap->vfptr->Alloc)(
           v3->pRenderHeap,
           32i64);
    if ( v4 )
    {
      *(_QWORD *)(v4 + 16) = v3;
      *(_QWORD *)(v4 + 24) = v2;
    }
    v2->hRef.pFontHandle = (Scaleform::Render::FontCacheHandle *volatile )v4;
    if ( !v2->hRef.pFontHandle )
    {
      LeaveCriticalSection(lpCriticalSection);
      return 0i64;
    }
    v6 = v2->hRef.pFontHandle;
    v6->pPrev = v3->Fonts[0].Root.pPrev;
    v6->pNext = (Scaleform::Render::FontCacheHandle *)v3->Fonts;
    v3->Fonts[0].Root.pPrev->pNext = v6;
    v3->Fonts[0].Root.pPrev = v6;
    LeaveCriticalSection(lpCriticalSection);
  }
  return v2->hRef.pFontHandle;
}

