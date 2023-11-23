// File Line: 53
// RVA: 0x89CC70
void __fastcall Scaleform::GFx::TextField::ShadowParams::ShadowParams(
        Scaleform::GFx::TextField::ShadowParams *this,
        Scaleform::GFx::ASStringManager *psc)
{
  Scaleform::GFx::ASStringManager::CreateEmptyString(psc, &this->ShadowStyleStr);
  this->ShadowOffsets.Data.Data = 0i64;
  this->ShadowOffsets.Data.Size = 0i64;
  this->ShadowOffsets.Data.Policy.Capacity = 0i64;
  this->TextOffsets.Data.Data = 0i64;
  this->TextOffsets.Data.Size = 0i64;
  this->TextOffsets.Data.Policy.Capacity = 0i64;
  this->ShadowColor.Raw = -16777216;
}

// File Line: 281
// RVA: 0x8DD4F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::TextField::GetRectBounds(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::AvmBitmap *, Scaleform::Render::Rect<float> *, Scaleform::Render::Matrix2x4<float> *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
    this,
    result,
    transform);
  return result;
}

// File Line: 369
// RVA: 0x6DDC00
void __fastcall Scaleform::GFx::TextField::ClearImageSubstitutor(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::DocView *pObject; // rdi
  Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx

  pObject = this->pDocument.pObject;
  p_Data = &pObject->pImageSubstitutor->Elements.Data;
  if ( p_Data )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>(p_Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_Data);
  }
  pObject->pImageSubstitutor = 0i64;
}

// File Line: 376
// RVA: 0x6DFFF0
Scaleform::Render::Text::DocView::ImageSubstitutor *__fastcall Scaleform::GFx::TextField::CreateImageSubstitutor(
        Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::DocView *pObject; // rbx
  Scaleform::Render::Text::DocView::ImageSubstitutor *v2; // rax

  pObject = this->pDocument.pObject;
  if ( !pObject->pImageSubstitutor )
  {
    v2 = (Scaleform::Render::Text::DocView::ImageSubstitutor *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
    pObject->pImageSubstitutor = v2;
  }
  return pObject->pImageSubstitutor;
}

// File Line: 424
// RVA: 0x6EFB40
double __fastcall Scaleform::GFx::TextField::GetHScrollOffset(Scaleform::GFx::TextField *this)
{
  return (double)(int)Scaleform::Render::Text::DocView::GetHScrollOffset(this->pDocument.pObject) * 0.05;
}

// File Line: 581
// RVA: 0x71B300
void __fastcall Scaleform::GFx::TextField::SetShadowAlpha(Scaleform::GFx::TextField *this, float v)
{
  Scaleform::Render::Text::DocView *pObject; // rdx
  float v3; // xmm1_4

  pObject = this->pDocument.pObject;
  v3 = v * 255.0;
  if ( v3 >= 255.0 )
  {
    v3 = FLOAT_255_0;
  }
  else if ( v3 < 0.0 )
  {
    pObject->Filter.ShadowAlpha = (int)0.0;
    pObject->Filter.ShadowParams.Colors[0].Channels.Alpha = (int)0.0;
    return;
  }
  pObject->Filter.ShadowAlpha = (int)v3;
  pObject->Filter.ShadowParams.Colors[0].Channels.Alpha = (int)v3;
}

