// File Line: 22
// RVA: 0x80E930
void __fastcall Scaleform::GFx::AS3::StackReader::Read(Scaleform::GFx::AS3::StackReader *this, Scaleform::GFx::AS3::Multiname *obj)
{
  Scaleform::GFx::AS3::Multiname *v2; // rdi
  Scaleform::GFx::AS3::StackReader *v3; // rbx
  unsigned __int32 v4; // eax
  Scaleform::GFx::AS3::Value **v5; // rdi
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::WeakProxy *v7; // rdx
  bool v8; // zf

  v2 = obj;
  v3 = this;
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
        Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(v2, (Scaleform::GFx::AS3::VSBase *)&v3->OpStack->pCurrent);
$LN8_94:
        Scaleform::GFx::AS3::StackReader::CheckObject(v3, v3->OpStack->pCurrent);
        if ( v3->VMRef->HandleException )
          return;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v2->Obj,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->OpStack->pCurrent->value.VS._1.VStr);
        v2->Kind &= 0xFFFFFFFC;
        v5 = &v3->OpStack->pCurrent;
        v6 = *v5;
        if ( ((*v5)->Flags & 0x1F) <= 9 )
          goto LABEL_13;
        if ( ((*v5)->Flags >> 9) & 1 )
        {
          v7 = v6->Bonus.pWeakProxy;
          v8 = v7->RefCount-- == 1;
          if ( v8 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v6->Bonus.pWeakProxy = 0i64;
          v6->value.VNumber = 0.0;
          v6->value.VS._2.VObj = 0i64;
          v6->Flags &= 0xFFFFFDE0;
          --*v5;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(*v5);
LABEL_13:
          --*v5;
        }
        break;
      case 5u:
      case 0xDu:
        Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(v2, (Scaleform::GFx::AS3::VSBase *)&v3->OpStack->pCurrent);
        break;
      case 0xFu:
        v3->VMRef->UI->vfptr->Output(v3->VMRef->UI, Output_Warning, "Reading chained multiname in itself.");
        v4 = v2->Kind - 1;
        if ( v4 <= 0xF )
          continue;
        break;
      default:
        return;
    }
    break;
  }
}

// File Line: 85
// RVA: 0x781880
void __fastcall Scaleform::GFx::AS3::ReadArgs::ReadArgs(Scaleform::GFx::AS3::ReadArgs *this, Scaleform::GFx::AS3::VM *vm, unsigned int arg_count)
{
  unsigned __int64 v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::ReadArgs *v5; // rsi
  Scaleform::MemoryHeap *v6; // rax
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v7; // r15
  Scaleform::GFx::AS3::ValueStack *v8; // r14
  Scaleform::GFx::AS3::Value *v9; // rcx
  size_t v10; // rbx

  v3 = arg_count;
  v4 = vm;
  v5 = this;
  this->VMRef = vm;
  this->OpStack = &vm->OpStack;
  this->ArgNum = arg_count;
  `eh vector constructor iterator(
    this->FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  v6 = v4->MHeap;
  v7 = &v5->CallArgs;
  v7->Data.Data = 0i64;
  v7->Data.Size = 0i64;
  v7->Data.Policy.Capacity = 0i64;
  v5->CallArgs.Data.pHeap = v6;
  if ( (_DWORD)v3 )
  {
    v8 = v5->OpStack;
    if ( (unsigned int)v3 > 8 )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v5->CallArgs.Data,
        v3);
      v9 = v7->Data.Data;
    }
    else
    {
      v9 = v5->FixedArr;
    }
    v10 = 32i64 * (unsigned int)v3;
    memmove(v9, &v8->pCurrent[-(unsigned __int16)(v3 - 1)], v10);
    v8->pCurrent = (Scaleform::GFx::AS3::Value *)((char *)v8->pCurrent - v10);
  }
}

