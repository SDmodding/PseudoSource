// File Line: 59
// RVA: 0x184A60
unsigned __int64 __fastcall UFG::qGetMainThreadID()
{
  return UFG::gMainThreadId;
}

// File Line: 72
// RVA: 0x161580
void __fastcall UFG::qInitParams::qInitParams(UFG::qInitParams *this)
{
  this->mTool_EnableDebugExecutableCheck = 1;
  this->mPS3_FileIOThreadStackSize = 0x10000;
  *(_QWORD *)&this->mMemory_NumTransactions = 0i64;
  this->mPS3_SysCacheName = 0i64;
  this->mPS3_FileIOThreadPriority = -1;
  this->mX360_FileIOThreadStackSize = 0x10000;
  this->mX360_FileIOThreadPriority = -1;
  this->mX360_FileIOThreadLogicalCoreID = 5;
}

// File Line: 92
// RVA: 0x184A50
UFG::qInitParams *__fastcall UFG::qGetInitParams()
{
  return &UFG::gQuarkInitParams;
}

// File Line: 108
// RVA: 0x184DD0
void __fastcall UFG::qInit(UFG::qInitParams *init_params)
{
  UFG::qResourceWarehouse *v1; // rax
  AMD_HD3D *v2; // rcx
  AMD_HD3D *v3; // rax

  UFG::gQuarkInitialized = 1;
  if ( init_params )
    UFG::gQuarkInitParams = *init_params;
  UFG::InitMemorySystem((UFG *)init_params);
  UFG::qInitPlat();
  UFG::gMainThreadId = (unsigned __int64)UFG::qGetCurrentThreadID();
  UFG::gQuarkFileSystem.mStartTicks = UFG::qGetTicks();
  UFG::qFileSystem::InitPlat(&UFG::gQuarkFileSystem);
  v1 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Init(v1);
  _(v2);
  v3 = (AMD_HD3D *)UFG::qSpuManager::Instance();
  _(v3);
  if ( (_S8_4 & 1) == 0 )
  {
    _S8_4 |= 1u;
    stru_14235BC40.mTaskFunctionDecls.mNode.mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    stru_14235BC40.mTaskFunctionDecls.mNode.mNext = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    UFG::gTaskFunctionManager = &stru_14235BC40;
    atexit(UFG::qTaskFunctionManager::Instance_::_2_::_dynamic_atexit_destructor_for__sInstance__);
  }
  UFG::qTaskFunctionManager::Init(&stru_14235BC40);
}

// File Line: 145
// RVA: 0x182200
void __fastcall UFG::qClose(UFG *this)
{
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *i; // rdx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *mPrev; // rcx
  UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *mNext; // rax
  AMD_HD3D *v4; // rax
  UFG *v5; // rcx
  AMD_HD3D *v6; // rcx
  char *v7; // rdx

  if ( (_S8_4 & 1) == 0 )
  {
    _S8_4 |= 1u;
    stru_14235BC40.mTaskFunctionDecls.mNode.mPrev = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    stru_14235BC40.mTaskFunctionDecls.mNode.mNext = (UFG::qNode<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl> *)&stru_14235BC40;
    UFG::gTaskFunctionManager = &stru_14235BC40;
    atexit(UFG::qTaskFunctionManager::Instance_::_2_::_dynamic_atexit_destructor_for__sInstance__);
  }
  for ( i = stru_14235BC40.mTaskFunctionDecls.mNode.mNext;
        (UFG::qTaskFunctionManager *)stru_14235BC40.mTaskFunctionDecls.mNode.mNext != &stru_14235BC40;
        i = stru_14235BC40.mTaskFunctionDecls.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
  v4 = (AMD_HD3D *)UFG::qSpuManager::Instance();
  _(v4);
  UFG::qValidateChunkFileBuilders(v5);
  UFG::qFileSystem::ClosePlat(&UFG::gQuarkFileSystem);
  _(v6);
  v7 = (char *)UFG::gMemoryTransactions;
  if ( UFG::gMemoryTransactions )
  {
    UFG::gMemoryTransactions = 0i64;
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
  }
}

