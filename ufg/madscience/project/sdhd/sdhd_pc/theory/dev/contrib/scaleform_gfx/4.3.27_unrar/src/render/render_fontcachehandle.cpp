// File Line: 25
// RVA: 0x9EFC20
void __fastcall Scaleform::Render::FontCacheHandleRef::releaseFont(Scaleform::Render::FontCacheHandleRef *this)
{
  Scaleform::Render::FontCacheHandleManager *v1; // rbx

  v1 = (Scaleform::Render::FontCacheHandleManager *)_InterlockedExchange64((volatile __int64 *)this, 0i64);
  if ( v1 )
  {
    Scaleform::Render::FontCacheHandleManager::fontLost(v1, this);
    if ( !_InterlockedDecrement(&v1->RefCount) )
      v1->vfptr->__vecDelDtor(v1, 1u);
  }
}

// File Line: 45
// RVA: 0x99FC10
void __fastcall Scaleform::Render::FontCacheHandleManager::ProcessKillList(
        Scaleform::Render::FontCacheHandleManager *this)
{
  Scaleform::Lock *p_FontLock; // rbx
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *v3; // rsi
  Scaleform::Render::FontCacheHandle *pNext; // rdi
  char v5; // r15
  Scaleform::Render::FontCacheHandle *v6; // rbp
  Scaleform::Render::GlyphCache *pCache; // rcx

  p_FontLock = &this->FontLock;
  EnterCriticalSection(&this->FontLock.cs);
  v3 = &this->Fonts[1];
  pNext = this->Fonts[1].Root.pNext;
  if ( pNext != (Scaleform::Render::FontCacheHandle *)&this->Fonts[1] )
  {
    v5 = 0;
    do
    {
      v6 = pNext->pNext;
      pCache = this->pCache;
      if ( pCache )
      {
        Scaleform::Render::GlyphCache::CleanUpFont(pCache, pNext);
        v5 = 1;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pNext);
      pNext = v6;
    }
    while ( v6 != (Scaleform::Render::FontCacheHandle *)v3 );
    v3->Root.pPrev = (Scaleform::Render::FontCacheHandle *)v3;
    this->Fonts[1].Root.pNext = (Scaleform::Render::FontCacheHandle *)&this->Fonts[1];
    if ( v5 )
      Scaleform::Render::GlyphQueue::MergeEmptySlots(&this->pCache->Queue);
  }
  LeaveCriticalSection(&p_FontLock->cs);
}

// File Line: 53
// RVA: 0x96D540
void __fastcall Scaleform::Render::FontCacheHandleManager::DestroyAllFonts(
        Scaleform::Render::FontCacheHandleManager *this)
{
  Scaleform::Lock *p_FontLock; // rbx
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *v3; // rsi
  Scaleform::Render::FontCacheHandle *pNext; // rdi
  char v5; // r15
  Scaleform::Render::FontCacheHandle *v6; // r14
  Scaleform::Render::GlyphCache *pCache; // rcx
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *Fonts; // rsi
  Scaleform::Render::FontCacheHandle *v9; // rdi
  Scaleform::Render::FontCacheHandle *v10; // rbx
  __int64 v11; // rcx
  Scaleform::Lock *v12; // [rsp+50h] [rbp+8h]

  p_FontLock = &this->FontLock;
  v12 = &this->FontLock;
  EnterCriticalSection(&this->FontLock.cs);
  v3 = &this->Fonts[1];
  pNext = this->Fonts[1].Root.pNext;
  if ( pNext != (Scaleform::Render::FontCacheHandle *)&this->Fonts[1] )
  {
    v5 = 0;
    do
    {
      v6 = pNext->pNext;
      pCache = this->pCache;
      if ( pCache )
      {
        Scaleform::Render::GlyphCache::CleanUpFont(pCache, pNext);
        v5 = 1;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pNext);
      pNext = v6;
    }
    while ( v6 != (Scaleform::Render::FontCacheHandle *)v3 );
    v3->Root.pPrev = (Scaleform::Render::FontCacheHandle *)v3;
    this->Fonts[1].Root.pNext = (Scaleform::Render::FontCacheHandle *)&this->Fonts[1];
    if ( v5 )
      Scaleform::Render::GlyphQueue::MergeEmptySlots(&this->pCache->Queue);
  }
  Fonts = this->Fonts;
  v9 = this->Fonts[0].Root.pNext;
  if ( v9 != (Scaleform::Render::FontCacheHandle *)this->Fonts )
  {
    do
    {
      v10 = v9->pNext;
      v9->pFont->hRef.pFontHandle = 0i64;
      v11 = _InterlockedExchange64((volatile __int64 *)&v9->pFont->hRef, 0i64);
      if ( v11 && !_InterlockedDecrement((volatile signed __int32 *)(v11 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v11)(v11, 1i64);
      v9->pFont = 0i64;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
      v9 = v10;
    }
    while ( v10 != (Scaleform::Render::FontCacheHandle *)Fonts );
    Fonts->Root.pPrev = (Scaleform::Render::FontCacheHandle *)Fonts;
    this->Fonts[0].Root.pNext = (Scaleform::Render::FontCacheHandle *)this->Fonts;
    p_FontLock = v12;
  }
  LeaveCriticalSection(&p_FontLock->cs);
}

// File Line: 62
// RVA: 0x9E3270
void __fastcall Scaleform::Render::FontCacheHandleManager::fontLost(
        Scaleform::Render::FontCacheHandleManager *this,
        Scaleform::Render::FontCacheHandleRef *href)
{
  Scaleform::Render::FontCacheHandle *volatile pFontHandle; // r8
  Scaleform::Lock *p_FontLock; // [rsp+40h] [rbp+8h]

  p_FontLock = &this->FontLock;
  EnterCriticalSection(&this->FontLock.cs);
  pFontHandle = href->pFontHandle;
  if ( pFontHandle )
  {
    pFontHandle->pPrev->pNext = pFontHandle->pNext;
    pFontHandle->pNext->Scaleform::ListNode<Scaleform::Render::FontCacheHandle>::$241C431F049217F7D8597F3704BB3B65::pPrev = pFontHandle->pPrev;
    pFontHandle->pPrev = (Scaleform::Render::FontCacheHandle *)-1i64;
    pFontHandle->pNext = (Scaleform::Render::FontCacheHandle *)-1i64;
    pFontHandle->pPrev = this->Fonts[1].Root.pPrev;
    pFontHandle->pNext = (Scaleform::Render::FontCacheHandle *)&this->Fonts[1];
    this->Fonts[1].Root.pPrev->pNext = pFontHandle;
    this->Fonts[1].Root.pPrev = pFontHandle;
    pFontHandle->pFont = 0i64;
  }
  LeaveCriticalSection(&p_FontLock->cs);
}

// File Line: 121
// RVA: 0x9A7470
Scaleform::Render::FontCacheHandle *__fastcall Scaleform::Render::FontCacheHandleManager::RegisterFont(
        Scaleform::Render::FontCacheHandleManager *this,
        Scaleform::Render::Font *font)
{
  Scaleform::Render::FontCacheHandle *v4; // rax
  Scaleform::Render::FontCacheHandle *volatile pFontHandle; // rdx
  Scaleform::Lock *lpCriticalSection; // [rsp+48h] [rbp+10h]

  if ( !font->hRef.pManager.Value )
  {
    _InterlockedExchangeAdd(&this->RefCount, 1u);
    font->hRef.pManager.Value = this;
  }
  if ( !font->hRef.pFontHandle )
  {
    lpCriticalSection = &this->FontLock;
    EnterCriticalSection(&this->FontLock.cs);
    v4 = (Scaleform::Render::FontCacheHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pRenderHeap->vfptr->Alloc)(
                                                 this->pRenderHeap,
                                                 32i64);
    if ( v4 )
    {
      v4->pManager = this;
      v4->pFont = font;
    }
    font->hRef.pFontHandle = v4;
    if ( !font->hRef.pFontHandle )
    {
      LeaveCriticalSection(&lpCriticalSection->cs);
      return 0i64;
    }
    pFontHandle = font->hRef.pFontHandle;
    pFontHandle->pPrev = this->Fonts[0].Root.pPrev;
    pFontHandle->pNext = (Scaleform::Render::FontCacheHandle *)this->Fonts;
    this->Fonts[0].Root.pPrev->pNext = pFontHandle;
    this->Fonts[0].Root.pPrev = pFontHandle;
    LeaveCriticalSection(&lpCriticalSection->cs);
  }
  return font->hRef.pFontHandle;
}

