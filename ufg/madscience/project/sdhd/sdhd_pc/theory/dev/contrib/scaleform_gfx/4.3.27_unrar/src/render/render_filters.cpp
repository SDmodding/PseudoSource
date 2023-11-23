// File Line: 24
// RVA: 0x95DB70
bool __fastcall Scaleform::Render::BlurFilterImpl::CanCacheAcrossTransform(
        Scaleform::Render::DisplacementMapFilter *this,
        bool __formal,
        bool a3,
        bool deltaScale)
{
  return !deltaScale;
}

// File Line: 32
// RVA: 0x9606D0
Scaleform::Render::BlurFilterImpl *__fastcall Scaleform::Render::BlurFilter::Clone(
        Scaleform::Render::BlurFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::BlurFilterImpl *v4; // rax
  Scaleform::Render::BlurFilterImpl *v5; // rbx

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::BlurFilterImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                              v2,
                                              80i64);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(v4, Filter_Blur, &this->Params);
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilter::`vftable;
  return v5;
}

// File Line: 39
// RVA: 0x997520
bool __fastcall Scaleform::Render::BlurFilter::IsContributing(Scaleform::Render::BlurFilter *this)
{
  return (this->Params.BlurX > 20.0 || this->Params.BlurY > 20.0) && this->Params.Passes;
}

// File Line: 46
// RVA: 0x960C50
void __fastcall Scaleform::Render::ShadowFilter::Clone(
        Scaleform::Render::ShadowFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::ShadowFilter *v4; // rax

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::ShadowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                            v2,
                                            80i64);
  if ( v4 )
    Scaleform::Render::ShadowFilter::ShadowFilter(v4, &this->Params, this->Angle, this->Distance * 0.050000001);
}

// File Line: 66
// RVA: 0x960B30
Scaleform::Render::BlurFilterImpl *__fastcall Scaleform::Render::GlowFilter::Clone(
        Scaleform::Render::GlowFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::BlurFilterImpl *v4; // rax
  Scaleform::Render::BlurFilterImpl *v5; // rbx

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::BlurFilterImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                              v2,
                                              80i64);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(v4, Filter_Glow, &this->Params);
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlowFilter::`vftable;
  return v5;
}

// File Line: 73
// RVA: 0x997610
bool __fastcall Scaleform::Render::ShadowFilter::IsContributing(Scaleform::Render::ShadowFilter *this)
{
  return this->Params.Colors[0].Channels.Alpha && this->Params.Passes;
}

// File Line: 80
// RVA: 0x960650
void __fastcall Scaleform::Render::BevelFilter::Clone(
        Scaleform::Render::BevelFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::BevelFilter *v4; // rax

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::BevelFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                           v2,
                                           80i64);
  if ( v4 )
    Scaleform::Render::BevelFilter::BevelFilter(v4, &this->Params, this->Angle, this->Distance * 0.050000001);
}

// File Line: 87
// RVA: 0x997500
bool __fastcall Scaleform::Render::BevelFilter::IsContributing(Scaleform::Render::BevelFilter *this)
{
  return (this->Params.Colors[0].Channels.Alpha || this->Params.Colors[1].Channels.Alpha) && this->Params.Passes;
}

// File Line: 93
// RVA: 0x95DC10
bool __fastcall Scaleform::Render::ShadowFilter::CanCacheAcrossTransform(
        Scaleform::Render::ShadowFilter *this,
        bool deltaTrans,
        bool deltaRot,
        bool deltaScale)
{
  return !deltaRot && !deltaScale;
}

// File Line: 103
// RVA: 0x93CFE0
void __fastcall Scaleform::Render::GradientFilter::GradientFilter(
        Scaleform::Render::GradientFilter *this,
        Scaleform::Render::FilterType type,
        Scaleform::Render::GradientData *gradient,
        float dist,
        float angle,
        float blurx,
        float blury,
        unsigned int passes)
{
  float v10; // xmm7_4
  Scaleform::Render::GradientData *pObject; // rcx

  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, type);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientFilter::`vftable;
  this->GradientImage.pObject = 0i64;
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
  this->Angle = angle;
  this->Distance = dist * 20.0;
  v10 = sinf(angle) * (float)(dist * 20.0);
  this->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  this->Params.Offset.y = v10;
  this->Params.Strength = 1.0;
  if ( gradient )
    _InterlockedExchangeAdd(&gradient->RefCount, 1u);
  pObject = this->Params.Gradient.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->Params.Gradient.pObject = gradient;
}

// File Line: 116
// RVA: 0x93CF40
void __fastcall Scaleform::Render::GradientFilter::GradientFilter(
        Scaleform::Render::GradientFilter *this,
        Scaleform::Render::FilterType type,
        Scaleform::Render::BlurFilterParams *params,
        float angle,
        float dist)
{
  float v6; // xmm6_4

  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, type, params);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientFilter::`vftable;
  this->GradientImage.pObject = 0i64;
  this->Angle = angle;
  this->Distance = dist * 20.0;
  v6 = sinf(angle) * (float)(dist * 20.0);
  this->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  this->Params.Offset.y = v6;
}

// File Line: 121
// RVA: 0x960BC0
void __fastcall Scaleform::Render::GradientFilter::Clone(
        Scaleform::Render::GradientFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::GradientFilter *v4; // rax

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::GradientFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                              v2,
                                              88i64);
  if ( v4 )
    Scaleform::Render::GradientFilter::GradientFilter(
      v4,
      this->Type,
      &this->Params,
      this->Angle,
      this->Distance * 0.050000001);
}

// File Line: 128
// RVA: 0x9975F0
bool __fastcall Scaleform::Render::GradientFilter::IsContributing(Scaleform::Render::GradientFilter *this)
{
  return this->Params.Passes && this->Params.Gradient.pObject;
}

// File Line: 156
// RVA: 0x9396E0
void __fastcall Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(Scaleform::Render::ColorMatrixFilter *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = Filter_ColorMatrix;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ColorMatrixFilter::`vftable;
  *(_OWORD *)this->MatrixData = *(_OWORD *)ColorMatrix_Identity;
  *(_OWORD *)&this->MatrixData[4] = xmmword_1420BB580;
  *(_OWORD *)&this->MatrixData[8] = xmmword_1420BB590;
  *(_OWORD *)&this->MatrixData[12] = xmmword_1420BB5A0;
  *(_OWORD *)&this->MatrixData[16] = xmmword_1420BB5B0;
}

// File Line: 164
// RVA: 0x997540
bool __fastcall Scaleform::Render::ColorMatrixFilter::IsContributing(Scaleform::Render::ColorMatrixFilter *this)
{
  return memcmp(this->MatrixData, ColorMatrix_Identity, 0x50ui64) != 0;
}

// File Line: 169
// RVA: 0x960810
Scaleform::Render::Filter *__fastcall Scaleform::Render::ColorMatrixFilter::Clone(
        Scaleform::Render::ColorMatrixFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::ColorMatrixFilter *v4; // rax
  float *v5; // rax
  float *v6; // rcx

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::ColorMatrixFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                                 v2,
                                                 104i64);
  if ( v4 )
  {
    Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    v6[6] = this->MatrixData[0];
    v6[7] = this->MatrixData[1];
    v6[8] = this->MatrixData[2];
    v6[9] = this->MatrixData[3];
    v6[10] = this->MatrixData[4];
    v6[11] = this->MatrixData[5];
    v6[12] = this->MatrixData[6];
    v6[13] = this->MatrixData[7];
    v6[14] = this->MatrixData[8];
    v6[15] = this->MatrixData[9];
    v6[16] = this->MatrixData[10];
    v6[17] = this->MatrixData[11];
    v6[18] = this->MatrixData[12];
    v6[19] = this->MatrixData[13];
    v6[20] = this->MatrixData[14];
    v6[21] = this->MatrixData[15];
    v6[22] = this->MatrixData[16];
    v6[23] = this->MatrixData[17];
    v6[24] = this->MatrixData[18];
    v6[25] = this->MatrixData[19];
  }
  return (Scaleform::Render::Filter *)v6;
}

// File Line: 184
// RVA: 0x960760
Scaleform::Render::Filter *__fastcall Scaleform::Render::CacheAsBitmapFilter::Clone(
        Scaleform::Render::CacheAsBitmapFilter *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::Filter *result; // rax

  v2 = pheap;
  if ( !pheap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  result = (Scaleform::Render::Filter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                          v2,
                                          24i64);
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  result->RefCount = 1;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  result->Type = Filter_CacheAsBitmap;
  result->Frozen = 0;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::CacheAsBitmapFilter::`vftable;
  return result;
}

// File Line: 205
// RVA: 0x93B030
void __fastcall Scaleform::Render::DisplacementMapFilter::DisplacementMapFilter(
        Scaleform::Render::DisplacementMapFilter *this,
        Scaleform::Render::Image *mapBitmap,
        Scaleform::Render::Point<float> mapPoint,
        Scaleform::Render::DrawableImage::ChannelBits compx,
        Scaleform::Render::DrawableImage::ChannelBits compy,
        Scaleform::Render::DisplacementMapFilter::DisplacementMode mode,
        float scaleX,
        float scaleY,
        unsigned int *color)
{
  float v13; // xmm0_4

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = Filter_DisplacementMap;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DisplacementMapFilter::`vftable;
  if ( mapBitmap )
    ((void (__fastcall *)(Scaleform::Render::Image *))mapBitmap->vfptr[1].__vecDelDtor)(mapBitmap);
  this->DisplacementMap.pObject = mapBitmap;
  v13 = *(float *)(*(_QWORD *)&mapPoint + 4i64);
  this->MapPoint.x = **(float **)&mapPoint;
  this->MapPoint.y = v13;
  this->ComponentX = compx;
  this->ComponentY = compy;
  this->Mode = mode;
  this->ScaleX = scaleX;
  this->ScaleY = scaleY;
  this->ColorValue.Raw = *color;
}

// File Line: 210
// RVA: 0x997570
_BOOL8 __fastcall SSUnaryParam::is_defaultable(SSUnaryParam *this)
{
  return this->i_default_p != 0i64;
}

// File Line: 215
// RVA: 0x960900
void __fastcall Scaleform::Render::DisplacementMapFilter::Clone(
        Scaleform::Render::DisplacementMapFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::DisplacementMapFilter *v4; // r10
  float y; // xmm1_4
  Scaleform::Render::Color color; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::Render::Point<float> mapPoint; // [rsp+88h] [rbp+20h] BYREF

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = (Scaleform::Render::DisplacementMapFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v2->vfptr->Alloc)(
                                                     v2,
                                                     64i64);
  if ( v4 )
  {
    color = (Scaleform::Render::Color)this->ColorValue.Raw;
    y = this->MapPoint.y;
    mapPoint.x = this->MapPoint.x;
    mapPoint.y = y;
    Scaleform::Render::DisplacementMapFilter::DisplacementMapFilter(
      v4,
      this->DisplacementMap.pObject,
      (Scaleform::Render::Point<float>)&mapPoint,
      this->ComponentX,
      this->ComponentY,
      this->Mode,
      this->ScaleX,
      this->ScaleY,
      (unsigned int *)&color);
  }
}

// File Line: 226
// RVA: 0x93BF00
void __fastcall Scaleform::Render::FilterSet::FilterSet(
        Scaleform::Render::FilterSet *this,
        Scaleform::Render::Filter *filter)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::FilterSet,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable;
  this->Filters.Data.Data = 0i64;
  this->Filters.Data.Size = 0i64;
  this->Filters.Data.Policy.Capacity = 0i64;
  *(_WORD *)&this->Frozen = 0;
  this->pCacheAsBitmapFilter.pObject = 0i64;
  if ( filter )
    Scaleform::Render::FilterSet::AddFilter(this, filter);
}

// File Line: 231
// RVA: 0x94A390
void __fastcall Scaleform::Render::FilterSet::~FilterSet(Scaleform::Render::FilterSet *this)
{
  Scaleform::Render::CacheAsBitmapFilter *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable;
  pObject = this->pCacheAsBitmapFilter.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>(&this->Filters.Data);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 252
// RVA: 0x9841A0
Scaleform::Render::Filter *__fastcall Scaleform::Render::FilterSet::GetFilter(
        Scaleform::Render::FilterSet *this,
        unsigned __int64 index)
{
  return this->Filters.Data.Data[index].pObject;
}

// File Line: 265
// RVA: 0x9541B0
void __fastcall Scaleform::Render::FilterSet::AddFilter(
        Scaleform::Render::FilterSet *this,
        Scaleform::Render::Filter *filter)
{
  Scaleform::Ptr<Scaleform::Render::Filter> *Data; // rbx
  Scaleform::Render::Filter *pObject; // rcx
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *p_Filters; // rbx
  Scaleform::Ptr<Scaleform::Render::Filter> *v6; // rdx

  if ( this->Filters.Data.Size == 1 && (Data = this->Filters.Data.Data, Data->pObject->Type == Filter_CacheAsBitmap) )
  {
    if ( filter )
      _InterlockedExchangeAdd(&filter->RefCount, 1u);
    pObject = Data->pObject;
    if ( Data->pObject && !_InterlockedDecrement(&pObject->RefCount) )
    {
      if ( pObject )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
    }
    Data->pObject = filter;
  }
  else
  {
    if ( filter )
      _InterlockedExchangeAdd(&filter->RefCount, 1u);
    p_Filters = &this->Filters;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Filters.Data,
      &this->Filters,
      this->Filters.Data.Size + 1);
    v6 = &p_Filters->Data.Data[p_Filters->Data.Size - 1];
    if ( v6 )
    {
      if ( filter )
        _InterlockedExchangeAdd(&filter->RefCount, 1u);
      v6->pObject = filter;
    }
    if ( filter && !_InterlockedDecrement(&filter->RefCount) )
      filter->vfptr->__vecDelDtor(filter, 1i64);
  }
}

// File Line: 318
// RVA: 0x980A50
_BOOL8 __fastcall Scaleform::Render::FilterSet::GetCacheAsBitmap(Scaleform::Render::FilterSet *this)
{
  return this->CacheAsBitmap;
}

// File Line: 323
// RVA: 0x9AE8E0
void __fastcall Scaleform::Render::FilterSet::SetCacheAsBitmap(Scaleform::Render::FilterSet *this, bool enable)
{
  __int64 v3; // rdi
  Scaleform::Render::CacheAsBitmapFilter *pObject; // rcx
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *p_Filters; // rcx

  this->CacheAsBitmap = enable;
  if ( enable )
  {
    if ( !LODWORD(this->Filters.Data.Size) )
    {
      if ( !this->pCacheAsBitmapFilter.pObject )
      {
        v3 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
               Scaleform::Memory::pGlobalHeap,
               24i64);
        if ( v3 )
        {
          *(_QWORD *)v3 = &Scaleform::RefCountImplCore::`vftable;
          *(_DWORD *)(v3 + 8) = 1;
          *(_QWORD *)v3 = &Scaleform::RefCountImpl::`vftable;
          *(_QWORD *)v3 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
          *(_QWORD *)v3 = &Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
          *(_QWORD *)v3 = &Scaleform::Render::Filter::`vftable;
          *(_DWORD *)(v3 + 16) = 11;
          *(_BYTE *)(v3 + 20) = 0;
          *(_QWORD *)v3 = &Scaleform::Render::CacheAsBitmapFilter::`vftable;
        }
        else
        {
          v3 = 0i64;
        }
        pObject = this->pCacheAsBitmapFilter.pObject;
        if ( pObject )
        {
          if ( !_InterlockedDecrement(&pObject->RefCount) )
            pObject->vfptr->__vecDelDtor(pObject, 1u);
        }
        this->pCacheAsBitmapFilter.pObject = (Scaleform::Render::CacheAsBitmapFilter *)v3;
      }
      Scaleform::Render::FilterSet::AddFilter(this, this->pCacheAsBitmapFilter.pObject);
    }
  }
  else if ( LODWORD(this->Filters.Data.Size) == 1 )
  {
    p_Filters = &this->Filters;
    if ( p_Filters->Data.Data->pObject->Type == Filter_CacheAsBitmap )
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        p_Filters,
        0i64);
  }
}

// File Line: 337
// RVA: 0x9609D0
Scaleform::Render::FilterSet *__fastcall Scaleform::Render::FilterSet::Clone(
        Scaleform::Render::FilterSet *this,
        bool deepCopy,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // r14
  __int64 v6; // rsi
  unsigned __int64 v7; // rbx
  Scaleform::Render::Filter *pObject; // rcx
  Scaleform::Render::Filter *v10; // rdi

  v3 = heap;
  if ( !heap )
    v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v6 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))v3->vfptr->Alloc)(v3, 56i64);
  if ( v6 )
  {
    *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v6 + 8) = 1;
    *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::Render::FilterSet,2>::`vftable;
    *(_QWORD *)v6 = &Scaleform::Render::FilterSet::`vftable;
    v7 = 0i64;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 24) = 0i64;
    *(_QWORD *)(v6 + 32) = 0i64;
    *(_WORD *)(v6 + 40) = 0;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  else
  {
    v7 = 0i64;
    v6 = 0i64;
  }
  if ( !v6 )
    return 0i64;
  *(_BYTE *)(v6 + 41) = this->CacheAsBitmap;
  if ( this->Filters.Data.Size )
  {
    do
    {
      if ( deepCopy )
      {
        pObject = this->Filters.Data.Data[v7].pObject;
        v10 = (Scaleform::Render::Filter *)pObject->vfptr[1].__vecDelDtor(pObject, (unsigned int)v3);
        Scaleform::Render::FilterSet::AddFilter((Scaleform::Render::FilterSet *)v6, v10);
        if ( v10 )
        {
          if ( !_InterlockedDecrement(&v10->RefCount) )
            v10->vfptr->__vecDelDtor(v10, 1u);
        }
      }
      else
      {
        Scaleform::Render::FilterSet::AddFilter((Scaleform::Render::FilterSet *)v6, this->Filters.Data.Data[v7].pObject);
      }
      ++v7;
    }
    while ( v7 < this->Filters.Data.Size );
  }
  return (Scaleform::Render::FilterSet *)v6;
}

// File Line: 364
// RVA: 0x997580
char __fastcall Scaleform::Render::FilterSet::IsContributing(Scaleform::Render::FilterSet *this)
{
  unsigned int v3; // ebx
  __int64 v4; // rcx
  Scaleform::Render::Filter *pObject; // rcx

  if ( this->CacheAsBitmap )
    return 1;
  v3 = 0;
  if ( !this->Filters.Data.Size )
    return 0;
  v4 = 0i64;
  while ( 1 )
  {
    pObject = this->Filters.Data.Data[v4].pObject;
    if ( pObject )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Filter *))pObject->vfptr[2].__vecDelDtor)(pObject) )
        break;
    }
    v4 = ++v3;
    if ( v3 >= this->Filters.Data.Size )
      return 0;
  }
  return 1;
}

// File Line: 382
// RVA: 0x95DB80
char __fastcall Scaleform::Render::FilterSet::CanCacheAcrossTransform(
        Scaleform::Render::FilterSet *this,
        bool deltaTrans,
        bool deltaRot,
        bool deltaScale)
{
  unsigned int v4; // ebx
  __int64 v9; // r10
  Scaleform::Render::Filter *pObject; // rcx

  v4 = 0;
  if ( !this->Filters.Data.Size )
    return 1;
  v9 = 0i64;
  while ( 1 )
  {
    pObject = this->Filters.Data.Data[v9].pObject;
    if ( pObject )
    {
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Filter *, bool, bool, bool))pObject->vfptr[3].__vecDelDtor)(
              pObject,
              deltaTrans,
              deltaRot,
              deltaScale) )
        break;
    }
    v9 = ++v4;
    if ( v4 >= this->Filters.Data.Size )
      return 1;
  }
  return 0;
}

