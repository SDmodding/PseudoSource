// File Line: 26
// RVA: 0x973010
void __fastcall Scaleform::Render::DICommand_CreateTexture::ExecuteHW(Scaleform::Render::DICommand_CreateTexture *this, Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DICommand_CreateTexture *v2; // rdi
  Scaleform::Render::DICommandContext *v3; // rbx
  Scaleform::Render::TextureManager *v4; // rax

  v2 = this;
  v3 = context;
  v4 = (Scaleform::Render::TextureManager *)((__int64 (*)(void))context->pHAL->vfptr[61].__vecDelDtor)();
  Scaleform::Render::DrawableImage::createTextureFromManager(v2->pImage.pObject, v3->pHAL, v4);
}

// File Line: 35
// RVA: 0x972E70
void __fastcall Scaleform::Render::DICommand_Clear::ExecuteHW(Scaleform::Render::DICommand_Clear *this, Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::HAL *v2; // rbx
  Scaleform::Render::DICommandContext *v3; // rdi
  Scaleform::Render::DICommand_Clear *v4; // rsi
  signed int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // er10
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  signed int *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  Scaleform::Render::HAL *v12; // rcx
  Scaleform::Render::HAL *v13; // rbx
  signed int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // er10
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  __int64 v18; // [rsp+20h] [rbp-18h]
  int v19; // [rsp+28h] [rbp-10h]
  int v20; // [rsp+2Ch] [rbp-Ch]
  unsigned int v21; // [rsp+40h] [rbp+8h]
  char v22; // [rsp+48h] [rbp+10h]

  v2 = context->pHAL;
  v3 = context;
  v4 = this;
  if ( v2->CurrentBlendState.Mode != 16 || v2->CurrentBlendState.SourceAc != 1 || v2->CurrentBlendState.ForceAc != 1 )
  {
    v5 = v2->Profiler.vfptr->GetBlendMode(&v2->Profiler, Blend_OverwriteAll);
    v2->FillFlags &= 0xFFFFFFFC;
    v6 = v2->FillFlags;
    v7 = v5;
    if ( (unsigned int)(v5 - 3) <= 1 )
    {
      v2->FillFlags = v6 | 1;
    }
    else if ( v5 == 10 )
    {
      v2->FillFlags = v6 | 2;
      v2->FillFlags |= 0x20u;
LABEL_11:
      v2->CurrentBlendState.Mode = v5;
      v8 = v2->vfptr;
      *(_WORD *)&v2->CurrentBlendState.SourceAc = 257;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, signed __int64))v8[42].__vecDelDtor)(v2, v7, 1i64);
      goto LABEL_12;
    }
    if ( v5 <= 1 )
      v2->FillFlags &= 0xFFFFFFDF;
    else
      v2->FillFlags |= 0x20u;
    goto LABEL_11;
  }
LABEL_12:
  v9 = (signed int *)v4->pImage.pObject->vfptr[5].__vecDelDtor(
                       (Scaleform::RefCountImplCore *)&v4->pImage.pObject->vfptr,
                       (unsigned int)&v22);
  v10 = (float)v9[1];
  v11 = (float)*v9;
  v12 = v3->pHAL;
  v18 = 0i64;
  v19 = (signed int)v11;
  v20 = (signed int)v10;
  v21 = v4->FillColor.Raw;
  ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, unsigned int *, _QWORD, _QWORD, _QWORD))v12->vfptr[18].__vecDelDtor)(
    v12,
    &v18,
    &v21,
    0i64,
    0i64,
    *(_QWORD *)&v19);
  v13 = v3->pHAL;
  if ( v13->CurrentBlendState.Mode || v13->CurrentBlendState.SourceAc || v13->CurrentBlendState.ForceAc )
  {
    v14 = v13->Profiler.vfptr->GetBlendMode(&v13->Profiler, 0i64);
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
      v13->FillFlags &= 0xFFFFFFDF;
    else
      v13->FillFlags |= 0x20u;
    goto LABEL_22;
  }
}

// File Line: 43
// RVA: 0x974120
void __fastcall Scaleform::Render::DICommand_ApplyFilter::ExecuteHWGetImages(Scaleform::Render::DICommand_ApplyFilter *this, Scaleform::Render::DrawableImage **images, Scaleform::Render::Size<float> *readOffsets)
{
  float v3; // xmm1_4
  float v4; // xmm1_4

  *images = this->pImage.pObject;
  v3 = (float)this->DestPoint.y;
  readOffsets->Width = (float)this->DestPoint.x;
  readOffsets->Height = v3;
  images[1] = this->pSource.pObject;
  v4 = (float)this->SourceRect.y1;
  readOffsets[1].Width = (float)this->SourceRect.x1;
  readOffsets[1].Height = v4;
}

// File Line: 55
// RVA: 0x973360
void __fastcall Scaleform::Render::DICommand_ApplyFilter::ExecuteHWCopyAction(Scaleform::Render::DICommand_ApplyFilter *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::Matrix2x4<float> *v4; // r14
  Scaleform::Render::Texture **v5; // r15
  Scaleform::Render::DICommandContext *v6; // rsi
  Scaleform::Render::DICommand_ApplyFilter *v7; // rbx
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm8_4
  float v13; // xmm9_4
  float v14; // xmm0_4
  Scaleform::Render::Filter *v15; // rdx
  Scaleform::Render::CacheablePrimitive *v16; // rax
  __int64 v17; // rdi
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v18; // rcx
  float v19; // xmm6_4
  float v20; // xmm7_4
  Scaleform::Render::MatrixPoolImpl::DataHeader *v21; // rbx
  bool v22; // zf
  __int64 v23; // rcx
  Scaleform::Render::CacheAsBitmapFilter *v24; // rcx
  Scaleform::Render::Rect<float> bounds; // [rsp+30h] [rbp-90h]
  Scaleform::Render::FilterSet v26; // [rsp+40h] [rbp-80h]
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
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+1A0h] [rbp+E0h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v40; // [rsp+1A8h] [rbp+E8h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v41; // [rsp+1B0h] [rbp+F0h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v42; // [rsp+1B8h] [rbp+F8h]

  v34 = -2i64;
  v4 = texgen;
  v5 = tex;
  v6 = context;
  v7 = this;
  v26.0 = (Scaleform::RefCountBase<Scaleform::Render::FilterSet,2>)_xmm;
  *(__m128 *)&v26.Filters.Data.Data = _xmm;
  v8 = (float)this->SourceRect.y2;
  v9 = (float)this->SourceRect.x2;
  v10 = (float)this->SourceRect.y1;
  v11 = (float)this->SourceRect.x1;
  bounds.x1 = (float)(signed int)(float)(v11 * 20.0);
  bounds.y1 = (float)(signed int)(float)(v10 * 20.0);
  bounds.x2 = (float)(signed int)(float)(v9 * 20.0);
  bounds.y2 = (float)(signed int)(float)(v8 * 20.0);
  Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(this->pFilter.pObject, &bounds);
  v29 = bounds.x1 * 0.050000001;
  v30 = bounds.y1 * 0.050000001;
  v31 = bounds.x2 * 0.050000001;
  v32 = bounds.y2 * 0.050000001;
  v12 = (float)(bounds.y2 * 0.050000001) - (float)(bounds.y1 * 0.050000001);
  v13 = (float)(bounds.x2 * 0.050000001) - (float)(bounds.x1 * 0.050000001);
  *(float *)&v40 = (float)(bounds.x2 * 0.050000001) - (float)(bounds.x1 * 0.050000001);
  *((float *)&v40 + 1) = (float)(bounds.y2 * 0.050000001) - (float)(bounds.y1 * 0.050000001);
  *(float *)&v26.Filters.Data.Policy.Capacity = (float)(bounds.x2 * 0.050000001) - (float)(bounds.x1 * 0.050000001);
  *((float *)&v26.Filters.Data.Policy.Capacity + 1) = v13 * 0.0;
  *(float *)&v26.Frozen = v13 * 0.0;
  *(float *)&v26.pCacheAsBitmapFilter.pObject = v12 * 0.0;
  *((float *)&v26.pCacheAsBitmapFilter.pObject + 1) = (float)(bounds.y2 * 0.050000001)
                                                    - (float)(bounds.y1 * 0.050000001);
  v27 = v12 * 0.0;
  *(float *)(&v26.CacheAsBitmap + 3) = (float)(v13 * 0.0) + (float)(bounds.x1 * 0.050000001);
  v14 = (float)(v12 * 0.0) + (float)(bounds.y1 * 0.050000001);
  v28 = (float)(v12 * 0.0) + (float)(bounds.y1 * 0.050000001);
  v15 = v7->pFilter.pObject;
  v26.RefCount = 1;
  v26.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable;
  v41 = &v26.Filters;
  v42 = &v26.Filters;
  v26.Filters.Data.Data = 0i64;
  v26.Filters.Data.Size = 0i64;
  v26.Filters.Data.Policy.Capacity = 0i64;
  *(_WORD *)&v26.Frozen = 0;
  v26.pCacheAsBitmapFilter.pObject = 0i64;
  if ( v15 )
    Scaleform::Render::FilterSet::AddFilter(&v26, v15);
  v16 = (Scaleform::Render::CacheablePrimitive *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   88i64);
  v17 = (__int64)v16;
  v41 = (Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *)v16;
  if ( v16 )
  {
    Scaleform::Render::CacheablePrimitive::CacheablePrimitive(v16, 0);
    *(_QWORD *)v17 = &Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
    *(_QWORD *)(v17 + 16) = &Scaleform::Render::FilterPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
    _InterlockedExchangeAdd(&v26.RefCount, 1u);
    *(_QWORD *)(v17 + 80) = &v26;
  }
  else
  {
    v17 = 0i64;
  }
  v33 = v17;
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
    &v6->pR2D->pImpl->MPool,
    &result,
    (Scaleform::Render::Matrix2x4<float> *)&v26.Filters.Data.Policy,
    0);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(
    &result,
    (Scaleform::Render::Matrix2x4<float> *)&v26.Filters.Data.Policy);
  Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> *)(v17 + 48),
    *(_QWORD *)(v17 + 56) + 1i64);
  if ( *(_QWORD *)(v17 + 56) != 1i64 )
    memmove((void *)(*(_QWORD *)(v17 + 48) + 8i64), *(const void **)(v17 + 48), 8 * (*(_QWORD *)(v17 + 56) - 1i64));
  v18 = *(Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> **)(v17 + 48);
  v41 = v18;
  v42 = v18;
  if ( v18 )
  {
    v18->Data.Data = (Scaleform::Ptr<Scaleform::Render::Filter> *)result.pHandle;
    if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
      ++result.pHandle->pHeader->RefCount;
  }
  v6->pHAL->vfptr[47].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->pHAL->vfptr, v17);
  ((void (*)(void))v6->pHAL->vfptr[71].__vecDelDtor)();
  v38 = v14 * 2.0;
  v35 = (float)(v14 * 2.0) * 0.0;
  v36 = v14 * 2.0;
  v37 = (float)(v14 * 2.0) * -0.5;
  v19 = (float)(v8 - v10) / v12;
  v20 = (float)(v9 - v11) / v13;
  *(float *)&v26.vfptr = v20 * 2.0;
  *((float *)&v26.vfptr + 1) = v20 * 0.0;
  *(float *)&v26.RefCount = v20 * 0.0;
  *((float *)&v26.RefCount + 1) = v20 * -1.0;
  *(float *)&v26.Filters.Data.Data = v19 * v35;
  *((float *)&v26.Filters.Data.Data + 1) = v19 * (float)(v14 * 2.0);
  *(float *)&v26.Filters.Data.Size = v19 * 0.0;
  *((float *)&v26.Filters.Data.Size + 1) = v19 * v37;
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture *, Scaleform::Render::FilterSet *, Scaleform::Render::Matrix2x4<float> *, signed int))v6->pHAL->vfptr[58].__vecDelDtor)(
    v6->pHAL,
    v5[1],
    &v26,
    &v4[1],
    -1);
  ((void (*)(void))v6->pHAL->vfptr[48].__vecDelDtor)();
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v21 = result.pHandle->pHeader;
    v22 = result.pHandle->pHeader->RefCount == 1;
    --v21->RefCount;
    if ( v22 )
    {
      v23 = v21->DataPageOffset;
      *(_WORD *)((char *)&v21[1].RefCount + v23 + 2) += 16 * (unsigned __int8)v21->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v21[1].pHandle + v23))[5].pHeader += (unsigned __int8)v21->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v21->pHandle);
      v21->pHandle = 0i64;
    }
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v17 + 8)) )
    (**(void (__fastcall ***)(__int64, signed __int64))v17)(v17, 1i64);
  v26.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable;
  v24 = v26.pCacheAsBitmapFilter.pObject;
  if ( v26.pCacheAsBitmapFilter.pObject && !_InterlockedDecrement(&v26.pCacheAsBitmapFilter.pObject->RefCount) && v24 )
    v24->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, 1u);
  v40 = &v26.Filters;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy> *)&v26.Filters.Data.Data);
}

// File Line: 86
// RVA: 0x973880
void __fastcall Scaleform::Render::DICommand_ColorTransform::ExecuteHWCopyAction(Scaleform::Render::DICommand_ColorTransform *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DICommandContext *v4; // rdi
  Scaleform::Render::Matrix2x4<float> *v5; // rsi
  Scaleform::Render::DICommand_ColorTransform *v6; // rbx
  Scaleform::Render::Texture **v7; // rbp
  Scaleform::Render::DrawableImage *v8; // rax
  __int128 v9; // xmm1
  __int128 v10; // [rsp+20h] [rbp-28h]
  __int128 v11; // [rsp+30h] [rbp-18h]

  v4 = context;
  v5 = texgen;
  v6 = this;
  v7 = tex;
  Scaleform::Render::HAL::applyBlendMode(
    context->pHAL,
    (Scaleform::Render::BlendMode)((this->pImage.pObject->Transparent != 0) + 15),
    1,
    1);
  v8 = v6->pImage.pObject;
  v9 = *(_OWORD *)&v6->Cx.M[1][0];
  v10 = *(_OWORD *)&v6->Cx.M[0][0];
  v11 = v9;
  if ( !v8->Transparent )
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
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, __int128 *))v4->pHAL->vfptr[52].__vecDelDtor)(
    v4->pHAL,
    v7 + 1,
    &v5[1],
    &v10);
}

// File Line: 109
// RVA: 0x973050
void __fastcall Scaleform::Render::DICommand_Draw::ExecuteHW(Scaleform::Render::DICommand_Draw *this, Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DICommandContext *v2; // rdi
  Scaleform::Render::DrawableImageContext *v3; // r14
  Scaleform::Render::DICommand_Draw *v4; // rsi
  Scaleform::Render::HAL *v5; // rbx
  char v6; // bp
  bool v7; // zf
  Scaleform::Render::HAL *v8; // rbx
  signed int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // er10
  Scaleform::RefCountImplCoreVtbl *v12; // rax
  Scaleform::Render::HAL *v13; // rcx
  Scaleform::Render::HALEndDisplayItem *v14; // [rsp+20h] [rbp-58h]
  __int64 v15; // [rsp+28h] [rbp-50h]
  Scaleform::Render::Viewport vpin; // [rsp+30h] [rbp-48h]
  Scaleform::Render::Color backgroundColor; // [rsp+80h] [rbp+8h]

  v2 = context;
  v3 = this->pImage.pObject->pContext.pObject;
  v4 = this;
  v3->vfptr[1].__vecDelDtor(
    (Scaleform::RefCountImplCore *)&this->pImage.pObject->pContext.pObject->vfptr,
    (unsigned int)context->pR2D->pImpl);
  v5 = v2->pHAL;
  v6 = 0;
  v7 = (v5->HALState & 8) == 0;
  vpin.BufferWidth = v5->VP.BufferWidth;
  vpin.BufferHeight = v5->VP.BufferHeight;
  vpin.Left = v5->VP.Left;
  vpin.Top = v5->VP.Top;
  vpin.Width = v5->VP.Width;
  vpin.Height = v5->VP.Height;
  vpin.Flags = v5->VP.Flags;
  vpin.ScissorLeft = v5->VP.ScissorLeft;
  vpin.ScissorTop = v5->VP.ScissorTop;
  vpin.ScissorWidth = v5->VP.ScissorWidth;
  vpin.ScissorHeight = v5->VP.ScissorHeight;
  if ( !v7 )
  {
    v6 = 1;
    if ( v5->HALState & 0x400 )
    {
      ((void (__fastcall *)(Scaleform::Render::HAL *))v5->vfptr[8].__vecDelDtor)(v5);
      ((void (__fastcall *)(Scaleform::Render::HAL *))v5->vfptr[12].__vecDelDtor)(v5);
    }
    else
    {
      v15 = 0i64;
      v14 = &Scaleform::Render::HALEndDisplayItem::Instance;
      v5->vfptr[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v14);
    }
  }
  ((void (*)(void))v2->pHAL->vfptr[8].__vecDelDtor)();
  v2->pHAL->vfptr[30].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->pHAL->vfptr, 3u);
  v8 = v2->pHAL;
  if ( v8->CurrentBlendState.Mode != 1 || v8->CurrentBlendState.SourceAc != 1 || v8->CurrentBlendState.ForceAc != 1 )
  {
    v9 = v8->Profiler.vfptr->GetBlendMode(&v8->Profiler, Blend_Normal);
    v8->FillFlags &= 0xFFFFFFFC;
    v10 = v8->FillFlags;
    v11 = v9;
    if ( (unsigned int)(v9 - 3) <= 1 )
    {
      v8->FillFlags = v10 | 1;
    }
    else if ( v9 == 10 )
    {
      v8->FillFlags = v10 | 2;
      v8->FillFlags |= 0x20u;
LABEL_15:
      v8->CurrentBlendState.Mode = v9;
      v12 = v8->vfptr;
      *(_WORD *)&v8->CurrentBlendState.SourceAc = 257;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, signed __int64))v12[42].__vecDelDtor)(v8, v11, 1i64);
      goto LABEL_16;
    }
    if ( v9 <= 1 )
      v8->FillFlags &= 0xFFFFFFDF;
    else
      v8->FillFlags |= 0x20u;
    goto LABEL_15;
  }
LABEL_16:
  Scaleform::Render::Renderer2DImpl::Draw(v2->pR2D->pImpl, v4->pRoot);
  ((void (*)(void))v2->pHAL->vfptr[8].__vecDelDtor)();
  if ( v6 )
  {
    v13 = v2->pHAL;
    backgroundColor = 0;
    Scaleform::Render::HAL::BeginDisplay(v13, (__int64)&backgroundColor, &vpin);
  }
  Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(v3, v4->pRoot);
}

// File Line: 144
// RVA: 0x972760
void __fastcall Scaleform::Render::DICommand_Draw::ExecuteDiscard(Scaleform::Render::DICommand_Draw *this)
{
  Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(this->pImage.pObject->pContext.pObject, this->pRoot);
}

// File Line: 153
// RVA: 0x972780
void __fastcall Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_CopyPixels>::ExecuteHW(Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *this, Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *v2; // r14
  __int64 v3; // r15
  unsigned __int64 v4; // rsi
  __int64 v5; // rbx
  signed __int64 v6; // r13
  signed __int64 v7; // rdi
  unsigned __int64 v8; // rcx
  __int64 v9; // rax
  unsigned __int64 v10; // rcx
  __int64 v11; // rax
  int v12; // er15
  int v13; // er12
  Scaleform::Render::DrawableImage *v14; // rbx
  int *v15; // rdi
  unsigned int *v16; // rax
  __int64 v17; // rdx
  signed int v18; // ecx
  int v19; // er10
  int v20; // er11
  signed int v21; // er9
  __int64 v22; // r8
  int v23; // ebx
  signed int v24; // eax
  int v25; // ebx
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  __int64 v29; // rdi
  __int64 v30; // rbx
  unsigned int v31; // eax
  signed int *v32; // rbx
  int v33; // edi
  int v34; // edx
  unsigned int v35; // ecx
  unsigned int v36; // ecx
  float *v37; // r8
  int v38; // er14
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
  __int64 v58; // [rsp+20h] [rbp-A0h]
  int v59; // [rsp+30h] [rbp-90h]
  int v60; // [rsp+34h] [rbp-8Ch]
  __m128 v61; // [rsp+40h] [rbp-80h]
  __m128 v62; // [rsp+50h] [rbp-70h]
  __int64 v63; // [rsp+60h] [rbp-60h]
  __int64 v64; // [rsp+68h] [rbp-58h]
  __m128 v65; // [rsp+70h] [rbp-50h]
  __int64 v66; // [rsp+88h] [rbp-38h]
  __int64 v67[3]; // [rsp+90h] [rbp-30h]
  __int64 v68[3]; // [rsp+A8h] [rbp-18h]
  __int128 v69; // [rsp+C0h] [rbp+0h]
  __m128 v70; // [rsp+D0h] [rbp+10h]
  __int128 v71; // [rsp+E0h] [rbp+20h]
  __m128 v72; // [rsp+F0h] [rbp+30h]
  __int128 v73; // [rsp+100h] [rbp+40h]
  __m128 v74; // [rsp+110h] [rbp+50h]
  __int64 v75; // [rsp+1A0h] [rbp+E0h]
  __int64 v76; // [rsp+1A8h] [rbp+E8h]
  __int64 *v77; // [rsp+1B0h] [rbp+F0h]
  char v78; // [rsp+1B8h] [rbp+F8h]

  v66 = -2i64;
  v2 = this;
  v3 = ((__int64 (*)(void))context->pHAL->vfptr[61].__vecDelDtor)();
  v77 = (__int64 *)v3;
  v62.m128_u64[1] = 0i64;
  v63 = 0i64;
  v64 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold> *, char *, __m128 *))v2->vfptr[1].__vecDelDtor)(
    v2,
    &v62.m128_i8[8],
    &v65);
  v4 = 0i64;
  v5 = 0i64;
  v6 = 3i64;
  v7 = 3i64;
  do
  {
    v8 = v62.m128_u64[v5 + 1];
    if ( v8 )
      v9 = (*(__int64 (**)(void))(*(_QWORD *)v8 + 208i64))();
    else
      v9 = 0i64;
    v68[v5] = v9;
    v10 = v62.m128_u64[v5 + 1];
    if ( v10 )
      v11 = (*(__int64 (__fastcall **)(unsigned __int64, __int64))(*(_QWORD *)v10 + 168i64))(v10, v3);
    else
      v11 = 0i64;
    v67[v5] = v11;
    ++v5;
    --v7;
  }
  while ( v7 );
  v59 = 0;
  v60 = 0;
  v12 = 0;
  v13 = 0;
  v14 = v2->pSource.pObject;
  v15 = (int *)v2->pImage.pObject->vfptr[5].__vecDelDtor(
                 (Scaleform::RefCountImplCore *)&v2->pImage.pObject->vfptr,
                 (unsigned int)&v78);
  v16 = (unsigned int *)v14->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, (unsigned int)&v62);
  v17 = (unsigned int)v2->SourceRect.y1;
  v18 = v2->SourceRect.x1;
  v19 = v2->DestPoint.y - v17;
  v20 = v2->DestPoint.x - v18;
  v21 = v16[1];
  v22 = *v16;
  if ( v21 >= (signed int)v17 )
  {
    v23 = v2->SourceRect.y2;
    if ( v23 >= 0 )
    {
      v24 = v2->SourceRect.x2;
      if ( v24 >= 0 && (signed int)v22 >= v18 )
      {
        if ( v18 < 0 )
          v18 = 0;
        if ( (signed int)v22 > v24 )
          LODWORD(v22) = v2->SourceRect.x2;
        if ( (signed int)v17 < 0 )
          LODWORD(v17) = 0;
        if ( v21 > v23 )
          v21 = v2->SourceRect.y2;
        v25 = v18 + v20;
        v26 = v22 + v20;
        v22 = (unsigned int)(v19 + v17);
        v17 = (unsigned int)(v19 + v21);
        if ( (signed int)v17 >= 0 && v15[1] >= (signed int)v22 && *v15 >= v25 && v26 >= 0 )
        {
          v27 = 0;
          if ( v25 > 0 )
            v27 = v25;
          v59 = v27;
          v12 = v26;
          if ( v26 > *v15 )
            v12 = *v15;
          v28 = 0;
          if ( (signed int)v22 > 0 )
            v28 = v22;
          v60 = v28;
          v13 = v19 + v21;
          if ( (signed int)v17 > v15[1] )
            v13 = v15[1];
        }
      }
    }
  }
  v29 = (__int64)v77;
  v30 = *v77;
  v31 = (*(__int64 (__fastcall **)(__int64 *, __int64, __int64))(*v77 + 104))(v77, v17, v22);
  LOBYTE(v77) = (*(unsigned __int8 (__fastcall **)(__int64, _QWORD, signed __int64))(v30 + 32))(v29, v31, 1152i64) == 0;
  v78 = v2->vfptr[1].GetCPUCaps((Scaleform::Render::DICommand *)&v2->vfptr);
  v32 = 0i64;
  v62.m128_u64[0] = 0i64;
  v33 = v59;
  if ( v78 )
  {
    LODWORD(v63) = v12 - v59;
    HIDWORD(v63) = v13 - v60;
    if ( (_BYTE)v77 )
    {
      v35 = ((((unsigned int)(v12 - v59 - 1) >> 1) | (v12 - v59 - 1)) >> 2) | ((unsigned int)(v12 - v59 - 1) >> 1) | (v12 - v59 - 1);
      v36 = (((v35 >> 4) | v35) >> 8) | (v35 >> 4) | v35;
      LODWORD(v63) = (v36 | (v36 >> 16)) + 1;
      v34 = v13 - v60;
      HIDWORD(v63) = (((((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 8) | ((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1) | ((((((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 8) | ((((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 4) | ((((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 2) | ((unsigned int)(v34 - 1) >> 1) | (v34 - 1)) >> 16))
                   + 1;
    }
    v32 = (signed int *)(*(__int64 (__fastcall **)(_QWORD, __int64 *, _QWORD))(**(_QWORD **)(v76 + 8) + 176i64))(
                          *(_QWORD *)(v76 + 8),
                          &v63,
                          0i64);
    v62.m128_u64[0] = (unsigned __int64)v32;
    v59 = 0;
    v61.m128_u64[0] = 0i64;
    v61.m128_f32[2] = (float)(signed int)v63;
    v61.m128_f32[3] = (float)SHIDWORD(v63);
    (*(void (__fastcall **)(_QWORD, __m128 *, signed int *, signed __int64, int *))(**(_QWORD **)(v76 + 8) + 192i64))(
      *(_QWORD *)(v76 + 8),
      &v61,
      v32,
      2i64,
      &v59);
  }
  v69 = _xmm;
  v70 = _xmm;
  v71 = _xmm;
  v72 = _xmm;
  v73 = _xmm;
  v74 = _xmm;
  v37 = (float *)((char *)&v69 + 8);
  v38 = v60;
  do
  {
    v39 = v67[v4 / 2];
    if ( v39 )
    {
      v40 = (float)(v13 - v38) / (float)*(signed int *)(v39 + 52);
      v41 = (float)(v12 - v33) / (float)*(signed int *)(v39 + 48);
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
      v44 = (float)*(signed int *)(v39 + 52);
      v45 = v65.m128_f32[v4 + 1];
      v37[1] = v42 + (float)(v65.m128_f32[v4] / (float)*(signed int *)(v39 + 48));
      v37[5] = (float)(v45 / v44) + v43;
    }
    v4 += 2i64;
    v37 += 8;
    --v6;
  }
  while ( v6 );
  v46 = v76;
  (*(void (__fastcall **)(__int64, __int64, __int64 *, __int128 *))(*(_QWORD *)v75 + 80i64))(v75, v76, v67, &v69);
  if ( v78 )
  {
    (*(void (__fastcall **)(_QWORD, signed __int64))(**(_QWORD **)(v46 + 8) + 200i64))(*(_QWORD *)(v46 + 8), 2i64);
    v62 = _xmm;
    v65 = (__m128)_xmm;
    v61 = _xmm;
    v47 = (float)(v13 - v60);
    v48 = (float)(v12 - v33);
    if ( (_BYTE)v77 )
    {
      v48 = (float)(signed int)((((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2)) >> 4) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2)) >> 4)) >> 8)) >> 16) | ((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2)) >> 4) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1) | ((((signed int)v48 - 1) | ((unsigned int)((signed int)v48 - 1) >> 1)) >> 2)) >> 4)) >> 8))
                              + 1);
      v47 = (float)(signed int)((((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2)) >> 4) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2)) >> 4)) >> 8)) >> 16) | ((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2)) >> 4) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1) | ((((signed int)v47 - 1) | ((unsigned int)((signed int)v47 - 1) >> 1)) >> 2)) >> 4)) >> 8))
                              + 1);
    }
    v49 = v47 / (float)(*(_DWORD *)(v68[0] + 60) - *(_DWORD *)(v68[0] + 52));
    v61.m128_f32[0] = v48 / (float)(*(_DWORD *)(v68[0] + 56) - *(_DWORD *)(v68[0] + 48));
    v61.m128_f32[1] = v61.m128_f32[0] * 0.0;
    v61.m128_f32[2] = v61.m128_f32[0] * 0.0;
    v61.m128_f32[3] = v61.m128_f32[0] * 0.0;
    v62.m128_f32[0] = v49 * 0.0;
    v62.m128_f32[1] = v49;
    v62.m128_f32[2] = v49 * 0.0;
    v62.m128_f32[3] = v49 * 0.0;
    v50 = (__m128)v65.m128_u32[0];
    v51 = (float)(v65.m128_f32[1] - (float)((float)(*(_DWORD *)(v68[0] + 60) - *(_DWORD *)(v68[0] + 52)) * 0.5))
        / (float)(*(_DWORD *)(v68[0] + 60) - *(_DWORD *)(v68[0] + 52));
    v50.m128_f32[0] = (float)(v65.m128_f32[0]
                            - (float)((float)(*(_DWORD *)(v68[0] + 56) - *(_DWORD *)(v68[0] + 48)) * 0.5))
                    / (float)(*(_DWORD *)(v68[0] + 56) - *(_DWORD *)(v68[0] + 48));
    v61.m128_f32[3] = (float)(v61.m128_f32[0] * 0.0) + v50.m128_f32[0];
    v62.m128_f32[3] = (float)(v49 * 0.0) + v51;
    (*(void (**)(void))(**(_QWORD **)(v46 + 8) + 568i64))();
    v52 = v50;
    v52.m128_f32[0] = v50.m128_f32[0] * 2.0;
    v61 = _mm_mul_ps(v61, (__m128)_xmm);
    v62 = _mm_mul_ps(v62, _mm_shuffle_ps(v52, v52, 0));
    v53 = 0i64;
    v54 = 0i64;
    v53.m128_f32[0] = (float)(v32[15] - v32[13]) / (float)v32[11];
    v54.m128_f32[0] = (float)(v32[14] - v32[12]) / (float)v32[10];
    v65 = _mm_mul_ps(v65, _mm_shuffle_ps(v54, v54, 0));
    v61 = _mm_mul_ps(v61, _mm_shuffle_ps(v53, v53, 0));
    v55 = *(__int64 **)(v46 + 8);
    v56 = *v55;
    v57 = (*(__int64 (__fastcall **)(signed int *))(*(_QWORD *)v32 + 24i64))(v32);
    LODWORD(v58) = -1;
    (*(void (__fastcall **)(__int64 *, __int64, __m128 *, __m128 *, __int64))(v56 + 464))(v55, v57, &v61, &v65, v58);
    (*(void (__fastcall **)(signed int *, _QWORD))(*(_QWORD *)v32 + 40i64))(v32, 0i64);
  }
  if ( v32 )
    (*(void (__fastcall **)(signed int *))(*(_QWORD *)v32 + 16i64))(v32);
}

// File Line: 245
// RVA: 0x973A20
void __fastcall Scaleform::Render::DICommand_CopyChannel::ExecuteHWCopyAction(Scaleform::Render::DICommand_CopyChannel *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::Matrix2x4<float> *v4; // r12
  Scaleform::Render::Texture **v5; // r13
  Scaleform::Render::DICommandContext *v6; // r15
  Scaleform::Render::DICommand_CopyChannel *v7; // r14
  signed int v8; // esi
  char *v9; // rdi
  int v10; // ebx
  char v11; // bp
  signed int v12; // edx
  signed int v13; // edi
  __int64 v14; // rsi
  int v15[10]; // [rsp+20h] [rbp-A8h]
  char v16; // [rsp+48h] [rbp-80h]
  int Dst[16]; // [rsp+60h] [rbp-68h]

  v4 = texgen;
  v5 = tex;
  v6 = context;
  v7 = this;
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
  if ( v7->DestChannel != 1 )
  {
    switch ( v7->DestChannel )
    {
      case 2:
        v12 = 1;
        break;
      case 4:
        v12 = 2;
        break;
      case 8:
        v12 = 3;
        break;
      default:
        v11 = 0;
        break;
    }
  }
  if ( v7->SourceChannel != 1 )
  {
    switch ( v7->SourceChannel )
    {
      case 2:
        v13 = 1;
        break;
      case 4:
        v13 = 2;
        break;
      case 8:
        v13 = 3;
        break;
      default:
        v11 = 0;
        break;
    }
  }
  v14 = v12;
  v15[5 * v12] = 0;
  memset(Dst, 0, 0x40ui64);
  if ( v11 )
    Dst[v13 + 4 * v14] = 1065353216;
  LOBYTE(v10) = v7->pImage.pObject->Transparent != 0;
  Scaleform::Render::HAL::applyBlendMode(v6->pHAL, (Scaleform::Render::BlendMode)(v10 + 15), 1, 1);
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, int *))v6->pHAL->vfptr[54].__vecDelDtor)(
    v6->pHAL,
    v5,
    v4,
    v15);
}

// File Line: 289
// RVA: 0x974170
void __fastcall Scaleform::Render::DICommand_CopyPixels::ExecuteHWGetImages(Scaleform::Render::DICommand_CopyPixels *this, Scaleform::Render::DrawableImage **images, Scaleform::Render::Size<float> *readOffsets)
{
  float v3; // xmm0_4
  __m128i v4; // xmm1

  *images = this->pImage.pObject;
  v3 = (float)this->DestPoint.x;
  readOffsets->Height = (float)this->DestPoint.y;
  readOffsets->Width = v3;
  images[1] = this->pSource.pObject;
  v4 = _mm_cvtsi32_si128(this->SourceRect.y1);
  readOffsets[1].Width = (float)this->SourceRect.x1;
  LODWORD(readOffsets[1].Height) = (unsigned __int128)_mm_cvtepi32_ps(v4);
  images[2] = this->pAlphaSource.pObject;
  *(float *)v4.m128i_i32 = (float)this->AlphaPoint.y;
  readOffsets[2].Width = (float)this->AlphaPoint.x;
  LODWORD(readOffsets[2].Height) = v4.m128i_i32[0];
}

// File Line: 300
// RVA: 0x973B80
void __fastcall Scaleform::Render::DICommand_CopyPixels::ExecuteHWCopyAction(Scaleform::Render::DICommand_CopyPixels *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DrawableImage *v4; // rax
  Scaleform::Render::DICommandContext *v5; // rbx
  Scaleform::Render::Matrix2x4<float> *v6; // rsi
  Scaleform::Render::DICommand_CopyPixels *v7; // rdi
  Scaleform::Render::HAL *v8; // rcx
  Scaleform::Render::Texture **v9; // rbp
  bool v10; // ST28_1
  bool v11; // ST20_1
  __int128 v12; // [rsp+30h] [rbp-28h]
  __int128 v13; // [rsp+40h] [rbp-18h]

  v4 = this->pImage.pObject;
  v5 = context;
  v6 = texgen;
  v7 = this;
  v8 = context->pHAL;
  v12 = _xmm_bf800000000000000000000040000000;
  v13 = _xmm;
  v9 = tex;
  Scaleform::Render::HAL::applyBlendMode(v8, (Scaleform::Render::BlendMode)((v4->Transparent != 0) + 15), 1, 1);
  v10 = v7->pImage.pObject->Transparent;
  v11 = v7->MergeAlpha;
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, __int128 *, bool, bool, _QWORD, _QWORD, _QWORD, _QWORD))v5->pHAL->vfptr[56].__vecDelDtor)(
    v5->pHAL,
    v9,
    v6,
    &v12,
    v11,
    v10,
    _xmm_bf800000000000000000000040000000,
    *((_QWORD *)&_xmm_bf800000000000000000000040000000 + 1),
    _xmm,
    *((_QWORD *)&_xmm + 1));
}

// File Line: 308
// RVA: 0x973250
void __fastcall Scaleform::Render::DICommand_FillRect::ExecuteHW(Scaleform::Render::DICommand_FillRect *this, Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::HAL *v2; // rbx
  Scaleform::Render::DICommandContext *v3; // rsi
  Scaleform::Render::DICommand_FillRect *v4; // rdi
  signed int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // er10
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  char v9; // cl
  bool v10; // zf
  int v11; // eax
  Scaleform::Render::HAL *v12; // rcx
  int v13; // [rsp+20h] [rbp-18h]
  int v14; // [rsp+24h] [rbp-14h]
  int v15; // [rsp+28h] [rbp-10h]
  int v16; // [rsp+2Ch] [rbp-Ch]
  unsigned int v17; // [rsp+40h] [rbp+8h]

  v2 = context->pHAL;
  v3 = context;
  v4 = this;
  if ( v2->CurrentBlendState.Mode != 16 || v2->CurrentBlendState.SourceAc != 1 || v2->CurrentBlendState.ForceAc != 1 )
  {
    v5 = v2->Profiler.vfptr->GetBlendMode(&v2->Profiler, Blend_OverwriteAll);
    v2->FillFlags &= 0xFFFFFFFC;
    v6 = v2->FillFlags;
    v7 = v5;
    if ( (unsigned int)(v5 - 3) <= 1 )
    {
      v2->FillFlags = v6 | 1;
    }
    else if ( v5 == 10 )
    {
      v2->FillFlags = v6 | 2;
      v2->FillFlags |= 0x20u;
LABEL_11:
      v2->CurrentBlendState.Mode = v5;
      v8 = v2->vfptr;
      *(_WORD *)&v2->CurrentBlendState.SourceAc = 257;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, signed __int64))v8[42].__vecDelDtor)(v2, v7, 1i64);
      goto LABEL_12;
    }
    if ( v5 <= 1 )
      v2->FillFlags &= 0xFFFFFFDF;
    else
      v2->FillFlags |= 0x20u;
    goto LABEL_11;
  }
LABEL_12:
  v17 = v4->FillColor.Raw;
  v9 = HIBYTE(v17);
  v10 = v4->pImage.pObject->Transparent == 0;
  v13 = v4->ApplyRect.x1;
  if ( v10 )
    v9 = -1;
  v14 = v4->ApplyRect.y1;
  v11 = v4->ApplyRect.x2;
  HIBYTE(v17) = v9;
  v12 = v3->pHAL;
  v15 = v11;
  v16 = v4->ApplyRect.y2;
  ((void (__fastcall *)(Scaleform::Render::HAL *, int *, unsigned int *, _QWORD, _QWORD))v12->vfptr[18].__vecDelDtor)(
    v12,
    &v13,
    &v17,
    0i64,
    *(_QWORD *)&v13);
}

// File Line: 321
// RVA: 0x9739A0
void __fastcall Scaleform::Render::DICommand_Compare::ExecuteHWCopyAction(Scaleform::Render::DICommand_Compare *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DICommand_Compare *v4; // rbx
  Scaleform::Render::Matrix2x4<float> *v5; // rsi
  Scaleform::Render::Texture **v6; // r14
  Scaleform::Render::DICommandContext *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // rax

  v4 = this;
  v5 = texgen;
  v6 = tex;
  v7 = context;
  v8 = ((__int64 (*)(void))this->pSource.pObject->vfptr[26].__vecDelDtor)();
  *v6 = (Scaleform::Render::Texture *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 24i64))(v8);
  v9 = ((__int64 (*)(void))v4->pImageCompare1.pObject->vfptr[26].__vecDelDtor)();
  v6[1] = (Scaleform::Render::Texture *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 24i64))(v9);
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *))v7->pHAL->vfptr[53].__vecDelDtor)(
    v7->pHAL,
    v6,
    v5);
}

// File Line: 331
// RVA: 0x973C20
void __fastcall Scaleform::Render::DICommand_Merge::ExecuteHWCopyAction(Scaleform::Render::DICommand_Merge *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::Matrix2x4<float> *v4; // r15
  Scaleform::Render::Texture **v5; // r12
  Scaleform::Render::DICommandContext *v6; // r14
  Scaleform::Render::DICommand_Merge *v7; // rbp
  signed int v8; // esi
  float *v9; // rdi
  Scaleform::Render::HAL *v10; // rcx
  signed int v11; // edx
  signed int v12; // eax
  float v13; // xmm1_4
  signed int v14; // eax
  float v15; // xmm5_4
  signed int v16; // eax
  float v17; // xmm1_4
  float v18; // xmm4_4
  Scaleform::Render::DrawableImage *v19; // rax
  float v20; // [rsp+20h] [rbp-98h]
  float v21; // [rsp+34h] [rbp-84h]
  float v22; // [rsp+48h] [rbp-70h]
  float v23; // [rsp+5Ch] [rbp-5Ch]
  float v24; // [rsp+60h] [rbp-58h]
  float v25; // [rsp+74h] [rbp-44h]
  float v26; // [rsp+88h] [rbp-30h]
  float v27; // [rsp+9Ch] [rbp-1Ch]

  v4 = texgen;
  v5 = tex;
  v6 = context;
  v7 = this;
  v8 = 1;
  v9 = &v22;
  do
  {
    memset(v9 - 10, 0, 0x40ui64);
    --v8;
    *(v9 - 10) = 1.0;
    *(v9 - 5) = 1.0;
    *v9 = 1.0;
    v9[5] = 1.0;
    v9 += 16;
  }
  while ( v8 >= 0 );
  v10 = v6->pHAL;
  v11 = 256;
  v12 = 256;
  if ( v7->RedMultiplier < 0x100 )
    v12 = v7->RedMultiplier;
  v13 = (float)v12;
  v14 = 256;
  if ( v7->GreenMultiplier < 0x100 )
    v14 = v7->GreenMultiplier;
  v15 = (float)v14;
  v16 = 256;
  if ( v7->BlueMultiplier < 0x100 )
    v16 = v7->BlueMultiplier;
  v17 = v13 * 0.00390625;
  if ( v7->AlphaMultiplier < 0x100 )
    v11 = v7->AlphaMultiplier;
  v24 = v17;
  v25 = v15 * 0.00390625;
  v18 = (float)v16 * 0.00390625;
  v19 = v7->pImage.pObject;
  v26 = v18;
  v27 = (float)v11 * 0.00390625;
  v20 = 1.0 - v17;
  v21 = 1.0 - (float)(v15 * 0.00390625);
  v22 = 1.0 - v18;
  v23 = 1.0 - v27;
  Scaleform::Render::HAL::applyBlendMode(v10, (Scaleform::Render::BlendMode)((v19->Transparent != 0) + 15), 1, 1);
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, float *))v6->pHAL->vfptr[55].__vecDelDtor)(
    v6->pHAL,
    v5,
    v4,
    &v20);
}

// File Line: 351
// RVA: 0x973DB0
void __fastcall Scaleform::Render::DICommand_PaletteMap::ExecuteHWCopyAction(Scaleform::Render::DICommand_PaletteMap *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::Texture **tex, Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DICommandVtbl *v4; // rax
  Scaleform::Render::Matrix2x4<float> *v5; // rdi
  Scaleform::Render::Texture **v6; // rsi
  Scaleform::Render::DICommandContext *v7; // r14
  Scaleform::Render::DICommand_PaletteMap *v8; // rbx
  signed int *v9; // rax
  Scaleform::Render::DrawableImage *v10; // rcx
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  signed int *v13; // rax
  float v14; // xmm6_4
  float v15; // xmm7_4
  signed int *v16; // rax
  signed int v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm4_4
  unsigned int v20; // ST20_4
  __m128 v21; // [rsp+30h] [rbp-40h]
  __m128 v22; // [rsp+40h] [rbp-30h]
  char v23; // [rsp+90h] [rbp+20h]
  char v24; // [rsp+98h] [rbp+28h]

  v4 = this->vfptr;
  v5 = texgen;
  v6 = tex;
  v7 = context;
  v8 = this;
  v21 = (__m128)_xmm;
  v22 = _xmm;
  if ( ((unsigned __int8 (*)(void))v4[1].GetCPUCaps)() )
  {
    v21 = (__m128)_xmm_bf800000000000000000000040000000;
    v22 = (__m128)_xmm;
  }
  else
  {
    v9 = (signed int *)v8->pImage.pObject->vfptr[5].__vecDelDtor(
                         (Scaleform::RefCountImplCore *)&v8->pImage.pObject->vfptr,
                         (unsigned int)&v23);
    v10 = v8->pImage.pObject;
    v11 = (__m128)COERCE_UNSIGNED_INT((float)(v8->SourceRect.x2 - v8->SourceRect.x1));
    v12 = (__m128)COERCE_UNSIGNED_INT((float)(v8->SourceRect.y2 - v8->SourceRect.y1));
    v11.m128_f32[0] = v11.m128_f32[0] / (float)*v9;
    v12.m128_f32[0] = v12.m128_f32[0] / (float)v9[1];
    v21 = _mm_mul_ps(v21, _mm_shuffle_ps(v11, v11, 0));
    v22 = _mm_mul_ps(v22, _mm_shuffle_ps(v12, v12, 0));
    v13 = (signed int *)v10->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, (unsigned int)&v23);
    v14 = (float)*v13;
    v15 = (float)v13[1];
    v16 = (signed int *)v8->pImage.pObject->vfptr[5].__vecDelDtor(
                          (Scaleform::RefCountImplCore *)&v8->pImage.pObject->vfptr,
                          (unsigned int)&v24);
    v17 = *v16;
    v18 = (float)v8->DestPoint.x;
    v19 = v22.m128_f32[3] + (float)((float)((float)v8->DestPoint.y - (float)((float)v16[1] * 0.5)) / v15);
    v21.m128_f32[0] = v21.m128_f32[0] * 2.0;
    v21.m128_f32[2] = v21.m128_f32[2] * 2.0;
    v21.m128_f32[3] = (float)(v21.m128_f32[3] + (float)((float)(v18 - (float)((float)v17 * 0.5)) / v14)) * 2.0;
    v21.m128_f32[1] = v21.m128_f32[1] * 2.0;
    v22.m128_f32[0] = v22.m128_f32[0] * -2.0;
    v22.m128_f32[1] = v22.m128_f32[1] * -2.0;
    v22.m128_f32[3] = v19 * -2.0;
    v22.m128_f32[2] = v22.m128_f32[2] * -2.0;
  }
  v20 = v8->ChannelMask;
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture **, Scaleform::Render::Matrix2x4<float> *, __m128 *, unsigned int, unsigned int *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))v7->pHAL->vfptr[57].__vecDelDtor)(
    v7->pHAL,
    v6,
    v5,
    &v21,
    v20,
    v8->Channels,
    v21.m128_u64[0],
    v21.m128_u64[1],
    v22.m128_u64[0],
    v22.m128_u64[1]);
}

// File Line: 373
// RVA: 0x973FC0
void __usercall Scaleform::Render::DICommand_Scroll::ExecuteHWCopyAction(Scaleform::Render::DICommand_Scroll *this@<rcx>, Scaleform::Render::DICommandContext *context@<rdx>, Scaleform::Render::Texture **tex@<r8>, Scaleform::Render::Matrix2x4<float> *texgen@<r9>, float a5@<xmm0>)
{
  Scaleform::Render::DICommand_Scroll *v5; // rbx
  Scaleform::Render::Matrix2x4<float> *v6; // rsi
  Scaleform::Render::Texture **v7; // r14
  Scaleform::Render::DICommandContext *v8; // rdi
  Scaleform::Render::DrawableImage *v9; // rax
  Scaleform::Render::HAL *v10; // rcx
  signed int v11; // ST20_4
  __int128 v12; // [rsp+30h] [rbp-28h]
  float v13; // [rsp+40h] [rbp-18h]
  float v14; // [rsp+44h] [rbp-14h]
  int v15; // [rsp+48h] [rbp-10h]
  float v16; // [rsp+4Ch] [rbp-Ch]

  v5 = this;
  v6 = texgen;
  v7 = tex;
  v8 = context;
  ((void (*)(void))context->pHAL->vfptr[71].__vecDelDtor)();
  v9 = v5->pImage.pObject;
  v10 = v8->pHAL;
  v15 = 0;
  v14 = a5 * 2.0;
  v12 = _xmm_bf800000000000000000000040000000;
  v13 = (float)(a5 * 2.0) * 0.0;
  v16 = (float)(a5 * 2.0) * -0.5;
  Scaleform::Render::HAL::applyBlendMode(v10, (Scaleform::Render::BlendMode)((v9->Transparent != 0) + 15), 1, 1);
  v11 = -1;
  ((void (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture *, __int128 *, Scaleform::Render::Matrix2x4<float> *, signed int))v8->pHAL->vfptr[58].__vecDelDtor)(
    v8->pHAL,
    *v7,
    &v12,
    &v6[1],
    v11);
}

