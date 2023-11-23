// File Line: 129
// RVA: 0x949550
void __fastcall Scaleform::Render::DICommand::~DICommand(Scaleform::Render::DICommand *this)
{
  Scaleform::Render::DrawableImage *pObject; // rcx

  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  pObject = this->pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[2].__vecDelDtor)(pObject);
}

// File Line: 175
// RVA: 0x98B670
__int64 __fastcall AkQueuedMsg::Sizeof_ListenerPosition()
{
  return 48i64;
}

// File Line: 297
// RVA: 0x9293B0
bool __fastcall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_ApplyFilter>(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::Render::DICommand_ApplyFilter *src)
{
  Scaleform::Render::DICommand_SourceRect *v3; // rax
  Scaleform::Render::DICommand_SourceRect *v4; // rbx
  Scaleform::Render::Filter *pObject; // rcx

  v3 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                    this,
                                                    0x38u,
                                                    &this->QueueLock);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v3, src);
    v4->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ApplyFilter>::`vftable;
    v4->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_ApplyFilter::`vftable;
    pObject = src->pFilter.pObject;
    if ( pObject )
      _InterlockedExchangeAdd(&pObject->RefCount, 1u);
    v4[1].vfptr = (Scaleform::Render::DICommandVtbl *)src->pFilter.pObject;
    LOBYTE(v3) = 1;
  }
  return (char)v3;
}

// File Line: 331
// RVA: 0x93B940
void __fastcall Scaleform::Render::DICommandQueue::ExecuteCommand::ExecuteCommand(
        Scaleform::Render::DICommandQueue::ExecuteCommand *this,
        Scaleform::Render::DICommandQueue *queue)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ThreadCommand::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DICommandQueue::ExecuteCommand::`vftable;
  this->pQueue = queue;
  this->ExecuteDone.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->ExecuteDone.RefCount = 1;
  this->ExecuteDone.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->ExecuteDone.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->ExecuteDone.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Waitable,2>::`vftable;
  this->ExecuteDone.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  this->ExecuteDone.pHandlers = 0i64;
  this->ExecuteDone.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  this->ExecuteDone.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  this->ExecuteDone.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&this->ExecuteDone.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->ExecuteDone.StateWaitCondition);
  this->ExecuteDone.State = 0;
  this->ExecuteDone.Temporary = 0;
}

// File Line: 337
// RVA: 0x9C2630
void __fastcall Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(
        Scaleform::Render::DICommandQueue::ExecuteCommand *this)
{
  Scaleform::Mutex *p_StateMutex; // rbx
  Scaleform::Mutex *v3; // [rsp+40h] [rbp+8h]

  p_StateMutex = &this->ExecuteDone.StateMutex;
  v3 = &this->ExecuteDone.StateMutex;
  Scaleform::Mutex::DoLock(&this->ExecuteDone.StateMutex);
  while ( !this->ExecuteDone.State )
    Scaleform::WaitCondition::Wait(&this->ExecuteDone.StateWaitCondition, p_StateMutex, 0xFFFFFFFF);
  if ( this->ExecuteDone.Temporary )
  {
    this->ExecuteDone.Temporary = 0;
    this->ExecuteDone.State = 0;
  }
  Scaleform::Mutex::Unlock(v3);
  Scaleform::Mutex::DoLock(p_StateMutex);
  this->ExecuteDone.State = 0;
  this->ExecuteDone.Temporary = 0;
  Scaleform::Mutex::Unlock(p_StateMutex);
}

// File Line: 433
// RVA: 0x93AD40
void __fastcall Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(
        Scaleform::Render::DICommand_SourceRect *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sr,
        Scaleform::Render::Point<long> *dp)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx

  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pImage.pObject = image;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( source )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))source->vfptr[1].__vecDelDtor)(source);
  this->pSource.pObject = source;
  y2 = sr->y2;
  x2 = sr->x2;
  y1 = sr->y1;
  this->SourceRect.x1 = sr->x1;
  this->SourceRect.y1 = y1;
  this->SourceRect.x2 = x2;
  this->SourceRect.y2 = y2;
  y = dp->y;
  this->DestPoint.x = dp->x;
  this->DestPoint.y = y;
}

// File Line: 461
// RVA: 0x98B690
__int64 __fastcall UFG::qReflectInventory<UFG::StatModifierTypeBase>::GetClassSize(hkpCapsuleShape *this)
{
  return 80i64;
}

// File Line: 468
// RVA: 0x974090
void __fastcall Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::ExecuteHWGetImages(
        Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *this,
        Scaleform::Render::DrawableImage **images,
        Scaleform::Render::Size<float> *readOffsets)
{
  int v6; // ebp
  float y; // xmm1_4
  __m128i v8; // xmm1

  v6 = 0;
  if ( (unsigned __int8)this->vfptr[1].GetCPUCaps(this) )
  {
    v6 = 1;
    *images = this->pImage.pObject;
    y = (float)this->DestPoint.y;
    readOffsets->Width = (float)this->DestPoint.x;
    readOffsets->Height = y;
  }
  images[v6] = this->pSource.pObject;
  v8 = _mm_cvtsi32_si128(this->SourceRect.y1);
  readOffsets[v6].Width = (float)this->SourceRect.x1;
  LODWORD(readOffsets[v6].Height) = _mm_cvtepi32_ps(v8).m128_u32[0];
}

// File Line: 522
// RVA: 0x93A000
void __fastcall Scaleform::Render::DICommand_Draw::DICommand_Draw(
        Scaleform::Render::DICommand_Draw *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::TreeRoot *root,
        Scaleform::Render::Rect<long> *clipRect)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx

  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pImage.pObject = image;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Draw,Scaleform::Render::DICommand>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Draw::`vftable;
  this->pRoot = root;
  *(_QWORD *)&this->ClipRect.x1 = 0i64;
  *(_QWORD *)&this->ClipRect.x2 = 0i64;
  this->HasClipRect = clipRect != 0i64;
  if ( clipRect )
  {
    y2 = clipRect->y2;
    x2 = clipRect->x2;
    y1 = clipRect->y1;
    this->ClipRect.x1 = clipRect->x1;
    this->ClipRect.y1 = y1;
    this->ClipRect.x2 = x2;
    this->ClipRect.y2 = y2;
  }
}

// File Line: 596
// RVA: 0x98B7E0
__int64 __fastcall Scaleform::Render::DICommand_CopyPixels::GetSourceImages(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DISourceImages *ps)
{
  Scaleform::Render::DrawableImage *pObject; // rax

  ps->pImages[0] = this->pSource.pObject;
  pObject = this->pAlphaSource.pObject;
  if ( !pObject )
    return 1i64;
  ps->pImages[1] = pObject;
  return 2i64;
}

// File Line: 616
// RVA: 0x939D60
void __fastcall Scaleform::Render::DICommand_ColorTransform::DICommand_ColorTransform(
        Scaleform::Render::DICommand_ColorTransform *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::Rect<long> *rect,
        Scaleform::Render::Cxform *cxform)
{
  int y1; // r14d
  int x1; // r15d
  int y2; // r8d
  int x2; // edx
  int v12; // ecx

  y1 = rect->y1;
  x1 = rect->x1;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pImage.pObject = image;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pSource.pObject = image;
  y2 = rect->y2;
  x2 = rect->x2;
  v12 = rect->y1;
  this->SourceRect.x1 = rect->x1;
  this->SourceRect.y1 = v12;
  this->SourceRect.x2 = x2;
  this->SourceRect.y2 = y2;
  this->DestPoint.x = x1;
  this->DestPoint.y = y1;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ColorTransform>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_ColorTransform::`vftable;
  *(_OWORD *)&this->Cx.M[0][0] = *(_OWORD *)&cxform->M[0][0];
  *(_OWORD *)&this->Cx.M[1][0] = *(_OWORD *)&cxform->M[1][0];
}

// File Line: 632
// RVA: 0x939E40
void __fastcall Scaleform::Render::DICommand_Compare::DICommand_Compare(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *cmp0,
        Scaleform::Render::DrawableImage *cmp1)
{
  int *v8; // rax
  int v9; // ebp
  int v10; // r15d
  char v11; // [rsp+68h] [rbp+10h] BYREF

  v8 = (int *)image->vfptr[5].__vecDelDtor(image, &v11);
  v9 = v8[1];
  v10 = *v8;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pImage.pObject = image;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( cmp0 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmp0->vfptr[1].__vecDelDtor)(cmp0);
  this->pSource.pObject = cmp0;
  *(_QWORD *)&this->SourceRect.x1 = 0i64;
  this->SourceRect.x2 = v10;
  this->SourceRect.y2 = v9;
  this->DestPoint = 0i64;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Compare>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Compare::`vftable;
  if ( cmp1 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmp1->vfptr[1].__vecDelDtor)(cmp1);
  this->pImageCompare1.pObject = cmp1;
}

// File Line: 635
// RVA: 0x98B7C0
__int64 __fastcall Scaleform::Render::DICommand_Compare::GetSourceImages(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DISourceImages *ps)
{
  ps->pImages[0] = this->pSource.pObject;
  ps->pImages[1] = this->pImageCompare1.pObject;
  return 2i64;
}

// File Line: 643
// RVA: 0x98B0A0
bool __fastcall Scaleform::Render::DICommand_Compare::GetRequireSourceRead(Scaleform::Render::DICommand_Compare *this)
{
  Scaleform::Render::DrawableImage *pObject; // rax

  pObject = this->pImage.pObject;
  return this->pSource.pObject == pObject || this->pImageCompare1.pObject == pObject;
}

// File Line: 700
// RVA: 0x980A40
__int64 __fastcall Scaleform::Render::DICommand_Histogram::GetCPUCaps(Scaleform::Render::DICommand_HitTest *this)
{
  return 49i64;
}

// File Line: 745
// RVA: 0x98E2E0
__int64 __fastcall Scaleform::Render::DICommand_GetPixels::GetType(SSConditional *this)
{
  return 14i64;
}

// File Line: 794
// RVA: 0x98B800
Scaleform::Render::Image *__fastcall Scaleform::Render::DICommand_HitTest::GetSourceImages(
        Scaleform::Render::DICommand_HitTest *this,
        Scaleform::Render::DISourceImages *ps)
{
  Scaleform::Render::Image *result; // rax

  result = this->SecondImage.pObject;
  if ( result )
  {
    ps->pImages[0] = result;
    return (Scaleform::Render::Image *)1;
  }
  return result;
}

// File Line: 846
// RVA: 0x98E300
__int64 __fastcall Scaleform::Render::DICommand_Noise::GetType(hkpCylinderShape *this)
{
  return 18i64;
}

// File Line: 867
// RVA: 0x93A570
void __fastcall Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(
        Scaleform::Render::DICommand_PaletteMap *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sr,
        Scaleform::Render::Point<long> *dp,
        unsigned int **channels)
{
  unsigned int *v7; // rax
  __int64 v8; // rdi
  _OWORD *v9; // rdx
  unsigned int *v10; // rcx
  __int64 v11; // rax
  unsigned int *v12; // rdx
  unsigned int *v13; // rcx
  __int64 v14; // rax
  unsigned int *v15; // rdx
  unsigned int *v16; // rcx
  __int64 v17; // rax
  unsigned int *v18; // rdx
  unsigned int *v19; // rcx

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(this, image, source, sr, dp);
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  this->ChannelMask = 0;
  v7 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 4096i64, 0i64);
  this->Channels = v7;
  memset(v7, 0, 0x1000ui64);
  v8 = 8i64;
  if ( *channels )
  {
    this->ChannelMask |= 1u;
    v9 = *channels;
    v10 = this->Channels;
    if ( (((unsigned __int8)v10 | (unsigned __int8)*channels) & 0xF) != 0 )
    {
      memmove(v10, v9, 0x400ui64);
    }
    else
    {
      v11 = 8i64;
      do
      {
        *(_OWORD *)v10 = *v9;
        *((_OWORD *)v10 + 1) = v9[1];
        *((_OWORD *)v10 + 2) = v9[2];
        *((_OWORD *)v10 + 3) = v9[3];
        *((_OWORD *)v10 + 4) = v9[4];
        *((_OWORD *)v10 + 5) = v9[5];
        *((_OWORD *)v10 + 6) = v9[6];
        v10 += 32;
        *((_OWORD *)v10 - 1) = v9[7];
        v9 += 8;
        --v11;
      }
      while ( v11 );
    }
  }
  if ( channels[1] )
  {
    this->ChannelMask |= 2u;
    v12 = channels[1];
    v13 = this->Channels + 256;
    if ( ((LOBYTE(this->Channels) | (unsigned __int8)v12) & 0xF) != 0 )
    {
      memmove(v13, v12, 0x400ui64);
    }
    else
    {
      v14 = 8i64;
      do
      {
        *(_OWORD *)v13 = *(_OWORD *)v12;
        *((_OWORD *)v13 + 1) = *((_OWORD *)v12 + 1);
        *((_OWORD *)v13 + 2) = *((_OWORD *)v12 + 2);
        *((_OWORD *)v13 + 3) = *((_OWORD *)v12 + 3);
        *((_OWORD *)v13 + 4) = *((_OWORD *)v12 + 4);
        *((_OWORD *)v13 + 5) = *((_OWORD *)v12 + 5);
        *((_OWORD *)v13 + 6) = *((_OWORD *)v12 + 6);
        v13 += 32;
        *((_OWORD *)v13 - 1) = *((_OWORD *)v12 + 7);
        v12 += 32;
        --v14;
      }
      while ( v14 );
    }
  }
  if ( channels[2] )
  {
    this->ChannelMask |= 4u;
    v15 = channels[2];
    v16 = this->Channels + 512;
    if ( ((LOBYTE(this->Channels) | (unsigned __int8)v15) & 0xF) != 0 )
    {
      memmove(v16, v15, 0x400ui64);
    }
    else
    {
      v17 = 8i64;
      do
      {
        *(_OWORD *)v16 = *(_OWORD *)v15;
        *((_OWORD *)v16 + 1) = *((_OWORD *)v15 + 1);
        *((_OWORD *)v16 + 2) = *((_OWORD *)v15 + 2);
        *((_OWORD *)v16 + 3) = *((_OWORD *)v15 + 3);
        *((_OWORD *)v16 + 4) = *((_OWORD *)v15 + 4);
        *((_OWORD *)v16 + 5) = *((_OWORD *)v15 + 5);
        *((_OWORD *)v16 + 6) = *((_OWORD *)v15 + 6);
        v16 += 32;
        *((_OWORD *)v16 - 1) = *((_OWORD *)v15 + 7);
        v15 += 32;
        --v17;
      }
      while ( v17 );
    }
  }
  if ( channels[3] )
  {
    this->ChannelMask |= 8u;
    v18 = channels[3];
    v19 = this->Channels + 768;
    if ( ((LOBYTE(this->Channels) | (unsigned __int8)v18) & 0xF) != 0 )
    {
      memmove(v19, v18, 0x400ui64);
    }
    else
    {
      do
      {
        *(_OWORD *)v19 = *(_OWORD *)v18;
        *((_OWORD *)v19 + 1) = *((_OWORD *)v18 + 1);
        *((_OWORD *)v19 + 2) = *((_OWORD *)v18 + 2);
        *((_OWORD *)v19 + 3) = *((_OWORD *)v18 + 3);
        *((_OWORD *)v19 + 4) = *((_OWORD *)v18 + 4);
        *((_OWORD *)v19 + 5) = *((_OWORD *)v18 + 5);
        *((_OWORD *)v19 + 6) = *((_OWORD *)v18 + 6);
        v19 += 32;
        *((_OWORD *)v19 - 1) = *((_OWORD *)v18 + 7);
        v18 += 32;
        --v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 883
// RVA: 0x93A490
void __fastcall Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(
        Scaleform::Render::DICommand_PaletteMap *this,
        Scaleform::Render::DICommand_PaletteMap *other)
{
  unsigned int *v4; // rax
  unsigned int *Channels; // rdx
  __int64 v6; // rcx

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(this, other);
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  this->ChannelMask = other->ChannelMask;
  v4 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 4096i64, 0i64);
  this->Channels = v4;
  Channels = other->Channels;
  if ( (((unsigned __int8)v4 | (unsigned __int8)Channels) & 0xF) != 0 )
  {
    memmove(v4, Channels, 0x1000ui64);
  }
  else
  {
    v6 = 32i64;
    do
    {
      *(_OWORD *)v4 = *(_OWORD *)Channels;
      *((_OWORD *)v4 + 1) = *((_OWORD *)Channels + 1);
      *((_OWORD *)v4 + 2) = *((_OWORD *)Channels + 2);
      *((_OWORD *)v4 + 3) = *((_OWORD *)Channels + 3);
      *((_OWORD *)v4 + 4) = *((_OWORD *)Channels + 4);
      *((_OWORD *)v4 + 5) = *((_OWORD *)Channels + 5);
      *((_OWORD *)v4 + 6) = *((_OWORD *)Channels + 6);
      v4 += 32;
      *((_OWORD *)v4 - 1) = *((_OWORD *)Channels + 7);
      Channels += 32;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 889
// RVA: 0x949850
void __fastcall Scaleform::Render::DICommand_PaletteMap::~DICommand_PaletteMap(
        Scaleform::Render::DICommand_PaletteMap *this)
{
  Scaleform::Render::DrawableImage *pObject; // rcx
  Scaleform::Render::DrawableImage *v3; // rcx

  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  if ( this->Channels )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Channels = 0i64;
  pObject = this->pSource.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[2].__vecDelDtor)(pObject);
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  v3 = this->pImage.pObject;
  if ( v3 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
}

// File Line: 898
// RVA: 0x98B0C0
bool __fastcall Scaleform::Render::DICommand_PaletteMap::GetRequireSourceRead(
        Scaleform::Render::DICommand_PaletteMap *this)
{
  return this->pImage.pObject == this->pSource.pObject;
}

// File Line: 925
// RVA: 0x93A900
void __fastcall Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(
        Scaleform::Render::DICommand_PerlinNoise *this,
        Scaleform::Render::DrawableImage *image,
        float frequencyX,
        float frequencyY,
        unsigned int octaves,
        unsigned int seed,
        bool stitch,
        bool fractal,
        unsigned int channels,
        bool grayScale,
        float *offsets,
        unsigned int offsetCount)
{
  unsigned int v14; // eax

  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pImage.pObject = image;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_PerlinNoise,Scaleform::Render::DICommand>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PerlinNoise::`vftable;
  this->FrequencyX = frequencyX;
  this->FrequencyY = frequencyY;
  this->NumOctaves = octaves;
  this->RandomSeed = seed;
  this->Stitch = stitch;
  this->FractalNoise = fractal;
  this->ChannelMask = channels;
  this->GrayScale = grayScale;
  v14 = 16;
  if ( offsetCount < 0x10 )
    v14 = offsetCount;
  this->OffsetCount = v14;
  if ( offsetCount )
    memmove(this->Offsets, offsets, 4i64 * offsetCount);
}

// File Line: 935
// RVA: 0x93A830
void __fastcall Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(
        Scaleform::Render::DICommand_PerlinNoise *this,
        Scaleform::Render::DICommand_PerlinNoise *other)
{
  Scaleform::Render::DrawableImage *pObject; // rcx
  unsigned int OffsetCount; // eax
  size_t v6; // r8

  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  pObject = other->pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[1].__vecDelDtor)(pObject);
  this->pImage.pObject = other->pImage.pObject;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_PerlinNoise,Scaleform::Render::DICommand>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PerlinNoise::`vftable;
  this->FrequencyX = other->FrequencyX;
  this->FrequencyY = other->FrequencyY;
  this->NumOctaves = other->NumOctaves;
  this->RandomSeed = other->RandomSeed;
  this->Stitch = other->Stitch;
  this->FractalNoise = other->FractalNoise;
  this->ChannelMask = other->ChannelMask;
  this->GrayScale = other->GrayScale;
  this->OffsetCount = other->OffsetCount;
  OffsetCount = other->OffsetCount;
  if ( OffsetCount )
  {
    v6 = 4i64 * OffsetCount;
    if ( v6 > 0x80 )
      v6 = 128i64;
    memmove(this->Offsets, other->Offsets, v6);
  }
}

// File Line: 967
// RVA: 0x98B820
__int64 __fastcall Scaleform::Render::DICommand_SourceRect::GetSourceImages(
        Scaleform::Render::DICommand_SourceRect *this,
        Scaleform::Render::DISourceImages *ps)
{
  ps->pImages[0] = this->pSource.pObject;
  return 1i64;
}

// File Line: 972
// RVA: 0x98E310
__int64 __fastcall Scaleform::Render::DICommand_PixelDissolve::GetType(SSInvokeCascade *this)
{
  return 21i64;
}

// File Line: 973
// RVA: 0x98E2F0
__int64 __fastcall Scaleform::Render::DICommand_PixelDissolve::GetCPUCaps(SSLoopExit *this)
{
  return 17i64;
}

// File Line: 1019
// RVA: 0x98E320
__int64 __fastcall SSInvokeClosureCoroutine::get_type(SSInvokeClosureCoroutine *this)
{
  return 23i64;
}

// File Line: 1036
// RVA: 0x93AAC0
void __fastcall Scaleform::Render::DICommand_Scroll::DICommand_Scroll(
        Scaleform::Render::DICommand_Scroll *this,
        Scaleform::Render::DrawableImage *image,
        int x,
        int y)
{
  int v8; // edi
  int v9; // ebx
  char v10[48]; // [rsp+28h] [rbp-30h] BYREF
  char v11; // [rsp+68h] [rbp+10h] BYREF

  v8 = *((_DWORD *)image->vfptr[5].__vecDelDtor(image, &v11) + 1);
  v9 = *(_DWORD *)image->vfptr[5].__vecDelDtor(image, v10);
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pImage.pObject = image;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  this->pSource.pObject = image;
  *(_QWORD *)&this->SourceRect.x1 = 0i64;
  this->SourceRect.x2 = v9;
  this->SourceRect.y2 = v8;
  this->DestPoint.x = x;
  this->DestPoint.y = y;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::`vftable;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Scroll::`vftable;
  this->X = x;
  this->Y = y;
}

// File Line: 1064
// RVA: 0x98B0D0
_BOOL8 __fastcall Scaleform::Render::DICommand_Threshold::GetRequireSourceRead(
        Scaleform::Render::DICommand_Threshold *this)
{
  return this->CopySource;
}

