// File Line: 42
// RVA: 0x429270
void __fastcall UFG::OSuiteTickerManager::~OSuiteTickerManager(UFG::OSuiteTickerManager *this)
{
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mPrev; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v4; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v5; // rax

  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteTickerManager::`vftable;
  UFG::OSuiteManager::Instance();
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->mNext = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  UFG::qString::~qString(&this->m_infoDataID);
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->mNext = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
}

// File Line: 47
// RVA: 0x42E560
UFG::OSuiteTickerManager *__fastcall UFG::OSuiteTickerManager::Instance()
{
  UFG::qList<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver,1,0> *p_m_lOSuiteObservers; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rcx

  if ( (_S9_11 & 1) == 0 )
  {
    _S9_11 |= 1u;
    qword_142401468 = &qword_142401468;
    unk_142401470 = &qword_142401468;
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
    p_m_lOSuiteObservers = &UFG::OSuiteManager::Instance()->m_lOSuiteObservers;
    mNext = p_m_lOSuiteObservers->mNode.mNext;
    p_m_lOSuiteObservers->mNode.mNext = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&qword_142401468;
    qword_142401468 = p_m_lOSuiteObservers;
    unk_142401470 = mNext;
    mNext->mPrev = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&qword_142401468;
    atexit(UFG::OSuiteTickerManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_3;
}

// File Line: 53
// RVA: 0x42E720
bool __fastcall UFG::OSuiteTickerManager::IsTickerAvailable(
        UFG::OSuiteTickerManager *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  return !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, a2) && this->m_tickerActive;
}

// File Line: 65
// RVA: 0x42BCC0
void __fastcall UFG::OSuiteTickerManager::DownloadTicker(UFG::OSuiteTickerManager *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax
  char v5; // r14
  UFG::OSuiteTickerManager::TickerType m_tickerType; // ecx
  __int32 v7; // ecx
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
  OSuite::TMap<OSuite::ZString,OSuite::ZString> params; // [rsp+20h] [rbp-E0h] BYREF
  OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void> cb; // [rsp+40h] [rbp-C0h] BYREF
  OSuite::ZString key; // [rsp+50h] [rbp-B0h] BYREF
  OSuite::ZString that; // [rsp+68h] [rbp-98h] BYREF
  OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString> data; // [rsp+80h] [rbp-80h] BYREF
  OSuite::ZString v28; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v29; // [rsp+D0h] [rbp-30h]
  OSuite::ZString v30; // [rsp+D8h] [rbp-28h] BYREF
  OSuite::ZOQuery query; // [rsp+F0h] [rbp-10h] BYREF

  v29 = -2i64;
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
      this->m_streamerTimeout = 5;
      this->m_tickerActive = 0;
    }
    v5 = 0;
    m_tickerType = this->m_tickerType;
    if ( m_tickerType )
    {
      v7 = m_tickerType - 1;
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
      *(_WORD *)&this->m_loadOfflineTicker = 257;
      return;
    }
    OSuite::ZOQuery::ZOQuery(&query);
    OSuite::TMap<OSuite::ZString,OSuite::ZString>::TMap<OSuite::ZString,OSuite::ZString>(&params, 0x10ui64);
    OSuite::ZString::ZString(&key, "version");
    OSuite::ZString::ZString(&v30, 4);
    v10 = v9;
    v11 = key.OSuite::IHashable::vfptr->ComputeHash(&key.OSuite::IHashable);
    v12 = (int)(v11 & (params.m_nHashSize - 1));
    v13 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v12]);
    params.m_nCount -= v13;
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      &params.m_pLists[v12],
      &key,
      v10);
    v14 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v12]);
    params.m_nCount += v14;
    OSuite::ZString::~ZString(&v30);
    OSuite::ZString::~ZString(&key);
    v15 = "false";
    if ( v5 )
      v15 = "true";
    OSuite::ZString::ZString(&v28, v15);
    OSuite::ZString::ZString(&that, "standbyAccess");
    v16 = that.OSuite::IHashable::vfptr->ComputeHash(&that.OSuite::IHashable);
    v17 = (int)((params.m_nHashSize - 1) & v16);
    v18 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v17]);
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
    OSuite::ZRedBlackTreeBase::InsertElementSet(v19, v21);
    data.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<OSuite::ZString,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&data.m_Second);
    OSuite::ZString::~ZString(&data.m_First);
    v22 = OSuite::ZHttpStreamReader::Tell(&params.m_pLists[v17]);
    params.m_nCount += v22;
    OSuite::ZString::~ZString(&that);
    OSuite::ZString::~ZString(&v28);
    OSuite::ZOQuery::ServiceOperation(&query, "GetTicker", &params);
    cb.m_Closure.m_pthis = 0i64;
    cb.m_Closure.m_pFunction = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))UFG::OSuiteTickerManager::FeedFetchedCB;
    cb.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
    OSuite::ZWebServiceClient::ExecuteQuery(this->m_pWebServiceClient, &query, &cb);
    this->m_downloadActive = 1;
    params.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZString>::`vftable;
    if ( params.m_pLists )
    {
      if ( LODWORD(params.m_pLists[-1].m_Comparer.vfptr) )
        params.m_pLists->vfptr->__vecDelDtor(params.m_pLists, 3u);
      else
        operator delete[](&params.m_pLists[-1].m_Comparer.OSuite::ZObject);
    }
    OSuite::ZOQuery::~ZOQuery(&query);
  }
}

// File Line: 111
// RVA: 0x42E9E0
void __fastcall UFG::OSuiteTickerManager::OSuiteManagerConnected(
        UFG::OSuiteTickerManager *this,
        OSuite::ZWebServiceClient *p)
{
  bool v2; // zf

  if ( !this->m_pWebServiceClient )
  {
    v2 = !this->m_downloadActive;
    this->m_pWebServiceClient = p;
    if ( v2 )
    {
      this->m_tickerType = TICKER_ACTIVE;
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
  OSuite::ZWebServiceClient *m_pWebServiceClient; // rcx

  m_pWebServiceClient = this->m_pWebServiceClient;
  if ( m_pWebServiceClient )
    OSuite::ZWebServiceClient::CloseRequest(m_pWebServiceClient, this->m_pEntry);
  this->m_pEntry = 0i64;
}

// File Line: 199
// RVA: 0x42CCE0
char *__fastcall UFG::OSuiteTickerManager::GetTickerDescription(
        UFG::OSuiteTickerManager *this,
        hkgpIndexedMeshDefinitions::Edge *ch,
        bool isLong)
{
  int v5; // ebx
  int v6; // edx
  hkGeometryUtils::IVertices *v7; // rcx
  int v8; // r8d
  UFG::OnlineManager *v10; // rsi
  bool v11; // al

  v5 = (int)ch;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, ch) )
    return &customCaption;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v7, v6, v8) )
  {
    v10 = UFG::OnlineManager::Instance();
    v11 = UFG::OnlineManager::IsNetworkAvailable(v10) && UFG::OnlineManager::IsNetworkAvailable(v10);
    if ( (this->m_onlineTickerAvailable || !v11) && this->m_tickerActive )
    {
      if ( isLong )
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
    UFG::OSuiteManager::Instance();
  }
  return "$SOCIAL_HUB_ONLINE_STATUS_ICON_MESSAGE_YELLOW";
}

// File Line: 269
// RVA: 0x42C0B0
void __fastcall UFG::OSuiteTickerManager::FeedFetchedCB(
        UFG::OSuiteTickerManager *this,
        OSuite::SCallbackData *pData,
        OSuite::ZWebServiceClient *pWebServiceClient)
{
  OSuite::ZOEntry *v4; // rax
  OSuite::ZOProperty *v5; // rax
  const char *v6; // rax
  OSuite::ZOProperty *v7; // rax
  OSuite::ZOProperty *v8; // rax
  unsigned int BinarySize; // eax
  unsigned __int64 m_permSize; // rcx
  char *v11; // rdi
  unsigned int v12; // ebx
  OSuite::ZOProperty *v13; // rax
  char *v14; // rdi
  unsigned int m_tempSize; // ebx
  OSuite::ZOProperty *v16; // rax
  OSuite::ZString outValue; // [rsp+28h] [rbp-20h] BYREF

  if ( pData->Status.eError )
  {
    this->m_loadOfflineTicker = 1;
  }
  else
  {
    v4 = OSuite::ZWebServiceClient::RetrieveRequest<OSuite::ZOEntry>(pWebServiceClient, &pData->URL);
    this->m_pEntry = v4;
    if ( v4 )
    {
      OSuite::ZString::ZString(&outValue);
      v5 = OSuite::ZOEntry::Property(this->m_pEntry, "_id");
      OSuite::ZOProperty::GetValue(v5, &outValue);
      v6 = OSuite::ZString::c_str(&outValue);
      UFG::qString::Set(&this->m_infoDataID, v6);
      v7 = OSuite::ZOEntry::Property(this->m_pEntry, "bin_perm_pc");
      this->m_permSize = OSuite::ZOProperty::GetBinarySize(v7);
      v8 = OSuite::ZOEntry::Property(this->m_pEntry, "bin_temp_pc");
      BinarySize = OSuite::ZOProperty::GetBinarySize(v8);
      this->m_tempSize = BinarySize;
      m_permSize = this->m_permSize;
      if ( (_DWORD)m_permSize && BinarySize )
      {
        v11 = (char *)UFG::qMalloc(m_permSize, "OSuite", 0i64);
        this->m_permData = v11;
        v12 = this->m_permSize;
        v13 = OSuite::ZOEntry::Property(this->m_pEntry, "bin_perm_pc");
        OSuite::ZOProperty::GetBinary(v13, v11, v12);
        v14 = (char *)UFG::qMalloc(this->m_tempSize, "OSuite", 0i64);
        this->m_tempData = v14;
        m_tempSize = this->m_tempSize;
        v16 = OSuite::ZOEntry::Property(this->m_pEntry, "bin_temp_pc");
        OSuite::ZOProperty::GetBinary(v16, v14, m_tempSize);
        this->m_tickerDownloaded = 1;
      }
      else
      {
        this->m_loadOfflineTicker = 1;
      }
      OSuite::ZString::~ZString(&outValue);
    }
    else
    {
      this->m_loadOfflineTicker = 1;
    }
  }
}

