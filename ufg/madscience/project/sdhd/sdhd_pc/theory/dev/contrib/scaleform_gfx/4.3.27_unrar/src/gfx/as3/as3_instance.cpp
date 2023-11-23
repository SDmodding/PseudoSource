// File Line: 42
// RVA: 0x78EAA0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::~Traits(Scaleform::GFx::AS3::InstanceTraits::Traits *this)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}

// File Line: 46
// RVA: 0x800270
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance *v5; // rax
  Scaleform::GFx::AS3::Object *v6; // rbx
  int v7; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+20h]

  v7 = 337;
  v5 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v6 = v5;
  v8 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, t);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  Scaleform::GFx::AS3::Value::Pick(result, v6);
}

// File Line: 51
// RVA: 0x7997C0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::AS3Constructor(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::Traits *__formal,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, _QWORD, Scaleform::GFx::AS3::Value *))_this->value.VS._1.VStr->pData
   + 11))(
    _this->value.VS._1,
    argc,
    argv);
}

// File Line: 76
// RVA: 0x7EE8F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::GetQualifiedName(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Traits::QNameFormat f)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rsi
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::ASString *p_Uri; // rcx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString str; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v14; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+68h] [rbp+20h] BYREF

  v14 = result;
  pObject = this->Ns.pObject;
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASString *))this->vfptr[1].~RefCountBaseGC<328>)(
    this,
    &str);
  if ( pObject->Uri.pNode->Size )
  {
    p_Uri = &pObject->Uri;
    if ( f )
      v8 = Scaleform::GFx::ASString::operator+(p_Uri, &resulta, ".");
    else
      v8 = Scaleform::GFx::ASString::operator+(p_Uri, &resulta, "::");
    Scaleform::GFx::ASString::operator+(v8, result, &str);
    pNode = resulta.pNode;
    v10 = resulta.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    v6 = str.pNode;
    result->pNode = str.pNode;
    ++v6->RefCount;
  }
  v11 = str.pNode;
  v10 = str.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return result;
}

// File Line: 95
// RVA: 0x7F8F60
char __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::IsParentTypeOf(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *other)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx

  pObject = other;
  if ( this == other )
    return 1;
  if ( other )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))pObject->vfptr[4].~RefCountBaseGC<328>)(
               pObject,
               this) )
    {
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject->pParent.pObject;
      if ( pObject == this )
        break;
      if ( !pObject )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 149
// RVA: 0x77AA90
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Anonimous::Anonimous(
        Scaleform::GFx::AS3::InstanceTraits::Anonimous *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList **pObject; // rbx

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    this,
    vm,
    &Scaleform::GFx::AS3::InstanceTraits::Anonimous::CInfo);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable;
  pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList **)vm->TraitsObject.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*pObject)->List.Data.Data)(pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pConstructor,
    pObject[17]);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Anonimous::`vftable;
}

// File Line: 154
// RVA: 0x785070
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Void::Void(
        Scaleform::GFx::AS3::InstanceTraits::Void *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList **pObject; // rbx

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, &Scaleform::GFx::AS3::InstanceTraits::Void::CInfo);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Prototype::`vftable;
  pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList **)vm->TraitsObject.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*pObject)->List.Data.Data)(pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pConstructor,
    pObject[17]);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Void::`vftable;
}

// File Line: 162
// RVA: 0x77B860
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  bool isFinal; // r12
  bool v7; // r15
  Scaleform::GFx::AS3::VMAppDomain *pObject; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *ParentClassTraits; // rax
  Scaleform::GFx::AS3::Traits *v10; // r13
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  unsigned __int16 InstanceMemberNum; // r14
  unsigned __int8 i; // bl
  unsigned __int16 InstanceMethodNum; // r14
  unsigned __int8 j; // bl
  Scaleform::GFx::AS3::TypeInfo *Type; // rdi
  Scaleform::GFx::AS3::TypeInfo **Implements; // rax
  __int64 v18; // rbx
  __int64 v19; // rcx
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Multiname *v21; // rdx
  bool v22; // zf
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Multiname,2,Scaleform::ArrayDefaultPolicy> *v23; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v24; // rax
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v26; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Multiname v28; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [rsp+B8h] [rbp+48h] BYREF
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Multiname,2,Scaleform::ArrayDefaultPolicy> *p_ImplementsInterfaces; // [rsp+C0h] [rbp+50h]

  isFinal = (ci->Type->Flags & 8) != 0;
  v7 = (ci->Type->Flags & 2) != 0;
  if ( vm->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    pObject = vm->CallStack.Pages[(vm->CallStack.Size - 1) >> 6][(LODWORD(vm->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    pObject = vm->CurrentDomain.pObject;
  ParentClassTraits = Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(vm, ci, pObject);
  v10 = 0i64;
  if ( ParentClassTraits )
    v10 = ParentClassTraits->ITraits.pObject;
  pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(vm, &result, NS_Public, ci->Type->PkgName)->pV;
  Scaleform::GFx::AS3::Traits::Traits(this, vm, v10, v7, isFinal);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  this->Ns.pObject = pV;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::CTraits::`vftable;
  this->CI = ci;
  result.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)&this->ImplementsInterfaces;
  p_ImplementsInterfaces = &this->ImplementsInterfaces;
  this->ImplementsInterfaces.Data.Data = 0i64;
  this->ImplementsInterfaces.Data.Size = 0i64;
  this->ImplementsInterfaces.Data.Policy.Capacity = 0i64;
  this->MemSize = ci->Type->InstanceSize;
  InstanceMemberNum = ci->Type->InstanceMemberNum;
  for ( i = 0; i < InstanceMemberNum; ++i )
    Scaleform::GFx::AS3::Traits::AddSlot(this, &ci->InstanceMember[i]);
  InstanceMethodNum = ci->Type->InstanceMethodNum;
  for ( j = 0; j < InstanceMethodNum; ++j )
    Scaleform::GFx::AS3::Traits::Add2VT(this, ci, &ci->InstanceMethod[j]);
  Type = ci->Type;
  if ( (Type->Flags & 0x10) != 0 )
    this->Flags |= 4ui64;
  Implements = Type->Implements;
  if ( Implements )
  {
    v18 = 0i64;
    if ( *Implements )
    {
      v19 = 0i64;
      while ( 1 )
      {
        Scaleform::GFx::AS3::Multiname::Multiname(&v28, this->pVM, Implements[v19]);
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->ImplementsInterfaces.Data,
          &this->ImplementsInterfaces,
          this->ImplementsInterfaces.Data.Size + 1);
        Size = this->ImplementsInterfaces.Data.Size;
        v21 = this->ImplementsInterfaces.Data.Data - 1;
        v22 = &v21[Size] == 0i64;
        v23 = (Scaleform::ArrayLH<Scaleform::GFx::AS3::Multiname,2,Scaleform::ArrayDefaultPolicy> *)&v21[Size];
        result.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v23;
        p_ImplementsInterfaces = v23;
        if ( v22 )
          goto LABEL_31;
        LODWORD(v23->Data.Data) = v28.Kind;
        v23->Data.Size = (unsigned __int64)v28.Obj.pObject;
        v24 = v28.Obj.pObject;
        if ( v28.Obj.pObject )
        {
          ++v28.Obj.pObject->RefCount;
          v24->RefCount &= 0x8FBFFFFF;
        }
        LODWORD(v23->Data.Policy.Capacity) = v28.Name.Flags;
        v23[1].Data.Data = (Scaleform::GFx::AS3::Multiname *)v28.Name.Bonus.pWeakProxy;
        *(Scaleform::GFx::AS3::Value::VU *)&v23[1].Data.Size = v28.Name.value;
        if ( (v28.Name.Flags & 0x1F) <= 9 )
          goto LABEL_31;
        if ( (v28.Name.Flags & 0x200) != 0 )
        {
          ++v28.Name.Bonus.pWeakProxy->RefCount;
        }
        else if ( (v28.Name.Flags & 0x1F) == 10 )
        {
          ++v28.Name.value.VS._1.VStr->RefCount;
        }
        else if ( (v28.Name.Flags & 0x1F) > 0xA )
        {
          if ( (v28.Name.Flags & 0x1F) <= 0xF )
          {
            VObj = v28.Name.value.VS._1;
LABEL_28:
            if ( VObj.VStr )
            {
              ++VObj.VStr->Size;
              VObj.VStr->Size &= 0x8FBFFFFF;
            }
            goto LABEL_31;
          }
          if ( (v28.Name.Flags & 0x1F) <= 0x11 )
          {
            VObj = (Scaleform::GFx::AS3::Value::V1U)v28.Name.value.VS._2.VObj;
            goto LABEL_28;
          }
        }
LABEL_31:
        if ( (v28.Name.Flags & 0x1F) > 9 )
        {
          if ( (v28.Name.Flags & 0x200) != 0 )
          {
            v22 = v28.Name.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v22 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v28.Name.Bonus, 0, 24);
            v28.Name.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v28.Name);
          }
        }
        v26 = v28.Obj.pObject;
        if ( v28.Obj.pObject )
        {
          if ( ((__int64)v28.Obj.pObject & 1) != 0 )
          {
            --v28.Obj.pObject;
          }
          else
          {
            RefCount = v28.Obj.pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v28.Obj.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
            }
          }
        }
        v19 = ++v18;
        Implements = Type->Implements;
        if ( !Implements[v18] )
        {
          if ( v18 )
            Scaleform::GFx::AS3::InstanceTraits::CTraits::AddInterfaceSlots2This(this, 0i64, this);
          return;
        }
      }
    }
  }
}

// File Line: 197
// RVA: 0x789C30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::CTraits::`vftable;
  Scaleform::ArrayData<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>(&this->ImplementsInterfaces.Data);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}

// File Line: 212
// RVA: 0x7EC660
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::GetName(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    this->pVM->StringManagerRef,
    result,
    this->CI->Type->Name);
  return result;
}

// File Line: 219
// RVA: 0x824C20
char __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::SupportsInterface(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *itraits)
{
  Scaleform::GFx::AS3::VM *pVM; // r13
  unsigned __int64 v5; // rbp
  __int64 v6; // r15
  __int64 v7; // rax
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rsi
  Scaleform::GFx::AS3::Multiname *v9; // r14
  int v10; // edx
  bool v11; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v16; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v17; // rcx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  pVM = this->pVM;
  v5 = 0i64;
  if ( this->ImplementsInterfaces.Data.Size )
  {
    v6 = 0i64;
    do
    {
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::CTraits *))this->vfptr[2].~RefCountBaseGC<328>)(this);
      if ( v7 )
        pObject = *(Scaleform::GFx::AS3::VMAppDomain **)(v7 + 48);
      else
        pObject = this->pVM->SystemDomain.pObject;
      v9 = &this->ImplementsInterfaces.Data.Data[v6];
      v10 = v9->Name.Flags & 0x1F;
      if ( !v10 )
        goto LABEL_23;
      if ( (unsigned int)(v10 - 12) > 3 && v10 != 10 )
        goto LABEL_19;
      if ( !v9->Name.value.VS._1.VStr )
        goto LABEL_23;
      if ( v10 != 10 )
        goto LABEL_19;
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v9->Name, &result);
      v11 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v11 )
      {
LABEL_23:
        v16 = pVM->TraitsClassClass.pObject;
      }
      else
      {
LABEL_19:
        ParentDomain = pObject->ParentDomain;
        if ( !ParentDomain || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, v9)) == 0i64 )
        {
          ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                         &pObject->ClassTraitsSet,
                         v9);
          if ( !ClassTrait )
            goto LABEL_27;
        }
        v16 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
      }
      if ( v16 )
      {
        v17 = v16->ITraits.pObject;
        if ( v17 == itraits
          || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v17->vfptr[4].~RefCountBaseGC<328>)(
               v17,
               itraits) )
        {
          return 1;
        }
      }
LABEL_27:
      ++v5;
      ++v6;
    }
    while ( v5 < this->ImplementsInterfaces.Data.Size );
  }
  return 0;
}

// File Line: 244
// RVA: 0x7D5410
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 Size; // r14
  __int64 i; // rdi
  Scaleform::GFx::AS3::Multiname *v8; // rbx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_VObj; // rdx
  Scaleform::GFx::AS3::Value::V1U *p_value; // rbx

  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  Size = this->ImplementsInterfaces.Data.Size;
  if ( Size )
  {
    for ( i = 0i64; ; ++i )
    {
      v8 = &this->ImplementsInterfaces.Data.Data[i];
      if ( v8->Obj.pObject )
        op(prcc, &v8->Obj.pObject);
      Flags = v8->Name.Flags;
      if ( (Flags & 0x1F) <= 0xA || (Flags & 0x200) != 0 || (v8->Name.Flags & 0x1F) < 0xB )
        goto LABEL_18;
      if ( (v8->Name.Flags & 0x1F) > 0xF )
        break;
      p_value = (Scaleform::GFx::AS3::Value::V1U *)&v8->Name.value;
      if ( p_value->VStr )
      {
        p_VObj = 0i64;
        if ( (Flags & 0x1F) - 11 <= 4 )
          p_VObj = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)p_value;
LABEL_17:
        op(prcc, p_VObj);
      }
LABEL_18:
      if ( !--Size )
        return;
    }
    if ( (v8->Name.Flags & 0x1F) > 0x11 )
      goto LABEL_18;
    p_VObj = &v8->Name.value.VS._2.VObj;
    if ( !v8->Name.value.VS._2.VObj )
      goto LABEL_18;
    goto LABEL_17;
  }
}

// File Line: 253
// RVA: 0x7ACF80
void __fastcall Scaleform::GFx::AS3::InstanceTraits::CTraits::AddInterfaceSlots2This(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::VMAbcFile *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *This)
{
  Scaleform::GFx::AS3::VM *pVM; // r13
  unsigned __int64 Size; // r14
  Scaleform::GFx::AS3::VMAppDomain *pObject; // r15
  __int64 v9; // rbx
  __int64 i; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v12; // r8
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+28h] [rbp-40h] BYREF

  pVM = this->pVM;
  Size = this->ImplementsInterfaces.Data.Size;
  if ( file_ptr )
    pObject = file_ptr->AppDomain.pObject;
  else
    pObject = pVM->SystemDomain.pObject;
  v9 = 0i64;
  if ( Size )
  {
    for ( i = 0i64; ; ++i )
    {
      v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(pVM, &this->ImplementsInterfaces.Data.Data[i], pObject);
      if ( !v11 )
        break;
      v12 = v11->ITraits.pObject;
      if ( !v12 )
        break;
      Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(This, file_ptr, v12);
      if ( ++v9 >= Size )
        return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v16, 1014, this->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pVM, v13, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pNode = v16.Message.pNode;
    if ( v16.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 285
// RVA: 0x781800
void __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::RTraits(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASString *n,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> ns,
        Scaleform::GFx::AS3::InstanceTraits::Traits *pt,
        bool isDynamic,
        bool isFinal)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  Scaleform::GFx::AS3::Traits::Traits(this, vm, pt, isDynamic, isFinal);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  this->Ns.pObject = ns.pV;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable;
  pNode = n->pNode;
  this->Name = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
}

// File Line: 289
// RVA: 0x78D220
void __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::~RTraits(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable;
  pNode = this->Name.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  pObject = this->Ns.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}

// File Line: 293
// RVA: 0x7FFEB0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx

  pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pParent.pObject;
  if ( !pObject )
    pObject = this->pVM->TraitsObject.pObject->ITraits.pObject;
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::InstanceTraits::Traits *))pObject->vfptr[3].Finalize_GC)(
    pObject,
    result,
    t);
}

// File Line: 315
// RVA: 0x7E97A0
__int64 __fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::GetFixedMemSize(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // rcx

  pObject = this->pParent.pObject;
  if ( pObject )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pObject->vfptr[2].ForEachChild_GC)(pObject);
  else
    return 56i64;
}

// File Line: 326
// RVA: 0x7EC6F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::RTraits::GetName(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  pNode = this->Name.pNode;
  result->pNode = pNode;
  ++pNode->RefCount;
  return result;
}

// File Line: 391
// RVA: 0x77EE40
void __fastcall Scaleform::GFx::AS3::Instance::Instance(
        Scaleform::GFx::AS3::Instance *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // r8

  GC = t->pVM->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Object::`vftable;
  this->pTraits.pObject = t;
  t->RefCount = (t->RefCount + 1) & 0x8FBFFFFF;
  this->DynAttrs.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable;
  Scaleform::GFx::AS3::Traits::ConstructTail(t, this);
}

// File Line: 396
// RVA: 0x78BFB0
void __fastcall Scaleform::GFx::AS3::Instance::~Instance(Scaleform::GFx::AS3::Instance *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable;
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    this);
  Scaleform::GFx::AS3::Object::~Object(this);
}

// File Line: 401
// RVA: 0x7B8A90
void __fastcall Scaleform::GFx::AS3::Instance::Construct(
        Scaleform::GFx::AS3::Instance *this,
        Scaleform::GFx::AS3::Value *__formal,
        unsigned int a3,
        Scaleform::GFx::AS3::Value *a4)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  Scaleform::GFx::AS3::VM::Error::Error(&v8, 1115, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v8.Message.pNode;
  if ( v8.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

