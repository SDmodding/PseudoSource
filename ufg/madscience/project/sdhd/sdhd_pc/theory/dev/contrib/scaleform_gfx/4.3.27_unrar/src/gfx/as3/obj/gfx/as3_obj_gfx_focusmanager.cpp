// File Line: 41
// RVA: 0x82C100
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::Value *result,
        bool enable)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    vecDelDtor = pVM[1].vfptr[2].__vecDelDtor;
    *((_DWORD *)vecDelDtor + 5300) &= 0xFCFFFFFF;
    *((_DWORD *)vecDelDtor + 5300) |= (enable & 3) << 24;
  }
}

// File Line: 52
// RVA: 0x82C0A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        bool *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  int v3; // r8d
  int v4; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    v3 = *((_BYTE *)pVM[1].vfptr[2].__vecDelDtor + 21203) & 3;
    v4 = v3;
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
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysSet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::Value *result,
        bool disable)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    vecDelDtor = pVM[1].vfptr[2].__vecDelDtor;
    *((_DWORD *)vecDelDtor + 5300) &= 0x3FFFFFFFu;
    *((_DWORD *)vecDelDtor + 5300) |= disable << 30;
  }
}

// File Line: 77
// RVA: 0x8349E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::disableFocusKeysGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        bool *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  int v3; // r8d
  int v4; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    v4 = *((_DWORD *)pVM[1].vfptr[2].__vecDelDtor + 5300) >> 30;
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
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::moveFocus(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::ASString *keyToSimulate,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *startFromMovie)
{
  Scaleform::GFx::AS3::ASVM *pVM; // rsi
  Scaleform::GFx::MovieImpl *pMovieImpl; // r14
  __int64 v8; // rdi
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  const char *pData; // r8
  __int64 v11; // rdx
  char v12; // cl
  __int64 v13; // rdx
  char v14; // cl
  __int64 v15; // rdx
  char v16; // cl
  __int64 v17; // rdx
  char v18; // cl
  char *v19; // rcx
  __int64 v20; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v21; // rdx
  const char *v22; // rdi
  Scaleform::Log *Log; // rax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+8h] [rbp-39h] BYREF
  __int64 v25; // [rsp+10h] [rbp-31h]
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry keyEntry; // [rsp+18h] [rbp-29h] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [rsp+28h] [rbp-19h] BYREF
  Scaleform::GFx::InteractiveObject *v28; // [rsp+98h] [rbp+57h]
  _BOOL8 retaddr; // [rsp+B8h] [rbp+77h]
  unsigned int v30; // [rsp+C0h] [rbp+7Fh]

  v25 = -2i64;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  if ( pVM->ExtensionsEnabled )
  {
    pMovieImpl = pVM->pMovieRoot->pMovieImpl;
    v8 = 0i64;
    v28 = 0i64;
    if ( startFromMovie )
    {
      pObject = (Scaleform::GFx::InteractiveObject *)startFromMovie->pDispObj.pObject;
      if ( pObject )
        ++pObject->RefCount;
      v28 = pObject;
    }
    else
    {
      pObject = Scaleform::GFx::MovieImpl::GetFocusedCharacter(pMovieImpl, &resulta, v30)->pObject;
      if ( pObject )
        ++pObject->RefCount;
      v28 = pObject;
      if ( resulta.pObject )
        Scaleform::RefCountNTSImpl::Release(resulta.pObject);
    }
    pData = keyToSimulate->pNode->pData;
    if ( *pData == aU_2[0] && pData[1] == 112 && !pData[2] )
      goto LABEL_30;
    v11 = 0i64;
    while ( 1 )
    {
      v12 = pData[v11++];
      if ( v12 != aDown_0[v11 - 1] )
        break;
      if ( v11 == 5 )
        goto LABEL_30;
    }
    v13 = 0i64;
    while ( 1 )
    {
      v14 = pData[v13++];
      if ( v14 != aLeft_0[v13 - 1] )
        break;
      if ( v13 == 5 )
        goto LABEL_30;
    }
    v15 = 0i64;
    while ( 1 )
    {
      v16 = pData[v15++];
      if ( v16 != aRight_0[v15 - 1] )
        break;
      if ( v15 == 6 )
        goto LABEL_30;
    }
    v17 = 0i64;
    while ( 1 )
    {
      v18 = pData[v17++];
      if ( v18 != aTab_0[v17 - 1] )
        break;
      if ( v17 == 4 )
        goto LABEL_30;
    }
    if ( !strcmp(keyToSimulate->pNode->pData, "shifttab") )
    {
LABEL_30:
      *(_OWORD *)&pfocusInfo.pFocusGroup = 0i64;
      pfocusInfo.CurFocusIdx = -1;
      memset(&pfocusInfo.Prev_aRect, 0, 29);
      Scaleform::GFx::MovieImpl::InitFocusKeyInfo(pMovieImpl, &pfocusInfo, &keyEntry, retaddr, 0i64);
      if ( pObject )
        ++pObject->RefCount;
      if ( pfocusInfo.CurFocused.pObject )
        Scaleform::RefCountNTSImpl::Release(pfocusInfo.CurFocused.pObject);
      pfocusInfo.CurFocused.pObject = pObject;
      pfocusInfo.ManualFocus = 1;
      Scaleform::GFx::MovieImpl::ProcessFocusKey(pMovieImpl, F3_720_512, &keyEntry, &pfocusInfo);
      Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(pMovieImpl, &pfocusInfo);
      if ( pfocusInfo.CurFocused.pObject )
      {
        v19 = (char *)pfocusInfo.CurFocused.pObject + 4 * (unsigned __int8)pfocusInfo.CurFocused.pObject->AvmObjOffset;
        v20 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v19 + 8i64))(v19);
        if ( v20 )
          v8 = v20 - 56;
      }
      v21 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v8 + 16);
      if ( !v21 )
        v21 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v8 + 8);
      if ( ((unsigned __int8)v21 & 1) != 0 )
        v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v21 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, v21);
      if ( pfocusInfo.CurFocused.pObject )
        Scaleform::RefCountNTSImpl::Release(pfocusInfo.CurFocused.pObject);
    }
    else if ( Scaleform::GFx::AS3::ASVM::GetLog(pVM) )
    {
      v22 = keyToSimulate->pNode->pData;
      Log = Scaleform::GFx::AS3::ASVM::GetLog(pVM);
      Scaleform::Log::LogWarning(Log, "moveFocus - invalid string id for key: %s", v22);
    }
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
}

// File Line: 149
// RVA: 0x847F80
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::findFocus(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::ASString *keyToSimulate,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *parentMovie,
        bool loop,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *startFromMovie,
        bool includeFocusEnabledChars,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // r15
  Scaleform::GFx::MovieImpl *vecDelDtor; // rax
  __int64 v11; // r14
  unsigned int v12; // r12d
  Scaleform::GFx::InteractiveObject *pObject; // rdi
  char v14; // si
  const char *pData; // r8
  __int16 v16; // r13
  __int64 v17; // rcx
  char v18; // al
  __int64 v19; // rcx
  char v20; // al
  __int64 v21; // rcx
  char v22; // al
  __int64 v23; // rcx
  char v24; // al
  Scaleform::GFx::DisplayObject *v25; // rbx
  Scaleform::GFx::Sprite *ModalClip; // rax
  Scaleform::MemoryHeap *v27; // rax
  Scaleform::GFx::CharacterHandle *CharacterHandle; // r15
  Scaleform::GFx::CharacterHandle *v29; // r12
  Scaleform::WeakPtrProxy *WeakProxy; // r15
  Scaleform::WeakPtrProxy *v31; // rdx
  Scaleform::WeakPtrProxy *v32; // rdx
  char *v33; // rcx
  __int64 v34; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v35; // rdx
  char *v36; // rcx
  __int64 v37; // rax
  Scaleform::GFx::InteractiveObject *v38; // rcx
  char *v39; // rcx
  __int64 v40; // rax
  float v41; // xmm6_4
  __int64 v42; // r12
  __int64 v43; // rsi
  unsigned __int64 Size; // r13
  int v45; // r14d
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *Data; // r15
  Scaleform::GFx::InteractiveObject *v47; // rax
  Scaleform::GFx::InteractiveObject *v48; // r15
  Scaleform::Render::Rect<float> *v49; // rax
  float y2; // xmm0_4
  __int64 v51; // r14
  Scaleform::GFx::InteractiveObject *v52; // rcx
  char *v53; // rcx
  __int64 v54; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v55; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v56; // rsi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v57; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::CharacterHandle *v59; // rsi
  Scaleform::WeakPtrProxy *v60; // rdx
  Scaleform::Render::TreeShape *v61; // rcx
  Scaleform::GFx::MovieImpl *v63; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Rect<float> pr; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry keyEntry; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::Sprite *v66; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::InteractiveObject *v67; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::Sprite *v68; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::FocusGroupDescr pfocusGroup; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v71[4]; // [rsp+120h] [rbp+20h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+140h] [rbp+40h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+1C0h] [rbp+C0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v74; // [rsp+1C8h] [rbp+C8h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *v75; // [rsp+1D8h] [rbp+D8h]

  v75 = parentMovie;
  v74 = result;
  v71[2] = -2i64;
  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    vecDelDtor = (Scaleform::GFx::MovieImpl *)pVM[1].vfptr[2].__vecDelDtor;
    v63 = vecDelDtor;
    v11 = 0i64;
    v67 = 0i64;
    v12 = controllerIdx;
    if ( startFromMovie )
    {
      pObject = (Scaleform::GFx::InteractiveObject *)startFromMovie->pDispObj.pObject;
      if ( pObject )
        ++pObject->RefCount;
      v67 = pObject;
    }
    else
    {
      pObject = Scaleform::GFx::MovieImpl::GetFocusedCharacter(vecDelDtor, &resulta, controllerIdx)->pObject;
      if ( pObject )
        ++pObject->RefCount;
      v67 = pObject;
      if ( resulta.pObject )
        Scaleform::RefCountNTSImpl::Release(resulta.pObject);
    }
    v14 = 0;
    pData = keyToSimulate->pNode->pData;
    if ( *pData == aU_2[0] && pData[1] == 112 && !pData[2] )
    {
      v16 = 38;
      goto LABEL_33;
    }
    v17 = 0i64;
    while ( 1 )
    {
      v18 = pData[v17++];
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
      v20 = pData[v19++];
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
      v22 = pData[v21++];
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
      v24 = pData[v23++];
      if ( v24 != aTab_0[v23 - 1] )
        break;
      if ( v23 == 4 )
        goto LABEL_32;
    }
    if ( !strcmp(keyToSimulate->pNode->pData, "shifttab") )
    {
      v14 = 1;
LABEL_32:
      v16 = 9;
LABEL_33:
      v68 = 0i64;
      if ( v75 )
      {
        v25 = v75->pDispObj.pObject;
        v66 = (Scaleform::GFx::Sprite *)v25;
        if ( v25 )
          ++v25->RefCount;
        v68 = (Scaleform::GFx::Sprite *)v25;
      }
      else
      {
        ModalClip = Scaleform::GFx::MovieImpl::GetModalClip(v63, v12);
        v25 = ModalClip;
        v66 = ModalClip;
        if ( ModalClip )
          ++ModalClip->RefCount;
        v68 = ModalClip;
      }
      *(_OWORD *)&pfocusInfo.pFocusGroup = 0i64;
      pfocusInfo.CurFocusIdx = -1;
      memset(&pfocusInfo.Prev_aRect, 0, 29);
      keyEntry.KeyboardIndex = v12;
      LODWORD(resulta.pObject) = v16;
      keyEntry.Code = v16;
      keyEntry.KeysState = v14;
      v27 = (Scaleform::MemoryHeap *)*((_QWORD *)pVM[1].vfptr[2].__vecDelDtor + 8);
      pfocusGroup.FocusRectNode.pObject = 0i64;
      if ( !v27 )
        v27 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, &pfocusGroup);
      v71[0] = (__int64)&pfocusGroup.TabableArray;
      memset(&pfocusGroup.TabableArray, 0, 24);
      pfocusGroup.TabableArray.Data.pHeap = v27;
      *(_QWORD *)&pr.x1 = &pfocusGroup.LastFocused;
      memset(&pfocusGroup.LastFocused, 0, 20);
      memset(&pfocusGroup.LastFocusedRect, 0, 18);
      if ( v25 )
      {
        CharacterHandle = v25->pNameHandle.pObject;
        if ( CharacterHandle || (CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v25)) != 0i64 )
          ++CharacterHandle->RefCount;
      }
      else
      {
        CharacterHandle = 0i64;
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
      pfocusGroup.ModalClip.pObject = CharacterHandle;
      if ( pObject )
      {
        WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pObject);
        v31 = pfocusGroup.LastFocused.pProxy.pObject;
        if ( pfocusGroup.LastFocused.pProxy.pObject )
        {
          --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
          if ( !v31->RefCount )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        pfocusGroup.LastFocused.pProxy.pObject = WeakProxy;
      }
      else
      {
        v32 = pfocusGroup.LastFocused.pProxy.pObject;
        if ( pfocusGroup.LastFocused.pProxy.pObject )
        {
          --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
          if ( !v32->RefCount )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        pfocusGroup.LastFocused.pProxy.pObject = 0i64;
      }
      Scaleform::GFx::MovieImpl::InitFocusKeyInfo(v63, &pfocusInfo, &keyEntry, includeFocusEnabledChars, &pfocusGroup);
      pfocusInfo.ManualFocus = 1;
      Scaleform::GFx::MovieImpl::ProcessFocusKey(v63, F3_720_512, &keyEntry, &pfocusInfo);
      if ( pfocusInfo.CurFocused.pObject && pfocusInfo.CurFocused.pObject != pObject )
      {
        v33 = (char *)pfocusInfo.CurFocused.pObject + 4 * (unsigned __int8)pfocusInfo.CurFocused.pObject->AvmObjOffset;
        v34 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v33 + 8i64))(v33);
        if ( v34 )
          v11 = v34 - 56;
        v35 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 16);
        if ( !v35 )
          v35 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 8);
        if ( ((unsigned __int8)v35 & 1) != 0 )
          v35 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v35 - 1);
LABEL_87:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v74, v35);
        goto LABEL_123;
      }
      if ( loop && pfocusGroup.TabableArray.Data.Size )
      {
        if ( v16 == 9 )
        {
          if ( (v14 & 1) != 0 )
          {
            v38 = pfocusGroup.TabableArray.Data.Data[pfocusGroup.TabableArray.Data.Size - 1].pObject;
            if ( v38 )
            {
              v39 = (char *)v38 + 4 * (unsigned __int8)v38->AvmObjOffset;
              v40 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v39 + 8i64))(v39);
              if ( v40 )
                v11 = v40 - 56;
            }
            v35 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 16);
            if ( !v35 )
              v35 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 8);
            if ( ((unsigned __int8)v35 & 1) != 0 )
              v35 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v35 - 1);
          }
          else
          {
            if ( pfocusGroup.TabableArray.Data.Data->pObject )
            {
              v36 = (char *)pfocusGroup.TabableArray.Data.Data->pObject
                  + 4 * (unsigned __int8)pfocusGroup.TabableArray.Data.Data->pObject->AvmObjOffset;
              v37 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v36 + 8i64))(v36);
              if ( v37 )
                v11 = v37 - 56;
            }
            v35 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 16);
            if ( !v35 )
              v35 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v11 + 8);
            if ( ((unsigned __int8)v35 & 1) != 0 )
              v35 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v35 - 1);
          }
          goto LABEL_87;
        }
        v41 = FLOAT_1_1754944eN38;
        v42 = 0i64;
        v43 = 0i64;
        Size = pfocusGroup.TabableArray.Data.Size;
        v45 = (int)resulta.pObject;
        while ( 1 )
        {
          Data = pfocusGroup.TabableArray.Data.Data;
          v47 = pfocusGroup.TabableArray.Data.Data[v43].pObject;
          if ( v47 )
            ++v47->RefCount;
          v48 = Data[v43].pObject;
          resulta.pObject = v48;
          if ( !pfocusInfo.InclFocusEnabled
            && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v48->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[87].__vecDelDtor)(v48)
            || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::MovieImpl *, _QWORD))v48->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[85].__vecDelDtor)(
                  v48,
                  v63,
                  (unsigned __int8)pfocusInfo.KeyboardIndex) )
          {
            goto LABEL_108;
          }
          *(_OWORD *)&pmat.M[0][0] = _xmm;
          *(__m128 *)&pmat.M[1][0] = _xmm;
          Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v48, &pmat);
          v49 = (Scaleform::Render::Rect<float> *)v48->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[93].__vecDelDtor(
                                                    v48,
                                                    (unsigned int)v71);
          Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pmat, &pr, v49);
          if ( v45 == 37 )
            break;
          switch ( v45 )
          {
            case &:
              y2 = pr.y2;
LABEL_105:
              if ( v41 != 1.1754944e-38 && y2 <= v41 )
                break;
              goto LABEL_107;
            case \:
              y2 = pr.x1;
LABEL_99:
              if ( v41 != 1.1754944e-38 && y2 >= v41 )
                break;
LABEL_107:
              v42 = v43;
              v41 = y2;
              break;
            case (:
              y2 = pr.y1;
              goto LABEL_99;
          }
LABEL_108:
          Scaleform::RefCountNTSImpl::Release(v48);
          if ( ++v43 >= Size )
          {
            v25 = v66;
            v51 = 0i64;
            v52 = pfocusGroup.TabableArray.Data.Data[v42].pObject;
            if ( v52 )
            {
              v53 = (char *)v52 + 4 * (unsigned __int8)v52->AvmObjOffset;
              v54 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v53 + 8i64))(v53);
              if ( v54 )
                v51 = v54 - 56;
            }
            v55 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v51 + 16);
            if ( !v55 )
              v55 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v51 + 8);
            if ( ((unsigned __int8)v55 & 1) != 0 )
              v55 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v55 - 1);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(v74, v55);
            goto LABEL_123;
          }
        }
        y2 = pr.x2;
        goto LABEL_105;
      }
      v56 = v74;
      v57 = v74->pObject;
      if ( v74->pObject )
      {
        if ( ((unsigned __int8)v57 & 1) != 0 )
        {
          v74->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v57 - 1);
        }
        else
        {
          RefCount = v57->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v57->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v57);
          }
        }
        v56->pObject = 0i64;
      }
LABEL_123:
      v59 = pfocusGroup.ModalClip.pObject;
      if ( pfocusGroup.ModalClip.pObject )
      {
        --pfocusGroup.ModalClip.pObject->RefCount;
        if ( v59->RefCount <= 0 )
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle(v59);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v59);
        }
      }
      resulta.pObject = (Scaleform::GFx::InteractiveObject *)&pfocusGroup.LastFocused;
      v60 = pfocusGroup.LastFocused.pProxy.pObject;
      if ( pfocusGroup.LastFocused.pProxy.pObject )
      {
        --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
        if ( !v60->RefCount )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      resulta.pObject = (Scaleform::GFx::InteractiveObject *)&pfocusGroup.TabableArray;
      Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&pfocusGroup.TabableArray);
      v61 = pfocusGroup.FocusRectNode.pObject;
      if ( pfocusGroup.FocusRectNode.pObject )
      {
        if ( pfocusGroup.FocusRectNode.pObject->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v61);
      }
      if ( pfocusInfo.CurFocused.pObject )
        Scaleform::RefCountNTSImpl::Release(pfocusInfo.CurFocused.pObject);
      if ( v25 )
        Scaleform::RefCountNTSImpl::Release(v25);
    }
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
}

// File Line: 300
// RVA: 0x85B2A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocus(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // rsi
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::InteractiveObject *v8; // [rsp+50h] [rbp+18h]

  pVM = this->pTraits.pObject->pVM;
  pObject = 0i64;
  v8 = 0i64;
  if ( obj )
  {
    pObject = (Scaleform::GFx::InteractiveObject *)obj->pDispObj.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v8 = pObject;
  }
  Scaleform::GFx::MovieImpl::GetFocusedCharacter(
    (Scaleform::GFx::MovieImpl *)pVM[1].vfptr[2].__vecDelDtor,
    &resulta,
    controllerIdx);
  if ( resulta.pObject != pObject )
    Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
      (Scaleform::GFx::MovieImpl *)pVM[1].vfptr[2].__vecDelDtor,
      pObject,
      controllerIdx,
      GFx_FocusMovedByAS);
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release(resulta.pObject);
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
}

// File Line: 315
// RVA: 0x84B700
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocus(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        unsigned int controllerIdx)
{
  char *v4; // rcx
  __int64 v5; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rdx
  int TraitsType; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::MovieImpl::GetFocusedCharacter(
    (Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor,
    &resulta,
    controllerIdx);
  if ( !resulta.pObject )
    goto LABEL_12;
  v4 = (char *)resulta.pObject + 4 * (unsigned __int8)resulta.pObject->AvmObjOffset;
  v5 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 8i64))(v4);
  if ( v5 )
    v5 -= 56i64;
  v6 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v5 + 16);
  if ( !v6 )
    v6 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(v5 + 8);
  if ( ((unsigned __int8)v6 & 1) != 0 )
    v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v6 - 1);
  if ( v6 && ((TraitsType = v6->pTraits.pObject->TraitsType, TraitsType == 23) || TraitsType >= 29) )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, v6);
  }
  else
  {
LABEL_12:
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
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
      result->pObject = 0i64;
    }
  }
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release(resulta.pObject);
}

// File Line: 335
// RVA: 0x8556A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::numFocusGroupsGet(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result)
{
  *result = *((_DWORD *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 5288);
}

// File Line: 345
// RVA: 0x85B350
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setFocusGroupMask(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj,
        unsigned int mask)
{
  if ( this->pTraits.pObject->pVM[1].CallStack.gap0[0] )
  {
    if ( obj )
      obj->pDispObj.pObject->Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::vfptr[106].__vecDelDtor(
        obj->pDispObj.pObject,
        mask);
  }
}

// File Line: 359
// RVA: 0x84B7D0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocusGroupMask(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *obj)
{
  if ( this->pTraits.pObject->pVM[1].CallStack.gap0[0] )
    *result = Scaleform::GFx::InteractiveObject::GetFocusGroupMask((Scaleform::GFx::InteractiveObject *)obj->pDispObj.pObject);
}

// File Line: 371
// RVA: 0x85B070
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setControllerFocusGroup(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        bool *result,
        unsigned int controllerIdx,
        unsigned int focusGroupIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // rax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
    *result = (*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), _QWORD, _QWORD))(*(_QWORD *)pVM[1].vfptr[2].__vecDelDtor + 448i64))(
                pVM[1].vfptr[2].__vecDelDtor,
                controllerIdx,
                focusGroupIdx);
  else
    *result = 0;
}

// File Line: 386
// RVA: 0x84B0E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerFocusGroup(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // rax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
    *result = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)pVM[1].vfptr[2].__vecDelDtor + 456i64))(
                pVM[1].vfptr[2].__vecDelDtor,
                controllerIdx);
  else
    *result = 0;
}

// File Line: 401
// RVA: 0x84B130
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getControllerMaskByFocusGroup(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        unsigned int *result,
        unsigned int focusGroupIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // rax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
    *result = Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(
                (Scaleform::GFx::MovieImpl *)pVM[1].vfptr[2].__vecDelDtor,
                focusGroupIdx);
  else
    *result = 0;
}

// File Line: 417
// RVA: 0x84B9E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getModalClip(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::GFx::Sprite *ModalClip; // rax
  __int64 AvmObjOffset; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v7; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    ModalClip = Scaleform::GFx::MovieImpl::GetModalClip(
                  (Scaleform::GFx::MovieImpl *)pVM[1].vfptr[2].__vecDelDtor,
                  controllerIdx);
    if ( ModalClip )
    {
      AvmObjOffset = (unsigned __int8)ModalClip->AvmObjOffset;
      v7 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)((char *)&ModalClip->pWeakProxy + 4 * AvmObjOffset);
      if ( !v7 )
        v7 = *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(&ModalClip->RefCount + AvmObjOffset);
      if ( ((unsigned __int8)v7 & 1) != 0 )
        v7 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v7 - 1);
      if ( v7 && (unsigned int)(v7->pTraits.pObject->TraitsType - 30) <= 1 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, v7);
      }
      else
      {
        pObject = result->pObject;
        if ( result->pObject )
        {
          if ( ((unsigned __int8)pObject & 1) != 0 )
          {
            result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
            result->pObject = 0i64;
          }
          else
          {
            RefCount = pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
            }
            result->pObject = 0i64;
          }
        }
      }
    }
  }
}

// File Line: 439
// RVA: 0x85B950
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::setModalClip(
        Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *mc,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::GFx::MovieImpl *vecDelDtor; // rcx

  pVM = this->pTraits.pObject->pVM;
  if ( pVM[1].CallStack.gap0[0] )
  {
    vecDelDtor = (Scaleform::GFx::MovieImpl *)pVM[1].vfptr[2].__vecDelDtor;
    if ( mc )
      Scaleform::GFx::MovieImpl::SetModalClip(vecDelDtor, (Scaleform::GFx::Sprite *)mc->pDispObj.pObject, controllerIdx);
    else
      Scaleform::GFx::MovieImpl::SetModalClip(vecDelDtor, 0i64, controllerIdx);
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
  Scaleform::GFx::AS3::ThunkFunc4<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,bool,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, bool, unsigned int))Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::moveFocus;
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
  Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *,bool,Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *,bool,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *, bool, Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *, bool, unsigned int))Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::findFocus;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,7,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *, unsigned int))Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getFocus;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,14,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Sprite>,unsigned long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Sprite> *, unsigned int))Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::getModalClip;
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::FocusManager::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::FocusManagerCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::FocusManager::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::FocusManagerCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager::`vftable;
  }
  return result;
}

