// File Line: 59
// RVA: 0x783E10
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::UserDefinedFunction(Scaleform::GFx::AS3::UserDefinedFunction *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::FunctionHandler *pcontext, void *puserData)
{
  void *v4; // rsi
  Scaleform::GFx::Resource *v5; // rdi
  Scaleform::GFx::AS3::UserDefinedFunction *v6; // rbx
  Scaleform::Render::RenderBuffer *v7; // rcx

  v4 = puserData;
  v5 = (Scaleform::GFx::Resource *)pcontext;
  v6 = this;
  Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(
    (Scaleform::GFx::AS3::Instances::FunctionBase *)&this->vfptr,
    t);
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::UserDefinedFunction::`vftable';
  v6->pContext.pObject = 0i64;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef(v5);
  v7 = (Scaleform::Render::RenderBuffer *)v6->pContext.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v6->pContext.pObject = (Scaleform::GFx::FunctionHandler *)v5;
  v6->pUserData = v4;
}

// File Line: 68
// RVA: 0x7D0EF0
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::ExecuteUnsafe(Scaleform::GFx::AS3::UserDefinedFunction *this, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc)
{
  Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(this, _this, result, argc);
}

// File Line: 72
// RVA: 0x7CA930
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::Execute(Scaleform::GFx::AS3::UserDefinedFunction *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool discard_result)
{
  Scaleform::GFx::AS3::UserDefinedFunction *v5; // rdi
  Scaleform::GFx::AS3::WeakProxy *v6; // rdx
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::VM *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::Value *v10; // rax
  long double v11; // r8
  Scaleform::GFx::AS3::Value::V2U v12; // r9
  int v13; // ecx
  Scaleform::GFx::AS3::Value v14; // [rsp+48h] [rbp-30h]

  v5 = this;
  v14.Flags = 0;
  v14.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(this, _this, &v14, argc, argv);
  v6 = v14.Bonus.pWeakProxy;
  v7 = v14.Flags;
  if ( !discard_result )
  {
    v8 = v5->pTraits.pObject->pVM;
    v9 = v8->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
    ++v8->OpStack.pCurrent;
    v10 = v8->OpStack.pCurrent;
    if ( !v9 )
    {
      v10->Flags = v7;
      v10->Bonus.pWeakProxy = v6;
      v11 = v14.value.VNumber;
      v10->value.VNumber = v14.value.VNumber;
      v12.VObj = (Scaleform::GFx::AS3::Object *)v14.value.VS._2;
      v10->value.VS._2.VObj = v14.value.VS._2.VObj;
      v13 = v7 & 0x1F;
      if ( v13 > 9 )
      {
        if ( (v7 >> 9) & 1 )
        {
          ++v6->RefCount;
        }
        else if ( v13 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v11 + 24i64);
        }
        else if ( v13 > 10 )
        {
          if ( v13 <= 15 )
          {
            if ( v11 != 0.0 )
              *(_DWORD *)(*(_QWORD *)&v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v11 + 32i64) + 1) & 0x8FBFFFFF;
          }
          else if ( v13 <= 17 && v12.VObj )
          {
            v12.VObj->RefCount = (v12.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
    }
  }
  if ( (char)(v7 & 0x1F) > 9 )
  {
    if ( (v7 >> 9) & 1 )
    {
      v9 = v6->RefCount-- == 1;
      if ( v9 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v14.Bonus.pWeakProxy = 0i64;
      v14.value = 0ui64;
      v14.Flags = v7 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
    }
  }
}

// File Line: 79
// RVA: 0x7EBD00
signed __int64 __fastcall Scaleform::GFx::AS3::UserDefinedFunction::GetMaxParamNum(Scaleform::GFx::AS3::UserDefinedFunction *this)
{
  return 4095i64;
}

// File Line: 88
// RVA: 0x7CEE20
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(Scaleform::GFx::AS3::UserDefinedFunction *this, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc)
{
  __int64 v4; // r14
  Scaleform::GFx::AS3::Value *v5; // r12
  Scaleform::GFx::AS3::UserDefinedFunction *v6; // r15
  Scaleform::GFx::AS3::VM *v7; // r13
  Scaleform::GFx::AS3::MovieRoot *v8; // rsi
  Scaleform::GFx::Value *v9; // rdx
  Scaleform::GFx::AS3::Value *v10; // rbx
  __int64 v11; // rdi
  Scaleform::GFx::Value *v12; // rdx
  unsigned __int64 v13; // rdi
  Scaleform::GFx::Value *v14; // rdx
  Scaleform::GFx::Value *v15; // rbx
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-B8h]
  Scaleform::GFx::Value pdestVal; // [rsp+38h] [rbp-A0h]
  Scaleform::GFx::Value gfxVal; // [rsp+68h] [rbp-70h]
  __int64 v19; // [rsp+98h] [rbp-40h]
  Scaleform::GFx::Value::ObjectInterface **v20; // [rsp+A8h] [rbp-30h]
  void *(__fastcall *v21)(Scaleform::GFx::AS3::VM *, unsigned int); // [rsp+B0h] [rbp-28h]
  Scaleform::GFx::Value *v22; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::Value *v23; // [rsp+C0h] [rbp-18h]
  Scaleform::GFx::Value *v24; // [rsp+C8h] [rbp-10h]
  int v25; // [rsp+D0h] [rbp-8h]
  void *v26; // [rsp+D8h] [rbp+0h]
  __int64 v27; // [rsp+E0h] [rbp+8h]
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *v28; // [rsp+118h] [rbp+40h]
  Scaleform::GFx::AS3::Value *retaddr; // [rsp+138h] [rbp+60h]

  v27 = -2i64;
  v4 = argc;
  v5 = result;
  v6 = this;
  v28 = &pheapAddr;
  pheapAddr.Data = 0i64;
  *(_OWORD *)&pheapAddr.Size = 0ui64;
  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = 0;
  gfxVal.mValue.NValue = 0.0;
  LODWORD(gfxVal.DataAux) = 0;
  v7 = this->pTraits.pObject->pVM;
  v8 = (Scaleform::GFx::AS3::MovieRoot *)v7[1].vfptr;
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue((Scaleform::GFx::AS3::MovieRoot *)v7[1].vfptr, _this, &pdestVal);
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  v9 = &pheapAddr.Data[pheapAddr.Size - 1];
  v28 = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
  gfxVal.pNext = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( v9 )
  {
    v9->pObjectInterface = 0i64;
    v9->Type = pdestVal.Type;
    v9->mValue.NValue = pdestVal.mValue.NValue;
    v9->DataAux = pdestVal.DataAux;
    if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
    {
      v9->pObjectInterface = pdestVal.pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))pdestVal.pObjectInterface->vfptr->gap8)(
        pdestVal.pObjectInterface,
        v9,
        *(_QWORD *)&v9->mValue.NValue);
    }
  }
  if ( (_DWORD)v4 )
  {
    v10 = retaddr;
    v11 = v4;
    do
    {
      gfxVal.pObjectInterface = 0i64;
      pdestVal.mValue.IValue = 0;
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v8, v10, &gfxVal);
      Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v12 = &pheapAddr.Data[pheapAddr.Size - 1];
      v28 = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
      gfxVal.pNext = &pheapAddr.Data[pheapAddr.Size - 1];
      if ( v12 )
      {
        v12->pObjectInterface = 0i64;
        v12->Type = pdestVal.mValue.IValue;
        *(_QWORD *)&v12->mValue.NValue = pdestVal.DataAux;
        v12->DataAux = (unsigned __int64)gfxVal.pPrev;
        if ( ((unsigned int)pdestVal.mValue.IValue >> 6) & 1 )
        {
          v12->pObjectInterface = gfxVal.pObjectInterface;
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))gfxVal.pObjectInterface->vfptr->gap8)(
            gfxVal.pObjectInterface,
            v12,
            *(_QWORD *)&v12->mValue.NValue);
        }
      }
      if ( ((unsigned int)pdestVal.mValue.IValue >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&gfxVal.pObjectInterface->vfptr->gap8[8])(
          gfxVal.pObjectInterface,
          &gfxVal,
          pdestVal.DataAux);
        gfxVal.pObjectInterface = 0i64;
      }
      pdestVal.mValue.IValue = 0;
      ++v10;
      --v11;
    }
    while ( v11 );
  }
  v21 = v7[1].vfptr[2].__vecDelDtor;
  v20 = &gfxVal.pObjectInterface;
  v22 = &pdestVal;
  if ( (_DWORD)v4 )
    v24 = pheapAddr.Data + 1;
  else
    v24 = 0i64;
  v23 = pheapAddr.Data;
  v25 = LODWORD(pheapAddr.Size) - 1;
  v26 = v6->pUserData;
  v6->pContext.pObject->vfptr[1].__vecDelDtor(
    (Scaleform::RefCountImplCore *)&v6->pContext.pObject->vfptr,
    (unsigned int)&v20);
  if ( gfxVal.DataAux & 0x8F )
    Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v8, (Scaleform::GFx::Value *)((char *)&gfxVal + 16), v5);
  if ( (LODWORD(gfxVal.DataAux) >> 6) & 1 )
  {
    (*((void (__fastcall **)(_QWORD, Scaleform::GFx::Value::ObjectInterface **, __int64))*gfxVal.mValue.pStringManaged
     + 2))(
      *(_QWORD *)&gfxVal.mValue.NValue,
      &gfxVal.pObjectInterface,
      v19);
    gfxVal.mValue.NValue = 0.0;
  }
  LODWORD(gfxVal.DataAux) = 0;
  if ( ((unsigned int)pdestVal.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      *(_QWORD *)&pdestVal.mValue.NValue);
    pdestVal.pObjectInterface = 0i64;
  }
  pdestVal.Type = 0;
  v28 = &pheapAddr;
  v13 = pheapAddr.Size;
  v14 = pheapAddr.Data;
  v15 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    do
    {
      if ( ((unsigned int)v15->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v15->pObjectInterface->vfptr->gap8[8])(
          v15->pObjectInterface,
          v15,
          *(_QWORD *)&v15->mValue.NValue);
        v15->pObjectInterface = 0i64;
      }
      v15->Type = 0;
      --v15;
      --v13;
    }
    while ( v13 );
    v14 = pheapAddr.Data;
  }
  if ( v14 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 221
// RVA: 0x7E5C70
Scaleform::AmpStats *__fastcall Scaleform::GFx::AS2ValueObjectInterface::GetAdvanceStats(Scaleform::GFx::AS2ValueObjectInterface *this)
{
  return this->pMovieRoot->pASMovieRoot.pObject->pMovieImpl->AdvanceStats.pObject;
}

// File Line: 226
// RVA: 0x802A40
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::ObjectAddRef(Scaleform::GFx::AS3ValueObjectInterface *this, Scaleform::GFx::Value *val, void *pobj)
{
  Scaleform::GFx::Value *v3; // rbx
  Scaleform::GFx::AS3ValueObjectInterface *v4; // rdi
  __int32 v5; // eax

  v3 = val;
  v4 = this;
  v5 = val->Type & 0x8F;
  if ( v5 == 6 )
  {
    ++*((_DWORD *)pobj + 6);
    goto LABEL_10;
  }
  if ( v5 == 7 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pobj - 1);
    goto LABEL_10;
  }
  if ( v5 > 7 )
  {
    if ( v5 <= 10 )
    {
LABEL_7:
      *((_DWORD *)pobj + 8) = (*((_DWORD *)pobj + 8) + 1) & 0x8FBFFFFF;
      goto LABEL_10;
    }
    if ( v5 == 11 )
    {
      pobj = (void *)((unsigned __int64)pobj & 0xFFFFFFFFFFFFFFFDui64);
      goto LABEL_7;
    }
  }
LABEL_10:
  v3->pPrev = v4->ExternalObjRefs.Root.pPrev;
  v3->pNext = (Scaleform::GFx::Value *)&v4->ExternalObjRefs;
  v4->ExternalObjRefs.Root.pPrev->pNext = v3;
  v4->ExternalObjRefs.Root.pPrev = v3;
}

// File Line: 267
// RVA: 0x802AC0
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::ObjectRelease(Scaleform::GFx::AS3ValueObjectInterface *this, Scaleform::GFx::Value *val, void *pobj)
{
  Scaleform::GFx::Value *v3; // rbx
  __int32 v4; // eax
  int v5; // eax
  bool v6; // zf

  v3 = val;
  v4 = val->Type & 0x8F;
  if ( v4 == 6 )
  {
    v6 = (*((_DWORD *)pobj + 6))-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pobj);
  }
  else
  {
    if ( v4 == 7 )
    {
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)((char *)pobj - 24));
      goto LABEL_12;
    }
    if ( v4 > 7 )
    {
      if ( v4 > 10 )
      {
        if ( v4 != 11 )
          goto LABEL_12;
        pobj = (void *)((unsigned __int64)pobj & 0xFFFFFFFFFFFFFFFDui64);
      }
      v5 = *((_DWORD *)pobj + 8);
      if ( v5 & 0x3FFFFF )
      {
        *((_DWORD *)pobj + 8) = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pobj);
      }
    }
  }
LABEL_12:
  v3->pPrev->pNext = v3->pNext;
  v3->pNext->pPrev = v3->pPrev;
}

// File Line: 315
// RVA: 0x7F2050
_BOOL8 __fastcall Scaleform::GFx::AS3ValueObjectInterface::HasMember(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *name, bool isdobj)
{
  const char *v4; // r12
  Scaleform::GFx::AS3::Object *v5; // r14
  Scaleform::GFx::ASMovieRootBase *v6; // rsi
  Scaleform::RefCountImplCoreVtbl *v7; // r15
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v8; // r13
  unsigned int v9; // edi
  Scaleform::GFx::ASStringNode *v10; // rbx
  Scaleform::GFx::AS3::Value::V2U v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rdx
  int v13; // esi
  const char *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Traits *v20; // r9
  __int64 v21; // rdx
  signed __int64 v22; // rcx
  __int64 v23; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v24; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v25; // rbx
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int v27; // eax
  bool v28; // bl
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::Multiname mn; // [rsp+20h] [rbp-79h]
  Scaleform::GFx::AS3::Value v34; // [rsp+50h] [rbp-49h]
  Scaleform::GFx::AS3::PropRef v35; // [rsp+70h] [rbp-29h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+7h]
  Scaleform::GFx::AS3::Value::V2U v37; // [rsp+A8h] [rbp+Fh]
  __int64 v38; // [rsp+B0h] [rbp+17h]
  Scaleform::GFx::ASString v39; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::ASString namea; // [rsp+108h] [rbp+6Fh]

  v38 = -2i64;
  v4 = name;
  v5 = (Scaleform::GFx::AS3::Object *)pdata;
  v6 = this->pMovieRoot->pASMovieRoot.pObject;
  v7 = v6[2].vfptr;
  v8 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)&v6[9];
  v9 = 10;
  v34.Flags = 10;
  v34.Bonus.pWeakProxy = 0i64;
  v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)&v6[9],
          &result,
          name)->pNode;
  *(_QWORD *)&v34.value.VNumber = v10;
  if ( v10 == &v10->pManager->NullStringNode )
  {
    v10 = 0i64;
    v34.value.VNumber = 0.0;
    v11.VObj = v37.VObj;
    v34.value.VS._2 = v37;
    v9 = 12;
    v34.Flags = 12;
  }
  else
  {
    ++v10->RefCount;
    v11.VObj = (Scaleform::GFx::AS3::Object *)v34.value.VS._2;
  }
  v12 = (Scaleform::GFx::AS3::GASRefCountBase *)v6[2].vfptr[53].__vecDelDtor;
  mn.Kind = 0;
  mn.Obj.pObject = v12;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0i64;
  v13 = v9 & 0x1F;
  if ( (unsigned int)(v13 - 12) <= 3
    && v10
    && (v14 = v10[1].pData, *((_DWORD *)v14 + 30) == 17)
    && ~((const unsigned __int8)v14[112] >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&mn.Name, (Scaleform::GFx::ASString *)&v10[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v10[1].RefCount);
    mn.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rbp+57h+var_A0.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&mn.Name.Flags = *(_QWORD *)&v34.Flags;
    mn.Name.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&mn.Name.value.VNumber = v10;
    mn.Name.value.VS._2 = v11;
    if ( v13 > 9 )
    {
      if ( (v9 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v13 == 10 )
      {
        ++v10->RefCount;
      }
      else if ( v13 > 10 )
      {
        if ( v13 <= 15 )
        {
          if ( v10 )
            v10->Size = (v10->Size + 1) & 0x8FBFFFFF;
        }
        else if ( v13 <= 17 && v11.VObj )
        {
          v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (mn.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &v39);
      if ( v39.pNode->Size )
      {
        if ( *v39.pNode->pData == 64 )
        {
          mn.Kind |= 8u;
          v15 = Scaleform::GFx::ASString::Substring(&v39, &namea, 1, v39.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&mn.Name, v15);
          v16 = namea.pNode;
          v17 = namea.pNode->RefCount == 1;
          --v16->RefCount;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
      }
      v18 = v39.pNode;
      v17 = v39.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  if ( v13 > 9 )
  {
    if ( (v9 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v34.Bonus.pWeakProxy = 0i64;
      v34.value = 0ui64;
      v34.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
    }
  }
  v19 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  v35.pSI = 0i64;
  v35.SlotIndex = 0i64;
  v35.This.Flags = 0;
  v35.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Object::FindProperty(v5, &v35, &mn, 0);
  if ( v35.This.Flags & 0x1F
    && (!((_QWORD)v35.pSI & 1) || (_QWORD)v35.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(v35.pSI) >> 1) & 1) || (_QWORD)v35.pSI & 0xFFFFFFFFFFFFFFFDui64)
    || (v20 = v5->pTraits.pObject, (unsigned int)(v20->TraitsType - 29) >= 5)
    || !(~(LOBYTE(v20->Flags) >> 5) & 1) )
  {
    v28 = v35.This.Flags & 0x1F
       && (!((_QWORD)v35.pSI & 1) || (_QWORD)v35.pSI & 0xFFFFFFFFFFFFFFFEui64)
       && (!((LOBYTE(v35.pSI) >> 1) & 1) || (_QWORD)v35.pSI & 0xFFFFFFFFFFFFFFFDui64);
  }
  else
  {
    v21 = 0i64;
    if ( (*(_WORD *)(*(_QWORD *)&v5[1].RefCount + 106i64) >> 9) & 1 )
      v21 = *(_QWORD *)&v5[1].RefCount;
    if ( !v21
      || (v22 = v21 + 4i64 * *(unsigned __int8 *)(v21 + 109),
          v23 = (*(__int64 (__fastcall **)(signed __int64, __int64, _QWORD))(*(_QWORD *)v22 + 40i64))(
                  v22,
                  v21,
                  v35.This.Flags & 0x1F),
          v24 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v23 - 72),
          !v23) )
    {
      v24 = 0i64;
    }
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(v8, &namea, v4);
    v25 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
            v24,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&v39,
            &namea)->pObject;
    v26 = v39.pNode;
    if ( v39.pNode )
    {
      if ( (_QWORD)v39.pNode & 1 )
      {
        --v39.pNode;
      }
      else
      {
        v27 = v39.pNode->Size;
        if ( v27 & 0x3FFFFF )
        {
          v39.pNode->Size = v27 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v26);
        }
      }
    }
    if ( v25 )
    {
      v28 = 1;
    }
    else
    {
      if ( LOBYTE(v7[21].__vecDelDtor) )
        LOBYTE(v7[21].__vecDelDtor) = 0;
      v28 = 0;
    }
    v29 = namea.pNode;
    v17 = namea.pNode->RefCount == 1;
    --v29->RefCount;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  }
  if ( (v35.This.Flags & 0x1F) > 9 )
  {
    if ( (v35.This.Flags >> 9) & 1 )
    {
      v17 = v35.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v35.This.Bonus.pWeakProxy = 0i64;
      v35.This.value = 0ui64;
      v35.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v35.This);
    }
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v17 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
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
  return v28;
}

// File Line: 358
// RVA: 0x7EBD10
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetMember(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *name, Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::Value *v4; // rdi
  _QWORD *v5; // r12
  Scaleform::GFx::AS3::MovieRoot *v6; // r13
  Scaleform::GFx::AS3::VM *v7; // r15
  unsigned int v8; // esi
  Scaleform::GFx::ASStringNode *v9; // rbx
  Scaleform::GFx::AS3::Value::V2U v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rdx
  int v12; // er14
  const char *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v22; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v23; // rbx
  Scaleform::GFx::ASStringNode *v24; // rcx
  unsigned int v25; // eax
  unsigned int v26; // ebx
  unsigned __int8 v27; // bl
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+20h] [rbp-71h]
  int v33; // [rsp+40h] [rbp-51h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v34; // [rsp+48h] [rbp-49h]
  Scaleform::GFx::AS3::Value v35; // [rsp+50h] [rbp-41h]
  Scaleform::GFx::AS3::Value value; // [rsp+70h] [rbp-21h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp-1h]
  Scaleform::GFx::AS3::Value::V2U v38; // [rsp+98h] [rbp+7h]
  __int64 v39; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::ASString v40; // [rsp+F0h] [rbp+5Fh]
  Scaleform::GFx::ASString namea; // [rsp+F8h] [rbp+67h]
  char *pstr; // [rsp+100h] [rbp+6Fh]

  pstr = (char *)name;
  v39 = -2i64;
  v4 = pval;
  v5 = pdata;
  v6 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = (Scaleform::GFx::AS3::VM *)&v6->pAVM.pObject->vfptr;
  v8 = 10;
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->BuiltinsMgr.Builtins,
         &result,
         name)->pNode;
  *(_QWORD *)&other.value.VNumber = v9;
  if ( v9 == &v9->pManager->NullStringNode )
  {
    v9 = 0i64;
    other.value.VNumber = 0.0;
    v10.VObj = v38.VObj;
    other.value.VS._2 = v38;
    v8 = 12;
    other.Flags = 12;
  }
  else
  {
    ++v9->RefCount;
    v10.VObj = (Scaleform::GFx::AS3::Object *)other.value.VS._2;
  }
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7->PublicNamespace.pObject;
  v33 = 0;
  v34.pObject = v11;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  v35.Flags = 0;
  v35.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && v9
    && (v13 = v9[1].pData, *((_DWORD *)v13 + 30) == 17)
    && ~((const unsigned __int8)v13[112] >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v35, (Scaleform::GFx::ASString *)&v9[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v34,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v9[1].RefCount);
    v33 &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rbp+4Fh+other.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v35.Flags = *(_QWORD *)&other.Flags;
    v35.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v35.value.VNumber = v9;
    v35.value.VS._2 = v10;
    if ( v12 > 9 )
    {
      if ( (v8 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v12 == 10 )
      {
        ++v9->RefCount;
      }
      else if ( v12 > 10 )
      {
        if ( v12 <= 15 )
        {
          if ( v9 )
            v9->Size = (v9->Size + 1) & 0x8FBFFFFF;
        }
        else if ( v12 <= 17 && v10.VObj )
        {
          v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (v35.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v35, &v40);
      if ( v40.pNode->Size )
      {
        if ( *v40.pNode->pData == 64 )
        {
          v33 |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v40, &namea, 1, v40.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v35, v14);
          v15 = namea.pNode;
          v16 = namea.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = v40.pNode;
      v16 = v40.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( v12 > 9 )
  {
    if ( (v8 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v8 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  v18 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(_QWORD *, Scaleform::GFx::ASString *, int *, Scaleform::GFx::AS3::Value *))(*v5 + 32i64))(
                   v5,
                   &v40,
                   &v33,
                   &value) )
  {
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v6, &value, v4);
    if ( v7->HandleException )
    {
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
      v27 = 0;
    }
    else
    {
      v27 = 1;
    }
  }
  else
  {
    v19 = v5[5];
    if ( (unsigned int)(*(_DWORD *)(v19 + 120) - 29) < 5 && ~(*(_BYTE *)(v19 + 112) >> 5) & 1 )
    {
      v20 = 0i64;
      if ( (*(_WORD *)(v5[11] + 106i64) >> 9) & 1 )
        v20 = v5[11];
      if ( !v20
        || (v21 = (*(__int64 (**)(void))(*(_QWORD *)(v20 + 4i64 * *(unsigned __int8 *)(v20 + 109)) + 40i64))(),
            v22 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v21 - 72),
            !v21) )
      {
        v22 = 0i64;
      }
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->BuiltinsMgr.Builtins,
        &namea,
        pstr);
      v23 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
              v22,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&v40,
              &namea)->pObject;
      v24 = v40.pNode;
      if ( v40.pNode )
      {
        if ( (_QWORD)v40.pNode & 1 )
        {
          --v40.pNode;
        }
        else
        {
          v25 = v40.pNode->Size;
          if ( v25 & 0x3FFFFF )
          {
            v40.pNode->Size = v25 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v24);
          }
        }
      }
      if ( v23 )
      {
        other.Flags = 12;
        other.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&other.value.VNumber = v23;
        v23->RefCount = (v23->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(&value, &other);
        v26 = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags >> 9) & 1 )
          {
            v16 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            other.Bonus.pWeakProxy = 0i64;
            other.value = 0ui64;
            other.Flags = v26 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v6, &value, v4);
        v27 = 1;
      }
      else
      {
        if ( v7->HandleException )
          v7->HandleException = 0;
        if ( ((unsigned int)v4->Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v4->pObjectInterface->vfptr->gap8[8])(
            v4->pObjectInterface,
            v4,
            *(_QWORD *)&v4->mValue.NValue);
          v4->pObjectInterface = 0i64;
        }
        v4->Type = 0;
        v27 = 0;
      }
      v28 = namea.pNode;
      v16 = namea.pNode->RefCount == 1;
      --v28->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    }
    else
    {
      if ( v7->HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
      if ( ((unsigned int)v4->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v4->pObjectInterface->vfptr->gap8[8])(
          v4->pObjectInterface,
          v4,
          *(_QWORD *)&v4->mValue.NValue);
        v4->pObjectInterface = 0i64;
      }
      v4->Type = 0;
      v27 = 0;
    }
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v16 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  if ( (v35.Flags & 0x1F) > 9 )
  {
    if ( (v35.Flags >> 9) & 1 )
    {
      v16 = v35.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v35.Bonus.pWeakProxy = 0i64;
      v35.value = 0ui64;
      v35.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
    }
  }
  v29 = v34.pObject;
  if ( v34.pObject )
  {
    if ( (_QWORD)v34.pObject & 1 )
    {
      --v34.pObject;
    }
    else
    {
      v30 = v34.pObject->RefCount;
      if ( v30 & 0x3FFFFF )
      {
        v34.pObject->RefCount = v30 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v29->vfptr);
      }
    }
  }
  return v27;
}

// File Line: 414
// RVA: 0x81A110
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetMember(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *name, Scaleform::GFx::Value *value)
{
  const char *v4; // r12
  _QWORD *v5; // r15
  Scaleform::GFx::AS3::MovieRoot *v6; // r13
  Scaleform::GFx::AS3::VM *v7; // r14
  unsigned int v8; // edi
  Scaleform::GFx::ASStringNode *v9; // rbx
  unsigned __int64 v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rdx
  int v12; // esi
  const char *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v22; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v23; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v24; // rcx
  unsigned int v25; // eax
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned __int8 v27; // bl
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v29; // rcx
  unsigned int v30; // eax
  int v32; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v33; // [rsp+28h] [rbp-D8h]
  Scaleform::GFx::AS3::Value v34; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ASString namea; // [rsp+50h] [rbp-B0h]
  Scaleform::String v36; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v37; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> v39; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::ASString v40; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp-50h]
  __int64 v42; // [rsp+B8h] [rbp-48h]
  __int64 v43; // [rsp+C0h] [rbp-40h]
  unsigned __int64 v44; // [rsp+C8h] [rbp-38h]
  Scaleform::MsgFormat::Sink r; // [rsp+D0h] [rbp-30h]
  Scaleform::MsgFormat v46; // [rsp+F0h] [rbp-10h]
  char v47; // [rsp+540h] [rbp+440h]
  Scaleform::GFx::ASString v48; // [rsp+548h] [rbp+448h]
  char *v; // [rsp+550h] [rbp+450h]
  Scaleform::GFx::Value *gfxVal; // [rsp+558h] [rbp+458h]

  gfxVal = value;
  v = (char *)name;
  v42 = -2i64;
  v4 = name;
  v5 = pdata;
  v6 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = (Scaleform::GFx::AS3::VM *)&v6->pAVM.pObject->vfptr;
  v8 = 10;
  v37.Flags = 10;
  v37.Bonus.pWeakProxy = 0i64;
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->BuiltinsMgr.Builtins,
         &result,
         name)->pNode;
  *(_QWORD *)&v37.value.VNumber = v9;
  if ( v9 == &v9->pManager->NullStringNode )
  {
    v9 = 0i64;
    v43 = 0i64;
    v37.value = (Scaleform::GFx::AS3::Value::VU)__PAIR__(v44, 0i64);
    v10 = v44;
    v8 = 12;
    v37.Flags = 12;
  }
  else
  {
    ++v9->RefCount;
    v10 = (unsigned __int64)v37.value.VS._2.VObj;
  }
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7->PublicNamespace.pObject;
  v32 = 0;
  v33.pObject = v11;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  v34.Flags = 0;
  v34.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && v9
    && (v13 = v9[1].pData, *((_DWORD *)v13 + 30) == 17)
    && ~((const unsigned __int8)v13[112] >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v34, (Scaleform::GFx::ASString *)&v9[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v33,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v9[1].RefCount);
    v32 &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+530h+var_4D0.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v34.Flags = *(_QWORD *)&v37.Flags;
    v34.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v34.value.VNumber = v9;
    v34.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v10;
    if ( v12 > 9 )
    {
      if ( (v8 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v12 == 10 )
      {
        ++v9->RefCount;
      }
      else if ( v12 > 10 )
      {
        if ( v12 <= 15 )
        {
          if ( v9 )
            v9->Size = (v9->Size + 1) & 0x8FBFFFFF;
        }
        else if ( v12 <= 17 && v10 )
        {
          *(_DWORD *)(v10 + 32) = (*(_DWORD *)(v10 + 32) + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (v34.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v34, &v48);
      if ( v48.pNode->Size )
      {
        if ( *v48.pNode->pData == 64 )
        {
          v32 |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v48, &v40, 1, v48.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v34, v14);
          v15 = v40.pNode;
          v16 = v40.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = v48.pNode;
      v16 = v48.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( v12 > 9 )
  {
    if ( (v8 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v37.Bonus.pWeakProxy = 0i64;
      v37.value = 0ui64;
      v37.Flags = v8 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v37);
    }
  }
  v18 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = v5[5];
  if ( (unsigned int)(*(_DWORD *)(v19 + 120) - 29) < 5 && ~(*(_BYTE *)(v19 + 112) >> 5) & 1 )
  {
    v20 = 0i64;
    if ( (*(_WORD *)(v5[11] + 106i64) >> 9) & 1 )
      v20 = v5[11];
    if ( !v20
      || (v21 = (*(__int64 (**)(void))(*(_QWORD *)(v20 + 4i64 * *(unsigned __int8 *)(v20 + 109)) + 40i64))(),
          v22 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v21 - 72),
          !v21) )
    {
      v22 = 0i64;
    }
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->BuiltinsMgr.Builtins,
      &namea,
      v4);
    v23 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(v22, &v39, &namea)->pObject;
    v24 = v39.pObject;
    if ( v39.pObject )
    {
      if ( (_QWORD)v39.pObject & 1 )
      {
        --v39.pObject;
      }
      else
      {
        v25 = v39.pObject->RefCount;
        if ( v25 & 0x3FFFFF )
        {
          v39.pObject->RefCount = v25 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v24->vfptr);
        }
      }
    }
    if ( v23 )
    {
      Scaleform::String::String(&v36);
      r.Type = 0;
      r.SinkData.pStr = &v36;
      Scaleform::MsgFormat::MsgFormat(&v46, &r);
      Scaleform::MsgFormat::Parse(&v46, "Property '{0}' already exists as a DisplayObject. SetMember aborted.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v46, (const char *const *)&v);
      Scaleform::MsgFormat::FinishFormatD(&v46);
      Scaleform::MsgFormat::~MsgFormat(&v46);
      v6->vfptr->Output(
        (Scaleform::GFx::AS3::FlashUI *)&v6->vfptr,
        Output_Error,
        (const char *)((v36.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v36.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v26 = namea.pNode;
      v16 = namea.pNode->RefCount == 1;
      --v26->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v26);
      v27 = 0;
      goto LABEL_69;
    }
    v28 = namea.pNode;
    v16 = namea.pNode->RefCount == 1;
    --v28->RefCount;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  }
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v6, gfxVal, &pdestVal);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(_QWORD *, char *, int *, Scaleform::GFx::AS3::Value *))(*v5 + 24i64))(
                   v5,
                   &v47,
                   &v32,
                   &pdestVal) )
  {
    v27 = 1;
  }
  else
  {
    if ( v7->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
    v27 = 0;
  }
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags >> 9) & 1 )
    {
      v16 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      pdestVal.Bonus.pWeakProxy = 0i64;
      pdestVal.value = 0ui64;
      pdestVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
LABEL_69:
  if ( (v34.Flags & 0x1F) > 9 )
  {
    if ( (v34.Flags >> 9) & 1 )
    {
      v16 = v34.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v34.Bonus.pWeakProxy = 0i64;
      v34.value = 0ui64;
      v34.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
    }
  }
  v29 = v33.pObject;
  if ( v33.pObject )
  {
    if ( (_QWORD)v33.pObject & 1 )
    {
      --v33.pObject;
    }
    else
    {
      v30 = v33.pObject->RefCount;
      if ( v30 & 0x3FFFFF )
      {
        v33.pObject->RefCount = v30 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v29->vfptr);
      }
    }
  }
  return v27;
}

// File Line: 460
// RVA: 0x7F69B0
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::Invoke(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *presult, const char *name, Scaleform::GFx::Value *pargs, unsigned __int64 nargs)
{
  Scaleform::GFx::AS3::Object *v6; // r15
  Scaleform::GFx::AS3::MovieRoot *v7; // r12
  Scaleform::GFx::AS3::VM *v8; // r13
  unsigned int v9; // edi
  Scaleform::GFx::ASStringNode *v10; // rbx
  Scaleform::GFx::AS3::Value::V2U v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rdx
  int v13; // esi
  const char *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  unsigned __int64 v20; // r14
  __int64 v21; // rbx
  Scaleform::GFx::Value *v22; // rdi
  unsigned __int64 v23; // rsi
  unsigned __int8 v24; // bl
  Scaleform::GFx::AS3::GASRefCountBase *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::AS3::Value _this; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp-70h]
  unsigned __int64 count; // [rsp+98h] [rbp-68h]
  __int64 v32; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::Value v33; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::AS3::Value value; // [rsp+C8h] [rbp-38h]
  Scaleform::GFx::AS3::PropRef v35; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::ASString v36; // [rsp+118h] [rbp+18h]
  __int64 v37; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ASString v38; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::Value *pdestVal; // [rsp+180h] [rbp+80h]

  pdestVal = presult;
  v37 = -2i64;
  v6 = (Scaleform::GFx::AS3::Object *)pdata;
  v7 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = (Scaleform::GFx::AS3::VM *)&v7->pAVM.pObject->vfptr;
  v9 = 10;
  _this.Flags = 10;
  _this.Bonus.pWeakProxy = 0i64;
  v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->BuiltinsMgr.Builtins,
          &result,
          name)->pNode;
  *(_QWORD *)&_this.value.VNumber = v10;
  if ( v10 == &v10->pManager->NullStringNode )
  {
    v10 = 0i64;
    _this.value.VNumber = 0.0;
    v11.VObj = (Scaleform::GFx::AS3::Object *)count;
    _this.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)count;
    v9 = 12;
    _this.Flags = 12;
  }
  else
  {
    ++v10->RefCount;
    v11.VObj = (Scaleform::GFx::AS3::Object *)_this.value.VS._2;
  }
  v12 = (Scaleform::GFx::AS3::GASRefCountBase *)&v8->PublicNamespace.pObject->vfptr;
  mn.Kind = 0;
  mn.Obj.pObject = v12;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0i64;
  v13 = v9 & 0x1F;
  if ( (unsigned int)(v13 - 12) <= 3
    && v10
    && (v14 = v10[1].pData, *((_DWORD *)v14 + 30) == 17)
    && ~((const unsigned __int8)v14[112] >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&mn.Name, (Scaleform::GFx::ASString *)&v10[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v10[1].RefCount);
    mn.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+160h+_this.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&mn.Name.Flags = *(_QWORD *)&_this.Flags;
    mn.Name.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&mn.Name.value.VNumber = v10;
    mn.Name.value.VS._2 = v11;
    if ( v13 > 9 )
    {
      if ( (v9 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v13 == 10 )
      {
        ++v10->RefCount;
      }
      else if ( v13 > 10 )
      {
        if ( v13 <= 15 )
        {
          if ( v10 )
            v10->Size = (v10->Size + 1) & 0x8FBFFFFF;
        }
        else if ( v13 <= 17 && v11.VObj )
        {
          v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (mn.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &v38);
      if ( v38.pNode->Size )
      {
        if ( *v38.pNode->pData == 64 )
        {
          mn.Kind |= 8u;
          v15 = Scaleform::GFx::ASString::Substring(&v38, &v36, 1, v38.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&mn.Name, v15);
          v16 = v36.pNode;
          v17 = v36.pNode->RefCount == 1;
          --v16->RefCount;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
      }
      v18 = v38.pNode;
      v17 = v38.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  if ( v13 > 9 )
  {
    if ( (v9 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      _this.Bonus.pWeakProxy = 0i64;
      _this.value = 0ui64;
      _this.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  v19 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  v35.pSI = 0i64;
  v35.SlotIndex = 0i64;
  v35.This.Flags = 0;
  v35.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Object::FindProperty(v6, &v35, &mn, 0);
  if ( v35.This.Flags & 0x1F
    && (!((_QWORD)v35.pSI & 1) || (_QWORD)v35.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(v35.pSI) >> 1) & 1) || (_QWORD)v35.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    v33.Flags = 0;
    v33.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
            &v35,
            (Scaleform::GFx::AS3::CheckResult *)&v38,
            v8,
            &value,
            0)->Result )
      goto LABEL_105;
    v20 = nargs;
    if ( nargs )
    {
      v38.pNode = (Scaleform::GFx::ASStringNode *)&result;
      v21 = 0i64;
      result.pNode = 0i64;
      count = 0i64;
      v32 = 0i64;
      Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&result,
        (signed int)nargs);
      if ( v20 )
      {
        v22 = pargs;
        v23 = v20;
        do
        {
          Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(
            v7,
            v22,
            (Scaleform::GFx::AS3::Value *)((char *)result.pNode + v21));
          v21 += 32i64;
          ++v22;
          --v23;
        }
        while ( v23 );
      }
      _this.Flags = 12;
      _this.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&_this.value.VNumber = v6;
      if ( v6 )
        v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        v8,
        &value,
        &_this,
        &v33,
        v20,
        (Scaleform::GFx::AS3::Value *)result.pNode,
        0);
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v17 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v17 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      v38.pNode = (Scaleform::GFx::ASStringNode *)&result;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        (Scaleform::GFx::AS3::Value *)result.pNode,
        count);
      if ( result.pNode )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    else
    {
      _this.Flags = 12;
      _this.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&_this.value.VNumber = v6;
      if ( v6 )
        v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v8, &value, &_this, &v33, 0, 0i64, 0);
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v17 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v17 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
    }
    if ( v8->HandleException )
      goto LABEL_105;
    if ( pdestVal )
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v7, &v33, pdestVal);
    if ( v8->HandleException )
    {
LABEL_105:
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v8);
      v24 = 0;
    }
    else
    {
      v24 = 1;
    }
    if ( (v33.Flags & 0x1F) > 9 )
    {
      if ( (v33.Flags >> 9) & 1 )
      {
        v17 = v33.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v33.Bonus.pWeakProxy = 0i64;
        v33.value = 0ui64;
        v33.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v33);
      }
    }
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags >> 9) & 1 )
      {
        v17 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        value.Bonus.pWeakProxy = 0i64;
        value.value = 0ui64;
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
  }
  else
  {
    v24 = 0;
  }
  if ( (v35.This.Flags & 0x1F) > 9 )
  {
    if ( (v35.This.Flags >> 9) & 1 )
    {
      v17 = v35.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v35.This.Bonus.pWeakProxy = 0i64;
      v35.This.value = 0ui64;
      v35.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v35.This);
    }
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v17 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
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
  return v24;
}

// File Line: 518
// RVA: 0x7F7A80
Scaleform::GFx::AS3ValueObjectInterface::InvokeClosure

// File Line: 561
// RVA: 0x7C0AA0
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::DeleteMember(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *name, bool isdobj)
{
  void *v4; // r14
  Scaleform::GFx::ASMovieRootBase *v5; // rcx
  Scaleform::RefCountImplCoreVtbl *v6; // rsi
  long double *v7; // rax
  unsigned int v8; // edi
  long double v9; // rbx
  Scaleform::GFx::AS3::Value::V2U v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rdx
  int v12; // esi
  __int64 v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  __int64 v19; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-39h]
  Scaleform::GFx::AS3::Value::V2U v24; // [rsp+28h] [rbp-31h]
  __int64 v25; // [rsp+30h] [rbp-29h]
  Scaleform::GFx::AS3::Value v26; // [rsp+38h] [rbp-21h]
  int v27; // [rsp+58h] [rbp-1h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v28; // [rsp+60h] [rbp+7h]
  Scaleform::GFx::AS3::Value v29; // [rsp+68h] [rbp+Fh]
  Scaleform::GFx::ASString v30; // [rsp+C0h] [rbp+67h]
  Scaleform::GFx::ASString v31; // [rsp+C8h] [rbp+6Fh]

  v25 = -2i64;
  v4 = pdata;
  v5 = this->pMovieRoot->pASMovieRoot.pObject;
  v6 = v5[2].vfptr;
  v7 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)&v5[9],
                        &result,
                        name);
  v8 = 10;
  v26.Flags = 10;
  v26.Bonus.pWeakProxy = 0i64;
  v9 = *v7;
  v26.value.VNumber = v9;
  if ( *(_QWORD *)&v9 == *(_QWORD *)(*(_QWORD *)&v9 + 8i64) + 104i64 )
  {
    v9 = 0.0;
    v26.value.VNumber = 0.0;
    v10.VObj = v24.VObj;
    v26.value.VS._2 = v24;
    v8 = 12;
    v26.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v9 + 24i64);
    v10.VObj = (Scaleform::GFx::AS3::Object *)v26.value.VS._2;
  }
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v6[53].__vecDelDtor;
  v27 = 0;
  v28.pObject = v11;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  v29.Flags = 0;
  v29.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && v9 != 0.0
    && (v13 = *(_QWORD *)(*(_QWORD *)&v9 + 40i64), *(_DWORD *)(v13 + 120) == 17)
    && ~(*(_BYTE *)(v13 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v29, (Scaleform::GFx::ASString *)(*(_QWORD *)&v9 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v28,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v9 + 64i64));
    v27 &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rbp+57h+var_78.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v29.Flags = *(_QWORD *)&v26.Flags;
    v29.Bonus.pWeakProxy = 0i64;
    v29.value.VNumber = v9;
    v29.value.VS._2 = v10;
    if ( v12 > 9 )
    {
      if ( (v8 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v12 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v9 + 24i64);
      }
      else if ( v12 > 10 )
      {
        if ( v12 <= 15 )
        {
          if ( v9 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v9 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v9 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v12 <= 17 && v10.VObj )
        {
          v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (v29.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v29, &v30);
      if ( v30.pNode->Size )
      {
        if ( *v30.pNode->pData == 64 )
        {
          v27 |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v30, &v31, 1, v30.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v29, v14);
          v15 = v31.pNode;
          v16 = v31.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = v30.pNode;
      v16 = v30.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( v12 > 9 )
  {
    if ( (v8 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v26.Bonus.pWeakProxy = 0i64;
      v26.value = 0ui64;
      v26.Flags = v8 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
    }
  }
  v18 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = *(unsigned __int8 *)(*(__int64 (__fastcall **)(void *, Scaleform::GFx::ASString *, int *))(*(_QWORD *)v4 + 64i64))(
                              v4,
                              &v30,
                              &v27);
  if ( (v29.Flags & 0x1F) > 9 )
  {
    if ( (v29.Flags >> 9) & 1 )
    {
      v16 = v29.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v29.Bonus.pWeakProxy = 0i64;
      v29.value = 0ui64;
      v29.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
    }
  }
  v20 = v28.pObject;
  if ( v28.pObject )
  {
    if ( (_QWORD)v28.pObject & 1 )
    {
      --v28.pObject;
    }
    else
    {
      v21 = v28.pObject->RefCount;
      if ( v21 & 0x3FFFFF )
      {
        v28.pObject->RefCount = v21 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v20->vfptr);
      }
    }
  }
  return (unsigned __int8)v19;
}

// File Line: 577
// RVA: 0x829B50
Scaleform::GFx::AS3ValueObjectInterface::VisitMembers

// File Line: 665
// RVA: 0x7F8640
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::IsInstanceOf(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *className)
{
  _QWORD *v3; // rsi
  Scaleform::GFx::AS3::VM *v4; // rbx
  unsigned __int64 v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  __int64 v7; // r8
  _QWORD *v8; // rbx
  unsigned __int8 v9; // bl
  Scaleform::GFx::AS3::WeakProxy *v10; // rdx
  bool v11; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  unsigned int v13; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v3 = pdata;
  v4 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  qname.pStr = className;
  if ( className )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( className[v5] );
    qname.Size = v5;
  }
  else
  {
    qname.Size = 0i64;
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v4, &qname);
  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v4, &mn, v4->CurrentDomain.pObject);
  if ( !v6 )
    goto LABEL_26;
  v8 = (_QWORD *)v3[5];
  if ( !v8[17] )
    (*(void (__fastcall **)(_QWORD))(*v8 + 80i64))(v3[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v8[17] + 40i64),
         v6) )
  {
    v9 = 1;
  }
  else
  {
LABEL_26:
    v9 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v10 = mn.Name.Bonus.pWeakProxy;
      v11 = mn.Name.Bonus.pWeakProxy->RefCount == 1;
      --v10->RefCount;
      if ( v11 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v10,
          v7);
      mn.Name.Bonus.pWeakProxy = 0i64;
      mn.Name.value = 0ui64;
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v12 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v13 = mn.Obj.pObject->RefCount;
      if ( v13 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
      }
    }
  }
  return v9;
}

// File Line: 684
// RVA: 0x7F8290
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::IsByteArray(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata)
{
  _QWORD *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rsi
  _QWORD *v5; // rbx
  unsigned __int8 v6; // bl
  bool v7; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v8; // rcx
  unsigned int v9; // eax
  const char *v11; // [rsp+28h] [rbp-50h]
  __int64 v12; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v2 = pdata;
  v3 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11 = "flash.utils.ByteArray";
  v12 = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v3, (Scaleform::StringDataPtr *)&v11);
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v3, &mn, v3->CurrentDomain.pObject);
  if ( !v4 )
    goto LABEL_21;
  v5 = (_QWORD *)v2[5];
  if ( !v5[17] )
    (*(void (__fastcall **)(_QWORD))(*v5 + 80i64))(v2[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v5[17] + 40i64),
         v4) )
  {
    v6 = 1;
  }
  else
  {
LABEL_21:
    v6 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v7 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
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
  v8 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v9 = mn.Obj.pObject->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
  return v6;
}

// File Line: 704
// RVA: 0x7E6870
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetByteArraySize(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata)
{
  _QWORD *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rsi
  _QWORD *v5; // rbx
  unsigned int v6; // ebx
  bool v7; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v8; // rcx
  unsigned int v9; // eax
  const char *v11; // [rsp+28h] [rbp-50h]
  __int64 v12; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v2 = pdata;
  v3 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11 = "flash.utils.ByteArray";
  v12 = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v3, (Scaleform::StringDataPtr *)&v11);
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v3, &mn, v3->CurrentDomain.pObject);
  if ( !v4 )
    goto LABEL_21;
  v5 = (_QWORD *)v2[5];
  if ( !v5[17] )
    (*(void (__fastcall **)(_QWORD))(*v5 + 80i64))(v2[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v5[17] + 40i64),
         v4) )
  {
    v6 = *((_DWORD *)v2 + 16);
  }
  else
  {
LABEL_21:
    v6 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v7 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
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
  v8 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v9 = mn.Obj.pObject->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
  return v6;
}

// File Line: 721
// RVA: 0x818580
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetByteArraySize(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, unsigned __int64 setSize)
{
  unsigned int v3; // esi
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits **v6; // rbp
  Scaleform::GFx::AS3::Traits *v7; // rbx
  bool v8; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v9; // rcx
  unsigned int v10; // eax
  const char *v11; // [rsp+28h] [rbp-50h]
  __int64 v12; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v3 = setSize;
  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)pdata;
  v5 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11 = "flash.utils.ByteArray";
  v12 = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v5, (Scaleform::StringDataPtr *)&v11);
  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, &mn, v5->CurrentDomain.pObject);
  if ( v6 )
  {
    v7 = v4->pTraits.pObject;
    if ( !v7->pConstructor.pObject )
      v7->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->pTraits.pObject->vfptr);
    if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
           (Scaleform::GFx::AS3::ClassTraits::Traits *)v7->pConstructor.pObject->pTraits.pObject,
           (Scaleform::GFx::AS3::ClassTraits::Traits *)v6) )
    {
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(v4, v3);
    }
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v8 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
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
  v9 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v10 = mn.Obj.pObject->RefCount;
      if ( v10 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
      }
    }
  }
}

// File Line: 738
// RVA: 0x80EF50
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::ReadFromByteArray(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, char *destBuff, unsigned __int64 destBuffSz)
{
  unsigned __int64 v4; // rbp
  char *v5; // r14
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rsi
  Scaleform::GFx::AS3::Traits *v9; // rbx
  unsigned __int8 v10; // bl
  bool v11; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  unsigned int v13; // eax
  const char *v15; // [rsp+28h] [rbp-50h]
  __int64 v16; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v4 = destBuffSz;
  v5 = destBuff;
  v6 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)pdata;
  v7 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v15 = "flash.utils.ByteArray";
  v16 = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v7, (Scaleform::StringDataPtr *)&v15);
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v7, &mn, v7->CurrentDomain.pObject);
  if ( !v8 )
    goto LABEL_21;
  v9 = v6->pTraits.pObject;
  if ( !v9->pConstructor.pObject )
    v9->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->pTraits.pObject->vfptr);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v9->pConstructor.pObject->pTraits.pObject,
         v8) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(v6, v5, v4);
    v10 = 1;
  }
  else
  {
LABEL_21:
    v10 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v11 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
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
  v12 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v13 = mn.Obj.pObject->RefCount;
      if ( v13 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
      }
    }
  }
  return v10;
}

// File Line: 756
// RVA: 0x82A350
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::WriteToByteArray(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *srcBuff, unsigned __int64 writeSize)
{
  unsigned __int64 v4; // rbp
  const char *v5; // r14
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits **v8; // rsi
  Scaleform::GFx::AS3::Traits *v9; // rbx
  unsigned __int8 v10; // bl
  bool v11; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  unsigned int v13; // eax
  const char *v15; // [rsp+28h] [rbp-50h]
  __int64 v16; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v4 = writeSize;
  v5 = srcBuff;
  v6 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)pdata;
  v7 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v15 = "flash.utils.ByteArray";
  v16 = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v7, (Scaleform::StringDataPtr *)&v15);
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v7, &mn, v7->CurrentDomain.pObject);
  if ( !v8 )
    goto LABEL_21;
  v9 = v6->pTraits.pObject;
  if ( !v9->pConstructor.pObject )
    v9->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->pTraits.pObject->vfptr);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v9->pConstructor.pObject->pTraits.pObject,
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v8) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Set(v6, v5, v4);
    v10 = 1;
  }
  else
  {
LABEL_21:
    v10 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v11 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
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
  v12 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v13 = mn.Obj.pObject->RefCount;
      if ( v13 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
      }
    }
  }
  return v10;
}

// File Line: 774
// RVA: 0x7EEA90
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetRawDataPtr(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata)
{
  _QWORD *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rsi
  _QWORD *v5; // rbx
  __int64 v6; // rbx
  bool v7; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v8; // rcx
  unsigned int v9; // eax
  const char *v11; // [rsp+28h] [rbp-50h]
  __int64 v12; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v2 = pdata;
  v3 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11 = "flash.utils.ByteArray";
  v12 = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v3, (Scaleform::StringDataPtr *)&v11);
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v3, &mn, v3->CurrentDomain.pObject);
  if ( !v4 )
    goto LABEL_21;
  v5 = (_QWORD *)v2[5];
  if ( !v5[17] )
    (*(void (__fastcall **)(_QWORD))(*v5 + 80i64))(v2[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v5[17] + 40i64),
         v4) )
  {
    v6 = v2[9];
  }
  else
  {
LABEL_21:
    v6 = 0i64;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v7 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
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
  v8 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v9 = mn.Obj.pObject->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
  return v6;
}

// File Line: 791
// RVA: 0x7E5F60
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetArraySize(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata)
{
  return *((unsigned int *)pdata + 14);
}

// File Line: 799
// RVA: 0x818360
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetArraySize(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, unsigned int sz)
{
  Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)((char *)pdata + 56), sz);
  return 1;
}

// File Line: 808
// RVA: 0x7E93F0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetElement(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, unsigned int idx, Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::Value *v4; // rbx
  unsigned __int64 v5; // rdi
  char *v6; // rsi
  Scaleform::GFx::AS3ValueObjectInterface *v7; // rbp
  Scaleform::GFx::AS3::Value *v9; // rax

  v4 = pval;
  v5 = idx;
  v6 = (char *)pdata;
  v7 = this;
  if ( ((unsigned int)pval->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval->pObjectInterface->vfptr->gap8[8])(
      pval->pObjectInterface,
      pval,
      *(_QWORD *)&pval->mValue.NValue);
    v4->pObjectInterface = 0i64;
  }
  v4->Type = 0;
  if ( (unsigned int)v5 >= *((_DWORD *)v6 + 14) )
    return 0;
  v9 = Scaleform::GFx::AS3::Impl::SparseArray::At((Scaleform::GFx::AS3::Impl::SparseArray *)(v6 + 56), v5);
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(
    (Scaleform::GFx::AS3::MovieRoot *)v7->pMovieRoot->pASMovieRoot.pObject,
    v9,
    v4);
  return 1;
}

// File Line: 824
// RVA: 0x8198A0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetElement(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, unsigned int idx, Scaleform::GFx::Value *value)
{
  unsigned int v4; // ebx
  char *v5; // rdi
  Scaleform::GFx::AS3::MovieRoot *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+28h] [rbp-30h]

  v4 = idx;
  v5 = (char *)pdata;
  v6 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v6, value, &pdestVal);
  Scaleform::GFx::AS3::Impl::SparseArray::Set((Scaleform::GFx::AS3::Impl::SparseArray *)(v5 + 56), v4, &pdestVal);
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags >> 9) & 1 )
    {
      v7 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pdestVal.Bonus.pWeakProxy = 0i64;
      pdestVal.value = 0ui64;
      pdestVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
  return 1;
}

// File Line: 838
// RVA: 0x8299F0
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::VisitElements(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor, unsigned int idx, int count)
{
  unsigned int v5; // er14
  Scaleform::GFx::Value::ObjectInterface::ArrVisitor *v6; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v7; // rbx
  Scaleform::GFx::AS3::MovieRoot *v8; // r13
  __int64 v9; // rcx
  int v10; // eax
  unsigned int v11; // ebp
  unsigned __int64 v12; // rdi
  signed __int64 v13; // r15
  Scaleform::GFx::AS3::Value *v14; // rdx
  signed __int64 v15; // rax
  signed __int64 v16; // rdx
  Scaleform::GFx::Value pdestVal; // [rsp+28h] [rbp-60h]
  unsigned __int64 key; // [rsp+90h] [rbp+8h]

  v5 = idx;
  v6 = visitor;
  v7 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)pdata;
  v8 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = *((_QWORD *)pdata + 7);
  if ( idx < (unsigned int)v9 )
  {
    v10 = count;
    if ( count < 0 )
      v10 = v9 - idx;
    pdestVal.pObjectInterface = 0i64;
    pdestVal.Type = 0;
    v11 = idx + v10;
    if ( (unsigned int)v9 < idx + v10 )
      v11 = v9;
    if ( idx < v11 )
    {
      v12 = idx;
      v13 = 2i64 * idx;
      do
      {
        key = v12;
        if ( (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)v12 >= v7[15].pTable )
        {
          if ( (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)v12 < v7[8].pTable
            || (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)v12 > v7[9].pTable
            || (v15 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                        v7 + 18,
                        &key),
                v15 < 0)
            || (v16 = (signed __int64)&v7[18].pTable[2] + 56 * v15) == 0
            || (v14 = (Scaleform::GFx::AS3::Value *)(v16 + 8)) == 0i64 )
          {
            v14 = (Scaleform::GFx::AS3::Value *)&v7[10];
          }
        }
        else
        {
          v14 = (Scaleform::GFx::AS3::Value *)&v7[14].pTable[v13];
        }
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v8, v14, &pdestVal);
        v6->vfptr->Visit(v6, v5++, (Scaleform::GFx::Value *)((char *)&pdestVal + 2));
        ++v12;
        v13 += 2i64;
      }
      while ( v5 < v11 );
    }
    if ( (*(unsigned int *)((char *)&pdestVal.Type + 2) >> 6) & 1 )
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**(_QWORD **)((char *)&pdestVal.pObjectInterface + 2) + 16i64))(
        *(Scaleform::GFx::Value::ObjectInterface **)((char *)&pdestVal.pObjectInterface + 2),
        (char *)&pdestVal.pVoidPrev + 2,
        *(_QWORD *)((char *)&pdestVal.mValue + 2));
  }
}

// File Line: 862
// RVA: 0x80AB90
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::PushBack(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *value)
{
  char *v3; // rdi
  Scaleform::GFx::AS3::MovieRoot *v4; // rcx
  __int64 v5; // rcx
  Scaleform::GFx::AS3::Value::VU *v6; // rdx
  int v7; // eax
  long double v8; // rax
  bool v9; // zf
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+38h] [rbp-28h]

  v3 = (char *)pdata;
  v4 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v4, value, &pdestVal);
  v5 = *((_QWORD *)v3 + 7);
  if ( v5 != *((_QWORD *)v3 + 15) )
  {
    *((_QWORD *)v3 + 9) = v5;
    key.pFirst = (const unsigned __int64 *)(v3 + 72);
    key.pSecond = &pdestVal;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)v3
    + 18,
      *((void **)v3 + 19),
      &key);
    goto LABEL_17;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)(v3 + 112),
    *((const void **)v3 + 17),
    *((_QWORD *)v3 + 15) + 1i64);
  v6 = (Scaleform::GFx::AS3::Value::VU *)(32i64 * *((_QWORD *)v3 + 15) + *((_QWORD *)v3 + 14) - 32i64);
  if ( v6 )
  {
    LODWORD(v6->VS._1.VStr) = pdestVal.Flags;
    v6->VS._2.VObj = (Scaleform::GFx::AS3::Object *)pdestVal.Bonus.pWeakProxy;
    v6[1] = pdestVal.value;
    v7 = pdestVal.Flags & 0x1F;
    if ( v7 > 9 )
    {
      if ( (pdestVal.Flags >> 9) & 1 )
      {
        ++pdestVal.Bonus.pWeakProxy->RefCount;
        goto LABEL_17;
      }
      if ( v7 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&pdestVal.value.VNumber + 24i64);
      }
      else
      {
        if ( v7 <= 10 )
          goto LABEL_17;
        if ( v7 <= 15 )
        {
          v8 = pdestVal.value.VNumber;
        }
        else
        {
          if ( v7 > 17 )
            goto LABEL_17;
          v8 = *(double *)&pdestVal.value.VS._2.VObj;
        }
        if ( v8 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v8 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v8 + 32i64) &= 0x8FBFFFFF;
        }
      }
    }
  }
LABEL_17:
  ++*((_QWORD *)v3 + 7);
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags >> 9) & 1 )
    {
      v9 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pdestVal.Bonus.pWeakProxy = 0i64;
      pdestVal.value = 0ui64;
      pdestVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
  return 1;
}

// File Line: 875
// RVA: 0x807680
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::PopBack(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pval)
{
  int v3; // esi
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // rdi
  Scaleform::GFx::AS3::MovieRoot *v5; // rbp
  Scaleform::GFx::Value *v6; // rbx
  char result; // al
  Scaleform::GFx::AS3::Value *v8; // rax

  v3 = *((_DWORD *)pdata + 14);
  v4 = (Scaleform::GFx::AS3::Impl::SparseArray *)((char *)pdata + 56);
  v5 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = pval;
  if ( v3 > 0 )
  {
    if ( pval )
    {
      v8 = Scaleform::GFx::AS3::Impl::SparseArray::At(
             (Scaleform::GFx::AS3::Impl::SparseArray *)((char *)pdata + 56),
             v3 - 1);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v5, v8, v6);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(v4, v3 - 1);
    result = 1;
  }
  else
  {
    if ( pval )
    {
      if ( ((unsigned int)pval->Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval->pObjectInterface->vfptr->gap8[8])(
          pval->pObjectInterface,
          pval,
          *(_QWORD *)&pval->mValue.NValue);
        v6->pObjectInterface = 0i64;
      }
      v6->Type = 0;
    }
    result = 0;
  }
  return result;
}

// File Line: 897
// RVA: 0x811880
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::RemoveElements(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, unsigned int idx, int count)
{
  unsigned int v4; // eax
  unsigned int v6; // eax

  v4 = *((_DWORD *)pdata + 14);
  if ( idx >= v4 )
    return 0;
  if ( count < 0 )
    count = v4 - idx;
  v6 = v4 - idx;
  if ( v6 < count )
    count = v6;
  Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(
    (Scaleform::GFx::AS3::Impl::SparseArray *)((char *)pdata + 56),
    idx,
    (unsigned int)count,
    0i64);
  return 1;
}

// File Line: 910
// RVA: 0x7F1B30
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetWorldMatrix(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix2x4<float> *pmat)
{
  __int64 v3; // rcx
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  Scaleform::GFx::DisplayObjectBase *v5; // rcx
  float v6; // xmm1_4
  char result; // al
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  Scaleform::Render::Matrix2x4<float> pmata; // [rsp+20h] [rbp-28h]

  v3 = *((_QWORD *)pdata + 5);
  v4 = pmat;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)*((_QWORD *)pdata + 11);
  *(_OWORD *)&pmata.M[0][0] = _xmm;
  *(__m128 *)&pmata.M[1][0] = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v5, &pmata);
  v6 = pmata.M[0][1];
  result = 1;
  v8 = pmata.M[0][3];
  v9 = pmata.M[1][3];
  v4->M[0][0] = pmata.M[0][0];
  v10 = pmata.M[0][2];
  v4->M[0][1] = v6;
  v11 = pmata.M[1][0];
  v4->M[0][2] = v10;
  v12 = pmata.M[1][1];
  v4->M[1][0] = v11;
  v13 = pmata.M[1][2];
  v4->M[1][1] = v12;
  v4->M[0][3] = v8 * 0.050000001;
  v4->M[1][2] = v13;
  v4->M[1][3] = v9 * 0.050000001;
  return result;
}

// File Line: 926
// RVA: 0x7E9060
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayMatrix(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix2x4<float> *pmat)
{
  __int64 v3; // rcx
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  __int64 v5; // rax
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  char result; // al

  v3 = *((_QWORD *)pdata + 5);
  v4 = pmat;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v5 = (*(__int64 (**)(void))(**((_QWORD **)pdata + 11) + 16i64))();
  v6 = *(float *)(v5 + 20);
  v7 = *(float *)(v5 + 12) * 0.050000001;
  v8 = *(float *)(v5 + 24);
  v9 = *(float *)v5;
  v10 = *(float *)(v5 + 4);
  v11 = *(float *)(v5 + 8);
  v12 = *(float *)(v5 + 16);
  v4->M[1][3] = *(float *)(v5 + 28) * 0.050000001;
  result = 1;
  v4->M[1][1] = v6;
  v4->M[1][2] = v8;
  v4->M[0][0] = v9;
  v4->M[0][1] = v10;
  v4->M[0][2] = v11;
  v4->M[0][3] = v7;
  v4->M[1][0] = v12;
  return result;
}

// File Line: 942
// RVA: 0x8196C0
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayMatrix(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix2x4<float> *mat)
{
  __int64 v3; // rcx
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  Scaleform::GFx::DisplayObjectBase *v5; // rdi
  bool result; // al
  int v7; // xmm0_4
  float v8; // xmm2_4
  int v9; // xmm1_4
  int v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm0_4
  float v14; // xmm4_4
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128d v17; // xmm0
  __m128d v18; // xmm2
  double v19; // xmm1_8
  int v20; // [rsp+20h] [rbp-39h]
  float v21; // [rsp+24h] [rbp-35h]
  int v22; // [rsp+28h] [rbp-31h]
  float v23; // [rsp+2Ch] [rbp-2Dh]
  int v24; // [rsp+30h] [rbp-29h]
  int v25; // [rsp+34h] [rbp-25h]
  int v26; // [rsp+38h] [rbp-21h]
  float v27; // [rsp+3Ch] [rbp-1Dh]
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+40h] [rbp-19h]

  v3 = *((_QWORD *)pdata + 5);
  v4 = mat;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)*((_QWORD *)pdata + 11);
  result = Scaleform::Render::Matrix2x4<float>::IsValid(mat);
  if ( result )
  {
    v7 = LODWORD(v4->M[0][0]);
    v8 = v4->M[0][3];
    v21 = v4->M[0][1];
    v9 = LODWORD(v4->M[1][1]);
    v20 = v7;
    v10 = LODWORD(v4->M[0][2]);
    v25 = v9;
    v11 = v4->M[1][3] * 20.0;
    v22 = v10;
    v12 = LODWORD(v4->M[1][0]);
    v23 = v8 * 20.0;
    v24 = v12;
    v13 = LODWORD(v4->M[1][2]);
    v27 = v11;
    v26 = v13;
    v5->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v20);
    geomData.YScale = DOUBLE_100_0;
    geomData.XScale = DOUBLE_100_0;
    *(_QWORD *)&geomData.X = 0i64;
    *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
    geomData.Rotation = 0.0;
    *(_OWORD *)&geomData.XRotation = 0i64;
    *(_OWORD *)&geomData.Z = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
    v14 = v4->M[1][0];
    v15 = (__m128)LODWORD(v4->M[0][0]);
    v16 = (__m128)LODWORD(v4->M[0][1]);
    geomData.X = (signed int)v4->M[0][3];
    v17 = _mm_cvtps_pd(v15);
    v18 = _mm_cvtps_pd(v16);
    geomData.Y = (signed int)v4->M[1][3];
    v17.m128d_f64[0] = v17.m128d_f64[0] * v17.m128d_f64[0] + v14 * v14;
    v19 = v4->M[1][1] * v4->M[1][1];
    geomData.XScale = COERCE_DOUBLE(_mm_sqrt_pd(v17)) * 100.0;
    v18.m128d_f64[0] = v18.m128d_f64[0] * v18.m128d_f64[0] + v19;
    geomData.YScale = COERCE_DOUBLE(_mm_sqrt_pd(v18)) * 100.0;
    geomData.Rotation = atan2(v14, v15.m128_f32[0]) * 180.0 * 0.3183098861837907;
    Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &geomData);
    result = 1;
  }
  return result;
}

// File Line: 976
// RVA: 0x7EBA80
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetMatrix3D(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix3x4<float> *pmat)
{
  __int64 v3; // rcx
  Scaleform::Render::Matrix3x4<float> *v4; // rbx
  __int64 v5; // rax
  float v6; // xmm8_4
  float v7; // xmm12_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm9_4
  float v12; // xmm10_4
  float v13; // xmm11_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  char result; // al

  v3 = *((_QWORD *)pdata + 5);
  v4 = pmat;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v5 = (*(__int64 (**)(void))(**((_QWORD **)pdata + 11) + 32i64))();
  v6 = *(float *)(v5 + 28) * 0.050000001;
  v7 = *(float *)(v5 + 44) * 0.050000001;
  v8 = *(float *)(v5 + 12) * 0.050000001;
  v9 = *(float *)(v5 + 20);
  v10 = *(float *)(v5 + 24);
  v11 = *(float *)(v5 + 32);
  v12 = *(float *)(v5 + 36);
  v13 = *(float *)(v5 + 40);
  v14 = *(float *)v5;
  v15 = *(float *)(v5 + 4);
  v16 = *(float *)(v5 + 8);
  v17 = *(float *)(v5 + 16);
  result = 1;
  v4->M[0][0] = v14;
  v4->M[0][1] = v15;
  v4->M[0][2] = v16;
  v4->M[0][3] = v8;
  v4->M[1][0] = v17;
  v4->M[1][1] = v9;
  v4->M[1][2] = v10;
  v4->M[1][3] = v6;
  v4->M[2][0] = v11;
  v4->M[2][1] = v12;
  v4->M[2][2] = v13;
  v4->M[2][3] = v7;
  return result;
}

// File Line: 992
// RVA: 0x819EF0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetMatrix3D(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::Render::Matrix3x4<float> *mat)
{
  __int64 v3; // rcx
  Scaleform::Render::Matrix3x4<float> *v4; // rbx
  Scaleform::GFx::DisplayObjectBase *v5; // rdi
  char result; // al
  int v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  float v15; // xmm1_4
  __m128 v16; // xmm2
  float v17; // [rsp+20h] [rbp-49h]
  int v18; // [rsp+24h] [rbp-45h]
  float v19; // [rsp+28h] [rbp-41h]
  float v20; // [rsp+2Ch] [rbp-3Dh]
  int v21; // [rsp+30h] [rbp-39h]
  int v22; // [rsp+34h] [rbp-35h]
  float v23; // [rsp+38h] [rbp-31h]
  float v24; // [rsp+3Ch] [rbp-2Dh]
  int v25; // [rsp+40h] [rbp-29h]
  int v26; // [rsp+44h] [rbp-25h]
  int v27; // [rsp+48h] [rbp-21h]
  float v28; // [rsp+4Ch] [rbp-1Dh]
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+50h] [rbp-19h]
  float eX; // [rsp+D8h] [rbp+6Fh]
  float eY; // [rsp+E8h] [rbp+7Fh]

  v3 = *((_QWORD *)pdata + 5);
  v4 = mat;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)*((_QWORD *)pdata + 11);
  result = Scaleform::Render::Matrix3x4<float>::IsValid(mat);
  if ( result )
  {
    v7 = LODWORD(v4->M[0][1]);
    v8 = v4->M[0][3];
    v9 = v4->M[1][3];
    v17 = v4->M[0][0];
    v19 = v4->M[0][2];
    v10 = LODWORD(v4->M[1][0]);
    v18 = v7;
    v11 = LODWORD(v4->M[1][1]);
    v21 = v10;
    v23 = v4->M[1][2];
    v12 = LODWORD(v4->M[2][0]);
    v22 = v11;
    v13 = LODWORD(v4->M[2][1]);
    v25 = v12;
    v14 = LODWORD(v4->M[2][2]);
    v26 = v13;
    v15 = v4->M[2][3];
    v27 = v14;
    v20 = v8 * 20.0;
    v24 = v9 * 20.0;
    v28 = v15 * 20.0;
    v5->vfptr[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v17);
    geomData.YScale = DOUBLE_100_0;
    geomData.XScale = DOUBLE_100_0;
    *(_QWORD *)&geomData.X = 0i64;
    *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
    geomData.Rotation = 0.0;
    *(_OWORD *)&geomData.XRotation = 0i64;
    *(_OWORD *)&geomData.Z = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
    v16 = (__m128)LODWORD(v4->M[0][2]);
    v16.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v4->M[1][2] * v4->M[1][2]);
    geomData.Z = v4->M[2][3];
    v16.m128_f32[0] = v16.m128_f32[0] + (float)(v4->M[2][2] * v4->M[2][2]);
    geomData.ZScale = COERCE_FLOAT(_mm_sqrt_ps(v16)) * 100.0;
    Scaleform::Render::Matrix3x4<float>::GetEulerAngles(v4, &eX, &eY, 0i64);
    geomData.XRotation = eX * 180.0 * 0.3183098861837907;
    geomData.YRotation = eY * 180.0 * 0.3183098861837907;
    Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &geomData);
    result = 1;
  }
  return result;
}

// File Line: 1029
// RVA: 0x7F8570
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::IsDisplayObjectActive(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata)
{
  __int64 v2; // rcx
  bool result; // al

  v2 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v2 + 120) - 22) < 0xC && ~(*(_BYTE *)(v2 + 112) >> 5) & 1 )
    result = *((_QWORD *)pdata + 11) != 0i64;
  else
    result = 0;
  return result;
}

// File Line: 1038
// RVA: 0x7EDB00
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetParent(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pparent)
{
  Scaleform::GFx::Value *v3; // rbx
  __int64 v4; // r8
  Scaleform::GFx::AS3ValueObjectInterface *v5; // r9
  __int64 v6; // rcx
  __int64 v7; // rcx
  Scaleform::GFx::AS3::MovieRoot *v8; // r10
  __int64 v9; // rax
  char *v10; // r9
  char result; // al

  v3 = pparent;
  v4 = *((_QWORD *)pdata + 5);
  v5 = this;
  if ( (unsigned int)(*(_DWORD *)(v4 + 120) - 22) >= 0xC )
    return 0;
  if ( !(~(*(_BYTE *)(v4 + 112) >> 5) & 1) )
    return 0;
  v6 = *((_QWORD *)pdata + 11);
  if ( !v6 )
    return 0;
  v7 = *(_QWORD *)(v6 + 56);
  if ( v7 )
  {
    v8 = (Scaleform::GFx::AS3::MovieRoot *)v5->pMovieRoot->pASMovieRoot.pObject;
    v9 = *(unsigned __int8 *)(v7 + 109);
    v10 = *(char **)(v7 + 4 * v9 + 16);
    if ( !v10 )
      v10 = *(char **)(v7 + 4 * v9 + 8);
    if ( (unsigned __int8)v10 & 1 )
      --v10;
    result = Scaleform::GFx::AS3::MovieRoot::CreateObjectValue(v8, v3, v8->pMovieImpl->pObjectInterface, v10);
  }
  else
  {
    if ( ((unsigned int)v3->Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD, Scaleform::GFx::AS3ValueObjectInterface *))&v3->pObjectInterface->vfptr->gap8[8])(
        v3->pObjectInterface,
        v3,
        *(_QWORD *)&v3->mValue.NValue,
        v5);
      v3->pObjectInterface = 0i64;
    }
    v3->Type = 1;
    result = 1;
  }
  return result;
}

// File Line: 1062
// RVA: 0x7E8BC0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayInfo(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  __int64 v3; // rcx
  Scaleform::GFx::Value::DisplayInfo *v4; // rbx
  Scaleform::GFx::TextField *v5; // rdi
  long double v7; // xmm0_8
  long double v8; // xmm7_8
  long double v9; // xmm8_8
  long double v10; // xmm9_8
  long double v11; // xmm11_8
  long double v12; // xmm10_8
  long double v13; // xmm6_8
  char v14; // al
  double v15; // xmm0_8
  long double v16; // xmm1_8
  long double v17; // xmm0_8
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm0_4
  int v23; // xmm1_4
  int v24; // xmm0_4
  int v25; // xmm1_4
  int v26; // xmm0_4
  int v27; // xmm1_4
  int v28; // xmm0_4
  int v29; // xmm1_4
  int v30; // xmm0_4
  int v31; // xmm1_4
  int v32; // xmm0_4
  int v33; // xmm1_4
  int v34; // xmm0_4
  int v35; // xmm1_4
  int v36; // xmm0_4
  int v37; // xmm1_4
  int v38; // xmm0_4
  int v39; // xmm1_4
  int v40; // xmm0_4
  int v41; // xmm1_4
  int v42; // xmm0_4
  int v43; // xmm1_4
  int v44; // xmm0_4
  int v45; // xmm1_4
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // rdx
  int v48; // [rsp+20h] [rbp-E0h]
  int v49; // [rsp+24h] [rbp-DCh]
  int v50; // [rsp+28h] [rbp-D8h]
  int v51; // [rsp+2Ch] [rbp-D4h]
  int v52; // [rsp+30h] [rbp-D0h]
  int v53; // [rsp+34h] [rbp-CCh]
  int v54; // [rsp+38h] [rbp-C8h]
  int v55; // [rsp+3Ch] [rbp-C4h]
  int v56; // [rsp+40h] [rbp-C0h]
  int v57; // [rsp+44h] [rbp-BCh]
  int v58; // [rsp+48h] [rbp-B8h]
  int v59; // [rsp+4Ch] [rbp-B4h]
  int Dst; // [rsp+50h] [rbp-B0h]
  int v61; // [rsp+54h] [rbp-ACh]
  int v62; // [rsp+58h] [rbp-A8h]
  int v63; // [rsp+5Ch] [rbp-A4h]
  int v64; // [rsp+60h] [rbp-A0h]
  int v65; // [rsp+64h] [rbp-9Ch]
  int v66; // [rsp+68h] [rbp-98h]
  int v67; // [rsp+6Ch] [rbp-94h]
  int v68; // [rsp+70h] [rbp-90h]
  int v69; // [rsp+74h] [rbp-8Ch]
  int v70; // [rsp+78h] [rbp-88h]
  int v71; // [rsp+7Ch] [rbp-84h]
  int v72; // [rsp+80h] [rbp-80h]
  int v73; // [rsp+84h] [rbp-7Ch]
  int v74; // [rsp+88h] [rbp-78h]
  int v75; // [rsp+8Ch] [rbp-74h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+90h] [rbp-70h]

  v3 = *((_QWORD *)pdata + 5);
  v4 = pinfo;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v5 = (Scaleform::GFx::TextField *)*((_QWORD *)pdata + 11);
  if ( !v5 )
    return 0;
  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  v7 = *(double *)&_xmm;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetGeomData((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr, &geomData);
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[81].__vecDelDtor)(v5) == 4 )
  {
    Scaleform::GFx::TextField::GetPosition(v5, v4);
  }
  else
  {
    v8 = geomData.Rotation;
    v9 = geomData.XScale;
    v10 = geomData.YScale;
    v11 = (double)geomData.X * 0.05;
    v12 = (double)geomData.Y * 0.05;
    v13 = (float)(Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr)->M[0][3]
                * 100.0);
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[59].__vecDelDtor)(v5);
    v15 = geomData.Z;
    v4->Visible = v14;
    v4->VarsSet |= 0x7FFu;
    v16 = geomData.YRotation;
    v4->X = v11;
    v4->Z = v15 * 0.05;
    v17 = geomData.XRotation;
    v4->Y = v12;
    v4->XRotation = v17;
    v7 = geomData.ZScale;
    v4->Rotation = v8;
    v4->XScale = v9;
    v4->YScale = v10;
    v4->Alpha = v13;
    v4->ZScale = v7;
    v4->YRotation = v16;
  }
  ((void (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[40].__vecDelDtor)(v5);
  v4->VarsSet |= 0x800u;
  v4->FOV = v7;
  memset(&Dst, 0, 0x40ui64);
  Dst = 1065353216;
  v65 = 1065353216;
  v70 = 1065353216;
  v75 = 1065353216;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->vfptr[6].__vecDelDtor)(
         v5,
         &Dst,
         0i64) )
  {
    v18 = Dst;
    v19 = v61;
    v4->VarsSet |= 0x1000u;
    LODWORD(v4->ProjectionMatrix3D.M[0][0]) = v18;
    v20 = v62;
    LODWORD(v4->ProjectionMatrix3D.M[0][1]) = v19;
    v21 = v63;
    LODWORD(v4->ProjectionMatrix3D.M[0][2]) = v20;
    v22 = v64;
    LODWORD(v4->ProjectionMatrix3D.M[0][3]) = v21;
    v23 = v65;
    LODWORD(v4->ProjectionMatrix3D.M[1][0]) = v22;
    v24 = v66;
    LODWORD(v4->ProjectionMatrix3D.M[1][1]) = v23;
    v25 = v67;
    LODWORD(v4->ProjectionMatrix3D.M[1][2]) = v24;
    v26 = v68;
    LODWORD(v4->ProjectionMatrix3D.M[1][3]) = v25;
    v27 = v69;
    LODWORD(v4->ProjectionMatrix3D.M[2][0]) = v26;
    v28 = v70;
    LODWORD(v4->ProjectionMatrix3D.M[2][1]) = v27;
    v29 = v71;
    LODWORD(v4->ProjectionMatrix3D.M[2][2]) = v28;
    v30 = v72;
    LODWORD(v4->ProjectionMatrix3D.M[2][3]) = v29;
    v31 = v73;
    LODWORD(v4->ProjectionMatrix3D.M[3][0]) = v30;
    v32 = v74;
    LODWORD(v4->ProjectionMatrix3D.M[3][1]) = v31;
    v33 = v75;
    LODWORD(v4->ProjectionMatrix3D.M[3][2]) = v32;
    LODWORD(v4->ProjectionMatrix3D.M[3][3]) = v33;
  }
  memset(&v48, 0, 0x30ui64);
  v48 = 1065353216;
  v53 = 1065353216;
  v58 = 1065353216;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->vfptr[9].__vecDelDtor)(
         v5,
         &v48,
         0i64) )
  {
    v34 = v48;
    v35 = v49;
    v4->VarsSet |= 0x2000u;
    LODWORD(v4->ViewMatrix3D.M[0][0]) = v34;
    v36 = v50;
    LODWORD(v4->ViewMatrix3D.M[0][1]) = v35;
    v37 = v51;
    LODWORD(v4->ViewMatrix3D.M[0][2]) = v36;
    v38 = v52;
    LODWORD(v4->ViewMatrix3D.M[0][3]) = v37;
    v39 = v53;
    LODWORD(v4->ViewMatrix3D.M[1][0]) = v38;
    v40 = v54;
    LODWORD(v4->ViewMatrix3D.M[1][1]) = v39;
    v41 = v55;
    LODWORD(v4->ViewMatrix3D.M[1][2]) = v40;
    v42 = v56;
    LODWORD(v4->ViewMatrix3D.M[1][3]) = v41;
    v43 = v57;
    LODWORD(v4->ViewMatrix3D.M[2][0]) = v42;
    v44 = v58;
    LODWORD(v4->ViewMatrix3D.M[2][1]) = v43;
    v45 = v59;
    LODWORD(v4->ViewMatrix3D.M[2][2]) = v44;
    LODWORD(v4->ViewMatrix3D.M[2][3]) = v45;
  }
  v46 = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
  v47 = (signed __int64)((unsigned __int128)((signed __int64)(v46 - (v46 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  LODWORD(v46) = *(_WORD *)(*(_QWORD *)(*(_QWORD *)((v46 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                      + 8 * ((unsigned int)v47 + (v47 >> 63))
                                      + 40)
                          + 10i64) & 0xC;
  v4->VarsSet |= 0x4000u;
  v4->EdgeAAMode = v46;
  return 1;
}

// File Line: 1108
// RVA: 0x818CC0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayInfo(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value::DisplayInfo *cinfo)
{
  __int64 v3; // rcx
  Scaleform::GFx::Value::DisplayInfo *v4; // rsi
  Scaleform::GFx::TextField *v5; // rdi
  char v6; // r14
  bool v7; // r12
  Scaleform::Render::EdgeAAMode v8; // ebx
  Scaleform::Render::TreeNode *v9; // rax
  Scaleform::Render::Cxform *v10; // rax
  double v11; // xmm1_8
  float v12; // xmm0_4
  double v13; // xmm8_8
  double v14; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v15; // rax
  double v16; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v17; // rax
  long double v18; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v19; // rbx
  double v20; // xmm0_8
  long double v21; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v22; // rbx
  double v23; // xmm0_8
  unsigned __int16 v24; // cx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v26; // rbx
  char v27; // r14
  __int64 v28; // rax
  float v29; // xmm2_4
  __m128d v30; // xmm0
  float v31; // xmm1_4
  __m128d v32; // xmm11
  __m128d v33; // xmm10
  unsigned __int16 v34; // r15
  __m128 v35; // xmm7
  float v36; // xmm6_4
  __m128 v37; // xmm9
  float v38; // xmm8_4
  long double v39; // xmm0_8
  __m128d v40; // xmm2
  double v41; // xmm7_8
  double v42; // xmm3_8
  double v43; // xmm8_8
  __m128d v44; // xmm1
  double v45; // xmm6_8
  long double v46; // xmm0_8
  double v47; // xmm0_8
  double v48; // xmm6_8
  double v49; // xmm1_8
  double v50; // xmm0_8
  double v51; // xmm14_8
  double v52; // xmm0_8
  double v53; // xmm1_8
  __int64 v54; // rcx
  signed int v55; // eax
  __int64 v56; // rcx
  bool v57; // zf
  Scaleform::RefCountNTSImplCoreVtbl *v58; // rax
  double v59; // xmm11_8
  double v60; // xmm11_8
  double v61; // xmm10_8
  double v62; // xmm10_8
  unsigned __int64 v64; // [rsp+28h] [rbp-C8h]
  double v65; // [rsp+28h] [rbp-C8h]
  unsigned __int64 v66; // [rsp+30h] [rbp-C0h]
  Scaleform::Render::Matrix2x4<float> v67; // [rsp+40h] [rbp-B0h]
  Scaleform::Render::Cxform v68; // [rsp+60h] [rbp-90h]
  double retaddr; // [rsp+148h] [rbp+58h]
  double v70; // [rsp+158h] [rbp+68h]

  v3 = *((_QWORD *)pdata + 5);
  v4 = cinfo;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) < 0xC && ~(*(_BYTE *)(v3 + 112) >> 5) & 1 )
  {
    v5 = (Scaleform::GFx::TextField *)*((_QWORD *)pdata + 11);
    v6 = 0;
    v7 = ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[81].__vecDelDtor)(v5) == 4;
    if ( (v4->VarsSet >> 14) & 1 )
    {
      v8 = v4->EdgeAAMode;
      v9 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
      Scaleform::Render::TreeNode::SetEdgeAAMode(v9, v8);
    }
    if ( (LOBYTE(v4->VarsSet) >> 5) & 1 )
    {
      retaddr = v4->Alpha;
      if ( (*(_QWORD *)&v4->Alpha & 0x7FF0000000000000i64) != 9218868437227405312i64
        || !(*(_QWORD *)&v4->Alpha & 0xFFFFFFFFFFFFFi64) )
      {
        v10 = Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
        v11 = v4->Alpha * 0.01;
        *(_OWORD *)&v68.M[0][0] = *(_OWORD *)&v10->M[0][0];
        *(_OWORD *)&v68.M[1][0] = *(_OWORD *)&v10->M[1][0];
        v12 = v11;
        if ( COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)&v68.M[0][0], *(__m128 *)&v68.M[0][0], 255)) != v12 )
        {
          v68.M[0][3] = v11;
          Scaleform::GFx::DisplayObjectBase::SetCxform((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr, &v68);
          v5->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, 0);
        }
      }
    }
    if ( (LOBYTE(v4->VarsSet) >> 6) & 1 )
      v5->vfptr[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, v4->Visible);
    v13 = DOUBLE_20_0;
    if ( SLOBYTE(v4->VarsSet) < 0 )
    {
      v14 = v4->Z * 20.0;
      retaddr = v14;
      if ( (*(_QWORD *)&v14 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v14 & 0xFFFFFFFFFFFFFi64 )
        v14 = 0.0;
      retaddr = v14;
      if ( v14 == -1.797693134862316e308/*-Inf*/ || (retaddr = v14, v14 == 1.797693134862316e308/*+Inf*/) )
        v14 = 0.0;
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
      v15 = v5->pGeomData;
      if ( v14 != v15->Z )
      {
        v15->Z = v14;
        v6 = 1;
      }
    }
    if ( (v4->VarsSet >> 10) & 1 )
    {
      v16 = v4->ZScale;
      retaddr = v4->ZScale;
      if ( (*(_QWORD *)&v4->ZScale & 0x7FF0000000000000i64) == 9218868437227405312i64
        && *(_QWORD *)&v4->ZScale & 0xFFFFFFFFFFFFFi64
        || (retaddr = v4->ZScale, v16 == -1.797693134862316e308/*-Inf*/)
        || (retaddr = v4->ZScale, v16 == 1.797693134862316e308/*+Inf*/) )
      {
        v16 = DOUBLE_100_0;
      }
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
      v17 = v5->pGeomData;
      if ( v16 != v17->ZScale )
      {
        v17->ZScale = v16;
        v6 = 1;
      }
    }
    if ( v4->VarsSet & 0x100 )
    {
      v18 = v4->XRotation;
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
      v19 = v5->pGeomData;
      v20 = fmod(v18, 360.0);
      if ( v20 <= 180.0 )
      {
        if ( v20 < -180.0 )
          v20 = v20 + 360.0;
      }
      else
      {
        v20 = v20 + -360.0;
      }
      if ( v20 != v19->XRotation )
      {
        v19->XRotation = v20;
        v6 = 1;
      }
    }
    if ( !((v4->VarsSet >> 9) & 1) )
      goto LABEL_142;
    v21 = v4->YRotation;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
    v22 = v5->pGeomData;
    v23 = fmod(v21, 360.0);
    if ( v23 <= 180.0 )
    {
      if ( v23 < -180.0 )
        v23 = v23 + 360.0;
    }
    else
    {
      v23 = v23 + -360.0;
    }
    if ( v23 != v22->YRotation )
    {
      v22->YRotation = v23;
    }
    else
    {
LABEL_142:
      if ( !v6 )
        goto LABEL_45;
    }
    ((void (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[13].__vecDelDtor)(v5);
LABEL_45:
    v24 = v4->VarsSet;
    if ( (v24 >> 11) & 1 )
    {
      fmod(v4->FOV, 180.0);
      ((void (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[40].__vecDelDtor)(v5);
    }
    else
    {
      if ( (v24 >> 12) & 1 )
        v5->vfptr[7].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v4->ProjectionMatrix3D);
      if ( (v4->VarsSet >> 13) & 1 )
        v5->vfptr[10].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v4->ViewMatrix3D);
    }
    if ( !(v4->VarsSet & 0x1F) )
      return 1;
    if ( v7 )
    {
      v5->Flags |= 0x2000u;
      Scaleform::GFx::TextField::SetDirtyFlag(v5);
    }
    v5->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, 0);
    v26 = v5->pGeomData;
    v27 = 0;
    v28 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[2].__vecDelDtor)(v5);
    *(_QWORD *)&v67.M[0][0] = *(_QWORD *)v28;
    v67.M[0][2] = *(float *)(v28 + 8);
    v29 = *(float *)(v28 + 12);
    v67.M[0][3] = *(float *)(v28 + 12);
    *(_QWORD *)&v67.M[1][0] = *(_QWORD *)(v28 + 16);
    v30 = (__m128d)*(unsigned int *)(v28 + 24);
    v67.M[1][2] = *(float *)(v28 + 24);
    v31 = *(float *)(v28 + 28);
    v67.M[1][3] = *(float *)(v28 + 28);
    if ( v7 && v4->VarsSet & 3 )
    {
      Scaleform::GFx::TextField::TransformToTextRectSpace(v5, (Scaleform::Render::Point<float> *)&retaddr, v4);
      v31 = v67.M[1][3];
      v29 = v67.M[0][3];
      v32 = _mm_cvtps_pd((__m128)LODWORD(retaddr));
      v33 = _mm_cvtps_pd((__m128)HIDWORD(retaddr));
    }
    else
    {
      if ( v4->VarsSet & 1 )
        v32 = (__m128d)*(unsigned __int64 *)&v4->X;
      else
        v32 = (__m128d)v64;
      if ( (LOBYTE(v4->VarsSet) >> 1) & 1 )
        v33 = (__m128d)*(unsigned __int64 *)&v4->Y;
      else
        v33 = (__m128d)v66;
    }
    v34 = v4->VarsSet;
    if ( v34 & 0x1C )
    {
      v35 = (__m128)LODWORD(v26->OrigMatrix.M[0][0]);
      v36 = v26->OrigMatrix.M[1][0];
      v37 = (__m128)LODWORD(v26->OrigMatrix.M[0][1]);
      v38 = v26->OrigMatrix.M[1][1];
      v68.M[0][2] = v26->OrigMatrix.M[0][2];
      *(_QWORD *)&v68.M[1][2] = __PAIR__(LODWORD(v31), LODWORD(v26->OrigMatrix.M[1][2]));
      *(_QWORD *)&v68.M[0][0] = __PAIR__(v37.m128_u32[0], v35.m128_u32[0]);
      *(_QWORD *)&v68.M[1][0] = __PAIR__(LODWORD(v38), LODWORD(v36));
      v68.M[0][3] = v29;
      v39 = atan2(v36, v35.m128_f32[0]);
      v40 = _mm_cvtps_pd(v35);
      v41 = v26->YScale * 0.01;
      v65 = v39;
      v40.m128d_f64[0] = v40.m128d_f64[0] * v40.m128d_f64[0] + v36 * v36;
      v42 = v38;
      v43 = v26->XScale * 0.01;
      v44 = _mm_cvtps_pd(v37);
      *(_QWORD *)&retaddr = (unsigned __int128)_mm_sqrt_pd(v40);
      v44.m128d_f64[0] = v44.m128d_f64[0] * v44.m128d_f64[0] + v42 * v42;
      v45 = v26->Rotation * 3.141592653589793 * 0.005555555555555556;
      *(_QWORD *)&v70 = (unsigned __int128)_mm_sqrt_pd(v44);
      if ( ((unsigned __int8)v34 >> 2) & 1 )
        v46 = v4->Rotation;
      else
        v46 = Scaleform::GFx::NumberUtil::NaN();
      if ( (*(_QWORD *)&v46 & 0x7FF0000000000000i64) != 9218868437227405312i64
        || !(*(_QWORD *)&v46 & 0xFFFFFFFFFFFFFi64) )
      {
        v47 = fmod(v46, 360.0);
        v48 = v47;
        if ( v47 <= 180.0 )
        {
          if ( v47 < -180.0 )
            v48 = v47 + 360.0;
        }
        else
        {
          v48 = v47 + -360.0;
        }
        if ( v48 != v26->Rotation )
        {
          v26->Rotation = v48;
          v27 = 1;
        }
        v45 = v48 * 3.141592653589793 * 0.005555555555555556;
      }
      if ( (LOBYTE(v4->VarsSet) >> 3) & 1 )
      {
        v49 = DOUBLE_0_01;
        v50 = v4->XScale * 0.01;
      }
      else
      {
        v50 = Scaleform::GFx::NumberUtil::NaN();
        v49 = DOUBLE_0_01;
      }
      v51 = retaddr;
      if ( v50 != v43 && (*(_QWORD *)&v50 & 0x7FF0000000000000i64) != 9218868437227405312i64 )
      {
        v26->XScale = v4->XScale;
        if ( retaddr == 0.0 || v50 > 1.0e16 )
        {
          v50 = 0.0;
          v51 = DOUBLE_1_0;
        }
        v43 = v50;
        v27 = 1;
      }
      if ( (LOBYTE(v4->VarsSet) >> 4) & 1 )
        v52 = v4->YScale * v49;
      else
        v52 = Scaleform::GFx::NumberUtil::NaN();
      v53 = v70;
      if ( v52 != v41 )
      {
        retaddr = v52;
        if ( (*(_QWORD *)&v52 & 0x7FF0000000000000i64) != 9218868437227405312i64 )
        {
          v26->YScale = v4->YScale;
          if ( v70 == 0.0 || v52 > 1.0e16 )
          {
            v52 = 0.0;
            v53 = DOUBLE_1_0;
          }
          v41 = v52;
          v27 = 1;
        }
      }
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        (Scaleform::Render::Matrix2x4<float> *)&v68,
        v43 / v51,
        v41 / v53,
        v45 - v65);
      v13 = DOUBLE_20_0;
      v67 = (Scaleform::Render::Matrix2x4<float>)v68;
      v30.m128d_f64[1] = *(long double *)&v68.M[1][2];
    }
    if ( v4->VarsSet & 1 )
      v30 = v32;
    else
      v30.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    retaddr = v30.m128d_f64[0];
    if ( (*(_QWORD *)&v30.m128d_f64[0] & 0x7FF0000000000000i64) != 9218868437227405312i64
      || !(*(_QWORD *)&v30.m128d_f64[0] & 0xFFFFFFFFFFFFFi64) )
    {
      retaddr = v30.m128d_f64[0];
      if ( *(_QWORD *)&v30.m128d_f64[0] == -4503599627370496i64
        || (retaddr = v30.m128d_f64[0], *(_QWORD *)&v30.m128d_f64[0] == 9218868437227405312i64) )
      {
        v30 = 0i64;
      }
      v30.m128d_f64[0] = v30.m128d_f64[0] * v13;
      v54 = (unsigned int)(signed int)v30.m128d_f64[0];
      if ( v54 != 0x8000000000000000i64 && (double)(signed int)v54 != v30.m128d_f64[0] )
        v30.m128d_f64[0] = (double)(signed int)(v54 - (_mm_movemask_pd(_mm_unpckl_pd(v30, v30)) & 1));
      v55 = (signed int)v30.m128d_f64[0];
      v26->X = (signed int)v30.m128d_f64[0];
      v30 = (__m128d)LODWORD(v67.M[0][3]);
      if ( v67.M[0][3] != (float)v55 )
      {
        v67.M[0][3] = (float)v55;
        v27 = 1;
      }
    }
    if ( (LOBYTE(v4->VarsSet) >> 1) & 1 )
      v30 = v33;
    else
      v30.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    retaddr = v30.m128d_f64[0];
    if ( (*(_QWORD *)&v30.m128d_f64[0] & 0x7FF0000000000000i64) == 9218868437227405312i64
      && *(_QWORD *)&v30.m128d_f64[0] & 0xFFFFFFFFFFFFFi64 )
    {
      goto LABEL_143;
    }
    retaddr = v30.m128d_f64[0];
    if ( *(_QWORD *)&v30.m128d_f64[0] == -4503599627370496i64
      || (retaddr = v30.m128d_f64[0], *(_QWORD *)&v30.m128d_f64[0] == 9218868437227405312i64) )
    {
      v30 = 0i64;
    }
    v30.m128d_f64[0] = v30.m128d_f64[0] * v13;
    v56 = (unsigned int)(signed int)v30.m128d_f64[0];
    if ( v56 != 0x8000000000000000i64 && (double)(signed int)v56 != v30.m128d_f64[0] )
      v30.m128d_f64[0] = (double)(signed int)(v56 - (_mm_movemask_pd(_mm_unpckl_pd(v30, v30)) & 1));
    v26->Y = (signed int)v30.m128d_f64[0];
    if ( v67.M[1][3] == (float)(signed int)v30.m128d_f64[0] )
    {
LABEL_143:
      if ( !v27 )
      {
LABEL_127:
        if ( v7 )
        {
          if ( v4->VarsSet & 1 )
          {
            v59 = v32.m128d_f64[0] * v13;
            if ( v59 <= 0.0 )
              v60 = v59 - 0.5;
            else
              v60 = v59 + 0.5;
            v26->X = (signed int)v60;
          }
          if ( (LOBYTE(v4->VarsSet) >> 1) & 1 )
          {
            v61 = v33.m128d_f64[0] * v13;
            if ( v61 <= 0.0 )
              v62 = v61 - 0.5;
            else
              v62 = v61 + 0.5;
            v26->Y = (signed int)v62;
          }
        }
        return 1;
      }
    }
    else
    {
      v67.M[1][3] = (float)(signed int)v30.m128d_f64[0];
    }
    if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v67) )
    {
      v57 = Scaleform::GFx::DisplayObjectBase::Has3D((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr) == 0;
      v58 = v5->vfptr;
      if ( v57 )
        v58[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v67);
      else
        ((void (__fastcall *)(Scaleform::GFx::TextField *))v58[13].__vecDelDtor)(v5);
    }
    goto LABEL_127;
  }
  return 0;
}

// File Line: 1406
// RVA: 0x81EA40
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetText(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *ptext, bool reqHtml)
{
  bool v4; // di
  const char *v5; // rbp
  void *v6; // rsi
  Scaleform::GFx::AS3ValueObjectInterface *v7; // r14
  __int64 v8; // rdx
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  __int64 v11; // rbx
  unsigned int v13; // eax
  char v14; // cl
  unsigned int v15; // eax
  char v16; // [rsp+38h] [rbp-40h]
  __int64 v17; // [rsp+48h] [rbp-30h]
  unsigned int v18; // [rsp+50h] [rbp-28h]
  const char *v19; // [rsp+58h] [rbp-20h]

  v4 = reqHtml;
  v5 = ptext;
  v6 = pdata;
  v7 = this;
  v8 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v8 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v8 + 112) >> 5) & 1) )
    return 0;
  v9 = (Scaleform::GFx::TextField *)*((_QWORD *)v6 + 11);
  if ( ((unsigned int (__fastcall *)(_QWORD))v9->vfptr[81].__vecDelDtor)(*((_QWORD *)v6 + 11)) == 4 )
  {
    v13 = v9->Flags;
    v14 = (v9->Flags >> 1) & 1;
    if ( v4 )
    {
      if ( !v14 )
      {
        v15 = v13 | 2;
LABEL_14:
        v9->Flags = v15;
        goto LABEL_15;
      }
    }
    else if ( v14 )
    {
      v15 = v13 & 0xFFFFFFFD;
      goto LABEL_14;
    }
LABEL_15:
    Scaleform::GFx::TextField::SetTextValue(v9, v5, v4, 1);
    return 1;
  }
  v17 = 0i64;
  v18 = 6;
  v19 = v5;
  v10 = "text";
  if ( v4 )
    v10 = "htmlText";
  v11 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::AS3ValueObjectInterface *, void *, const char *, char *, char))&v7->vfptr->gap8[32])(
          v7,
          v6,
          v10,
          &v16,
          1);
  if ( (v18 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v17 + 16i64))(v17, &v16, v19);
    v17 = 0i64;
  }
  v18 = 0;
  return v11;
}

// File Line: 1424
// RVA: 0x81EB80
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetText(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const wchar_t *ptext, bool reqHtml)
{
  bool v4; // si
  const wchar_t *v5; // rbp
  void *v6; // rdi
  Scaleform::GFx::AS3ValueObjectInterface *v7; // r14
  __int64 v8; // rdx
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  char v11; // ST20_1
  __int64 v12; // rbx
  char result; // al
  char v14; // [rsp+38h] [rbp-40h]
  __int64 v15; // [rsp+48h] [rbp-30h]
  unsigned int v16; // [rsp+50h] [rbp-28h]
  const wchar_t *v17; // [rsp+58h] [rbp-20h]

  v4 = reqHtml;
  v5 = ptext;
  v6 = pdata;
  v7 = this;
  v8 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v8 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v8 + 112) >> 5) & 1) )
    return 0;
  v9 = (Scaleform::GFx::TextField *)*((_QWORD *)v6 + 11);
  if ( ((unsigned int (__fastcall *)(_QWORD))v9->vfptr[81].__vecDelDtor)(*((_QWORD *)v6 + 11)) == 4 )
  {
    Scaleform::GFx::TextField::SetText(v9, v5, v4);
    result = 1;
  }
  else
  {
    v15 = 0i64;
    v16 = 7;
    v17 = v5;
    v10 = "text";
    if ( v4 )
      v10 = "htmlText";
    v11 = 1;
    v12 = (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::AS3ValueObjectInterface *, void *, const char *, char *, char))&v7->vfptr->gap8[32])(
            v7,
            v6,
            v10,
            &v14,
            v11);
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const wchar_t *))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
      v15 = 0i64;
    }
    v16 = 0;
    result = v12;
  }
  return result;
}

// File Line: 1442
// RVA: 0x7F0240
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetText(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pval, bool reqHtml)
{
  bool v4; // di
  Scaleform::GFx::Value *v5; // r15
  void *v6; // rsi
  Scaleform::GFx::AS3ValueObjectInterface *v7; // r14
  Scaleform::GFx::AS3::MovieRoot *v8; // r12
  __int64 v9; // rdx
  Scaleform::GFx::TextField *v10; // rbx
  const char *v11; // r8
  char v12; // al
  Scaleform::GFx::ASString *v13; // rax
  char v14; // di
  Scaleform::GFx::ASStringNode *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int v19; // edi
  Scaleform::GFx::AS3::Value::V2U v20; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS3::Value value; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASString v22; // [rsp+B0h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+B8h] [rbp+48h]

  v4 = reqHtml;
  v5 = pval;
  v6 = pdata;
  v7 = this;
  v8 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v9 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v9 + 112) >> 5) & 1) )
    return 0;
  v10 = (Scaleform::GFx::TextField *)*((_QWORD *)v6 + 11);
  if ( ((unsigned int (__fastcall *)(_QWORD))v10->vfptr[81].__vecDelDtor)(*((_QWORD *)v6 + 11)) == 4 )
  {
    if ( v4 )
    {
      v13 = Scaleform::GFx::TextField::GetHtml(v10, &result);
      v14 = 1;
    }
    else
    {
      v13 = Scaleform::GFx::TextField::GetText(v10, &v22, 0);
      v14 = 2;
    }
    v15 = v13->pNode;
    ++v15->RefCount;
    if ( v14 & 2 )
    {
      v14 &= 0xFDu;
      v16 = v22.pNode;
      v17 = v22.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    if ( v14 & 1 )
    {
      v18 = result.pNode;
      v17 = result.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
    value.Flags = 10;
    value.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&value.value.VNumber = v15;
    if ( v15 == &v15->pManager->NullStringNode )
    {
      value.value.VNumber = 0.0;
      value.value.VS._2 = v20;
      value.Flags = 12;
    }
    else
    {
      ++v15->RefCount;
    }
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v8, &value, v5);
    v19 = value.Flags;
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags >> 9) & 1 )
      {
        v17 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        value.Bonus.pWeakProxy = 0i64;
        value.value = 0ui64;
        value.Flags = v19 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
    v17 = v15->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    v12 = 1;
  }
  else
  {
    v11 = "text";
    if ( v4 )
      v11 = "htmlText";
    v12 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS3ValueObjectInterface *, void *, const char *, Scaleform::GFx::Value *, char))&v7->vfptr->gap8[24])(
            v7,
            v6,
            v11,
            v5,
            1);
  }
  return v12;
}

// File Line: 1462
// RVA: 0x7F1CE0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GotoAndPlay(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, const char *frame, __int64 stop)
{
  Scaleform::GFx::MovieImpl *v4; // rax
  __int64 v5; // rcx
  char v6; // si
  Scaleform::GFx::AS3::MovieRoot *v7; // rdi
  _WORD *v8; // rbx
  unsigned int v10; // [rsp+30h] [rbp+8h]

  v4 = this->pMovieRoot;
  v5 = *((_QWORD *)pdata + 5);
  v6 = stop;
  v7 = (Scaleform::GFx::AS3::MovieRoot *)v4->pASMovieRoot.pObject;
  if ( (unsigned int)(*(_DWORD *)(v5 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v5 + 112) >> 5) & 1) )
    return 0;
  v8 = (_WORD *)*((_QWORD *)pdata + 11);
  if ( !((v8[53] >> 10) & 1) )
    return 0;
  LOBYTE(stop) = 1;
  if ( !(*(unsigned __int8 (__fastcall **)(_WORD *, const char *, unsigned int *, __int64))(*(_QWORD *)v8 + 864i64))(
          v8,
          frame,
          &v10,
          stop) )
    return 0;
  (*(void (__fastcall **)(_WORD *, _QWORD))(*(_QWORD *)v8 + 880i64))(v8, v10);
  (*(void (__fastcall **)(_WORD *, bool))(*(_QWORD *)v8 + 912i64))(v8, v6 != 0);
  Scaleform::GFx::AS3::FrameCounter::QueueFrameActions((Scaleform::GFx::AS3::FrameCounter *)v7->pStage.pObject->FrameCounterObj.pObject);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(v7, 0);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(v7, AL_High);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(v7, AL_Frame);
  return 1;
}

// File Line: 1492
// RVA: 0x7F1C00
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GotoAndPlay(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, unsigned int frame, bool stop)
{
  Scaleform::GFx::MovieImpl *v4; // rax
  __int64 v5; // rcx
  bool v6; // si
  Scaleform::GFx::AS3::MovieRoot *v7; // rdi
  _WORD *v8; // rbx

  v4 = this->pMovieRoot;
  v5 = *((_QWORD *)pdata + 5);
  v6 = stop;
  v7 = (Scaleform::GFx::AS3::MovieRoot *)v4->pASMovieRoot.pObject;
  if ( (unsigned int)(*(_DWORD *)(v5 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v5 + 112) >> 5) & 1) )
    return 0;
  v8 = (_WORD *)*((_QWORD *)pdata + 11);
  if ( !((v8[53] >> 10) & 1) )
    return 0;
  (*(void (__fastcall **)(_WORD *, _QWORD))(*(_QWORD *)v8 + 880i64))(v8, frame - 1);
  (*(void (__fastcall **)(_WORD *, bool))(*(_QWORD *)v8 + 912i64))(v8, v6 != 0);
  Scaleform::GFx::AS3::FrameCounter::QueueFrameActions((Scaleform::GFx::AS3::FrameCounter *)v7->pStage.pObject->FrameCounterObj.pObject);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(v7, 0);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(v7, AL_High);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(v7, AL_Frame);
  return 1;
}

// File Line: 1518
// RVA: 0x7E74F0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetCxform(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::Render::Cxform *pcx)
{
  __int64 v3; // rcx
  Scaleform::Render::Cxform *v4; // rbx
  Scaleform::Render::Cxform *v5; // rax
  __int128 v6; // xmm1
  char result; // al

  v3 = *((_QWORD *)pdata + 5);
  v4 = pcx;
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v5 = Scaleform::GFx::DisplayObjectBase::GetCxform(*((Scaleform::GFx::DisplayObjectBase **)pdata + 11));
  *(_OWORD *)&v4->M[0][0] = *(_OWORD *)&v5->M[0][0];
  v6 = *(_OWORD *)&v5->M[1][0];
  result = 1;
  *(_OWORD *)&v4->M[1][0] = v6;
  return result;
}

// File Line: 1530
// RVA: 0x818C50
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetCxform(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::Render::Cxform *cx)
{
  __int64 v3; // rcx
  Scaleform::GFx::DisplayObjectBase *v4; // rbx

  v3 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || !(~(*(_BYTE *)(v3 + 112) >> 5) & 1) )
    return 0;
  v4 = (Scaleform::GFx::DisplayObjectBase *)*((_QWORD *)pdata + 11);
  Scaleform::GFx::DisplayObjectBase::SetCxform(v4, cx);
  v4->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 0);
  return 1;
}

// File Line: 1551
// RVA: 0x7BC660
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::CreateEmptyMovieClip(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pmc, const char *instanceName, int depth)
{
  const char *v5; // rbp
  Scaleform::GFx::Value *v6; // r14
  Scaleform::GFx::ASMovieRootBase *v7; // rsi
  __int64 v8; // rcx
  __int64 v9; // rbx
  long double v10; // rdi
  __int64 v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  __int64 v15; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v16; // rcx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v17; // rdx
  char v18; // bl
  Scaleform::GFx::AS3::Value value; // [rsp+48h] [rbp-60h]
  Scaleform::GFx::AS3::Value v21; // [rsp+68h] [rbp-40h]
  Scaleform::GFx::ASString v22; // [rsp+B0h] [rbp+8h]

  v5 = instanceName;
  v6 = pmc;
  v7 = this->pMovieRoot->pASMovieRoot.pObject;
  v8 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v8 + 120) - 29) >= 5 || !(~(*(_BYTE *)(v8 + 112) >> 5) & 1) )
    return 0;
  v9 = *((_QWORD *)pdata + 11);
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::VM::CreateObject(
         (Scaleform::GFx::AS3::VM *)v7[2].vfptr,
         (Scaleform::GFx::AS3::CheckResult *)&v22,
         "flash.display.Sprite",
         (Scaleform::GFx::AS3::VMAppDomain *)v7[2].vfptr[52].__vecDelDtor,
         &value,
         0,
         0i64)->Result
    && (v10 = value.value.VNumber,
        v11 = *(_QWORD *)(*(_QWORD *)&value.value.VNumber + 40i64),
        (unsigned int)(*(_DWORD *)(v11 + 120) - 22) < 0xC)
    && ~(*(_BYTE *)(v11 + 112) >> 5) & 1 )
  {
    v21.Flags = 0;
    v21.Bonus.pWeakProxy = 0i64;
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)&v7[9],
            &v22,
            v5);
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
      *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)&v10,
      &v21,
      v12);
    v13 = v22.pNode;
    v14 = v22.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    if ( !v9
      || (v15 = (*(__int64 (**)(void))(*(_QWORD *)(v9 + 4i64 * *(unsigned __int8 *)(v9 + 109)) + 40i64))(),
          v16 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v15 - 72),
          !v15) )
    {
      v16 = 0i64;
    }
    if ( depth >= 0 )
      LODWORD(v17) = depth;
    else
      v17 = v16->pDispObj[1].pGeomData;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(
      v16,
      *(Scaleform::GFx::DisplayObjectBase **)(*(_QWORD *)&v10 + 88i64),
      (unsigned int)v17);
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue((Scaleform::GFx::AS3::MovieRoot *)v7, &value, v6);
    v18 = 1;
  }
  else
  {
    v18 = 0;
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v14 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v14 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  return v18;
}

// File Line: 1585
// RVA: 0x7B1C80
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::AttachMovie(Scaleform::GFx::AS3ValueObjectInterface *this, void *pdata, Scaleform::GFx::Value *pmc, const char *symbolName, const char *instanceName, int depth, Scaleform::GFx::MemberValueSet *initArgs)
{
  const char *v7; // r14
  Scaleform::GFx::Value *v8; // r15
  Scaleform::GFx::AS3::MovieRoot *v9; // r13
  __int64 v10; // rcx
  __int64 v11; // rbx
  Scaleform::GFx::AS3::VM *v12; // rdi
  __int64 v13; // rax
  signed __int64 v14; // r9
  Scaleform::GFx::LogState *v15; // rbx
  long double v16; // rdi
  __int64 v17; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v18; // rsi
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::MemberValueSet *v22; // r12
  unsigned int v23; // er15
  __int64 v24; // r14
  signed __int64 v25; // r14
  long double *v26; // rax
  unsigned int v27; // edi
  long double v28; // rbx
  Scaleform::GFx::AS3::Value::V2U v29; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v30; // rcx
  int v31; // esi
  __int64 v32; // rax
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  __int64 v37; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v38; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v39; // rdi
  Scaleform::GFx::LogState *v40; // rsi
  char v41; // bl
  Scaleform::GFx::AS3::Value *v43; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS3::Value v44; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value value; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS3::Multiname v47; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::DisplayObjectBase **v48; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::ASString v49; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::ASString v50; // [rsp+E0h] [rbp-20h]
  __int64 v51; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v52; // [rsp+F0h] [rbp-10h]
  __int64 v53; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::AS3::Value v54; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::ASString v56; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::Value *v57; // [rsp+180h] [rbp+80h]
  const char *v58; // [rsp+188h] [rbp+88h]

  v58 = symbolName;
  v57 = pmc;
  v53 = -2i64;
  v7 = symbolName;
  v8 = pmc;
  v9 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v10 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v10 + 120) - 29) >= 5 || !(~(*(_BYTE *)(v10 + 112) >> 5) & 1) )
    return 0;
  v51 = *((_QWORD *)pdata + 11);
  v11 = v51;
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  v12 = (Scaleform::GFx::AS3::VM *)&v9->pAVM.pObject->vfptr;
  if ( !v51
    || (v13 = (*(__int64 (**)(void))(*(_QWORD *)(v51 + 4i64 * *(unsigned __int8 *)(v51 + 109)) + 40i64))(),
        v14 = v13 - 72,
        !v13) )
  {
    v14 = 0i64;
  }
  if ( Scaleform::GFx::AS3::VM::CreateObject(
         v12,
         &result,
         v7,
         *(Scaleform::GFx::AS3::VMAppDomain **)(v14 + 40),
         &value,
         0,
         0i64)->Result )
  {
    v16 = value.value.VNumber;
    v48 = (Scaleform::GFx::DisplayObjectBase **)value.value.VS._1.VStr;
    v17 = *(_QWORD *)(*(_QWORD *)&value.value.VNumber + 40i64);
    if ( (unsigned int)(*(_DWORD *)(v17 + 120) - 22) < 0xC && ~(*(_BYTE *)(v17 + 112) >> 5) & 1 )
    {
      v54.Flags = 0;
      v54.Bonus.pWeakProxy = 0i64;
      v18 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->BuiltinsMgr.Builtins;
      v19 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->BuiltinsMgr.Builtins,
              (Scaleform::GFx::ASString *)&result,
              instanceName);
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
        *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)&v16,
        &v54,
        v19);
      v20 = *(Scaleform::GFx::ASStringNode **)&result.Result;
      v21 = *(_DWORD *)(*(_QWORD *)&result.Result + 24i64) == 1;
      --v20->RefCount;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      v22 = initArgs;
      if ( initArgs )
      {
        v23 = 0;
        if ( initArgs->Data.Size > 0 )
        {
          v24 = 0i64;
          do
          {
            v25 = (signed __int64)&v22->Data.Data[v24];
            v26 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                   v18,
                                   &v49,
                                   (Scaleform::String *)v25);
            v27 = 10;
            v44.Flags = 10;
            v44.Bonus.pWeakProxy = 0i64;
            v28 = *v26;
            v44.value.VNumber = v28;
            if ( *(_QWORD *)&v28 == *(_QWORD *)(*(_QWORD *)&v28 + 8i64) + 104i64 )
            {
              v28 = 0.0;
              v44.value.VNumber = 0.0;
              v29.VObj = v52.VObj;
              v44.value.VS._2 = v52;
              v27 = 12;
              v44.Flags = 12;
            }
            else
            {
              ++*(_DWORD *)(*(_QWORD *)&v28 + 24i64);
              v29.VObj = (Scaleform::GFx::AS3::Object *)v44.value.VS._2;
            }
            v30 = (Scaleform::GFx::AS3::GASRefCountBase *)&v9->pAVM.pObject->PublicNamespace.pObject->vfptr;
            v47.Kind = 0;
            v47.Obj.pObject = v30;
            if ( v30 )
              v30->RefCount = (v30->RefCount + 1) & 0x8FBFFFFF;
            v47.Name.Flags = 0;
            v47.Name.Bonus.pWeakProxy = 0i64;
            v31 = v27 & 0x1F;
            if ( (unsigned int)(v31 - 12) <= 3
              && v28 != 0.0
              && (v32 = *(_QWORD *)(*(_QWORD *)&v28 + 40i64), *(_DWORD *)(v32 + 120) == 17)
              && ~(*(_BYTE *)(v32 + 112) >> 5) & 1 )
            {
              Scaleform::GFx::AS3::Value::Assign(&v47.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v28 + 56i64));
              Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v47.Obj,
                *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v28 + 64i64));
              v47.Kind &= 0xFFFFFFF9;
            }
            else
            {
              __asm { prefetcht1 byte ptr [rsp+160h+var_120.Flags]; Prefetch to all cache levels }
              *(_QWORD *)&v47.Name.Flags = *(_QWORD *)&v44.Flags;
              v47.Name.Bonus.pWeakProxy = 0i64;
              v47.Name.value.VNumber = v28;
              v47.Name.value.VS._2 = v29;
              if ( v31 > 9 )
              {
                if ( (v27 >> 9) & 1 )
                {
                  LODWORD(MEMORY[0]) = MEMORY[0] + 1;
                }
                else if ( v31 == 10 )
                {
                  ++*(_DWORD *)(*(_QWORD *)&v28 + 24i64);
                }
                else if ( v31 > 10 )
                {
                  if ( v31 <= 15 )
                  {
                    if ( v28 != 0.0 )
                      *(_DWORD *)(*(_QWORD *)&v28 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v28 + 32i64) + 1) & 0x8FBFFFFF;
                  }
                  else if ( v31 <= 17 && v29.VObj )
                  {
                    v29.VObj->RefCount = (v29.VObj->RefCount + 1) & 0x8FBFFFFF;
                  }
                }
              }
              if ( (v47.Name.Flags & 0x1F) == 10 )
              {
                Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v47.Name, &v56);
                if ( v56.pNode->Size )
                {
                  if ( *v56.pNode->pData == 64 )
                  {
                    v47.Kind |= 8u;
                    v33 = Scaleform::GFx::ASString::Substring(&v56, &v50, 1, v56.pNode->Size);
                    Scaleform::GFx::AS3::Value::Assign(&v47.Name, v33);
                    v34 = v50.pNode;
                    v21 = v50.pNode->RefCount == 1;
                    --v34->RefCount;
                    if ( v21 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
                  }
                }
                v35 = v56.pNode;
                v21 = v56.pNode->RefCount == 1;
                --v35->RefCount;
                if ( v21 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v35);
              }
            }
            if ( v31 > 9 )
            {
              if ( (v27 >> 9) & 1 )
              {
                LODWORD(MEMORY[0]) = MEMORY[0] - 1;
                if ( !(_DWORD)MEMORY[0] )
                  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
                v44.Bonus.pWeakProxy = 0i64;
                v44.value = 0ui64;
                v44.Flags = v27 & 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v44);
              }
            }
            v36 = v49.pNode;
            v21 = v49.pNode->RefCount == 1;
            --v36->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v36);
            pdestVal.Flags = 0;
            pdestVal.Bonus.pWeakProxy = 0i64;
            Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v9, (Scaleform::GFx::Value *)(v25 + 8), &pdestVal);
            ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase **, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*v48)->vfptr)(
              v48,
              &result,
              &v47,
              &pdestVal);
            if ( (pdestVal.Flags & 0x1F) > 9 )
            {
              if ( (pdestVal.Flags >> 9) & 1 )
              {
                v21 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v21 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                pdestVal.Bonus.pWeakProxy = 0i64;
                pdestVal.value = 0ui64;
                pdestVal.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
              }
            }
            Scaleform::GFx::AS3::Multiname::~Multiname(&v47);
            v24 = ++v23;
            v18 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->BuiltinsMgr.Builtins;
          }
          while ( v23 < v22->Data.Size );
          v11 = v51;
          v7 = v58;
        }
        v8 = v57;
      }
      if ( !v11
        || (v37 = (*(__int64 (**)(void))(*(_QWORD *)(v11 + 4i64 * *(unsigned __int8 *)(v11 + 109)) + 40i64))(),
            v38 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v37 - 72),
            !v37) )
      {
        v38 = 0i64;
      }
      LODWORD(v39) = depth;
      if ( depth > SLODWORD(v38->pDispObj[1].pGeomData) )
      {
        v40 = Scaleform::GFx::StateBag::GetLogState(
                (Scaleform::GFx::StateBag *)&v9->pMovieImpl->vfptr,
                (Scaleform::Ptr<Scaleform::GFx::LogState> *)&result)->pObject;
        if ( *(_QWORD *)&result.Result )
          Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&result.Result);
        if ( v40 )
        {
          LODWORD(v43) = v38->pDispObj[1].pGeomData;
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v40->vfptr,
            "DAPI AttachMovie() depth requested (%d) for symbol \"%s\" is too large. Using next highest index (%d) instead.",
            (unsigned int)v39,
            v7,
            v43);
        }
      }
      if ( (signed int)v39 < 0 || (signed int)v39 > SLODWORD(v38->pDispObj[1].pGeomData) )
        v39 = v38->pDispObj[1].pGeomData;
      Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(v38, v48[11], (unsigned int)v39);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v9, &value, v8);
      v41 = 1;
      goto LABEL_78;
    }
  }
  else
  {
    v15 = Scaleform::GFx::StateBag::GetLogState(
            (Scaleform::GFx::StateBag *)&v9->pMovieImpl->vfptr,
            (Scaleform::Ptr<Scaleform::GFx::LogState> *)&result)->pObject;
    if ( *(_QWORD *)&result.Result )
      Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&result.Result);
    if ( v15 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v15->vfptr,
        "attachMovie() failed - export name \"%s\" is not found.",
        v7);
    v12->HandleException = 0;
  }
  v41 = 0;
LABEL_78:
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v21 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v21 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  return v41;
}

// File Line: 1648
// RVA: 0x826610
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::ToString(Scaleform::GFx::AS3ValueObjectInterface *this, Scaleform::String *pstr, Scaleform::GFx::Value *thisVal)
{
  Scaleform::String *v3; // rdi
  Scaleform::GFx::AS3::MovieRoot *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult v9; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h]

  v3 = pstr;
  v4 = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(v4, thisVal, &pdestVal);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->BuiltinsMgr.Builtins,
    &result);
  Scaleform::GFx::AS3::Value::Convert2String(&pdestVal, &v9, &result);
  Scaleform::String::AssignString(v3, result.pNode->pData, result.pNode->Size);
  v5 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v7 = pdestVal.Flags;
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags >> 9) & 1 )
    {
      v6 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v6 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pdestVal.Bonus.pWeakProxy = 0i64;
      pdestVal.value = 0ui64;
      pdestVal.Flags = v7 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
}

// File Line: 1698
// RVA: 0x7BE5A0
char __fastcall Scaleform::GFx::AS3::MovieRoot::CreateObjectValue(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Value *pval, Scaleform::GFx::Value::ObjectInterface *pobjifc, void *pdata)
{
  __int64 v4; // rcx
  Scaleform::GFx::Value *v5; // rbx
  void *v6; // rbp
  int v7; // edx
  Scaleform::GFx::Value::ObjectInterface *v8; // rsi
  signed int v9; // edi

  v4 = *((_QWORD *)pdata + 5);
  v5 = pval;
  v6 = pdata;
  v7 = *(_DWORD *)(v4 + 120);
  v8 = pobjifc;
  v9 = 8;
  if ( (unsigned int)(v7 - 22) < 0xC && ~(*(_BYTE *)(v4 + 112) >> 5) & 1 )
  {
    v9 = 10;
  }
  else if ( v7 == 7 )
  {
    v9 = 9;
  }
  if ( ((unsigned int)v5->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v5->pObjectInterface->vfptr->gap8[8])(
      v5->pObjectInterface,
      v5,
      *(_QWORD *)&v5->mValue.NValue);
    v5->pObjectInterface = 0i64;
  }
  *(_QWORD *)&v5->mValue.NValue = v6;
  v5->pObjectInterface = v8;
  v5->Type = v9 | 0x40;
  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, void *))v8->vfptr->gap8)(
    v8,
    v5,
    v6);
  return 1;
}

// File Line: 1722
// RVA: 0x7E2F80
void __fastcall Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Value *gfxVal, Scaleform::GFx::AS3::Value *pdestVal)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::Value::ValueType v4; // er8
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS3::Instances::Function *v11; // rdx
  Scaleform::GFx::AS3::Traits *v12; // rax
  __int64 v13; // rax
  unsigned __int64 v14; // rcx
  int v15; // eax
  unsigned __int64 v16; // rax
  unsigned int v17; // ebx
  Scaleform::GFx::ASString v18; // [rsp+20h] [rbp-30h]
  __int64 v19; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::AS3::Value other; // [rsp+30h] [rbp-20h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+18h]
  Scaleform::GFx::ASString v; // [rsp+78h] [rbp+28h]

  v19 = -2i64;
  v3 = pdestVal;
  v4 = gfxVal->Type;
  switch ( gfxVal->Type & 0x8F )
  {
    case 0:
      Scaleform::GFx::AS3::Value::SetUndefined(v3);
      break;
    case 1:
      Scaleform::GFx::AS3::Value::SetNull(v3);
      break;
    case 2:
      Scaleform::GFx::AS3::Value::SetBool(v3, gfxVal->mValue.BValue);
      break;
    case 3:
      Scaleform::GFx::AS3::Value::SetSInt32(v3, gfxVal->mValue.IValue);
      break;
    case 4:
      Scaleform::GFx::AS3::Value::SetUInt32(v3, gfxVal->mValue.UIValue);
      break;
    case 5:
      Scaleform::GFx::AS3::Value::SetNumber(v3, gfxVal->mValue.NValue);
      break;
    case 6:
      if ( ((unsigned int)v4 >> 6) & 1 )
      {
        Scaleform::GFx::AS3::Value::Assign(v3, (Scaleform::GFx::ASStringNode *)gfxVal->mValue.pString);
      }
      else
      {
        v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
               (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->BuiltinsMgr.Builtins,
               &result,
               gfxVal->mValue.pString);
        Scaleform::GFx::AS3::Value::Assign(v3, v5);
        v6 = result.pNode;
        v7 = result.pNode->RefCount == 1;
        --v6->RefCount;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      }
      break;
    case 7:
      if ( ((unsigned int)v4 >> 6) & 1 )
      {
        v8 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&gfxVal->mValue.NValue - 8i64);
        v.pNode = v8;
        ++v8->RefCount;
        Scaleform::GFx::AS3::Value::Assign(v3, &v);
        v7 = v8->RefCount-- == 1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      }
      else
      {
        v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
               (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->BuiltinsMgr.Builtins,
               &v18,
               gfxVal->mValue.pStringW,
               -1i64);
        Scaleform::GFx::AS3::Value::Assign(v3, v9);
        v10 = v18.pNode;
        v7 = v18.pNode->RefCount == 1;
        --v10->RefCount;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      }
      break;
    case 8:
    case 9:
    case 0xA:
      v11 = (Scaleform::GFx::AS3::Instances::Function *)gfxVal->mValue.pString;
      if ( v11 && (v12 = v11->pTraits.pObject, v12->TraitsType == 10) && ~(LOBYTE(v12->Flags) >> 5) & 1 )
        Scaleform::GFx::AS3::Value::Assign(v3, v11);
      else
        Scaleform::GFx::AS3::Value::Assign(v3, (Scaleform::GFx::AS3::Object *)&v11->vfptr);
      break;
    case 0xB:
      v13 = *(_QWORD *)&gfxVal->mValue.NValue >> 1;
      v14 = *(_QWORD *)&gfxVal->mValue.NValue & 0xFFFFFFFFFFFFFFFDui64;
      other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)(*(_QWORD *)&gfxVal->mValue.NValue & 0xFFFFFFFFFFFFFFFDui64);
      other.Bonus.pWeakProxy = 0i64;
      if ( v13 & 1 )
      {
        v15 = gfxVal->DataAux;
        other.Flags = 17;
        other.value.VS._1.VInt = v15;
        if ( v14 )
          *(_DWORD *)(v14 + 32) = (*(_DWORD *)(v14 + 32) + 1) & 0x8FBFFFFF;
        other.Flags = 17;
        Scaleform::GFx::AS3::Value::Assign(v3, &other);
      }
      else
      {
        v16 = gfxVal->DataAux;
        other.Flags = 16;
        *(_QWORD *)&other.value.VNumber = v16;
        if ( v14 )
          *(_DWORD *)(v14 + 32) = (*(_DWORD *)(v14 + 32) + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(v3, &other);
      }
      v17 = other.Flags;
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags >> 9) & 1 )
        {
          v7 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v7 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          other.Flags = v17 & 0xFFFFFDE0;
          other.value = 0ui64;
          other.Bonus.pWeakProxy = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
      break;
    default:
      return;
  }
}

// File Line: 1807
// RVA: 0x7A9350
Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue

// File Line: 1976
// RVA: 0x7BE530
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateObjectInterface(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::MovieImpl *movie)
{
  Scaleform::GFx::MovieImpl *v2; // rbx
  Scaleform::GFx::Value::ObjectInterface *v3; // rax
  Scaleform::List<Scaleform::GFx::Value,Scaleform::GFx::Value> *v4; // rcx

  v2 = movie;
  v3 = (Scaleform::GFx::Value::ObjectInterface *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, signed __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                   this,
                                                   32i64);
  if ( v3 )
  {
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::Value::ObjectInterface::`vftable';
    v3->pMovieRoot = v2;
    v4 = &v3->ExternalObjRefs;
    v4->Root.pPrev = (Scaleform::GFx::Value *)v4;
    v4->Root.pNext = (Scaleform::GFx::Value *)v4;
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::AS3ValueObjectInterface::`vftable';
    v2->pObjectInterface = v3;
  }
  else
  {
    v2->pObjectInterface = 0i64;
  }
}

// File Line: 1983
// RVA: 0x7BF6C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateString(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Value *pvalue, const char *pstring)
{
  Scaleform::GFx::Value *v3; // rdi
  Scaleform::GFx::AS3::MovieRoot *v4; // rbx
  unsigned int v5; // ebx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v3 = pvalue;
  v4 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->BuiltinsMgr.Builtins,
    &result,
    pstring);
  value.Flags = 10;
  value.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&value.value.VNumber = result;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    value.value.VNumber = 0.0;
    value.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)value.Bonus.pWeakProxy;
    value.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v4, &value, v3);
  v5 = value.Flags;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v6 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v6 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags = v5 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  v7 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 1989
// RVA: 0x7BF830
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateStringW(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Value *pvalue, const wchar_t *pstring)
{
  Scaleform::GFx::Value *v3; // rdi
  Scaleform::GFx::AS3::MovieRoot *v4; // rbx
  unsigned int v5; // ebx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v3 = pvalue;
  v4 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->BuiltinsMgr.Builtins,
    &result,
    pstring,
    -1i64);
  value.Flags = 10;
  value.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&value.value.VNumber = result;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    value.value.VNumber = 0.0;
    value.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)value.Bonus.pWeakProxy;
    value.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v4, &value, v3);
  v5 = value.Flags;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v6 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v6 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags = v5 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  v7 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 1996
// RVA: 0x7BE130
Scaleform::GFx::AS3::MovieRoot::CreateObject

// File Line: 2034
// RVA: 0x7BB910
Scaleform::GFx::AS3::MovieRoot::CreateArray

// File Line: 2042
// RVA: 0x7BCD90
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateFunction(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::Value *pvalue, Scaleform::GFx::FunctionHandler *pfc, void *puserData)
{
  void *v4; // rsi
  Scaleform::GFx::FunctionHandler *v5; // rbp
  Scaleform::GFx::Value *v6; // rdi
  Scaleform::GFx::AS3::MovieRoot *v7; // rbx
  Scaleform::GFx::AS3::UserDefinedFunction *v8; // rax
  unsigned __int64 v9; // rax
  unsigned int v10; // ebx
  bool v11; // zf
  Scaleform::GFx::AS3::Value value; // [rsp+28h] [rbp-40h]

  v4 = puserData;
  v5 = pfc;
  v6 = pvalue;
  v7 = this;
  v8 = (Scaleform::GFx::AS3::UserDefinedFunction *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))this->pAVM.pObject->MHeap->vfptr->Alloc)(
                                                     this->pAVM.pObject->MHeap,
                                                     80i64);
  *(_QWORD *)&value.Flags = v8;
  if ( v8 )
    Scaleform::GFx::AS3::UserDefinedFunction::UserDefinedFunction(
      v8,
      v7->pAVM.pObject->TraitsFunction.pObject->ITraits.pObject,
      v5,
      v4);
  else
    v9 = 0i64;
  value.Bonus.pWeakProxy = 0i64;
  value.Flags = 14;
  value.value = (Scaleform::GFx::AS3::Value::VU)v9;
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v7, &value, v6);
  v10 = value.Flags;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v11 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags = v10 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
}

