// File Line: 299
// RVA: 0x787C30
void __fastcall Scaleform::GFx::AS3::SH2<2,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<2,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(Scaleform::GFx::AS3::SH2<2,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> *this)
{
  Scaleform::GFx::AS3::VSBase *v1; // rdi
  signed int v2; // esi
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::WeakProxy *v4; // rdx
  bool v5; // zf

  v1 = this->stack;
  v2 = 2;
  do
  {
    v3 = v1->pCurrent;
    --v2;
    if ( (v1->pCurrent->Flags & 0x1F) > 9 )
    {
      if ( (v1->pCurrent->Flags >> 9) & 1 )
      {
        v4 = v3->Bonus.pWeakProxy;
        v5 = v4->RefCount-- == 1;
        if ( v5 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v3->Flags &= 0xFFFFFDE0;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VNumber = 0.0;
        v3->value.VS._2.VObj = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v1->pCurrent);
      }
    }
    --v1->pCurrent;
  }
  while ( v2 );
}

