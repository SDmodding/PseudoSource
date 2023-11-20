// File Line: 42
// RVA: 0x78EAA0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::~Traits(Scaleform::GFx::AS3::InstanceTraits::Traits *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  v2 = this->Ns.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits((Scaleform::GFx::AS3::Traits *)&v1->vfptr);
}

// File Line: 46
// RVA: 0x800270
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::MakeObject(Scaleform::GFx::AS3::InstanceTraits::Traits *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::Instance *v5; // rax
  Scaleform::GFx::AS3::Object *v6; // rbx
  int v7; // [rsp+50h] [rbp+18h]
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+20h]

  v3 = t;
  v4 = result;
  v7 = 337;
  v5 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(
                                          t->pVM->MHeap,
                                          t->MemSize,
                                          (Scaleform::AllocInfo *)&v7);
  v6 = (Scaleform::GFx::AS3::Object *)&v5->vfptr;
  v8 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, v3);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  Scaleform::GFx::AS3::Value::Pick(v4, v6);
}

// File Line: 51
// RVA: 0x7997C0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::AS3Constructor(Scaleform::GFx::AS3::InstanceTraits::Traits *this, Scaleform::GFx::AS3::Traits *__formal, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  (*((void (__fastcall **)(_QWORD, _QWORD, Scaleform::GFx::AS3::Value *))_this->value.VS._1.VStr->pData + 11))(
    *(_QWORD *)&_this->value.VNumber,
    argc,
    argv);
}

// File Line: 76
// RVA: 0x7EE8F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::GetQualifiedName(Scaleform::GFx::AS3::InstanceTraits::Traits *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Traits::QNameFormat f)
{
  Scaleform::GFx::AS3::Traits::QNameFormat v3; // edi
  Scaleform::GFx::ASString *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // rsi
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::ASString *v7; // rcx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString str; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString *v14; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+68h] [rbp+20h]

  v14 = result;
  v3 = f;
  v4 = result;
  v5 = this->Ns.pObject;
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASString *))this->vfptr[1].~RefCountBaseGC<328>)(
    this,
    &str);
  if ( v5->Uri.pNode->Size )
  {
    v7 = &v5->Uri;
    if ( v3 )
      v8 = Scaleform::GFx::ASString::operator+(v7, &resulta, ".");
    else
      v8 = Scaleform::GFx::ASString::operator+(v7, &resulta, "::");
    Scaleform::GFx::ASString::operator+(v8, v4, &str);
    v9 = resulta.pNode;
    v10 = resulta.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  else
  {
    v6 = str.pNode;
    v4->pNode = str.pNode;
    ++v6->RefCount;
  }
  v11 = str.pNode;
  v10 = str.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return v4;
}

// File Line: 95
// RVA: 0x7F8F60
char __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::IsParentTypeOf(Scaleform::GFx::AS3::InstanceTraits::Traits *this, Scaleform::GFx::AS3::InstanceTraits::Traits *other)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // rdi

  v2 = other;
  v3 = this;
  if ( this == other )
    return 1;
  if ( other )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v2->vfptr[4].~RefCountBaseGC<328>)(
               v2,
               v3) )
    {
      v2 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v2->pParent.pObject;
      if ( v2 == v3 )
        break;
      if ( !v2 )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 149
// RVA: 0x77AA90
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Anonimous::Anonimous(Scaleform::GFx::AS3::InstanceTraits::Anonimous *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v4; // rbx

  v2 = vm;
  v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    &Scaleform::GFx::AS3::InstanceTraits::Anonimous::CInfo);
  v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)v2->TraitsObject.pObject->ITraits.pObject;
  if ( !v4[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*v4)->List.Data.Data)(v4);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v3 + 17, v4[17]);
  v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)&Scaleform::GFx::AS3::InstanceTraits::Anonimous::`vftable';
}

// File Line: 154
// RVA: 0x785070
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Void::Void(Scaleform::GFx::AS3::InstanceTraits::Void *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v4; // rbx

  v2 = vm;
  v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    &Scaleform::GFx::AS3::InstanceTraits::Void::CInfo);
  v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable';
  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)v2->TraitsObject.pObject->ITraits.pObject;
  if ( !v4[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*v4)->List.Data.Data)(v4);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v3 + 17, v4[17]);
  v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)&Scaleform::GFx::AS3::InstanceTraits::Void::`vftable';
}

// File Line: 162
// RVA: 0x77B860
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(Scaleform::GFx::AS3::InstanceTraits::CTraits *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::ClassInfo *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // r14
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v5; // rsi
  bool isFinal; // r12
  bool v7; // r15
  Scaleform::GFx::AS3::VMAppDomain *v8; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Traits *v10; // r13
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // r15
  unsigned __int16 v13; // r14
  unsigned __int8 i; // bl
  unsigned __int16 v15; // r14
  unsigned __int8 j; // bl
  Scaleform::GFx::AS3::TypeInfo *v17; // rdi
  Scaleform::GFx::AS3::TypeInfo **v18; // rax
  __int64 v19; // rbx
  signed __int64 v20; // rcx
  signed __int64 v21; // rcx
  signed __int64 v22; // rdx
  bool v23; // zf
  __int64 v24; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v25; // rax
  int v26; // eax
  long double v27; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::Multiname v30; // [rsp+38h] [rbp-38h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [rsp+B8h] [rbp+48h]
  __int64 v32; // [rsp+C0h] [rbp+50h]

  v3 = ci;
  v4 = vm;
  v5 = this;
  isFinal = (ci->Type->Flags >> 3) & 1;
  v7 = (ci->Type->Flags >> 1) & 1;
  if ( vm->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v8 = vm->CallStack.Pages[(vm->CallStack.Size - 1) >> 6][(LODWORD(vm->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v8 = vm->CurrentDomain.pObject;
  v9 = Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(vm, v3, v8);
  v10 = 0i64;
  if ( v9 )
    v10 = (Scaleform::GFx::AS3::Traits *)&v9->ITraits.pObject->vfptr;
  v11 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(v4, &result, 0, v3->Type->PkgName)->pV;
  Scaleform::GFx::AS3::Traits::Traits((Scaleform::GFx::AS3::Traits *)&v5->vfptr, v4, v10, v7, isFinal);
  v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  v5->Ns.pObject = v11;
  v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::CTraits::`vftable';
  v5->CI = v3;
  v12 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)&v5->ImplementsInterfaces;
  result.pV = v12;
  v32 = (__int64)&v5->ImplementsInterfaces;
  v12->vfptr = 0i64;
  v12->pRCCRaw = 0i64;
  v12->pNext = 0i64;
  v5->MemSize = v3->Type->InstanceSize;
  v13 = v3->Type->InstanceMemberNum;
  for ( i = 0;
        i < v13;
        Scaleform::GFx::AS3::Traits::AddSlot((Scaleform::GFx::AS3::Traits *)&v5->vfptr, &v3->InstanceMember[i++]) )
  {
    ;
  }
  v15 = v3->Type->InstanceMethodNum;
  for ( j = 0;
        j < v15;
        Scaleform::GFx::AS3::Traits::Add2VT((Scaleform::GFx::AS3::Traits *)&v5->vfptr, v3, &v3->InstanceMethod[j++]) )
  {
    ;
  }
  v17 = v3->Type;
  if ( (v17->Flags >> 4) & 1 )
    v5->Flags |= 4ui64;
  v18 = v17->Implements;
  if ( v18 )
  {
    v19 = 0i64;
    if ( *v18 )
    {
      v20 = 0i64;
      while ( 1 )
      {
        Scaleform::GFx::AS3::Multiname::Multiname(&v30, v5->pVM, v18[v20]);
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy> *)&v5->ImplementsInterfaces.Data.Data,
          &v5->ImplementsInterfaces,
          v5->ImplementsInterfaces.Data.Size + 1);
        v21 = 48 * v5->ImplementsInterfaces.Data.Size;
        v22 = (signed __int64)&v12->vfptr[-2];
        v23 = v21 + v22 == 0;
        v24 = v21 + v22;
        result.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v24;
        v32 = v24;
        if ( v23 )
          goto LABEL_31;
        *(_DWORD *)v24 = v30.Kind;
        *(_QWORD *)(v24 + 8) = v30.Obj.pObject;
        v25 = v30.Obj.pObject;
        if ( v30.Obj.pObject )
        {
          ++v30.Obj.pObject->RefCount;
          v25->RefCount &= 0x8FBFFFFF;
        }
        *(_DWORD *)(v24 + 16) = v30.Name.Flags;
        *(_QWORD *)(v24 + 24) = v30.Name.Bonus.pWeakProxy;
        *(Scaleform::GFx::AS3::Value::VU *)(v24 + 32) = v30.Name.value;
        v26 = v30.Name.Flags & 0x1F;
        if ( v26 <= 9 )
          goto LABEL_31;
        if ( (v30.Name.Flags >> 9) & 1 )
        {
          ++v30.Name.Bonus.pWeakProxy->RefCount;
        }
        else if ( v26 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v30.Name.value.VNumber + 24i64);
        }
        else if ( v26 > 10 )
        {
          if ( v26 <= 15 )
          {
            v27 = v30.Name.value.VNumber;
LABEL_28:
            if ( v27 != 0.0 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v27 + 32i64);
              *(_DWORD *)(*(_QWORD *)&v27 + 32i64) &= 0x8FBFFFFF;
            }
            goto LABEL_31;
          }
          if ( v26 <= 17 )
          {
            v27 = *(double *)&v30.Name.value.VS._2.VObj;
            goto LABEL_28;
          }
        }
LABEL_31:
        if ( (v30.Name.Flags & 0x1F) > 9 )
        {
          if ( (v30.Name.Flags >> 9) & 1 )
          {
            v23 = v30.Name.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v23 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v30.Name.Bonus.pWeakProxy = 0i64;
            v30.Name.value = 0ui64;
            v30.Name.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v30.Name);
          }
        }
        v28 = v30.Obj.pObject;
        if ( v30.Obj.pObject )
        {
          if ( (_QWORD)v30.Obj.pObject & 1 )
          {
            --v30.Obj.pObject;
          }
          else
          {
            v29 = v30.Obj.pObject->RefCount;
            if ( v29 & 0x3FFFFF )
            {
              v30.Obj.pObject->RefCount = v29 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v28->vfptr);
            }
          }
        }
        v20 = ++v19;
        v18 = v17->Implements;
        if ( !v18[v19] )
        {
          if ( v19 )
            Scaleform::GFx::AS3::InstanceTraits::CTraits::AddInterfaceSlots2This(
              v5,
              0i64,
              (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v5->vfptr);
          return;
        }
      }
    }
  }
}

// File Line: 197
// RVA: 0x789C30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(Scaleform::GFx::AS3::InstanceTraits::CTraits *this)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::CTraits::`vftable';
  Scaleform::ArrayData<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>(&this->ImplementsInterfaces.Data);
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  v2 = v1->Ns.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits((Scaleform::GFx::AS3::Traits *)&v1->vfptr);
}

// File Line: 212
// RVA: 0x7EC660
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::GetName(Scaleform::GFx::AS3::InstanceTraits::CTraits *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pVM->StringManagerRef->Builtins,
    result,
    this->CI->Type->Name);
  return v2;
}

// File Line: 219
// RVA: 0x824C20
char __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::SupportsInterface(Scaleform::GFx::AS3::InstanceTraits::CTraits *this, Scaleform::GFx::AS3::InstanceTraits::Traits *itraits)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // r12
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // r13
  unsigned __int64 v5; // rbp
  __int64 v6; // r15
  __int64 v7; // rax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v8; // rsi
  Scaleform::GFx::AS3::Multiname *v9; // r14
  int v10; // edx
  bool v11; // bl
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VMAppDomain *v14; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v15; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v16; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v17; // rcx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v2 = itraits;
  v3 = this;
  v4 = this->pVM;
  v5 = 0i64;
  if ( this->ImplementsInterfaces.Data.Size )
  {
    v6 = 0i64;
    do
    {
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::CTraits *))v3->vfptr[2].~RefCountBaseGC<328>)(v3);
      if ( v7 )
        v8 = *(Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> **)(v7 + 48);
      else
        v8 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v3->pVM->SystemDomain.pObject;
      v9 = &v3->ImplementsInterfaces.Data.Data[v6];
      v10 = v9->Name.Flags & 0x1F;
      if ( !v10 )
        goto LABEL_33;
      if ( (unsigned int)(v10 - 12) > 3 && v10 != 10 )
        goto LABEL_34;
      if ( !*(_QWORD *)&v9->Name.value.VNumber )
        goto LABEL_33;
      if ( v10 != 10 )
        goto LABEL_34;
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v9->Name, &result);
      v11 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
      v12 = result.pNode;
      v13 = result.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      if ( !v11 )
      {
LABEL_34:
        v14 = (Scaleform::GFx::AS3::VMAppDomain *)v8[2].Entries.mHash.pHeap;
        if ( !v14 || (v15 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v14, v9)) == 0i64 )
        {
          v15 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(v8 + 3, v9);
          if ( !v15 )
            goto LABEL_27;
        }
        v16 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*v15;
      }
      else
      {
LABEL_33:
        v16 = v4->TraitsClassClass.pObject;
      }
      if ( v16 )
      {
        v17 = v16->ITraits.pObject;
        if ( v17 == v2
          || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v17->vfptr[4].~RefCountBaseGC<328>)(
               v17,
               v2) )
        {
          return 1;
        }
      }
LABEL_27:
      ++v5;
      ++v6;
    }
    while ( v5 < v3->ImplementsInterfaces.Data.Size );
  }
  return 0;
}

// File Line: 244
// RVA: 0x7D5410
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::ForEachChild_GC(Scaleform::GFx::AS3::InstanceTraits::CTraits *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rsi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rbp
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v5; // r15
  unsigned __int64 v6; // r14
  __int64 v7; // rdi
  Scaleform::GFx::AS3::Multiname *v8; // rbx
  int v9; // eax
  signed __int64 v10; // rdx
  _QWORD *v11; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Traits::ForEachChild_GC((Scaleform::GFx::AS3::Traits *)&this->vfptr, prcc, op);
  if ( v5->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  v6 = v5->ImplementsInterfaces.Data.Size;
  if ( v6 )
  {
    v7 = 0i64;
    while ( 1 )
    {
      v8 = &v5->ImplementsInterfaces.Data.Data[v7];
      if ( v8->Obj.pObject )
        v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v8->Obj);
      v9 = v8->Name.Flags & 0x1F;
      if ( v9 <= 10 || (v8->Name.Flags >> 9) & 1 || v9 < 11 )
        goto LABEL_18;
      if ( v9 > 15 )
        break;
      v11 = (_QWORD *)&v8->Name.value.VNumber;
      if ( *v11 )
      {
        v10 = 0i64;
        if ( (unsigned int)(v9 - 11) <= 4 )
          v10 = (signed __int64)v11;
LABEL_17:
        v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v10);
      }
LABEL_18:
      ++v7;
      if ( !--v6 )
        return;
    }
    if ( v9 > 17 )
      goto LABEL_18;
    v10 = (signed __int64)&v8->Name.value.VS._2.VObj;
    if ( !v8->Name.value.VS._2.VObj )
      goto LABEL_18;
    goto LABEL_17;
  }
}

// File Line: 253
// RVA: 0x7ACF80
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::AddInterfaceSlots2This(Scaleform::GFx::AS3::InstanceTraits::CTraits *this, Scaleform::GFx::AS3::VMAbcFile *file_ptr, Scaleform::GFx::AS3::InstanceTraits::Traits *This)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // r12
  Scaleform::GFx::AS3::VMAbcFile *v4; // rsi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v5; // rbp
  Scaleform::GFx::AS3::VM *v6; // r13
  unsigned __int64 v7; // r14
  Scaleform::GFx::AS3::VMAppDomain *v8; // r15
  unsigned __int64 v9; // rbx
  __int64 v10; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v12; // r8
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+28h] [rbp-40h]

  v3 = This;
  v4 = file_ptr;
  v5 = this;
  v6 = this->pVM;
  v7 = this->ImplementsInterfaces.Data.Size;
  if ( file_ptr )
    v8 = file_ptr->AppDomain.pObject;
  else
    v8 = v6->SystemDomain.pObject;
  v9 = 0i64;
  if ( v7 )
  {
    v10 = 0i64;
    while ( 1 )
    {
      v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v6, &v5->ImplementsInterfaces.Data.Data[v10], v8);
      if ( !v11 )
        break;
      v12 = v11->ITraits.pObject;
      if ( !v12 )
        break;
      Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(v3, v4, v12);
      ++v9;
      ++v10;
      if ( v9 >= v7 )
        return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eClassNotFoundError, v5->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pVM, v13, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v14 = v16.Message.pNode;
    v15 = v16.Message.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
}

// File Line: 285
// RVA: 0x781800
void __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::RTraits(Scaleform::GFx::AS3::InstanceTraits::RTraits *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::ASString *n, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> ns, Scaleform::GFx::AS3::InstanceTraits::Traits *pt, bool isDynamic, bool isFinal)
{
  Scaleform::GFx::ASString *v7; // rbx
  Scaleform::GFx::AS3::InstanceTraits::RTraits *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // [rsp+68h] [rbp+20h]

  v10 = ns.pV;
  v7 = n;
  v8 = this;
  Scaleform::GFx::AS3::Traits::Traits(
    (Scaleform::GFx::AS3::Traits *)&this->vfptr,
    vm,
    (Scaleform::GFx::AS3::Traits *)&pt->vfptr,
    isDynamic,
    isFinal);
  v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  v8->Ns.pObject = v10;
  v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable';
  v9 = v7->pNode;
  v8->Name = (Scaleform::GFx::ASString)v7->pNode;
  ++v9->RefCount;
}

// File Line: 289
// RVA: 0x78D220
void __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::~RTraits(Scaleform::GFx::AS3::InstanceTraits::RTraits *this)
{
  Scaleform::GFx::AS3::InstanceTraits::RTraits *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rcx
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable';
  v2 = this->Name.pNode;
  v3 = v2->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  v4 = v1->Ns.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits((Scaleform::GFx::AS3::Traits *)&v1->vfptr);
}

// File Line: 293
// RVA: 0x7FFEB0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::MakeObject(Scaleform::GFx::AS3::InstanceTraits::RTraits *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::RTraits *v3; // rax
  Scaleform::GFx::AS3::Traits *v4; // rcx

  v3 = this;
  v4 = this->pParent.pObject;
  if ( !v4 )
    v4 = (Scaleform::GFx::AS3::Traits *)&v3->pVM->TraitsObject.pObject->ITraits.pObject->vfptr;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v4->vfptr[3].Finalize_GC)(
    v4,
    result,
    t);
}

// File Line: 315
// RVA: 0x7E97A0
__int64 __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::GetFixedMemSize(Scaleform::GFx::AS3::InstanceTraits::RTraits *this)
{
  Scaleform::GFx::AS3::Traits *v1; // rcx
  __int64 result; // rax

  v1 = this->pParent.pObject;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[2].ForEachChild_GC)();
  else
    result = 56i64;
  return result;
}

// File Line: 326
// RVA: 0x7EC6F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::GetName(Scaleform::GFx::AS3::InstanceTraits::RTraits *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v2; // rax

  v2 = this->Name.pNode;
  result->pNode = v2;
  ++v2->RefCount;
  return result;
}

// File Line: 391
// RVA: 0x77EE40
void __fastcall Scaleform::GFx::AS3::Instance::Instance(Scaleform::GFx::AS3::Instance *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::ASRefCountCollector *v2; // r8

  v2 = t->pVM->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v2;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable';
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Object::`vftable';
  this->pTraits.pObject = (Scaleform::GFx::AS3::Traits *)&t->vfptr;
  t->RefCount = (t->RefCount + 1) & 0x8FBFFFFF;
  this->DynAttrs.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::ConstructTail(
    (Scaleform::GFx::AS3::Traits *)&t->vfptr,
    (Scaleform::GFx::AS3::Object *)&this->vfptr);
}

// File Line: 396
// RVA: 0x78BFB0
void __fastcall Scaleform::GFx::AS3::Instance::~Instance(Scaleform::GFx::AS3::Instance *this)
{
  Scaleform::GFx::AS3::Instance *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((_QWORD)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    (Scaleform::GFx::AS3::Object *)&this->vfptr);
  Scaleform::GFx::AS3::Object::~Object((Scaleform::GFx::AS3::Object *)&v1->vfptr);
}

// File Line: 401
// RVA: 0x7B8A90
void __fastcall Scaleform::GFx::AS3::Instance::Construct(Scaleform::GFx::AS3::Instance *this, Scaleform::GFx::AS3::Value *__formal, unsigned int a3, Scaleform::GFx::AS3::Value *a4)
{
  Scaleform::GFx::AS3::Instance *v4; // rbx
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v4 = this;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotConstructorError, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4->pTraits.pObject->pVM, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v6 = v8.Message.pNode;
  v7 = v8.Message.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

