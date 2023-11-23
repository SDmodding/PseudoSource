// File Line: 22
// RVA: 0x80E930
void __fastcall Scaleform::GFx::AS3::StackReader::Read(
        Scaleform::GFx::AS3::StackReader *this,
        Scaleform::GFx::AS3::Multiname *obj)
{
  unsigned __int32 v4; // eax
  Scaleform::GFx::AS3::ValueStack *OpStack; // rdi
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  v4 = obj->Kind - 1;
  while ( 2 )
  {
    switch ( v4 )
    {
      case 0u:
      case 8u:
        goto $LN8_94;
      case 4u:
      case 0xCu:
        Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(obj, this->OpStack);
$LN8_94:
        Scaleform::GFx::AS3::StackReader::CheckObject(this, this->OpStack->pCurrent);
        if ( this->VMRef->HandleException )
          return;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&obj->Obj,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->OpStack->pCurrent->value.VS._1.VStr);
        obj->Kind &= 0xFFFFFFFC;
        OpStack = this->OpStack;
        pCurrent = OpStack->pCurrent;
        if ( (OpStack->pCurrent->Flags & 0x1F) <= 9 )
          goto LABEL_13;
        if ( (OpStack->pCurrent->Flags & 0x200) != 0 )
        {
          pWeakProxy = pCurrent->Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          pCurrent->Bonus.pWeakProxy = 0i64;
          pCurrent->value.VS._1.VStr = 0i64;
          pCurrent->value.VS._2.VObj = 0i64;
          pCurrent->Flags &= 0xFFFFFDE0;
          --OpStack->pCurrent;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(OpStack->pCurrent);
LABEL_13:
          --OpStack->pCurrent;
        }
        return;
      case 5u:
      case 0xDu:
        Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(obj, this->OpStack);
        return;
      case 0xFu:
        this->VMRef->UI->vfptr->Output(this->VMRef->UI, Output_Warning, "Reading chained multiname in itself.");
        v4 = obj->Kind - 1;
        if ( v4 <= 0xF )
          continue;
        return;
      default:
        return;
    }
  }
}

// File Line: 85
// RVA: 0x781880
void __fastcall Scaleform::GFx::AS3::ReadArgs::ReadArgs(
        Scaleform::GFx::AS3::ReadArgs *this,
        Scaleform::GFx::AS3::VM *vm,
        unsigned int arg_count)
{
  unsigned __int64 v3; // rdi
  Scaleform::MemoryHeap *MHeap; // rax
  Scaleform::GFx::AS3::ValueStack *OpStack; // r14
  Scaleform::GFx::AS3::Value *Data; // rcx
  size_t v9; // rbx

  v3 = arg_count;
  this->VMRef = vm;
  this->OpStack = &vm->OpStack;
  this->ArgNum = arg_count;
  `eh vector constructor iterator(
    this->FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  MHeap = vm->MHeap;
  this->CallArgs.Data.Data = 0i64;
  this->CallArgs.Data.Size = 0i64;
  this->CallArgs.Data.Policy.Capacity = 0i64;
  this->CallArgs.Data.pHeap = MHeap;
  if ( (_DWORD)v3 )
  {
    OpStack = this->OpStack;
    if ( (unsigned int)v3 > 8 )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->CallArgs.Data,
        v3);
      Data = this->CallArgs.Data.Data;
    }
    else
    {
      Data = this->FixedArr;
    }
    v9 = 32i64 * (unsigned int)v3;
    memmove(Data, &OpStack->pCurrent[-(unsigned __int16)(v3 - 1)], v9);
    OpStack->pCurrent = (Scaleform::GFx::AS3::Value *)((char *)OpStack->pCurrent - v9);
  }
}

