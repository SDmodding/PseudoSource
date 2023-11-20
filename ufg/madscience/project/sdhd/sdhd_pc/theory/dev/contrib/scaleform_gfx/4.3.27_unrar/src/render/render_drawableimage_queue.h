// File Line: 129
// RVA: 0x949550
void __fastcall Scaleform::Render::DICommand::~DICommand(Scaleform::Render::DICommand *this)
{
  Scaleform::Render::DrawableImage *v1; // rcx

  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  v1 = this->pImage.pObject;
  if ( v1 )
    ((void (*)(void))v1->vfptr[2].__vecDelDtor)();
}

// File Line: 175
// RVA: 0x98B670
signed __int64 __fastcall AkQueuedMsg::Sizeof_ListenerPosition()
{
  return 48i64;
}

// File Line: 297
// RVA: 0x9293B0
bool __fastcall Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_ApplyFilter>(Scaleform::Render::DICommandQueue *this, Scaleform::Render::DICommand_ApplyFilter *src)
{
  Scaleform::Render::DICommand_ApplyFilter *v2; // rdi
  Scaleform::Render::DICommand_SourceRect *v3; // rax
  Scaleform::Render::DICommand_SourceRect *v4; // rbx
  Scaleform::Render::Filter *v5; // rcx

  v2 = src;
  v3 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                    this,
                                                    0x38u,
                                                    &this->QueueLock);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(
      v3,
      (Scaleform::Render::DICommand_SourceRect *)&v2->vfptr);
    v4->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ApplyFilter>::`vftable;
    v4->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_ApplyFilter::`vftable;
    v5 = v2->pFilter.pObject;
    if ( v5 )
      _InterlockedExchangeAdd(&v5->RefCount, 1u);
    v4[1].vfptr = (Scaleform::Render::DICommandVtbl *)v2->pFilter.pObject;
    LOBYTE(v3) = 1;
  }
  return (char)v3;
}

// File Line: 331
// RVA: 0x93B940
void __fastcall Scaleform::Render::DICommandQueue::ExecuteCommand::ExecuteCommand(Scaleform::Render::DICommandQueue::ExecuteCommand *this, Scaleform::Render::DICommandQueue *queue)
{
  Scaleform::Render::DICommandQueue::ExecuteCommand *v2; // rdi
  Scaleform::Event *v3; // [rsp+48h] [rbp+10h]

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ThreadCommand::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DICommandQueue::ExecuteCommand::`vftable;
  this->pQueue = queue;
  v3 = &this->ExecuteDone;
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v3->RefCount = 1;
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Waitable,2>::`vftable;
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Waitable::`vftable;
  this->ExecuteDone.pHandlers = 0i64;
  this->ExecuteDone.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::AcquireInterface::`vftable;
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Event::`vftable{for `Scaleform::Waitable};
  this->ExecuteDone.vfptr = (Scaleform::AcquireInterfaceVtbl *)&Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
  Scaleform::Mutex::Mutex(&this->ExecuteDone.StateMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v2->ExecuteDone.StateWaitCondition);
  v2->ExecuteDone.State = 0;
  v2->ExecuteDone.Temporary = 0;
}

// File Line: 337
// RVA: 0x9C2630
void __fastcall Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(Scaleform::Render::DICommandQueue::ExecuteCommand *this)
{
  Scaleform::Render::DICommandQueue::ExecuteCommand *v1; // rdi
  Scaleform::Mutex *v2; // rbx
  volatile bool v3; // t1
  Scaleform::Mutex *v4; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = &this->ExecuteDone.StateMutex;
  v4 = &this->ExecuteDone.StateMutex;
  Scaleform::Mutex::DoLock(&this->ExecuteDone.StateMutex);
  while ( !v1->ExecuteDone.State )
    Scaleform::WaitCondition::Wait(&v1->ExecuteDone.StateWaitCondition, v2, 0xFFFFFFFF);
  v3 = v1->ExecuteDone.State;
  if ( v1->ExecuteDone.Temporary )
  {
    v1->ExecuteDone.Temporary = 0;
    v1->ExecuteDone.State = 0;
  }
  Scaleform::Mutex::Unlock(v4);
  Scaleform::Mutex::DoLock(v2);
  v1->ExecuteDone.State = 0;
  v1->ExecuteDone.Temporary = 0;
  Scaleform::Mutex::Unlock(v2);
}

// File Line: 433
// RVA: 0x93AD40
void __fastcall Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(Scaleform::Render::DICommand_SourceRect *this, Scaleform::Render::DrawableImage *image, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sr, Scaleform::Render::Point<long> *dp)
{
  Scaleform::Render::Rect<long> *v5; // r14
  Scaleform::Render::DrawableImage *v6; // rsi
  Scaleform::Render::DrawableImage *v7; // rdi
  Scaleform::Render::DICommand_SourceRect *v8; // rbx
  int v9; // er8
  int v10; // edx
  int v11; // ecx
  int v12; // ecx

  v5 = sr;
  v6 = source;
  v7 = image;
  v8 = this;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  v8->pImage.pObject = v7;
  v8->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
  v8->pSource.pObject = v6;
  v9 = v5->y2;
  v10 = v5->x2;
  v11 = v5->y1;
  v8->SourceRect.x1 = v5->x1;
  v8->SourceRect.y1 = v11;
  v8->SourceRect.x2 = v10;
  v8->SourceRect.y2 = v9;
  v12 = dp->y;
  v8->DestPoint.x = dp->x;
  v8->DestPoint.y = v12;
}

// File Line: 461
// RVA: 0x98B690
signed __int64 __fastcall UFG::qReflectInventory<UFG::StatModifierTypeBase>::GetClassSize(hkpCapsuleShape *this)
{
  return 80i64;
}

// File Line: 468
// RVA: 0x974090
void __fastcall Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::ExecuteHWGetImages(Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *this, Scaleform::Render::DrawableImage **images, Scaleform::Render::Size<float> *readOffsets)
{
  Scaleform::Render::Size<float> *v3; // rdi
  Scaleform::Render::DrawableImage **v4; // rsi
  Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *v5; // rbx
  unsigned int v6; // ebp
  float v7; // xmm1_4
  __int64 v8; // rcx
  __m128i v9; // xmm1

  v3 = readOffsets;
  v4 = images;
  v5 = this;
  v6 = 0;
  if ( ((unsigned __int8 (*)(void))this->vfptr[1].GetCPUCaps)() )
  {
    v6 = 1;
    *v4 = v5->pImage.pObject;
    v7 = (float)v5->DestPoint.y;
    v3->Width = (float)v5->DestPoint.x;
    v3->Height = v7;
  }
  v8 = v6;
  v4[v8] = v5->pSource.pObject;
  v9 = _mm_cvtsi32_si128(v5->SourceRect.y1);
  v3[v8].Width = (float)v5->SourceRect.x1;
  LODWORD(v3[v8].Height) = (unsigned __int128)_mm_cvtepi32_ps(v9);
}

// File Line: 522
// RVA: 0x93A000
void __fastcall Scaleform::Render::DICommand_Draw::DICommand_Draw(Scaleform::Render::DICommand_Draw *this, Scaleform::Render::DrawableImage *image, Scaleform::Render::TreeRoot *root, Scaleform::Render::Rect<long> *clipRect)
{
  Scaleform::Render::Rect<long> *v4; // rdi
  Scaleform::Render::TreeRoot *v5; // rbp
  Scaleform::Render::DrawableImage *v6; // rsi
  Scaleform::Render::DICommand_Draw *v7; // rbx
  int v8; // er8
  int v9; // edx
  int v10; // ecx

  v4 = clipRect;
  v5 = root;
  v6 = image;
  v7 = this;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  v7->pImage.pObject = v6;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Draw,Scaleform::Render::DICommand>::`vftable;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Draw::`vftable;
  v7->pRoot = v5;
  *(_QWORD *)&v7->ClipRect.x1 = 0i64;
  *(_QWORD *)&v7->ClipRect.x2 = 0i64;
  v7->HasClipRect = v4 != 0i64;
  if ( v4 )
  {
    v8 = v4->y2;
    v9 = v4->x2;
    v10 = v4->y1;
    v7->ClipRect.x1 = v4->x1;
    v7->ClipRect.y1 = v10;
    v7->ClipRect.x2 = v9;
    v7->ClipRect.y2 = v8;
  }
}

// File Line: 596
// RVA: 0x98B7E0
signed __int64 __fastcall Scaleform::Render::DICommand_CopyPixels::GetSourceImages(Scaleform::Render::DICommand_CopyPixels *this, Scaleform::Render::DISourceImages *ps)
{
  Scaleform::Render::DrawableImage *v2; // rax

  ps->pImages[0] = (Scaleform::Render::Image *)&this->pSource.pObject->vfptr;
  v2 = this->pAlphaSource.pObject;
  if ( !v2 )
    return 1i64;
  ps->pImages[1] = (Scaleform::Render::Image *)&v2->vfptr;
  return 2i64;
}

// File Line: 616
// RVA: 0x939D60
void __fastcall Scaleform::Render::DICommand_ColorTransform::DICommand_ColorTransform(Scaleform::Render::DICommand_ColorTransform *this, Scaleform::Render::DrawableImage *image, Scaleform::Render::Rect<long> *rect, Scaleform::Render::Cxform *cxform)
{
  Scaleform::Render::Cxform *v4; // rbp
  Scaleform::Render::Rect<long> *v5; // rsi
  Scaleform::Render::DrawableImage *v6; // rbx
  Scaleform::Render::DICommand_ColorTransform *v7; // rdi
  int v8; // er14
  int v9; // er15
  int v10; // er8
  int v11; // edx
  int v12; // ecx

  v4 = cxform;
  v5 = rect;
  v6 = image;
  v7 = this;
  v8 = rect->y1;
  v9 = rect->x1;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  v7->pImage.pObject = v6;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
  v7->pSource.pObject = v6;
  v10 = v5->y2;
  v11 = v5->x2;
  v12 = v5->y1;
  v7->SourceRect.x1 = v5->x1;
  v7->SourceRect.y1 = v12;
  v7->SourceRect.x2 = v11;
  v7->SourceRect.y2 = v10;
  v7->DestPoint.x = v9;
  v7->DestPoint.y = v8;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ColorTransform>::`vftable;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_ColorTransform::`vftable;
  *(_OWORD *)&v7->Cx.M[0][0] = *(_OWORD *)&v4->M[0][0];
  *(_OWORD *)&v7->Cx.M[1][0] = *(_OWORD *)&v4->M[1][0];
}

// File Line: 632
// RVA: 0x939E40
void __fastcall Scaleform::Render::DICommand_Compare::DICommand_Compare(Scaleform::Render::DICommand_Compare *this, Scaleform::Render::DrawableImage *image, Scaleform::Render::DrawableImage *cmp0, Scaleform::Render::DrawableImage *cmp1)
{
  Scaleform::Render::DrawableImage *v4; // rsi
  Scaleform::Render::DrawableImage *v5; // r14
  Scaleform::Render::DrawableImage *v6; // rbx
  Scaleform::Render::DICommand_Compare *v7; // rdi
  int *v8; // rax
  int v9; // ebp
  int v10; // er15
  char v11; // [rsp+68h] [rbp+10h]

  v4 = cmp1;
  v5 = cmp0;
  v6 = image;
  v7 = this;
  v8 = (int *)image->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)image, (unsigned int)&v11);
  v9 = v8[1];
  v10 = *v8;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
  v7->pImage.pObject = v6;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[1].__vecDelDtor)(v5);
  v7->pSource.pObject = v5;
  *(_QWORD *)&v7->SourceRect.x1 = 0i64;
  v7->SourceRect.x2 = v10;
  v7->SourceRect.y2 = v9;
  v7->DestPoint = 0i64;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Compare>::`vftable;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Compare::`vftable;
  if ( v4 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
  v7->pImageCompare1.pObject = v4;
}

// File Line: 635
// RVA: 0x98B7C0
signed __int64 __fastcall Scaleform::Render::DICommand_Compare::GetSourceImages(Scaleform::Render::DICommand_Compare *this, Scaleform::Render::DISourceImages *ps)
{
  ps->pImages[0] = (Scaleform::Render::Image *)&this->pSource.pObject->vfptr;
  ps->pImages[1] = (Scaleform::Render::Image *)&this->pImageCompare1.pObject->vfptr;
  return 2i64;
}

// File Line: 643
// RVA: 0x98B0A0
bool __fastcall Scaleform::Render::DICommand_Compare::GetRequireSourceRead(Scaleform::Render::DICommand_Compare *this)
{
  Scaleform::Render::DrawableImage *v1; // rax

  v1 = this->pImage.pObject;
  return this->pSource.pObject == v1 || this->pImageCompare1.pObject == v1;
}

// File Line: 700
// RVA: 0x980A40
signed __int64 __fastcall Scaleform::Render::DICommand_Histogram::GetCPUCaps(Scaleform::Render::DICommand_HitTest *this)
{
  return 49i64;
}

// File Line: 745
// RVA: 0x98E2E0
signed __int64 __fastcall Scaleform::Render::DICommand_GetPixels::GetType(SSConditional *this)
{
  return 14i64;
}

// File Line: 794
// RVA: 0x98B800
Scaleform::Render::Image *__fastcall Scaleform::Render::DICommand_HitTest::GetSourceImages(Scaleform::Render::DICommand_HitTest *this, Scaleform::Render::DISourceImages *ps)
{
  Scaleform::Render::Image *result; // rax

  result = this->SecondImage.pObject;
  if ( result )
  {
    ps->pImages[0] = result;
    result = (Scaleform::Render::Image *)1;
  }
  return result;
}

// File Line: 846
// RVA: 0x98E300
signed __int64 __fastcall Scaleform::Render::DICommand_Noise::GetType(hkpCylinderShape *this)
{
  return 18i64;
}

// File Line: 867
// RVA: 0x93A570
void __fastcall Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(Scaleform::Render::DICommand_PaletteMap *this, Scaleform::Render::DrawableImage *image, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sr, Scaleform::Render::Point<long> *dp, unsigned int **channels)
{
  Scaleform::Render::DICommand_PaletteMap *v6; // rbx
  unsigned int *v7; // rax
  signed __int64 v8; // rdi
  unsigned int *v9; // rdx
  unsigned int *v10; // rcx
  signed __int64 v11; // rax
  unsigned int *v12; // rdx
  _OWORD *v13; // rcx
  signed __int64 v14; // rax
  unsigned int *v15; // rdx
  _OWORD *v16; // rcx
  signed __int64 v17; // rax
  unsigned int *v18; // rdx
  _OWORD *v19; // rcx

  v6 = this;
  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(
    (Scaleform::Render::DICommand_SourceRect *)&this->vfptr,
    image,
    source,
    sr,
    dp);
  v6->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::`vftable;
  v6->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  v6->ChannelMask = 0;
  v7 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 4096ui64, 0i64);
  v6->Channels = v7;
  memset(v7, 0, 0x1000ui64);
  v8 = 8i64;
  if ( *channels )
  {
    v6->ChannelMask |= 1u;
    v9 = *channels;
    v10 = v6->Channels;
    if ( ((unsigned __int8)v10 | (unsigned __int8)*channels) & 0xF )
    {
      memmove(v10, v9, 0x400ui64);
    }
    else
    {
      v11 = 8i64;
      do
      {
        *(_OWORD *)v10 = *(_OWORD *)v9;
        *((_OWORD *)v10 + 1) = *((_OWORD *)v9 + 1);
        *((_OWORD *)v10 + 2) = *((_OWORD *)v9 + 2);
        *((_OWORD *)v10 + 3) = *((_OWORD *)v9 + 3);
        *((_OWORD *)v10 + 4) = *((_OWORD *)v9 + 4);
        *((_OWORD *)v10 + 5) = *((_OWORD *)v9 + 5);
        *((_OWORD *)v10 + 6) = *((_OWORD *)v9 + 6);
        v10 += 32;
        *((_OWORD *)v10 - 1) = *((_OWORD *)v9 + 7);
        v9 += 32;
        --v11;
      }
      while ( v11 );
    }
  }
  if ( channels[1] )
  {
    v6->ChannelMask |= 2u;
    v12 = channels[1];
    v13 = v6->Channels + 256;
    if ( (LOBYTE(v6->Channels) | (unsigned __int8)channels[1]) & 0xF )
    {
      memmove(v13, v12, 0x400ui64);
    }
    else
    {
      v14 = 8i64;
      do
      {
        *v13 = *(_OWORD *)v12;
        v13[1] = *((_OWORD *)v12 + 1);
        v13[2] = *((_OWORD *)v12 + 2);
        v13[3] = *((_OWORD *)v12 + 3);
        v13[4] = *((_OWORD *)v12 + 4);
        v13[5] = *((_OWORD *)v12 + 5);
        v13[6] = *((_OWORD *)v12 + 6);
        v13 += 8;
        *(v13 - 1) = *((_OWORD *)v12 + 7);
        v12 += 32;
        --v14;
      }
      while ( v14 );
    }
  }
  if ( channels[2] )
  {
    v6->ChannelMask |= 4u;
    v15 = channels[2];
    v16 = v6->Channels + 512;
    if ( (LOBYTE(v6->Channels) | (unsigned __int8)channels[2]) & 0xF )
    {
      memmove(v16, v15, 0x400ui64);
    }
    else
    {
      v17 = 8i64;
      do
      {
        *v16 = *(_OWORD *)v15;
        v16[1] = *((_OWORD *)v15 + 1);
        v16[2] = *((_OWORD *)v15 + 2);
        v16[3] = *((_OWORD *)v15 + 3);
        v16[4] = *((_OWORD *)v15 + 4);
        v16[5] = *((_OWORD *)v15 + 5);
        v16[6] = *((_OWORD *)v15 + 6);
        v16 += 8;
        *(v16 - 1) = *((_OWORD *)v15 + 7);
        v15 += 32;
        --v17;
      }
      while ( v17 );
    }
  }
  if ( channels[3] )
  {
    v6->ChannelMask |= 8u;
    v18 = channels[3];
    v19 = v6->Channels + 768;
    if ( (LOBYTE(v6->Channels) | (unsigned __int8)channels[3]) & 0xF )
    {
      memmove(v19, v18, 0x400ui64);
    }
    else
    {
      do
      {
        *v19 = *(_OWORD *)v18;
        v19[1] = *((_OWORD *)v18 + 1);
        v19[2] = *((_OWORD *)v18 + 2);
        v19[3] = *((_OWORD *)v18 + 3);
        v19[4] = *((_OWORD *)v18 + 4);
        v19[5] = *((_OWORD *)v18 + 5);
        v19[6] = *((_OWORD *)v18 + 6);
        v19 += 8;
        *(v19 - 1) = *((_OWORD *)v18 + 7);
        v18 += 32;
        --v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 883
// RVA: 0x93A490
void __fastcall Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(Scaleform::Render::DICommand_PaletteMap *this, Scaleform::Render::DICommand_PaletteMap *other)
{
  Scaleform::Render::DICommand_PaletteMap *v2; // rdi
  Scaleform::Render::DICommand_PaletteMap *v3; // rbx
  unsigned int *v4; // rax
  unsigned int *v5; // rdx
  signed __int64 v6; // rcx

  v2 = other;
  v3 = this;
  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(
    (Scaleform::Render::DICommand_SourceRect *)&this->vfptr,
    (Scaleform::Render::DICommand_SourceRect *)&other->vfptr);
  v3->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::`vftable;
  v3->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  v3->ChannelMask = v2->ChannelMask;
  v4 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 4096ui64, 0i64);
  v3->Channels = v4;
  v5 = v2->Channels;
  if ( ((unsigned __int8)v4 | (unsigned __int8)v2->Channels) & 0xF )
  {
    memmove(v4, v5, 0x1000ui64);
  }
  else
  {
    v6 = 32i64;
    do
    {
      *(_OWORD *)v4 = *(_OWORD *)v5;
      *((_OWORD *)v4 + 1) = *((_OWORD *)v5 + 1);
      *((_OWORD *)v4 + 2) = *((_OWORD *)v5 + 2);
      *((_OWORD *)v4 + 3) = *((_OWORD *)v5 + 3);
      *((_OWORD *)v4 + 4) = *((_OWORD *)v5 + 4);
      *((_OWORD *)v4 + 5) = *((_OWORD *)v5 + 5);
      *((_OWORD *)v4 + 6) = *((_OWORD *)v5 + 6);
      v4 += 32;
      *((_OWORD *)v4 - 1) = *((_OWORD *)v5 + 7);
      v5 += 32;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 889
// RVA: 0x949850
void __fastcall Scaleform::Render::DICommand_PaletteMap::~DICommand_PaletteMap(Scaleform::Render::DICommand_PaletteMap *this)
{
  Scaleform::Render::DICommand_PaletteMap *v1; // rbx
  Scaleform::Render::DrawableImage *v2; // rcx
  Scaleform::Render::DrawableImage *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  if ( this->Channels )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v1->Channels = 0i64;
  v2 = v1->pSource.pObject;
  if ( v2 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v2->vfptr[2].__vecDelDtor)(v2);
  v1->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  v3 = v1->pImage.pObject;
  if ( v3 )
    ((void (*)(void))v3->vfptr[2].__vecDelDtor)();
}

// File Line: 898
// RVA: 0x98B0C0
bool __fastcall Scaleform::Render::DICommand_PaletteMap::GetRequireSourceRead(Scaleform::Render::DICommand_PaletteMap *this)
{
  return this->pImage.pObject == this->pSource.pObject;
}

// File Line: 925
// RVA: 0x93A900
void __fastcall Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(Scaleform::Render::DICommand_PerlinNoise *this, Scaleform::Render::DrawableImage *image, float frequencyX, float frequencyY, unsigned int octaves, unsigned int seed, bool stitch, bool fractal, unsigned int channels, bool grayScale, float *offsets, unsigned int offsetCount)
{
  Scaleform::Render::DrawableImage *v12; // rdi
  Scaleform::Render::DICommand_PerlinNoise *v13; // rbx
  unsigned int v14; // eax

  v12 = image;
  v13 = this;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( image )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))image->vfptr[1].__vecDelDtor)(image);
  v13->pImage.pObject = v12;
  v13->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_PerlinNoise,Scaleform::Render::DICommand>::`vftable;
  v13->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PerlinNoise::`vftable;
  v13->FrequencyX = frequencyX;
  v13->FrequencyY = frequencyY;
  v13->NumOctaves = octaves;
  v13->RandomSeed = seed;
  v13->Stitch = stitch;
  v13->FractalNoise = fractal;
  v13->ChannelMask = channels;
  v13->GrayScale = grayScale;
  v14 = 16;
  if ( offsetCount < 0x10 )
    v14 = offsetCount;
  v13->OffsetCount = v14;
  if ( offsetCount )
    memmove(v13->Offsets, offsets, 4i64 * offsetCount);
}

// File Line: 935
// RVA: 0x93A830
void __fastcall Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(Scaleform::Render::DICommand_PerlinNoise *this, Scaleform::Render::DICommand_PerlinNoise *other)
{
  Scaleform::Render::DICommand_PerlinNoise *v2; // rdi
  Scaleform::Render::DICommand_PerlinNoise *v3; // rbx
  Scaleform::Render::DrawableImage *v4; // rcx
  unsigned int v5; // eax
  size_t v6; // r8

  v2 = other;
  v3 = this;
  this->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  v4 = other->pImage.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
  v3->pImage.pObject = v2->pImage.pObject;
  v3->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_PerlinNoise,Scaleform::Render::DICommand>::`vftable;
  v3->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PerlinNoise::`vftable;
  v3->FrequencyX = v2->FrequencyX;
  v3->FrequencyY = v2->FrequencyY;
  v3->NumOctaves = v2->NumOctaves;
  v3->RandomSeed = v2->RandomSeed;
  v3->Stitch = v2->Stitch;
  v3->FractalNoise = v2->FractalNoise;
  v3->ChannelMask = v2->ChannelMask;
  v3->GrayScale = v2->GrayScale;
  v3->OffsetCount = v2->OffsetCount;
  v5 = v2->OffsetCount;
  if ( v5 )
  {
    v6 = 4i64 * v5;
    if ( v6 > 0x80 )
      v6 = 128i64;
    memmove(v3->Offsets, v2->Offsets, v6);
  }
}

// File Line: 967
// RVA: 0x98B820
signed __int64 __fastcall Scaleform::Render::DICommand_SourceRect::GetSourceImages(Scaleform::Render::DICommand_SourceRect *this, Scaleform::Render::DISourceImages *ps)
{
  ps->pImages[0] = (Scaleform::Render::Image *)&this->pSource.pObject->vfptr;
  return 1i64;
}

// File Line: 972
// RVA: 0x98E310
signed __int64 __fastcall Scaleform::Render::DICommand_PixelDissolve::GetType(SSInvokeCascade *this)
{
  return 21i64;
}

// File Line: 973
// RVA: 0x98E2F0
signed __int64 __fastcall Scaleform::Render::DICommand_PixelDissolve::GetCPUCaps(SSLoopExit *this)
{
  return 17i64;
}

// File Line: 1019
// RVA: 0x98E320
signed __int64 __fastcall SSInvokeClosureCoroutine::get_type(SSInvokeClosureCoroutine *this)
{
  return 23i64;
}

// File Line: 1036
// RVA: 0x93AAC0
void __fastcall Scaleform::Render::DICommand_Scroll::DICommand_Scroll(Scaleform::Render::DICommand_Scroll *this, Scaleform::Render::DrawableImage *image, int x, int y)
{
  int v4; // er15
  int v5; // ebp
  Scaleform::Render::DrawableImage *v6; // rsi
  Scaleform::Render::DICommand_Scroll *v7; // r14
  int v8; // edi
  int v9; // ebx
  char v10; // [rsp+28h] [rbp-30h]
  char v11; // [rsp+68h] [rbp+10h]

  v4 = y;
  v5 = x;
  v6 = image;
  v7 = this;
  v8 = *(_DWORD *)((__int64)image->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)image, (unsigned int)&v11) + 4);
  v9 = *(_DWORD *)v6->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)&v10);
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
  v7->pImage.pObject = v6;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
  v7->pSource.pObject = v6;
  *(_QWORD *)&v7->SourceRect.x1 = 0i64;
  v7->SourceRect.x2 = v9;
  v7->SourceRect.y2 = v8;
  v7->DestPoint.x = v5;
  v7->DestPoint.y = v4;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::`vftable;
  v7->vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Scroll::`vftable;
  v7->X = v5;
  v7->Y = v4;
}

// File Line: 1064
// RVA: 0x98B0D0
_BOOL8 __fastcall Scaleform::Render::DICommand_Threshold::GetRequireSourceRead(Scaleform::Render::DICommand_Threshold *this)
{
  return this->CopySource;
}

