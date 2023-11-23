// File Line: 61
// RVA: 0x7FF2B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::Catch *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Catch *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 68
// RVA: 0x77BD10
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Catch::Catch(
        Scaleform::GFx::AS3::InstanceTraits::fl::Catch *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rbx
  __int64 var_name_ind; // rax
  const char *Data; // r8
  const char *v11; // r8
  unsigned __int64 v12; // r9
  char v13; // al
  unsigned int v14; // ecx
  char v15; // dl
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  __int64 exc_type_ind; // rcx
  Scaleform::GFx::AS3::SlotInfo::BindingType BindingType; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r8
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+78h] [rbp+20h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, &Scaleform::GFx::AS3::fl::CatchCI);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Catch::`vftable;
  this->TraitsType = Traits_Catch;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &result);
  var_name_ind = e->var_name_ind;
  if ( (_DWORD)var_name_ind )
  {
    Data = file->File.pObject->Const_Pool.ConstStr.Data.Data[file->File.pObject->Const_Pool.const_multiname.Data.Data[var_name_ind].NameIndex].Data;
    if ( Data )
    {
      v13 = *Data;
      v11 = Data + 1;
      LODWORD(v12) = v13 & 0x7F;
      v14 = 7;
      if ( v13 < 0 )
      {
        do
        {
          if ( v14 >= 0x20 )
            break;
          v15 = *v11++;
          LODWORD(v12) = ((v15 & 0x7F) << v14) | v12;
          v14 += 7;
        }
        while ( v15 < 0 );
      }
      v12 = (int)v12;
    }
    else
    {
      v11 = &customCaption;
      v12 = 0i64;
    }
    v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            StringManagerRef,
            &v26,
            v11,
            v12);
    pNode = v16->pNode;
    ++v16->pNode->RefCount;
    v18 = result.pNode;
    v19 = result.pNode->RefCount-- == 1;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    result.pNode = pNode;
    v20 = v26.pNode;
    v19 = v26.pNode->RefCount-- == 1;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
  exc_type_ind = (int)e->exc_type_ind;
  BindingType = BT_Value;
  if ( (_DWORD)exc_type_ind )
    BindingType = Scaleform::GFx::AS3::Traits::GetBindingType(
                    this,
                    file,
                    &file->File.pObject->Const_Pool.const_multiname.Data.Data[exc_type_ind]);
  pObject = this->pVM->PublicNamespace.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::AddSlot(
    this,
    &result,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)pObject,
    BindingType,
    0i64,
    0);
  Scaleform::GFx::AS3::Traits::CalculateMemSize(this, 0x38u);
  v24 = result.pNode;
  v19 = result.pNode->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
}

// File Line: 118
// RVA: 0x7FE8D0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *__fastcall Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstanceTraits(
        Scaleform::GFx::AS3::Classes::fl::Catch *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v8; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v9; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v10; // rax
  _DWORD v12[2]; // [rsp+20h] [rbp-38h] BYREF
  __int64 v13; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v14; // [rsp+30h] [rbp-28h]

  v13 = -2i64;
  v8 = 0i64;
  v12[1] = 0;
  v12[0] = 328;
  v9 = (Scaleform::GFx::AS3::InstanceTraits::fl::Catch *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           240i64,
                                                           v12);
  v14 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Catch::Catch(v9, file, this->pTraits.pObject->pVM, e);
    v8 = v10;
  }
  result->pObject = v8;
  return result;
}

// File Line: 140
// RVA: 0x753DF0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Catch::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::CatchCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Catch::`vftable;
    v6->TraitsType = Traits_Catch;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::CatchCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Catch::`vftable;
    v8.pV->TraitsType = Traits_Catch;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Catch::`vftable;
  }
  return result;
}

