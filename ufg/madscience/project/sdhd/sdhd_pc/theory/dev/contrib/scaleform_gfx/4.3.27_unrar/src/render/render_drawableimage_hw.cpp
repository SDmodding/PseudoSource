// File Line: 26
// RVA: 0x973010
void __fastcall Scaleform::Render::DICommand_CreateTexture::ExecuteHW(
        Scaleform::Render::DICommand_CreateTexture *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::TextureManager *v4; // rax

  v4 = (Scaleform::Render::TextureManager *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  Scaleform::Render::DrawableImage::createTextureFromManager(this->pImage.pObject, context->pHAL, v4);
}

// File Line: 35
// RVA: 0x972E70
void __fastcall Scaleform::Render::DICommand_Clear::ExecuteHW(
        Scaleform::Render::DICommand_Clear *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::HAL *pHAL; // rbx
  int v5; // eax
  unsigned int FillFlags; // edx
  unsigned int v7; // r10d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  int *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  Scaleform::Render::HAL *v12; // rcx
  Scaleform::Render::HAL *v13; // rbx
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // r10d
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  __int64 v18; // [rsp+20h] [rbp-18h] BYREF
  int v19; // [rsp+28h] [rbp-10h]
  int v20; // [rsp+2Ch] [rbp-Ch]
  unsigned int Raw; // [rsp+40h] [rbp+8h] BYREF
  char v22; // [rsp+48h] [rbp+10h] BYREF

  pHAL = context->pHAL;
  if ( pHAL->CurrentBlendState.Mode != Blend_OverwriteAll
    || !pHAL->CurrentBlendState.SourceAc
    || !pHAL->CurrentBlendState.ForceAc )
  {
    v5 = pHAL->Profiler.vfptr->GetBlendMode(&pHAL->Profiler, Blend_OverwriteAll);
    pHAL->FillFlags &= 0xFFFFFFFC;
    FillFlags = pHAL->FillFlags;
    v7 = v5;
    if ( (unsigned int)(v5 - 3) <= 1 )
    {
      pHAL->FillFlags = FillFlags | 1;
    }
    else if ( v5 == 10 )
    {
      pHAL->FillFlags = FillFlags | 2;
      pHAL->FillFlags |= 0x20u;
LABEL_11:
      pHAL->CurrentBlendState.Mode = v5;
      vfptr = pHAL->vfptr;
      *(_WORD *)&pHAL->CurrentBlendState.SourceAc = 257;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, __int64))vfptr[42].__vecDelDtor)(pHAL, v7, 1i64);
      goto LABEL_12;
    }
    if ( v5 <= 1 )
      pHAL->FillFlags &= ~0x20u;
    else
      pHAL->FillFlags |= 0x20u;
    goto LABEL_11;
  }
LABEL_12:
  v9 = (int *)this->pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Clear,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[5].__vecDelDtor(
                this->pImage.pObject,
                &v22);
  v10 = (float)v9[1];
  v11 = (float)*v9;
  v12 = context->pHAL;
  v18 = 0i64;
  v19 = (int)v11;
  v20 = (int)v10;
  Raw = this->FillColor.Raw;
  ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, unsigned int *, _QWORD))v12->vfptr[18].__vecDelDtor)(
    v12,
    &v18,
    &Raw,
    0i64);
  v13 = context->pHAL;
  if ( v13->CurrentBlendState.Mode || v13->CurrentBlendState.SourceAc || v13->CurrentBlendState.ForceAc )
  {
    v14 = v13->Profiler.vfptr->GetBlendMode(&v13->Profiler, Blend_None);
    v13->FillFlags &= 0xFFFFFFFC;
    v15 = v13->FillFlags;
    v16 = v14;
    if ( (unsigned int)(v14 - 3) <= 1 )
    {
      v13->FillFlags = v15 | 1;
    }
    else if ( v14 == 10 )
    {
      v13->FillFlags = v15 | 2;
      v13->FillFlags |= 0x20u;
LABEL_22:
      v13->CurrentBlendState.Mode = v14;
      v17 = v13->vfptr;
      *(_WORD *)&v13->CurrentBlendState.SourceAc = 0;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, _QWORD, _QWORD))v17[42].__vecDelDtor)(
        v13,
        v16,
        0i64,
        0i64);
      return;
    }
    if ( v14 <= 1 )
      v13->FillFlags &= ~0x20u;
    else
      v13->FillFlags |= 0x20u;
    goto LABEL_22;
  }
}

// File Line: 43
// RVA: 0x974120
void __fastcall Scaleform::Render::DICommand_ApplyFilter::ExecuteHWGetImages(
        Scaleform::Render::DICommand_ApplyFilter *this,
        Scaleform::Render::DrawableImage **images,
        Scaleform::Render::Size<float> *readOffsets)
{
  float y; // xmm1_4
  float y1; // xmm1_4

  *images = this->pImage.pObject;
  y = (float)this->DestPoint.y;
  readOffsets->Width = (float)this->DestPoint.x;
  readOffsets->Height = y;
  images[1] = this->pSource.pObject;
  y1 = (float)this->SourceRect.y1;
  readOffsets[1].Width = (float)this->SourceRect.x1;
  readOffsets[1].Height = y1;
}

// File Line: 55
// RVA: 0x973360
void __fastcall Scaleform::Render::DICommand_ApplyFilter::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_ApplyFilter *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  float y2; // xmm6_4
  float x2; // xmm7_4
  float y1; // xmm11_4
  float x1; // xmm12_4
  float v12; // xmm8_4
  float v13; // xmm9_4
  Scaleform::Render::Filter *pObject; // rdx
  Scaleform::Render::CacheablePrimitive *v15; // rax
  __int64 v16; // rdi
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v17; // rcx
  double v18; // xmm0_8
  float v19; // xmm6_4
  float v20; // xmm7_4
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::CacheAsBitmapFilter *v24; // rcx
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-90h] BYREF
  Scaleform::Render::FilterSet v26; // [rsp+40h] [rbp-80h] BYREF
  float v27; // [rsp+78h] [rbp-48h]
  float v28; // [rsp+7Ch] [rbp-44h]
  float v29; // [rsp+80h] [rbp-40h]
  float v30; // [rsp+84h] [rbp-3Ch]
  float v31; // [rsp+88h] [rbp-38h]
  float v32; // [rsp+8Ch] [rbp-34h]
  __int64 v33; // [rsp+90h] [rbp-30h]
  __int64 v34; // [rsp+98h] [rbp-28h]
  float v35; // [rsp+B0h] [rbp-10h]
  float v36; // [rsp+B4h] [rbp-Ch]
  float v37; // [rsp+BCh] [rbp-4h]
  float v38; // [rsp+D4h] [rbp+14h]
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+1A0h] [rbp+E0h] BYREF
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v40; // [rsp+1A8h] [rbp+E8h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *p_Filters; // [rsp+1B0h] [rbp+F0h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v42; // [rsp+1B8h] [rbp+F8h]

  v34 = -2i64;
  v26.Scaleform::RefCountBase<Scaleform::Render::FilterSet,2> = (Scaleform::RefCountBase<Scaleform::Render::FilterSet,2>)_xmm;
  *(__m128 *)&v26.Filters.Data.Data = _xmm;
  y2 = (float)this->SourceRect.y2;
  x2 = (float)this->SourceRect.x2;
  y1 = (float)this->SourceRect.y1;
  x1 = (float)this->SourceRect.x1;
  bounds.x1 = (float)(int)(float)(x1 * 20.0);
  bounds.y1 = (float)(int)(float)(y1 * 20.0);
  bounds.x2 = (float)(int)(float)(x2 * 20.0);
  bounds.y2 = (float)(int)(float)(y2 * 20.0);
  Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(this->pFilter.pObject, &bounds);
  v29 = bounds.x1 * 0.050000001;
  v30 = bounds.y1 * 0.050000001;
  v31 = bounds.x2 * 0.050000001;
  v32 = bounds.y2 * 0.050000001;
  v12 = (float)(bounds.y2 * 0.050000001) - (float)(bounds.y1 * 0.050000001);
  v13 = (float)(bounds.x2 * 0.050000001) - (float)(bounds.x1 * 0.050000001);
  *(float *)&v40 = v13;
  *((float *)&v40 + 1) = v12;
  *(float *)&v26.Filters.Data.Policy.Capacity = v13;
  *((float *)&v26.Filters.Data.Policy.Capacity + 1) = v13 * 0.0;
  *(float *)&v26.Frozen = v13 * 0.0;
  *(float *)&v26.pCacheAsBitmapFilter.pObject = v12 * 0.0;
  *((float *)&v26.pCacheAsBitmapFilter.pObject + 1) = v12;
  v27 = v12 * 0.0;
  *(float *)(&v26.CacheAsBitmap + 3) = (float)(v13 * 0.0) + (float)(bounds.x1 * 0.050000001);
  v28 = (float)(v12 * 0.0) + (float)(bounds.y1 * 0.050000001);
  pObject = this->pFilter.pObject;
  v26.RefCount = 1;
  v26.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable;
  p_Filters = &v26.Filters;
  v42 = &v26.Filters;
  memset(&v26.Filters, 0, 26);
  v26.pCacheAsBitmapFilter.pObject = 0i64;
  if ( pObject )
    Scaleform::Render::FilterSet::AddFilter(&v26, pObject);
  v15 = (Scaleform::Render::CacheablePrimitive *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   88i64);
  v16 = (__int64)v15;
  p_Filters = (Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *)v15;
  if ( v15 )
  {
    Scaleform::Render::CacheablePrimitive::CacheablePrimitive(v15, 0);
    *(_QWORD *)v16 = &Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
    *(_QWORD *)(v16 + 16) = &Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
    _InterlockedExchangeAdd(&v26.RefCount, 1u);
    *(_QWORD *)(v16 + 80) = &v26;
  }
  else
  {
    v16 = 0i64;
  }
  v33 = v16;
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
    &context->pR2D->pImpl->MPool,
    &result,
    (Scaleform::Render::Matrix2x4<float> *)&v26.Filters.Data.Policy,
    0);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(
    &result,
    (Scaleform::Render::Matrix2x4<float> *)&v26.Filters.Data.Policy);
  Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> *)(v16 + 48),
    *(_QWORD *)(v16 + 56) + 1i64);
  if ( *(_QWORD *)(v16 + 56) != 1i64 )
    memmove((void *)(*(_QWORD *)(v16 + 48) + 8i64), *(const void **)(v16 + 48), 8 * (*(_QWORD *)(v16 + 56) - 1i64));
  v17 = *(Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> **)(v16 + 48);
  p_Filters = v17;
  v42 = v17;
  if ( v17 )
  {
    v17->Data.Data = (Scaleform::Ptr<Scaleform::Render::Filter> *)result.pHandle;
    if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      ++result.pHandle->pHeader->RefCount;
  }
  context->pHAL->vfptr[47].__vecDelDtor(context->pHAL, v16);
  v18 = ((double (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[71].__vecDelDtor)(context->pHAL);
  v38 = *(float *)&v18 * 2.0;
  v35 = (float)(*(float *)&v18 * 2.0) * 0.0;
  v36 = *(float *)&v18 * 2.0;
  v37 = (float)(*(float *)&v18 * 2.0) * -0.5;
  v19 = (float)(y2 - y1) / v12;
  v20 = (float)(x2 - x1) / v13;
  *(float *)&v26.vfptr = v20 * 2.0;
  *((float *)&v26.vfptr + 1) = v20 * 0.0;
  *(float *)&v26.RefCount = v20 * 0.0;
  *((float *)&v26.RefCount + 1) = v20 * -1.0;
  *(float *)&v26.Filters.Data.Data = v19 * v35;
  *((float *)&v26.Filters.Data.Data + 1) = v19 * (float)(*(float *)&v18 * 2.0);
  *(float *)&v26.Filters.Data.Size = v19 * 0.0;
  *((float *)&v26.Filters.Data.Size + 1) = v19 * v37;
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture *, Scaleform::Render::FilterSet *, Scaleform::Render::Matrix2x4<float> *, int))context->pHAL->vfptr[58].__vecDelDtor)(
    context->pHAL,
    tex[1],
    &v26,
    &texgen[1],
    -1);
  ((void (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[48].__vecDelDtor)(context->pHAL);
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    pHeader = result.pHandle->pHeader;
    if ( result.pHandle->pHeader->RefCount-- == 1 )
    {
      DataPageOffset = pHeader->DataPageOffset;
      *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0i64;
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v16 + 8)) )
    (**(void (__fastcall ***)(__int64, __int64))v16)(v16, 1i64);
  v26.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable;
  v24 = v26.pCacheAsBitmapFilter.pObject;
  if ( v26.pCacheAsBitmapFilter.pObject && !_InterlockedDecrement(&v26.pCacheAsBitmapFilter.pObject->RefCount) && v24 )
    v24->vfptr->__vecDelDtor(v24, 1u);
  v40 = &v26.Filters;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>(&v26.Filters.Data);
}

// File Line: 86
// RVA: 0x973880
void __fastcall Scaleform::Render::DICommand_ColorTransform::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_ColorTransform *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DrawableImage *pObject; // rax
  __int128 v9; // xmm1
  __int128 v10; // [rsp+20h] [rbp-28h] BYREF
  __int128 v11; // [rsp+30h] [rbp-18h]

  Scaleform::Render::HAL::applyBlendMode(
    context->pHAL,
    (Scaleform::Render::BlendMode)(this->pImage.pObject->Transparent + 15),
    1,
    1);
  pObject = this->pImage.pObject;
  v9 = *(_OWORD *)&this->Cx.M[1][0];
  v10 = *(_OWORD *)&this->Cx.M[0][0];
  v11 = v9;
  if ( !pObject->Transparent )
  {
    *(float *)&v10 = *(float *)&v10 * (float)(*((float *)&v11 + 3) + *((float *)&v10 + 3));
    *(float *)&v11 = *(float *)&v11 * (float)(*((float *)&v11 + 3) + *((float *)&v10 + 3));
    *((float *)&v10 + 1) = *((float *)&v10 + 1) * (float)(*((float *)&v11 + 3) + *((float *)&v10 + 3));
    *((float *)&v11 + 1) = *((float *)&v11 + 1) * (float)(*((float *)&v11 + 3) + *((float *)&v10 + 3));
    *((float *)&v10 + 2) = *((float *)&v10 + 2) * (float)(*((float *)&v11 + 3) + *((float *)&v10 + 3));
    *((float *)&v11 + 2) = *((float *)&v11 + 2) * (float)(*((float *)&v11 + 3) + *((float *)&v10 + 3));
    HIDWORD(v10) = (_DWORD)FLOAT_1_0;
    HIDWORD(v11) = 0;
  }
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, __int128 *))context->pHAL->vfptr[52].__vecDelDtor)(
    context->pHAL,
    tex + 1,
    &texgen[1],
    &v10);
}

// File Line: 109
// RVA: 0x973050
void __fastcall Scaleform::Render::DICommand_Draw::ExecuteHW(
        Scaleform::Render::DICommand_Draw *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DrawableImageContext *pObject; // r14
  Scaleform::Render::HAL *pHAL; // rbx
  char v6; // bp
  bool v7; // zf
  Scaleform::Render::HAL *v8; // rbx
  int v9; // eax
  unsigned int FillFlags; // edx
  unsigned int v11; // r10d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::HAL *v13; // rcx
  __int64 v14[2]; // [rsp+20h] [rbp-58h] BYREF
  Scaleform::Render::Viewport vpin; // [rsp+30h] [rbp-48h] BYREF
  Scaleform::Render::Color backgroundColor; // [rsp+80h] [rbp+8h] BYREF

  pObject = this->pImage.pObject->pContext.pObject;
  pObject->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor(
    pObject,
    (unsigned int)context->pR2D->pImpl);
  pHAL = context->pHAL;
  v6 = 0;
  v7 = (pHAL->HALState & 8) == 0;
  vpin = pHAL->VP;
  if ( !v7 )
  {
    v6 = 1;
    if ( (pHAL->HALState & 0x400) != 0 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))pHAL->vfptr[8].__vecDelDtor)(pHAL);
      ((void (__fastcall *)(Scaleform::Render::HAL *))pHAL->vfptr[12].__vecDelDtor)(pHAL);
    }
    else
    {
      v14[1] = 0i64;
      v14[0] = (__int64)&Scaleform::Render::HALEndDisplayItem::Instance;
      pHAL->vfptr[33].__vecDelDtor(pHAL, (unsigned int)v14);
    }
  }
  ((void (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[8].__vecDelDtor)(context->pHAL);
  context->pHAL->vfptr[30].__vecDelDtor(context->pHAL, 3u);
  v8 = context->pHAL;
  if ( v8->CurrentBlendState.Mode != Blend_Normal || !v8->CurrentBlendState.SourceAc || !v8->CurrentBlendState.ForceAc )
  {
    v9 = v8->Profiler.vfptr->GetBlendMode(&v8->Profiler, Blend_Normal);
    v8->FillFlags &= 0xFFFFFFFC;
    FillFlags = v8->FillFlags;
    v11 = v9;
    if ( (unsigned int)(v9 - 3) <= 1 )
    {
      v8->FillFlags = FillFlags | 1;
    }
    else if ( v9 == 10 )
    {
      v8->FillFlags = FillFlags | 2;
      v8->FillFlags |= 0x20u;
LABEL_15:
      v8->CurrentBlendState.Mode = v9;
      vfptr = v8->vfptr;
      *(_WORD *)&v8->CurrentBlendState.SourceAc = 257;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, __int64))vfptr[42].__vecDelDtor)(v8, v11, 1i64);
      goto LABEL_16;
    }
    if ( v9 <= 1 )
      v8->FillFlags &= ~0x20u;
    else
      v8->FillFlags |= 0x20u;
    goto LABEL_15;
  }
LABEL_16:
  Scaleform::Render::Renderer2DImpl::Draw(context->pR2D->pImpl, this->pRoot);
  ((void (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[8].__vecDelDtor)(context->pHAL);
  if ( v6 )
  {
    v13 = context->pHAL;
    backgroundColor = 0;
    Scaleform::Render::HAL::BeginDisplay(v13, (int *)&backgroundColor.Raw, &vpin);
  }
  Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(pObject, (Scaleform::GFx::AS2::Object *)this->pRoot);
}

// File Line: 144
// RVA: 0x972760
void __fastcall Scaleform::Render::DICommand_Draw::ExecuteDiscard(Scaleform::Render::DICommand_Draw *this)
{
  Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(
    this->pImage.pObject->pContext.pObject,
    (Scaleform::GFx::AS2::Object *)this->pRoot);
}

// File Line: 153
// RVA: 0x972780
void __fastcall Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_CopyPixels>::ExecuteHW(
        Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *this,
        Scaleform::Render::DICommandContext *context)
{
  __int64 v3; // r15
  unsigned __int64 v4; // rsi
  __int64 v5; // rbx
  __int64 v6; // r13
  __int64 v7; // rdi
  unsigned __int64 v8; // rcx
  __int64 v9; // rax
  unsigned __int64 v10; // rcx
  __int64 v11; // rax
  int v12; // r15d
  int v13; // r12d
  Scaleform::Render::DrawableImage *pObject; // rbx
  int *v15; // rdi
  unsigned int *v16; // rax
  __int64 y1; // rdx
  int x1; // ecx
  int v19; // r10d
  int v20; // r11d
  int v21; // r9d
  __int64 v22; // r8
  int y2; // ebx
  int x2; // eax
  int v25; // ebx
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  __int64 v29; // rdi
  __int64 v30; // rbx
  unsigned int v31; // eax
  int *v32; // rbx
  int v33; // edi
  int v34; // edx
  unsigned int v35; // ecx
  unsigned int v36; // ecx
  float *v37; // r8
  int v38; // r14d
  __int64 v39; // rdx
  float v40; // xmm5_4
  float v41; // xmm4_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  float v44; // xmm0_4
  float v45; // xmm3_4
  __int64 v46; // rsi
  float v47; // xmm2_4
  float v48; // xmm7_4
  float v49; // xmm2_4
  __m128 v50; // xmm0
  float v51; // xmm3_4
  __m128 v52; // xmm4
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __int64 *v55; // rdi
  __int64 v56; // rsi
  __int64 v57; // rax
  int v58; // [rsp+30h] [rbp-90h] BYREF
  int v59; // [rsp+34h] [rbp-8Ch]
  __m128 v60; // [rsp+40h] [rbp-80h] BYREF
  __m128 v61; // [rsp+50h] [rbp-70h] BYREF
  __int64 v62[2]; // [rsp+60h] [rbp-60h] BYREF
  __m128 v63; // [rsp+70h] [rbp-50h] BYREF
  __int64 v64; // [rsp+88h] [rbp-38h]
  __int64 v65[3]; // [rsp+90h] [rbp-30h] BYREF
  __int64 v66[3]; // [rsp+A8h] [rbp-18h]
  __int128 v67[13]; // [rsp+C0h] [rbp+0h] BYREF
  __int64 v68; // [rsp+1A0h] [rbp+E0h]
  __int64 v69; // [rsp+1A8h] [rbp+E8h]
  __int64 *v70; // [rsp+1B0h] [rbp+F0h]
  char v71[24]; // [rsp+1B8h] [rbp+F8h] BYREF

  v64 = -2i64;
  v3 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[61].__vecDelDtor)(context->pHAL);
  v70 = (__int64 *)v3;
  v61.m128_u64[1] = 0i64;
  v62[0] = 0i64;
  v62[1] = 0i64;
  ((void (__fastcall *)(Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *, unsigned __int16 *, __m128 *))this->vfptr[1].__vecDelDtor)(
    this,
    &v61.m128_u16[4],
    &v63);
  v4 = 0i64;
  v5 = 0i64;
  v6 = 3i64;
  v7 = 3i64;
  do
  {
    v8 = v61.m128_u64[v5 + 1];
    if ( v8 )
      v9 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v8 + 208i64))(v8);
    else
      v9 = 0i64;
    v66[v5] = v9;
    v10 = v61.m128_u64[v5 + 1];
    if ( v10 )
      v11 = (*(__int64 (__fastcall **)(unsigned __int64, __int64))(*(_QWORD *)v10 + 168i64))(v10, v3);
    else
      v11 = 0i64;
    v65[v5++] = v11;
    --v7;
  }
  while ( v7 );
  v58 = 0;
  v59 = 0;
  v12 = 0;
  v13 = 0;
  pObject = this->pSource.pObject;
  v15 = (int *)this->pImage.pObject->Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[5].__vecDelDtor(
                 this->pImage.pObject,
                 v71);
  v16 = (unsigned int *)pObject->vfptr[5].__vecDelDtor(pObject, (unsigned int)&v61);
  y1 = (unsigned int)this->SourceRect.y1;
  x1 = this->SourceRect.x1;
  v19 = this->DestPoint.y - y1;
  v20 = this->DestPoint.x - x1;
  v21 = v16[1];
  v22 = *v16;
  if ( v21 >= (int)y1 )
  {
    y2 = this->SourceRect.y2;
    if ( y2 >= 0 )
    {
      x2 = this->SourceRect.x2;
      if ( x2 >= 0 && (int)v22 >= x1 )
      {
        if ( x1 < 0 )
          x1 = 0;
        if ( (int)v22 > x2 )
          LODWORD(v22) = this->SourceRect.x2;
        if ( (int)y1 < 0 )
          LODWORD(y1) = 0;
        if ( v21 > y2 )
          v21 = this->SourceRect.y2;
        v25 = x1 + v20;
        v26 = v22 + v20;
        v22 = (unsigned int)(v19 + y1);
        y1 = (unsigned int)(v19 + v21);
        if ( (int)y1 >= 0 && v15[1] >= (int)v22 && *v15 >= v25 && v26 >= 0 )
        {
          v27 = 0;
          if ( v25 > 0 )
            v27 = v25;
          v58 = v27;
          v12 = v26;
          if ( v26 > *v15 )
            v12 = *v15;
          v28 = 0;
          if ( (int)v22 > 0 )
            v28 = v22;
          v59 = v28;
          v13 = v19 + v21;
          if ( (int)y1 > v15[1] )
            v13 = v15[1];
        }
      }
    }
  }
  v29 = (__int64)v70;
  v30 = *v70;
  v31 = (*(__int64 (__fastcall **)(__int64 *, __int64, __int64))(*v70 + 104))(v70, y1, v22);
  LOBYTE(v70) = (*(unsigned __int8 (__fastcall **)(__int64, _QWORD, __int64))(v30 + 32))(v29, v31, 1152i64) == 0;
  v71[0] = this->vfptr[1].GetCPUCaps(this);
  v32 = 0i64;
  v61.m128_u64[0] = 0i64;
  v33 = v58;
  if ( v71[0] )
  {
    LODWORD(v62[0]) = v12 - v58;
    HIDWORD(v62[0]) = v13 - v59;
    if ( (_BYTE)v70 )
    {
      v35 = ((((unsigned int)(v12 - v58 - 1) >> 1) | (v12 - v58 - 1)) >> 2) | ((unsigned int)(v12 - v58 - 1) >> 1) | (v12 - v58 - 1);
      v36 = (((v35 >> 4) | v35) >> 8) | (v35 >> 4) | v35;
      LODWORD(v62[0]) = (v36 | HIWORD(v36)) + 1;
      v34 = v13 - v59;
      HIDWORD(v62[0]) = (((((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 8) | ((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1) | ((((((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 8) | ((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 16))
                      + 1;
    }
    v32 = (int *)(*(__int64 (__fastcall **)(_QWORD, __int64 *, _QWORD))(**(_QWORD **)(v69 + 8) + 176i64))(
                   *(_QWORD *)(v69 + 8),
                   v62,
                   0i64);
    v61.m128_u64[0] = (unsigned __int64)v32;
    v58 = 0;
    v60.m128_u64[0] = 0i64;
    v60.m128_f32[2] = (float)SLODWORD(v62[0]);
    v60.m128_f32[3] = (float)SHIDWORD(v62[0]);
    (*(void (__fastcall **)(_QWORD, __m128 *, int *, __int64, int *))(**(_QWORD **)(v69 + 8) + 192i64))(
      *(_QWORD *)(v69 + 8),
      &v60,
      v32,
      2i64,
      &v58);
  }
  v67[0] = _xmm;
  v67[1] = (__int128)_xmm;
  v67[2] = _xmm;
  v67[3] = (__int128)_xmm;
  v67[4] = _xmm;
  v67[5] = (__int128)_xmm;
  v37 = (float *)v67 + 2;
  v38 = v59;
  do
  {
    v39 = v65[v4 / 2];
    if ( v39 )
    {
      v40 = (float)(v13 - v38) / (float)*(int *)(v39 + 52);
      v41 = (float)(v12 - v33) / (float)*(int *)(v39 + 48);
      *(v37 - 2) = v41 * *(v37 - 2);
      *(v37 - 1) = v41 * *(v37 - 1);
      *v37 = v41 * *v37;
      v42 = v41 * v37[1];
      v37[1] = v42;
      v37[2] = v40 * v37[2];
      v37[3] = v40 * v37[3];
      v37[4] = v40 * v37[4];
      v43 = v40 * v37[5];
      v37[5] = v43;
      v44 = (float)*(int *)(v39 + 52);
      v45 = v63.m128_f32[v4 + 1];
      v37[1] = v42 + (float)(v63.m128_f32[v4] / (float)*(int *)(v39 + 48));
      v37[5] = (float)(v45 / v44) + v43;
    }
    v4 += 2i64;
    v37 += 8;
    --v6;
  }
  while ( v6 );
  v46 = v69;
  (*(void (__fastcall **)(__int64, __int64, __int64 *, __int128 *))(*(_QWORD *)v68 + 80i64))(v68, v69, v65, v67);
  if ( v71[0] )
  {
    (*(void (__fastcall **)(_QWORD, __int64))(**(_QWORD **)(v46 + 8) + 200i64))(*(_QWORD *)(v46 + 8), 2i64);
    v61 = _xmm;
    v63 = (__m128)_xmm;
    v60 = _xmm;
    v47 = (float)(v13 - v59);
    v48 = (float)(v12 - v33);
    if ( (_BYTE)v70 )
    {
      v48 = (float)(int)((((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2)) >> 4) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2)) >> 4)) >> 8)) >> 16) | ((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2)) >> 4) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1) | ((((int)v48 - 1) | ((unsigned int)((int)v48 - 1) >> 1)) >> 2)) >> 4)) >> 8))
                       + 1);
      v47 = (float)(int)((((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2)) >> 4) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2)) >> 4)) >> 8)) >> 16) | ((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2)) >> 4) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1) | ((((int)v47 - 1) | ((unsigned int)((int)v47 - 1) >> 1)) >> 2)) >> 4)) >> 8))
                       + 1);
    }
    v49 = v47 / (float)(*(_DWORD *)(v66[0] + 60) - *(_DWORD *)(v66[0] + 52));
    v60.m128_f32[0] = v48 / (float)(*(_DWORD *)(v66[0] + 56) - *(_DWORD *)(v66[0] + 48));
    v60.m128_f32[1] = v60.m128_f32[0] * 0.0;
    v60.m128_f32[2] = v60.m128_f32[0] * 0.0;
    v60.m128_f32[3] = v60.m128_f32[0] * 0.0;
    v61.m128_f32[0] = v49 * 0.0;
    v61.m128_f32[1] = v49;
    v61.m128_f32[2] = v49 * 0.0;
    v61.m128_f32[3] = v49 * 0.0;
    v50 = (__m128)v63.m128_u32[0];
    v51 = (float)(v63.m128_f32[1] - (float)((float)(*(_DWORD *)(v66[0] + 60) - *(_DWORD *)(v66[0] + 52)) * 0.5))
        / (float)(*(_DWORD *)(v66[0] + 60) - *(_DWORD *)(v66[0] + 52));
    v60.m128_f32[3] = (float)(v60.m128_f32[0] * 0.0)
                    + (float)((float)(v63.m128_f32[0]
                                    - (float)((float)(*(_DWORD *)(v66[0] + 56) - *(_DWORD *)(v66[0] + 48)) * 0.5))
                            / (float)(*(_DWORD *)(v66[0] + 56) - *(_DWORD *)(v66[0] + 48)));
    v61.m128_f32[3] = (float)(v49 * 0.0) + v51;
    *(double *)v50.m128_u64 = (*(double (__fastcall **)(_QWORD))(**(_QWORD **)(v46 + 8) + 568i64))(*(_QWORD *)(v46 + 8));
    v52 = v50;
    v52.m128_f32[0] = v50.m128_f32[0] * 2.0;
    v60 = _mm_mul_ps(v60, (__m128)_xmm);
    v61 = _mm_mul_ps(v61, _mm_shuffle_ps(v52, v52, 0));
    v53 = 0i64;
    v54 = 0i64;
    v53.m128_f32[0] = (float)(v32[15] - v32[13]) / (float)v32[11];
    v54.m128_f32[0] = (float)(v32[14] - v32[12]) / (float)v32[10];
    v63 = _mm_mul_ps(v63, _mm_shuffle_ps(v54, v54, 0));
    v60 = _mm_mul_ps(v60, _mm_shuffle_ps(v53, v53, 0));
    v55 = *(__int64 **)(v46 + 8);
    v56 = *v55;
    v57 = (*(__int64 (__fastcall **)(int *))(*(_QWORD *)v32 + 24i64))(v32);
    (*(void (__fastcall **)(__int64 *, __int64, __m128 *, __m128 *, int))(v56 + 464))(v55, v57, &v60, &v63, -1);
    (*(void (__fastcall **)(int *, _QWORD))(*(_QWORD *)v32 + 40i64))(v32, 0i64);
  }
  if ( v32 )
    (*(void (__fastcall **)(int *))(*(_QWORD *)v32 + 16i64))(v32);
}
    (*(void (__fastcall **)(__int64 *, __int64, __m128 *, __m128 *, int))(v56 + 464))(v55, v57, &v60, &v63, -1);
    (*(void (__fastcall **)(int *, _QWORD))(*(_QWORD *)v32 + 40i64))(v32, 0i64);
  }
  if ( v32 )
    (*(void

// File Line: 245
// RVA: 0x973A20
void __fastcall Scaleform::Render::DICommand_CopyChannel::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_CopyChannel *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  int v8; // esi
  char *v9; // rdi
  int v10; // ebx
  char v11; // bp
  int v12; // edx
  int v13; // edi
  __int64 v14; // rsi
  int v15[10]; // [rsp+20h] [rbp-A8h] BYREF
  char v16; // [rsp+48h] [rbp-80h] BYREF
  int Dst[16]; // [rsp+60h] [rbp-68h] BYREF

  v8 = 1;
  v9 = &v16;
  do
  {
    memset(v9 - 40, 0, 0x40ui64);
    --v8;
    *((_DWORD *)v9 - 10) = 1065353216;
    *((_DWORD *)v9 - 5) = 1065353216;
    *(_DWORD *)v9 = 1065353216;
    *((_DWORD *)v9 + 5) = 1065353216;
    v9 += 64;
  }
  while ( v8 >= 0 );
  v10 = 0;
  v11 = 1;
  v12 = 0;
  v13 = 0;
  if ( this->DestChannel != Channel_Red )
  {
    switch ( this->DestChannel )
    {
      case Channel_Green:
        v12 = 1;
        break;
      case Channel_Blue:
        v12 = 2;
        break;
      case Channel_Alpha:
        v12 = 3;
        break;
      default:
        v11 = 0;
        break;
    }
  }
  if ( this->SourceChannel != Channel_Red )
  {
    switch ( this->SourceChannel )
    {
      case Channel_Green:
        v13 = 1;
        break;
      case Channel_Blue:
        v13 = 2;
        break;
      case Channel_Alpha:
        v13 = 3;
        break;
      default:
        v11 = 0;
        break;
    }
  }
  v14 = v12;
  v15[5 * v12] = 0;
  memset(Dst, 0, sizeof(Dst));
  if ( v11 )
    Dst[4 * v14 + v13] = 1065353216;
  LOBYTE(v10) = this->pImage.pObject->Transparent;
  Scaleform::Render::HAL::applyBlendMode(context->pHAL, (Scaleform::Render::BlendMode)(v10 + 15), 1, 1);
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, int *))context->pHAL->vfptr[54].__vecDelDtor)(
    context->pHAL,
    tex,
    texgen,
    v15);
}

// File Line: 289
// RVA: 0x974170
void __fastcall Scaleform::Render::DICommand_CopyPixels::ExecuteHWGetImages(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DrawableImage **images,
        Scaleform::Render::Size<float> *readOffsets)
{
  float x; // xmm0_4
  __m128i v4; // xmm1

  *images = this->pImage.pObject;
  x = (float)this->DestPoint.x;
  readOffsets->Height = (float)this->DestPoint.y;
  readOffsets->Width = x;
  images[1] = this->pSource.pObject;
  v4 = _mm_cvtsi32_si128(this->SourceRect.y1);
  readOffsets[1].Width = (float)this->SourceRect.x1;
  LODWORD(readOffsets[1].Height) = _mm_cvtepi32_ps(v4).m128_u32[0];
  images[2] = this->pAlphaSource.pObject;
  *(float *)v4.m128i_i32 = (float)this->AlphaPoint.y;
  readOffsets[2].Width = (float)this->AlphaPoint.x;
  LODWORD(readOffsets[2].Height) = v4.m128i_i32[0];
}

// File Line: 300
// RVA: 0x973B80
void __fastcall Scaleform::Render::DICommand_CopyPixels::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DrawableImage *pObject; // rax
  Scaleform::Render::HAL *pHAL; // rcx
  bool MergeAlpha; // [rsp+20h] [rbp-38h]
  bool Transparent; // [rsp+28h] [rbp-30h]
  __int128 v12[2]; // [rsp+30h] [rbp-28h] BYREF

  pObject = this->pImage.pObject;
  pHAL = context->pHAL;
  v12[0] = _xmm_bf800000000000000000000040000000;
  v12[1] = _xmm;
  Scaleform::Render::HAL::applyBlendMode(pHAL, (Scaleform::Render::BlendMode)(pObject->Transparent + 15), 1, 1);
  Transparent = this->pImage.pObject->Transparent;
  MergeAlpha = this->MergeAlpha;
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, __int128 *, bool, bool))context->pHAL->vfptr[56].__vecDelDtor)(
    context->pHAL,
    tex,
    texgen,
    v12,
    MergeAlpha,
    Transparent);
}

// File Line: 308
// RVA: 0x973250
void __fastcall Scaleform::Render::DICommand_FillRect::ExecuteHW(
        Scaleform::Render::DICommand_FillRect *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::HAL *pHAL; // rbx
  int v5; // eax
  unsigned int FillFlags; // edx
  unsigned int v7; // r10d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  char v9; // cl
  bool v10; // zf
  int x2; // eax
  Scaleform::Render::HAL *v12; // rcx
  int v13[6]; // [rsp+20h] [rbp-18h] BYREF
  unsigned int Raw; // [rsp+40h] [rbp+8h] BYREF

  pHAL = context->pHAL;
  if ( pHAL->CurrentBlendState.Mode != Blend_OverwriteAll
    || !pHAL->CurrentBlendState.SourceAc
    || !pHAL->CurrentBlendState.ForceAc )
  {
    v5 = pHAL->Profiler.vfptr->GetBlendMode(&pHAL->Profiler, Blend_OverwriteAll);
    pHAL->FillFlags &= 0xFFFFFFFC;
    FillFlags = pHAL->FillFlags;
    v7 = v5;
    if ( (unsigned int)(v5 - 3) <= 1 )
    {
      pHAL->FillFlags = FillFlags | 1;
    }
    else if ( v5 == 10 )
    {
      pHAL->FillFlags = FillFlags | 2;
      pHAL->FillFlags |= 0x20u;
LABEL_11:
      pHAL->CurrentBlendState.Mode = v5;
      vfptr = pHAL->vfptr;
      *(_WORD *)&pHAL->CurrentBlendState.SourceAc = 257;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, __int64))vfptr[42].__vecDelDtor)(pHAL, v7, 1i64);
      goto LABEL_12;
    }
    if ( v5 <= 1 )
      pHAL->FillFlags &= ~0x20u;
    else
      pHAL->FillFlags |= 0x20u;
    goto LABEL_11;
  }
LABEL_12:
  Raw = this->FillColor.Raw;
  v9 = HIBYTE(Raw);
  v10 = !this->pImage.pObject->Transparent;
  v13[0] = this->ApplyRect.x1;
  if ( v10 )
    v9 = -1;
  v13[1] = this->ApplyRect.y1;
  x2 = this->ApplyRect.x2;
  HIBYTE(Raw) = v9;
  v12 = context->pHAL;
  v13[2] = x2;
  v13[3] = this->ApplyRect.y2;
  ((void (__fastcall *)(Scaleform::Render::HAL *, int *, unsigned int *, _QWORD))v12->vfptr[18].__vecDelDtor)(
    v12,
    v13,
    &Raw,
    0i64);
}

// File Line: 321
// RVA: 0x9739A0
void __fastcall Scaleform::Render::DICommand_Compare::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  __int64 v8; // rax
  __int64 v9; // rax

  v8 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))this->pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Compare>::Scaleform::Render::DICommand_SourceRect::vfptr[26].__vecDelDtor)(this->pSource.pObject);
  *tex = (Scaleform::Render::Texture *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 24i64))(v8);
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))this->pImageCompare1.pObject->vfptr[26].__vecDelDtor)(this->pImageCompare1.pObject);
  tex[1] = (Scaleform::Render::Texture *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *))context->pHAL->vfptr[53].__vecDelDtor)(
    context->pHAL,
    tex,
    texgen);
}

// File Line: 331
// RVA: 0x973C20
void __fastcall Scaleform::Render::DICommand_Merge::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_Merge *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  int v8; // esi
  int *v9; // rdi
  Scaleform::Render::HAL *pHAL; // rcx
  signed int AlphaMultiplier; // edx
  signed int RedMultiplier; // eax
  float v13; // xmm1_4
  signed int GreenMultiplier; // eax
  float v15; // xmm5_4
  signed int BlueMultiplier; // eax
  float v17; // xmm1_4
  int v18; // xmm4_4
  Scaleform::Render::DrawableImage *pObject; // rax
  int v20[10]; // [rsp+20h] [rbp-98h] BYREF
  int v21[21]; // [rsp+48h] [rbp-70h] BYREF
  float v22; // [rsp+9Ch] [rbp-1Ch]

  v8 = 1;
  v9 = v21;
  do
  {
    memset(v9 - 10, 0, 0x40ui64);
    --v8;
    *(v9 - 10) = 1065353216;
    *(v9 - 5) = 1065353216;
    *v9 = 1065353216;
    v9[5] = 1065353216;
    v9 += 16;
  }
  while ( v8 >= 0 );
  pHAL = context->pHAL;
  AlphaMultiplier = 256;
  RedMultiplier = 256;
  if ( this->RedMultiplier < 0x100 )
    RedMultiplier = this->RedMultiplier;
  v13 = (float)RedMultiplier;
  GreenMultiplier = 256;
  if ( this->GreenMultiplier < 0x100 )
    GreenMultiplier = this->GreenMultiplier;
  v15 = (float)GreenMultiplier;
  BlueMultiplier = 256;
  if ( this->BlueMultiplier < 0x100 )
    BlueMultiplier = this->BlueMultiplier;
  v17 = v13 * 0.00390625;
  if ( this->AlphaMultiplier < 0x100 )
    AlphaMultiplier = this->AlphaMultiplier;
  *(float *)&v21[6] = v17;
  *(float *)&v21[11] = v15 * 0.00390625;
  *(float *)&v18 = (float)BlueMultiplier * 0.00390625;
  pObject = this->pImage.pObject;
  v21[16] = v18;
  v22 = (float)AlphaMultiplier * 0.00390625;
  *(float *)v20 = 1.0 - v17;
  *(float *)&v20[5] = 1.0 - (float)(v15 * 0.00390625);
  *(float *)v21 = 1.0 - *(float *)&v18;
  *(float *)&v21[5] = 1.0 - v22;
  Scaleform::Render::HAL::applyBlendMode(pHAL, (Scaleform::Render::BlendMode)(pObject->Transparent + 15), 1, 1);
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, int *))context->pHAL->vfptr[55].__vecDelDtor)(
    context->pHAL,
    tex,
    texgen,
    v20);
}

// File Line: 351
// RVA: 0x973DB0
void __fastcall Scaleform::Render::DICommand_PaletteMap::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_PaletteMap *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DICommandVtbl *vfptr; // rax
  int *v9; // rax
  Scaleform::Render::DrawableImage *pObject; // rcx
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  int *v13; // rax
  float v14; // xmm6_4
  float v15; // xmm7_4
  int *v16; // rax
  int v17; // ecx
  float x; // xmm1_4
  float v19; // xmm4_4
  __m128 v20; // [rsp+30h] [rbp-40h] BYREF
  __m128 v21; // [rsp+40h] [rbp-30h]
  char v22; // [rsp+90h] [rbp+20h] BYREF
  char v23; // [rsp+98h] [rbp+28h] BYREF

  vfptr = this->vfptr;
  v20 = (__m128)_xmm;
  v21 = _xmm;
  if ( (unsigned __int8)vfptr[1].GetCPUCaps(this) )
  {
    v20 = (__m128)_xmm_bf800000000000000000000040000000;
    v21 = (__m128)_xmm;
  }
  else
  {
    v9 = (int *)this->pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[5].__vecDelDtor(
                  this->pImage.pObject,
                  &v22);
    pObject = this->pImage.pObject;
    v11 = (__m128)COERCE_UNSIGNED_INT((float)(this->SourceRect.x2 - this->SourceRect.x1));
    v12 = (__m128)COERCE_UNSIGNED_INT((float)(this->SourceRect.y2 - this->SourceRect.y1));
    v11.m128_f32[0] = v11.m128_f32[0] / (float)*v9;
    v12.m128_f32[0] = v12.m128_f32[0] / (float)v9[1];
    v20 = _mm_mul_ps(v20, _mm_shuffle_ps(v11, v11, 0));
    v21 = _mm_mul_ps(v21, _mm_shuffle_ps(v12, v12, 0));
    v13 = (int *)pObject->vfptr[5].__vecDelDtor(pObject, (unsigned int)&v22);
    v14 = (float)*v13;
    v15 = (float)v13[1];
    v16 = (int *)this->pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[5].__vecDelDtor(
                   this->pImage.pObject,
                   &v23);
    v17 = *v16;
    x = (float)this->DestPoint.x;
    v19 = v21.m128_f32[3] + (float)((float)((float)this->DestPoint.y - (float)((float)v16[1] * 0.5)) / v15);
    v20.m128_f32[0] = v20.m128_f32[0] * 2.0;
    v20.m128_f32[2] = v20.m128_f32[2] * 2.0;
    v20.m128_f32[3] = (float)(v20.m128_f32[3] + (float)((float)(x - (float)((float)v17 * 0.5)) / v14)) * 2.0;
    v20.m128_f32[1] = v20.m128_f32[1] * 2.0;
    v21.m128_f32[0] = v21.m128_f32[0] * -2.0;
    v21.m128_f32[1] = v21.m128_f32[1] * -2.0;
    v21.m128_f32[3] = v19 * -2.0;
    v21.m128_f32[2] = v21.m128_f32[2] * -2.0;
  }
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, __m128 *, unsigned int, unsigned int *))context->pHAL->vfptr[57].__vecDelDtor)(
    context->pHAL,
    tex,
    texgen,
    &v20,
    this->ChannelMask,
    this->Channels);
}

// File Line: 373
// RVA: 0x973FC0
void __fastcall Scaleform::Render::DICommand_Scroll::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_Scroll *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  double v8; // xmm0_8
  Scaleform::Render::DrawableImage *pObject; // rax
  Scaleform::Render::HAL *pHAL; // rcx
  __int128 v11; // [rsp+30h] [rbp-28h] BYREF
  float v12; // [rsp+40h] [rbp-18h]
  float v13; // [rsp+44h] [rbp-14h]
  int v14; // [rsp+48h] [rbp-10h]
  float v15; // [rsp+4Ch] [rbp-Ch]

  v8 = ((double (__fastcall *)(Scaleform::Render::HAL *))context->pHAL->vfptr[71].__vecDelDtor)(context->pHAL);
  pObject = this->pImage.pObject;
  pHAL = context->pHAL;
  v14 = 0;
  v13 = *(float *)&v8 * 2.0;
  v11 = _xmm_bf800000000000000000000040000000;
  v12 = (float)(*(float *)&v8 * 2.0) * 0.0;
  v15 = (float)(*(float *)&v8 * 2.0) * -0.5;
  Scaleform::Render::HAL::applyBlendMode(pHAL, (Scaleform::Render::BlendMode)(pObject->Transparent + 15), 1, 1);
  ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, __int128 *, Scaleform::Render::Matrix2x4<float> *, int))context->pHAL->vfptr[58].__vecDelDtor)(
    context->pHAL,
    *tex,
    &v11,
    &texgen[1],
    -1);
}

