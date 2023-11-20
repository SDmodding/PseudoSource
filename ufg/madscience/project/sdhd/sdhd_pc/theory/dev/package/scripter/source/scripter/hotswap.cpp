// File Line: 43
// RVA: 0x14646A0
void (__fastcall *UFG::_dynamic_initializer_for__DefaultHotSwapCallBack__())(fastdelegate::detail::GenericClass *this)
{
  void (__fastcall *result)(fastdelegate::detail::GenericClass *); // rax

  result = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !_ )
    result = 0i64;
  UFG::DefaultHotSwapCallBack.m_Closure.m_pFunction = result;
  return result;
}

// File Line: 54
// RVA: 0x1464630
void (__fastcall *dynamic_initializer_for__UFG::HotSwapFileManager::msHotSwapFeedbackCallback__())(fastdelegate::detail::GenericClass *this)
{
  void (__fastcall *result)(fastdelegate::detail::GenericClass *); // rax

  result = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !_ )
    result = 0i64;
  UFG::HotSwapFileManager::msHotSwapFeedbackCallback.m_Closure.m_pFunction = result;
  return result;
}

// File Line: 95
// RVA: 0x1464650
__int64 dynamic_initializer_for__UFG::HotSwapFileManager::sInstance__()
{
  stru_142036A10.mNode.mPrev = (UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *)&stru_142036A10;
  stru_142036A10.mNode.mNext = (UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *)&stru_142036A10;
  unk_142036A20 = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::HotSwapFileManager::sInstance__);
}

// File Line: 98
// RVA: 0x13F8A0
UFG::HotSwapFileManager *__fastcall UFG::HotSwapFileManager::Get()
{
  return &UFG::HotSwapFileManager::sInstance;
}

// File Line: 124
// RVA: 0x13F8B0
__int64 __fastcall UFG::HotSwapFileManager::ProcessBuildLabOptions(UFG::HotSwapFileManager *this, UFG::BuildLabOptions *buildLabOptions, const char *obfuscateKey, unsigned int obfuscateKeyLength)
{
  UFG::qList<UFG::HotSwapSystemInfo,UFG::HotSwapSystemInfo,1,0> *v4; // rbx
  UFG::qList<UFG::HotSwapSystemInfo,UFG::HotSwapSystemInfo,1,0> *v5; // rcx
  __int64 result; // rax

  v4 = &this->mHotSwapSystemList;
  UFG::qList<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory,1,0>::DeleteNodes((UFG::qList<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory,1,0> *)&this->mHotSwapSystemList);
  v5 = (UFG::qList<UFG::HotSwapSystemInfo,UFG::HotSwapSystemInfo,1,0> *)v4->mNode.mNext;
  for ( result = 0i64; v5 != v4; result = (unsigned int)(result + 1) )
    v5 = (UFG::qList<UFG::HotSwapSystemInfo,UFG::HotSwapSystemInfo,1,0> *)v5->mNode.mNext;
  return result;
}

// File Line: 247
// RVA: 0x13F900
_BOOL8 __fastcall UFG::HotSwapFileManager::UnRegisterFile(UFG::HotSwapFileManager *this, const char *file, fastdelegate::FastDelegate1<char const *,void> *callback)
{
  fastdelegate::FastDelegate1<char const *,void> *v3; // r14
  UFG::HotSwapFileManager *v4; // rsi
  char v5; // r15
  int v6; // ebp
  UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *i; // rbx
  UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *v8; // rdi
  UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *v9; // rcx
  UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *v10; // rax
  UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *v11; // rdx
  UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *v12; // rax

  v3 = callback;
  v4 = this;
  v5 = 0;
  v6 = UFG::qStringHashUpper32(file, 0xFFFFFFFF);
  for ( i = v4->mHotSwapInfoList.mNode.mNext; i != (UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *)v4; i = i->mNext )
  {
    if ( LODWORD(i[3].mNext) == v6
      && i[4].mPrev == (UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *)v3->m_Closure.m_pthis
      && i[4].mNext == (UFG::qNode<UFG::HotSwapFileInfo,UFG::HotSwapFileInfo> *)v3->m_Closure.m_pFunction )
    {
      v8 = i;
      if ( v4->mIsUpdating )
      {
        BYTE1(i[6].mNext) = 1;
      }
      else
      {
        i = i->mPrev;
        v9 = v8->mPrev;
        v10 = v8->mNext;
        v9->mNext = v10;
        v10->mPrev = v9;
        v8->mPrev = v8;
        v8->mNext = v8;
        UFG::qString::~qString((UFG::qString *)&v8[1]);
        v11 = v8->mPrev;
        v12 = v8->mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v8->mPrev = v8;
        v8->mNext = v8;
        operator delete[](v8);
        v5 = 1;
      }
    }
  }
  return v5 == 0;
}

// File Line: 302
// RVA: 0x13F8F0
void __fastcall UFG::HotSwapFileManager::SetEnabled(bool bEnabled)
{
  HotSwapFileManager_Enabled = bEnabled;
}

