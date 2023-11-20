// File Line: 219
// RVA: 0x7901B0
__int64 __fastcall Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::operator new(unsigned __int64 sz, Scaleform::MemAddressStub *adr)
{
  int v3; // [rsp+40h] [rbp+18h]

  v3 = 74;
  return Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
           Scaleform::Memory::pGlobalHeap,
           adr,
           sz,
           (Scaleform::AllocInfo *)&v3);
}

// File Line: 398
// RVA: 0x1454800
void *dynamic_initializer_for__Scaleform::Render::Matrix3x4_float_::Identity__()
{
  void *result; // rax

  result = memset(&Scaleform::Render::Matrix3x4<float>::Identity, 0, 0x30ui64);
  Scaleform::Render::Matrix3x4<float>::Identity.M[0][0] = 1.0;
  Scaleform::Render::Matrix3x4<float>::Identity.M[1][1] = 1.0;
  Scaleform::Render::Matrix3x4<float>::Identity.M[2][2] = 1.0;
  return result;
}

// File Line: 418
// RVA: 0x8A22E0
void __fastcall Scaleform::GFx::DisplayList::DisplayEntry::~DisplayEntry(Scaleform::Ptr<Scaleform::GFx::Sprite> *this)
{
  JUMPOUT(this->pObject, 0i64, Scaleform::RefCountNTSImpl::Release);
}

// File Line: 704
// RVA: 0x790CC0
Scaleform::Ptr<Scaleform::GFx::Sprite> *__fastcall Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(Scaleform::WeakPtr<Scaleform::GFx::Sprite> *this, Scaleform::Ptr<Scaleform::GFx::Sprite> *result)
{
  Scaleform::Ptr<Scaleform::GFx::Sprite> *v2; // rdi
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *v3; // rsi
  Scaleform::GFx::Sprite *v4; // rbx
  Scaleform::WeakPtrProxy *v5; // rdx
  int v6; // eax
  bool v7; // zf

  v2 = result;
  v3 = this;
  v4 = 0i64;
  v5 = this->pProxy.pObject;
  if ( this->pProxy.pObject )
  {
    if ( v5->pObject )
    {
      v4 = (Scaleform::GFx::Sprite *)v5->pObject;
      v6 = v4->RefCount;
      if ( v6 )
        v4->RefCount = v6 + 1;
      else
        v4 = 0i64;
    }
    else
    {
      if ( v5 )
      {
        v7 = v5->RefCount-- == 1;
        if ( v7 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::WeakPtrProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v5);
      }
      v3->pProxy.pObject = 0i64;
    }
  }
  v2->pObject = v4;
  return v2;
}

