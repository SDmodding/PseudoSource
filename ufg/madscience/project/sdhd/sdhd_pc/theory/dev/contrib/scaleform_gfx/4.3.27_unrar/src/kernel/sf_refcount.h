// File Line: 219
// RVA: 0x7901B0
void *__fastcall Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::operator new(
        unsigned __int64 sz,
        Scaleform::MemAddressStub *adr)
{
  int v3; // [rsp+40h] [rbp+18h] BYREF

  v3 = 74;
  return Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, adr, sz, &v3);
}

// File Line: 398
// RVA: 0x1454800
void *dynamic_initializer_for__Scaleform::Render::Matrix3x4_float_::Identity__()
{
  void *result; // rax

  result = memset(
             &Scaleform::Render::Matrix3x4<float>::Identity,
             0,
             sizeof(Scaleform::Render::Matrix3x4<float>::Identity));
  Scaleform::Render::Matrix3x4<float>::Identity.M[0][0] = 1.0;
  Scaleform::Render::Matrix3x4<float>::Identity.M[1][1] = 1.0;
  Scaleform::Render::Matrix3x4<float>::Identity.M[2][2] = 1.0;
  return result;
}

// File Line: 418
// RVA: 0x8A22E0
void __fastcall Scaleform::GFx::DisplayList::DisplayEntry::~DisplayEntry(Scaleform::Ptr<Scaleform::GFx::Sprite> *this)
{
  Scaleform::GFx::Sprite *pObject; // rcx

  pObject = this->pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
}

// File Line: 704
// RVA: 0x790CC0
Scaleform::Ptr<Scaleform::GFx::Sprite> *__fastcall Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        Scaleform::WeakPtr<Scaleform::GFx::Sprite> *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> *result)
{
  Scaleform::GFx::Sprite *v4; // rbx
  Scaleform::WeakPtrProxy *pObject; // rdx
  int RefCount; // eax

  v4 = 0i64;
  pObject = this->pProxy.pObject;
  if ( this->pProxy.pObject )
  {
    if ( pObject->pObject )
    {
      v4 = (Scaleform::GFx::Sprite *)pObject->pObject;
      RefCount = v4->RefCount;
      if ( RefCount )
        v4->RefCount = RefCount + 1;
      else
        v4 = 0i64;
    }
    else
    {
      if ( pObject )
      {
        if ( pObject->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      this->pProxy.pObject = 0i64;
    }
  }
  result->pObject = v4;
  return result;
}

