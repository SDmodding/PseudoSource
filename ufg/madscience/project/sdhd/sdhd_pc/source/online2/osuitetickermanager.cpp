// File Line: 42
// RVA: 0x429270
void __fastcall UFG::OSuiteTickerManager::~OSuiteTickerManager(UFG::OSuiteTickerManager *this)
{
  UFG::OSuiteTickerManager *v1; // rbx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rdi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v3; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v4; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v5; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteTickerManager::`vftable;
  UFG::OSuiteManager::Instance();
  v2 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&v1->m_infoDataID);
  v1->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&v1->mPrev;
}

// File Line: 47
// RVA: 0x42E560
UFG::OSuiteTickerManager *__fastcall UFG::OSuiteTickerManager::Instance()
{
  UFG::qList<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver,1,0> *v0; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v1; // rcx

  if ( !(_S9_11 & 1) )
  {
    _S9_11 |= 1u;
    unk_142401468 = &unk_142401468;
    unk_142401470 = &unk_142401468;
    instance_3.vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteTickerManager::`vftable;
    unk_142401478 = 0i64;
    unk_142401480 = 0i64;
    unk_142401488 = 0i64;
    unk_142401490 = 0i64;
    unk_142401498 = 0i64;
    unk_1424014A0 = 0i64;
    UFG::qString::qString(&stru_1424014A8);
    unk_1424014D0 = 0;
    unk_1424014D4 = 0;
    v0 = &UFG::OSuiteManager::Instance()->m_lOSuiteObservers;
    v1 = v0->mNode.mNext;
    v0->mNode.mNext = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&unk_142401468;
    unk_142401468 = v0;
    unk_142401470 = v1;
    v1->mPrev = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&unk_142401468;
    atexit(UFG::OSuiteTickerManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_3;
}

// File Line: 53
// RVA: 0x42E720
bool __fastcall UFG::OSuiteTickerManager::IsTickerAvailable(UFG::OSuiteTickerManager *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::OSuiteTickerManager *v2; // rbx
  bool result; // al

  v2 = this;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, a2) )
    result = 0;
  else
    result = v2->m_tickerActive;
  return result;
}

// File Line: 65
// RVA: 0x42BCC0
void __fastcall UFG::OSuiteTickerManager::DownloadTicker(UFG::OSuiteTickerManager *this)
{
  UFG::OSuiteTickerManager *v1; // rsi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax
  char v5; // r14
  UFG::OSuiteTickerManager::TickerType v6; // ecx
  int v7; // ecx
  hkgpIndexedMeshDefinitions::Edge *v8; // rdx
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rdi
  unsigned int v11; // eax
  __int64 v12; // rbx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rax
  const char *v15; // rdx
  unsigned int v16; // eax
  __int64 v17; // rbx
  unsigned __int64 v18; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v19; // rdi
  OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *v20; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v21; // rax
  unsigned __int64 v22; // rax
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+20h] [rbp-E0h]
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+40h] [rbp-C0h]
  OSuite::ZString key; // [rsp+50h] [rbp-B0h]
  OSuite::ZString that; // [rsp+68h] [rbp-98h]
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+80h] [rbp-80h]
  OSuite::ZString v28; // [rsp+B8h] [rbp-48h]
  __int64 v29; // [rsp+D0h] [rbp-30h]
  OSuite::ZString v30; // [rsp+D8h] [rbp-28h]
  OSuite::ZOQuery query; // [rsp+F0h] [rbp-10h]

  v29 = -2i64;
  v1 = this;
  if ( !this->m_downloadActive )
  {
    v2 = UFG::UIScreenTextureManager::Instance();
    if ( UFG::UIScreenTextureManager::IsTexturePackLoaded(v2, UFG::OSuiteTickerManager::m_texturePackFilename) )
    {
      UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Infocast");
      v3 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v3, UFG::OSuiteTickerManager::m_texturePackFilename);
      v4 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ForceFlush(v4);
      v1->m_streamerTimeout = 5;
      v1->m_tickerActive = 0;
    }
    v5 = 0;
    v6 = v1->m_tickerType;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 != 1 )
          return;
        goto LABEL_21;
      }
      v5 = 1;
    }
    if ( !UFG::OSuiteManager::Instance()->m_bConnected
      || Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, v8) )
    {
LABEL_21:
      *(_WORD *)&v1->m_loadOfflineTicker = 257;
      return;
    }
    OSuite::ZOQuery::ZOQuery(&query);
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
    OSuite::ZString::ZString(&key, "version");
    OSuite::ZString::ZString(&v30, 4);
    v10 = v9;
    v11 = key.vfptr->ComputeHash((OSuite::IHashable *)&key.vfptr);
    v12 = (signed int)(v11 & (params.m_nHashSize - 1));
    v13 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v12].vfptr);
    params.m_nCount -= v13;
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &params.m_pLists[v12],
      &key,
      v10);
    v14 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v12].vfptr);
    params.m_nCount += v14;
    OSuite::ZString::~ZString(&v30);
    OSuite::ZString::~ZString(&key);
    v15 = "false";
    if ( v5 )
      v15 = "true";
    OSuite::ZString::ZString(&v28, v15);
    OSuite::ZString::ZString(&that, "standbyAccess");
    v16 = that.vfptr->ComputeHash((OSuite::IHashable *)&that.vfptr);
    v17 = (signed int)((params.m_nHashSize - 1) & v16);
    v18 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v17].vfptr);
    params.m_nCount -= v18;
    v19 = &params.m_pLists[v17];
    data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
    OSuite::ZString::ZString(&data.m_First, &that);
    OSuite::ZString::ZString(&data.m_Second, &v28);
    data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>::`vftable;
    v20 = (OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> > *)OSuite::ZObject::operator new(0x58ui64);
    if ( v20 )
      OSuite::ZRedBlackTreeBase::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>::TElement<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>>(
        v20,
        &data);
    else
      v21 = 0i64;
    OSuite::ZRedBlackTreeBase::InsertElementSet((OSuite::ZRedBlackTreeBase *)&v19->vfptr, v21);
    data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&data.m_Second);
    OSuite::ZString::~ZString(&data.m_First);
    v22 = OSuite::ZHttpStreamReader::Tell((OSuite::ZRedBlackTreeBase *)&params.m_pLists[v17].vfptr);
    params.m_nCount += v22;
    OSuite::ZString::~ZString(&that);
    OSuite::ZString::~ZString(&v28);
    OSuite::ZOQuery::ServiceOperation(&query, "GetTicker", &params);
    cb.m_Closure.m_pthis = 0i64;
    cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteTickerManager::FeedFetchedCB;
    cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(v1);
    OSuite::ZWebServiceClient::ExecuteQuery(v1->m_pWebServiceClient, &query, &cb);
    v1->m_downloadActive = 1;
    params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
    if ( params.m_pLists )
    {
      if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
        params.m_pLists->vfptr->__vecDelDtor((OSuite::ZObject *)params.m_pLists, 3u);
      else
        operator delete[](&params.m_pLists[-1].m_Comparer.vfptr);
    }
    OSuite::ZOQuery::~ZOQuery(&query);
  }
}

// File Line: 111
// RVA: 0x42E9E0
void __fastcall UFG::OSuiteTickerManager::OSuiteManagerConnected(UFG::OSuiteTickerManager *this, OSuite::ZWebServiceClient *p)
{
  bool v2; // zf

  if ( !this->m_pWebServiceClient )
  {
    v2 = this->m_downloadActive == 0;
    this->m_pWebServiceClient = p;
    if ( v2 )
    {
      this->m_tickerType = 0;
      UFG::OSuiteTickerManager::DownloadTicker(this);
    }
    else
    {
      this->m_queueTickerDownload = 1;
    }
  }
}

// File Line: 135
// RVA: 0x430EB0
void __fastcall UFG::OSuiteTickerManager::Shutdown(UFG::OSuiteTickerManager *this)
{
  UFG::OSuiteTickerManager *v1; // rbx
  OSuite::ZWebServiceClient *v2; // rcx

  v1 = this;
  v2 = this->m_pWebServiceClient;
  if ( v2 )
    OSuite::ZWebServiceClient::CloseRequest(v2, (OSuite::ZAtomBase *)&v1->m_pEntry->vfptr);
  v1->m_pEntry = 0i64;
}

// File Line: 199
// RVA: 0x42CCE0
char *__fastcall UFG::OSuiteTickerManager::GetTickerDescription(UFG::OSuiteTickerManager *this, __int64 ch, bool isLong)
{
  UFG::OSuiteTickerManager *v3; // rdi
  bool v4; // bp
  int v5; // ebx
  int v6; // edx
  hkGeometryUtils::IVertices *v7; // rcx
  int v8; // er8
  UFG::OnlineManager *v10; // rsi
  bool v11; // al
  bool v12; // zf

  v3 = this;
  v4 = isLong;
  v5 = ch;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
         0i64,
         (hkgpIndexedMeshDefinitions::Edge *)ch) )
  {
    return &customWorldMapCaption;
  }
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v7, v6, v8) )
  {
    v10 = UFG::OnlineManager::Instance();
    v11 = (unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(v10)
       && (unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(v10);
    if ( (v3->m_onlineTickerAvailable || !v11) && v3->m_tickerActive )
    {
      if ( v4 )
      {
        switch ( v5 )
        {
          case 0:
            return "$INFOCAST_LONGDESCRIPTION_CHANNEL_0";
          case 1:
            return "$INFOCAST_LONGDESCRIPTION_CHANNEL_1";
          case 2:
            return "$INFOCAST_LONGDESCRIPTION_CHANNEL_2";
        }
      }
      else
      {
        switch ( v5 )
        {
          case 0:
            return "$INFOCAST_SHORTDESCRIPTION_CHANNEL_0";
          case 1:
            return "$INFOCAST_SHORTDESCRIPTION_CHANNEL_1";
          case 2:
            return "$INFOCAST_SHORTDESCRIPTION_CHANNEL_2";
        }
      }
    }
    v12 = UFG::OSuiteManager::Instance()->m_bConnected == 0;
  }
  return "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_YELLOW";
}

// File Line: 269
// RVA: 0x42C0B0
void __fastcall UFG::OSuiteTickerManager::FeedFetchedCB(UFG::OSuiteTickerManager *this, OSuite::SCallbackData *pData, OSuite::ZWebServiceClient *pWebServiceClient)
{
  UFG::OSuiteTickerManager *v3; // rsi
  OSuite::ZOEntry *v4; // rax
  OSuite::ZOProperty *v5; // rax
  const char *v6; // rax
  OSuite::ZOProperty *v7; // rax
  OSuite::ZOProperty *v8; // rax
  unsigned int v9; // eax
  unsigned __int64 v10; // rcx
  char *v11; // rdi
  unsigned int v12; // ebx
  OSuite::ZOProperty *v13; // rax
  char *v14; // rdi
  unsigned int v15; // ebx
  OSuite::ZOProperty *v16; // rax
  OSuite::ZString outValue; // [rsp+28h] [rbp-20h]

  v3 = this;
  if ( pData->Status.eError )
  {
    this->m_loadOfflineTicker = 1;
  }
  else
  {
    v4 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(pWebServiceClient, &pData->URL);
    v3->m_pEntry = v4;
    if ( v4 )
    {
      OSuite::ZString::ZString(&outValue);
      v5 = OSuite::ZOEntry::Property(v3->m_pEntry, "_id");
      OSuite::ZOProperty::GetValue(v5, &outValue);
      v6 = OSuite::ZString::c_str(&outValue);
      UFG::qString::Set(&v3->m_infoDataID, v6);
      v7 = OSuite::ZOEntry::Property(v3->m_pEntry, "bin_perm_pc");
      v3->m_permSize = OSuite::ZOProperty::GetBinarySize(v7);
      v8 = OSuite::ZOEntry::Property(v3->m_pEntry, "bin_temp_pc");
      v9 = OSuite::ZOProperty::GetBinarySize(v8);
      v3->m_tempSize = v9;
      v10 = v3->m_permSize;
      if ( (_DWORD)v10 && v9 )
      {
        v11 = (char *)UFG::qMalloc(v10, "OSuite", 0i64);
        v3->m_permData = v11;
        v12 = v3->m_permSize;
        v13 = OSuite::ZOEntry::Property(v3->m_pEntry, "bin_perm_pc");
        OSuite::ZOProperty::GetBinary(v13, v11, v12);
        v14 = (char *)UFG::qMalloc(v3->m_tempSize, "OSuite", 0i64);
        v3->m_tempData = v14;
        v15 = v3->m_tempSize;
        v16 = OSuite::ZOEntry::Property(v3->m_pEntry, "bin_temp_pc");
        OSuite::ZOProperty::GetBinary(v16, v14, v15);
        v3->m_tickerDownloaded = 1;
      }
      else
      {
        v3->m_loadOfflineTicker = 1;
      }
      OSuite::ZString::~ZString(&outValue);
    }
    else
    {
      v3->m_loadOfflineTicker = 1;
    }
  }
}

