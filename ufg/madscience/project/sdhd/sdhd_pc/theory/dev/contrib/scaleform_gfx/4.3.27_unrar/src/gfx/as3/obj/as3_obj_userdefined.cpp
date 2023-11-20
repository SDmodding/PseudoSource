// File Line: 30
// RVA: 0x783BA0
void __fastcall Scaleform::GFx::AS3::Classes::UserDefined::UserDefined(Scaleform::GFx::AS3::Classes::UserDefined *this, Scaleform::GFx::AS3::ClassTraits::UserDefined *t)
{
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v2; // rbx
  Scaleform::GFx::AS3::Classes::UserDefined *v3; // rdi
  Scaleform::GFx::AS3::Traits *v4; // rcx
  Scaleform::GFx::AS3::VM *v5; // r9
  unsigned __int64 v6; // rdx
  char v7; // [rsp+48h] [rbp+10h]

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Class::Class(
    (Scaleform::GFx::AS3::Class *)&this->vfptr,
    (Scaleform::GFx::AS3::ClassTraits::Traits *)&t->vfptr);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::UDBase::`vftable;
  Scaleform::GFx::AS3::Traits::ConstructTail(
    (Scaleform::GFx::AS3::Traits *)&v2->vfptr,
    (Scaleform::GFx::AS3::Object *)&v3->vfptr);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::UserDefined::`vftable;
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::UserDefined *, char *, Scaleform::GFx::AS3::Classes::UserDefined *))v2->vfptr[2].Finalize_GC)(
                   v2,
                   &v7,
                   v3) )
  {
    v4 = v3->pTraits.pObject;
    v5 = v4->pVM;
    if ( v5->CallStack.Size )
      v6 = v5->CallStack.Pages[(v5->CallStack.Size - 1) >> 6][(LODWORD(v5->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
    else
      v6 = 0i64;
    Scaleform::GFx::AS3::Traits::StoreScopeStack(v4, v6, &v5->ScopeStack);
  }
}

// File Line: 47
// RVA: 0x7B2F60
void __fastcall Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(Scaleform::GFx::AS3::Classes::UserDefined *this)
{
  Scaleform::GFx::AS3::Classes::UserDefined *v1; // r9
  __int64 v2; // rbx
  Scaleform::GFx::AS3::Traits *v3; // rdx
  Scaleform::GFx::AS3::VMAbcFile *v4; // r14
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM *v9; // rcx
  Scaleform::GFx::AS3::ValueStack *v10; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v11; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v12; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v13; // rcx
  unsigned int v14; // eax
  unsigned __int64 v15; // rdi
  Scaleform::GFx::AS3::CallFrame **v16; // rax
  signed __int64 v17; // rcx
  Scaleform::GFx::AS3::CallFrame *v18; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::Value v20; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::AS3::Value _this; // [rsp+E0h] [rbp-20h]
  __int64 v22; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::AS3::VM::Error v23; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::AS3::CallFrame *v24; // [rsp+150h] [rbp+50h]
  Scaleform::GFx::AS3::CallFrame *v25; // [rsp+158h] [rbp+58h]

  v22 = -2i64;
  v1 = this;
  v2 = *(signed int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(this->pTraits.pObject[1].pRCCRaw + 152) + 224i64)
                                 + 8i64 * SLODWORD(this->pTraits.pObject[1].pNext[2].pNext))
                     + 8i64);
  _this.Flags = 13;
  _this.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&_this.value.VNumber = this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v20.Flags = 13;
  v20.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v20.value.VNumber = this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v3 = this->pTraits.pObject;
  v4 = (Scaleform::GFx::AS3::VMAbcFile *)v3[1]._pRCC;
  v5 = v3->pVM;
  if ( v5->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v23, eStackOverflowError, v3->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v6, &Scaleform::GFx::AS3::fl::ErrorTI);
    v7 = v23.Message.pNode;
    v8 = v23.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  else
  {
    *(_WORD *)&other.DiscardResult = 1;
    v9 = v4->VMRef;
    *(_OWORD *)&other.ScopeStackBaseInd = v9->ScopeStack.Data.Size;
    other.pRegisterFile = &v9->RegisterFile;
    other.pHeap = v9->MHeap;
    other.pFile = v4;
    other.MBIIndex.Ind = v2;
    other.pSavedScope = &v3->InitScope;
    other.OriginationTraits = v3;
    other.pScopeStack = &v9->ScopeStack;
    other.DefXMLNamespace.pObject = 0i64;
    other.Invoker.Flags = 13;
    other.Invoker.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&other.Invoker.value.VNumber = v1;
    other.Invoker.value.VS._2.VObj = v20.value.VS._2.VObj;
    v1->RefCount = (v1->RefCount + 1) & 0x8FBFFFFF;
    v10 = &v4->VMRef->OpStack;
    other.PrevInitialStackPos = v10->pCurrent;
    other.PrevFirstStackPos = v10->pStack;
    v11 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(v10, v11->max_stack + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v11->local_reg_count);
    v12 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *v12 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
        *v12);
      v24 = 0i64;
      if ( &v24 != (Scaleform::GFx::AS3::CallFrame **)v12 )
      {
        v13 = *v12;
        if ( *v12 )
        {
          if ( (unsigned __int8)v13 & 1 )
          {
            *v12 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v13 - 1);
          }
          else
          {
            v14 = v13->RefCount;
            if ( v14 & 0x3FFFFF )
            {
              v13->RefCount = v14 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
            }
          }
        }
        *v12 = 0i64;
      }
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      v4->File.pObject->Methods.Info.Data.Data[v4->File.pObject->MethodBodies.Info.Data.Data[v2]->method_info_ind],
      &_this,
      0,
      0i64);
    if ( v5->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      v15 = v5->CallStack.Size >> 6;
      if ( v15 >= v5->CallStack.NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v5->CallStack.gap0,
          v5->CallStack.Size >> 6);
      v16 = v5->CallStack.Pages;
      v17 = v5->CallStack.Size & 0x3F;
      v8 = &v16[v15][v17] == 0i64;
      v18 = &v16[v15][v17];
      v24 = v18;
      v25 = v18;
      if ( !v8 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v18, &other);
      ++v5->CallStack.Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
}

// File Line: 80
// RVA: 0x807A10
void __fastcall Scaleform::GFx::AS3::Classes::UserDefined::PostInit(Scaleform::GFx::AS3::Classes::UserDefined *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  unsigned int v5; // er13
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Traits *v7; // r11
  __int64 v8; // rbx
  Scaleform::GFx::AS3::Traits *v9; // rdx
  Scaleform::GFx::AS3::VMAbcFile *v10; // r15
  Scaleform::GFx::AS3::VM *v11; // r14
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM *v15; // rcx
  unsigned int v16; // ecx
  Scaleform::GFx::AS3::WeakProxy *v17; // rdx
  int v18; // eax
  long double v19; // rcx
  Scaleform::GFx::AS3::ValueStack *v20; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v21; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v22; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v23; // rcx
  unsigned int v24; // eax
  unsigned __int64 v25; // rdi
  Scaleform::GFx::AS3::CallFrame **v26; // rax
  signed __int64 v27; // rcx
  Scaleform::GFx::AS3::CallFrame *v28; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+8h] [rbp-79h]
  Scaleform::GFx::AS3::VM::Error v30; // [rsp+98h] [rbp+17h]
  __int64 v31; // [rsp+A8h] [rbp+27h]
  Scaleform::GFx::AS3::CallFrame *v32; // [rsp+E8h] [rbp+67h]

  v31 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = _this;
  v7 = this->pTraits.pObject;
  v8 = *(signed int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7[1].pRCCRaw + 152) + 224i64)
                                 + 8i64 * SLODWORD(v7[1].pNext->pPrev))
                     + 8i64);
  v9 = (Scaleform::GFx::AS3::Traits *)v7[1].vfptr;
  v10 = (Scaleform::GFx::AS3::VMAbcFile *)v7[1]._pRCC;
  v11 = v7->pVM;
  if ( v11->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v30, eStackOverflowError, v7->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v11, v12, &Scaleform::GFx::AS3::fl::ErrorTI);
    v13 = v30.Message.pNode;
    v14 = v30.Message.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    return;
  }
  *(_WORD *)&other.DiscardResult = 1;
  v15 = v10->VMRef;
  other.ScopeStackBaseInd = v15->ScopeStack.Data.Size;
  other.CP = 0i64;
  other.pRegisterFile = &v15->RegisterFile;
  other.pHeap = v15->MHeap;
  other.pFile = v10;
  other.MBIIndex.Ind = v8;
  other.pSavedScope = &v9->InitScope;
  other.OriginationTraits = v9;
  other.pScopeStack = &v15->ScopeStack;
  other.DefXMLNamespace.pObject = 0i64;
  v16 = v6->Flags;
  other.Invoker.Flags = v16;
  v17 = v6->Bonus.pWeakProxy;
  other.Invoker.Bonus.pWeakProxy = v6->Bonus.pWeakProxy;
  other.Invoker.value = v6->value;
  v18 = v16 & 0x1F;
  if ( v18 > 9 )
  {
    if ( (v16 >> 9) & 1 )
    {
      ++v17->RefCount;
      goto LABEL_16;
    }
    if ( v18 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v6->value.VNumber + 24i64);
    }
    else if ( v18 > 10 )
    {
      if ( v18 <= 15 )
      {
        v19 = v6->value.VNumber;
LABEL_13:
        if ( v19 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v19 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v19 + 32i64) + 1) & 0x8FBFFFFF;
        goto LABEL_16;
      }
      if ( v18 <= 17 )
      {
        v19 = *(double *)&v6->value.VS._2.VObj;
        goto LABEL_13;
      }
    }
  }
LABEL_16:
  v20 = &v10->VMRef->OpStack;
  other.PrevInitialStackPos = v20->pCurrent;
  other.PrevFirstStackPos = v20->pStack;
  v21 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
  Scaleform::GFx::AS3::ValueStack::Reserve(v20, v21->max_stack + 1);
  Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v21->local_reg_count);
  v22 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
  if ( *v22 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
      *v22);
    v32 = 0i64;
    if ( &v32 != (Scaleform::GFx::AS3::CallFrame **)v22 )
    {
      v23 = *v22;
      if ( *v22 )
      {
        if ( (unsigned __int8)v23 & 1 )
        {
          *v22 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v23 - 1);
        }
        else
        {
          v24 = v23->RefCount;
          if ( v24 & 0x3FFFFF )
          {
            v23->RefCount = v24 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v23->vfptr);
          }
        }
      }
      *v22 = 0i64;
    }
  }
  Scaleform::GFx::AS3::CallFrame::SetupRegisters(
    &other,
    v10->File.pObject->Methods.Info.Data.Data[v10->File.pObject->MethodBodies.Info.Data.Data[v8]->method_info_ind],
    v6,
    v5,
    v4);
  if ( v11->HandleException )
  {
    other.ACopy = 1;
  }
  else
  {
    v25 = v11->CallStack.Size >> 6;
    if ( v25 >= v11->CallStack.NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
        (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v11->CallStack.gap0,
        v11->CallStack.Size >> 6);
    v26 = v11->CallStack.Pages;
    v27 = v11->CallStack.Size & 0x3F;
    v14 = &v26[v25][v27] == 0i64;
    v28 = &v26[v25][v27];
    v32 = v28;
    *(_QWORD *)&v30.ID = v28;
    if ( !v14 )
      Scaleform::GFx::AS3::CallFrame::CallFrame(v28, &other);
    ++v11->CallStack.Size;
  }
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
}

// File Line: 123
// RVA: 0x783B20
void __fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::UserDefined(Scaleform::GFx::AS3::ClassTraits::UserDefined *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  Scaleform::GFx::AS3::Abc::ClassInfo *v4; // rsi
  Scaleform::GFx::AS3::VMAbcFile *v5; // rdi
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v6; // rbx

  v4 = info;
  v5 = file;
  v6 = this;
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits((Scaleform::GFx::AS3::ClassTraits::Traits *)&this->vfptr, vm, 0i64);
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::UserDefined::`vftable;
  v6->File.pObject = v5;
  if ( v5 )
    v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  v6->class_info = v4;
  v6->Flags |= 0x10ui64;
}

// File Line: 131
// RVA: 0x78ECF0
void __fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::~UserDefined(Scaleform::GFx::AS3::ClassTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v1; // rbx
  Scaleform::GFx::AS3::VMAbcFile *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // rcx
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::UserDefined::`vftable;
  v2 = this->File.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)v2 - 1);
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
  v4 = v1->ITraits.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v4 - 1);
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

// File Line: 135
// RVA: 0x810450
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::RegisterSlots(Scaleform::GFx::AS3::ClassTraits::UserDefined *this, Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::VMAbcFile *v2; // rbx
  Scaleform::GFx::AS3::Abc::ClassInfo *v3; // rdi
  Scaleform::GFx::AS3::CheckResult *v4; // r14
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v5; // rsi
  unsigned int parent_size; // eax
  bool v7; // zf
  Scaleform::GFx::AS3::CheckResult *v8; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h]

  v2 = this->File.pObject;
  v3 = this->class_info;
  v4 = result;
  v5 = this;
  parent_size = ((__int64 (*)(void))this->vfptr[2].ForEachChild_GC)();
  v7 = Scaleform::GFx::AS3::Traits::AddSlots(
         (Scaleform::GFx::AS3::Traits *)&v5->vfptr,
         &resulta,
         (Scaleform::GFx::AS3::Abc::HasTraits *)&v3->stat_info.obj_traits,
         v2,
         parent_size)->Result == 0;
  v8 = v4;
  v4->Result = !v7;
  return v8;
}

// File Line: 150
// RVA: 0x7EFFD0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::GetSuperClassTraits(Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  Scaleform::GFx::AS3::VMAbcFile *v2; // rdi
  __int64 v3; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *result; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h]

  v2 = file;
  v3 = info->inst_info.super_name_ind;
  if ( !(_DWORD)v3 )
    return 0i64;
  result = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
             v2->VMRef,
             (Scaleform::GFx::AS3::VMFile *)&v2->vfptr,
             &v2->File.pObject->Const_Pool.const_multiname.Data.Data[v3]);
  v5 = result;
  if ( !result )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eNotImplementedError, v2->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v2->VMRef, v6, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v7 = v9.Message.pNode;
    v8 = v9.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    result = v5;
  }
  return result;
}

// File Line: 171
// RVA: 0x7F57A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(Scaleform::GFx::AS3::ClassTraits::UserDefined *this, Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rbx
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v5; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v6; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rsi
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v9; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v10; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v13; // [rsp+60h] [rbp+18h]

  v2 = result;
  v3 = this;
  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::ClassTraits::UserDefined::GetSuperClassTraits(
                                                        this->File.pObject,
                                                        this->class_info);
  v5 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)v4;
  if ( !v3->pVM->HandleException )
  {
    v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->pParent;
    if ( !v3->pParent.pObject )
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v6, v4);
    if ( v3->ITraits.pObject )
    {
      v2->Result = 1;
      return v2;
    }
    v7.pV = 0i64;
    if ( v5 )
    {
      if ( !v5->ITraits.pObject )
      {
        Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(v5, &resulta);
        if ( v3->pVM->HandleException )
        {
          v2->Result = 0;
          return v2;
        }
      }
      v8 = v5->ITraits.pObject;
    }
    else
    {
      v8 = 0i64;
    }
    *(_QWORD *)&resulta.Result = v3->pVM->MHeap;
    v9 = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *, signed __int64, _QWORD))(**(_QWORD **)&resulta.Result + 80i64))(
                                                               v6,
                                                               232i64,
                                                               0i64);
    v13 = v9;
    if ( v9 )
    {
      Scaleform::GFx::AS3::InstanceTraits::UserDefined::UserDefined(v9, v3->File.pObject, v8, v3->class_info);
      v7.pV = v10;
    }
    Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
      (Scaleform::GFx::AS3::ClassTraits::Traits *)&v3->vfptr,
      v7);
    if ( !v3->pVM->HandleException )
    {
      Scaleform::GFx::AS3::ClassTraits::UserDefined::RegisterSlots(v3, v2);
      return v2;
    }
  }
  v2->Result = 0;
  return v2;
}

// File Line: 228
// RVA: 0x821120
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::SetupSlotValues(Scaleform::GFx::AS3::ClassTraits::UserDefined *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Object *for_obj)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::Traits::SetupSlotValues(
    (Scaleform::GFx::AS3::Traits *)&this->vfptr,
    result,
    this->File.pObject,
    (Scaleform::GFx::AS3::Abc::HasTraits *)&this->class_info->stat_info.obj_traits);
  return v3;
}

// File Line: 236
// RVA: 0x7EA270
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::GetGlobalObjectScript(Scaleform::GFx::AS3::ClassTraits::UserDefined *this)
{
  return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((__int64 (*)(void))this->ITraits.pObject->vfptr[3].ForEachChild_GC)();
}

// File Line: 241
// RVA: 0x7FA5D0
Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::MakeClass(Scaleform::GFx::AS3::ClassTraits::UserDefined *this, Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *v2; // rdi
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v3; // rbx
  Scaleform::GFx::AS3::Classes::UserDefined *v4; // rax
  Scaleform::GFx::AS3::Classes::UserDefined *v5; // rax
  Scaleform::GFx::AS3::Classes::UserDefined *v6; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // r8
  unsigned __int64 v9; // rdx
  long double v10; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-40h]
  int v13; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS3::Classes::UserDefined *v14; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::AS3::Classes::UserDefined *v15; // [rsp+80h] [rbp+18h]

  v2 = result;
  v3 = this;
  v13 = 337;
  v4 = (Scaleform::GFx::AS3::Classes::UserDefined *)this->pVM->MHeap->vfptr->Alloc(
                                                      this->pVM->MHeap,
                                                      this->MemSize,
                                                      (Scaleform::AllocInfo *)&v13);
  v14 = v4;
  v15 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Classes::UserDefined::UserDefined(v4, v3);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v2->pV = v6;
  v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
  v7 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)v3->ITraits.pObject;
  v8 = v3->pVM;
  if ( v8->CallStack.Size )
    v9 = v8->CallStack.Pages[(v8->CallStack.Size - 1) >> 6][(LODWORD(v8->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
  else
    v9 = 0i64;
  Scaleform::GFx::AS3::Traits::StoreScopeStack(
    (Scaleform::GFx::AS3::Traits *)&v3->ITraits.pObject->vfptr,
    v9,
    &v8->ScopeStack);
  v10 = *(double *)&v2->pV;
  source.Flags = 13;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v10;
  if ( v10 != 0.0 )
    *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v7 + 7,
    v7[8].Data,
    v7[7].Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v7[7].Data[v7[7].Size - 1], &source);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
  Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(v2->pV);
  return v2;
}

// File Line: 274
// RVA: 0x7E96D0
UFG::SimObject *__fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(UFG::TSVehicle *this)
{
  return this->mpSimObj.m_pPointer;
}

// File Line: 279
// RVA: 0x7D6770
void __fastcall Scaleform::GFx::AS3::ClassTraits::UserDefined::ForEachChild_GC(Scaleform::GFx::AS3::ClassTraits::UserDefined *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v5; // rsi

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Traits::ForEachChild_GC((Scaleform::GFx::AS3::Traits *)&this->vfptr, prcc, op);
  if ( v5->ITraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->File.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
}

// File Line: 300
// RVA: 0x783C60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::UserDefined(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::InstanceTraits::Traits *pt, Scaleform::GFx::AS3::Abc::ClassInfo *info)
{
  Scaleform::GFx::AS3::Abc::ClassInfo *v4; // rbp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // r14
  Scaleform::GFx::AS3::VMAbcFile *v6; // rsi
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v7; // rdi
  Scaleform::GFx::ASString *v8; // r13
  bool isFinal; // r15
  char v10; // r12
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned int v16; // eax
  Scaleform::GFx::AS3::Traits *v17; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+88h] [rbp+10h]

  v4 = info;
  v5 = pt;
  v6 = file;
  v7 = this;
  v8 = Scaleform::GFx::AS3::VMFile::GetInternedString(
         (Scaleform::GFx::AS3::VMFile *)&file->vfptr,
         (Scaleform::GFx::ASString *)&result,
         file->File.pObject->Const_Pool.const_multiname.Data.Data[info->inst_info.name_ind].NameIndex);
  isFinal = ((unsigned __int8)v4->inst_info.flags >> 1) & 1;
  v10 = v4->inst_info.flags & 1;
  v11 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
          (Scaleform::GFx::AS3::VMFile *)&v6->vfptr,
          v6->File.pObject->Const_Pool.const_multiname.Data.Data[v4->inst_info.name_ind].Ind);
  v12 = v11;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::Traits(
    (Scaleform::GFx::AS3::Traits *)&v7->vfptr,
    v6->VMRef,
    (Scaleform::GFx::AS3::Traits *)&v5->vfptr,
    v10 == 0,
    isFinal);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  v7->Ns.pObject = v12;
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable;
  v13 = v8->pNode;
  v7->Name = (Scaleform::GFx::ASString)v8->pNode;
  ++v13->RefCount;
  v14 = *(Scaleform::GFx::ASStringNode **)&result.Result;
  v15 = *(_DWORD *)(*(_QWORD *)&result.Result + 24i64) == 1;
  --v14->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::UserDefined::`vftable;
  v7->Script.pObject = 0i64;
  v7->class_info = v4;
  v7->Flags |= 0x10ui64;
  v7->Flags ^= (LODWORD(v7->Flags) ^ -(((unsigned __int8)v4->inst_info.flags >> 2) & 1)) & 4;
  if ( v5 )
  {
    v16 = v5->MemSize;
  }
  else
  {
    v17 = v7->pParent.pObject;
    if ( v17 )
      v16 = ((__int64 (*)(void))v17->vfptr[2].ForEachChild_GC)();
    else
      v16 = 56;
  }
  if ( Scaleform::GFx::AS3::Traits::AddSlots(
         (Scaleform::GFx::AS3::Traits *)&v7->vfptr,
         &result,
         (Scaleform::GFx::AS3::Abc::HasTraits *)&v4->inst_info.obj_traits,
         v6,
         v16)->Result )
    Scaleform::GFx::AS3::InstanceTraits::UserDefined::AddInterfaceSlots2This(
      v7,
      v6,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr);
}

// File Line: 341
// RVA: 0x799E20
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::AS3Constructor(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this, Scaleform::GFx::AS3::Traits *ot, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v5; // er12
  Scaleform::GFx::AS3::Value *v6; // r13
  Scaleform::GFx::AS3::Traits *v7; // r14
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v8; // rsi
  __int64 v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v10; // rdi
  Scaleform::GFx::AS3::Traits *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v12; // rdi
  __int64 v13; // rbx
  Scaleform::GFx::AS3::Traits *v14; // r15
  Scaleform::GFx::AS3::Traits *v15; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v16; // r14
  Scaleform::GFx::AS3::VM *v17; // rsi
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::AS3::VM *v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rcx
  Scaleform::GFx::AS3::Value::VU v24; // kr00_16
  int v25; // er8
  Scaleform::GFx::AS3::ValueStack *v26; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v27; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v28; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v29; // rcx
  unsigned int v30; // eax
  unsigned __int64 v31; // rdi
  Scaleform::GFx::AS3::CallFrame **v32; // rax
  signed __int64 v33; // rcx
  Scaleform::GFx::AS3::CallFrame *v34; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+30h] [rbp-91h]
  Scaleform::GFx::AS3::VM::Error v36; // [rsp+C0h] [rbp-1h]
  __int64 v37; // [rsp+D0h] [rbp+Fh]
  Scaleform::GFx::AS3::CallFrame *v38; // [rsp+120h] [rbp+5Fh]
  Scaleform::GFx::AS3::CallFrame *v39; // [rsp+128h] [rbp+67h]

  v37 = -2i64;
  v5 = argc;
  v6 = _this;
  v7 = ot;
  v8 = this;
  v9 = this->class_info->inst_info.method_info_ind;
  v10 = this->Script.pObject;
  if ( !v10->Initialized )
  {
    v10->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->Script.pObject->vfptr);
    v11 = v10->pTraits.pObject;
    if ( !v11->pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v11->pVM, 1u);
  }
  v12 = v8->Script.pObject;
  v13 = *(signed int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12->pTraits.pObject[1].FirstOwnSlotNum + 152) + 224i64)
                                  + 8 * v9)
                      + 8i64);
  v14 = v7->pParent.pObject;
  if ( !v12->Initialized )
  {
    v12->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->Script.pObject->vfptr);
    v15 = v12->pTraits.pObject;
    if ( !v15->pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v15->pVM, 1u);
  }
  v16 = (Scaleform::GFx::AS3::VMAbcFile *)v8->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v17 = v8->pVM;
  if ( v17->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v36, eStackOverflowError, v17);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v17, v18, &Scaleform::GFx::AS3::fl::ErrorTI);
    v19 = v36.Message.pNode;
    v20 = v36.Message.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  else
  {
    *(_WORD *)&other.DiscardResult = 1;
    v21 = v16->VMRef;
    other.ScopeStackBaseInd = v21->ScopeStack.Data.Size;
    other.CP = 0i64;
    other.pRegisterFile = &v21->RegisterFile;
    other.pHeap = v21->MHeap;
    other.pFile = v16;
    other.MBIIndex.Ind = v13;
    other.pSavedScope = &v14->InitScope;
    other.OriginationTraits = v14;
    other.pScopeStack = &v21->ScopeStack;
    other.DefXMLNamespace.pObject = 0i64;
    other.Invoker.Flags = v.Flags;
    other.Invoker.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v24 = v.value;
    v22 = *(_OWORD *)&v24 >> 64;
    v23 = (unsigned __int128)v24;
    other.Invoker.value = v.value;
    v25 = v.Flags & 0x1F;
    if ( v25 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( v25 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
      }
      else if ( v25 > 10 )
      {
        if ( v25 <= 15 )
        {
          if ( *(_QWORD *)&v.value.VNumber )
          {
            ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
            *(_DWORD *)(v23 + 32) &= 0x8FBFFFFF;
          }
        }
        else if ( v25 <= 17 && v.value.VS._2.VObj )
        {
          ++v.value.VS._2.VObj->RefCount;
          *(_DWORD *)(v22 + 32) &= 0x8FBFFFFF;
        }
      }
    }
    v26 = &v16->VMRef->OpStack;
    other.PrevInitialStackPos = v26->pCurrent;
    other.PrevFirstStackPos = v26->pStack;
    v27 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(v26, v27->max_stack + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v27->local_reg_count);
    v28 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *v28 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
        *v28);
      v38 = 0i64;
      if ( &v38 != (Scaleform::GFx::AS3::CallFrame **)v28 )
      {
        v29 = *v28;
        if ( *v28 )
        {
          if ( (unsigned __int8)v29 & 1 )
          {
            *v28 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v29 - 1);
          }
          else
          {
            v30 = v29->RefCount;
            if ( v30 & 0x3FFFFF )
            {
              v29->RefCount = v30 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v29->vfptr);
            }
          }
        }
        *v28 = 0i64;
      }
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      v16->File.pObject->Methods.Info.Data.Data[v16->File.pObject->MethodBodies.Info.Data.Data[v13]->method_info_ind],
      v6,
      v5,
      argv);
    if ( v17->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      v31 = v17->CallStack.Size >> 6;
      if ( v31 >= v17->CallStack.NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v17->CallStack.gap0,
          v17->CallStack.Size >> 6);
      v32 = v17->CallStack.Pages;
      v33 = v17->CallStack.Size & 0x3F;
      v20 = &v32[v31][v33] == 0i64;
      v34 = &v32[v31][v33];
      v38 = v34;
      v39 = v34;
      if ( !v20 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v34, &other);
      ++v17->CallStack.Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
}

// File Line: 380
// RVA: 0x7EF2C0
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetGlobalObjectScript(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v1; // rdi
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v2; // rbx
  Scaleform::GFx::AS3::VM *v3; // rcx

  v1 = this->Script.pObject;
  v2 = this;
  if ( v1->Initialized )
    return this->Script.pObject;
  v1->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->Script.pObject->vfptr);
  v3 = v1->pTraits.pObject->pVM;
  if ( !v3->HandleException )
    Scaleform::GFx::AS3::VM::ExecuteCode(v3, 1u);
  return v2->Script.pObject;
}

// File Line: 385
// RVA: 0x824D90
char __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::SupportsInterface(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this, Scaleform::GFx::AS3::InstanceTraits::Traits *itraits)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // r15
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v3; // rsi
  Scaleform::GFx::AS3::Abc::ClassInfo *v4; // r13
  unsigned __int64 v5; // r12
  __int64 v6; // r14
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v7; // rbx
  Scaleform::GFx::AS3::Traits *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v9; // rbx
  Scaleform::GFx::AS3::Abc::Multiname *v10; // rdi
  Scaleform::GFx::AS3::Traits *v11; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v12; // rbx
  Scaleform::GFx::AS3::Traits *v13; // rcx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v14; // rdi
  int v15; // ecx
  bool v16; // bl
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::AS3::VMAppDomain *v19; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v20; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v21; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v22; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v23; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::AS3::Multiname mn; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+40h]
  Scaleform::GFx::AS3::VM *v30; // [rsp+B0h] [rbp+50h]

  v2 = itraits;
  v3 = this;
  v4 = this->class_info;
  v30 = this->pVM;
  v5 = v4->inst_info.implemented_interfaces.info.Data.Size;
  v6 = 0i64;
  if ( !v5 )
    return 0;
  while ( 1 )
  {
    v7 = v3->Script.pObject;
    if ( !v7->Initialized )
    {
      v7->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->Script.pObject->vfptr);
      v8 = v7->pTraits.pObject;
      if ( !v8->pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v8->pVM, 1u);
    }
    v9 = v3->Script.pObject;
    v10 = (Scaleform::GFx::AS3::Abc::Multiname *)(*(_QWORD *)(*(_QWORD *)(v9->pTraits.pObject[1].FirstOwnSlotNum + 152)
                                                            + 176i64)
                                                + 16i64
                                                * v4->inst_info.implemented_interfaces.info.Data.Data[(unsigned int)v6]);
    if ( !v9->Initialized )
    {
      v9->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->Script.pObject->vfptr);
      v11 = v9->pTraits.pObject;
      if ( !v11->pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v11->pVM, 1u);
    }
    Scaleform::GFx::AS3::Multiname::Multiname(
      &mn,
      (Scaleform::GFx::AS3::VMFile *)v3->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum,
      v10);
    v12 = v3->Script.pObject;
    if ( !v12->Initialized )
    {
      v12->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->Script.pObject->vfptr);
      v13 = v12->pTraits.pObject;
      if ( !v13->pVM->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v13->pVM, 1u);
    }
    v14 = *(Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> **)(v3->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum
                                                                                                 + 48);
    v15 = mn.Name.Flags & 0x1F;
    if ( !(mn.Name.Flags & 0x1F) )
      goto LABEL_60;
    if ( (unsigned int)(v15 - 12) > 3 && v15 != 10 )
      goto LABEL_61;
    if ( !*(_QWORD *)&mn.Name.value.VNumber )
      goto LABEL_60;
    if ( v15 != 10 )
      goto LABEL_61;
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
    v16 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
    v17 = result.pNode;
    v18 = result.pNode->RefCount == 1;
    --v17->RefCount;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    if ( !v16 )
    {
LABEL_61:
      v19 = (Scaleform::GFx::AS3::VMAppDomain *)v14[2].Entries.mHash.pHeap;
      if ( !v19 || (v20 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v19, &mn)) == 0i64 )
      {
        v20 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(v14 + 3, &mn);
        if ( !v20 )
          goto LABEL_32;
      }
      v21 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)*v20;
    }
    else
    {
LABEL_60:
      v21 = v30->TraitsClassClass.pObject;
    }
    if ( v21 )
    {
      v22 = v21->ITraits.pObject;
      if ( v22 == v2
        || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v22->vfptr[4].~RefCountBaseGC<328>)(
             v22,
             v2) )
      {
        break;
      }
    }
LABEL_32:
    if ( (mn.Name.Flags & 0x1F) > 9 )
    {
      if ( (mn.Name.Flags >> 9) & 1 )
      {
        v18 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v18 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        mn.Name.Bonus.pWeakProxy = 0i64;
        mn.Name.value = 0ui64;
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
      if ( (_QWORD)mn.Obj.pObject & 1 )
      {
        --mn.Obj.pObject;
      }
      else
      {
        v24 = mn.Obj.pObject->RefCount;
        if ( v24 & 0x3FFFFF )
        {
          mn.Obj.pObject->RefCount = v24 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v23->vfptr);
        }
      }
    }
    if ( ++v6 >= v5 )
      return 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v18 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      mn.Name.Bonus.pWeakProxy = 0i64;
      mn.Name.value = 0ui64;
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
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v26 = mn.Obj.pObject->RefCount;
      if ( v26 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v26 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v25->vfptr);
      }
    }
  }
  return 1;
}

// File Line: 418
// RVA: 0x821150
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::SetupSlotValues(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Object *for_obj)
{
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v3; // rsi
  Scaleform::GFx::AS3::Traits *v4; // rcx
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v7; // rbx
  Scaleform::GFx::AS3::Abc::HasTraits *v8; // r14
  Scaleform::GFx::AS3::VM *v9; // rcx
  char v10; // [rsp+50h] [rbp+8h]

  v3 = this;
  v4 = this->pParent.pObject;
  v5 = result;
  if ( !v4
    || *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, char *))v4->vfptr[2].Finalize_GC)(v4, &v10) )
  {
    v7 = v3->Script.pObject;
    v8 = (Scaleform::GFx::AS3::Abc::HasTraits *)&v3->class_info->inst_info.obj_traits;
    if ( !v7->Initialized )
    {
      v7->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->Script.pObject->vfptr);
      v9 = v7->pTraits.pObject->pVM;
      if ( !v9->HandleException )
        Scaleform::GFx::AS3::VM::ExecuteCode(v9, 1u);
    }
    Scaleform::GFx::AS3::Traits::SetupSlotValues(
      (Scaleform::GFx::AS3::Traits *)&v3->vfptr,
      v5,
      (Scaleform::GFx::AS3::VMAbcFile *)v3->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum,
      v8);
    v6 = v5;
  }
  else
  {
    v5->Result = 0;
    v6 = v5;
  }
  return v6;
}

// File Line: 429
// RVA: 0x807DC0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::PreInit(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::UserDefined *, Scaleform::GFx::AS3::CheckResult *, _QWORD))this->vfptr[2].Finalize_GC)(
    this,
    result,
    *(_QWORD *)&_this->value.VNumber);
  return v3;
}

// File Line: 459
// RVA: 0x7D67D0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::ForEachChild_GC(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v5; // rsi

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Traits::ForEachChild_GC((Scaleform::GFx::AS3::Traits *)&this->vfptr, prcc, op);
  if ( v5->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->Script.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
}

// File Line: 466
// RVA: 0x7F3C30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::InitOnDemand(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v1; // rbx
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // rcx

  v1 = this->Script.pObject;
  v2 = this;
  if ( !v1->Initialized )
  {
    v1->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->Script.pObject->vfptr);
    v3 = v1->pTraits.pObject->pVM;
    if ( !v3->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v3, 1u);
  }
  v4 = v2->Script.pObject;
  if ( !v4->Initialized )
  {
    v4->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->Script.pObject->vfptr);
    v5 = v4->pTraits.pObject->pVM;
    if ( !v5->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v5, 1u);
  }
}

// File Line: 471
// RVA: 0x7E96E0
Scaleform::GFx::AS3::VMAbcFile *__fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v1; // rbx
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rcx

  v1 = this->Script.pObject;
  v2 = this;
  if ( !v1->Initialized )
  {
    v1->vfptr[6].Finalize_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->Script.pObject->vfptr);
    v3 = v1->pTraits.pObject->pVM;
    if ( !v3->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v3, 1u);
  }
  return (Scaleform::GFx::AS3::VMAbcFile *)v2->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum;
}

// File Line: 492
// RVA: 0x7AD080
void __fastcall Scaleform::GFx::AS3::InstanceTraits::UserDefined::AddInterfaceSlots2This(Scaleform::GFx::AS3::InstanceTraits::UserDefined *this, Scaleform::GFx::AS3::VMAbcFile *file_ptr, Scaleform::GFx::AS3::InstanceTraits::Traits *This)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // r12
  Scaleform::GFx::AS3::VMAbcFile *v4; // r15
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v5; // rbx
  __int64 v6; // r13
  Scaleform::GFx::AS3::VM *v7; // r14
  unsigned __int64 v8; // rsi
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v9; // rdi
  int v10; // ecx
  bool v11; // bl
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VMAppDomain *v14; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v15; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // r14
  Scaleform::GFx::AS3::VMAppDomain *v17; // r13
  Scaleform::GFx::AS3::VM *v18; // r15
  int v19; // ecx
  bool v20; // bl
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v22; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v23; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v24; // rsi
  __int64 v25; // r12
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Instances::fl::GlobalObject *v27; // rdx
  Scaleform::GFx::AS3::Traits *v28; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v29; // r8
  Scaleform::GFx::AS3::GASRefCountBase *v30; // rcx
  unsigned int v31; // eax
  __int64 v32; // rbx
  Scaleform::GFx::AS3::VM::Error *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v35; // rcx
  unsigned int v36; // eax
  Scaleform::GFx::AS3::Multiname mn; // [rsp+0h] [rbp-49h]
  Scaleform::GFx::AS3::VMAbcFile *v38; // [rsp+30h] [rbp-19h]
  unsigned __int64 v39; // [rsp+38h] [rbp-11h]
  Scaleform::GFx::ASString v40; // [rsp+40h] [rbp-9h]
  __int64 v41; // [rsp+48h] [rbp-1h]
  Scaleform::GFx::AS3::VM::Error v42; // [rsp+50h] [rbp+7h]
  __int64 v43; // [rsp+60h] [rbp+17h]
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v44; // [rsp+B0h] [rbp+67h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *v45; // [rsp+C0h] [rbp+77h]
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+7Fh]

  v43 = -2i64;
  v3 = This;
  v4 = file_ptr;
  v38 = file_ptr;
  v5 = this;
  if ( this->Script.pObject )
  {
    v4 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile(this);
    v38 = v4;
  }
  v6 = (__int64)v5->class_info;
  v41 = v6;
  v7 = v5->pVM;
  *(_QWORD *)&v42.ID = v5->pVM;
  v8 = 0i64;
  v39 = 0i64;
  if ( *(_QWORD *)(v6 + 56) )
  {
    do
    {
      Scaleform::GFx::AS3::Multiname::Multiname(
        &mn,
        (Scaleform::GFx::AS3::VMFile *)&v4->vfptr,
        &v4->File.pObject->Const_Pool.const_multiname.Data.Data[*(signed int *)(*(_QWORD *)(v6 + 48)
                                                                              + 4i64 * (unsigned int)v8)]);
      v9 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v4->AppDomain.pObject;
      v10 = mn.Name.Flags & 0x1F;
      if ( !(mn.Name.Flags & 0x1F) )
        goto LABEL_81;
      if ( (unsigned int)(v10 - 12) > 3 && v10 != 10 )
        goto LABEL_82;
      if ( !*(_QWORD *)&mn.Name.value.VNumber )
        goto LABEL_81;
      if ( v10 != 10 )
        goto LABEL_82;
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
      v11 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
      v12 = result.pNode;
      v13 = result.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v13 = v11 == 0;
      v5 = v44;
      if ( v13 )
      {
LABEL_82:
        v14 = (Scaleform::GFx::AS3::VMAppDomain *)v9[2].Entries.mHash.pHeap;
        if ( v14 && (v15 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v14, &mn)) != 0i64
          || (v15 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(v9 + 3, &mn)) != 0i64 )
        {
          v16 = *v15;
        }
        else
        {
          v16 = 0i64;
        }
      }
      else
      {
LABEL_81:
        v16 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v7->TraitsClassClass.pObject->vfptr;
      }
      if ( !v16 )
      {
        v17 = v4->AppDomain.pObject;
        v18 = v5->pVM;
        v19 = mn.Name.Flags & 0x1F;
        if ( !(mn.Name.Flags & 0x1F) )
          goto LABEL_83;
        if ( (unsigned int)(v19 - 12) > 3 && v19 != 10 )
          goto LABEL_84;
        if ( !*(_QWORD *)&mn.Name.value.VNumber )
          goto LABEL_83;
        if ( v19 != 10 )
          goto LABEL_84;
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &v40);
        v20 = !v40.pNode->Size || *v40.pNode->pData == pattern[0] && !*((_BYTE *)v40.pNode->pData + 1);
        v21 = v40.pNode;
        v13 = v40.pNode->RefCount == 1;
        --v21->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        if ( !v20 )
        {
LABEL_84:
          v22 = v17->ParentDomain;
          if ( v22 && (v23 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v22, &mn)) != 0i64
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
        else
        {
LABEL_83:
          v24 = v18->TraitsClassClass.pObject;
        }
        v25 = 0i64;
        if ( v24 )
          v25 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *))v24->vfptr[2].~RefCountBaseGC<328>)(v24);
        for ( i = v18->GlobalObjects.Data.Size; i; --i )
        {
          v27 = v18->GlobalObjects.Data.Data[i - 1];
          v28 = v27->pTraits.pObject;
          if ( !v24
            || v25 == ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v28->vfptr[2].~RefCountBaseGC<328>)(v27->pTraits.pObject) )
          {
            v16 = Scaleform::GFx::AS3::FindFixedTraits(v18, v28, &mn, v17);
            if ( v16 )
              break;
          }
        }
        if ( !v16 )
        {
LABEL_66:
          v32 = (__int64)v44;
          Scaleform::GFx::AS3::VM::Error::Error(&v42, eClassNotFoundError, v44->pVM);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            *(Scaleform::GFx::AS3::VM **)(v32 + 128),
            v33,
            &Scaleform::GFx::AS3::fl::VerifyErrorTI);
          v34 = v42.Message.pNode;
          v13 = v42.Message.pNode->RefCount == 1;
          --v34->RefCount;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v34);
          if ( (mn.Name.Flags & 0x1F) > 9 )
          {
            if ( (mn.Name.Flags >> 9) & 1 )
            {
              v13 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v13 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              mn.Name.Bonus.pWeakProxy = 0i64;
              mn.Name.value = 0ui64;
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
            if ( (_QWORD)mn.Obj.pObject & 1 )
            {
              --mn.Obj.pObject;
            }
            else
            {
              v36 = mn.Obj.pObject->RefCount;
              if ( v36 & 0x3FFFFF )
              {
                mn.Obj.pObject->RefCount = v36 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v35->vfptr);
              }
            }
          }
          return;
        }
        v8 = v39;
        v4 = v38;
        v6 = v41;
        v3 = v45;
      }
      v29 = v16->ITraits.pObject;
      if ( !v29 )
        goto LABEL_66;
      Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(v3, v4, v29);
      if ( (mn.Name.Flags & 0x1F) > 9 )
      {
        if ( (mn.Name.Flags >> 9) & 1 )
        {
          v13 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          mn.Name.Bonus.pWeakProxy = 0i64;
          mn.Name.value = 0ui64;
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
        if ( (_QWORD)mn.Obj.pObject & 1 )
        {
          --mn.Obj.pObject;
        }
        else
        {
          v31 = mn.Obj.pObject->RefCount;
          if ( v31 & 0x3FFFFF )
          {
            mn.Obj.pObject->RefCount = v31 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v30->vfptr);
          }
        }
      }
      v39 = ++v8;
      v5 = v44;
      v7 = *(Scaleform::GFx::AS3::VM **)&v42.ID;
    }
    while ( v8 < *(_QWORD *)(v6 + 56) );
  }
}

