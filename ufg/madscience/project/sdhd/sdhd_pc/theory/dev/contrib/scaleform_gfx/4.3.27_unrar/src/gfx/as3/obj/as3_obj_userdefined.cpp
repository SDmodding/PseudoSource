// File Line: 30
// RVA: 0x783BA0
void __fastcall Scaleform::GFx::AS3::Classes::UserDefined::UserDefined(
        Scaleform::GFx::AS3::Classes::UserDefined *this,
        Scaleform::GFx::AS3::ClassTraits::UserDefined *t)
{
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::AS3::VM *pVM; // r9
  unsigned __int64 ScopeStackBaseInd; // rdx
  char v7; // [rsp+48h] [rbp+10h] BYREF

  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::UDBase::`vftable;
  Scaleform::GFx::AS3::Traits::ConstructTail(t, this);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::UserDefined::`vftable;
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::UserDefined *, char *, Scaleform::GFx::AS3::Classes::UserDefined *))t->vfptr[2].Finalize_GC)(
                   t,
                   &v7,
                   this) )
  {
    pObject = this->pTraits.pObject;
    pVM = pObject->pVM;
    if ( pVM->CallStack.Size )
      ScopeStackBaseInd = pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(LODWORD(pVM->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
    else
      ScopeStackBaseInd = 0i64;
    Scaleform::GFx::AS3::Traits::StoreScopeStack(pObject, ScopeStackBaseInd, &pVM->ScopeStack);
  }
}

// File Line: 47
// RVA: 0x7B2F60
void __fastcall Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(
        Scaleform::GFx::AS3::Classes::UserDefined *this)
{
  __int64 v2; // rbx
  Scaleform::GFx::AS3::Traits *pObject; // rdx
  Scaleform::GFx::AS3::VMAbcFile *pRCC; // r14
  Scaleform::GFx::AS3::VM *pVM; // rsi
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v11; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **p_DefXMLNamespace; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v13; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v15; // rdi
  Scaleform::GFx::AS3::CallFrame **Pages; // rax
  __int64 v17; // rcx
  Scaleform::GFx::AS3::CallFrame *v18; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::AS3::Value v20; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v22; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::AS3::VM::Error v23; // [rsp+108h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::CallFrame *v24; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::GFx::AS3::CallFrame *v25; // [rsp+158h] [rbp+58h]

  v22 = -2i64;
  v2 = *(int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(this->pTraits.pObject[1].pRCCRaw + 152) + 224i64)
                          + 8i64 * SLODWORD(this->pTraits.pObject[1].pNext[2].pNext))
              + 8i64);
  _this.Flags = 13;
  _this.Bonus.pWeakProxy = 0i64;
  _this.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v20.Flags = 13;
  v20.Bonus.pWeakProxy = 0i64;
  v20.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  pObject = this->pTraits.pObject;
  pRCC = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1]._pRCC;
  pVM = pObject->pVM;
  if ( pVM->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v23, 1023, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v6, &Scaleform::GFx::AS3::fl::ErrorTI);
    pNode = v23.Message.pNode;
    v8 = v23.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    *(_WORD *)&other.DiscardResult = 1;
    VMRef = pRCC->VMRef;
    other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    other.CP = 0i64;
    other.pRegisterFile = &VMRef->RegisterFile;
    other.pHeap = VMRef->MHeap;
    other.pFile = pRCC;
    other.MBIIndex.Ind = v2;
    other.pSavedScope = &pObject->InitScope;
    other.OriginationTraits = pObject;
    other.pScopeStack = &VMRef->ScopeStack;
    other.DefXMLNamespace.pObject = 0i64;
    other.Invoker.Flags = 13;
    other.Invoker.Bonus.pWeakProxy = 0i64;
    other.Invoker.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
    other.Invoker.value.VS._2.VObj = v20.value.VS._2.VObj;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    p_OpStack = &pRCC->VMRef->OpStack;
    other.PrevInitialStackPos = p_OpStack->pCurrent;
    other.PrevFirstStackPos = p_OpStack->pStack;
    v11 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(p_OpStack, v11->max_stack + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v11->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
        *p_DefXMLNamespace);
      v24 = 0i64;
      if ( &v24 != (Scaleform::GFx::AS3::CallFrame **)p_DefXMLNamespace )
      {
        v13 = *p_DefXMLNamespace;
        if ( *p_DefXMLNamespace )
        {
          if ( ((unsigned __int8)v13 & 1) != 0 )
          {
            *p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v13 - 1);
          }
          else
          {
            RefCount = v13->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v13->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
            }
          }
        }
        *p_DefXMLNamespace = 0i64;
      }
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      pRCC->File.pObject->Methods.Info.Data.Data[pRCC->File.pObject->MethodBodies.Info.Data.Data[v2]->method_info_ind],
      &_this,
      0,
      0i64);
    if ( pVM->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      v15 = pVM->CallStack.Size >> 6;
      if ( v15 >= pVM->CallStack.NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          &pVM->CallStack,
          pVM->CallStack.Size >> 6);
      Pages = pVM->CallStack.Pages;
      v17 = pVM->CallStack.Size & 0x3F;
      v8 = &Pages[v15][v17] == 0i64;
      v18 = &Pages[v15][v17];
      v24 = v18;
      v25 = v18;
      if ( !v8 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v18, &other);
      ++pVM->CallStack.Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
}

// File Line: 80
// RVA: 0x807A10
void __fastcall Scaleform::GFx::AS3::Classes::UserDefined::PostInit(
        Scaleform::GFx::AS3::Classes::UserDefined *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // r11
  __int64 v8; // rbx
  Scaleform::GFx::AS3::Traits *vfptr; // rdx
  Scaleform::GFx::AS3::VMAbcFile *pRCC; // r15
  Scaleform::GFx::AS3::VM *pVM; // r14
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v20; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **p_DefXMLNamespace; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v24; // rdi
  Scaleform::GFx::AS3::CallFrame **Pages; // rax
  __int64 v26; // rcx
  Scaleform::GFx::AS3::CallFrame *v27; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+8h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+98h] [rbp+17h] BYREF
  __int64 v30; // [rsp+A8h] [rbp+27h]
  Scaleform::GFx::AS3::CallFrame *v31; // [rsp+E8h] [rbp+67h] BYREF

  v30 = -2i64;
  pObject = this->pTraits.pObject;
  v8 = *(int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(pObject[1].pRCCRaw + 152) + 224i64)
                          + 8i64 * SLODWORD(pObject[1].pNext->Scaleform::GFx::AS3::Slots::pPrev))
              + 8i64);
  vfptr = (Scaleform::GFx::AS3::Traits *)pObject[1].vfptr;
  pRCC = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1]._pRCC;
  pVM = pObject->pVM;
  if ( pVM->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v29, 1023, pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v12, &Scaleform::GFx::AS3::fl::ErrorTI);
    pNode = v29.Message.pNode;
    v14 = v29.Message.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  *(_WORD *)&other.DiscardResult = 1;
  VMRef = pRCC->VMRef;
  other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
  other.CP = 0i64;
  other.pRegisterFile = &VMRef->RegisterFile;
  other.pHeap = VMRef->MHeap;
  other.pFile = pRCC;
  other.MBIIndex.Ind = v8;
  other.pSavedScope = &vfptr->InitScope;
  other.OriginationTraits = vfptr;
  other.pScopeStack = &VMRef->ScopeStack;
  other.DefXMLNamespace.pObject = 0i64;
  Flags = _this->Flags;
  other.Invoker.Flags = Flags;
  pWeakProxy = _this->Bonus.pWeakProxy;
  other.Invoker.Bonus.pWeakProxy = pWeakProxy;
  other.Invoker.value = _this->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      goto LABEL_16;
    }
    if ( (Flags & 0x1F) == 10 )
    {
      ++_this->value.VS._1.VStr->RefCount;
    }
    else if ( (Flags & 0x1F) > 0xA )
    {
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = _this->value.VS._1;
LABEL_13:
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
        goto LABEL_16;
      }
      if ( (Flags & 0x1F) <= 0x11 )
      {
        VObj = (Scaleform::GFx::AS3::Value::V1U)_this->value.VS._2.VObj;
        goto LABEL_13;
      }
    }
  }
LABEL_16:
  p_OpStack = &pRCC->VMRef->OpStack;
  other.PrevInitialStackPos = p_OpStack->pCurrent;
  other.PrevFirstStackPos = p_OpStack->pStack;
  v20 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
  Scaleform::GFx::AS3::ValueStack::Reserve(p_OpStack, v20->max_stack + 1);
  Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v20->local_reg_count);
  p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
  if ( *p_DefXMLNamespace )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
      *p_DefXMLNamespace);
    v31 = 0i64;
    if ( &v31 != (Scaleform::GFx::AS3::CallFrame **)p_DefXMLNamespace )
    {
      v22 = *p_DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        if ( ((unsigned __int8)v22 & 1) != 0 )
        {
          *p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v22 - 1);
        }
        else
        {
          RefCount = v22->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v22->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
          }
        }
      }
      *p_DefXMLNamespace = 0i64;
    }
  }
  Scaleform::GFx::AS3::CallFrame::SetupRegisters(
    &other,
    pRCC->File.pObject->Methods.Info.Data.Data[pRCC->File.pObject->MethodBodies.Info.Data.Data[v8]->method_info_ind],
    _this,
    argc,
    argv);
  if ( pVM->HandleException )
  {
    other.ACopy = 1;
  }
  else
  {
    v24 = pVM->CallStack.Size >> 6;
    if ( v24 >= pVM->CallStack.NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
        &pVM->CallStack,
        pVM->CallStack.Size >> 6);
    Pages = pVM->CallStack.Pages;
    v26 = pVM->CallStack.Size & 0x3F;
    v14 = &Pages[v24][v26] == 0i64;
    v27 = &Pages[v24][v26];
    v31 = v27;
    *(_QWORD *)&v29.ID = v27;
    if ( !v14 )
      Scaleform::GFx::AS3::CallFrame::CallFrame(v27, &other);
    ++pVM->CallStack.Size;
  }
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
}

// File Line: 123
// RVA: 0x783B20
void __fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::UserDefined(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, 0i64);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::UserDefined::`vftable;
  this->File.pObject = file;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  this->class_info = info;
  this->Flags |= 0x10ui64;
}

// File Line: 131
// RVA: 0x78ECF0
void __fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::~UserDefined(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // rcx
  unsigned int v5; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::UserDefined::`vftable;
  pObject = this->File.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
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
  v4 = this->ITraits.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( (v5 & 0x3FFFFF) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  Scaleform::GFx::AS3::Traits::~Traits(this);
}

// File Line: 135
// RVA: 0x810450
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::RegisterSlots(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rbx
  Scaleform::GFx::AS3::Abc::ClassInfo *class_info; // rdi
  unsigned int parent_size; // eax
  bool v7; // zf
  Scaleform::GFx::AS3::CheckResult *v8; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h] BYREF

  pObject = this->File.pObject;
  class_info = this->class_info;
  parent_size = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::UserDefined *))this->vfptr[2].ForEachChild_GC)(this);
  v7 = !Scaleform::GFx::AS3::Traits::AddSlots(this, &resulta, &class_info->stat_info, pObject, parent_size)->Result;
  v8 = result;
  result->Result = !v7;
  return v8;
}

// File Line: 150
// RVA: 0x7EFFD0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::GetSuperClassTraits(
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  __int64 super_name_ind; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *result; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  super_name_ind = info->inst_info.super_name_ind;
  if ( !(_DWORD)super_name_ind )
    return 0i64;
  result = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
             file->VMRef,
             file,
             &file->File.pObject->Const_Pool.const_multiname.Data.Data[super_name_ind]);
  if ( !result )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1001, file->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(file->VMRef, v5, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 0i64;
  }
  return result;
}

// File Line: 171
// RVA: 0x7F57A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *SuperClassTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v5; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits const > *p_pParent; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rsi
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v9; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v10; // rax
  Scaleform::MemoryHeap *resulta; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v13; // [rsp+60h] [rbp+18h]

  SuperClassTraits = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::ClassTraits::UserDefined::GetSuperClassTraits(
                                                                      this->File.pObject,
                                                                      this->class_info);
  v5 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)SuperClassTraits;
  if ( !this->pVM->HandleException )
  {
    p_pParent = &this->pParent;
    if ( !this->pParent.pObject )
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)p_pParent,
        SuperClassTraits);
    if ( this->ITraits.pObject )
    {
      result->Result = 1;
      return result;
    }
    v7.pV = 0i64;
    if ( v5 )
    {
      if ( !v5->ITraits.pObject )
      {
        Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(v5, (Scaleform::GFx::AS3::CheckResult *)&resulta);
        if ( this->pVM->HandleException )
        {
          result->Result = 0;
          return result;
        }
      }
      pObject = v5->ITraits.pObject;
    }
    else
    {
      pObject = 0i64;
    }
    resulta = this->pVM->MHeap;
    v9 = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)resulta->vfptr->Alloc(
                                                               (Scaleform::MemoryHeap *)p_pParent,
                                                               232ui64,
                                                               0i64);
    v13 = v9;
    if ( v9 )
    {
      Scaleform::GFx::AS3::InstanceTraits::UserDefined::UserDefined(v9, this->File.pObject, pObject, this->class_info);
      v7.pV = v10;
    }
    Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v7);
    if ( !this->pVM->HandleException )
    {
      Scaleform::GFx::AS3::ClassTraits::UserDefined::RegisterSlots(this, result);
      return result;
    }
  }
  result->Result = 0;
  return result;
}

// File Line: 228
// RVA: 0x821120
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::SetupSlotValues(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Object *for_obj)
{
  Scaleform::GFx::AS3::Traits::SetupSlotValues(this, result, this->File.pObject, &this->class_info->stat_info);
  return result;
}

// File Line: 236
// RVA: 0x7EA270
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::GetGlobalObjectScript(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this)
{
  return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))this->ITraits.pObject->Scaleform::GFx::AS3::ClassTraits::Traits::vfptr[3].ForEachChild_GC)(this->ITraits.pObject);
}

// File Line: 241
// RVA: 0x7FA5D0
Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::MakeClass(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *result)
{
  Scaleform::GFx::AS3::Classes::UserDefined *v4; // rax
  Scaleform::GFx::AS3::Classes::UserDefined *v5; // rax
  Scaleform::GFx::AS3::Classes::UserDefined *v6; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rsi
  Scaleform::GFx::AS3::VM *pVM; // r8
  unsigned __int64 ScopeStackBaseInd; // rdx
  Scaleform::GFx::AS3::Classes::UserDefined *pV; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-40h] BYREF
  int v13; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Classes::UserDefined *v14; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::AS3::Classes::UserDefined *v15; // [rsp+80h] [rbp+18h]

  v13 = 337;
  v4 = (Scaleform::GFx::AS3::Classes::UserDefined *)this->pVM->MHeap->vfptr->Alloc(
                                                      this->pVM->MHeap,
                                                      this->MemSize,
                                                      &v13);
  v14 = v4;
  v15 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Classes::UserDefined::UserDefined(v4, this);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
  pObject = this->ITraits.pObject;
  pVM = this->pVM;
  if ( pVM->CallStack.Size )
    ScopeStackBaseInd = pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(LODWORD(pVM->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
  else
    ScopeStackBaseInd = 0i64;
  Scaleform::GFx::AS3::Traits::StoreScopeStack(this->ITraits.pObject, ScopeStackBaseInd, &pVM->ScopeStack);
  pV = result->pV;
  source.Flags = 13;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pV;
  if ( pV )
    pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pObject->InitScope.Data,
    pObject->InitScope.Data.pHeap,
    pObject->InitScope.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &pObject->InitScope.Data.Data[pObject->InitScope.Data.Size - 1].Flags,
    &source);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
  Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(result->pV);
  return result;
}

// File Line: 274
// RVA: 0x7E96D0
UFG::SimObjectVehicle *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(UFG::TSVehicle *this)
{
  return (UFG::SimObjectVehicle *)this->mpSimObj.m_pPointer;
}

// File Line: 279
// RVA: 0x7D6770
void __fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::ForEachChild_GC(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->ITraits.pObject )
    op(prcc);
  if ( this->File.pObject )
    op(prcc);
}

// File Line: 300
// RVA: 0x783C60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::UserDefined(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::InstanceTraits::Traits *pt,
        Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  Scaleform::GFx::ASString *InternedString; // r13
  bool isFinal; // r15
  char v10; // r12
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::ASString result; // [rsp+88h] [rbp+10h] BYREF

  InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                     file,
                     &result,
                     file->File.pObject->Const_Pool.const_multiname.Data.Data[info->inst_info.name_ind].NameIndex);
  isFinal = (info->inst_info.flags & 2) != 0;
  v10 = info->inst_info.flags & 1;
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                        file,
                        file->File.pObject->Const_Pool.const_multiname.Data.Data[info->inst_info.name_ind].Ind);
  v12 = InternedNamespace;
  if ( InternedNamespace )
    InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::Traits(this, file->VMRef, pt, v10 == 0, isFinal);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  this->Ns.pObject = v12;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable;
  pNode = InternedString->pNode;
  this->Name = (Scaleform::GFx::ASString)InternedString->pNode;
  ++pNode->RefCount;
  v14 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::UserDefined::`vftable;
  this->Script.pObject = 0i64;
  this->class_info = info;
  this->Flags |= 0x10ui64;
  this->Flags ^= (LODWORD(this->Flags) ^ -((info->inst_info.flags & 4) != 0)) & 4;
  if ( pt )
  {
    MemSize = pt->MemSize;
  }
  else
  {
    pObject = this->pParent.pObject;
    if ( pObject )
      MemSize = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pObject->vfptr[2].ForEachChild_GC)(pObject);
    else
      MemSize = 56;
  }
  if ( Scaleform::GFx::AS3::Traits::AddSlots(
         this,
         (Scaleform::GFx::AS3::CheckResult *)&result,
         &info->inst_info,
         file,
         MemSize)->Result )
    Scaleform::GFx::AS3::InstanceTraits::UserDefined::AddInterfaceSlots2This(this, file, this);
}

// File Line: 341
// RVA: 0x799E20
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::AS3Constructor(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  __int64 method_info_ind; // rbx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // rdi
  Scaleform::GFx::AS3::Traits *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v12; // rdi
  __int64 v13; // rbx
  Scaleform::GFx::AS3::Traits *v14; // r15
  Scaleform::GFx::AS3::Traits *v15; // rcx
  Scaleform::GFx::AS3::VMAbcFile *FirstOwnSlotNum; // r14
  Scaleform::GFx::AS3::VM *pVM; // rsi
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v20; // zf
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::Value::V2U v22; // rdx
  Scaleform::GFx::AS3::Value::V1U v23; // rcx
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v25; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **p_DefXMLNamespace; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v27; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v29; // rdi
  Scaleform::GFx::AS3::CallFrame **Pages; // rax
  __int64 v31; // rcx
  Scaleform::GFx::AS3::CallFrame *v32; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+30h] [rbp-91h] BYREF
  Scaleform::GFx::AS3::VM::Error v34; // [rsp+C0h] [rbp-1h] BYREF
  __int64 v35; // [rsp+D0h] [rbp+Fh]
  Scaleform::GFx::AS3::CallFrame *v36; // [rsp+120h] [rbp+5Fh] BYREF
  Scaleform::GFx::AS3::CallFrame *v37; // [rsp+128h] [rbp+67h]

  v35 = -2i64;
  method_info_ind = this->class_info->inst_info.method_info_ind;
  pObject = this->Script.pObject;
  if ( !pObject->Initialized )
  {
    pObject->vfptr[6].Finalize_GC(this->Script.pObject);
    v11 = pObject->pTraits.pObject;
    if ( !v11->pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v11->pVM, 1u);
  }
  v12 = this->Script.pObject;
  v13 = *(int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12->pTraits.pObject[1].FirstOwnSlotNum + 152) + 224i64)
                           + 8 * method_info_ind)
               + 8i64);
  v14 = ot->pParent.pObject;
  if ( !v12->Initialized )
  {
    v12->vfptr[6].Finalize_GC(this->Script.pObject);
    v15 = v12->pTraits.pObject;
    if ( !v15->pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v15->pVM, 1u);
  }
  FirstOwnSlotNum = (Scaleform::GFx::AS3::VMAbcFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum;
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  pVM = this->pVM;
  if ( pVM->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v34, 1023, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v18, &Scaleform::GFx::AS3::fl::ErrorTI);
    pNode = v34.Message.pNode;
    v20 = v34.Message.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    *(_WORD *)&other.DiscardResult = 1;
    VMRef = FirstOwnSlotNum->VMRef;
    other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    other.CP = 0i64;
    other.pRegisterFile = &VMRef->RegisterFile;
    other.pHeap = VMRef->MHeap;
    other.pFile = FirstOwnSlotNum;
    other.MBIIndex.Ind = v13;
    other.pSavedScope = &v14->InitScope;
    other.OriginationTraits = v14;
    other.pScopeStack = &VMRef->ScopeStack;
    other.DefXMLNamespace.pObject = 0i64;
    other.Invoker.Flags = v.Flags;
    other.Invoker.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v22.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
    v23 = v.value.VS._1;
    other.Invoker.value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
      }
      else if ( (v.Flags & 0x1F) > 0xA )
      {
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          if ( v.value.VS._1.VStr )
          {
            ++v.value.VS._1.VStr->Size;
            v23.VStr->Size &= 0x8FBFFFFF;
          }
        }
        else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
        {
          ++v.value.VS._2.VObj->RefCount;
          v22.VObj->RefCount &= 0x8FBFFFFF;
        }
      }
    }
    p_OpStack = &FirstOwnSlotNum->VMRef->OpStack;
    other.PrevInitialStackPos = p_OpStack->pCurrent;
    other.PrevFirstStackPos = p_OpStack->pStack;
    v25 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(p_OpStack, v25->max_stack + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v25->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
        *p_DefXMLNamespace);
      v36 = 0i64;
      if ( &v36 != (Scaleform::GFx::AS3::CallFrame **)p_DefXMLNamespace )
      {
        v27 = *p_DefXMLNamespace;
        if ( *p_DefXMLNamespace )
        {
          if ( ((unsigned __int8)v27 & 1) != 0 )
          {
            *p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v27 - 1);
          }
          else
          {
            RefCount = v27->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v27->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
            }
          }
        }
        *p_DefXMLNamespace = 0i64;
      }
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      FirstOwnSlotNum->File.pObject->Methods.Info.Data.Data[FirstOwnSlotNum->File.pObject->MethodBodies.Info.Data.Data[v13]->method_info_ind],
      _this,
      argc,
      argv);
    if ( pVM->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      v29 = pVM->CallStack.Size >> 6;
      if ( v29 >= pVM->CallStack.NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          &pVM->CallStack,
          pVM->CallStack.Size >> 6);
      Pages = pVM->CallStack.Pages;
      v31 = pVM->CallStack.Size & 0x3F;
      v20 = &Pages[v29][v31] == 0i64;
      v32 = &Pages[v29][v31];
      v36 = v32;
      v37 = v32;
      if ( !v20 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v32, &other);
      ++pVM->CallStack.Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
}

// File Line: 380
// RVA: 0x7EF2C0
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetGlobalObjectScript(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // rdi
  Scaleform::GFx::AS3::VM *pVM; // rcx

  pObject = this->Script.pObject;
  if ( pObject->Initialized )
    return this->Script.pObject;
  pObject->vfptr[6].Finalize_GC(this->Script.pObject);
  pVM = pObject->pTraits.pObject->pVM;
  if ( !pVM->HandleException )
    Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
  return this->Script.pObject;
}

// File Line: 385
// RVA: 0x824D90
char __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::SupportsInterface(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *itraits)
{
  Scaleform::GFx::AS3::Abc::ClassInfo *class_info; // r13
  unsigned __int64 Size; // r12
  __int64 v6; // r14
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // rbx
  Scaleform::GFx::AS3::Traits *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v9; // rbx
  Scaleform::GFx::AS3::Abc::Multiname *v10; // rdi
  Scaleform::GFx::AS3::Traits *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v12; // rbx
  Scaleform::GFx::AS3::Traits *v13; // rcx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v14; // rdi
  int v15; // ecx
  bool v16; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v18; // zf
  Scaleform::GFx::AS3::VMAppDomain *pHeap; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v21; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v22; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v23; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::AS3::Multiname mn; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+40h] BYREF
  Scaleform::GFx::AS3::VM *pVM; // [rsp+B0h] [rbp+50h]

  class_info = this->class_info;
  pVM = this->pVM;
  Size = class_info->inst_info.implemented_interfaces.info.Data.Size;
  v6 = 0i64;
  if ( !Size )
    return 0;
  while ( 1 )
  {
    pObject = this->Script.pObject;
    if ( !pObject->Initialized )
    {
      pObject->vfptr[6].Finalize_GC(this->Script.pObject);
      v8 = pObject->pTraits.pObject;
      if ( !v8->pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v8->pVM, 1u);
    }
    v9 = this->Script.pObject;
    v10 = (Scaleform::GFx::AS3::Abc::Multiname *)(*(_QWORD *)(*(_QWORD *)(v9->pTraits.pObject[1].FirstOwnSlotNum + 152)
                                                            + 176i64)
                                                + 16i64
                                                * class_info->inst_info.implemented_interfaces.info.Data.Data[(unsigned int)v6]);
    if ( !v9->Initialized )
    {
      v9->vfptr[6].Finalize_GC(this->Script.pObject);
      v11 = v9->pTraits.pObject;
      if ( !v11->pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v11->pVM, 1u);
    }
    Scaleform::GFx::AS3::Multiname::Multiname(
      &mn,
      (Scaleform::GFx::AS3::VMFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum,
      v10);
    v12 = this->Script.pObject;
    if ( !v12->Initialized )
    {
      v12->vfptr[6].Finalize_GC(this->Script.pObject);
      v13 = v12->pTraits.pObject;
      if ( !v13->pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v13->pVM, 1u);
    }
    v14 = *(Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> **)(this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum
                                                                                                 + 48);
    v15 = mn.Name.Flags & 0x1F;
    if ( (mn.Name.Flags & 0x1F) == 0 )
      goto LABEL_28;
    if ( (unsigned int)(v15 - 12) > 3 && v15 != 10 )
      goto LABEL_24;
    if ( !mn.Name.value.VS._1.VStr )
      goto LABEL_28;
    if ( v15 != 10 )
      goto LABEL_24;
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
    v16 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
    pNode = result.pNode;
    v18 = result.pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v16 )
    {
LABEL_28:
      v21 = pVM->TraitsClassClass.pObject;
    }
    else
    {
LABEL_24:
      pHeap = (Scaleform::GFx::AS3::VMAppDomain *)v14[2].Entries.mHash.pHeap;
      if ( !pHeap || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(pHeap, &mn)) == 0i64 )
      {
        ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       v14 + 3,
                       &mn);
        if ( !ClassTrait )
          goto LABEL_32;
      }
      v21 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*ClassTrait;
    }
    if ( v21 )
    {
      v22 = v21->ITraits.pObject;
      if ( v22 == itraits
        || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v22->vfptr[4].~RefCountBaseGC<328>)(
             v22,
             itraits) )
      {
        break;
      }
    }
LABEL_32:
    if ( (mn.Name.Flags & 0x1F) > 9 )
    {
      if ( (mn.Name.Flags & 0x200) != 0 )
      {
        v18 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v18 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&mn.Name.Bonus, 0, 24);
        mn.Name.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
      }
    }
    v23 = mn.Obj.pObject;
    if ( mn.Obj.pObject )
    {
      if ( ((__int64)mn.Obj.pObject & 1) != 0 )
      {
        --mn.Obj.pObject;
      }
      else
      {
        RefCount = mn.Obj.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          mn.Obj.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
        }
      }
    }
    if ( ++v6 >= Size )
      return 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      v18 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v25 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v26 = mn.Obj.pObject->RefCount;
      if ( (v26 & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = v26 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
      }
    }
  }
  return 1;
}

// File Line: 418
// RVA: 0x821150
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::SetupSlotValues(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Object *for_obj)
{
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v7; // rbx
  Scaleform::GFx::AS3::Abc::ClassInfo *class_info; // r14
  Scaleform::GFx::AS3::VM *pVM; // rcx
  char v10; // [rsp+50h] [rbp+8h] BYREF

  pObject = this->pParent.pObject;
  if ( !pObject
    || *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, char *))pObject->vfptr[2].Finalize_GC)(
                   pObject,
                   &v10) )
  {
    v7 = this->Script.pObject;
    class_info = this->class_info;
    if ( !v7->Initialized )
    {
      v7->vfptr[6].Finalize_GC(this->Script.pObject);
      pVM = v7->pTraits.pObject->pVM;
      if ( !pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
    }
    Scaleform::GFx::AS3::Traits::SetupSlotValues(
      this,
      result,
      (Scaleform::GFx::AS3::VMAbcFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum,
      &class_info->inst_info);
    return result;
  }
  else
  {
    result->Result = 0;
    return result;
  }
}

// File Line: 429
// RVA: 0x807DC0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::PreInit(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *_this)
{
  ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))this->vfptr[2].Finalize_GC)(
    this,
    result,
    (Scaleform::GFx::AS3::Value::V1U)_this->value.VS._1.VStr);
  return result;
}

// File Line: 459
// RVA: 0x7D67D0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->Ns.pObject )
    op(prcc);
  if ( this->Script.pObject )
    op(prcc);
}

// File Line: 466
// RVA: 0x7F3C30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::InitOnDemand(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // rbx
  Scaleform::GFx::AS3::VM *pVM; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // rcx

  pObject = this->Script.pObject;
  if ( !pObject->Initialized )
  {
    pObject->vfptr[6].Finalize_GC(this->Script.pObject);
    pVM = pObject->pTraits.pObject->pVM;
    if ( !pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
  }
  v4 = this->Script.pObject;
  if ( !v4->Initialized )
  {
    v4->vfptr[6].Finalize_GC(this->Script.pObject);
    v5 = v4->pTraits.pObject->pVM;
    if ( !v5->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v5, 1u);
  }
}

// File Line: 471
// RVA: 0x7E96E0
Scaleform::GFx::AS3::VMAbcFile *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // rbx
  Scaleform::GFx::AS3::VM *pVM; // rcx

  pObject = this->Script.pObject;
  if ( !pObject->Initialized )
  {
    pObject->vfptr[6].Finalize_GC(this->Script.pObject);
    pVM = pObject->pTraits.pObject->pVM;
    if ( !pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
  }
  return (Scaleform::GFx::AS3::VMAbcFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum;
}

// File Line: 492
// RVA: 0x7AD080
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::AddInterfaceSlots2This(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        Scaleform::GFx::AS3::VMAbcFile *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *This)
{
  Scaleform::GFx::AS3::VMAbcFile *File; // r15
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v5; // rbx
  __int64 class_info; // r13
  Scaleform::GFx::AS3::VM *pVM; // r14
  unsigned __int64 v8; // rsi
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *pObject; // rdi
  int v10; // ecx
  bool v11; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VMAppDomain *pHeap; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *FixedTraits; // r14
  Scaleform::GFx::AS3::VMAppDomain *v17; // r13
  Scaleform::GFx::AS3::VM *v18; // r15
  int v19; // ecx
  bool v20; // bl
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v23; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v24; // rsi
  __int64 v25; // r12
  unsigned __int64 j; // rbx
  Scaleform::GFx::AS3::Instances::fl::GlobalObject *v27; // rdx
  Scaleform::GFx::AS3::Traits *v28; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v29; // r8
  Scaleform::GFx::AS3::GASRefCountBase *v30; // rcx
  unsigned int v31; // eax
  __int64 v32; // rbx
  Scaleform::GFx::AS3::VM::Error *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v35; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Multiname mn; // [rsp+0h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::VMAbcFile *v38; // [rsp+30h] [rbp-19h]
  unsigned __int64 i; // [rsp+38h] [rbp-11h]
  Scaleform::GFx::ASString v40; // [rsp+40h] [rbp-9h] BYREF
  __int64 v41; // [rsp+48h] [rbp-1h]
  Scaleform::GFx::AS3::VM::Error v42; // [rsp+50h] [rbp+7h] BYREF
  __int64 v43; // [rsp+60h] [rbp+17h]
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v44; // [rsp+B0h] [rbp+67h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *v45; // [rsp+C0h] [rbp+77h]
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+7Fh] BYREF

  v43 = -2i64;
  File = file_ptr;
  v38 = file_ptr;
  v5 = this;
  if ( this->Script.pObject )
  {
    File = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile(this);
    v38 = File;
  }
  class_info = (__int64)v5->class_info;
  v41 = class_info;
  pVM = v5->pVM;
  *(_QWORD *)&v42.ID = pVM;
  v8 = 0i64;
  for ( i = 0i64; v8 < *(_QWORD *)(class_info + 56); pVM = *(Scaleform::GFx::AS3::VM **)&v42.ID )
  {
    Scaleform::GFx::AS3::Multiname::Multiname(
      &mn,
      File,
      &File->File.pObject->Const_Pool.const_multiname.Data.Data[*(int *)(*(_QWORD *)(class_info + 48)
                                                                       + 4i64 * (unsigned int)v8)]);
    pObject = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)File->AppDomain.pObject;
    v10 = mn.Name.Flags & 0x1F;
    if ( (mn.Name.Flags & 0x1F) == 0 )
      goto LABEL_22;
    if ( (unsigned int)(v10 - 12) > 3 && v10 != 10 )
      goto LABEL_17;
    if ( !mn.Name.value.VS._1.VStr )
      goto LABEL_22;
    if ( v10 != 10 )
      goto LABEL_17;
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
    v11 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
    pNode = result.pNode;
    v13 = result.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v13 = !v11;
    v5 = v44;
    if ( v13 )
    {
LABEL_17:
      pHeap = (Scaleform::GFx::AS3::VMAppDomain *)pObject[2].Entries.mHash.pHeap;
      if ( pHeap && (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(pHeap, &mn)) != 0i64
        || (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                           pObject + 3,
                           &mn)) != 0i64 )
      {
        FixedTraits = *ClassTrait;
      }
      else
      {
        FixedTraits = 0i64;
      }
    }
    else
    {
LABEL_22:
      FixedTraits = pVM->TraitsClassClass.pObject;
    }
    if ( !FixedTraits )
    {
      v17 = File->AppDomain.pObject;
      v18 = v5->pVM;
      v19 = mn.Name.Flags & 0x1F;
      if ( (mn.Name.Flags & 0x1F) == 0 )
        goto LABEL_42;
      if ( (unsigned int)(v19 - 12) > 3 && v19 != 10 )
        goto LABEL_37;
      if ( !mn.Name.value.VS._1.VStr )
        goto LABEL_42;
      if ( v19 != 10 )
        goto LABEL_37;
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &v40);
      v20 = !v40.pNode->Size || *v40.pNode->pData == pattern[0] && !*((_BYTE *)v40.pNode->pData + 1);
      v21 = v40.pNode;
      v13 = v40.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      if ( v20 )
      {
LABEL_42:
        v24 = v18->TraitsClassClass.pObject;
      }
      else
      {
LABEL_37:
        ParentDomain = v17->ParentDomain;
        if ( ParentDomain && (v23 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, &mn)) != 0i64
          || (v23 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                      &v17->ClassTraitsSet,
                      &mn)) != 0i64 )
        {
          v24 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*v23;
        }
        else
        {
          v24 = 0i64;
        }
      }
      v25 = 0i64;
      if ( v24 )
        v25 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *))v24->vfptr[2].~RefCountBaseGC<328>)(v24);
      for ( j = v18->GlobalObjects.Data.Size; j; --j )
      {
        v27 = v18->GlobalObjects.Data.Data[j - 1];
        v28 = v27->pTraits.pObject;
        if ( !v24
          || v25 == ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v28->vfptr[2].~RefCountBaseGC<328>)(v27->pTraits.pObject) )
        {
          FixedTraits = Scaleform::GFx::AS3::FindFixedTraits(v18, v28, &mn, v17);
          if ( FixedTraits )
            break;
        }
      }
      if ( !FixedTraits )
      {
LABEL_66:
        v32 = (__int64)v44;
        Scaleform::GFx::AS3::VM::Error::Error(&v42, 1014, v44->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          *(Scaleform::GFx::AS3::VM **)(v32 + 128),
          v33,
          &Scaleform::GFx::AS3::fl::VerifyErrorTI);
        v34 = v42.Message.pNode;
        v13 = v42.Message.pNode->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
        if ( (mn.Name.Flags & 0x1F) > 9 )
        {
          if ( (mn.Name.Flags & 0x200) != 0 )
          {
            v13 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v13 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&mn.Name.Bonus, 0, 24);
            mn.Name.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
          }
        }
        v35 = mn.Obj.pObject;
        if ( mn.Obj.pObject )
        {
          if ( ((__int64)mn.Obj.pObject & 1) != 0 )
          {
            --mn.Obj.pObject;
          }
          else
          {
            RefCount = mn.Obj.pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              mn.Obj.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v35);
            }
          }
        }
        return;
      }
      v8 = i;
      File = v38;
      class_info = v41;
      This = v45;
    }
    v29 = FixedTraits->ITraits.pObject;
    if ( !v29 )
      goto LABEL_66;
    Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(This, File, v29);
    if ( (mn.Name.Flags & 0x1F) > 9 )
    {
      if ( (mn.Name.Flags & 0x200) != 0 )
      {
        v13 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&mn.Name.Bonus, 0, 24);
        mn.Name.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
      }
    }
    v30 = mn.Obj.pObject;
    if ( mn.Obj.pObject )
    {
      if ( ((__int64)mn.Obj.pObject & 1) != 0 )
      {
        --mn.Obj.pObject;
      }
      else
      {
        v31 = mn.Obj.pObject->RefCount;
        if ( (v31 & 0x3FFFFF) != 0 )
        {
          mn.Obj.pObject->RefCount = v31 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
        }
      }
    }
    i = ++v8;
    v5 = v44;
  }
}

