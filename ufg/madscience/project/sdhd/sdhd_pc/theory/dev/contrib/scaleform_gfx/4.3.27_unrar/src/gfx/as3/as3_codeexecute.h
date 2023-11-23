// File Line: 299
// RVA: 0x787C30
void __fastcall Scaleform::GFx::AS3::SH2<2,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<2,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(
        Scaleform::GFx::AS3::SH2<2,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> *this)
{
  Scaleform::GFx::AS3::VSBase *stack; // rdi
  int v2; // esi
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  stack = this->stack;
  v2 = 2;
  do
  {
    pCurrent = stack->pCurrent;
    --v2;
    if ( (stack->pCurrent->Flags & 0x1F) > 9 )
    {
      if ( (stack->pCurrent->Flags & 0x200) != 0 )
      {
        pWeakProxy = pCurrent->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pCurrent->Flags &= 0xFFFFFDE0;
        pCurrent->Bonus.pWeakProxy = 0i64;
        pCurrent->value.VS._1.VStr = 0i64;
        pCurrent->value.VS._2.VObj = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(stack->pCurrent);
      }
    }
    --stack->pCurrent;
  }
  while ( v2 );
}

