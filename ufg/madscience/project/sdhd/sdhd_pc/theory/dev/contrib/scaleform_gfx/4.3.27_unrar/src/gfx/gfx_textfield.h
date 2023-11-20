// File Line: 53
// RVA: 0x89CC70
void __fastcall Scaleform::GFx::TextField::ShadowParams::ShadowParams(Scaleform::GFx::TextField::ShadowParams *this, Scaleform::GFx::ASStringManager *psc)
{
  Scaleform::GFx::TextField::ShadowParams *v2; // rbx
  signed __int64 v3; // [rsp+50h] [rbp+18h]
  signed __int64 v4; // [rsp+50h] [rbp+18h]

  v2 = this;
  Scaleform::GFx::ASStringManager::CreateEmptyString(psc, &this->ShadowStyleStr);
  v3 = (signed __int64)&v2->ShadowOffsets;
  *(_OWORD *)v3 = 0ui64;
  *(_QWORD *)(v3 + 16) = 0i64;
  v4 = (signed __int64)&v2->TextOffsets;
  *(_OWORD *)v4 = 0ui64;
  *(_QWORD *)(v4 + 16) = 0i64;
  *(_WORD *)((char *)&v4 + 1) = 0;
  LOBYTE(v4) = 0;
  BYTE3(v4) = -1;
  v2->ShadowColor.Raw = v4;
}

// File Line: 281
// RVA: 0x8DD4F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::TextField::GetRectBounds(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::Render::Rect<float> *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *, Scaleform::Render::Rect<float> *, Scaleform::Render::Matrix2x4<float> *))this->vfptr[61].__vecDelDtor)(
    this,
    result,
    transform);
  return v3;
}

// File Line: 369
// RVA: 0x6DDC00
void __fastcall Scaleform::GFx::TextField::ClearImageSubstitutor(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::DocView *v1; // rdi
  Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy> *v2; // rbx

  v1 = this->pDocument.pObject;
  v2 = (Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy> *)&v1->pImageSubstitutor->Elements.Data.Data;
  if ( v2 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>(v2);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  v1->pImageSubstitutor = 0i64;
}

// File Line: 376
// RVA: 0x6DFFF0
Scaleform::Render::Text::DocView::ImageSubstitutor *__fastcall Scaleform::GFx::TextField::CreateImageSubstitutor(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::DocView *v1; // rbx
  Scaleform::Render::Text::DocView::ImageSubstitutor *v2; // rax

  v1 = this->pDocument.pObject;
  if ( !v1->pImageSubstitutor )
  {
    v2 = (Scaleform::Render::Text::DocView::ImageSubstitutor *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 24i64);
    if ( v2 )
    {
      v2->Elements.Data.Data = 0i64;
      v2->Elements.Data.Size = 0i64;
      v2->Elements.Data.Policy.Capacity = 0i64;
    }
    else
    {
      v2 = 0i64;
    }
    v1->pImageSubstitutor = v2;
  }
  return v1->pImageSubstitutor;
}

// File Line: 424
// RVA: 0x6EFB40
double __fastcall Scaleform::GFx::TextField::GetHScrollOffset(Scaleform::GFx::TextField *this)
{
  return (double)(signed int)Scaleform::Render::Text::DocView::GetHScrollOffset(this->pDocument.pObject) * 0.05;
}

// File Line: 581
// RVA: 0x71B300
void __fastcall Scaleform::GFx::TextField::SetShadowAlpha(Scaleform::GFx::TextField *this, float v)
{
  Scaleform::Render::Text::DocView *v2; // rdx
  float v3; // xmm1_4

  v2 = this->pDocument.pObject;
  v3 = v * 255.0;
  if ( v3 >= 255.0 )
  {
    v3 = FLOAT_255_0;
  }
  else if ( v3 < 0.0 )
  {
    v2->Filter.ShadowAlpha = (signed int)0.0;
    v2->Filter.ShadowParams.Colors[0].Channels.Alpha = (signed int)0.0;
    return;
  }
  v2->Filter.ShadowAlpha = (signed int)v3;
  v2->Filter.ShadowParams.Colors[0].Channels.Alpha = (signed int)v3;
}

