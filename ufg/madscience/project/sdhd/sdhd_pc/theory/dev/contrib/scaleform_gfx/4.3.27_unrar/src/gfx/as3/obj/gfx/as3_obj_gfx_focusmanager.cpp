// File Line: 41
// RVA: 0x82C100
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysSet(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::Value *result, bool enable)
{
  Scaleform::GFx::AS3::VM *v3; // rax
  void *(__fastcall *v4)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  v3 = this->pTraits.pObject->pVM;
  if ( v3[1].CallStack.gap0[0] )
  {
    v4 = v3[1].vfptr[2].__vecDelDtor;
    *((_DWORD *)v4 + 5300) &= 0xFCFFFFFF;
    *((_DWORD *)v4 + 5300) |= (enable & 3) << 24;
  }
}

// File Line: 52
// RVA: 0x82C0A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysGet(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, bool *result)
{
  Scaleform::GFx::AS3::VM *v2; // rax
  int v3; // er8
  int v4; // eax

  v2 = this->pTraits.pObject->pVM;
  if ( v2[1].CallStack.gap0[0] )
  {
    v3 = *((_BYTE *)v2[1].vfptr[2].__vecDelDtor + 21203) & 3;
    v4 = *((_BYTE *)v2[1].vfptr[2].__vecDelDtor + 21203) & 3;
    if ( v3 == 3 )
      v4 = -1;
    if ( v4 )
    {
      if ( v3 == 3 )
        v3 = -1;
      *result = v3 == 1;
    }
    else
    {
      *result = 0;
    }
  }
}

// File Line: 66
// RVA: 0x834A40
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysSet(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::Value *result, bool disable)
{
  Scaleform::GFx::AS3::VM *v3; // rax
  void *(__fastcall *v4)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  v3 = this->pTraits.pObject->pVM;
  if ( v3[1].CallStack.gap0[0] )
  {
    v4 = v3[1].vfptr[2].__vecDelDtor;
    *((_DWORD *)v4 + 5300) &= 0x3FFFFFFFu;
    *((_DWORD *)v4 + 5300) |= (disable << 30) & 0xC0000000;
  }
}

// File Line: 77
// RVA: 0x8349E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysGet(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, bool *result)
{
  Scaleform::GFx::AS3::VM *v2; // rax
  signed int v3; // er8
  signed int v4; // eax

  v2 = this->pTraits.pObject->pVM;
  if ( v2[1].CallStack.gap0[0] )
  {
    v4 = *((_DWORD *)v2[1].vfptr[2].__vecDelDtor + 5300) >> 30;
    v3 = v4;
    if ( v4 == 3 )
      v4 = -1;
    if ( v4 )
    {
      if ( v3 == 3 )
        v3 = -1;
      *result = v3 == 1;
    }
    else
    {
      *result = 0;
    }
  }
}

// File Line: 91
// RVA: 0x854A20
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::moveFocus(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *result, Scaleform::GFx::ASString *keyToSimulate, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *startFromMovie)
{
  const char ***v4; // r15
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v5; // r13
  Scaleform::GFx::AS3::ASVM *v6; // rsi
  Scaleform::GFx::MovieImpl *v7; // r14
  signed __int64 v8; // rdi
  Scaleform::GFx::InteractiveObject *v9; // rbx
  const char *v10; // r8
  __int64 v11; // rdx
  char v12; // cl
  __int64 v13; // rdx
  char v14; // cl
  __int64 v15; // rdx
  char v16; // cl
  __int64 v17; // rdx
  char v18; // cl
  __int64 v19; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v20; // rdx
  const char *v21; // rdi
  Scaleform::Log *v22; // rax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+8h] [rbp-39h]
  __int64 v24; // [rsp+10h] [rbp-31h]
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry keyEntry; // [rsp+18h] [rbp-29h]
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [rsp+28h] [rbp-19h]
  Scaleform::GFx::InteractiveObject *v27; // [rsp+98h] [rbp+57h]
  _BOOL8 retaddr; // [rsp+B8h] [rbp+77h]
  unsigned int v29; // [rsp+C0h] [rbp+7Fh]

  v24 = -2i64;
  v4 = (const char ***)keyToSimulate;
  v5 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result;
  v6 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  if ( v6->ExtensionsEnabled )
  {
    v7 = v6->pMovieRoot->pMovieImpl;
    v8 = 0i64;
    v27 = 0i64;
    if ( startFromMovie )
    {
      v9 = (Scaleform::GFx::InteractiveObject *)startFromMovie->pDispObj.pObject;
      if ( v9 )
        ++v9->RefCount;
      v27 = v9;
    }
    else
    {
      v9 = Scaleform::GFx::MovieImpl::GetFocusedCharacter(v7, &resulta, v29)->pObject;
      if ( v9 )
        ++v9->RefCount;
      v27 = v9;
      if ( resulta.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
    }
    v10 = **v4;
    if ( *v10 == aU_2[0] && v10[1] == 112 && !v10[2] )
      goto LABEL_30;
    v11 = 0i64;
    while ( 1 )
    {
      v12 = v10[v11++];
      if ( v12 != aDown_0[v11 - 1] )
        break;
      if ( v11 == 5 )
        goto LABEL_30;
    }
    v13 = 0i64;
    while ( 1 )
    {
      v14 = v10[v13++];
      if ( v14 != aLeft_0[v13 - 1] )
        break;
      if ( v13 == 5 )
        goto LABEL_30;
    }
    v15 = 0i64;
    while ( 1 )
    {
      v16 = v10[v15++];
      if ( v16 != aRight_0[v15 - 1] )
        break;
      if ( v15 == 6 )
        goto LABEL_30;
    }
    v17 = 0i64;
    while ( 1 )
    {
      v18 = v10[v17++];
      if ( v18 != aTab_0[v17 - 1] )
        break;
      if ( v17 == 4 )
        goto LABEL_30;
    }
    if ( strcmp(**v4, "shifttab") )
    {
      if ( Scaleform::GFx::AS3::ASVM::GetLog(v6) )
      {
        v21 = **v4;
        v22 = Scaleform::GFx::AS3::ASVM::GetLog(v6);
        Scaleform::Log::LogWarning(v22, "moveFocus - invalid string id for key: '%s'", v21);
      }
    }
    else
    {
LABEL_30:
      _mm_store_si128((__m128i *)&pfocusInfo, (__m128i)0i64);
      pfocusInfo.CurFocusIdx = -1;
      pfocusInfo.Prev_aRect = 0i64;
      *(_QWORD *)&pfocusInfo.PrevKeyCode = 0i64;
      *(_DWORD *)&pfocusInfo.KeyboardIndex = 0;
      pfocusInfo.Initialized = 0;
      Scaleform::GFx::MovieImpl::InitFocusKeyInfo(v7, &pfocusInfo, &keyEntry, retaddr, 0i64);
      if ( v9 )
        ++v9->RefCount;
      if ( pfocusInfo.CurFocused.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&pfocusInfo.CurFocused.pObject->vfptr);
      pfocusInfo.CurFocused.pObject = v9;
      pfocusInfo.ManualFocus = 1;
      Scaleform::GFx::MovieImpl::ProcessFocusKey(v7, F3_720_512, &keyEntry, &pfocusInfo);
      Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(v7, &pfocusInfo);
      if ( pfocusInfo.CurFocused.pObject )
      {
        v19 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pfocusInfo.CurFocused.pObject->vfptr
                                                                          + 4
                                                                          * (unsigned __int8)pfocusInfo.CurFocused.pObject->AvmObjOffset))[1].__vecDelDtor)();
        if ( v19 )
          v8 = v19 - 56;
      }
      v20 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v8 + 16);
      if ( !v20 )
        v20 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v8 + 8);
      if ( (unsigned __int8)v20 & 1 )
        v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v20 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v5, v20);
      if ( pfocusInfo.CurFocused.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&pfocusInfo.CurFocused.pObject->vfptr);
    }
    if ( v9 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
  }
}

// File Line: 149
// RVA: 0x847F80
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::findFocus(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *result, Scaleform::GFx::ASString *keyToSimulate, Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *parentMovie, bool loop, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *startFromMovie, bool includeFocusEnabledChars, unsigned int controllerIdx)
{
  const char ***v8; // rbx
  Scaleform::GFx::AS3::VM *v9; // r15
  Scaleform::GFx::MovieImpl *v10; // rax
  signed __int64 v11; // r14
  unsigned int v12; // er12
  Scaleform::GFx::InteractiveObject *v13; // rdi
  char v14; // si
  const char *v15; // r8
  signed __int16 v16; // r13
  __int64 v17; // rcx
  char v18; // al
  __int64 v19; // rcx
  char v20; // al
  __int64 v21; // rcx
  char v22; // al
  __int64 v23; // rcx
  char v24; // al
  Scaleform::GFx::DisplayObject *v25; // rbx
  Scaleform::GFx::Sprite *v26; // rax
  Scaleform::MemoryHeap *v27; // rax
  Scaleform::GFx::CharacterHandle *v28; // r15
  Scaleform::GFx::CharacterHandle *v29; // r12
  Scaleform::WeakPtrProxy *v30; // r15
  Scaleform::WeakPtrProxy *v31; // rdx
  Scaleform::WeakPtrProxy *v32; // rdx
  __int64 v33; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v34; // rdx
  __int64 v35; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v36; // rdx
  Scaleform::GFx::InteractiveObject *v37; // rcx
  __int64 v38; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v39; // rdx
  float v40; // xmm6_4
  __int64 v41; // r12
  __int64 v42; // rsi
  unsigned __int64 v43; // r13
  int v44; // er14
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v45; // r15
  Scaleform::GFx::InteractiveObject *v46; // rax
  Scaleform::GFx::InteractiveObject *v47; // r15
  Scaleform::Render::Rect<float> *v48; // rax
  float v49; // xmm0_4
  Scaleform::GFx::InteractiveObject *v50; // rcx
  __int64 v51; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v52; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v53; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v54; // rcx
  unsigned int v55; // eax
  Scaleform::GFx::CharacterHandle *v56; // rsi
  Scaleform::WeakPtrProxy *v57; // rdx
  Scaleform::Render::TreeShape *v58; // rcx
  bool v59; // zf
  Scaleform::GFx::MovieImpl *v60; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Rect<float> pr; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry keyEntry; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::Sprite *v63; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::InteractiveObject *v64; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::Sprite *v65; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::FocusGroupDescr pfocusGroup; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [rsp+E0h] [rbp-20h]
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *v68; // [rsp+120h] [rbp+20h]
  __int64 v69; // [rsp+130h] [rbp+30h]
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+140h] [rbp+40h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v72; // [rsp+1C8h] [rbp+C8h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *v73; // [rsp+1D8h] [rbp+D8h]

  v73 = parentMovie;
  v72 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result;
  v69 = -2i64;
  v8 = (const char ***)keyToSimulate;
  v9 = this->pTraits.pObject->pVM;
  if ( v9[1].CallStack.gap0[0] )
  {
    v10 = (Scaleform::GFx::MovieImpl *)v9[1].vfptr[2].__vecDelDtor;
    v60 = (Scaleform::GFx::MovieImpl *)v9[1].vfptr[2].__vecDelDtor;
    v11 = 0i64;
    v64 = 0i64;
    v12 = controllerIdx;
    if ( startFromMovie )
    {
      v13 = (Scaleform::GFx::InteractiveObject *)startFromMovie->pDispObj.pObject;
      if ( v13 )
        ++v13->RefCount;
      v64 = v13;
    }
    else
    {
      v13 = Scaleform::GFx::MovieImpl::GetFocusedCharacter(v10, &resulta, controllerIdx)->pObject;
      if ( v13 )
        ++v13->RefCount;
      v64 = v13;
      if ( resulta.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
    }
    v14 = 0;
    v15 = **v8;
    if ( *v15 == aU_2[0] && v15[1] == 112 && !v15[2] )
    {
      v16 = 38;
      goto LABEL_33;
    }
    v17 = 0i64;
    while ( 1 )
    {
      v18 = v15[v17++];
      if ( v18 != aDown_0[v17 - 1] )
        break;
      if ( v17 == 5 )
      {
        v16 = 40;
        goto LABEL_33;
      }
    }
    v19 = 0i64;
    while ( 1 )
    {
      v20 = v15[v19++];
      if ( v20 != aLeft_0[v19 - 1] )
        break;
      if ( v19 == 5 )
      {
        v16 = 37;
        goto LABEL_33;
      }
    }
    v21 = 0i64;
    while ( 1 )
    {
      v22 = v15[v21++];
      if ( v22 != aRight_0[v21 - 1] )
        break;
      if ( v21 == 6 )
      {
        v16 = 39;
        goto LABEL_33;
      }
    }
    v23 = 0i64;
    while ( 1 )
    {
      v24 = v15[v23++];
      if ( v24 != aTab_0[v23 - 1] )
        break;
      if ( v23 == 4 )
        goto LABEL_32;
    }
    if ( strcmp(**v8, "shifttab") )
      goto LABEL_138;
    v14 = 1;
LABEL_32:
    v16 = 9;
LABEL_33:
    v65 = 0i64;
    if ( v73 )
    {
      v25 = v73->pDispObj.pObject;
      v63 = (Scaleform::GFx::Sprite *)v25;
      if ( v25 )
        ++v25->RefCount;
      v65 = (Scaleform::GFx::Sprite *)v25;
    }
    else
    {
      v26 = Scaleform::GFx::MovieImpl::GetModalClip(v60, v12);
      v25 = (Scaleform::GFx::DisplayObject *)&v26->vfptr;
      v63 = v26;
      if ( v26 )
        ++v26->RefCount;
      v65 = v26;
    }
    _mm_store_si128((__m128i *)&pfocusInfo, (__m128i)0i64);
    pfocusInfo.CurFocusIdx = -1;
    pfocusInfo.Prev_aRect = 0i64;
    *(_QWORD *)&pfocusInfo.PrevKeyCode = 0i64;
    *(_DWORD *)&pfocusInfo.KeyboardIndex = 0;
    pfocusInfo.Initialized = 0;
    keyEntry.KeyboardIndex = v12;
    LODWORD(resulta.pObject) = v16;
    keyEntry.Code = v16;
    keyEntry.KeysState = v14;
    v27 = (Scaleform::MemoryHeap *)*((_QWORD *)v9[1].vfptr[2].__vecDelDtor + 8);
    pfocusGroup.FocusRectNode.pObject = 0i64;
    if ( !v27 )
      v27 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, &pfocusGroup);
    v68 = &pfocusGroup.TabableArray;
    pfocusGroup.TabableArray.Data.Data = 0i64;
    pfocusGroup.TabableArray.Data.Size = 0i64;
    pfocusGroup.TabableArray.Data.Policy.Capacity = 0i64;
    pfocusGroup.TabableArray.Data.pHeap = v27;
    *(_QWORD *)&pr.x1 = (char *)&pfocusGroup + 40;
    pfocusGroup.LastFocused.pProxy.pObject = 0i64;
    pfocusGroup.ModalClip.pObject = 0i64;
    pfocusGroup.LastFocusKeyCode = 0;
    pfocusGroup.LastFocusedRect = 0i64;
    *(_WORD *)&pfocusGroup.FocusRectShown = 0;
    if ( v25 )
    {
      v28 = v25->pNameHandle.pObject;
      if ( v28 || (v28 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v25)) != 0i64 )
        ++v28->RefCount;
    }
    else
    {
      v28 = 0i64;
    }
    v29 = pfocusGroup.ModalClip.pObject;
    if ( pfocusGroup.ModalClip.pObject )
    {
      --pfocusGroup.ModalClip.pObject->RefCount;
      if ( v29->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v29);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v29);
      }
    }
    pfocusGroup.ModalClip.pObject = v28;
    if ( v13 )
    {
      v30 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v13->vfptr);
      v31 = pfocusGroup.LastFocused.pProxy.pObject;
      if ( pfocusGroup.LastFocused.pProxy.pObject )
      {
        --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
        if ( !v31->RefCount )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
      pfocusGroup.LastFocused.pProxy.pObject = v30;
    }
    else
    {
      v32 = pfocusGroup.LastFocused.pProxy.pObject;
      if ( pfocusGroup.LastFocused.pProxy.pObject )
      {
        --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
        if ( !v32->RefCount )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
      pfocusGroup.LastFocused.pProxy.pObject = 0i64;
    }
    Scaleform::GFx::MovieImpl::InitFocusKeyInfo(v60, &pfocusInfo, &keyEntry, includeFocusEnabledChars, &pfocusGroup);
    pfocusInfo.ManualFocus = 1;
    Scaleform::GFx::MovieImpl::ProcessFocusKey(v60, F3_720_512, &keyEntry, &pfocusInfo);
    if ( pfocusInfo.CurFocused.pObject && pfocusInfo.CurFocused.pObject != v13 )
    {
      v33 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pfocusInfo.CurFocused.pObject->vfptr
                                                                        + 4
                                                                        * (unsigned __int8)pfocusInfo.CurFocused.pObject->AvmObjOffset))[1].__vecDelDtor)();
      if ( v33 )
        v11 = v33 - 56;
      v34 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 16);
      if ( !v34 )
        v34 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 8);
      if ( (unsigned __int8)v34 & 1 )
        v34 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v34 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v72, v34);
LABEL_125:
      v56 = pfocusGroup.ModalClip.pObject;
      if ( pfocusGroup.ModalClip.pObject )
      {
        --pfocusGroup.ModalClip.pObject->RefCount;
        if ( v56->RefCount <= 0 )
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle(v56);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v56);
        }
      }
      resulta.pObject = (Scaleform::GFx::InteractiveObject *)&pfocusGroup.LastFocused;
      v57 = pfocusGroup.LastFocused.pProxy.pObject;
      if ( pfocusGroup.LastFocused.pProxy.pObject )
      {
        --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
        if ( !v57->RefCount )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
      resulta.pObject = (Scaleform::GFx::InteractiveObject *)&pfocusGroup.TabableArray;
      Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&pfocusGroup.TabableArray);
      v58 = pfocusGroup.FocusRectNode.pObject;
      if ( pfocusGroup.FocusRectNode.pObject )
      {
        v59 = pfocusGroup.FocusRectNode.pObject->RefCount-- == 1;
        if ( v59 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v58->0);
      }
      if ( pfocusInfo.CurFocused.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&pfocusInfo.CurFocused.pObject->vfptr);
      if ( v25 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v25->vfptr);
LABEL_138:
      if ( v13 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
      return;
    }
    if ( !loop || !pfocusGroup.TabableArray.Data.Size )
    {
      v53 = v72;
      v54 = v72->pObject;
      if ( v72->pObject )
      {
        if ( (unsigned __int8)v54 & 1 )
        {
          v72->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v54 - 1);
        }
        else
        {
          v55 = v54->RefCount;
          if ( v55 & 0x3FFFFF )
          {
            v54->RefCount = v55 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v54->vfptr);
          }
        }
        v53->pObject = 0i64;
      }
      goto LABEL_125;
    }
    if ( v16 == 9 )
    {
      if ( v14 & 1 )
      {
        v37 = pfocusGroup.TabableArray.Data.Data[pfocusGroup.TabableArray.Data.Size - 1].pObject;
        if ( v37 )
        {
          v38 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v37->vfptr
                                                                            + 4 * (unsigned __int8)v37->AvmObjOffset))[1].__vecDelDtor)();
          if ( v38 )
            v11 = v38 - 56;
        }
        v39 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 16);
        if ( !v39 )
          v39 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 8);
        if ( (unsigned __int8)v39 & 1 )
          v39 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v39 - 1);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v72, v39);
      }
      else
      {
        if ( pfocusGroup.TabableArray.Data.Data->pObject )
        {
          v35 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pfocusGroup.TabableArray.Data.Data->pObject->vfptr
                                                                            + 4
                                                                            * (unsigned __int8)pfocusGroup.TabableArray.Data.Data->pObject->AvmObjOffset))[1].__vecDelDtor)();
          if ( v35 )
            v11 = v35 - 56;
        }
        v36 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 16);
        if ( !v36 )
          v36 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 8);
        if ( (unsigned __int8)v36 & 1 )
          v36 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v36 - 1);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v72, v36);
      }
      goto LABEL_125;
    }
    v40 = FLOAT_1_1754944eN38;
    v41 = 0i64;
    v42 = 0i64;
    if ( !pfocusGroup.TabableArray.Data.Size )
    {
LABEL_111:
      v50 = pfocusGroup.TabableArray.Data.Data[v41].pObject;
      if ( v50 )
      {
        v51 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v50->vfptr
                                                                          + 4 * (unsigned __int8)v50->AvmObjOffset))[1].__vecDelDtor)();
        if ( v51 )
          v11 = v51 - 56;
      }
      v52 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 16);
      if ( !v52 )
        v52 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 8);
      if ( (unsigned __int8)v52 & 1 )
        v52 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v52 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v72, v52);
      goto LABEL_125;
    }
    v43 = pfocusGroup.TabableArray.Data.Size;
    v44 = (int)resulta.pObject;
    while ( 1 )
    {
      v45 = pfocusGroup.TabableArray.Data.Data;
      v46 = pfocusGroup.TabableArray.Data.Data[v42].pObject;
      if ( v46 )
        ++v46->RefCount;
      v47 = v45[v42].pObject;
      resulta.pObject = v47;
      if ( !pfocusInfo.InclFocusEnabled
        && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v47->vfptr[87].__vecDelDtor)(v47)
        || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::MovieImpl *, _QWORD))v47->vfptr[85].__vecDelDtor)(
              v47,
              v60,
              (unsigned __int8)pfocusInfo.KeyboardIndex) )
      {
        goto LABEL_109;
      }
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix((Scaleform::GFx::DisplayObjectBase *)&v47->vfptr, &pmat);
      v48 = (Scaleform::Render::Rect<float> *)v47->vfptr[93].__vecDelDtor(
                                                (Scaleform::RefCountNTSImplCore *)&v47->vfptr,
                                                (unsigned int)&v68);
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pmat, &pr, v48);
      if ( v44 == 37 )
        break;
      switch ( v44 )
      {
        case 38:
          v49 = pr.y2;
LABEL_106:
          if ( v40 != 1.1754944e-38 && v49 <= v40 )
            break;
          goto LABEL_108;
        case 39:
          v49 = pr.x1;
LABEL_100:
          if ( v40 != 1.1754944e-38 && v49 >= v40 )
            break;
LABEL_108:
          v41 = v42;
          v40 = v49;
          break;
        case 40:
          v49 = pr.y1;
          goto LABEL_100;
      }
LABEL_109:
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v47->vfptr);
      if ( ++v42 >= v43 )
      {
        v25 = (Scaleform::GFx::DisplayObject *)&v63->vfptr;
        v11 = 0i64;
        goto LABEL_111;
      }
    }
    v49 = pr.x2;
    goto LABEL_106;
  }
}

// File Line: 300
// RVA: 0x85B2A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocus(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj, unsigned int controllerIdx)
{
  unsigned int v4; // edi
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::InteractiveObject *v6; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::InteractiveObject *v8; // [rsp+50h] [rbp+18h]

  v4 = controllerIdx;
  v5 = this->pTraits.pObject->pVM;
  v6 = 0i64;
  v8 = 0i64;
  if ( obj )
  {
    v6 = (Scaleform::GFx::InteractiveObject *)obj->pDispObj.pObject;
    if ( v6 )
      ++v6->RefCount;
    v8 = v6;
  }
  Scaleform::GFx::MovieImpl::GetFocusedCharacter(
    (Scaleform::GFx::MovieImpl *)v5[1].vfptr[2].__vecDelDtor,
    &resulta,
    controllerIdx);
  if ( resulta.pObject != v6 )
    Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
      (Scaleform::GFx::MovieImpl *)v5[1].vfptr[2].__vecDelDtor,
      v6,
      v4,
      GFx_FocusMovedByAS);
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v6->vfptr);
}

// File Line: 315
// RVA: 0x84B700
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocus(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *result, unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rbx
  char *v4; // rcx
  __int64 v5; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rdx
  signed int v7; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v8; // rcx
  unsigned int v9; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+40h] [rbp+8h]

  v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result;
  Scaleform::GFx::MovieImpl::GetFocusedCharacter(
    (Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor,
    &resulta,
    controllerIdx);
  if ( !resulta.pObject )
    goto LABEL_22;
  v4 = (char *)resulta.pObject + 4 * (unsigned __int8)resulta.pObject->AvmObjOffset;
  v5 = (*(__int64 (__cdecl **)(char *))(*(_QWORD *)v4 + 8i64))(v4);
  if ( v5 )
    v5 -= 56i64;
  v6 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v5 + 16);
  if ( !v6 )
    v6 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v5 + 8);
  if ( (unsigned __int8)v6 & 1 )
    v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v6 - 1);
  if ( v6 && ((v7 = v6->pTraits.pObject->TraitsType, v7 == 23) || v7 >= 29) )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v3, v6);
  }
  else
  {
LABEL_22:
    v8.pObject = v3->pObject;
    if ( v3->pObject )
    {
      if ( (_QWORD)v8.pObject & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v8.pObject - 1);
      }
      else
      {
        v9 = v8.pObject->RefCount;
        if ( v9 & 0x3FFFFF )
        {
          v8.pObject->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8.pObject->vfptr);
        }
      }
      v3->pObject = 0i64;
    }
  }
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
}

// File Line: 335
// RVA: 0x8556A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::numFocusGroupsGet(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, unsigned int *result)
{
  *result = *((_DWORD *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 5288);
}

// File Line: 345
// RVA: 0x85B350
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocusGroupMask(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj, unsigned int mask)
{
  if ( this->pTraits.pObject->pVM[1].CallStack.gap0[0] )
  {
    if ( obj )
      obj->pDispObj.pObject->vfptr[106].__vecDelDtor((Scaleform::RefCountNTSImplCore *)obj->pDispObj.pObject, mask);
  }
}

// File Line: 359
// RVA: 0x84B7D0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocusGroupMask(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, unsigned int *result, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj)
{
  if ( this->pTraits.pObject->pVM[1].CallStack.gap0[0] )
    *result = Scaleform::GFx::InteractiveObject::GetFocusGroupMask((Scaleform::GFx::InteractiveObject *)obj->pDispObj.pObject);
}

// File Line: 371
// RVA: 0x85B070
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setControllerFocusGroup(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, bool *result, unsigned int controllerIdx, unsigned int focusGroupIdx)
{
  Scaleform::GFx::AS3::VM *v4; // rax

  v4 = this->pTraits.pObject->pVM;
  if ( v4[1].CallStack.gap0[0] )
    *result = (*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), _QWORD, _QWORD))(*(_QWORD *)v4[1].vfptr[2].__vecDelDtor + 448i64))(
                v4[1].vfptr[2].__vecDelDtor,
                controllerIdx,
                focusGroupIdx);
  else
    *result = 0;
}

// File Line: 386
// RVA: 0x84B0E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerFocusGroup(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, unsigned int *result, unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *v3; // rax

  v3 = this->pTraits.pObject->pVM;
  if ( v3[1].CallStack.gap0[0] )
    *result = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)v3[1].vfptr[2].__vecDelDtor + 456i64))(
                v3[1].vfptr[2].__vecDelDtor,
                controllerIdx);
  else
    *result = 0;
}

// File Line: 401
// RVA: 0x84B130
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerMaskByFocusGroup(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, unsigned int *result, unsigned int focusGroupIdx)
{
  Scaleform::GFx::AS3::VM *v3; // rax

  v3 = this->pTraits.pObject->pVM;
  if ( v3[1].CallStack.gap0[0] )
    *result = Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(
                (Scaleform::GFx::MovieImpl *)v3[1].vfptr[2].__vecDelDtor,
                focusGroupIdx);
  else
    *result = 0;
}

// File Line: 417
// RVA: 0x84B9E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getModalClip(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Sprite> *result, unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Sprite> *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rax
  Scaleform::GFx::Sprite *v5; // rax
  __int64 v6; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v7; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v8; // rcx
  unsigned int v9; // eax

  v3 = result;
  v4 = this->pTraits.pObject->pVM;
  if ( v4[1].CallStack.gap0[0] )
  {
    v5 = Scaleform::GFx::MovieImpl::GetModalClip(
           (Scaleform::GFx::MovieImpl *)v4[1].vfptr[2].__vecDelDtor,
           controllerIdx);
    if ( v5 )
    {
      v6 = (unsigned __int8)v5->AvmObjOffset;
      v7 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)((char *)&v5->pWeakProxy + 4 * v6);
      if ( !v7 )
        v7 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(&v5->RefCount + v6);
      if ( (unsigned __int8)v7 & 1 )
        v7 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v7 - 1);
      if ( v7 && (unsigned int)(v7->pTraits.pObject->TraitsType - 30) <= 1 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v3,
          v7);
      }
      else
      {
        v8.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->pObject;
        if ( v3->pObject )
        {
          if ( (_QWORD)v8.pObject & 1 )
          {
            v3->pObject = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)((char *)&v8.pObject[-1].List.Data.Policy.Capacity
                                                                               + 7);
            v3->pObject = 0i64;
          }
          else
          {
            v9 = v8.pObject->RefCount;
            if ( v9 & 0x3FFFFF )
            {
              v8.pObject->RefCount = v9 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8.pObject->vfptr);
            }
            v3->pObject = 0i64;
          }
        }
      }
    }
  }
}

// File Line: 439
// RVA: 0x85B950
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setModalClip(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_display::Sprite *mc, unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *v4; // rax
  Scaleform::GFx::MovieImpl *v5; // rcx

  v4 = this->pTraits.pObject->pVM;
  if ( v4[1].CallStack.gap0[0] )
  {
    v5 = (Scaleform::GFx::MovieImpl *)v4[1].vfptr[2].__vecDelDtor;
    if ( mc )
      Scaleform::GFx::MovieImpl::SetModalClip(v5, (Scaleform::GFx::Sprite *)mc->pDispObj.pObject, controllerIdx);
    else
      Scaleform::GFx::MovieImpl::SetModalClip(v5, 0i64, controllerIdx);
  }
}

// File Line: 479
// RVA: 0x1590910
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_0_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E8D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,0,Scaleform::GFx::AS3::Value const,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysSet;
  return result;
}

// File Line: 480
// RVA: 0x1589E90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_1_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E8E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,1,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysGet;
  return result;
}

// File Line: 481
// RVA: 0x1590880
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_2_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E8F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,2,Scaleform::GFx::AS3::Value const,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysSet;
  return result;
}

// File Line: 482
// RVA: 0x1589EC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_3_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E900 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,3,bool>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysGet;
  return result;
}

// File Line: 483
// RVA: 0x1596820
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc4_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_4_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_bool_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E910 = v1;
  Scaleform::GFx::AS3::ThunkFunc4<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,bool,unsigned long>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, bool, unsigned int))Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::moveFocus;
  return result;
}

// File Line: 484
// RVA: 0x1596B80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc6_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer_____ptr64_bool_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_bool_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E920 = v1;
  Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *,bool,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,bool,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::findFocus;
  return result;
}

// File Line: 485
// RVA: 0x1595050
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_6_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E930 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocus;
  return result;
}

// File Line: 486
// RVA: 0x15908B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_7_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject__unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E940 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,7,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocus;
  return result;
}

// File Line: 487
// RVA: 0x1589EF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_8_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E950 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,8,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::numFocusGroupsGet;
  return result;
}

// File Line: 488
// RVA: 0x1595080
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_9_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E960 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,9,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocusGroupMask;
  return result;
}

// File Line: 489
// RVA: 0x15908E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_10_unsigned_long_Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E970 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,10,unsigned long,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocusGroupMask;
  return result;
}

// File Line: 490
// RVA: 0x15950B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_11_bool_unsigned_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E980 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,11,bool,unsigned long,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setControllerFocusGroup;
  return result;
}

// File Line: 491
// RVA: 0x1590940
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_12_unsigned_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E990 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,12,unsigned long,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerFocusGroup;
  return result;
}

// File Line: 492
// RVA: 0x1590970
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_13_unsigned_long_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E9A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,13,unsigned long,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerMaskByFocusGroup;
  return result;
}

// File Line: 493
// RVA: 0x15909A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_14_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::Sprite__unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E9B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Sprite>,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getModalClip;
  return result;
}

// File Line: 494
// RVA: 0x15950E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager_15_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_display::Sprite_____ptr64_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E9C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,15,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::Sprite *,unsigned long>::Method = Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setModalClip;
  return result;
}

// File Line: 547
// RVA: 0x767090
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::FocusManager::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::FocusManagerCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::FocusManager::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::FocusManagerCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::`vftable';
  }
  return v3;
}

