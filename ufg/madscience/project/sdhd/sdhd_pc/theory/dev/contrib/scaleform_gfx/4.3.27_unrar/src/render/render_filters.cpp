// File Line: 24
// RVA: 0x95DB70
bool __fastcall Scaleform::Render::BlurFilterImpl::CanCacheAcrossTransform(Scaleform::Render::DisplacementMapFilter *this, bool __formal, bool a3, bool deltaScale)
{
  return deltaScale == 0;
}

// File Line: 32
// RVA: 0x9606D0
Scaleform::Render::BlurFilterImpl *__fastcall Scaleform::Render::BlurFilter::Clone(Scaleform::Render::BlurFilter *this, Scaleform::MemoryHeap *heap, __int64 a3)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::Render::BlurFilter *v4; // rdi
  Scaleform::Render::BlurFilterImpl *v5; // rax
  Scaleform::Render::BlurFilterImpl *v6; // rbx

  v3 = heap;
  v4 = this;
  if ( !heap )
    v3 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::BlurFilter *, __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    this,
                                    a3,
                                    0i64,
                                    -2i64);
  v5 = (Scaleform::Render::BlurFilterImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(
                                              v3,
                                              80i64);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(v5, 0, &v4->Params);
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilter::`vftable';
  return v6;
}

// File Line: 39
// RVA: 0x997520
bool __fastcall Scaleform::Render::BlurFilter::IsContributing(Scaleform::Render::BlurFilter *this)
{
  return (this->Params.BlurX > 20.0 || this->Params.BlurY > 20.0) && this->Params.Passes;
}

// File Line: 46
// RVA: 0x960C50
void __fastcall Scaleform::Render::ShadowFilter::Clone(Scaleform::Render::ShadowFilter *this, Scaleform::MemoryHeap *heap, __int64 a3)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::Render::ShadowFilter *v4; // rbx
  Scaleform::Render::ShadowFilter *v5; // rax

  v3 = heap;
  v4 = this;
  if ( !heap )
    v3 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ShadowFilter *, __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    this,
                                    a3,
                                    0i64,
                                    -2i64);
  v5 = (Scaleform::Render::ShadowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(
                                            v3,
                                            80i64);
  if ( v5 )
    Scaleform::Render::ShadowFilter::ShadowFilter(v5, &v4->Params, v4->Angle, v4->Distance * 0.050000001);
}

// File Line: 66
// RVA: 0x960B30
Scaleform::Render::BlurFilterImpl *__fastcall Scaleform::Render::GlowFilter::Clone(Scaleform::Render::GlowFilter *this, Scaleform::MemoryHeap *heap, __int64 a3)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::Render::GlowFilter *v4; // rdi
  Scaleform::Render::BlurFilterImpl *v5; // rax
  Scaleform::Render::BlurFilterImpl *v6; // rbx

  v3 = heap;
  v4 = this;
  if ( !heap )
    v3 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::GlowFilter *, __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    this,
                                    a3,
                                    0i64,
                                    -2i64);
  v5 = (Scaleform::Render::BlurFilterImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(
                                              v3,
                                              80i64);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(v5, Filter_Glow, &v4->Params);
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlowFilter::`vftable';
  return v6;
}

// File Line: 73
// RVA: 0x997610
bool __fastcall Scaleform::Render::ShadowFilter::IsContributing(Scaleform::Render::ShadowFilter *this)
{
  return this->Params.Colors[0].Channels.Alpha && this->Params.Passes;
}

// File Line: 80
// RVA: 0x960650
void __fastcall Scaleform::Render::BevelFilter::Clone(Scaleform::Render::BevelFilter *this, Scaleform::MemoryHeap *heap, __int64 a3)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::Render::BevelFilter *v4; // rbx
  Scaleform::Render::BevelFilter *v5; // rax

  v3 = heap;
  v4 = this;
  if ( !heap )
    v3 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::BevelFilter *, __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    this,
                                    a3,
                                    0i64,
                                    -2i64);
  v5 = (Scaleform::Render::BevelFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(
                                           v3,
                                           80i64);
  if ( v5 )
    Scaleform::Render::BevelFilter::BevelFilter(v5, &v4->Params, v4->Angle, v4->Distance * 0.050000001);
}

// File Line: 87
// RVA: 0x997500
bool __fastcall Scaleform::Render::BevelFilter::IsContributing(Scaleform::Render::BevelFilter *this)
{
  return (this->Params.Colors[0].Channels.Alpha || this->Params.Colors[1].Channels.Alpha) && this->Params.Passes;
}

// File Line: 93
// RVA: 0x95DC10
bool __fastcall Scaleform::Render::ShadowFilter::CanCacheAcrossTransform(Scaleform::Render::ShadowFilter *this, bool deltaTrans, bool deltaRot, bool deltaScale)
{
  return !deltaRot && !deltaScale;
}

// File Line: 103
// RVA: 0x93CFE0
void __fastcall Scaleform::Render::GradientFilter::GradientFilter(Scaleform::Render::GradientFilter *this, Scaleform::Render::FilterType type, Scaleform::Render::GradientData *gradient, float dist, float angle, float blurx, float blury, unsigned int passes)
{
  Scaleform::Render::GradientData *v8; // rdi
  Scaleform::Render::GradientFilter *v9; // rbx
  float v10; // xmm7_4
  Scaleform::Render::GradientData *v11; // rcx

  v8 = gradient;
  v9 = this;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl((Scaleform::Render::BlurFilterImpl *)&this->vfptr, type);
  v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientFilter::`vftable';
  v9->GradientImage.pObject = 0i64;
  v9->Params.BlurX = blurx * 20.0;
  v9->Params.BlurY = blury * 20.0;
  v9->Params.Passes = passes;
  v9->Angle = angle;
  v9->Distance = dist * 20.0;
  v10 = sinf(angle) * (float)(dist * 20.0);
  v9->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  v9->Params.Offset.y = v10;
  v9->Params.Strength = 1.0;
  if ( v8 )
    _InterlockedExchangeAdd(&v8->RefCount, 1u);
  v11 = v9->Params.Gradient.pObject;
  if ( v11 && !_InterlockedDecrement(&v11->RefCount) && v11 )
    v11->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, 1u);
  v9->Params.Gradient.pObject = v8;
}

// File Line: 116
// RVA: 0x93CF40
void __fastcall Scaleform::Render::GradientFilter::GradientFilter(Scaleform::Render::GradientFilter *this, Scaleform::Render::FilterType type, Scaleform::Render::BlurFilterParams *params, float angle, float dist)
{
  Scaleform::Render::GradientFilter *v5; // rbx
  float v6; // xmm6_4

  v5 = this;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl((Scaleform::Render::BlurFilterImpl *)&this->vfptr, type, params);
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GradientFilter::`vftable';
  v5->GradientImage.pObject = 0i64;
  v5->Angle = angle;
  v5->Distance = dist * 20.0;
  v6 = sinf(angle) * (float)(dist * 20.0);
  v5->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  v5->Params.Offset.y = v6;
}

// File Line: 121
// RVA: 0x960BC0
void __fastcall Scaleform::Render::GradientFilter::Clone(Scaleform::Render::GradientFilter *this, Scaleform::MemoryHeap *heap, __int64 a3)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::Render::GradientFilter *v4; // rbx
  Scaleform::Render::GradientFilter *v5; // rax

  v3 = heap;
  v4 = this;
  if ( !heap )
    v3 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::GradientFilter *, __int64, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    this,
                                    a3,
                                    0i64);
  v5 = (Scaleform::Render::GradientFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(
                                              v3,
                                              88i64);
  if ( v5 )
    Scaleform::Render::GradientFilter::GradientFilter(v5, v4->Type, &v4->Params, v4->Angle, v4->Distance * 0.050000001);
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
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = 8;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ColorMatrixFilter::`vftable';
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
Scaleform::Render::Filter *__fastcall Scaleform::Render::ColorMatrixFilter::Clone(Scaleform::Render::ColorMatrixFilter *this, Scaleform::MemoryHeap *heap, __int64 a3)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::Render::ColorMatrixFilter *v4; // rbx
  Scaleform::Render::ColorMatrixFilter *v5; // rax
  _DWORD *v6; // rax
  _DWORD *v7; // rcx

  v3 = heap;
  v4 = this;
  if ( !heap )
    v3 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ColorMatrixFilter *, __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    this,
                                    a3,
                                    0i64,
                                    -2i64);
  v5 = (Scaleform::Render::ColorMatrixFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(
                                                 v3,
                                                 104i64);
  if ( v5 )
  {
    Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  if ( v7 )
  {
    v7[6] = LODWORD(v4->MatrixData[0]);
    v7[7] = LODWORD(v4->MatrixData[1]);
    v7[8] = LODWORD(v4->MatrixData[2]);
    v7[9] = LODWORD(v4->MatrixData[3]);
    v7[10] = LODWORD(v4->MatrixData[4]);
    v7[11] = LODWORD(v4->MatrixData[5]);
    v7[12] = LODWORD(v4->MatrixData[6]);
    v7[13] = LODWORD(v4->MatrixData[7]);
    v7[14] = LODWORD(v4->MatrixData[8]);
    v7[15] = LODWORD(v4->MatrixData[9]);
    v7[16] = LODWORD(v4->MatrixData[10]);
    v7[17] = LODWORD(v4->MatrixData[11]);
    v7[18] = LODWORD(v4->MatrixData[12]);
    v7[19] = LODWORD(v4->MatrixData[13]);
    v7[20] = LODWORD(v4->MatrixData[14]);
    v7[21] = LODWORD(v4->MatrixData[15]);
    v7[22] = LODWORD(v4->MatrixData[16]);
    v7[23] = LODWORD(v4->MatrixData[17]);
    v7[24] = LODWORD(v4->MatrixData[18]);
    v7[25] = LODWORD(v4->MatrixData[19]);
  }
  return (Scaleform::Render::Filter *)v7;
}

// File Line: 184
// RVA: 0x960760
Scaleform::Render::Filter *__fastcall Scaleform::Render::CacheAsBitmapFilter::Clone(Scaleform::Render::CacheAsBitmapFilter *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::Render::Filter *result; // rax

  v2 = pheap;
  if ( !pheap )
    v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  result = (Scaleform::Render::Filter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v2->vfptr->Alloc)(
                                          v2,
                                          24i64);
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  result->RefCount = 1;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  result->Type = 11;
  result->Frozen = 0;
  result->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::CacheAsBitmapFilter::`vftable';
  return result;
}

// File Line: 205
// RVA: 0x93B030
void __fastcall Scaleform::Render::DisplacementMapFilter::DisplacementMapFilter(Scaleform::Render::DisplacementMapFilter *this, Scaleform::Render::Image *mapBitmap, Scaleform::Render::Point<float> mapPoint, Scaleform::Render::DrawableImage::ChannelBits compx, Scaleform::Render::DrawableImage::ChannelBits compy, Scaleform::Render::DisplacementMapFilter::DisplacementMode mode, float scaleX, float scaleY, __int64 color)
{
  Scaleform::Render::DrawableImage::ChannelBits v9; // ebp
  float *v10; // rsi
  Scaleform::Render::Image *v11; // rdi
  Scaleform::Render::DisplacementMapFilter *v12; // rbx
  float v13; // xmm0_4

  v9 = compx;
  v10 = (float *)mapPoint;
  v11 = mapBitmap;
  v12 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = 10;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DisplacementMapFilter::`vftable';
  if ( mapBitmap )
    ((void (__fastcall *)(Scaleform::Render::Image *))mapBitmap->vfptr[1].__vecDelDtor)(mapBitmap);
  v12->DisplacementMap.pObject = v11;
  v13 = v10[1];
  v12->MapPoint.x = *v10;
  v12->MapPoint.y = v13;
  v12->ComponentX = v9;
  v12->ComponentY = compy;
  v12->Mode = mode;
  v12->ScaleX = scaleX;
  v12->ScaleY = scaleY;
  v12->ColorValue.Raw = *(_DWORD *)color;
}

// File Line: 210
// RVA: 0x997570
_BOOL8 __fastcall SSUnaryParam::is_defaultable(SSUnaryParam *this)
{
  return this->i_default_p != 0i64;
}

// File Line: 215
// RVA: 0x960900
void __fastcall Scaleform::Render::DisplacementMapFilter::Clone(Scaleform::Render::DisplacementMapFilter *this, Scaleform::MemoryHeap *heap, __int64 a3)
{
  Scaleform::MemoryHeap *v3; // r9
  Scaleform::Render::DisplacementMapFilter *v4; // rbx
  Scaleform::Render::DisplacementMapFilter *v5; // r10
  float v6; // xmm1_4
  Scaleform::Render::Color color; // [rsp+80h] [rbp+18h]
  Scaleform::Render::Point<float> mapPoint; // [rsp+88h] [rbp+20h]

  v3 = heap;
  v4 = this;
  if ( !heap )
    v3 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::DisplacementMapFilter *, __int64, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    this,
                                    a3,
                                    0i64);
  v5 = (Scaleform::Render::DisplacementMapFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(
                                                     v3,
                                                     64i64);
  if ( v5 )
  {
    color = (Scaleform::Render::Color)v4->ColorValue.Raw;
    v6 = v4->MapPoint.y;
    mapPoint.x = v4->MapPoint.x;
    mapPoint.y = v6;
    Scaleform::Render::DisplacementMapFilter::DisplacementMapFilter(
      v5,
      v4->DisplacementMap.pObject,
      (Scaleform::Render::Point<float>)&mapPoint,
      v4->ComponentX,
      v4->ComponentY,
      v4->Mode,
      v4->ScaleX,
      v4->ScaleY,
      (__int64)&color);
  }
}

// File Line: 226
// RVA: 0x93BF00
void __fastcall Scaleform::Render::FilterSet::FilterSet(Scaleform::Render::FilterSet *this, Scaleform::Render::Filter *filter)
{
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v2; // [rsp+48h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::FilterSet,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable';
  v2 = &this->Filters;
  *(_OWORD *)&v2->Data.Data = 0ui64;
  v2->Data.Policy.Capacity = 0i64;
  *(_WORD *)&this->Frozen = 0;
  this->pCacheAsBitmapFilter.pObject = 0i64;
  if ( filter )
    Scaleform::Render::FilterSet::AddFilter(this, filter);
}

// File Line: 231
// RVA: 0x94A390
void __fastcall Scaleform::Render::FilterSet::~FilterSet(Scaleform::Render::FilterSet *this)
{
  Scaleform::Render::FilterSet *v1; // rbx
  Scaleform::Render::CacheAsBitmapFilter *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FilterSet::`vftable';
  v2 = this->pCacheAsBitmapFilter.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->Filters.Data.Data);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 252
// RVA: 0x9841A0
Scaleform::Render::Filter *__fastcall Scaleform::Render::FilterSet::GetFilter(Scaleform::Render::FilterSet *this, unsigned __int64 index)
{
  return this->Filters.Data.Data[index].pObject;
}

// File Line: 265
// RVA: 0x9541B0
void __fastcall Scaleform::Render::FilterSet::AddFilter(Scaleform::Render::FilterSet *this, Scaleform::Render::Filter *filter)
{
  Scaleform::Render::Filter *v2; // rdi
  Scaleform::Ptr<Scaleform::Render::Filter> *v3; // rbx
  Scaleform::Render::Filter *v4; // rcx
  Scaleform::Array<Scaleform::Ptr<Scaleform::Render::Filter>,2,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  Scaleform::Render::Filter **v6; // rdx

  v2 = filter;
  if ( this->Filters.Data.Size != 1 || (v3 = this->Filters.Data.Data, v3->pObject->Type != 11) )
  {
    if ( filter )
      _InterlockedExchangeAdd(&filter->RefCount, 1u);
    v5 = &this->Filters;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Filters.Data.Data,
      &this->Filters,
      this->Filters.Data.Size + 1);
    v6 = &v5->Data.Data[v5->Data.Size - 1].pObject;
    if ( v6 )
    {
      if ( v2 )
        _InterlockedExchangeAdd(&v2->RefCount, 1u);
      *v6 = v2;
    }
    if ( v2 && !_InterlockedDecrement(&v2->RefCount) )
      v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  }
  else
  {
    if ( filter )
      _InterlockedExchangeAdd(&filter->RefCount, 1u);
    v4 = v3->pObject;
    if ( v3->pObject && !_InterlockedDecrement(&v4->RefCount) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    }
    v3->pObject = v2;
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
  Scaleform::Render::FilterSet *v2; // rbx
  __int64 v3; // rdi
  Scaleform::Render::CacheAsBitmapFilter *v4; // rcx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy> > *v5; // rcx

  v2 = this;
  this->CacheAsBitmap = enable;
  if ( enable )
  {
    if ( !LODWORD(this->Filters.Data.Size) )
    {
      if ( !this->pCacheAsBitmapFilter.pObject )
      {
        v3 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
               Scaleform::Memory::pGlobalHeap,
               24i64);
        if ( v3 )
        {
          *(_QWORD *)v3 = &Scaleform::RefCountImplCore::`vftable';
          *(_DWORD *)(v3 + 8) = 1;
          *(_QWORD *)v3 = &Scaleform::RefCountImpl::`vftable';
          *(_QWORD *)v3 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
          *(_QWORD *)v3 = &Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
          *(_QWORD *)v3 = &Scaleform::Render::Filter::`vftable';
          *(_DWORD *)(v3 + 16) = 11;
          *(_BYTE *)(v3 + 20) = 0;
          *(_QWORD *)v3 = &Scaleform::Render::CacheAsBitmapFilter::`vftable';
        }
        else
        {
          v3 = 0i64;
        }
        v4 = v2->pCacheAsBitmapFilter.pObject;
        if ( v4 && !_InterlockedDecrement(&v4->RefCount) )
        {
          if ( v4 )
            v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
        }
        v2->pCacheAsBitmapFilter.pObject = (Scaleform::Render::CacheAsBitmapFilter *)v3;
      }
      Scaleform::Render::FilterSet::AddFilter(v2, (Scaleform::Render::Filter *)&v2->pCacheAsBitmapFilter.pObject->vfptr);
    }
  }
  else if ( LODWORD(this->Filters.Data.Size) == 1 )
  {
    v5 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Filters.Data;
    if ( v5->Data.Data->pObject->Type == 11 )
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        v5,
        0i64);
  }
}

// File Line: 337
// RVA: 0x9609D0
Scaleform::Render::FilterSet *__fastcall Scaleform::Render::FilterSet::Clone(Scaleform::Render::FilterSet *this, bool deepCopy, Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v3; // r14
  bool v4; // r15
  Scaleform::Render::FilterSet *v5; // rbp
  __int64 v6; // rsi
  _QWORD *v7; // ST28_8
  unsigned __int64 v8; // rbx
  Scaleform::Render::Filter *v10; // rcx
  Scaleform::Render::Filter *v11; // rdi

  v3 = heap;
  v4 = deepCopy;
  v5 = this;
  if ( !heap )
    v3 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v6 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->vfptr->Alloc)(v3, 56i64);
  if ( v6 )
  {
    *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v6 + 8) = 1;
    *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::Render::FilterSet,2>::`vftable';
    *(_QWORD *)v6 = &Scaleform::Render::FilterSet::`vftable';
    v7 = (_QWORD *)(v6 + 16);
    v8 = 0i64;
    *v7 = 0i64;
    v7[1] = 0i64;
    v7[2] = 0i64;
    *(_WORD *)(v6 + 40) = 0;
    *(_QWORD *)(v6 + 48) = 0i64;
  }
  else
  {
    v8 = 0i64;
    v6 = 0i64;
  }
  if ( !v6 )
    return 0i64;
  *(_BYTE *)(v6 + 41) = v5->CacheAsBitmap;
  if ( v5->Filters.Data.Size )
  {
    do
    {
      if ( v4 )
      {
        v10 = v5->Filters.Data.Data[v8].pObject;
        v11 = (Scaleform::Render::Filter *)v10->vfptr[1].__vecDelDtor(
                                             (Scaleform::RefCountImplCore *)&v10->vfptr,
                                             (unsigned int)v3);
        Scaleform::Render::FilterSet::AddFilter((Scaleform::Render::FilterSet *)v6, v11);
        if ( v11 )
        {
          if ( !_InterlockedDecrement(&v11->RefCount) )
            v11->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, 1u);
        }
      }
      else
      {
        Scaleform::Render::FilterSet::AddFilter((Scaleform::Render::FilterSet *)v6, v5->Filters.Data.Data[v8].pObject);
      }
      ++v8;
    }
    while ( v8 < v5->Filters.Data.Size );
  }
  return (Scaleform::Render::FilterSet *)v6;
}

// File Line: 364
// RVA: 0x997580
char __fastcall Scaleform::Render::FilterSet::IsContributing(Scaleform::Render::FilterSet *this)
{
  Scaleform::Render::FilterSet *v1; // rdi
  unsigned int v3; // ebx
  __int64 v4; // rcx
  Scaleform::Render::Filter *v5; // rcx

  v1 = this;
  if ( this->CacheAsBitmap )
    return 1;
  v3 = 0;
  if ( !this->Filters.Data.Size )
    return 0;
  v4 = 0i64;
  while ( 1 )
  {
    v5 = v1->Filters.Data.Data[v4].pObject;
    if ( v5 )
    {
      if ( ((unsigned __int8 (*)(void))v5->vfptr[2].__vecDelDtor)() )
        break;
    }
    v4 = ++v3;
    if ( v3 >= v1->Filters.Data.Size )
      return 0;
  }
  return 1;
}

// File Line: 382
// RVA: 0x95DB80
char __fastcall Scaleform::Render::FilterSet::CanCacheAcrossTransform(Scaleform::Render::FilterSet *this, bool deltaTrans, bool deltaRot, bool deltaScale)
{
  unsigned int v4; // ebx
  bool v5; // si
  bool v6; // bp
  bool v7; // r14
  Scaleform::Render::FilterSet *v8; // rdi
  __int64 v9; // r10
  Scaleform::Render::Filter *v10; // rcx

  v4 = 0;
  v5 = deltaScale;
  v6 = deltaRot;
  v7 = deltaTrans;
  v8 = this;
  if ( !this->Filters.Data.Size )
    return 1;
  v9 = 0i64;
  while ( 1 )
  {
    v10 = v8->Filters.Data.Data[v9].pObject;
    if ( v10 )
    {
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Filter *, bool, bool, bool))v10->vfptr[3].__vecDelDtor)(
              v10,
              v7,
              v6,
              v5) )
        break;
    }
    v9 = ++v4;
    if ( v4 >= v8->Filters.Data.Size )
      return 1;
  }
  return 0;
}

