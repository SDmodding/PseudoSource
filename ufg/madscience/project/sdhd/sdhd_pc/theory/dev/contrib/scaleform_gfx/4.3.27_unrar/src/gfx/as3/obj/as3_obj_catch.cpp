// File Line: 61
// RVA: 0x7FF2B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl::Catch *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl::Catch *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 68
// RVA: 0x77BD10
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Catch::Catch(Scaleform::GFx::AS3::InstanceTraits::fl::Catch *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v4; // rbp
  Scaleform::GFx::AS3::VM *v5; // rbx
  Scaleform::GFx::AS3::VMAbcFile *v6; // rsi
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v7; // rdi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v8; // rbx
  __int64 v9; // rax
  const char *v10; // r8
  const char *v11; // r8
  unsigned __int64 v12; // r9
  char v13; // al
  unsigned int v14; // ecx
  char v15; // dl
  Scaleform::GFx::ASStringNode *v16; // rbx
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  __int64 v20; // rcx
  Scaleform::GFx::AS3::SlotInfo::BindingType v21; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > v22; // r8
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h]
  Scaleform::GFx::ASString v25; // [rsp+78h] [rbp+20h]

  v4 = e;
  v5 = vm;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    &Scaleform::GFx::AS3::fl::CatchCI);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Catch::`vftable;
  v7->TraitsType = 21;
  v8 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v8, &result);
  v9 = v4->var_name_ind;
  if ( (_DWORD)v9 )
  {
    v10 = v6->File.pObject->Const_Pool.ConstStr.Data.Data[v6->File.pObject->Const_Pool.const_multiname.Data.Data[v9].NameIndex].Data;
    if ( v10 )
    {
      v13 = *v10;
      v11 = v10 + 1;
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
      v12 = (signed int)v12;
    }
    else
    {
      v11 = &customWorldMapCaption;
      v12 = 0i64;
    }
    v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v8,
            &v25,
            v11,
            v12)->pNode;
    ++v16->RefCount;
    v17 = result.pNode;
    v18 = result.pNode->RefCount == 1;
    --v17->RefCount;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    result.pNode = v16;
    v19 = v25.pNode;
    v18 = v25.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  v20 = (signed int)v4->exc_type_ind;
  v21 = 2;
  if ( (_DWORD)v20 )
    v21 = Scaleform::GFx::AS3::Traits::GetBindingType(
            (Scaleform::GFx::AS3::Traits *)&v7->vfptr,
            v6,
            &v6->File.pObject->Const_Pool.const_multiname.Data.Data[v20]);
  v22.pV = v7->pVM->PublicNamespace.pObject;
  if ( v22.pV )
    v22.pV->RefCount = (v22.pV->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::AddSlot((Scaleform::GFx::AS3::Traits *)&v7->vfptr, &result, v22, v21, 0i64, 0);
  Scaleform::GFx::AS3::Traits::CalculateMemSize((Scaleform::GFx::AS3::Traits *)&v7->vfptr, 0x38u);
  v23 = result.pNode;
  v18 = result.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
}

// File Line: 118
// RVA: 0x7FE8D0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *__fastcall Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstanceTraits(Scaleform::GFx::AS3::Classes::fl::Catch *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *result, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v4; // rbp
  Scaleform::GFx::AS3::VMAbcFile *v5; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *v6; // rbx
  Scaleform::GFx::AS3::Classes::fl::Catch *v7; // rsi
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v8; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v9; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v10; // rax
  __int64 v12; // [rsp+20h] [rbp-38h]
  __int64 v13; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *v14; // [rsp+30h] [rbp-28h]

  v13 = -2i64;
  v4 = e;
  v5 = file;
  v6 = result;
  v7 = this;
  v8 = 0i64;
  v12 = 328i64;
  v9 = (Scaleform::GFx::AS3::InstanceTraits::fl::Catch *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Classes::fl::Catch *, signed __int64, __int64 *, signed __int64, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           240i64,
                                                           &v12,
                                                           328i64,
                                                           -2i64);
  v14 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Catch::Catch(v9, v5, v7->pTraits.pObject->pVM, v4);
    v8 = v10;
  }
  v6->pObject = v8;
  return v6;
}

// File Line: 140
// RVA: 0x753DF0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Catch::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::CatchCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Catch::`vftable;
    v6->TraitsType = 21;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::CatchCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Catch::`vftable;
    v8.pV->TraitsType = 21;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Catch::`vftable;
  }
  return v3;
}

